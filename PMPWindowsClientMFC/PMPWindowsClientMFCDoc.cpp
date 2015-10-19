
// PMPWindowsClientMFCDoc.cpp : implementation of the CPMPWindowsClientMFCDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PMPWindowsClientMFC.h"
#endif

#include "PMPWindowsClientMFCDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPMPWindowsClientMFCDoc

IMPLEMENT_DYNCREATE(CPMPWindowsClientMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CPMPWindowsClientMFCDoc, CDocument)
END_MESSAGE_MAP()


// CPMPWindowsClientMFCDoc construction/destruction

CPMPWindowsClientMFCDoc::CPMPWindowsClientMFCDoc()
{
	// TODO: add one-time construction code here

}

CPMPWindowsClientMFCDoc::~CPMPWindowsClientMFCDoc()
{
}

BOOL CPMPWindowsClientMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CPMPWindowsClientMFCDoc serialization

void CPMPWindowsClientMFCDoc::Serialize(CArchive& ar)
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
void CPMPWindowsClientMFCDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CPMPWindowsClientMFCDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CPMPWindowsClientMFCDoc::SetSearchContent(const CString& value)
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

// CPMPWindowsClientMFCDoc diagnostics

#ifdef _DEBUG
void CPMPWindowsClientMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPMPWindowsClientMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPMPWindowsClientMFCDoc commands
