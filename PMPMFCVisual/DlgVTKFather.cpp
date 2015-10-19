// DlgVTKFather.cpp : implementation file
//

#include "stdafx.h"
#include "PMPMFCVisual.h"
#include "DlgVTKFather.h"
#include "afxdialogex.h"

#include "vtkCallbackCommand.h"

#include "vtkLookupTable.h"
#include "vtkContourFilter.h"

#include "vtkProperty.h"
#include "vtkPointData.h"

#include "stdio.h"
#include "malloc.h"

#define MAX_POINTS 110592
#define DATA_TYPE float


// DlgVTKFather dialog

IMPLEMENT_DYNAMIC(DlgVTKFather, CDialog)

DlgVTKFather::DlgVTKFather(CWnd* pParent /*=NULL*/)
	: CDialog(DlgVTKFather::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	this->pvtkMFCWindow     = NULL;

	// set data reader to null
	this->pvtkDataSetReader = NULL;

	// Create the the renderer, window and interactor objects.
	this->pvtkRenderer    = vtkRenderer::New();

	// Create the the objects used to form the visualisation.
	this->pvtkDataSetMapper  = vtkDataSetMapper::New();
	this->pvtkActor      = vtkActor::New();
	this->pvtkActor2D    = vtkActor2D::New();
	this->pvtkTextMapper  = vtkTextMapper::New();

	this->ptBorder = CPoint(0,0);
	m_pdlgVTKChild = new DlgVTKChild();
}

DlgVTKFather::~DlgVTKFather()
{

}

void DlgVTKFather::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_VTK_FATHER, m_TabVtkFather);
}


BEGIN_MESSAGE_MAP(DlgVTKFather, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_FILE, &DlgVTKFather::OnBnClickedButtonFile)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// DlgVTKFather message handlers

void DlgVTKFather::ExecutePipeline()
{
	if (pvtkDataSetReader)  // have file
	{
		this->pvtkDataSetMapper->SetInputConnection(pvtkDataSetReader->GetOutputPort());
		this->pvtkActor->SetMapper(this->pvtkDataSetMapper);

		this->pvtkTextMapper->SetInput(pvtkDataSetReader->GetFileName());
		this->pvtkTextMapper->GetTextProperty()->SetFontSize(12);
		this->pvtkActor2D->SetMapper(this->pvtkTextMapper);

		this->pvtkRenderer->SetBackground(0.0,0.0,0.4);
		this->pvtkRenderer->AddActor(this->pvtkActor);
		this->pvtkRenderer->AddActor(this->pvtkActor2D);
	}
	else  // have no file
	{
		this->pvtkTextMapper->SetInput("Hello World");
		this->pvtkTextMapper->GetTextProperty()->SetFontSize(24);
		this->pvtkActor2D->SetMapper(this->pvtkTextMapper);

		this->pvtkRenderer->SetBackground(0.0,0.0,0.4);
		this->pvtkRenderer->AddActor(this->pvtkActor2D);
	}
	this->pvtkRenderer->ResetCamera();
}

static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}

BOOL DlgVTKFather::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);      // Set big icon
	SetIcon(m_hIcon, FALSE);    // Set small icon

	// adjust dialog & window size

	TCITEM  tcitem1;
	tcitem1.mask = TCIF_TEXT;
	tcitem1.pszText=_T("NO1");
	this->m_TabVtkFather.InsertItem(0,&tcitem1);

	CRect tabRect;
	m_TabVtkFather.GetClientRect(&tabRect);
	// 定位选项卡位置
	tabRect.bottom -=10;
	tabRect.left +=10;
	tabRect.top +=25;
	tabRect.right-=10;

	m_pdlgVTKChild->Create(IDD_DIALOG_VTK_CHILD,GetDlgItem(IDC_TAB_VTK_FATHER));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void DlgVTKFather::OnBnClickedButtonFile()
{
	// TODO: Add your control notification handler code here
	static char BASED_CODE szFilter[] = "VTK Files (*.vtk)|*.vtk|All Files (*.*)|*.*||";
	CFileDialog cFileDialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);

	if (cFileDialog.DoModal() == IDOK)
	{

		
		/*
		// remove old actors
		this->pvtkRenderer->RemoveActor(this->pvtkActor);
		this->pvtkRenderer->RemoveActor(this->pvtkActor2D);

		// read new data
		if (!this->pvtkDataSetReader)
			this->pvtkDataSetReader = vtkDataSetReader::New();
		this->pvtkDataSetReader->SetFileName(cFileDialog.GetPathName());

		// execute object pipeline
		*/
		// data转化到vtk
		CString filename = cFileDialog.GetPathName();
		PMPTransformToVTKForIsosurface(filename);
		//printf("input the name of vtk file:\n");
		//scanf("%s",filename);
		//# Read the source file.
		vtkDataSetReader * reader = vtkDataSetReader::New();
		reader->SetFileName(filename+".vtk");
		reader->Update();
		//# Needed because of GetScalarRange
		vtkDataSet * id = reader->GetOutput();
		double * scalar_range = id->GetPointData()->GetArray(0)->GetRange();
		//print(id);
		//print(scalar_range);

		vtkLookupTable * colormap=vtkLookupTable::New();
		colormap->SetHueRange(0,0);
		colormap->SetSaturationRange(0,0);
		colormap->SetAlphaRange(0.5,0.5);
		colormap->SetValueRange(0,0);
		vtkContourFilter * contour = vtkContourFilter::New();
		contour->SetInputData(id);
		contour->SetValue(0,1);
		contour->ComputeScalarsOn();
		vtkContourFilter * contour1 = vtkContourFilter::New();
		contour1->SetInputData(id);
		contour1->ComputeScalarsOn();
		contour1->SetValue(0,2);
		//# Create the mapper that corresponds the objects of the vtk file
		//# into graphics elements
		vtkDataSetMapper * mapper = vtkDataSetMapper::New();
		mapper->SetInputConnection(reader->GetOutputPort());
		mapper->SetScalarRange(0,0);
		mapper->SetLookupTable(colormap);

		vtkDataSetMapper * mapper1 = vtkDataSetMapper::New();
		mapper1->SetInputConnection(contour->GetOutputPort());
		mapper1->SetScalarRange(scalar_range);

		vtkDataSetMapper *mapper2 = vtkDataSetMapper::New();
		mapper2->SetInputConnection(contour1->GetOutputPort());
		mapper2->SetScalarRange(scalar_range);
		//# Create the Actor
		vtkActor * actor = vtkActor::New();
		actor->SetMapper(mapper);
		actor->GetProperty()->SetColor(0,0,0);
		actor->GetProperty()->SetOpacity(0.5);
		//#actor->GetProperty()->SetRepresentationToSurface()

		vtkActor *actor1 = vtkActor::New();
		actor1->SetMapper(mapper1);

		vtkActor *actor2 = vtkActor::New();
		actor2->SetMapper(mapper2);

		//#actor->GetProperty()->SetOrigin(1.0,1.0,1.0)
		//# Create the Renderer
		//vtkRenderer *renderer = vtkRenderer::New();
		this->pvtkRenderer->AddActor(actor);
		pvtkRenderer->AddActor(actor1);
		pvtkRenderer->AddActor(actor2);
		pvtkRenderer->SetBackground(1, 1, 1);
		//ExecutePipeline();
		initVTK();
		// update window
		if (this->pvtkMFCWindow)
			this->pvtkMFCWindow->RedrawWindow();
	}
}


void DlgVTKFather::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	if (::IsWindow(this->GetSafeHwnd()))
	{
		if (this->pvtkMFCWindow)
		{
			cx -= ptBorder.x;
			cy -= ptBorder.y;
			this->GetDlgItem(IDC_VTK_WINDOW)->SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE);
			this->pvtkMFCWindow->SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOMOVE);
		}
	}
}
void DlgVTKFather::PMPTransformToVTKForIsosurface(CString filename){
	
	//CString datafilename="struct.in";
	//CString str = "    48    48    36     2";
	//CStdioFile stdfile;
	//CString datalinestr;
	//stdfile.Open(datafilename,CStdioFile::modeRead | CStdioFile::typeText);
	//stdfile.ReadString(datalinestr);
	//int x,y,z,v;
	//
	int nx=0,ny=0,nz=0,nn=0;
	float pf1=0.0,pf2=0.0;
	//char *des1;
	//char *des2;
	// 该数据空间超过了VS栈空间，使用C语言关键字malloc创建动态数组
	//int data[MAX_POINTS][4];
	// 先创建指针的指针，再创建指针的指针
	DATA_TYPE **data;
	data = (DATA_TYPE * *)malloc(MAX_POINTS*sizeof(DATA_TYPE *));
	for (int i=0;i<MAX_POINTS;i++)
	{
		*(data + i) = (DATA_TYPE *)malloc(4*sizeof(DATA_TYPE));
	}
	int x=0,y=0,z=0,v=0;
	int temp=29393; 
	int dex=0; 
	int Row =0; 
	FILE * fp;
	FILE * vtk;
	CString str;
	printf("开始转化\n");
	// 首先读一行，读取数据的维数信息
	fp = fopen(filename,"a+"); 
	str.Format("%s.vtk",filename);
	vtk = fopen(str,"w+"); 
	if(NULL == fp) {
		//printf("error open the file");
	} else { 
		fscanf(fp,"%d%d%d ! System size %f%f     ! Phase fraction",&nx,&ny,&nz,&pf1,&pf2);
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
		fscanf(fp,"%f%f%f%f",*(data+0)+0,*(data+0)+1,*(data+0)+2,*(data+0)+3); 
		//fscanf(fp,"%d%d%d%d",&x,&y,&z,&v); 
		dex++;
		//printf("%f %f %f %f\n",*(*(data+0)+0),*(*(data+0)+1),*(*(data+0)+2),*(*(data+0)+3));
		for(int i=1;i<Row;i++) 
		{
			fscanf(fp,"%f%f%f%f",*(data+i)+0,*(data+i)+1,*(data+i)+2,*(data+i)+3); 
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
	for (int i=0;i<MAX_POINTS;i++)
	{
		fprintf(vtk,"%0.1f\n",*(*(data+i)+3));
	}
	fclose(vtk);


	// 二维动态数据显然不能这样释放
	//free(data);
	//先撤销元素的指针，再撤销指针的指针
	for(int i=0;i<MAX_POINTS;i++){
		free(*(data+i));
	}
	free(data);

	fclose(fp); //OK 了 
	//stdfile.Close();
	//printf("结束转化\n");
}

bool DlgVTKFather::initVTK(){
	this->pvtkMFCWindow = new vtkMFCWindow(this);
	// get double click events
	vtkCallbackCommand* callback = vtkCallbackCommand::New();
	callback->SetCallback(handle_double_click);
	this->pvtkMFCWindow->GetInteractor()->AddObserver(vtkCommand::LeftButtonPressEvent, callback, 1.0);
	callback->Delete();


	CRect cRectVTK;
	this->pvtkMFCWindow->GetClientRect(&cRectVTK);

	CRect cRectClient;
	GetClientRect(&cRectClient);

	this->ptBorder.x = cRectClient.Width()  - cRectVTK.Width();
	this->ptBorder.y = cRectClient.Height() - cRectVTK.Height();

	// set the vtk renderer, windows, etc
	this->pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->pvtkRenderer);

	// execute object pipeline
	//ExecutePipeline();
	return true;
}