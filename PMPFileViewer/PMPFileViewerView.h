
// PMPFileViewerView.h : interface of the CPMPFileViewerView class
//

#pragma once

#include "PMPFileViewerDoc.h"
#include "vtkRenderer.h"
#include "vtkMFCWindow.h"

class CPMPFileViewerView : public CScrollView
{
protected: // create from serialization only
	CPMPFileViewerView();
	DECLARE_DYNCREATE(CPMPFileViewerView)

// Attributes
public:
	CPMPFileViewerDoc * GetDocument() const;

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
	virtual ~CPMPFileViewerView();
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
	afx_msg void OnSpinodaldecompositionCalculate();
	afx_msg void OnPhasemodelingCalculate();
	afx_msg LRESULT OnTreeViewMessage(WPARAM wParam, LPARAM lParam);
public :
	void ExecutePipeline(void);
	vtkRenderer *m_pvtkRenderer;
	vtkMFCWindow *m_pvtkMFCWindow;
	vtkRenderer * GetRenderer(){
		return this->m_pvtkRenderer;
	};
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
};

#ifndef _DEBUG  // debug version in PMPFileViewerView.cpp
inline CPMPFileViewerDoc* CPMPFileViewerView::GetDocument() const
   { return reinterpret_cast<CPMPFileViewerDoc*>(m_pDocument); }
#endif

