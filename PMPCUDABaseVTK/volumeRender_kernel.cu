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

// ����������ԭʼ��������
typedef unsigned char VolumeType;
//typedef unsigned short VolumeType;

texture<VolumeType, 3, cudaReadModeNormalizedFloat> tex;         // 3D texture// 3D����
texture<float4, 1, cudaReadModeElementType>         transferTex; // 1D transfer function texture//ת���������

//__device__ cudaPitchedPtr d_PitchedPtr;

typedef struct
{
    float4 m[3];
} float3x4;

// �ӽǾ���λ��GPU�ĳ����洢��
__constant__ float3x4 c_invViewMatrix;  // inverse view matrix

// ������ߣ���ʼλ�úͷ���
struct Ray
{
    float3 o;   // origin
    float3 d;   // direction
};

// intersect ray with a box���� �ͺ����ཻ
// http://www.siggraph.org/education/materials/HyperGraph/raytrace/rtinter3.htm

__device__
int intersectBox(
Ray r, // ����
float3 boxmin,//  
float3 boxmax, //
float *tnear, // ������
float *tfar // Զ����
) 
{
	// ������������������ཻ�Ľ���
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

// ͨ�������ӽǾ��󣩱任������������ת����
// transform vector by matrix (no translation)
__device__
float3 mul(const float3x4 &M, const float3 &v)
{
    float3 r;
	// dot��ʾ��ˣ�Ҳ�����������������ڻ�
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
    rgba.x = __saturatef(rgba.x);   // clamp to [0.0, 1.0]����һ���������ݹ���0��1֮��
    rgba.y = __saturatef(rgba.y);
    rgba.z = __saturatef(rgba.z);
    rgba.w = __saturatef(rgba.w);

    return (uint(rgba.w*255)<<24) | (uint(rgba.z*255)<<16) | (uint(rgba.y*255)<<8) | uint(rgba.x*255);
}

__global__ void
d_render(
uint *d_output, //�������
uint imageW, //ͼ��Ŀ��
uint imageH,//ͼ��ĸ߶�
         float density, //ͼ���ܶ�
		 float brightness,//ͼ������
         float transferOffset, //����
		 float transferScale//�����Ϳ̶�
		 )
{
    const int maxSteps = 500;
    const float tstep = 0.01f;// ����
    const float opacityThreshold = 0.95f;// ͸���ȷ�ֵ
    const float3 boxMin = make_float3(-1.0f, -1.0f, -1.0f);// ��Χ�е���С�������
    const float3 boxMax = make_float3(1.0f, 1.0f, 1.0f);

	// �߳������������ϵ�����
    uint x = blockIdx.x*blockDim.x + threadIdx.x;
    uint y = blockIdx.y*blockDim.y + threadIdx.y;

    if ((x >= imageW) || (y >= imageH)) return;
	// �����ƽ����(-1,-1,-1)��(1,1,1)����ά�ռ�
    float u = (x / (float) imageW)*2.0f-1.0f;
    float v = (y / (float) imageH)*2.0f-1.0f;

    // calculate eye ray in world space
	// ������������ϵ�е�����
    Ray eyeRay;
    eyeRay.o = make_float3(mul(c_invViewMatrix, make_float4(0.0f, 0.0f, 0.0f, 1.0f)));
	// ��ʼ���߷���(u,v,-2λ��)
    eyeRay.d = normalize(make_float3(u, v, -2.0f));
	// ���ӽǵ����߷���
    eyeRay.d = mul(c_invViewMatrix, eyeRay.d);

    // find intersection with box
	// ͨ����Χ���㷨���������Ƿ����������ཻ
    float tnear, tfar;
    int hit = intersectBox(eyeRay, boxMin, boxMax, &tnear, &tfar);

    if (!hit) return;

    if (tnear < 0.0f) tnear = 0.0f;     // clamp to near plane// ������С��0����Ϊ0

    // march along ray from front to back, accumulating color
	// ������ߴ�ǰ���������ɫ
    float4 sum = make_float4(0.0f);
    float t = tnear;
    float3 pos = eyeRay.o + eyeRay.d*tnear;//��ʼλ��
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
	// ����ɫֵд���������
    // write output color
    d_output[y*imageW + x] = rgbaFloatToInt(sum);
}

// ���������˲�ģʽ
extern "C"
void setTextureFilterMode(bool bLinearFilter)
{
    tex.filterMode = bLinearFilter ? cudaFilterModeLinear : cudaFilterModePoint;
}


// ��ʼ��CUDA
extern "C"
void initCuda(void *h_volume, cudaExtent volumeSize)
{
	// ������ά����
    // create 3D array
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc<VolumeType>();
    checkCudaErrors(cudaMalloc3DArray(&d_volumeArray, &channelDesc, volumeSize));// ����GPU�ڴ�
	// �������ݵ�GPU
    // copy data to 3D array
    cudaMemcpy3DParms copyParams = {0};
    copyParams.srcPtr   = make_cudaPitchedPtr(h_volume, volumeSize.width*sizeof(VolumeType), volumeSize.width, volumeSize.height);
    copyParams.dstArray = d_volumeArray;
    copyParams.extent   = volumeSize;
    copyParams.kind     = cudaMemcpyHostToDevice;
    checkCudaErrors(cudaMemcpy3D(&copyParams));



	// �����������
    // set texture parameters
    tex.normalized = true;                      // access with normalized texture coordinates//ʹ�ñ�׼��������ϵ
    tex.filterMode = cudaFilterModeLinear;      // linear interpolation//���Բ�ֵ�˲�
    tex.addressMode[0] = cudaAddressModeClamp;  // clamp texture coordinates
    tex.addressMode[1] = cudaAddressModeClamp;
	//�����鵽3D����
    // bind array to 3D texture
    checkCudaErrors(cudaBindTextureToArray(tex, d_volumeArray, channelDesc));
	//����ת����������������������������ݵ���ɫ��ÿһ��float4Ϊȡ�����RGBA
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
	// ��1D�������ʽ����ɫת������󶨵�transferTex
    cudaChannelFormatDesc channelDesc2 = cudaCreateChannelDesc<float4>();
    cudaArray *d_transferFuncArray;
    checkCudaErrors(cudaMallocArray(&d_transferFuncArray, &channelDesc2, sizeof(transferFunc)/sizeof(float4), 1));
    checkCudaErrors(cudaMemcpyToArray(d_transferFuncArray, 0, 0, transferFunc, sizeof(transferFunc), cudaMemcpyHostToDevice));
	// ����3D����Ĳ���
    transferTex.filterMode = cudaFilterModeLinear;// ��ֵ��ʽ�����Բ�ֵ
    transferTex.normalized = true;    // access with normalized texture coordinates����һ���������꣺true
    transferTex.addressMode[0] = cudaAddressModeClamp;   // wrap texture coordinates//��ȡ����Ѱַ

	// ������󶨵�������
    // Bind the array to the texture
    checkCudaErrors(cudaBindTextureToArray(transferTex, d_transferFuncArray, channelDesc2));
}
// �ͷ�CUDA����
extern "C"
void freeCudaBuffers()
{
    checkCudaErrors(cudaFreeArray(d_volumeArray));
    checkCudaErrors(cudaFreeArray(d_transferFuncArray));
	
}



// �����ӽǾ���
extern "C"
void copyInvViewMatrix(float *invViewMatrix, size_t sizeofMatrix)
{
    checkCudaErrors(cudaMemcpyToSymbol(c_invViewMatrix, invViewMatrix, sizeofMatrix));
}
//////////////////////////////////////////////////////////////////////////////////////
//���������ڴ洢��������Ż�
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////////

__global__ void
my_d_render(
uint *d_output, //�������
uint imageW, //ͼ��Ŀ��
uint imageH,//ͼ��ĸ߶�
         float density, //ͼ���ܶ�
		 float brightness,//ͼ������
         float transferOffset, //����
		 float transferScale,//�����Ϳ̶�
		 cudaPitchedPtr devPitchedPtr,
		 cudaExtent devextent
		 )
{
    const int maxSteps = 500;
    const float tstep = 0.01f;// ����
    const float opacityThreshold = 0.95f;// ͸���ȷ�ֵ
    const float3 boxMin = make_float3(-1.0f, -1.0f, -1.0f);// ��Χ�е���С�������
    const float3 boxMax = make_float3(1.0f, 1.0f, 1.0f);

	char * devPtr = (char *)devPitchedPtr.ptr;
	size_t pitch = devPitchedPtr.pitch;
	size_t slicePitch = pitch*devextent.height;

	// �߳������������ϵ�����
    uint x = blockIdx.x*blockDim.x + threadIdx.x;
    uint y = blockIdx.y*blockDim.y + threadIdx.y;
	uint z = blockIdx.z*blockDim.z + threadIdx.z;

    if ((x >= imageW) || (y >= imageH)) return;
	// �����ƽ����(-1,-1,-1)��(1,1,1)����ά�ռ�
    float u = (x / (float) imageW)*2.0f-1.0f;
    float v = (y / (float) imageH)*2.0f-1.0f;

    // calculate eye ray in world space
	// ������������ϵ�е�����
    Ray eyeRay;
    eyeRay.o = make_float3(mul(c_invViewMatrix, make_float4(0.0f, 0.0f, 0.0f, 1.0f)));
	// ��ʼ���߷���(u,v,-2λ��)
    eyeRay.d = normalize(make_float3(u, v, -2.0f));
	// ���ӽǵ����߷���
    eyeRay.d = mul(c_invViewMatrix, eyeRay.d);

    // find intersection with box
	// ͨ����Χ���㷨���������Ƿ����������ཻ
    float tnear, tfar;
    int hit = intersectBox(eyeRay, boxMin, boxMax, &tnear, &tfar);

    if (!hit) return;

    if (tnear < 0.0f) tnear = 0.0f;     // clamp to near plane// ������С��0����Ϊ0

    // march along ray from front to back, accumulating color
	// ������ߴ�ǰ���������ɫ
    float4 sum = make_float4(0.0f);
    float t = tnear;
    float3 pos = eyeRay.o + eyeRay.d*tnear;//��ʼλ��
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
	// ����ɫֵд���������
    // write output color
    d_output[y*imageW + x] = rgbaFloatToInt(sum);
}

// ����ȫ�ִ洢������ ��ʼ��CUDA
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


	// ������ά����
    // create 3D array
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc<VolumeType>();
    checkCudaErrors(cudaMalloc3DArray(&d_volumeArray, &channelDesc, volumeSize));// ����GPU�ڴ�
	// �������ݵ�GPU
    // copy data to 3D array
    cudaMemcpy3DParms copyParams = {0};
    copyParams.srcPtr   = make_cudaPitchedPtr(h_volume, volumeSize.width*sizeof(VolumeType), volumeSize.width, volumeSize.height);
    copyParams.dstArray = d_volumeArray;
    copyParams.extent   = volumeSize;
    copyParams.kind     = cudaMemcpyHostToDevice;
    checkCudaErrors(cudaMemcpy3D(&copyParams));


	/*
	// �����������
    // set texture parameters
    tex.normalized = true;                      // access with normalized texture coordinates//ʹ�ñ�׼��������ϵ
    tex.filterMode = cudaFilterModeLinear;      // linear interpolation//���Բ�ֵ�˲�
    tex.addressMode[0] = cudaAddressModeClamp;  // clamp texture coordinates
    tex.addressMode[1] = cudaAddressModeClamp;
	//�����鵽3D����
    // bind array to 3D texture
    checkCudaErrors(cudaBindTextureToArray(tex, d_volumeArray, channelDesc));
	//*/
	//����ת����������������������������ݵ���ɫ��ÿһ��float4Ϊȡ�����RGBA
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
	// ��1D�������ʽ����ɫת������󶨵�transferTex
    cudaChannelFormatDesc channelDesc2 = cudaCreateChannelDesc<float4>();
    cudaArray *d_transferFuncArray;
    checkCudaErrors(cudaMallocArray(&d_transferFuncArray, &channelDesc2, sizeof(transferFunc)/sizeof(float4), 1));
    checkCudaErrors(cudaMemcpyToArray(d_transferFuncArray, 0, 0, transferFunc, sizeof(transferFunc), cudaMemcpyHostToDevice));
	// ����3D����Ĳ���
    transferTex.filterMode = cudaFilterModeLinear;// ��ֵ��ʽ�����Բ�ֵ
    transferTex.normalized = true;    // access with normalized texture coordinates����һ���������꣺true
    transferTex.addressMode[0] = cudaAddressModeClamp;   // wrap texture coordinates//��ȡ����Ѱַ

	// ������󶨵�������
    // Bind the array to the texture
    checkCudaErrors(cudaBindTextureToArray(transferTex, d_transferFuncArray, channelDesc2));
}

// ����CUDA�ں˽��������
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
