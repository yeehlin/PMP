
// PMPFileViewerView.cpp : implementation of the CPMPFileViewerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PMPFileViewer.h"
#endif

#include "PMPFileViewerView.h"
#include "PMPFileViewerDoc.h"

#include "vtkWin32OpenGLRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkCallbackCommand.h"
#include "vtkInteractorStyleTrackballCamera.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPMPFileViewerView

IMPLEMENT_DYNCREATE(CPMPFileViewerView, CScrollView)

BEGIN_MESSAGE_MAP(CPMPFileViewerView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPMPFileViewerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SPINODALDECOMPOSITION_CALCULATE, &CPMPFileViewerView::OnSpinodaldecompositionCalculate)
	ON_COMMAND(ID_PHASEMODELING_CALCULATE, &CPMPFileViewerView::OnPhasemodelingCalculate)
	ON_MESSAGE(WM_USERMESSAGE, &CPMPFileViewerView::OnTreeViewMessage)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CPMPFileViewerView construction/destruction

CPMPFileViewerView::CPMPFileViewerView()
{
	// TODO: add construction code here
	this->m_pvtkMFCWindow = NULL;
	this->m_pvtkRenderer = vtkRenderer::New();
	
}

CPMPFileViewerView::~CPMPFileViewerView()
{
	if (this->m_pvtkMFCWindow) delete this->m_pvtkMFCWindow;
	if (this->m_pvtkRenderer) this->m_pvtkRenderer->Delete();

}

BOOL CPMPFileViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CPMPFileViewerView drawing

void CPMPFileViewerView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here
	//int cy;
	//TEXTMETRIC tm;
	//pDC->GetTextMetrics(&tm);
	//cy = tm.tmHeight+tm.tmExternalLeading;
	//for (int i=0;i<pDoc->m_textArray.GetSize();i++)
	//{
	//	pDC->TextOut(0,i*cy,pDoc->m_textArray.GetAt(i));
	//}
	
	if (this->m_pvtkMFCWindow)
	{
		if (pDC->IsPrinting())
			this->m_pvtkMFCWindow->DrawDC(pDC);
	}
}


// CPMPFileViewerView printing


void CPMPFileViewerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPMPFileViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPMPFileViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPMPFileViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPMPFileViewerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPMPFileViewerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPMPFileViewerView diagnostics

#ifdef _DEBUG
void CPMPFileViewerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPMPFileViewerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPMPFileViewerDoc* CPMPFileViewerView::GetDocument() const // non-debug version is inline
{
	// 不同的数据到底有没有同一面
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPFileViewerDoc)));
	return (CPMPFileViewerDoc*)m_pDocument;
}
#endif //_DEBUG


static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}
void CPMPFileViewerView::ExecutePipeline()
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



// CPMPFileViewerView message handlers


void CPMPFileViewerView::OnSpinodaldecompositionCalculate()
{
	// TODO: Add your command handler code here
	CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
	pMainFrame->getFileViewWnd()->FillFileViewByModuleType(1);
	pMainFrame->getFileViewWnd()->SetModuleType(1);
	pMainFrame->getFileViewWnd()->getFileTreeView()->setModuleType(1);
	pMainFrame->getFileViewWnd()->SetTimer(TIMER_FOR_FILEVIEW,5000,NULL);
	//pMainFrame->getFileViewWnd()->KillTimer(TIMER_FOR_FILEVIEW_MDL2);
}


void CPMPFileViewerView::OnPhasemodelingCalculate()
{
	// TODO: Add your command handler code here
	CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
	pMainFrame->getFileViewWnd()->FillFileViewByModuleType(2);
	pMainFrame->getFileViewWnd()->SetModuleType(2);
	pMainFrame->getFileViewWnd()->getFileTreeView()->setModuleType(2);
	pMainFrame->getFileViewWnd()->SetTimer(TIMER_FOR_FILEVIEW_MDL2,4000,NULL);
	//pMainFrame->getFileViewWnd()->KillTimer(TIMER_FOR_FILEVIEW);
}
LRESULT CPMPFileViewerView::OnTreeViewMessage(WPARAM wParam, LPARAM lParam){
	::MessageBox(NULL,_T("想要打开"),_T("OK"),MB_OK);
	return 0;
}


void CPMPFileViewerView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	this->SetScrollSizes(MM_TEXT,GetDocument()->GetDocSize());
	ExecutePipeline();
}


void CPMPFileViewerView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (this->m_pvtkMFCWindow)
	{
		this->m_pvtkMFCWindow->MoveWindow(0, 0, cx, cy);
	}
}



BOOL CPMPFileViewerView::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll)
{
	// TODO: Add your specialized code here and/or call the base class
	if (this->m_pvtkMFCWindow)
	{
		CRect cr;GetClientRect(cr);
		this->m_pvtkMFCWindow->MoveWindow(0, 0, cr.Width(), cr.Height());
	}


	return CScrollView::OnScroll(nScrollCode, nPos, bDoScroll);
}
