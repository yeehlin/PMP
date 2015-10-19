#include "afx.h"
#include "stdio.h"
#include "malloc.h"

#include "vtkContourFilter.h"

#define DATA_TYPE float
#define DATA_TYPE_DOUBLE double

////////////////////////////////////转化数据的方式//////////////////////////////////////
//   标量
//   1、Scalar1D 4、Scalar1D1
//   向量
//   2、Vector3D 4、Vector1D1、Vector1D2、Vector1D3
//   张量（该张量对称）
//   3、Tensor33D 4、Vector1D1、...、Vector1D6
////////////////////////////////////转化数据的方式//////////////////////////////////////

// 转化Scalar类型数据，全取（共1列）
void PMPTransformToVTKForScalar1D(CString filename,CString &outfilename);
// 转化Vector类型数据，全取（共3列）
void PMPTransformToVTKForVector3D(CString filename,CString &outfilename);
// 转化Tensor类型数据，全取（共6列）
void PMPTransformToVTKForTensor33D(CString filename,CString &outfilename);
// 转化任意类型数据，取某一列
void PMPTransformToVTKForVolume(CString filename,int column,CString &outfilename);

// 旧的显示程序
void pmpvisualizationgrid();
void pmpvisualizationisosurface();
void pmpvisualizationvolume();
void pmpvisualizationpolarization();
void pmpvisualizationtensor();
void pmpvisualizationstreamline();
void pmpvisualizationmultiview();

// 新的显示程序
// 标量数据的等值面
void PMPVisualizeIsosurface(CString filename);
// 标量数据的体绘制
void PMPVisualizeVolumn(CString filename);
// Scalar数据可视化
void PMPVisualizeScalar1D(CString filename);
// Vector数据可视化
void PMPVisualizeVector3D(CString filename);
// Tensor数据可视化
void PMPVisualizeTensor33D(CString filename);
// Vector数据Streamline可视化
void PMPVisualizeVector3DStreamline(CString filename);
// Tensor数据Multiview
void PMPVisualizeTensor33DMultiview(CString filename);

// GPU加速算法
//GPU加速的体绘制算法
void PMPVisualizeVolumnGPU(CString filename);

// 测试程序
// 测试Scalar数据
void PMPScalarTest();
// 测试Vector数据
void PMPVectorTest();
// 测试Tensor数据
void PMPTensorTest();

// 测试GPU
void PMPVolumeGPUTest();

double isoValue1 ;
double isoValue2;
extern vtkContourFilter * contour;
extern vtkContourFilter * contour1;

//extern void GPUVolumeDemo();
void main(){
	PMPScalarTest();
	//PMPVectorTest();
	//PMPTensorTest();
	PMPVolumeGPUTest();
}

