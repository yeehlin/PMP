
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
	// 指针成员初始化
	m_pelectricModelingDLGFather = NULL;

}

CTestMFCDlgWithTabctrlDoc::~CTestMFCDlgWithTabctrlDoc()
{
	// 持有对象的当前对象销毁动态内存；
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

//由哪个类来处理基于哪个命令：该命令会做什么——弹出对话框（弹出对话框是为了获取输入数据）
// 谁需要这些数据，就在哪个类中处理该命令


void CTestMFCDlgWithTabctrlDoc::OnToolModelingsystem()
{
	// TODO: Add your command handler code here
	// 对话框中控件值的回填需要将对话框对象作为本对象的属性（只有对象持有才可以回填）
	//ElectricModelingDLGFather electricModelingDLGFather;
	// 触发事件后是new关键字动态创建对话框对象，并在适当的时候手动销毁该对象
	// 确保只创建一次并在程序运行期间持有该对象
	if (m_pelectricModelingDLGFather == NULL){
		m_pelectricModelingDLGFather = new ElectricModelingDLGFather();	
		if (PathFileExists(".\\piez\\parameter.in")){
			m_pelectricModelingDLGFather->LoadParameter(".\\piez\\parameter.in");
		}
	}
	// 显示之前给一个标题
	m_pelectricModelingDLGFather->m_caption = _T("Modeling Calculate");
	// 在对话框显示出来之前，读取parameter.in文件填入对话框对象，
	// 判断参数文件是否存在

	if (m_pelectricModelingDLGFather->DoModal()==IDOK){
		// just show it ,do something if want.你可以接受对话框中的数据，不过要在DOC中设定属性。
		//::MessageBox(NULL,_T("欢迎使用"),_T("OKOK"),MB_OK);
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
