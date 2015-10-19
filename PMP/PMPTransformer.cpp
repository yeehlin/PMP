// PMPTransformer.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPTransformer.h"


#define DATA_TYPE float

// CPMPTransformer

CPMPTransformer::CPMPTransformer()
{
}

CPMPTransformer::~CPMPTransformer()
{
}
// ��ȡ�Ӵ��ĸ���
int CPMPTransformer::PMPStringSplit(CString str){
	str.Trim();
	int in=0;
	char *p[20];
	char *buf = (LPSTR)(LPCTSTR)str;
	while((p[in]=strtok(buf," "))!=NULL) {
		in++;
		buf=NULL; }
	return in;
}
void CPMPTransformer::PMPTransformToVTKForIsosurface(CString filename){
	
	//CString datafilename="struct.in";
	//CString str = "    48    48    36     2";
	//CStdioFile stdfile;
	//CString datalinestr;
	//stdfile.Open(datafilename,CStdioFile::modeRead | CStdioFile::typeText);
	//stdfile.ReadString(datalinestr);
	//int x,y,z,v;
	//
	int redux = 0,reduy = 0,reduz = 0;
	int nx=0,ny=0,nz=0,nn=0;
	float pf1=0.0,pf2=0.0;
	//char *des1;
	//char *des2;
	// �����ݿռ䳬����VSջ�ռ䣬ʹ��C���Թؼ���malloc������̬����
	//int data[MAX_POINTS][4];
	// �ȴ���ָ���ָ�룬�ٴ���ָ���ָ��
	DATA_TYPE **data;
	int x=0,y=0,z=0,v=0;
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	//////////////////////////////////////////////////////////////////////////

	//::MessageBox(NULL,_T(filename),_T("OK"),MB_OK);
	CStdioFile datafile;
	datafile.Open(filename,CFile::modeRead |CFile::shareDenyNone| CFile::typeText);
	CString datatype;
	// �����һ��
	datafile.ReadString(datatype);
	//printf(datatype);
	datatype.Trim();
	int in=this->PMPStringSplit(datatype);
	datafile.Close();
	//////////////////////////////////////////////////////////////////////////
	//printf("��ʼת��\n");
	// ���ȶ�һ�У���ȡ���ݵ�ά����Ϣ
	fp = fopen(filename,"r"); 
	str.Format("%s%s.vtk",filename,"Scalar");
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		printf("error open the file");
	} else { 
		if (in == 3)
		{
			//printf("������%d���Ӵ�",in);
			fscanf(fp,"%d %d %d",&nx,&ny,&nz);
		}else{
			//printf("������%d���Ӵ�",in);
			fscanf(fp,"%d %d %d ! System size %f%f     ! Phase fraction",&nx,&ny,&nz,&pf1,&pf2);
		}
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// ���������ַ�ʽ�����������������ݵ���ά�����
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
		//printf("���ݵ�������%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //��ָ���ƶ�����ʼ
		fscanf(fp,"%d %d %d %e",&redux,&reduy,&reduz,*(data+0)+0); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		//dex++;
		//printf("%d %d %d %e\n",redux,reduy,reduz,*(*(data+0)+0));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%d%d%d%e",&redux,&reduy,&reduz,*(data+i)+0); 
			//dex++;
		}

	}//��ȡֵ
	// ����ѡ��������ݣ���������̫�࣬�������
	//for(int i=0;i<100;i++){
		//printf("%d %d %d %d\n",*(*(data+i)+0),*(*(data+i)+1),*(*(data+i)+2),*(*(data+i)+3));
	//}
	//����vtkҪ��������ļ�����������ͨ��structured_points�ĸ�ʽ
	
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


	// ��ά��̬������Ȼ���������ͷ�
	//free(data);
	//�ȳ���Ԫ�ص�ָ�룬�ٳ���ָ���ָ��
	for(int i=0;i<Row;i++){
		free(*(data+i));
	}
	free(data);
	if (fp != NULL)
	{
		fclose(fp); 
	}
	//printf("����ת��\n");
}
// ת��3+1scalar���ݵ�vtk�ļ�
void CPMPTransformer::PMPTransformToVTKForScalar(CString filename){
	
	int nx=0,ny=0,nz=0,nn=0;
	// ���������������
	int redux=0,reduy=0,reduz=0;
	float pf1=0.0,pf2=0.0;
	//char *des1;
	//char *des2;
	// �����ݿռ䳬����VSջ�ռ䣬ʹ��C���Թؼ���malloc������̬����
	//int data[MAX_POINTS][4];
	// �ȴ���ָ���ָ�룬�ٴ���ָ���ָ��
	DATA_TYPE **data;
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	//printf("��ʼת��\n");
	// ���ȶ�һ�У���ȡ���ݵ�ά����Ϣ
	//////////////////////////////////////////////////////////////////////////
	CStdioFile datafile;
	datafile.Open(filename,CFile::modeRead |CFile::shareDenyNone | CFile::typeText);
	CString datatype;
	// �����һ��
	datafile.ReadString(datatype);
	datatype.Trim();
	int in=0;
	char *p[20];
	char *buf = (LPSTR)(LPCTSTR)datatype;
	while((p[in]=strtok(buf," "))!=NULL) {
		in++;
		buf=NULL; }
	datafile.Close();
	//////////////////////////////////////////////////////////////////////////
	fp = fopen(filename,"r"); 
	str.Format("%s%s.vtk",filename,"Scalar");
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		//printf("error open the file");
	} else { 
		if (in == 3)
		{
			fscanf(fp,"%d %d %d",&nx,&ny,&nz);
		}else{

			fscanf(fp,"%d %d %d ! System size %f%f     ! Phase fraction",&nx,&ny,&nz,&pf1,&pf2);
		}
		
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// ���������ַ�ʽ�����������������ݵ���ά�����
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
		//printf("���ݵ�������%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //��ָ���ƶ�����ʼ
		fscanf(fp,"%d %d %d %e",&redux,&reduy,&reduz,*(data+0)+0); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		//printf("%f %f %f %f\n",*(*(data+0)+0),*(*(data+0)+1),*(*(data+0)+2),*(*(data+0)+3));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%d %d %d %e",&redux,&reduy,&reduz,*(data+i)+0); 
		}

	}//��ȡֵ
	// ����ѡ��������ݣ���������̫�࣬�������
	//for(int i=0;i<100;i++){
		//printf("%d %d %d %d\n",*(*(data+i)+0),*(*(data+i)+1),*(*(data+i)+2),*(*(data+i)+3));
	//}
	//����vtkҪ��������ļ�����������ͨ��structured_points�ĸ�ʽ
	
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


	// ��ά��̬������Ȼ���������ͷ�
	//free(data);
	//�ȳ���Ԫ�ص�ָ�룬�ٳ���ָ���ָ��
	for(int i=0;i<Row;i++){
		free(*(data+i));
	}
	free(data);
	if (fp != NULL)
	{
		fclose(fp); 
	}
	//printf("����ת��\n");
}
// ת��vector�������ݵ�3D����
void CPMPTransformer::PMPTransformToVTKForVector3D(CString filename){
	int nx=0,ny=0,nz=0,nn=0;
	// ���������������
	int redux = 0,reduy = 0,reduz =0;
	DATA_TYPE **data;
	// û����������
	int dex=0; 
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	//printf("��ʼת��\n");
	// ���ȶ�һ�У���ȡ���ݵ�ά����Ϣ
	fp = fopen(filename,"r"); 
	str.Format("%s%s.vtk",filename,"Vector3D");
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		//printf("error open the file");
	} else { 
		fscanf(fp,"%d %d %d",&nx,&ny,&nz);
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// ���������ַ�ʽ�����������������ݵ���ά�����
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
		//printf("���ݵ�������%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //��ָ���ƶ�����ʼ
		fscanf(fp,"%d %d %d %f %f %f",&redux,&reduy,&reduz,*(data+0)+0,*(data+0)+1,*(data+0)+2); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		//dex++;
		//printf("%f %f %f %f %f %f\n",*(*(data+0)+0),*(*(data+0)+1),*(*(data+0)+2),*(*(data+0)+3),*(*(data+0)+4),*(*(data+0)+5));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%d %d %d %f %f %f",&redux,&reduy,&reduz,*(data+i)+0,*(data+i)+1,*(data+i)+2); 
			//dex++;
		}

	}

	//����vtkҪ��������ļ�����������ͨ��structured_points�ĸ�ʽ
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
		fprintf(vtk,"%f %f %f\n",*(*(data+i)+0),*(*(data+i)+1),*(*(data+i)+2));
	}
	if(vtk != NULL){fclose(vtk);}
	
	for(int i=0;i<Row;i++){
		free(*(data+i));
	}
	free(data);
	if(fp != NULL){fclose(fp);}
	
	//printf("����ת��\n");
}
// CPMPTransformer member functions
// ת��tensor���ݵ�scalar(3*3D--->1D)
void CPMPTransformer::PMPTransformToVTKForTensor1D(CString filename){
	// �����������
	int redux =0 ,reduy = 0,reduz =0;
	int nx=0,ny=0,nz=0,nn=0;
	float pf1=0.0,pf2=0.0;
	DATA_TYPE **data;
	// �����������
	DATA_TYPE redu22 = 0.0f,redu33 = 0.0f,redu23 = 0.0f,redu13 = 0.0f,redu12 = 0.0f;
	int dex=0; 
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	//printf("��ʼת��\n");
	// ���ȶ�һ�У���ȡ���ݵ�ά����Ϣ
	//::MessageBox(NULL,_T(filename),_T("��ʼת��"),MB_OK);
	fp = fopen(filename,"r"); 
	str.Format("%s%s.vtk",filename,"Tensor1D");
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		//printf("error open the file");
		::MessageBox(NULL,_T("��ʧ��"),_T("OK"),MB_OK);
	}else { 
		fscanf(fp,"%d%d%d",&nx,&ny,&nz);
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// ���������ַ�ʽ�����������������ݵ���ά�����
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
		//printf("���ݵ�������%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //��ָ���ƶ�����ʼ
		fscanf(fp,"%d %d %d %f %f %f %f %f %f",&redux,&reduy,&reduz,*(data+0)+0,&redu22,&redu33,&redu23,&redu13,&redu12); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		//dex++;
		//printf("%f %f %f %f %f %f %f %f %f\n",*(*(data+0)+0),*(*(data+0)+1),*(*(data+0)+2),*(*(data+0)+3),*(*(data+0)+4),*(*(data+0)+5),*(*(data+0)+6),*(*(data+0)+7),*(*(data+0)+8));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%d%d%d%f%f%f%f%f%f",&redux,&reduy,&reduz,*(data+i)+0,&redu22,&redu33,&redu23,&redu13,&redu12); 
			//dex++;
		}

	}

	//����vtkҪ��������ļ�����������ͨ��structured_points�ĸ�ʽ
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
	if (vtk != NULL){
		fclose(vtk);}
	for(int i=0;i<Row;i++){
		free(*(data+i));
	}
	free(data);
	if (fp != NULL)
	{fclose(fp);
	}
	
	//::MessageBox(NULL,_T("����ת��"),_T("OK"),MB_OK);
	//printf("����ת��\n");
}

