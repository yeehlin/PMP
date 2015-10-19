// RichTextDoc.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTextView.h"
#include "RichTextDoc.h"


// CRichTextDoc

IMPLEMENT_DYNCREATE(CRichTextDoc, CDocument)

CRichTextDoc::CRichTextDoc()
{
}

BOOL CRichTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CRichTextDoc::~CRichTextDoc()
{
}


BEGIN_MESSAGE_MAP(CRichTextDoc, CDocument)
END_MESSAGE_MAP()


// CRichTextDoc diagnostics

#ifdef _DEBUG
void CRichTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CRichTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CRichTextDoc serialization

void CRichTextDoc::Serialize(CArchive& ar)
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
#endif


// CRichTextDoc commands
