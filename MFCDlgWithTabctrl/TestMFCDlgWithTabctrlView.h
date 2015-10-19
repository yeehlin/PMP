
// TestMFCDlgWithTabctrlView.h : interface of the CTestMFCDlgWithTabctrlView class
//

#pragma once


class CTestMFCDlgWithTabctrlView : public CView
{
protected: // create from serialization only
	CTestMFCDlgWithTabctrlView();
	DECLARE_DYNCREATE(CTestMFCDlgWithTabctrlView)

// Attributes
public:
	CTestMFCDlgWithTabctrlDoc* GetDocument() const;

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
	virtual ~CTestMFCDlgWithTabctrlView();
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
	afx_msg void OnToolIsosurfacevalue();
	afx_msg void OnToolPointscolor();

	int RGBnPoints;
	int OPAnPoints;
};

#ifndef _DEBUG  // debug version in TestMFCDlgWithTabctrlView.cpp
inline CTestMFCDlgWithTabctrlDoc* CTestMFCDlgWithTabctrlView::GetDocument() const
   { return reinterpret_cast<CTestMFCDlgWithTabctrlDoc*>(m_pDocument); }
#endif

