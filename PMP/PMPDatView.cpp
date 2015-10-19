// PMPDatView.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPDatView.h"

// CPMPDatView

IMPLEMENT_DYNCREATE(CPMPDatView, CView)

CPMPDatView::CPMPDatView()
{
	this->m_pvtkMFCWindow = NULL;
	this->m_pvtkRenderer = vtkRenderer::New();
	sfDlg = NULL;
	pcDlg = NULL;
}

CPMPDatView::~CPMPDatView()
{
	if (this->m_pvtkMFCWindow) delete this->m_pvtkMFCWindow;
	if (this->m_pvtkRenderer) this->m_pvtkRenderer->Delete();
	if (sfDlg != NULL)
	{
		delete sfDlg;
	}
	if (pcDlg != NULL)
	{
		delete pcDlg;
	}
}

BEGIN_MESSAGE_MAP(CPMPDatView, CView)
	ON_WM_SIZE()
	ON_COMMAND(ID_VISUALIZE_BACKGROUNDCOLOR, &CPMPDatView::OnVisualizeBackgroundcolor)
	ON_COMMAND(ID_BUTTON_BACKGROUND_256, &CPMPDatView::OnButtonBackground256)
	ON_COMMAND(ID_VISUALIZE_SCALEFACTOR, &CPMPDatView::OnVisualizeScalefactor)
	ON_COMMAND(ID_BUTTON_SCALEFACTOR_256, &CPMPDatView::OnButtonScalefactor256)
	ON_COMMAND(ID_VISUALIZE_POINTSCOLOR, &CPMPDatView::OnVisualizePointscolor)
	ON_COMMAND(ID_BUTTON_POINTS_COLOR_256, &CPMPDatView::OnButtonPointsColor256)
END_MESSAGE_MAP()


// CPMPDatView drawing

void CPMPDatView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	if (this->m_pvtkMFCWindow)
	{
		if (pDC->IsPrinting())
			this->m_pvtkMFCWindow->DrawDC(pDC);
	}
}


// CPMPDatView diagnostics

#ifdef _DEBUG
void CPMPDatView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPDatView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
CPMPDatDoc* CPMPDatView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPDatDoc)));
	return (CPMPDatDoc*)m_pDocument;
}
#endif //_DEBUG


// CPMPDatView message handlers

static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}
void CPMPDatView::ExecutePipeline()
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

void CPMPDatView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (this->m_pvtkMFCWindow)
	{
		this->m_pvtkMFCWindow->MoveWindow(0, 0, cx, cy);
	}
}


void CPMPDatView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class

	CPMPDatDoc* pDoc = GetDocument();
	GetParent()->SetWindowTextA(GetDocument()->GetTitle()+_T("-Vector"));
	m_visualizer.PMPVisualizeVector3D(filename,m_pvtkRenderer);
	ExecutePipeline();
}


void CPMPDatView::pmpvisualizationpolarization(CString filename){

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
	mask->SetInput(id);
	mask->Update();
	vtkGlyph3D * glyph = vtkGlyph3D::New();
	glyph->SetSourceConnection(arrow->GetOutputPort());
	glyph->SetInput(mask->GetOutput());
	glyph->OrientOn();
	glyph->SetVectorModeToUseVector();
	glyph->SetColorModeToColorByVector();
	glyph->SetScaleModeToScaleByVector();
	glyph->SetScaleFactor(100000);

	vtkOutlineFilter * outline=vtkOutlineFilter::New();
	outline->SetInput(reader->GetOutput());

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
	//POSITION pos = this->GetFirstViewPosition();
	//CPMPDatView * pCPMPView = (CPMPDatView *)this->GetNextView(pos);
	//CMainFrame * pFrame = (CMainFrame*)AfxGetMainWnd();
	//CMainFrame * pFrame = (CMainFrame *)AfxGetMainWnd();
	//CVTKMFCCreatePolyActorsView* pCVTKMFCCreatePolyActorsView = (CVTKMFCCreatePolyActorsView *)pFrame->GetActiveView();
	//if (this->pvtkActor){
	//	pCVTKMFCCreateBMPActorsView->GetRenderer()->AddActor(this->pvtkActor);
	//}
	this->GetRenderer()->AddActor(actor);
	this->GetRenderer()->AddActor(outlineActor);
	this->GetRenderer()->AddActor(axes);
	this->GetRenderer()->SetBackground(0.9, 0.9, 0.9);
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

void CPMPDatView::OnVisualizeBackgroundcolor()
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


void CPMPDatView::OnButtonBackground256()
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


void CPMPDatView::OnVisualizeScalefactor()
{
	// TODO: Add your command handler code here
	this->SetScaleFactor();
}


void CPMPDatView::OnButtonScalefactor256()
{
	// TODO: Add your command handler code here
	this->SetScaleFactor();
}


void CPMPDatView::OnVisualizePointscolor()
{
	// TODO: Add your command handler code here
	this->SetPointColor();
}


void CPMPDatView::OnButtonPointsColor256()
{
	// TODO: Add your command handler code here
	this->SetPointColor();
}

void CPMPDatView::SetScaleFactor(){
	if (sfDlg == NULL)
	{
		sfDlg = new CScaleFactorDlg();
		sfDlg->m_caption+="-"+GetDocument()->GetTitle();

	}
	sfDlg->m_edit_scale_factor = m_visualizer.scaleFactor;
	// 设置默认值
	sfDlg->fadefault = 1/sqrt(m_visualizer.m_Vector3Dscalar_range0*m_visualizer.m_Vector3Dscalar_range1);
	if (sfDlg->DoModal() == IDOK)
	{
		m_visualizer.scaleFactor = sfDlg->m_edit_scale_factor;
		m_visualizer.glyph->SetScaleFactor(m_visualizer.scaleFactor);
		CRect rc;
		GetClientRect(rc);
		m_pvtkMFCWindow->RedrawWindow(rc);
	}
}
void CPMPDatView::SetPointColor(){
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

			CRect rc;
			GetClientRect(rc);
			m_pvtkMFCWindow->RedrawWindow(rc);
		}
	}
}