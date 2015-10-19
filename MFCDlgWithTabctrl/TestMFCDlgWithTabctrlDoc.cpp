
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

//由哪个类来处理基于哪个命令：该命令会做什么——弹出对话框（弹出对话框是为了获取输入数据）
// 谁需要这些数据，就在哪个类中处理该命令
void CTestMFCDlgWithTabctrlDoc::OnToolCalculate()
{
	// TODO: Add your command handler code here
	// 在类向导中添加命令处理函数，是因为DOC可能需要对话框中的数据
	// 为了使用CalculateDlgFather.cpp模块，需要包含该模块的头文件
	// 一定注意：这里创建对象还是不够的，这只是在内存中有了对话框对象，一定要调用DoModal显示
	if (this->m_pCalculateDlgFather == NULL){
		this->m_pCalculateDlgFather = new CalculateDlgFather();
	}
	if (m_pCalculateDlgFather->DoModal()==IDOK){
	}
	m_pCalculateDlgFather->PersistenceParameter();
}