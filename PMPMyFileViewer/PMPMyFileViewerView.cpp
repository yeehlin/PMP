
// PMPMyFileViewerView.cpp : implementation of the CPMPMyFileViewerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PMPMyFileViewer.h"
#endif

#include "PMPMyFileViewerDoc.h"
#include "PMPMyFileViewerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPMPMyFileViewerView

IMPLEMENT_DYNCREATE(CPMPMyFileViewerView, CView)

BEGIN_MESSAGE_MAP(CPMPMyFileViewerView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPMPMyFileViewerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPMPMyFileViewerView construction/destruction

CPMPMyFileViewerView::CPMPMyFileViewerView()
{
	// TODO: add construction code here

}

CPMPMyFileViewerView::~CPMPMyFileViewerView()
{
}

BOOL CPMPMyFileViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPMPMyFileViewerView drawing

void CPMPMyFileViewerView::OnDraw(CDC* /*pDC*/)
{
	CPMPMyFileViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPMPMyFileViewerView printing


void CPMPMyFileViewerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPMPMyFileViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPMPMyFileViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPMPMyFileViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPMPMyFileViewerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPMPMyFileViewerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPMPMyFileViewerView diagnostics

#ifdef _DEBUG
void CPMPMyFileViewerView::AssertValid() const
{
	CView::AssertValid();
}

void CPMPMyFileViewerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPMPMyFileViewerDoc* CPMPMyFileViewerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPMyFileViewerDoc)));
	return (CPMPMyFileViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CPMPMyFileViewerView message handlers
