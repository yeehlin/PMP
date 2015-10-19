// PMPTxtDoc.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPTxtDoc.h"

#include "PMPTxtView.h"

// CPMPTxtDoc

IMPLEMENT_DYNCREATE(CPMPTxtDoc, CDocument)

CPMPTxtDoc::CPMPTxtDoc()
{
}

BOOL CPMPTxtDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CPMPTxtDoc::~CPMPTxtDoc()
{
}


BEGIN_MESSAGE_MAP(CPMPTxtDoc, CDocument)
END_MESSAGE_MAP()


// CPMPTxtDoc diagnostics

#ifdef _DEBUG
void CPMPTxtDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CPMPTxtDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CPMPTxtDoc serialization

void CPMPTxtDoc::Serialize(CArchive& ar)
{
	CString str;
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		POSITION pos = this->GetFirstViewPosition();
		CPMPTxtView * p_cPMPTxtView = (CPMPTxtView *)this->GetNextView(pos);
		p_cPMPTxtView->m_ctrlRichEdit->GetWindowTextA(str);
		ar.Write(str,str.GetLength());
	}
	else
	{
		// TODO: add loading code here
		m_PathName = ar.m_strFileName;
		m_realfilename = ar.GetFile()->GetFileName();
		long size = 0;
		long filesize =  ar.GetFile()->GetLength();
		// 允许打开一个不超过20M的文本文件
		
		if(ar.GetFile()->GetLength()<=1024*1024*20){
			char * temp = (char * )malloc(sizeof(char)*filesize + 1);
			while(ar.ReadString(m_text)){
				m_text.Append("\n");
				strcpy(temp+size,m_text.GetBuffer(0));
				m_text.ReleaseBuffer();
				size+=m_text.GetLength();
			}
			//m_textContent.Add(temp);
			m_text = temp;
			free(temp);
		}else{
			::MessageBox(NULL,_T("Too large to open"),_T("Message"),MB_OK);
		}
	}
}
#endif


// CPMPTxtDoc commands
void CPMPTxtDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class
	m_textContent.RemoveAll();
	CDocument::DeleteContents();
}
