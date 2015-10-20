
// PMPView.h : interface of the CPMPView class
//

#pragma once

#include "vtkRenderer.h"
#include "vtkMFCWindow.h"

#include "CalculateDlgFather.h"
#include "ElectricModelingDLGFather.h"
#include "PMPDlgJobs.h"

#include "ProcessCreater.h"

#define TIMER_ONE_SECOND 1
#define TIMER_PIEZ_OUTPUT 2

class CPMPView : public CView
{
protected: // create from serialization only
	CPMPView();
	DECLARE_DYNCREATE(CPMPView)

// Attributes
public:
	CPMPDoc* GetDocument() const;

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
	virtual ~CPMPView();
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
public :
	void ExecutePipeline(void);
	vtkRenderer *m_pvtkRenderer;
	vtkMFCWindow *m_pvtkMFCWindow;
	vtkRenderer * GetRenderer(){
		return this->m_pvtkRenderer;
	};
	int i;
	CFileFind fileFind;
	CFile bmpfile;
	void NextActor(int i);
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSpinodaldecompositionCalculate();
	//***************�Ի���******************//
	CalculateDlgFather *m_pcalculateDlgFather;
	ElectricModelingDLGFather * m_pelectricModelingDLGFather;
	PMPDlgJobs * m_pCJobControlDlg;
	// ��ǰ���е�ģ���ʶ,0��ʾû��ģ������
	int m_CurrentMoldule;

	afx_msg void OnPhasemodelingCalculate();
	afx_msg void OnButtonSuspend256();
	afx_msg void OnButtonResume256();
	afx_msg void OnButtonStop256();
	PROCESS_INFORMATION pi; 
	void ReadCMDOutput();
	CString output;
	void SetOutput(CString output);
	CStringArray m_outputList;
	void OutputToList(CString output);
	void SetOutputList(CStringArray &list);
	int flagsize;
	afx_msg void OnClose();

	// �ƹ���������
	CProcessCreater  * m_pSpinodalpc;
	CProcessCreater * m_pPiezopc;
	// ģʽʶ��Ի���
	CProcessCreater * m_pPaternRecpc;
	// ����Ŀ¼
	CString workdirectory;
	// ����Ŀ¼
	BOOL MakeDir(CString szDirName);
	// ��������-������ģ���Ӧ��Ŀ¼������ģ������ʱ��Ҫ���ļ���ģ�鹤��Ŀ¼
	BOOL EnviornmentConfig(int moduleType);
	afx_msg void OnToolsPatternrecognition();
	afx_msg void OnPhasemodelingJobcontrol();
};

#ifndef _DEBUG  // debug version in PMPView.cpp
inline CPMPDoc* CPMPView::GetDocument() const
   { return reinterpret_cast<CPMPDoc*>(m_pDocument); }
#endif

