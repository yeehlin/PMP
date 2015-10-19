#pragma once

#include "PMPTensorDatDoc.h"

#include "PMPVisualization.h"

#include "ScaleFactorDlg.h"

// CPMPTensorDatTensoView view

class CPMPTensorDatTensoView : public CView
{
	DECLARE_DYNCREATE(CPMPTensorDatTensoView)

protected:
	CPMPTensorDatTensoView();           // protected constructor used by dynamic creation
	virtual ~CPMPTensorDatTensoView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this viewpublic:
	CPMPTensorDatDoc * GetDocument() const;
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public :
	// 可视化接口
	CString filename;
	void pmpvisualizationtensor(CString filename);
	void ExecutePipeline(void);
	vtkRenderer *m_pvtkRenderer;
	vtkMFCWindow *m_pvtkMFCWindow;
	vtkRenderer * GetRenderer(){
		return this->m_pvtkRenderer;
	};
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
public :
	// 数据转换接口
	CPMPVisualization m_visualizer;
	afx_msg void OnVisualizeBackgroundcolor();
	afx_msg void OnButtonBackground256();
	afx_msg void OnVisualizeScalefactor();
	afx_msg void OnButtonScalefactor256();
	// 设置Scalar factor
	CScaleFactorDlg * sfDlg;
	void SetScaleFactor();
};

#ifndef _DEBUG  // debug version in PMPTensorDatTensoView.cpp
inline CPMPTensorDatDoc* CPMPTensorDatTensoView::GetDocument() const
{ return reinterpret_cast<CPMPTensorDatDoc*>(m_pDocument); }
#endif