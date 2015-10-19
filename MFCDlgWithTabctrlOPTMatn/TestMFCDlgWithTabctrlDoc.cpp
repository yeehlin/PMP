
// TestMFCDlgWithTabctrlDoc.cpp : implementation of the CTestMFCDlgWithTabctrlDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestMFCDlgWithTabctrl.h"
#endif

#include "TestMFCDlgWithTabctrlDoc.h"
#include "ElectricModelingDLGFather.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestMFCDlgWithTabctrlDoc

IMPLEMENT_DYNCREATE(CTestMFCDlgWithTabctrlDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestMFCDlgWithTabctrlDoc, CDocument)
	ON_COMMAND(ID_TOOL_MODELINGSYSTEM, &CTestMFCDlgWithTabctrlDoc::OnToolModelingsystem)
END_MESSAGE_MAP()


// CTestMFCDlgWithTabctrlDoc construction/destruction

CTestMFCDlgWithTabctrlDoc::CTestMFCDlgWithTabctrlDoc()
{
	// TODO: add one-time construction code here
	// ָ���Ա��ʼ��
	m_pelectricModelingDLGFather = NULL;

}

CTestMFCDlgWithTabctrlDoc::~CTestMFCDlgWithTabctrlDoc()
{
	// ���ж���ĵ�ǰ�������ٶ�̬�ڴ棻
	if (m_pelectricModelingDLGFather != NULL){delete m_pelectricModelingDLGFather;}
	 
}

BOOL CTestMFCDlgWithTabctrlDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CTestMFCDlgWithTabctrlDoc serialization

void CTestMFCDlgWithTabctrlDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CTestMFCDlgWithTabctrlDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CTestMFCDlgWithTabctrlDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTestMFCDlgWithTabctrlDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTestMFCDlgWithTabctrlDoc diagnostics

#ifdef _DEBUG
void CTestMFCDlgWithTabctrlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestMFCDlgWithTabctrlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTestMFCDlgWithTabctrlDoc commands

//���ĸ�������������ĸ�������������ʲô���������Ի��򣨵����Ի�����Ϊ�˻�ȡ�������ݣ�
// ˭��Ҫ��Щ���ݣ������ĸ����д��������


void CTestMFCDlgWithTabctrlDoc::OnToolModelingsystem()
{
	// TODO: Add your command handler code here
	// �Ի����пؼ�ֵ�Ļ�����Ҫ���Ի��������Ϊ����������ԣ�ֻ�ж�����вſ��Ի��
	//ElectricModelingDLGFather electricModelingDLGFather;
	// �����¼�����new�ؼ��ֶ�̬�����Ի�����󣬲����ʵ���ʱ���ֶ����ٸö���
	// ȷ��ֻ����һ�β��ڳ��������ڼ���иö���
	if (m_pelectricModelingDLGFather == NULL){
		m_pelectricModelingDLGFather = new ElectricModelingDLGFather();	
		if (PathFileExists(".\\piez\\parameter.in")){
			m_pelectricModelingDLGFather->LoadParameter(".\\piez\\parameter.in");
		}
	}
	// ��ʾ֮ǰ��һ������
	m_pelectricModelingDLGFather->m_caption = _T("Modeling Calculate");
	// �ڶԻ�����ʾ����֮ǰ����ȡparameter.in�ļ�����Ի������
	// �жϲ����ļ��Ƿ����

	if (m_pelectricModelingDLGFather->DoModal()==IDOK){
		// just show it ,do something if want.����Խ��ܶԻ����е����ݣ�����Ҫ��DOC���趨���ԡ�
		//::MessageBox(NULL,_T("��ӭʹ��"),_T("OKOK"),MB_OK);
		/*
		CString temp;
		electricModelingDLGFather.m_electricModelingDLGChild1.m_combo_sys_type;
		::MessageBox(NULL,_T(electricModelingDLGFather.m_electricModelingDLGChild1.m_combo_sys_type),_T("Phase No.1"),MB_OK);
		temp.Format("%0.1f",electricModelingDLGFather.m_electricModelingDLGChild2.m_edit_c11);
		::MessageBox(NULL,temp,_T("Phase No.2"),MB_OK);
		temp.Format("%0.1f",electricModelingDLGFather.m_electricModelingDLGPhaseNo2.m_edit_phase_no2_c11);
		::MessageBox(NULL,temp,_T("Phase No.3"),MB_OK);
		*/
		//m_pelectricModelingDLGFather->PersistenceParameter();
	}

	
}