void CPMPTransformer::PMPTransformToVTKForTensor(CString filename){
	// ��Ҫ��ȡ���ļ���strain.00000000.dat
	// �����������
	int redux=0,reduy=0,reduz=0;
	int nx=0,ny=0,nz=0,nn=0;
	DATA_TYPE **data;
	// �����������
	DATA_TYPE redu1=0.0f,redu2=0.0f,redu3=0.0f;
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	//printf("��ʼת��\n");
	// ���ȶ�һ�У���ȡ���ݵ�ά����Ϣ
	fp = fopen(filename,"r"); 
	str.Format("%s%s.vtk",filename,"Tensor");
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		//printf("error open the file");
	} else { 
		fscanf(fp,"%d %d %d",&nx,&ny,&nz);
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// ���������ַ�ʽ�����������������ݵ���ά�����
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
		printf("���ݵ�������%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //��ָ���ƶ�����ʼ
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

	//����vtkҪ��������ļ�����������ͨ��structured_points�ĸ�ʽ
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
	//printf("����ת��\n");
}

void CPMPTransformer::PMPTransformToVTKForScalar1D(CString filename,CString &outfilename){
	// �����������
	int redux = 0,reduy = 0,reduz = 0;
	int nx=0,ny=0,nz=0,nn=0;
	float pf1=0.0,pf2=0.0;
	//char *des1;
	//char *des2;
	// �����ݿռ䳬����VSջ�ռ䣬ʹ��C���Թؼ���malloc������̬����
	//int data[MAX_POINTS][4];
	// �ȴ���ָ���ָ�룬�ٴ���ָ���ָ��
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
	// �����һ��
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
	printf("��ʼת��\n");
	// ���ȶ�һ�У���ȡ���ݵ�ά����Ϣ
	fp = fopen(filename,"r"); 
	str.Format("%s%s",filename,"Scalar1D.vtk");
	printf("Scalar1D:outfilename:\n%s\n",(outfilename = str));
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		printf("error open the file");
	} else { 
		if (in == 3)
		{
			printf("������%d���Ӵ�\n",in);
			fscanf(fp,"%d %d %d",&nx,&ny,&nz);
		}else{
			printf("������%d���Ӵ�\n",in);
			fscanf(fp,"%d %d %d ! System size %f%f     ! Phase fraction",&nx,&ny,&nz,&pf1,&pf2);
		}
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// ���������ַ�ʽ�����������������ݵ���ά�����
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
		printf("���ݵ�������%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //��ָ���ƶ�����ʼ
		fscanf(fp,"%d %d %d %e",&redux,&reduy,&reduz,*(data+0)+0); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		dex++;
		printf("%d %d %d %e\n",redux,reduy,reduz,*(*(data+0)+0));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%d%d%d%e",&redux,&reduy,&reduz,*(data+i)+0); 
			dex++;
		}

	}//��ȡֵ
	// ����ѡ��������ݣ���������̫�࣬�������
	//for(int i=0;i<100;i++){
		//printf("%d %d %d %d\n",*(*(data+i)+0),*(*(data+i)+1),*(*(data+i)+2),*(*(data+i)+3));
	//}
	//����vtkҪ��������ļ�����������ͨ��structured_points�ĸ�ʽ
	
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


	// ��ά��̬������Ȼ���������ͷ�
	//free(data);
	//�ȳ���Ԫ�ص�ָ�룬�ٳ���ָ���ָ��
	for(int i=0;i<Row;i++){
		free(*(data+i));
	}
	free(data);
	if (fp != NULL)
	{
		fclose(fp); 
	}
	printf("����ת��\n");
}
void CPMPTransformer::PMPTransformToVTKForVector3D(CString filename,CString &outfilename){
	// ��ȡ��ת��Vector���͵�����
	// �����������
	int redux= 0,reduy=0,reduz=0;
	int nx=0,ny=0,nz=0,nn=0;
	DATA_TYPE **data;
	// û����������
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	printf("��ʼת��\n");
	// ���ȶ�һ�У���ȡ���ݵ�ά����Ϣ
	fp = fopen(filename,"r"); 
	str.Format("%s%s",filename,"Vector3D.vtk");
	printf("Vector3D:outfilename:\n%s\n",(outfilename = str));
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		printf("error open the file");
	} else { 
		fscanf(fp,"%d%d%d",&nx,&ny,&nz);
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// ���������ַ�ʽ�����������������ݵ���ά�����
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
		printf("���ݵ�������%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //��ָ���ƶ�����ʼ
		fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,*(data+0)+0,*(data+0)+1,*(data+0)+2); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		printf("%d %d %d %g %g %g\n",redux,reduy,reduz,*(*(data+0)+0),*(*(data+0)+1),*(*(data+0)+2));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,*(data+i)+0,*(data+i)+1,*(data+i)+2); 
		}

	}

	//����vtkҪ��������ļ�����������ͨ��structured_points�ĸ�ʽ
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
	printf("����ת��\n");
}
void CPMPTransformer::PMPTransformToVTKForTensor33D(CString filename,CString & outfilename){
	// ��Ҫ��ȡ���ļ����������������ļ�
	// �����������
	int redux=0,reduy=0,reduz=0;
	int nx=0,ny=0,nz=0,nn=0;
	DATA_TYPE **data;
	// û����������
	int Row =0;
	FILE * fp;
	FILE * vtk;
	CString str;
	printf("��ʼת��\n");
	// ���ȶ�һ�У���ȡ���ݵ�ά����Ϣ
	fp = fopen(filename,"r"); 
	str.Format("%s%s",filename,"Tensor33D.vtk");
	printf("Tensor33D:outfilename:\n%s\n",(outfilename=str));
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		printf("error open the file");
	} else { 
		fscanf(fp,"%d %d %d",&nx,&ny,&nz);
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// ���������ַ�ʽ�����������������ݵ���ά�����
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
		printf("���ݵ�������%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //��ָ���ƶ�����ʼ
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

	//����vtkҪ��������ļ�����������ͨ��structured_points�ĸ�ʽ
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
	printf("����ת��\n");
}
void CPMPTransformer::PMPTransformToVTKForVolume(CString filename,int column,CString & outfilename){
	// �����������
	int redux = 0,reduy=0,reduz=0;
	int nx=0,ny=0,nz=0,nn=0;
	DATA_TYPE **data;
	// �����������
	DATA_TYPE redu[10];
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	///////////////////////////////////�鿴��������///////////////////////////////////////
	CStdioFile datafile;
	datafile.Open(filename,CFile::modeRead |CFile::shareDenyNone | CFile::typeText);
	CString datatype;
	// �����һ��
	datafile.ReadString(datatype);
	// ����ڶ���
	datafile.ReadString(datatype);
	printf("�ڶ��У�%s\n",datatype);
	datatype.Trim();
	int in=0;
	char *p[20];
	char *buf = (LPSTR)(LPCTSTR)datatype;
	while((p[in]=strtok(buf," "))!=NULL) {
		in++;
		buf=NULL; }
	datafile.Close();
	////////////////////////////////////�鿴��������//////////////////////////////////////

	printf("�������ʹ��ţ�%d\n",in);
	printf("��ʼת��\n");
	// ���ȶ�һ�У���ȡ���ݵ�ά����Ϣ
	fp = fopen(filename,"r"); 
	switch(in){
		// scalar����
	case 4:
		str.Format("%s%s%d%s",filename,"Scalar1D",column,".vtk");
		break;
		// vector����
	case 6:
		str.Format("%s%s%d%s",filename,"Vector3D",column,".vtk");
		break;
		// tensor����
	case 9:
		str.Format("%s%s%d%s",filename,"Tensor33D",column,".vtk");
		break;
		// δ֪����
	default:
		break;
	}
	// �������ļ���
	printf("Volumn:outfilename:\n%s\n",(outfilename = str));
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		printf("error open the file");
	} else { 
		fscanf(fp,"%d %d %d",&nx,&ny,&nz);
		//printf("%d %d %d %f %f\n",nx,ny,nz,pf1,pf2);
		// ���������ַ�ʽ�����������������ݵ���ά�����
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
		printf("���ݵ�������%d\n",Row);
		switch(in){
			// scalar����
		case 4:
			{
				switch(column){
					// ȡ��1��
				case 1:
					fscanf(fp,"%d%d%d%g",&redux,&reduy,&reduz,*(data+0)+0);
					printf("%d %d %d %g\n",redux,reduy,reduz,*(*(data+0)+0));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g",&redux,&reduy,&reduz,*(data+i)+0); 
					} 
					break;
					// ȡδ֪��
				default:
					break;
				}
			}
			break;
			// vector����
		case 6:
			{
				switch(column){
					// ȡ��1��
				case 1:
					fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,*(data+0)+0,redu+0,redu+1);
					printf("%d %d %d %g %g %g\n",redux,reduy,reduz,*(*(data+0)+0),*(redu+0),*(redu+1));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,*(data+i)+0,redu+0,redu+1); 
					} 
					break;
					// ȡ��2��
				case 2:
					fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,redu+0,*(data+0)+0,redu+1);
					printf("%d %d %d %g %g %g\n",redux,reduy,reduz,*(redu+0),*(*(data+0)+0),*(redu+1));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,redu+0,*(data+i)+0,redu+1); 
					} 
					break;
					// ȡ��3��
				case 3:
					fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,*(data+0)+0);
					printf("%d %d %d %g %g %g\n",redux,reduy,reduz,*(redu+0),*(redu+1),*(*(data+0)+0));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,*(data+i)+0); 
					} 
					break;
					// ȡδ֪��
				default:
					break;
				}
			}
			break;
			// tensor����
		case 9:
			{
				switch(column){
					// ȡ��1��
				case 1:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,*(data+0)+0,redu+0,redu+1,redu+2,redu+3,redu+4);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(*(data+0)+0),*(redu+0),*(redu+1),*(redu+2),*(redu+3),*(redu+4));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,*(data+i)+0,redu+0,redu+1,redu+2,redu+3,redu+4); 
					} 
					break;
					// ȡ��2��
				case 2:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,*(data+0)+0,redu+1,redu+2,redu+3,redu+4);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(redu+0),*(*(data+0)+0),*(redu+1),*(redu+2),*(redu+3),*(redu+4));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,*(data+i)+0,redu+1,redu+2,redu+3,redu+4); 
					} 
					break;
					// ȡ��3��
				case 3:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,*(data+0)+0,redu+2,redu+3,redu+4);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(redu+0),*(redu+1),*(*(data+0)+0),*(redu+2),*(redu+3),*(redu+4));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,*(data+i)+0,redu+2,redu+3,redu+4); 
					} 
					break;
					// ȡ��4��
				case 4:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,*(data+0)+0,redu+3,redu+4);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(redu+0),*(redu+1),*(redu+2),*(*(data+0)+0),*(redu+3),*(redu+4));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,*(data+i)+0,redu+3,redu+4); 
					} 
					break;
					// ȡ��5��
				case 5:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,redu+3,*(data+0)+0,redu+4);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(redu+0),*(redu+1),*(redu+2),*(redu+3),*(*(data+0)+0),*(redu+4));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,redu+3,*(data+i)+0,redu+4); 
					} 
					break;
					// ȡ��6��
				case 6:
					fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,redu+3,redu+4,*(data+0)+0);
					printf("%d %d %d %g %g %g %g %g %g\n",redux,reduy,reduz,*(redu+0),*(redu+1),*(redu+2),*(redu+3),*(redu+4),*(*(data+0)+0));
					for(int i=1;i<Row;i++) 
					{
						fscanf(fp,"%d%d%d%g%g%g%g%g%g",&redux,&reduy,&reduz,redu+0,redu+1,redu+2,redu+3,redu+4,*(data+i)+0); 
					} 
					break;
					// ȡδ֪��
				default:
					break;
				}
			}
	
			break;
			// δ֪��������
		default:
			break;
		}

	}

	//����vtkҪ��������ļ�����������ͨ��structured_points�ĸ�ʽ
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
		fprintf(vtk,"%g\n",*(*(data+i)+0));
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
	printf("����ת��\n");
}
