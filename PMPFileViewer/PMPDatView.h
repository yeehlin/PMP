#pragma once

#include "PMPDatDoc.h"
#include "vtkRenderer.h"
#include "vtkMFCWindow.h"

// CPMPDatView view

class CPMPDatView : public CView
{
	DECLARE_DYNCREATE(CPMPDatView)

protected:
	CPMPDatView();           // protected constructor used by dynamic creation
	virtual ~CPMPDatView();

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
public:
	CPMPDatDoc * GetDocument() const;
	void ExecutePipeline(void);
	vtkRenderer *m_pvtkRenderer;
	vtkMFCWindow *m_pvtkMFCWindow;
	vtkRenderer * GetRenderer(){
		return this->m_pvtkRenderer;
	};
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


