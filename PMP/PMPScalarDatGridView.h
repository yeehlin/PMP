#pragma once

#include "PMPScalarDatDoc.h"

#include "PMPVisualization.h"

#include "PointsColorDlg.h"

// CPMPScalarDatGridView view

class CPMPScalarDatGridView : public CView
{
	DECLARE_DYNCREATE(CPMPScalarDatGridView)

protected:
	CPMPScalarDatGridView();           // protected constructor used by dynamic creation
	virtual ~CPMPScalarDatGridView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
public:
	CPMPScalarDatDoc * GetDocument() const;
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
	void pmpvisualizationgrid(CString filename);
	void ExecutePipeline(void);
	vtkRenderer *m_pvtkRenderer;
	vtkMFCWindow *m_pvtkMFCWindow;
	vtkRenderer * GetRenderer(){
		return this->m_pvtkRenderer;
	};
	afx_msg void OnSize(UINT nType, int cx, int cy);

	virtual void OnInitialUpdate();

public :
	// 数据可视化接口
	CPMPVisualization m_visualizer;
	afx_msg void OnVisualizeBackgroundcolor();
	afx_msg void OnButtonBackground256();
	afx_msg void OnVisualizePointscolor();
	afx_msg void OnButtonPointsColor256();
	// 设置颜色点对话框
	CPointsColorDlg * pcDlg;
	void SetPointColor();
};

#ifndef _DEBUG  // debug version in PMPScalarDatGridView.cpp
inline CPMPScalarDatDoc* CPMPScalarDatGridView::GetDocument() const
{ return reinterpret_cast<CPMPScalarDatDoc*>(m_pDocument); }
#endif
