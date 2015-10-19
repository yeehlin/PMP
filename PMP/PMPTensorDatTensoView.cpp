// PMPTensorDatTensoView.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPTensorDatTensoView.h"


// CPMPTensorDatTensoView

IMPLEMENT_DYNCREATE(CPMPTensorDatTensoView, CView)

CPMPTensorDatTensoView::CPMPTensorDatTensoView()
{
	this->m_pvtkMFCWindow = NULL;
	this->m_pvtkRenderer = vtkRenderer::New();
	sfDlg = NULL;
	
}

CPMPTensorDatTensoView::~CPMPTensorDatTensoView()
{
	if (this->m_pvtkMFCWindow) delete this->m_pvtkMFCWindow;
	if (this->m_pvtkRenderer) this->m_pvtkRenderer->Delete();
	if (sfDlg != NULL)

	{
		delete sfDlg;
	}
}

BEGIN_MESSAGE_MAP(CPMPTensorDatTensoView, CView)
	ON_WM_SIZE()
	ON_COMMAND(ID_VISUALIZE_BACKGROUNDCOLOR, &CPMPTensorDatTensoView::OnVisualizeBackgroundcolor)
	ON_COMMAND(ID_BUTTON_BACKGROUND_256, &CPMPTensorDatTensoView::OnButtonBackground256)
	ON_COMMAND(ID_VISUALIZE_SCALEFACTOR, &CPMPTensorDatTensoView::OnVisualizeScalefactor)
	ON_COMMAND(ID_BUTTON_SCALEFACTOR_256, &CPMPTensorDatTensoView::OnButtonScalefactor256)
END_MESSAGE_MAP()


// CPMPTensorDatTensoView drawing

void CPMPTensorDatTensoView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	if (this->m_pvtkMFCWindow)
	{
		if (pDC->IsPrinting())
			this->m_pvtkMFCWindow->DrawDC(pDC);
	}
}


// CPMPTensorDatTensoView diagnostics

#ifdef _DEBUG
void CPMPTensorDatTensoView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPTensorDatTensoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
CPMPTensorDatDoc* CPMPTensorDatTensoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPTensorDatDoc)));
	return (CPMPTensorDatDoc*)m_pDocument;
}
#endif //_DEBUG


// CPMPTensorDatTensoView message handlers
static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}
void CPMPTensorDatTensoView::ExecutePipeline()
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

void CPMPTensorDatTensoView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (this->m_pvtkMFCWindow)
	{
		this->m_pvtkMFCWindow->MoveWindow(0, 0, cx, cy);
	}
}


void CPMPTensorDatTensoView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class

	GetParent()->SetWindowTextA(GetDocument()->GetTitle()+_T("-Tensor"));
	CPMPTensorDatDoc* pDoc = GetDocument();
	m_visualizer.PMPVisualizeTensor33D(filename,m_pvtkRenderer);
	ExecutePipeline();
}
void CPMPTensorDatTensoView::pmpvisualizationtensor(CString filename){

	//CString filename;
	//printf("input the name of vtk file:\n");
	//scanf("%s",filename);

	//# Read the source file.
	vtkStructuredPointsReader * reader = vtkStructuredPointsReader::New();
	reader->SetFileName(filename);
	vtkStructuredPoints * id = reader->GetOutput();


	//#Reduce the amount of points to be plotted, using maskPoints
	vtkMaskPoints * mask = vtkMaskPoints::New();
	mask->SetInputConnection(reader->GetOutputPort());
	mask->SetOnRatio(100);
	mask->SetMaximumNumberOfPoints(1000000);
	mask->RandomModeOn();

	//#Making tensor glyph with superquadratic glyph
	vtkSuperquadricSource * super=vtkSuperquadricSource::New();
	vtkTensorGlyph * tensorglyph=vtkTensorGlyph::New();
	tensorglyph->SetInputConnection(mask->GetOutputPort());
	tensorglyph->SetSourceConnection(super->GetOutputPort());
	tensorglyph->SetScaleFactor(5000);
	tensorglyph->ColorGlyphsOn();
	tensorglyph->SetColorModeToEigenvalues();

	//#tensor glyph mapper
	vtkPolyDataMapper * mapper = vtkPolyDataMapper::New();
	mapper->SetInputConnection(tensorglyph->GetOutputPort());

	vtkActor * actor = vtkActor::New();
	actor->SetMapper(mapper);

	//#create the outer boundary of the data
	vtkOutlineFilter * outline=vtkOutlineFilter::New();
	outline->SetInput(reader->GetOutput());
	vtkDataSetMapper * outlineMapper=vtkDataSetMapper::New();
	outlineMapper->SetInputConnection(outline->GetOutputPort());
	vtkActor * outlineActor=vtkActor::New();
	outlineActor->SetMapper(outlineMapper);
	outlineActor->GetProperty()->SetColor(0,0,0);


	//vtkRenderer * renderer = vtkRenderer::New();
	m_pvtkRenderer->AddActor(actor);
	m_pvtkRenderer->AddActor(outlineActor);
	m_pvtkRenderer->SetBackground(1, 1, 1);// # Set background to white

	//vtkRenderWindow * renWin = vtkRenderWindow::New();
	//renWin->AddRenderer(renderer);


	//vtkRenderWindowInteractor * interactor = vtkRenderWindowInteractor::New();
	//interactor->SetRenderWindow(renWin);

	//interactor->Initialize();

	//renWin->Render();

	//interactor->Start();
}

void CPMPTensorDatTensoView::OnVisualizeBackgroundcolor()
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


void CPMPTensorDatTensoView::OnButtonBackground256()
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


void CPMPTensorDatTensoView::OnVisualizeScalefactor()
{
	// TODO: Add your command handler code here
	this->SetScaleFactor();
}


void CPMPTensorDatTensoView::OnButtonScalefactor256()
{
	// TODO: Add your command handler code here
	this->SetScaleFactor();
}
void CPMPTensorDatTensoView::SetScaleFactor(){
	if (sfDlg == NULL)
	{
		sfDlg = new CScaleFactorDlg();
		sfDlg->m_caption+="-"+GetDocument()->GetTitle();

	}
	sfDlg->m_edit_scale_factor = m_visualizer.scaleFactor;
	// 设置默认值
	sfDlg->fadefault = 0.6/sqrt(m_visualizer.scalar_range0*m_visualizer.scalar_range1);
	if (sfDlg->DoModal() == IDOK)
	{
		m_visualizer.scaleFactor = sfDlg->m_edit_scale_factor;
		m_visualizer.tensorglyph->SetScaleFactor(m_visualizer.scaleFactor);
		CRect rc;
		GetClientRect(rc);
		m_pvtkMFCWindow->RedrawWindow(rc);
	}
}