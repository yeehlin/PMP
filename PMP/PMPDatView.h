#pragma once

#include "PMPDatDoc.h"

#include "PMPVisualization.h"
#include "ScaleFactorDlg.h"
#include "PointsColorDlg.h"
// CPMPDatView view

class CPMPDatView : public CView
{
	DECLARE_DYNCREATE(CPMPDatView)

protected:
	CPMPDatView();           // protected constructor used by dynamic creation
	virtual ~CPMPDatView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
public:
	CPMPDatDoc * GetDocument() const;
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
	void pmpvisualizationpolarization(CString filename);
	void ExecutePipeline(void);
	vtkRenderer *m_pvtkRenderer;
	vtkMFCWindow *m_pvtkMFCWindow;
	vtkRenderer * GetRenderer(){
		return this->m_pvtkRenderer;
	};
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
public :
	// 数据显示接口
	CPMPVisualization m_visualizer;
	afx_msg void OnVisualizeBackgroundcolor();
	afx_msg void OnButtonBackground256();
	afx_msg void OnVisualizeScalefactor();
	afx_msg void OnButtonScalefactor256();
	afx_msg void OnVisualizePointscolor();
	afx_msg void OnButtonPointsColor256();
public:
	// 调节scale factor
	CScaleFactorDlg * sfDlg;
	void SetScaleFactor();
	// 设置颜色点
	CPointsColorDlg * pcDlg;
	void SetPointColor();
};
#ifndef _DEBUG  // debug version in PMPDatView.cpp
inline CPMPDatDoc* CPMPDatView::GetDocument() const
{ return reinterpret_cast<CPMPDatDoc*>(m_pDocument); }
#endif



