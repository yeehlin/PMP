
// PMPWindowsClientMFCView.h : interface of the CPMPWindowsClientMFCView class
//

#pragma once

#include "PMPDlgJobs.h"
#include "NETPMP.h"

class CPMPWindowsClientMFCView : public CView
{
protected: // create from serialization only
	CPMPWindowsClientMFCView();
	DECLARE_DYNCREATE(CPMPWindowsClientMFCView)

// Attributes
public:
	CPMPWindowsClientMFCDoc* GetDocument() const;

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
	virtual ~CPMPWindowsClientMFCView();
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
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPhasemodelingCalculate();
	PMPDlgJobs * ppmpDlgJobs;
	NETPMP * pNETPMP;
};

#ifndef _DEBUG  // debug version in PMPWindowsClientMFCView.cpp
inline CPMPWindowsClientMFCDoc* CPMPWindowsClientMFCView::GetDocument() const
   { return reinterpret_cast<CPMPWindowsClientMFCDoc*>(m_pDocument); }
#endif