void PMPTransformToVTKForScalar1D(CString filename,CString &outfilename){
	// 存放冗余坐标
	int redux = 0,reduy = 0,reduz = 0;
	int nx=0,ny=0,nz=0,nn=0;
	float pf1=0.0,pf2=0.0;
	//char *des1;
	//char *des2;
	// 该数据空间超过了VS栈空间，使用C语言关键字malloc创建动态数组
	//int data[MAX_POINTS][4];
	// 先创建指针的指针，再创建指针的指针
	DATA_TYPE **data;
	int x=0,y=0,z=0,v=0;
	int dex=0; 
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	//////////////////////////////////////////////////////////////////////////
	CStdioFile datafile;
	datafile.Open(filename,CFile::modeRead | CFile::shareDenyNone | CFile::typeText);
	CString datatype;
	// 读入第一行
	datafile.ReadString(datatype);
	printf("%s\n",datatype);
	datatype.Trim();
	int in=0;
	char *p[20];
	char *buf = (LPSTR)(LPCTSTR)datatype;
	while((p[in]=strtok(buf," "))!=NULL) {
		in++;
		buf=NULL; }
	datafile.Close();
	//////////////////////////////////////////////////////////////////////////
	printf("开始转化\n");
	// 首先读一行，读取数据的维数信息
	fp = fopen(filename,"r"); 
	str.Format("%s%s",filename,"Scalar1D.vtk");
	printf("Scalar1D:outfilename:\n%s\n",(outfilename = str));
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		printf("error open the file");
	} else { 
		if (in == 3)
		{
			printf("首行有%d个子串\n",in);
			fscanf(fp,"%d %d %d",&nx,&ny,&nz);
		}else{
			printf("首行有%d个子串\n",in);
			fscanf(fp,"%d %d %d ! System size %f%f     ! Phase fraction",&nx,&ny,&nz,&pf1,&pf2);
		}
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// 不采用这种方式，规则是数据行数据等于维数相乘
		/*
		while((charTemp=fgetc(fp))!=EOF) 
		{ 
			if( charTemp == '\n') Row++; 
		}
		*/
		Row = nx*ny*nz;
		data = (DATA_TYPE * *)malloc(Row*sizeof(DATA_TYPE *));
		for (int i=0;i<Row;i++)
		{
			*(data + i) = (DATA_TYPE *)malloc(1*sizeof(DATA_TYPE));
		}
		printf("数据的行数：%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //将指针移动到开始
		fscanf(fp,"%d %d %d %e",&redux,&reduy,&reduz,*(data+0)+0); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		dex++;
		printf("%d %d %d %e\n",redux,reduy,reduz,*(*(data+0)+0));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%d%d%d%e",&redux,&reduy,&reduz,*(data+i)+0); 
			dex++;
		}

	}//读取值
	// 可以选择输出数据，但是数据太多，不宜输出
	//for(int i=0;i<100;i++){
		//printf("%d %d %d %d\n",*(*(data+i)+0),*(*(data+i)+1),*(*(data+i)+2),*(*(data+i)+3));
	//}
	//建立vtk要求的输入文件，采用最普通的structured_points的格式
	
	fprintf(vtk,"%s\n","# vtk DataFile Version 3.0");
	fprintf(vtk,"%s\n","Structured Points");
	fprintf(vtk,"%s\n","ASCII");
	fprintf(vtk,"\n");
	fprintf(vtk,"%s\n","DATASET STRUCTURED_POINTS");
	fprintf(vtk,"DIMENSIONS %d %d %d\n",nx,ny,nz);
	fprintf(vtk,"ORIGIN 1 1 1\n");
	fprintf(vtk,"SPACING 1 1 1\n");
	fprintf(vtk,"\n");
	fprintf(vtk,"POINT_DATA %d\n",Row);
	fprintf(vtk,"SCALARS scalars float\n");
	fprintf(vtk,"LOOKUP_TABLE default\n");
	for (int i=0;i<Row;i++)
	{
		fprintf(vtk,"%e\n",*(*(data+i)+0));
	}
	if (vtk != NULL)
	{
		fclose(vtk);
	}


	// 二维动态数据显然不能这样释放
	//free(data);
	//先撤销元素的指针，再撤销指针的指针
	for(int i=0;i<Row;i++){
		free(*(data+i));
	}
	free(data);
	if (fp != NULL)
	{
		fclose(fp); 
	}
	printf("结束转化\n");
}
void PMPTransformToVTKForVector3D(CString filename,CString &outfilename){
	// 读取并转化Vector类型的数据
	// 存放冗余坐标
	int redux= 0,reduy=0,reduz=0;
	int nx=0,ny=0,nz=0,nn=0;
	DATA_TYPE **data;
	// 没有冗余数据
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	printf("开始转化\n");
	// 首先读一行，读取数据的维数信息
	fp = fopen(filename,"r"); 
	str.Format("%s%s",filename,"Vector3D.vtk");
	printf("Vector3D:outfilename:\n%s\n",(outfilename = str));
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		printf("error open the file");
	} else { 
		fscanf(fp,"%d%d%d",&nx,&ny,&nz);
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// 不采用这种方式，规则是数据行数据等于维数相乘
		/*
		while((charTemp=fgetc(fp))!=EOF) 
		{ 
			if( charTemp == '\n') Row++; 
		}
		*/
		Row = nx*ny*nz;	
		data = (DATA_TYPE * *)malloc(Row*sizeof(DATA_TYPE *));
		for (int i=0;i<Row;i++)
		{
			*(data + i) = (DATA_TYPE *)malloc(3*sizeof(DATA_TYPE));
		}
		printf("数据的行数：%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //将指针移动到开始
		fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,*(data+0)+0,*(data+0)+1,*(data+0)+2); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		printf("%d %d %d %g %g %g\n",redux,reduy,reduz,*(*(data+0)+0),*(*(data+0)+1),*(*(data+0)+2));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,*(data+i)+0,*(data+i)+1,*(data+i)+2); 
		}

	}

	//建立vtk要求的输入文件，采用最普通的structured_points的格式
	fprintf(vtk,"%s\n","# vtk DataFile Version 3.0");
	fprintf(vtk,"%s\n","Structured Points");
	fprintf(vtk,"%s\n","ASCII");
	fprintf(vtk,"\n");
	fprintf(vtk,"%s\n","DATASET STRUCTURED_POINTS");
	fprintf(vtk,"DIMENSIONS %d %d %d\n",nx,ny,nz);
	fprintf(vtk,"ORIGIN 1 1 1\n");
	fprintf(vtk,"SPACING 1 1 1\n");
	fprintf(vtk,"\n");
	fprintf(vtk,"POINT_DATA %d\n",Row);
	fprintf(vtk,"VECTORS dispV float\n");
	for (int i=0;i<Row;i++)
	{
		fprintf(vtk,"%g %g %g\n",*(*(data+i)+0),*(*(data+i)+1),*(*(data+i)+2));
	}
	if (vtk != NULL)
	{
		fclose(vtk);
	}
	for(int i=0;i<Row;i++){
		free(*(data+i));
	}
	free(data);
	if (fp != NULL)
	{
		fclose(fp);
	}
	printf("结束转化\n");
}
void PMPTransformToVTKForTensor33D(CString filename,CString & outfilename){
	// 将要读取的文件类型是张量数据文件
	// 存放冗余坐标
	int redux=0,reduy=0,reduz=0;
	int nx=0,ny=0,nz=0,nn=0;
	DATA_TYPE **data;
	// 没有冗余数据
	int Row =0;
	FILE * fp;
	FILE * vtk;
	CString str;
	printf("开始转化\n");
	// 首先读一行，读取数据的维数信息
	fp = fopen(filename,"r"); 
	str.Format("%s%s",filename,"Tensor33D.vtk");
	printf("Tensor33D:outfilename:\n%s\n",(outfilename=str));
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		printf("error open the file");
	} else { 
		fscanf(fp,"%d %d %d",&nx,&ny,&nz);
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// 不采用这种方式，规则是数据行数据等于维数相乘
		/*
		while((charTemp=fgetc(fp))!=EOF) 
		{ 
			if( charTemp == '\n') Row++; 
		}
		*/
		Row = nx*ny*nz;	
		data = (DATA_TYPE * *)malloc(Row*sizeof(DATA_TYPE *));
		for (int i=0;i<Row;i++)
		{
			*(data + i) = (DATA_TYPE *)malloc(6*sizeof(DATA_TYPE));
		}
		printf("数据的行数：%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //将指针移动到开始
		fscanf(fp,"%d %d %d %g %g %g %g %g %g",&redux,&reduy,&reduz,*(data+0)+0,*(data+0)+1,*(data+0)+2,*(data+0)+3,*(data+0)+4,*(data+0)+5); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		//dex++;
		printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(*(data+0)+0),*(*(data+0)+1),*(*(data+0)+2),*(*(data+0)+3),*(*(data+0)+4),*(*(data+0)+5));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%d %d %d %g %g %g %g %g %g",&redux,&reduy,&reduz,*(data+i)+0,*(data+i)+1,*(data+i)+2,*(data+i)+3,*(data+i)+4,*(data+i)+5); 
			//dex++;
		}

	}

	//建立vtk要求的输入文件，采用最普通的structured_points的格式
	fprintf(vtk,"%s\n","# vtk DataFile Version 3.0");
	fprintf(vtk,"%s\n","Structured Points Example");
	fprintf(vtk,"%s\n","ASCII");
	fprintf(vtk,"\n");
	fprintf(vtk,"%s\n","DATASET STRUCTURED_POINTS");
	fprintf(vtk,"DIMENSIONS %d %d %d\n",nz,ny,nx);
	fprintf(vtk,"ORIGIN 0 0 0\n");
	fprintf(vtk,"SPACING 1 1 1\n");
	fprintf(vtk,"\n");
	fprintf(vtk,"POINT_DATA %d\n",Row);
	fprintf(vtk,"TENSORS strain float\n");
	for (int i=0;i<Row;i++)
	{
		fprintf(vtk,"%g %g %g\n",*(*(data+i)+0),*(*(data+i)+5),*(*(data+i)+4));
		fprintf(vtk,"%g %g %g\n",*(*(data+i)+5),*(*(data+i)+1),*(*(data+i)+3));
		fprintf(vtk,"%g %g %g\n",*(*(data+i)+4),*(*(data+i)+3),*(*(data+i)+2));
		fprintf(vtk,"\n");
	}
	if (vtk != NULL)
	{
		fclose(vtk);
	}
	for(int i=0;i<Row;i++){
		free(*(data+i));
	}
	free(data);
	if (fp != NULL)
	{
		fclose(fp);
	}
	printf("结束转化\n");
}
void PMPTransformToVTKForVolume(CString filename,int column,CString & outfilename){
	// 存放冗余坐标
	int redux = 0,reduy=0,reduz=0;
	int nx=0,ny=0,nz=0,nn=0;
	DATA_TYPE **data;
	// 存放冗余数据
	DATA_TYPE redu[10];
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	///////////////////////////////////查看数据类型///////////////////////////////////////
	CStdioFile datafile;
	datafile.Open(filename,CFile::modeRead |CFile::shareDenyNone | CFile::typeText);
	CString datatype;
	// 读入第一行
	datafile.ReadString(datatype);
	// 读入第二行
	datafile.ReadString(datatype);
	printf("第二行：%s\n",datatype);
	datatype.Trim();
	int in=0;
	char *p[20];
	char *buf = (LPSTR)(LPCTSTR)datatype;
	while((p[in]=strtok(buf," "))!=NULL) {
		in++;
		buf=NULL; }
	datafile.Close();
	////////////////////////////////////查看数据类型//////////////////////////////////////

	printf("数据类型代号：%d\n",in);
	printf("开始转化\n");
	// 首先读一行，读取数据的维数信息
	fp = fopen(filename,"r"); 
	switch(in){
		// scalar类型
	case 4:
		str.Format("%s%s%d%s",filename,"Scalar1D",column,".vtk");
		break;
		// vector类型
	case 6:
		str.Format("%s%s%d%s",filename,"Vector3D",column,".vtk");
		break;
		// tensor类型
	case 9:
		str.Format("%s%s%d%s",filename,"Tensor33D",column,".vtk");
		break;
		// 未知类型
	default:
		break;
	}
	// 输出输出文件名
	printf("Volumn:outfilename:\n%s\n",(outfilename = str));
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		printf("error open the file");
	} else { 
		fscanf(fp,"%d %d %d",&nx,&ny,&nz);
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// 不采用这种方式，规则是数据行数据等于维数相乘
		/*
		while((charTemp=fgetc(fp))!=EOF) 
		{ 
			if( charTemp == '\n') Row++; 
		}
		*/
		Row = nx*ny*nz;
		data = (DATA_TYPE * *)malloc(Row*sizeof(DATA_TYPE *));
		for (int i=0;i<Row;i++)
		{
			*(data + i) = (DATA_TYPE *)malloc(1*sizeof(DATA_TYPE));
		}
		printf("数据的行数：%d\n",Row);
		switch(in){
			// scalar数据
		case 4:
			{
				switch(column){
					// 取第1列
				case 1:
					fscanf(fp,"%d%d%d%g",&redux,&reduy,&reduz,*(data+0)+0);
					printf("%d %d %d %g\n",redux,reduy,reduz,*(*(data+0)+0));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g",&redux,&reduy,&reduz,*(data+i)+0); 
					} 
					break;
					// 取未知列
				default:
					break;
				}
			}
			break;
			// vector数据
		case 6:
			{
				switch(column){
					// 取第1列
				case 1:
					fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,*(data+0)+0,redu+0,redu+1);
					printf("%d %d %d %g %g %g\n",redux,reduy,reduz,*(*(data+0)+0),*(redu+0),*(redu+1));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,*(data+i)+0,redu+0,redu+1); 
					} 
					break;
					// 取第2列
				case 2:
					fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,redu+0,*(data+0)+0,redu+1);
					printf("%d %d %d %g %g %g\n",redux,reduy,reduz,*(redu+0),*(*(data+0)+0),*(redu+1));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,redu+0,*(data+i)+0,redu+1); 
					} 
					break;
					// 取第3列
				case 3:
					fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,*(data+0)+0);
					printf("%d %d %d %g %g %g\n",redux,reduy,reduz,*(redu+0),*(redu+1),*(*(data+0)+0));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,*(data+i)+0); 
					} 
					break;
					// 取未知列
				default:
					break;
				}
			}
			break;
			// tensor数据
		case 9:
			{
				switch(column){
					// 取第1列
				case 1:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,*(data+0)+0,redu+0,redu+1,redu+2,redu+3,redu+4);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(*(data+0)+0),*(redu+0),*(redu+1),*(redu+2),*(redu+3),*(redu+4));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,*(data+i)+0,redu+0,redu+1,redu+2,redu+3,redu+4); 
					} 
					break;
					// 取第2列
				case 2:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,*(data+0)+0,redu+1,redu+2,redu+3,redu+4);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(redu+0),*(*(data+0)+0),*(redu+1),*(redu+2),*(redu+3),*(redu+4));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,*(data+i)+0,redu+1,redu+2,redu+3,redu+4); 
					} 
					break;
					// 取第3列
				case 3:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,*(data+0)+0,redu+2,redu+3,redu+4);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(redu+0),*(redu+1),*(*(data+0)+0),*(redu+2),*(redu+3),*(redu+4));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,*(data+i)+0,redu+2,redu+3,redu+4); 
					} 
					break;
					// 取第4列
				case 4:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,*(data+0)+0,redu+3,redu+4);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(redu+0),*(redu+1),*(redu+2),*(*(data+0)+0),*(redu+3),*(redu+4));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,*(data+i)+0,redu+3,redu+4); 
					} 
					break;
					// 取第5列
				case 5:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,redu+3,*(data+0)+0,redu+4);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(redu+0),*(redu+1),*(redu+2),*(redu+3),*(*(data+0)+0),*(redu+4));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,redu+3,*(data+i)+0,redu+4); 
					} 
					break;
					// 取第6列
				case 6:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,redu+3,redu+4,*(data+0)+0);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(redu+0),*(redu+1),*(redu+2),*(redu+3),*(redu+4),*(*(data+0)+0));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,redu+3,redu+4,*(data+i)+0); 
					} 
					break;
					// 取未知列
				default:
					break;
				}
			}
	
			break;
			// 未知数据类型
		default:
			break;
		}

	}

	//建立vtk要求的输入文件，采用最普通的structured_points的格式
	fprintf(vtk,"%s\n","# vtk DataFile Version 3.0");
	fprintf(vtk,"%s\n","Structured Points");
	fprintf(vtk,"%s\n","ASCII");
	fprintf(vtk,"\n");
	fprintf(vtk,"%s\n","DATASET STRUCTURED_POINTS");
	fprintf(vtk,"DIMENSIONS %d %d %d\n",nx,ny,nz);
	fprintf(vtk,"ORIGIN 1 1 1\n");
	fprintf(vtk,"SPACING 1 1 1\n");
	fprintf(vtk,"\n");
	fprintf(vtk,"POINT_DATA %d\n",Row);
	fprintf(vtk,"SCALARS scalars float\n");
	fprintf(vtk,"LOOKUP_TABLE default\n");
	for (int i=0;i<Row;i++)
	{
		fprintf(vtk,"%f\n",*(*(data+i)+0));
	}
	if (vtk != NULL)
	{
		fclose(vtk);
	}
	for(int i=0;i<Row;i++){
		free(*(data+i));
	}
	free(data);
	if (fp!=NULL)
	{
		fclose(fp);
	}
	printf("结束转化\n");
}

