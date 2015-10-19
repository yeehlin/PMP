#pragma once

#include "PMPTensorDatDoc.h"

#include "PMPVisualization.h"

#include "PointsColorDlg.h"

// CPMPTensorDatView view

class CPMPTensorDatView : public CView
{
	DECLARE_DYNCREATE(CPMPTensorDatView)

protected:
	CPMPTensorDatView();           // protected constructor used by dynamic creation
	virtual ~CPMPTensorDatView();

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
	void pmpvisualizationvolume(CString filename);
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
	afx_msg void OnVisualizePointscolor();
	afx_msg void OnButtonPointsColor256();
	CPointsColorDlg * pcDlg;
	void SetPointColor();
};

#ifndef _DEBUG  // debug version in PMPTesnorDatView.cpp
inline CPMPTensorDatDoc* CPMPTensorDatView::GetDocument() const
{ return reinterpret_cast<CPMPTensorDatDoc*>(m_pDocument); }
#endif