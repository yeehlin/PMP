#pragma once

// CRichTextView view

#include "RichTextDoc.h"

class CRichTextView : public CView
{
	DECLARE_DYNCREATE(CRichTextView)

protected:
	CRichTextView();           // protected constructor used by dynamic creation
	virtual ~CRichTextView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
	// Attributes
public:
	CRichTextDoc * GetDocument() const;
};

#ifndef _DEBUG  // debug version in MFCTextViewView.cpp
inline CRichTextDoc* CRichTextView::GetDocument() const
{ return reinterpret_cast<CRichTextDoc*>(m_pDocument); }
#endif
