#pragma once

#include "PMPTxtDoc.h"

#include "PMPTransformer.h"

// CPMPTxtView view

class CPMPTxtView : public CView
{
	DECLARE_DYNCREATE(CPMPTxtView)

protected:
	CPMPTxtView();           // protected constructor used by dynamic creation
	virtual ~CPMPTxtView();
// Attributes
public:
	CPMPTxtDoc * GetDocument() const;
public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public :
		CEdit * m_ctrlEdit;
		CRichEditCtrl * m_ctrlRichEdit;
		afx_msg void OnSize(UINT nType, int cx, int cy);
		virtual void OnInitialUpdate();
		afx_msg void OnVisualizeVisualization();
public :
	CPMPTransformer m_transformer;
	afx_msg void OnButtonVisualization256();
	void TextVisualization();
};


#ifndef _DEBUG  // debug version in PMPFileViewerView.cpp
inline CPMPTxtDoc* CPMPTxtView::GetDocument() const
{ return reinterpret_cast<CPMPTxtDoc*>(m_pDocument); }
#endif