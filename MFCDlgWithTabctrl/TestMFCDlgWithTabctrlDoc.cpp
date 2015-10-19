
// TestMFCDlgWithTabctrlDoc.cpp : implementation of the CTestMFCDlgWithTabctrlDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestMFCDlgWithTabctrl.h"
#endif

#include "TestMFCDlgWithTabctrlDoc.h"
#include "CalculateDlgFather.h"
#include "CalculateDlgChild1.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestMFCDlgWithTabctrlDoc

IMPLEMENT_DYNCREATE(CTestMFCDlgWithTabctrlDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestMFCDlgWithTabctrlDoc, CDocument)
	ON_COMMAND(ID_TOOL_CALCULATE, &CTestMFCDlgWithTabctrlDoc::OnToolCalculate)
END_MESSAGE_MAP()


// CTestMFCDlgWithTabctrlDoc construction/destruction

CTestMFCDlgWithTabctrlDoc::CTestMFCDlgWithTabctrlDoc()
{
	// TODO: add one-time construction code here
	this->m_pCalculateDlgFather = NULL;

}

CTestMFCDlgWithTabctrlDoc::~CTestMFCDlgWithTabctrlDoc()
{
	if (this->m_pCalculateDlgFather != NULL){
		delete this->m_pCalculateDlgFather;
	}
	
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
void CTestMFCDlgWithTabctrlDoc::OnToolCalculate()
{
	// TODO: Add your command handler code here
	// ������������������������ΪDOC������Ҫ�Ի����е�����
	// Ϊ��ʹ��CalculateDlgFather.cppģ�飬��Ҫ������ģ���ͷ�ļ�
	// һ��ע�⣺���ﴴ�������ǲ����ģ���ֻ�����ڴ������˶Ի������һ��Ҫ����DoModal��ʾ
	if (this->m_pCalculateDlgFather == NULL){
		this->m_pCalculateDlgFather = new CalculateDlgFather();
	}
	if (m_pCalculateDlgFather->DoModal()==IDOK){
	}
	m_pCalculateDlgFather->PersistenceParameter();
}