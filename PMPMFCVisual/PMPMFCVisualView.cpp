
// PMPMFCVisualView.cpp : implementation of the CPMPMFCVisualView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PMPMFCVisual.h"
#endif

#include "PMPMFCVisualDoc.h"
#include "PMPMFCVisualView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPMPMFCVisualView

IMPLEMENT_DYNCREATE(CPMPMFCVisualView, CView)

BEGIN_MESSAGE_MAP(CPMPMFCVisualView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPMPMFCVisualView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPMPMFCVisualView construction/destruction

CPMPMFCVisualView::CPMPMFCVisualView()
{
	// TODO: add construction code here

}

CPMPMFCVisualView::~CPMPMFCVisualView()
{
}

BOOL CPMPMFCVisualView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPMPMFCVisualView drawing

void CPMPMFCVisualView::OnDraw(CDC* /*pDC*/)
{
	CPMPMFCVisualDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPMPMFCVisualView printing


void CPMPMFCVisualView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPMPMFCVisualView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPMPMFCVisualView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPMPMFCVisualView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPMPMFCVisualView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPMPMFCVisualView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPMPMFCVisualView diagnostics

#ifdef _DEBUG
void CPMPMFCVisualView::AssertValid() const
{
	CView::AssertValid();
}

void CPMPMFCVisualView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPMPMFCVisualDoc* CPMPMFCVisualView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPMFCVisualDoc)));
	return (CPMPMFCVisualDoc*)m_pDocument;
}
#endif //_DEBUG


// CPMPMFCVisualView message handlers
