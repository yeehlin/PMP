
// VTKMFCCreateBMPActorsView.h : interface of the CVTKMFCCreateBMPActorsView class
//

#pragma once

#include "vtkRenderer.h"
#include "vtkMFCWindow.h"
#include "vtkWin32OpenGLRenderWindow.h"

class CVTKMFCCreateBMPActorsView : public CView
{
protected: // create from serialization only
	CVTKMFCCreateBMPActorsView();
	DECLARE_DYNCREATE(CVTKMFCCreateBMPActorsView)

// Attributes
public:
	CVTKMFCCreateBMPActorsDoc* GetDocument() const;

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
	virtual ~CVTKMFCCreateBMPActorsView();
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
private:
	vtkRenderer *pvtkRenderer;
	vtkMFCWindow *pvtkMFCWindow;
	int i;
	CFileFind fileFind;
public:
	vtkRenderer * GetRenderer(){
		//ASSERT(this->pvtkRenderer);
		return this->pvtkRenderer;
	};
	virtual void OnInitialUpdate();
	afx_msg void OnAddactorsAddbmpactor();
	afx_msg void OnRemoveactorsRemovebmpactor();
	// 刷新Actor的显示
	bool RefreshActors(void);
	afx_msg void OnNextactorsNextbmpactor();
	// 管线的剩余部分
	void ExecutePipeline(void);
//	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
//	virtual BOOL OnCreateAggregates();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void NextActor(int i);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnScanbmpactorBeginscan();
	afx_msg void OnScanbmpactorEndscan();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder);
};
#ifndef _DEBUG  // debug version in VTKMFCCreateBMPActorsView.cpp
inline CVTKMFCCreateBMPActorsDoc* CVTKMFCCreateBMPActorsView::GetDocument() const
   { return reinterpret_cast<CVTKMFCCreateBMPActorsDoc*>(m_pDocument); }
#endif

