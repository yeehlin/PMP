#pragma once

#include "PMPDatDoc.h"

#include "PMPVisualization.h"

#include "PointsColorDlg.h"

// CPMPVectorDatVolumeView view

class CPMPVectorDatVolumeView : public CView
{
	DECLARE_DYNCREATE(CPMPVectorDatVolumeView)

protected:
	CPMPVectorDatVolumeView();           // protected constructor used by dynamic creation
	virtual ~CPMPVectorDatVolumeView();

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
	void ExecutePipeline(void);
	vtkRenderer *m_pvtkRenderer;
	vtkMFCWindow *m_pvtkMFCWindow;
	vtkRenderer * GetRenderer(){
		return this->m_pvtkRenderer;
	};
public :
	// 数据显示接口
	CPMPVisualization m_visualizer;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
	afx_msg void OnVisualizeBackgroundcolor();
	afx_msg void OnButtonBackground256();
	CPointsColorDlg * pcDlg;
	afx_msg void OnVisualizePointscolor();
	afx_msg void OnButtonPointsColor256();
	void SetPointColor();
};
#ifndef _DEBUG  // debug version in PMPVectorDatVolumeView.cpp
inline CPMPDatDoc* CPMPVectorDatVolumeView::GetDocument() const
{ return reinterpret_cast<CPMPDatDoc*>(m_pDocument); }
#endif

