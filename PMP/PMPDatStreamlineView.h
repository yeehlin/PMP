#pragma once

#include "PMPDatDoc.h"

#include "PMPVisualization.h"

#include "StreamlineSeedsDlg.h"
#include "PointsColorDlg.h"

// CPMPDatStreamlineView view

class CPMPDatStreamlineView : public CView
{
	DECLARE_DYNCREATE(CPMPDatStreamlineView)

protected:
	CPMPDatStreamlineView();           // protected constructor used by dynamic creation
	virtual ~CPMPDatStreamlineView();

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
	// ���ӻ��ӿ�
	CString filename;
	void pmpvisualizationstreamline(CString filename);
	void ExecutePipeline(void);
	vtkRenderer *m_pvtkRenderer;
	vtkMFCWindow *m_pvtkMFCWindow;
	vtkRenderer * GetRenderer(){
		return this->m_pvtkRenderer;
	};
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
public :
	// ����ת���ӿ�
	CPMPVisualization m_visualizer;
	afx_msg void OnVisualizeBackgroundcolor();
	afx_msg void OnButtonBackground256();
	afx_msg void OnVisualizeStreamlineseeds();
	afx_msg void OnButtonStreamlineSeeds256();
public :
	// ���ӶԻ���
	CStreamlineSeedsDlg * sldlg;
	int x;
	int y;
	int z;
	int nPoints;
	float radius;
	// ����ɫ�Ի���
	CPointsColorDlg *pcDlg;
	afx_msg void OnVisualizePointscolor();
	afx_msg void OnButtonPointsColor256();
	void SetPointColor();
};

#ifndef _DEBUG  // debug version in PMPDatStreamlineView.cpp
inline CPMPDatDoc* CPMPDatStreamlineView::GetDocument() const
{ return reinterpret_cast<CPMPDatDoc*>(m_pDocument); }
#endif
