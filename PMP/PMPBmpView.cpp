// PMPBmpView.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPBmpView.h"
#include "PMPBmpDoc.h"

#include "vtkWin32OpenGLRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkCallbackCommand.h"
#include "vtkInteractorStyleTrackballCamera.h"

// CPMPBmpView

IMPLEMENT_DYNCREATE(CPMPBmpView, CView)

CPMPBmpView::CPMPBmpView()
{

	this->m_pvtkMFCWindow = NULL;
	this->m_pvtkRenderer = vtkRenderer::New();
}

CPMPBmpView::~CPMPBmpView()
{
	if (this->m_pvtkMFCWindow) delete this->m_pvtkMFCWindow;
	if (this->m_pvtkRenderer) this->m_pvtkRenderer->Delete();
}

BEGIN_MESSAGE_MAP(CPMPBmpView, CView)
	ON_WM_SIZE()
	ON_COMMAND(ID_VISUALIZE_BACKGROUNDCOLOR, &CPMPBmpView::OnVisualizeBackgroundcolor)
	ON_COMMAND(ID_BUTTON_BACKGROUND_256, &CPMPBmpView::OnButtonBackground256)
END_MESSAGE_MAP()


// CPMPBmpView drawing

void CPMPBmpView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	if (this->m_pvtkMFCWindow)
	{
		if (pDC->IsPrinting())
			this->m_pvtkMFCWindow->DrawDC(pDC);
	}
}


// CPMPBmpView diagnostics

#ifdef _DEBUG
void CPMPBmpView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPBmpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
CPMPBmpDoc* CPMPBmpView::GetDocument() const // non-debug version is inline
{
	// 不同的数据到底有没有同一面
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPBmpDoc)));
	return (CPMPBmpDoc*)m_pDocument;
}

#endif //_DEBUG


// CPMPBmpView message handlers


void CPMPBmpView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	GetParent()->SetWindowTextA(GetDocument()->GetTitle());
	ExecutePipeline();
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
void CPMPBmpView::ExecutePipeline()
{
	if (this->m_pvtkMFCWindow == NULL){
		this->m_pvtkMFCWindow = new vtkMFCWindow(this);
	}
	vtkInteractorStyleTrackballCamera *style =
		vtkInteractorStyleTrackballCamera::New();
	this->m_pvtkRenderer->SetBackground(0.0,0.0,0.4);
	this->m_pvtkMFCWindow->GetInteractor()->SetInteractorStyle(style);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->m_pvtkRenderer);
	// get double click events
	vtkCallbackCommand * callback = vtkCallbackCommand::New();
	callback->SetCallback(handle_double_click);
	this->m_pvtkMFCWindow->GetInteractor()->AddObserver(vtkCommand::LeftButtonPressEvent, callback, 1.0);
	callback->Delete();
}


void CPMPBmpView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (this->m_pvtkMFCWindow)
	{
		this->m_pvtkMFCWindow->MoveWindow(0, 0, cx, cy);
	}
}


void CPMPBmpView::OnVisualizeBackgroundcolor()
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


void CPMPBmpView::OnButtonBackground256()
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
