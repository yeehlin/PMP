// PMPDatView.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "PMPDatView.h"

#include "vtkWin32OpenGLRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkCallbackCommand.h"
#include "vtkInteractorStyleTrackballCamera.h"

// CPMPDatView

IMPLEMENT_DYNCREATE(CPMPDatView, CView)

CPMPDatView::CPMPDatView()
{
	this->m_pvtkMFCWindow = NULL;
	this->m_pvtkRenderer = vtkRenderer::New();
}

CPMPDatView::~CPMPDatView()
{
	if (this->m_pvtkMFCWindow) delete this->m_pvtkMFCWindow;
	if (this->m_pvtkRenderer) this->m_pvtkRenderer->Delete();
}

BEGIN_MESSAGE_MAP(CPMPDatView, CView)
	ON_WM_SIZE()
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
void CPMPDatView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	ExecutePipeline();
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
