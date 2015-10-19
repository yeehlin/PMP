/*
 * Copyright 1993-2014 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

// Simple 3D volume renderer

#ifndef _VOLUMERENDER_KERNEL_CU_
#define _VOLUMERENDER_KERNEL_CU_

#include <helper_cuda.h>
#include <helper_math.h>

typedef unsigned int  uint;
typedef unsigned char uchar;

cudaArray *d_volumeArray = 0;
cudaArray *d_transferFuncArray;

__device__ cudaExtent devextent;
__device__ cudaPitchedPtr devPitchedPtr;

// 定义体数据原始数据类型
typedef unsigned char VolumeType;
//typedef unsigned short VolumeType;

texture<VolumeType, 3, cudaReadModeNormalizedFloat> tex;         // 3D texture// 3D纹理
texture<float4, 1, cudaReadModeElementType>         transferTex; // 1D transfer function texture//转化后的纹理

//__device__ cudaPitchedPtr d_PitchedPtr;

typedef struct
{
    float4 m[3];
} float3x4;

// 视角矩阵，位于GPU的常量存储器
__constant__ float3x4 c_invViewMatrix;  // inverse view matrix

// 定义光线，起始位置和方向
struct Ray
{
    float3 o;   // origin
    float3 d;   // direction
};

// intersect ray with a box光线 和盒子相交
// http://www.siggraph.org/education/materials/HyperGraph/raytrace/rtinter3.htm

__device__
int intersectBox(
Ray r, // 光线
float3 boxmin,//  
float3 boxmax, //
float *tnear, // 近交点
float *tfar // 远交点
) 
{
	// 计算光线与六个盒面相交的交点
    // compute intersection of ray with all six bbox planes
    float3 invR = make_float3(1.0f) / r.d;
    float3 tbot = invR * (boxmin - r.o);
    float3 ttop = invR * (boxmax - r.o);

    // re-order intersections to find smallest and largest on each axis
    float3 tmin = fminf(ttop, tbot);
    float3 tmax = fmaxf(ttop, tbot);

    // find the largest tmin and the smallest tmax
    float largest_tmin = fmaxf(fmaxf(tmin.x, tmin.y), fmaxf(tmin.x, tmin.z));
    float smallest_tmax = fminf(fminf(tmax.x, tmax.y), fminf(tmax.x, tmax.z));

    *tnear = largest_tmin;
    *tfar = smallest_tmax;

    return smallest_tmax > largest_tmin;
}

// 通过矩阵（视角矩阵）变换成向量（不是转化）
// transform vector by matrix (no translation)
__device__
float3 mul(const float3x4 &M, const float3 &v)
{
    float3 r;
	// dot表示点乘，也就是求两个向量的内积
    r.x = dot(v, make_float3(M.m[0]));
    r.y = dot(v, make_float3(M.m[1]));
    r.z = dot(v, make_float3(M.m[2]));
    return r;
}

// transform vector by matrix with translation
__device__
float4 mul(const float3x4 &M, const float4 &v)
{
    float4 r;
    r.x = dot(v, M.m[0]);
    r.y = dot(v, M.m[1]);
    r.z = dot(v, M.m[2]);
    r.w = 1.0f;
    return r;
}

__device__ uint rgbaFloatToInt(float4 rgba)
{
    rgba.x = __saturatef(rgba.x);   // clamp to [0.0, 1.0]，归一化，将数据归至0到1之间
    rgba.y = __saturatef(rgba.y);
    rgba.z = __saturatef(rgba.z);
    rgba.w = __saturatef(rgba.w);

    return (uint(rgba.w*255)<<24) | (uint(rgba.z*255)<<16) | (uint(rgba.y*255)<<8) | uint(rgba.x*255);
}

__global__ void
d_render(
uint *d_output, //输出数据
uint imageW, //图像的宽度
uint imageH,//图像的高度
         float density, //图像密度
		 float brightness,//图像亮度
         float transferOffset, //补偿
		 float transferScale//比例和刻度
		 )
{
    const int maxSteps = 500;
    const float tstep = 0.01f;// 步长
    const float opacityThreshold = 0.95f;// 透明度阀值
    const float3 boxMin = make_float3(-1.0f, -1.0f, -1.0f);// 包围盒的最小点和最大点
    const float3 boxMax = make_float3(1.0f, 1.0f, 1.0f);

	// 线程在两个方向上的坐标
    uint x = blockIdx.x*blockDim.x + threadIdx.x;
    uint y = blockIdx.y*blockDim.y + threadIdx.y;

    if ((x >= imageW) || (y >= imageH)) return;
	// 拉伸和平移至(-1,-1,-1)到(1,1,1)的三维空间
    float u = (x / (float) imageW)*2.0f-1.0f;
    float v = (y / (float) imageH)*2.0f-1.0f;

    // calculate eye ray in world space
	// 计算世界坐标系中的视线
    Ray eyeRay;
    eyeRay.o = make_float3(mul(c_invViewMatrix, make_float4(0.0f, 0.0f, 0.0f, 1.0f)));
	// 初始视线方向(u,v,-2位置)
    eyeRay.d = normalize(make_float3(u, v, -2.0f));
	// 有视角的视线方向
    eyeRay.d = mul(c_invViewMatrix, eyeRay.d);

    // find intersection with box
	// 通过包围盒算法计算视线是否与体数据相交
    float tnear, tfar;
    int hit = intersectBox(eyeRay, boxMin, boxMax, &tnear, &tfar);

    if (!hit) return;

    if (tnear < 0.0f) tnear = 0.0f;     // clamp to near plane// 近交点小于0则置为0

    // march along ray from front to back, accumulating color
	// 跟随光线从前往后计算颜色
    float4 sum = make_float4(0.0f);
    float t = tnear;
    float3 pos = eyeRay.o + eyeRay.d*tnear;//起始位置
    float3 step = eyeRay.d*tstep;

    for (int i=0; i<maxSteps; i++)
    {
        // read from 3D texture
        // remap position to [0, 1] coordinates
        float sample = tex3D(tex, pos.x*0.5f+0.5f, pos.y*0.5f+0.5f, pos.z*0.5f+0.5f);
        //sample *= 64.0f;    // scale for 10-bit data

        // lookup in transfer function texture
        float4 col = tex1D(transferTex, (sample-transferOffset)*transferScale);
        col.w *= density;

        // "under" operator for back-to-front blending
        //sum = lerp(sum, col, col.w);

        // pre-multiply alpha
        col.x *= col.w;
        col.y *= col.w;
        col.z *= col.w;
        // "over" operator for front-to-back blending
        sum = sum + col*(1.0f - sum.w);

        // exit early if opaque
        if (sum.w > opacityThreshold)
            break;

        t += tstep;

        if (t > tfar) break;

        pos += step;
    }

    sum *= brightness;
	// 将颜色值写入输出数据
    // write output color
    d_output[y*imageW + x] = rgbaFloatToInt(sum);
}

// 设置纹理滤波模式
extern "C"
void setTextureFilterMode(bool bLinearFilter)
{
    tex.filterMode = bLinearFilter ? cudaFilterModeLinear : cudaFilterModePoint;
}


// 初始化CUDA
extern "C"
void initCuda(void *h_volume, cudaExtent volumeSize)
{
	// 创建三维数组
    // create 3D array
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc<VolumeType>();
    checkCudaErrors(cudaMalloc3DArray(&d_volumeArray, &channelDesc, volumeSize));// 分配GPU内存
	// 拷贝数据到GPU
    // copy data to 3D array
    cudaMemcpy3DParms copyParams = {0};
    copyParams.srcPtr   = make_cudaPitchedPtr(h_volume, volumeSize.width*sizeof(VolumeType), volumeSize.width, volumeSize.height);
    copyParams.dstArray = d_volumeArray;
    copyParams.extent   = volumeSize;
    copyParams.kind     = cudaMemcpyHostToDevice;
    checkCudaErrors(cudaMemcpy3D(&copyParams));



	// 设置纹理参数
    // set texture parameters
    tex.normalized = true;                      // access with normalized texture coordinates//使用标准纹理坐标系
    tex.filterMode = cudaFilterModeLinear;      // linear interpolation//线性插值滤波
    tex.addressMode[0] = cudaAddressModeClamp;  // clamp texture coordinates
    tex.addressMode[1] = cudaAddressModeClamp;
	//绑定数组到3D纹理
    // bind array to 3D texture
    checkCudaErrors(cudaBindTextureToArray(tex, d_volumeArray, channelDesc));
	//建立转换矩阵纹理，该纹理用来填充体数据的颜色，每一个float4为取样点的RGBA
    // create transfer function texture
    float4 transferFunc[] =
    {
        {  0.0, 0.0, 0.0, 0.0, },
        {  1.0, 0.0, 0.0, 1.0, },
        {  1.0, 0.5, 0.0, 1.0, },
        {  1.0, 1.0, 0.0, 1.0, },
        {  0.0, 1.0, 0.0, 1.0, },
        {  0.0, 1.0, 1.0, 1.0, },
        {  0.0, 0.0, 1.0, 1.0, },
        {  1.0, 0.0, 1.0, 1.0, },
        {  0.0, 0.0, 0.0, 0.0, },
    };
	// 以1D数组的形式将颜色转换矩阵绑定到transferTex
    cudaChannelFormatDesc channelDesc2 = cudaCreateChannelDesc<float4>();
    cudaArray *d_transferFuncArray;
    checkCudaErrors(cudaMallocArray(&d_transferFuncArray, &channelDesc2, sizeof(transferFunc)/sizeof(float4), 1));
    checkCudaErrors(cudaMemcpyToArray(d_transferFuncArray, 0, 0, transferFunc, sizeof(transferFunc), cudaMemcpyHostToDevice));
	// 设置3D纹理的参数
    transferTex.filterMode = cudaFilterModeLinear;// 插值方式是线性插值
    transferTex.normalized = true;    // access with normalized texture coordinates，归一化纹理坐标：true
    transferTex.addressMode[0] = cudaAddressModeClamp;   // wrap texture coordinates//夹取纹理寻址

	// 将数组绑定到该纹理
    // Bind the array to the texture
    checkCudaErrors(cudaBindTextureToArray(transferTex, d_transferFuncArray, channelDesc2));
}
// 释放CUDA缓存
extern "C"
void freeCudaBuffers()
{
    checkCudaErrors(cudaFreeArray(d_volumeArray));
    checkCudaErrors(cudaFreeArray(d_transferFuncArray));
	
}



// 复制视角矩阵
extern "C"
void copyInvViewMatrix(float *invViewMatrix, size_t sizeofMatrix)
{
    checkCudaErrors(cudaMemcpyToSymbol(c_invViewMatrix, invViewMatrix, sizeofMatrix));
}
//////////////////////////////////////////////////////////////////////////////////////
//以下是我在存储器方面的优化
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////////

__global__ void
my_d_render(
uint *d_output, //输出数据
uint imageW, //图像的宽度
uint imageH,//图像的高度
         float density, //图像密度
		 float brightness,//图像亮度
         float transferOffset, //补偿
		 float transferScale,//比例和刻度
		 cudaPitchedPtr devPitchedPtr,
		 cudaExtent devextent
		 )
{
    const int maxSteps = 500;
    const float tstep = 0.01f;// 步长
    const float opacityThreshold = 0.95f;// 透明度阀值
    const float3 boxMin = make_float3(-1.0f, -1.0f, -1.0f);// 包围盒的最小点和最大点
    const float3 boxMax = make_float3(1.0f, 1.0f, 1.0f);

	char * devPtr = (char *)devPitchedPtr.ptr;
	size_t pitch = devPitchedPtr.pitch;
	size_t slicePitch = pitch*devextent.height;

	// 线程在两个方向上的坐标
    uint x = blockIdx.x*blockDim.x + threadIdx.x;
    uint y = blockIdx.y*blockDim.y + threadIdx.y;
	uint z = blockIdx.z*blockDim.z + threadIdx.z;

    if ((x >= imageW) || (y >= imageH)) return;
	// 拉伸和平移至(-1,-1,-1)到(1,1,1)的三维空间
    float u = (x / (float) imageW)*2.0f-1.0f;
    float v = (y / (float) imageH)*2.0f-1.0f;

    // calculate eye ray in world space
	// 计算世界坐标系中的视线
    Ray eyeRay;
    eyeRay.o = make_float3(mul(c_invViewMatrix, make_float4(0.0f, 0.0f, 0.0f, 1.0f)));
	// 初始视线方向(u,v,-2位置)
    eyeRay.d = normalize(make_float3(u, v, -2.0f));
	// 有视角的视线方向
    eyeRay.d = mul(c_invViewMatrix, eyeRay.d);

    // find intersection with box
	// 通过包围盒算法计算视线是否与体数据相交
    float tnear, tfar;
    int hit = intersectBox(eyeRay, boxMin, boxMax, &tnear, &tfar);

    if (!hit) return;

    if (tnear < 0.0f) tnear = 0.0f;     // clamp to near plane// 近交点小于0则置为0

    // march along ray from front to back, accumulating color
	// 跟随光线从前往后计算颜色
    float4 sum = make_float4(0.0f);
    float t = tnear;
    float3 pos = eyeRay.o + eyeRay.d*tnear;//起始位置
    float3 step = eyeRay.d*tstep;

    for (int i=0; i<maxSteps; i++)
    {
        // read from 3D texture
        // remap position to [0, 1] coordinates
        //float sample = tex3D(tex, pos.x*0.5f+0.5f, pos.y*0.5f+0.5f, pos.z*0.5f+0.5f);
        //sample *= 64.0f;    // scale for 10-bit data
		char * slice = devPtr+z*slicePitch;
		float * row = (float *)(slice + y*pitch);
		float element = row[x];


		float sample = 0.3;


        // lookup in transfer function texture
        float4 col = tex1D(transferTex, (sample-transferOffset)*transferScale);
        col.w *= density;

        // "under" operator for back-to-front blending
        //sum = lerp(sum, col, col.w);

        // pre-multiply alpha
        col.x *= col.w;
        col.y *= col.w;
        col.z *= col.w;
        // "over" operator for front-to-back blending
        sum = sum + col*(1.0f - sum.w);

        // exit early if opaque
        if (sum.w > opacityThreshold)
            break;

        t += tstep;

        if (t > tfar) break;

        pos += step;
    }

    sum *= brightness;
	// 将颜色值写入输出数据
    // write output color
    d_output[y*imageW + x] = rgbaFloatToInt(sum);
}

// 采用全局存储器策略 初始化CUDA
extern "C"
void myinitCuda(void *h_volume, cudaExtent volumeSize)
{
	checkCudaErrors(cudaMalloc3D(&devPitchedPtr,volumeSize));

	//devPitchedPtr=make_cudaPitchedPtr(h_volume, volumeSize.width*sizeof(VolumeType), volumeSize.width, volumeSize.height);
	cudaMemcpy3DParms mycopyParams = {0};
    mycopyParams.srcPtr   = make_cudaPitchedPtr(h_volume, volumeSize.width*sizeof(VolumeType), volumeSize.width, volumeSize.height);
    mycopyParams.dstPtr = devPitchedPtr;
    mycopyParams.extent   = volumeSize;
    mycopyParams.kind     = cudaMemcpyHostToDevice;
    checkCudaErrors(cudaMemcpy3D(&mycopyParams));

	devextent = volumeSize;


	//cudaFree((void *)&devPitchedPtr);


	// 创建三维数组
    // create 3D array
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc<VolumeType>();
    checkCudaErrors(cudaMalloc3DArray(&d_volumeArray, &channelDesc, volumeSize));// 分配GPU内存
	// 拷贝数据到GPU
    // copy data to 3D array
    cudaMemcpy3DParms copyParams = {0};
    copyParams.srcPtr   = make_cudaPitchedPtr(h_volume, volumeSize.width*sizeof(VolumeType), volumeSize.width, volumeSize.height);
    copyParams.dstArray = d_volumeArray;
    copyParams.extent   = volumeSize;
    copyParams.kind     = cudaMemcpyHostToDevice;
    checkCudaErrors(cudaMemcpy3D(&copyParams));


	/*
	// 设置纹理参数
    // set texture parameters
    tex.normalized = true;                      // access with normalized texture coordinates//使用标准纹理坐标系
    tex.filterMode = cudaFilterModeLinear;      // linear interpolation//线性插值滤波
    tex.addressMode[0] = cudaAddressModeClamp;  // clamp texture coordinates
    tex.addressMode[1] = cudaAddressModeClamp;
	//绑定数组到3D纹理
    // bind array to 3D texture
    checkCudaErrors(cudaBindTextureToArray(tex, d_volumeArray, channelDesc));
	//*/
	//建立转换矩阵纹理，该纹理用来填充体数据的颜色，每一个float4为取样点的RGBA
    // create transfer function texture
    float4 transferFunc[] =
    {
        {  0.0, 0.0, 0.0, 0.0, },
        {  1.0, 0.0, 0.0, 1.0, },
        {  1.0, 0.5, 0.0, 1.0, },
        {  1.0, 1.0, 0.0, 1.0, },
        {  0.0, 1.0, 0.0, 1.0, },
        {  0.0, 1.0, 1.0, 1.0, },
        {  0.0, 0.0, 1.0, 1.0, },
        {  1.0, 0.0, 1.0, 1.0, },
        {  0.0, 0.0, 0.0, 0.0, },
    };
	// 以1D数组的形式将颜色转换矩阵绑定到transferTex
    cudaChannelFormatDesc channelDesc2 = cudaCreateChannelDesc<float4>();
    cudaArray *d_transferFuncArray;
    checkCudaErrors(cudaMallocArray(&d_transferFuncArray, &channelDesc2, sizeof(transferFunc)/sizeof(float4), 1));
    checkCudaErrors(cudaMemcpyToArray(d_transferFuncArray, 0, 0, transferFunc, sizeof(transferFunc), cudaMemcpyHostToDevice));
	// 设置3D纹理的参数
    transferTex.filterMode = cudaFilterModeLinear;// 插值方式是线性插值
    transferTex.normalized = true;    // access with normalized texture coordinates，归一化纹理坐标：true
    transferTex.addressMode[0] = cudaAddressModeClamp;   // wrap texture coordinates//夹取纹理寻址

	// 将数组绑定到该纹理
    // Bind the array to the texture
    checkCudaErrors(cudaBindTextureToArray(transferTex, d_transferFuncArray, channelDesc2));
}

// 调用CUDA内核进行体绘制
extern "C"
void render_kernel(dim3 gridSize, dim3 blockSize, uint *d_output, uint imageW, uint imageH,
                   float density, float brightness, float transferOffset, float transferScale)
{

    //my_d_render<<<gridSize, blockSize>>>(d_output, imageW, imageH, density,
    //                                  brightness, transferOffset, transferScale,devPitchedPtr,devextent);
	d_render<<<gridSize, blockSize>>>(d_output, imageW, imageH, density,
                                      brightness, transferOffset, transferScale);
}



#endif // #ifndef _VOLUMERENDER_KERNEL_CU_
