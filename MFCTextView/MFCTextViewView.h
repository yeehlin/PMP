
// MFCTextViewView.h : interface of the CMFCTextViewView class
//

#pragma once


class CMFCTextViewView : public CView
{
protected: // create from serialization only
	CMFCTextViewView();
	DECLARE_DYNCREATE(CMFCTextViewView)

// Attributes
public:
	CMFCTextViewDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCTextViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

	afx_msg void OnKeydownRichEdit(NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()
public :
	CRichEditCtrl * m_ctrlRichEdit;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in MFCTextViewView.cpp
inline CMFCTextViewDoc* CMFCTextViewView::GetDocument() const
   { return reinterpret_cast<CMFCTextViewDoc*>(m_pDocument); }
#endif

