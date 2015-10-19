// RichTextView.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTextView.h"
#include "RichTextView.h"

// CRichTextView

IMPLEMENT_DYNCREATE(CRichTextView, CView)

CRichTextView::CRichTextView()
{
}

CRichTextView::~CRichTextView()
{
}

BEGIN_MESSAGE_MAP(CRichTextView, CRichEditView)
END_MESSAGE_MAP()


// CRichTextView diagnostics

#ifdef _DEBUG
void CRichTextView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CRichTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
CRichTextDoc* CRichTextView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRichTextDoc)));
	return (CRichTextDoc*)m_pDocument;
}
#endif //_DEBUG


// CRichTextView message handlers
