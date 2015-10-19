// PMPDatStreamlineView.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPDatStreamlineView.h"

#include "PMPDatDoc.h"


// CPMPDatStreamlineView

IMPLEMENT_DYNCREATE(CPMPDatStreamlineView, CView)

CPMPDatStreamlineView::CPMPDatStreamlineView()
{
	this->m_pvtkMFCWindow = NULL;
	this->m_pvtkRenderer = vtkRenderer::New();
	sldlg = NULL;
	x = 10;
	y = 10;
	z = 10;
	nPoints = 10;
	radius = 5.0f;
	pcDlg = NULL;
}

CPMPDatStreamlineView::~CPMPDatStreamlineView()
{
	if (this->m_pvtkMFCWindow) delete this->m_pvtkMFCWindow;
	if (this->m_pvtkRenderer) this->m_pvtkRenderer->Delete();
	if (sldlg != NULL)
	{
		delete sldlg;
	}
	if (pcDlg != NULL)
	{
		delete pcDlg;
	}
}

BEGIN_MESSAGE_MAP(CPMPDatStreamlineView, CView)
	ON_WM_SIZE()
	ON_COMMAND(ID_VISUALIZE_BACKGROUNDCOLOR, &CPMPDatStreamlineView::OnVisualizeBackgroundcolor)
	ON_COMMAND(ID_BUTTON_BACKGROUND_256, &CPMPDatStreamlineView::OnButtonBackground256)
	ON_COMMAND(ID_VISUALIZE_STREAMLINESEEDS, &CPMPDatStreamlineView::OnVisualizeStreamlineseeds)
	ON_COMMAND(ID_BUTTON_STREAMLINE_SEEDS_256, &CPMPDatStreamlineView::OnButtonStreamlineSeeds256)
	ON_COMMAND(ID_VISUALIZE_POINTSCOLOR, &CPMPDatStreamlineView::OnVisualizePointscolor)
	ON_COMMAND(ID_BUTTON_POINTS_COLOR_256, &CPMPDatStreamlineView::OnButtonPointsColor256)
END_MESSAGE_MAP()


// CPMPDatStreamlineView drawing

void CPMPDatStreamlineView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	if (this->m_pvtkMFCWindow)
	{
		if (pDC->IsPrinting())
			this->m_pvtkMFCWindow->DrawDC(pDC);
	}
}


// CPMPDatStreamlineView diagnostics

#ifdef _DEBUG
void CPMPDatStreamlineView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPDatStreamlineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif

CPMPDatDoc* CPMPDatStreamlineView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPDatDoc)));
	return (CPMPDatDoc*)m_pDocument;
}
#endif //_DEBUG


// CPMPDatStreamlineView message handlers
static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}
void CPMPDatStreamlineView::ExecutePipeline()
{
	if (this->m_pvtkMFCWindow == NULL){
		this->m_pvtkMFCWindow = new vtkMFCWindow(this);
	}
	vtkInteractorStyleTrackballCamera *style =
		vtkInteractorStyleTrackballCamera::New();
	this->m_pvtkRenderer->SetBackground(0.9,0.9,0.9);
	this->m_pvtkMFCWindow->GetInteractor()->SetInteractorStyle(style);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->m_pvtkRenderer);
	// get double click events
	vtkCallbackCommand * callback = vtkCallbackCommand::New();
	callback->SetCallback(handle_double_click);
	this->m_pvtkMFCWindow->GetInteractor()->AddObserver(vtkCommand::LeftButtonPressEvent, callback, 1.0);
	callback->Delete();
}

void CPMPDatStreamlineView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (this->m_pvtkMFCWindow)
	{
		this->m_pvtkMFCWindow->MoveWindow(0, 0, cx, cy);
	}
}


