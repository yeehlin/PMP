
// TestMFCDlgWithTabctrlView.cpp : implementation of the CTestMFCDlgWithTabctrlView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestMFCDlgWithTabctrl.h"
#endif

#include "TestMFCDlgWithTabctrlDoc.h"
#include "TestMFCDlgWithTabctrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCDlgWithTabctrlView

IMPLEMENT_DYNCREATE(CTestMFCDlgWithTabctrlView, CView)

BEGIN_MESSAGE_MAP(CTestMFCDlgWithTabctrlView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestMFCDlgWithTabctrlView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestMFCDlgWithTabctrlView construction/destruction

CTestMFCDlgWithTabctrlView::CTestMFCDlgWithTabctrlView()
{
	// TODO: add construction code here

}

CTestMFCDlgWithTabctrlView::~CTestMFCDlgWithTabctrlView()
{
}

BOOL CTestMFCDlgWithTabctrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestMFCDlgWithTabctrlView drawing

void CTestMFCDlgWithTabctrlView::OnDraw(CDC* /*pDC*/)
{
	CTestMFCDlgWithTabctrlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTestMFCDlgWithTabctrlView printing


void CTestMFCDlgWithTabctrlView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestMFCDlgWithTabctrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestMFCDlgWithTabctrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestMFCDlgWithTabctrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestMFCDlgWithTabctrlView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestMFCDlgWithTabctrlView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestMFCDlgWithTabctrlView diagnostics

#ifdef _DEBUG
void CTestMFCDlgWithTabctrlView::AssertValid() const
{
	CView::AssertValid();
}

void CTestMFCDlgWithTabctrlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestMFCDlgWithTabctrlDoc* CTestMFCDlgWithTabctrlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestMFCDlgWithTabctrlDoc)));
	return (CTestMFCDlgWithTabctrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestMFCDlgWithTabctrlView message handlers
