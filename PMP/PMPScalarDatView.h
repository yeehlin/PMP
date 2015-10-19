#pragma once

#include "PMPScalarDatDoc.h"

#include "PMPVisualization.h"

#include "IsosurfaceDlg.h"
#include "PointsColorDlg.h"
// CPMPScalarDatView view

class CPMPScalarDatView : public CView
{
	DECLARE_DYNCREATE(CPMPScalarDatView)

protected:
	CPMPScalarDatView();           // protected constructor used by dynamic creation
	virtual ~CPMPScalarDatView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this viewpublic:
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
		void pmpvisualizationisosurface(CString filename);
		void ExecutePipeline(void);
		vtkRenderer *m_pvtkRenderer;
		vtkMFCWindow *m_pvtkMFCWindow;
		vtkDataSetReader * reader;
		vtkRenderer * GetRenderer(){
			return this->m_pvtkRenderer;
		};
		afx_msg void OnSize(UINT nType, int cx, int cy);
		virtual void OnInitialUpdate();
public :
	// 数据可视化接口
	CPMPVisualization m_visualizer;
	afx_msg void OnClose();
	afx_msg void OnVisualizeBackgroundcolor();
	afx_msg void OnVisualizeIsosurfacevalue();
	CIsosurfaceDlg * isoDlg;
	CPointsColorDlg * pcDlg;
	afx_msg void OnButtonBackground256();
	afx_msg void OnButtonIsosurface256();
//	afx_msg void OnVisualizeScalefactor();
//	afx_msg void OnButtonScalefactor256();
	afx_msg void OnVisualizePointscolor();
	afx_msg void OnButtonPointsColor256();
	void SetPointColor();
};


#ifndef _DEBUG  // debug version in PMPScalarDatView.cpp
inline CPMPScalarDatDoc* CPMPScalarDatView::GetDocument() const
{ return reinterpret_cast<CPMPScalarDatDoc*>(m_pDocument); }
#endif