void CPMPDatStreamlineView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	GetParent()->SetWindowTextA(GetDocument()->GetTitle()+_T("-Streamline"));
	CPMPDatDoc* pDoc = GetDocument();
	m_visualizer.PMPVisualizeVector3DStreamline(filename,m_pvtkRenderer);
	ExecutePipeline();
}
void CPMPDatStreamlineView::pmpvisualizationstreamline(CString filename){

	//CString filename;
	//printf("input the name of vtk file:\n");
	//scanf("%s",filename);

	//# Read the source file.
	vtkDataSetReader * reader = vtkDataSetReader::New();
	reader->SetFileName(filename);
	reader->Update();// # Needed because of GetScalarRange
	double * scalar_range = reader->GetStructuredPointsOutput()->GetPointData()->GetVectors()->GetRange(-1);
	vtkDataSet * id=reader->GetOutput();

	//#Reduce the number of points to be plotted
	vtkMaskPoints * mask = vtkMaskPoints::New();
	mask->SetOnRatio(10);
	mask->SetInput(id);
	mask->Update();

	//#Set the source for stream lines
	vtkPointSource * seeds=vtkPointSource::New();
	seeds->SetCenter(10,10,10);
	seeds->SetNumberOfPoints(10);
	seeds->SetRadius(5);
	//#create stream lines
	vtkStreamLine * stream = vtkStreamLine::New();
	stream->SetInputConnection(reader->GetOutputPort());
	stream->SetStepLength(100);
	stream->SetIntegrationStepLength(0.1);
	stream->SetNumberOfThreads(100);
	stream->SetSource(seeds->GetOutput());
	stream->SetMaximumPropagationTime(10000000);
	stream->SpeedScalarsOn();
	stream->SetIntegrationDirectionToForward();

	//#create the outer boundary of data
	vtkOutlineFilter * outline=vtkOutlineFilter::New();
	outline->SetInput(reader->GetOutput());

	//#set the colormap based on vector's magnitude
	vtkColorTransferFunction * colormap=vtkColorTransferFunction::New();
	colormap->SetColorSpaceToLab();
	colormap->AddRGBPoint(scalar_range[0],0,0,1);
	colormap->AddRGBPoint(scalar_range[0]+scalar_range[1]/4,0,1,0);
	colormap->AddRGBPoint(scalar_range[0]+scalar_range[1]/2,1,0,0);
	colormap->Build();

	//#Streamline mapper and outline mapper
	vtkPolyDataMapper * streamMapper=vtkPolyDataMapper::New();
	streamMapper->SetInputConnection(stream->GetOutputPort());
	streamMapper->SetLookupTable(colormap);

	vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
	outlineMapper->SetInputConnection(outline->GetOutputPort());


	//# Create the Actor
	vtkTransform * transform=vtkTransform::New();
	transform->Translate(-5,0.0,0.0);
	vtkAxesActor * axes=vtkAxesActor::New();
	axes->SetUserTransform(transform);
	axes->SetScale(10);
	axes->SetTotalLength(10,10,10);
	axes->GetXAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
	axes->GetYAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
	axes->GetZAxisCaptionActor2D()->GetProperty()->SetColor(0,0,0);
	vtkActor * outlineActor=vtkActor::New();
	outlineActor->SetMapper(outlineMapper);
	outlineActor->GetProperty()->SetColor(0,0,0);

	vtkActor * streamActor=vtkActor::New();
	streamActor->SetMapper(streamMapper);
	streamActor->VisibilityOn();

	//# Create the Renderer
	//vtkRenderer * renderer = vtkRenderer::New();

	m_pvtkRenderer->AddActor(outlineActor);
	m_pvtkRenderer->AddActor(axes);
	m_pvtkRenderer->AddActor(streamActor);
	m_pvtkRenderer->SetBackground(0.6, 0.6, 0.6);// # Set background to white

	//# Create the RendererWindow
	//vtkRenderWindow * renderer_window = vtkRenderWindow::New();
	//renderer_window->AddRenderer(renderer);

	//# Create the RendererWindowInteractor and display the vtk_file
	//vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
	//interactor->SetRenderWindow(renderer_window);
	//interactor->Initialize();
	//interactor->Start();
}

void CPMPDatStreamlineView::OnVisualizeBackgroundcolor()
{
	// TODO: Add your command handler code here
	double m_dColorRed = 0.9 ;
	double  m_dColorGreen = 0.9;
	double m_dColorBlue = 0.9;
	COLORREF color = RGB(m_dColorRed*255, m_dColorGreen*255, m_dColorBlue*255);
	CColorDialog cdlg(color, CC_FULLOPEN | CC_RGBINIT); // 设置默认颜色
	if(cdlg.DoModal() == IDOK)
		color = cdlg.GetColor();

	m_dColorRed = GetRValue(color)/255.0;
	m_dColorGreen = GetGValue(color)/255.0;
	m_dColorBlue = GetBValue(color)/255.0;
	m_pvtkRenderer->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	CRect rc;
	GetClientRect(rc);
	m_pvtkMFCWindow->RedrawWindow(rc);
}


