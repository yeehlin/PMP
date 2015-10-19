
// PMPCallView.cpp : implementation of the CPMPCallView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PMPCall.h"
#endif

#include "PMPCallDoc.h"
#include "PMPCallView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPMPCallView

IMPLEMENT_DYNCREATE(CPMPCallView, CView)

BEGIN_MESSAGE_MAP(CPMPCallView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPMPCallView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPMPCallView construction/destruction

CPMPCallView::CPMPCallView()
{
	// TODO: add construction code here

}

CPMPCallView::~CPMPCallView()
{
}

BOOL CPMPCallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPMPCallView drawing

void CPMPCallView::OnDraw(CDC* /*pDC*/)
{
	CPMPCallDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPMPCallView printing


void CPMPCallView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPMPCallView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPMPCallView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPMPCallView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPMPCallView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPMPCallView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPMPCallView diagnostics

#ifdef _DEBUG
void CPMPCallView::AssertValid() const
{
	CView::AssertValid();
}

void CPMPCallView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPMPCallDoc* CPMPCallView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPCallDoc)));
	return (CPMPCallDoc*)m_pDocument;
}
#endif //_DEBUG


// CPMPCallView message handlers
