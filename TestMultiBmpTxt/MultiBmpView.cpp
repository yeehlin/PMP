
// MultiBmpView.cpp : implementation of the CMultiBmpView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestMultiBmpTxt.h"
#endif

#include "MultiBmpDoc.h"
#include "MultiBmpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMultiBmpView

IMPLEMENT_DYNCREATE(CMultiBmpView, CView)

BEGIN_MESSAGE_MAP(CMultiBmpView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMultiBmpView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMultiBmpView construction/destruction

CMultiBmpView::CMultiBmpView()
{
	// TODO: add construction code here

}

CMultiBmpView::~CMultiBmpView()
{
}

BOOL CMultiBmpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMultiBmpView drawing

void CMultiBmpView::OnDraw(CDC* /*pDC*/)
{
	CMultiBmpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMultiBmpView printing


void CMultiBmpView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMultiBmpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMultiBmpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMultiBmpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMultiBmpView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMultiBmpView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMultiBmpView diagnostics

#ifdef _DEBUG
void CMultiBmpView::AssertValid() const
{
	CView::AssertValid();
}

void CMultiBmpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultiBmpDoc* CMultiBmpView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiBmpDoc)));
	return (CMultiBmpDoc*)m_pDocument;
}
#endif //_DEBUG


// CMultiBmpView message handlers