void PMPScalarTest(){
	// 转化
	CString inputfile;
	CString filename="conc.00000000.datScalar1D.vtk";
	printf("input the name of data file:\n");
	//scanf("%s",inputfile);
	//PMPTransformToVTKForScalar1D(inputfile,filename);
	// Scalar数据可视化
	//PMPVisualizeScalar1D(inputfile);
	// 体绘制转化
	// Scalar数据的默认转化就是体数据转化
	// 显示体绘制
	PMPVisualizeVolumn(filename);
	// 等值面绘制
	// Scalar数据的默认绘图就PMPVisualizeScalar1D()是等值面绘制
}
void PMPVectorTest(){
	// 转化
	CString inputfile;
	CString filename;
	printf("input the name of data file:\n");
	scanf("%s",inputfile);
	//PMPTransformToVTKForVector3D(inputfile,filename);
	
	// Vector数据可视化
	//PMPVisualizeVector3D(inputfile);
	
	// Vector数据Streamline可视化
	PMPVisualizeVector3DStreamline(filename);
	
	// 体数据转化
	//PMPTransformToVTKForVolume(inputfile,1,filename);
	// Vector数据体绘制
	//PMPVisualizeVolumn(filename);
	//PMPTransformToVTKForVolume(inputfile,2,filename);
	//PMPVisualizeVolumn(filename);
	//PMPTransformToVTKForVolume(inputfile,3,filename);
	//PMPVisualizeVolumn(filename);
	
}
void PMPTensorTest(){
	// 转化
	CString inputfile;
	CString filename;
	printf("input the name of data file:\n");
	scanf("%s",inputfile);
	//PMPTransformToVTKForTensor33D(inputfile,filename);
	// 显示
	//PMPVisualizeTensor33D(inputfile);
	// Multiview显示
	//PMPVisualizeTensor33DMultiview(filename);
	PMPVisualizeVolumn(inputfile);
	//for (int i = 1;i<=6;i++)
	//{
		// 转化
		//PMPTransformToVTKForVolume(inputfile,i,filename);
		// 显示
		//PMPVisualizeVolumn(filename);
	//}
	
}

void PMPVolumeGPUTest(){
	// 转化
	CString inputfile;
	CString filename="conc.00000000.datScalar1D.vtk";
	printf("input the name of data file:\n");
	printf("%s\n",filename);
	//scanf("%s",inputfile);
	//PMPTransformToVTKForScalar1D(inputfile,filename);
	// Scalar数据可视化
	//PMPVisualizeScalar1D(inputfile);
	// 体绘制转化
	// Scalar数据的默认转化就是体数据转化
	// 显示体绘制
	PMPVisualizeVolumnGPU(filename);
	// 等值面绘制
	// Scalar数据的默认绘图就PMPVisualizeScalar1D()是等值面绘制
}