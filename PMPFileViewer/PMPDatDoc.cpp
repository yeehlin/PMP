// PMPDatDoc.cpp : implementation file
//

#include "stdafx.h"
#include "PMPDatView.h"
#include "PMPDatDoc.h"

#include "stdio.h"
#include "malloc.h"

#define MAX_POINTS 110592
#define DATA_TYPE float


// CPMPDatDoc

IMPLEMENT_DYNCREATE(CPMPDatDoc, CDocument)

CPMPDatDoc::CPMPDatDoc()
{
}

BOOL CPMPDatDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CPMPDatDoc::~CPMPDatDoc()
{
}


BEGIN_MESSAGE_MAP(CPMPDatDoc, CDocument)
END_MESSAGE_MAP()


// CPMPDatDoc diagnostics

#ifdef _DEBUG
void CPMPDatDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPDatDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CPMPDatDoc serialization

void CPMPDatDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
		CString strfilename = ar.m_strFileName;
		
		CString temp = ar.GetFile()->GetFileName().Left(3);
		//::MessageBox(NULL,_T(temp),_T("OK"),MB_OK);
		if (temp == _T("str")){
			this->PMPTransformToVTKForVolume(strfilename);
			this->pmpvisualizationvolume(strfilename+".vtk");
		}
		if (temp == _T("ele")){
			this->PMPTransformToVTKForPolarization(strfilename);
			this->pmpvisualizationpolarization(strfilename+".vtk");
		}

	}
}
#endif


// CPMPDatDoc commands

