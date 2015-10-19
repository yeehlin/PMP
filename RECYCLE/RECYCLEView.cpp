
// RECYCLEView.cpp : implementation of the CRECYCLEView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RECYCLE.h"
#endif

#include "RECYCLEDoc.h"
#include "RECYCLEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRECYCLEView

IMPLEMENT_DYNCREATE(CRECYCLEView, CView)

BEGIN_MESSAGE_MAP(CRECYCLEView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRECYCLEView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CRECYCLEView construction/destruction

CRECYCLEView::CRECYCLEView()
{
	// TODO: add construction code here

}

CRECYCLEView::~CRECYCLEView()
{
}

BOOL CRECYCLEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRECYCLEView drawing

void CRECYCLEView::OnDraw(CDC* /*pDC*/)
{
	CRECYCLEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CRECYCLEView printing


void CRECYCLEView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRECYCLEView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRECYCLEView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRECYCLEView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CRECYCLEView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRECYCLEView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRECYCLEView diagnostics

#ifdef _DEBUG
void CRECYCLEView::AssertValid() const
{
	CView::AssertValid();
}

void CRECYCLEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRECYCLEDoc* CRECYCLEView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRECYCLEDoc)));
	return (CRECYCLEDoc*)m_pDocument;
}
#endif //_DEBUG


// CRECYCLEView message handlers
