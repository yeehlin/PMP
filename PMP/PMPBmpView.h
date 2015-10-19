#pragma once

#include "PMPBmpDoc.h"
#include "vtkRenderer.h"
#include "vtkMFCWindow.h"
// CPMPBmpView view

class CPMPBmpView : public CView
{
	DECLARE_DYNCREATE(CPMPBmpView)

protected:
	CPMPBmpView();           // protected constructor used by dynamic creation
	virtual ~CPMPBmpView();
// Attributes
public:
	CPMPBmpDoc * GetDocument() const;
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
	void ExecutePipeline(void);
	vtkRenderer *m_pvtkRenderer;
	vtkMFCWindow *m_pvtkMFCWindow;
	vtkRenderer * GetRenderer(){
		return this->m_pvtkRenderer;
	};
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnVisualizeBackgroundcolor();
	afx_msg void OnButtonBackground256();
};

#ifndef _DEBUG  // debug version in PMPFileViewerView.cpp
inline CPMPBmpDoc* CPMPBmpView::GetDocument() const
{ return reinterpret_cast<CPMPBmpDoc*>(m_pDocument); }
#endif

