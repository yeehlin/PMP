
// MFCTextViewView.cpp : implementation of the CMFCTextViewView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTextView.h"
#endif

#include "MFCTextViewDoc.h"
#include "MFCTextViewView.h"

#include "MainFrm.h"
#include "vtkOpenGL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTextViewView

IMPLEMENT_DYNCREATE(CMFCTextViewView, CView)

BEGIN_MESSAGE_MAP(CMFCTextViewView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCTextViewView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_NOTIFY( LVN_KEYDOWN, IDC_RICHEDIT, &CMFCTextViewView::OnKeydownRichEdit)
	
//	ON_WM_KEYDOWN()
ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFCTextViewView construction/destruction

CMFCTextViewView::CMFCTextViewView()
{
	// TODO: add construction code here
	m_ctrlRichEdit = NULL;
	
	
}

CMFCTextViewView::~CMFCTextViewView()
{
	if (m_ctrlRichEdit != NULL){
		delete m_ctrlRichEdit;
	}

}

BOOL CMFCTextViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCTextViewView drawing

void CMFCTextViewView::OnDraw(CDC* pDC)
{
	CMFCTextViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	//pDC->TextOut(0,0,pDoc->m_Text);
}


// CMFCTextViewView printing


void CMFCTextViewView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCTextViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCTextViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCTextViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCTextViewView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCTextViewView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCTextViewView diagnostics

#ifdef _DEBUG
void CMFCTextViewView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTextViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTextViewDoc* CMFCTextViewView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTextViewDoc)));
	return (CMFCTextViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTextViewView message handlers


void CMFCTextViewView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CRect rcClient;
	GetClientRect(rcClient );
	if ( m_ctrlRichEdit )
		m_ctrlRichEdit->MoveWindow( rcClient );// �ı�༭�ؼ����ڴ�С 
}


void CMFCTextViewView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class

	CRect rcClient;GetClientRect( rcClient );// ��ȡ��ǰ��ͼ�Ŀͻ�����С
	// if ( m_ctrlEdit ) delete m_ctrlEdit;
	if (m_ctrlRichEdit == NULL){
		m_ctrlRichEdit = new CRichEditCtrl();
	}
	// IDC_RICHEDIT���ֶ���ӵ�������Ӧ֪ͨ��Ϣ
	m_ctrlRichEdit->Create( ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_HSCROLL | ES_AUTOHSCROLL| WS_VSCROLL | ES_AUTOVSCROLL ,rcClient, this, IDC_RICHEDIT);
	
	CMFCTextViewDoc * pDoc=GetDocument();
	CString str;
	int nLines = (int)pDoc->m_textContent.GetSize();
	for ( int i=0; i<nLines; i++ ) 
	{
		str = str + pDoc->m_textContent.GetAt( i );
		str = str + "\r\n";// ����
	}
	//m_ctrlRichEdit->SetTabStops( 16 ); // ����Tab����С
	
	m_ctrlRichEdit->SetWindowText( pDoc->m_Text);// ���ĵ����ݴ����ؼ�

}


//void CMFCTextViewView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	if (nChar>=0 && nChar<=128)
//	{
//		::AfxMessageBox("modified");
//		CMFCTextViewDoc * pDoc=GetDocument();
//		pDoc->SetModifiedFlag(TRUE);
//		CString viewname ;
//		GetWindowText(viewname);
//		viewname.Append("*");
//		this->SetWindowTextA(viewname);
//	}
//
//	CView::OnKeyDown(nChar, nRepCnt, nFlags);
//}


BOOL CMFCTextViewView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: Add your specialized code here and/or call the base class
	if(wParam==IDC_RICHEDIT){//10001Ϊ��Ŀؼ�ID 
		
		UINT uMes = (UINT)lParam;   
		if(uMes == LVN_KEYDOWN){   
			MessageBox(_T("ddd"));
			return   TRUE;   
		}   
	}

	return CView::OnNotify(wParam, lParam, pResult);
}

void CMFCTextViewView::OnKeydownRichEdit(NMHDR* pNMHDR, LRESULT* pResult){
	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;
	// TODO: Add your control notification handler
	//                 code here
	if (pLVKeyDow->hdr.code >0){
		MessageBox(_T("ddd"));
	}

	*pResult = 0;

}

BOOL CMFCTextViewView::OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult)
{
	// TODO: Add your specialized code here and/or call the base class
	//if (wParam==IDC_RICHEDIT)
	//{
		
		if (wParam >=0 &&wParam<=128)
		{
			MessageBox(_T("ddd"));
		}
	//}

	return CView::OnChildNotify(message, wParam, lParam, pLResult);
}



void CMFCTextViewView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	if(nChar==VK_ESCAPE) //������ļ�ΪEsc��
	{//��ȡ����ܴ��ڵ�ָ��
	 CMainFrame *pFrame =(CMainFrame* ) AfxGetApp()->m_pMainWnd;
	//��������������Զ��庯�� EndFullScreen ������˳�ȫ����ʾ״̬
	pFrame->EndFullScreen();}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
