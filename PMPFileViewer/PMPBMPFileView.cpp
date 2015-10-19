// PMPBMPFileView.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "PMPBMPFileView.h"

// CPMPBMPFileView

IMPLEMENT_DYNCREATE(CPMPBMPFileView, CView)

CPMPBMPFileView::CPMPBMPFileView()
{
	m_ctrlEdit = NULL;
}

CPMPBMPFileView::~CPMPBMPFileView()
{
	if (m_ctrlEdit != NULL){
		delete m_ctrlEdit;
	}
}

BEGIN_MESSAGE_MAP(CPMPBMPFileView, CView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CPMPBMPFileView drawing

void CPMPBMPFileView::OnDraw(CDC* pDC)
{
	CPMPBMPFile* pDoc = GetDocument();
	// TODO: add draw code here
	//pDC->TextOut(0,0,pDoc->m_text);
}
// CPMPBMPFileView diagnostics

#ifdef _DEBUG
void CPMPBMPFileView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPBMPFileView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif

CPMPBMPFile* CPMPBMPFileView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPBMPFile)));
	return (CPMPBMPFile*)m_pDocument;
}

#endif //_DEBUG

// CPMPBMPFileView message handlers


void CPMPBMPFileView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	CRect rcClient;GetClientRect( rcClient );// 获取当前视图的客户区大小
	  // if ( m_ctrlEdit ) delete m_ctrlEdit;
	if (m_ctrlEdit == NULL){
		m_ctrlEdit = new CEdit();
	 }
	m_ctrlEdit->Create( ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_HSCROLL | ES_AUTOHSCROLL| WS_VSCROLL | ES_AUTOVSCROLL ,rcClient, this, 201);
	CPMPBMPFile * pDoc=GetDocument();
	CString str;
	int nLines = (int)pDoc->m_textContent.GetSize();
	for ( int i=0; i<nLines; i++ ) 
	{
		str = str + pDoc->m_textContent.GetAt( i );
		str = str + "\r\n";// 换行
	}
	m_ctrlEdit->SetTabStops( 16 ); // 设置Tab符大小
	m_ctrlEdit->SetWindowText( str );// 将文档内容传给控件
}


void CPMPBMPFileView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CRect rcClient;
	GetClientRect(rcClient );
	if ( m_ctrlEdit )
		 m_ctrlEdit->MoveWindow( rcClient );// 改变编辑控件窗口大小 
}