void CPMPDatStreamlineView::OnButtonBackground256()
{
	// TODO: Add your command handler code here
	double m_dColorRed = 0.9 ;
	double  m_dColorGreen = 0.9;
	double m_dColorBlue = 0.9;
	COLORREF color = RGB(m_dColorRed*255, m_dColorGreen*255, m_dColorBlue*255);
	CColorDialog cdlg(color, CC_FULLOPEN | CC_RGBINIT); // 设置默认颜色
	if(cdlg.DoModal() == IDOK)
		color = cdlg.GetColor();

	m_dColorRed = GetRValue(color)/255.0;
	m_dColorGreen = GetGValue(color)/255.0;
	m_dColorBlue = GetBValue(color)/255.0;
	m_pvtkRenderer->SetBackground(m_dColorRed,m_dColorGreen,m_dColorBlue);
	CRect rc;
	GetClientRect(rc);
	m_pvtkMFCWindow->RedrawWindow(rc);
}


void CPMPDatStreamlineView::OnVisualizeStreamlineseeds()
{
	// TODO: Add your command handler code here
	if (sldlg == NULL)
	{
		sldlg = new CStreamlineSeedsDlg();
	}

	sldlg->m_edit_streamline_seeds_x_int = x;
	sldlg->m_edit_streamline_seeds_y_int = y;
	sldlg->m_edit_streamline_seeds_z_int = z;
	sldlg->m_edit_streamline_seeds_points_int =  nPoints;
	sldlg->m_edit_streamline_seeds_radius_float = radius;
	if (sldlg->DoModal() == IDOK)
	{
		x = sldlg->m_edit_streamline_seeds_x_int;
		y = sldlg->m_edit_streamline_seeds_y_int;
		z = sldlg->m_edit_streamline_seeds_z_int;
		nPoints =  sldlg->m_edit_streamline_seeds_points_int;
		radius = sldlg->m_edit_streamline_seeds_radius_float;

		m_visualizer.m_pVectorSeeds->SetCenter(x,y,z);
		m_visualizer.m_pVectorSeeds->SetCenter(x,y,z);
		m_visualizer.m_pVectorSeeds->SetNumberOfPoints(nPoints);
		m_visualizer.m_pVectorSeeds->SetRadius(radius);
		CRect rc;
		GetClientRect(rc);
		m_pvtkMFCWindow->RedrawWindow(rc);
	}
}


void CPMPDatStreamlineView::OnButtonStreamlineSeeds256()
{
	// TODO: Add your command handler code here
	if (sldlg == NULL)
	{
		sldlg = new CStreamlineSeedsDlg();
	}

	sldlg->m_edit_streamline_seeds_x_int = x;
	sldlg->m_edit_streamline_seeds_y_int = y;
	sldlg->m_edit_streamline_seeds_z_int = z;
	sldlg->m_edit_streamline_seeds_points_int =  nPoints;
	sldlg->m_edit_streamline_seeds_radius_float = radius;
	if (sldlg->DoModal() == IDOK)
	{
		x = sldlg->m_edit_streamline_seeds_x_int;
		y = sldlg->m_edit_streamline_seeds_y_int;
		z = sldlg->m_edit_streamline_seeds_z_int;
		nPoints =  sldlg->m_edit_streamline_seeds_points_int;
		radius = sldlg->m_edit_streamline_seeds_radius_float;

		m_visualizer.m_pVectorSeeds->SetCenter(x,y,z);
		m_visualizer.m_pVectorSeeds->SetCenter(x,y,z);
		m_visualizer.m_pVectorSeeds->SetNumberOfPoints(nPoints);
		m_visualizer.m_pVectorSeeds->SetRadius(radius);
		CRect rc;
		GetClientRect(rc);
		m_pvtkMFCWindow->RedrawWindow(rc);
	}
}


void CPMPDatStreamlineView::OnVisualizePointscolor()
{
	// TODO: Add your command handler code here
	this->SetPointColor();
}


void CPMPDatStreamlineView::OnButtonPointsColor256()
{
	// TODO: Add your command handler code here
	this->SetPointColor();
}
void CPMPDatStreamlineView::SetPointColor(){
	if(pcDlg == NULL){
		pcDlg = new CPointsColorDlg();
		pcDlg->m_cation +="-"+GetDocument()->GetTitle();
	}
	
	double minv = m_visualizer.scalar_range[0];
	double maxv = m_visualizer.scalar_range[1];
	double range = m_visualizer.diff;
	pcDlg->m_edit_min_value_points = minv;
	pcDlg->m_edit_max_value_points = maxv;
	pcDlg->m_edit_min_value_opa = minv;
	pcDlg->m_edit_max_value_opa = maxv;
	pcDlg->RGBnPoints = m_visualizer.RGBPoint;
	pcDlg->OPAnPoints = m_visualizer.opacityPoint;
	// 给颜色点赋值
	for (int i =0;i<m_visualizer.RGBPoint;i++)
	{
		*(pcDlg->RGBPoints[i]) = m_visualizer.RGBValue[i];
		*(pcDlg->RGBR[i]) = m_visualizer.RGB[i][0];
		*(pcDlg->RGBG[i]) = m_visualizer.RGB[i][1];
		*(pcDlg->RGBB[i]) = m_visualizer.RGB[i][2];
	}
	// 给透明点赋值

	//for (int i =0;i<m_visualizer.opacityPoint;i++)
	//{
		//*(pcDlg->OPAPoints[i]) = m_visualizer.opValue[i];
		//*(pcDlg->OPA [i]) = m_visualizer.alpha[i];
	//}
	
	if (pcDlg->DoModal() == IDOK)
	{
		m_visualizer.RGBPoint = pcDlg->RGBnPoints;
		if (m_visualizer.RGBPoint != 0)
		{
			
			m_visualizer.RGBValue = (double *)malloc(m_visualizer.RGBPoint*sizeof(double));
			m_visualizer.RGB = (double **)malloc(m_visualizer.RGBPoint*sizeof(double *));
			for (int i =0;i<m_visualizer.RGBPoint;i++)
			{
				*(m_visualizer.RGB + i) = (double *)malloc(3*sizeof(double));
			}
			m_visualizer.color->RemoveAllPoints();
			for (int k = 0,i = 0;k<6 || i<m_visualizer.RGBPoint;k++)
			{
				// 已经关闭了，无法得到控件上的内容
				//CString p;(pcDlg->RGBButton[k])->GetWindowText(p);
				if (pcDlg->RGBFlag[k] == TRUE)
				{
					//::MessageBox(NULL,_T("OK"),_T("OK"),MB_OK);
					m_visualizer.RGBValue[i] = *(pcDlg->RGBPoints[k]);
					//double **RGB;
					//RGB = (double **)(new double[RGBPoint][3]);
					//m_visualizer.RGB = (double **)malloc(m_visualizer.RGBPoint*sizeof(double *));
					//for (int i =0;i<m_visualizer.RGBPoint;i++)
					//{
						//*(m_visualizer.RGB + i) = (double *)malloc(3*sizeof(double));
					//}
					//for (int i = 0;i<m_visualizer.RGBPoint;i++)
					//{
							m_visualizer.RGB[i][0]=*(pcDlg->RGBR[k]);
							m_visualizer.RGB[i][1]=*(pcDlg->RGBG[k]);
							m_visualizer.RGB[i][2]=*(pcDlg->RGBB[k]);

					//}
					//double RGB[3][3] = {{0.0,0.0,1.0},{0.0,1.0,0.0},{1.0,0.0,0.0}};
					//for (int i=0;i<m_visualizer.RGBPoint;i++)
					//{
						m_visualizer.color->AddRGBPoint(m_visualizer.RGBValue[i],m_visualizer.RGB[i][0],m_visualizer.RGB[i][1],m_visualizer.RGB[i][2]);
					//}
					i++;
				}
			}
			m_visualizer.scaleBar->SetNumberOfLabels(m_visualizer.RGBPoint);
			CRect rc;
			GetClientRect(rc);
			m_pvtkMFCWindow->RedrawWindow(rc);
		}
	}
}