void CPMPDatDoc::PMPTransformToVTKForVolume(CString filename){
	int nx=0,ny=0,nz=0,nn=0;
	float pf1=0.0,pf2=0.0;
	DATA_TYPE **data;
	data = (DATA_TYPE * *)malloc(MAX_POINTS*sizeof(DATA_TYPE *));
	for (int i=0;i<MAX_POINTS;i++)
	{
		*(data + i) = (DATA_TYPE *)malloc(9*sizeof(DATA_TYPE));
	}
	int dex=0; 
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	//printf("开始转化\n");
	// 首先读一行，读取数据的维数信息
	//::MessageBox(NULL,_T(filename),_T("开始转换"),MB_OK);
	fp = fopen(filename,"r"); 
	str.Format("%s.vtk",filename);
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		//printf("error open the file");
		::MessageBox(NULL,_T("打开失败"),_T("OK"),MB_OK);
	}else { 
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
		//printf("数据的行数：%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //将指针移动到开始
		fscanf(fp,"%f%f%f%f%f%f%f%f%f",*(data+0)+0,*(data+0)+1,*(data+0)+2,*(data+0)+3,*(data+0)+4,*(data+0)+5,*(data+0)+6,*(data+0)+7,*(data+0)+8); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		//dex++;
		//printf("%f %f %f %f %f %f %f %f %f\n",*(*(data+0)+0),*(*(data+0)+1),*(*(data+0)+2),*(*(data+0)+3),*(*(data+0)+4),*(*(data+0)+5),*(*(data+0)+6),*(*(data+0)+7),*(*(data+0)+8));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%f%f%f%f%f%f%f%f%f",*(data+i)+0,*(data+i)+1,*(data+i)+2,*(data+i)+3,*(data+i)+4,*(data+i)+5,*(data+i)+6,*(data+i)+7,*(data+i)+8); 
			//dex++;
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
	for (int i=0;i<MAX_POINTS;i++)
	{
		fprintf(vtk,"%f\n",*(*(data+i)+3));
	}
	if (vtk != NULL){
		fclose(vtk);}
	for(int i=0;i<MAX_POINTS;i++){
		free(*(data+i));
	}
	free(data);
	if (fp != NULL)
	{fclose(fp);
	}
	
	//::MessageBox(NULL,_T("结束转换"),_T("OK"),MB_OK);
	//printf("结束转化\n");
}
void CPMPDatDoc::PMPTransformToVTKForPolarization(CString filename){
	int nx=0,ny=0,nz=0,nn=0;
	float pf1=0.0,pf2=0.0;
	DATA_TYPE **data;
	data = (DATA_TYPE * *)malloc(MAX_POINTS*sizeof(DATA_TYPE *));
	for (int i=0;i<MAX_POINTS;i++)
	{
		*(data + i) = (DATA_TYPE *)malloc(6*sizeof(DATA_TYPE));
	}
	int dex=0; 
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	//printf("开始转化\n");
	// 首先读一行，读取数据的维数信息
	fp = fopen(filename,"r"); 
	str.Format("%s.vtk",filename);
	vtk = fopen(str,"w"); 
	if(NULL == fp) {
		//printf("error open the file");
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
		//printf("数据的行数：%d\n",Row);
		//fp = fopen("struct.in","a+"); 
		//rewind(fp); //将指针移动到开始
		fscanf(fp,"%f%f%f%f%f%f",*(data+0)+0,*(data+0)+1,*(data+0)+2,*(data+0)+3,*(data+0)+4,*(data+0)+5); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		//dex++;
		//printf("%f %f %f %f %f %f\n",*(*(data+0)+0),*(*(data+0)+1),*(*(data+0)+2),*(*(data+0)+3),*(*(data+0)+4),*(*(data+0)+5));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%f%f%f%f%f%f",*(data+i)+0,*(data+i)+1,*(data+i)+2,*(data+i)+3,*(data+i)+4,*(data+i)+5); 
			//dex++;
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
	for (int i=0;i<MAX_POINTS;i++)
	{
		fprintf(vtk,"%f %f %f\n",*(*(data+i)+3),*(*(data+i)+4),*(*(data+i)+5));
	}
	if(vtk != NULL){fclose(vtk);}
	
	for(int i=0;i<MAX_POINTS;i++){
		free(*(data+i));
	}
	free(data);
	if(fp != NULL){fclose(fp);}
	
	//printf("结束转化\n");
}
void CPMPDatDoc::pmpvisualizationpolarization(CString filename){

//	printf("input the name of vtk file:\n");
	//scanf("%s",filename);
	//CString file_name = "vector.vtk";

	//# Read the source file.
	vtkDataSetReader * reader = vtkDataSetReader::New();
	reader->SetFileName(filename);
	reader->Update();
	//# Needed because of GetScalarRange
	vtkDataSet * id = reader->GetOutput();
	//double  * scalar_range = id->GetPointData()->GetArray(0)->GetRange();
	//printf("%f ",&scalar_range);
	//print(scalar_range);

	//# Create the mapper that corresponds the objects of the vtk file
	//# into graphics elements

	vtkArrowSource *arrow = vtkArrowSource::New();
	arrow->Update();
	vtkMaskPoints * mask = vtkMaskPoints::New();
	mask->SetOnRatio(10);
	mask->SetInputData(id);
	mask->Update();
	vtkGlyph3D * glyph = vtkGlyph3D::New();
	glyph->SetSourceConnection(arrow->GetOutputPort());
	glyph->SetInputData(mask->GetOutput());
	glyph->OrientOn();
	glyph->SetVectorModeToUseVector();
	glyph->SetColorModeToColorByVector();
	glyph->SetScaleModeToScaleByVector();
	glyph->SetScaleFactor(100000);

	vtkOutlineFilter * outline=vtkOutlineFilter::New();
	outline->SetInputData(reader->GetOutput());

	vtkDataSetMapper * mapper = vtkDataSetMapper::New();
	mapper->SetInputConnection(glyph->GetOutputPort());
	mapper->SetScalarRange(-0.00001,0.00001);

	vtkPolyDataMapper * outlineMapper=vtkPolyDataMapper::New();
	outlineMapper->SetInputConnection(outline->GetOutputPort());
	//# Create the Actor
	vtkActor * actor = vtkActor::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetOpacity(0.5);
	actor->GetProperty()->SetRepresentationToSurface();

	vtkTransform * transform=vtkTransform::New();
	transform->Translate(-5,0.0,0.0);
	vtkAxesActor * axes=vtkAxesActor::New();
	axes->SetUserTransform(transform);
	axes->SetScale(10);
	axes->SetTotalLength(10,10,10);
	axes->GetXAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
	axes->GetYAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
	axes->GetZAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
	vtkActor *outlineActor=vtkActor::New();
	outlineActor->SetMapper(outlineMapper);
	outlineActor->GetProperty()->SetColor(0,0,0);
	//#actor.GetProperty().SetOrigin(1.0,1.0,1.0);
	// Create the Renderer
	//vtkRenderer *renderer = vtkRenderer::New();
	POSITION pos = this->GetFirstViewPosition();
	CPMPDatView * pCPMPView = (CPMPDatView *)this->GetNextView(pos);
	//CMainFrame * pFrame = (CMainFrame*)AfxGetMainWnd();
	//CMainFrame * pFrame = (CMainFrame *)AfxGetMainWnd();
	//CVTKMFCCreatePolyActorsView* pCVTKMFCCreatePolyActorsView = (CVTKMFCCreatePolyActorsView *)pFrame->GetActiveView();
	//if (this->pvtkActor){
	//	pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(this->pvtkActor);
	//}
	pCPMPView->GetRenderer()->AddActor(actor);
	pCPMPView->GetRenderer()->AddActor(outlineActor);
	pCPMPView->GetRenderer()->AddActor(axes);
	pCPMPView->GetRenderer()->SetBackground(0.9, 0.9, 0.9);
	//# Set background to white

	// Create the RendererWindow
	//vtkRenderWindow * renderer_window = vtkRenderWindow::New();
	//renderer_window->AddRenderer(renderer);

	//# Create the RendererWindowInteractor and display the vtk_file
	//vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
	//interactor->SetRenderWindow(renderer_window);
	//interactor->Initialize();
	//interactor->Start();

	//arrow->Delete();
	//mask->Delete();
	//glyph->Delete();
	//outline->Delete();
	//mapper->Delete();
	//outlineMapper->Delete();
	//actor->Delete();
	//transform->Delete();
	//axes->Delete();
	//outlineActor->Delete();
	//renderer->Delete();
	//renderer_window->Delete();
	//interactor->Delete();
	//interactor->Delete();
	//renderer_window->Delete();
}

void CPMPDatDoc::pmpvisualizationvolume(CString filename){
	//CString file_name = "strain.vtk";
	
	//printf("input the name of vtk file:\n");
	//scanf("%s",filename);
	//# Read the source file.
	vtkDataSetReader * reader = vtkDataSetReader::New();
	reader->SetFileName(filename);
	reader->Update();
	//# Needed because of GetScalarRange
	vtkDataSet * id = reader->GetOutput();
	double * scalar_range = id->GetPointData()->GetArray(0)->GetRange();
	//print(id);
	//print(scalar_range);

	vtkLookupTable * colormap = vtkLookupTable::New();
	colormap->SetHueRange(0.333333,0.6666667);
	colormap->SetSaturationRange(0,0);
	colormap->SetAlphaRange(0.5,0.5);
	colormap->SetValueRange(scalar_range);

	vtkContourFilter * contour = vtkContourFilter::New();
	contour->SetInputData(id);
	contour->SetValue(0,1);
	contour->ComputeScalarsOn();
	vtkContourFilter *contour1 = vtkContourFilter::New();
	contour1->SetInputData(id);
	contour1->ComputeScalarsOn();
	contour1->SetValue(1,2);
	//# Create the mapper that corresponds the objects of the vtk file
	//# into graphics elements
	vtkSmartVolumeMapper * mapper = vtkSmartVolumeMapper::New();
	mapper->SetInputConnection(reader->GetOutputPort());

	//#mapper->SetScalarRange(scalar_range)
	//#mapper->SetLookupTable(colormap)

	vtkDataSetMapper *mapper1 = vtkDataSetMapper::New();
	mapper1->SetInputConnection(contour->GetOutputPort());
	mapper1->SetScalarRange(scalar_range);

	vtkDataSetMapper *mapper2 = vtkDataSetMapper::New();
	mapper2->SetInputConnection(contour1->GetOutputPort());
	mapper2->SetScalarRange(scalar_range);
	//# Create the Actor


	vtkVolume *actor = vtkVolume::New();
	actor->SetMapper(mapper);
	vtkVolumeProperty * volumeProperty= vtkVolumeProperty::New();
	vtkPiecewiseFunction * opacity= vtkPiecewiseFunction::New();
	opacity->AddPoint(scalar_range[0],0.3);
	opacity->AddPoint((scalar_range[0]+scalar_range[1])/8,0.3);
	opacity->AddPoint((scalar_range[0]+scalar_range[1])/8,0.05);
	opacity->AddPoint(6*(scalar_range[0]+scalar_range[1])/8,0.05);
	opacity->AddPoint(6*(scalar_range[0]+scalar_range[1])/8,0.3);
	opacity->AddPoint(scalar_range[1],0.3);

	vtkColorTransferFunction * color=vtkColorTransferFunction::New();
	color->SetColorSpaceToLab();
	color->AddRGBPoint(scalar_range[0],0.0,0.0,1.0);
	color->AddRGBPoint((scalar_range[0]+scalar_range[1])/2,0,1,0);
	color->AddRGBPoint(scalar_range[1],1.0,0.0,0.0);

	vtkPiecewiseFunction * gradOpacity = vtkPiecewiseFunction::New();
	gradOpacity->AddPoint(scalar_range[0],0);
	gradOpacity->AddPoint(scalar_range[1],0.3);

	volumeProperty->SetScalarOpacity(opacity);
	volumeProperty->SetColor(color);
	//#volumeProperty->SetGradientOpacity(gradOpacity);
	volumeProperty->SetInterpolationTypeToNearest();

	actor->SetProperty(volumeProperty);
	//#actor->GetProperty()->SetColor(0,0,0);
	//#actor->GetProperty()->SetOpacity(0.5);
	//#actor->GetProperty()->SetRepresentationToVolume();;

	vtkActor * actor1 = vtkActor::New();
	actor1->SetMapper(mapper1);
	vtkActor *actor2 = vtkActor::New();
	actor2->SetMapper(mapper2);

	//#actor->GetProperty()->SetOrigin(1.0,1.0,1.0)
	//# Create the Renderer
	//vtkRenderer * renderer = vtkRenderer::New();
	POSITION pos = this->GetFirstViewPosition();
	CPMPDatView * pCPMPView = (CPMPDatView *)this->GetNextView(pos);
	pCPMPView->GetRenderer()->AddActor(actor);
	//#renderer->AddActor(actor1)
	//#renderer->AddActor(actor2)
	pCPMPView->GetRenderer()->SetBackground(1, 1, 1);
	//# Set background to white

	//# Create the RendererWindow
	//vtkRenderWindow * renderer_window = vtkRenderWindow::New();
	//renderer_window->AddRenderer(renderer);
	//print(scalar_range[0],scalar_range[1]);
	//# Create the RendererWindowInteractor and display the vtk_file
	//vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
	//interactor->SetRenderWindow(renderer_window);
	//#style=vtkInteractorStyleTrackballActor()
	//#interactor->SetInteractorSytle(style)
	//#style->SetCurrentStyleToTrackballCamera()

	//interactor->Initialize();
	//interactor->Start();

}