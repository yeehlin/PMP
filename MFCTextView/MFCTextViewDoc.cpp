
// MFCTextViewDoc.cpp : implementation of the CMFCTextViewDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTextView.h"
#endif

#include "MFCTextViewDoc.h"
#include "MFCTextViewView.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCTextViewDoc

IMPLEMENT_DYNCREATE(CMFCTextViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCTextViewDoc, CDocument)
END_MESSAGE_MAP()


// CMFCTextViewDoc construction/destruction

CMFCTextViewDoc::CMFCTextViewDoc()
{
	// TODO: add one-time construction code here

}

CMFCTextViewDoc::~CMFCTextViewDoc()
{
}

BOOL CMFCTextViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCTextViewDoc serialization

void CMFCTextViewDoc::Serialize(CArchive& ar)
{
	CString str;
	CString sfd;
	if (ar.IsStoring())
	{
		
		// TODO: add storing code here



		POSITION pos = this->GetFirstViewPosition();
		CMFCTextViewView * p_cMFCTextViewView = (CMFCTextViewView *)this->GetNextView(pos);
		p_cMFCTextViewView->m_ctrlRichEdit->GetWindowTextA(str);
		ar.Write(str,str.GetLength());
	}
	else
	{
		// TODO: add loading code here
		long size = 0;
		long filesize =  ar.GetFile()->GetLength();
		if (filesize<=1024*1024*20){
			temp = (char * )malloc(sizeof(char)*filesize + 1);
			while(ar.ReadString(m_Text)){
				m_Text.Append("\n");
				strcpy(temp+size,m_Text.GetBuffer(0));
				m_Text.ReleaseBuffer();
				size+=m_Text.GetLength();
			}
			//m_textContent.Add(temp);
			m_Text = temp;
			free(temp);
		}else{
			::MessageBox(NULL,_T("Too large to open"),_T("OK"),MB_OK);
		}
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCTextViewDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMFCTextViewDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCTextViewDoc::SetSearchContent(const CString& value)
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

// CMFCTextViewDoc diagnostics

#ifdef _DEBUG
void CMFCTextViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCTextViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCTextViewDoc commands

void CMFCTextViewDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class
	m_textContent.RemoveAll();
	CDocument::DeleteContents();
}


BOOL CMFCTextViewDoc::SaveModified()
{
	// TODO: Add your specialized code here and/or call the base class
	CString viewname;
	CString str;
	POSITION pos = this->GetFirstViewPosition();
	CMFCTextViewView * p_cMFCTextViewView = (CMFCTextViewView *)this->GetNextView(pos);
	p_cMFCTextViewView->m_ctrlRichEdit->GetWindowTextA(str);
	if(str.GetLength() != m_Text.GetLength()){
		p_cMFCTextViewView->GetWindowText(viewname);
		viewname.Append("*");
		p_cMFCTextViewView->SetWindowTextA(viewname);
	}
	return CDocument::SaveModified();
}
