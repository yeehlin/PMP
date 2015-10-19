
// PMPWindowsClientMFCView.cpp : implementation of the CPMPWindowsClientMFCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PMPWindowsClientMFC.h"
#endif

#include "PMPWindowsClientMFCDoc.h"
#include "PMPWindowsClientMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPMPWindowsClientMFCView

IMPLEMENT_DYNCREATE(CPMPWindowsClientMFCView, CView)

BEGIN_MESSAGE_MAP(CPMPWindowsClientMFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPMPWindowsClientMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_PHASEMODELING_CALCULATE, &CPMPWindowsClientMFCView::OnPhasemodelingCalculate)
END_MESSAGE_MAP()

// CPMPWindowsClientMFCView construction/destruction

CPMPWindowsClientMFCView::CPMPWindowsClientMFCView()
{
	// TODO: add construction code here
		ppmpDlgJobs = NULL;

}

CPMPWindowsClientMFCView::~CPMPWindowsClientMFCView()
{
	if (ppmpDlgJobs != NULL){
		delete ppmpDlgJobs;
	}
}

BOOL CPMPWindowsClientMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPMPWindowsClientMFCView drawing

void CPMPWindowsClientMFCView::OnDraw(CDC* /*pDC*/)
{
	CPMPWindowsClientMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPMPWindowsClientMFCView printing


void CPMPWindowsClientMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPMPWindowsClientMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPMPWindowsClientMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPMPWindowsClientMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPMPWindowsClientMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPMPWindowsClientMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPMPWindowsClientMFCView diagnostics

#ifdef _DEBUG
void CPMPWindowsClientMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CPMPWindowsClientMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPMPWindowsClientMFCDoc* CPMPWindowsClientMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPWindowsClientMFCDoc)));
	return (CPMPWindowsClientMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CPMPWindowsClientMFCView message handlers


void CPMPWindowsClientMFCView::OnPhasemodelingCalculate()
{
	// TODO: Add your command handler code here
	if (this->ppmpDlgJobs == NULL){
		ppmpDlgJobs = new PMPDlgJobs();
	}
	if (ppmpDlgJobs->DoModal() == IDOK){

	}
}
