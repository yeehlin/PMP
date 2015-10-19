#pragma once

#include "ElectricModelingDLGElastic.h"

// ElectricModelingDLGMoreElastic dialog

class ElectricModelingDLGMoreElastic : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMoreElastic)
public:
	ElectricModelingDLGMoreElastic(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMoreElastic();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MORE_ELASTIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public :
	CString m_caption;
	int m_PhaseCount;
	int m_simulationType;
	void SetPhaseCount( int phaseCount );
	void SetSimulationType( int simulationType);
	// 持有对象
	//ElectricModelingDLGElastic m_electricModelingDLGElastic[6];
	//ElectricModelingDLGMechanical m_electricModelingDLGMechanical;
	// 优化持有对象为动态创建p
	ElectricModelingDLGElastic  * m_pelectricModelingDLGElastic[6];
	CTabCtrl m_TabMoreElastic;
	afx_msg void OnTcnSelchangeTabMoreElastic(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	/*
	afx_msg void OnEnChangeEditC12();
	afx_msg void OnEnChangeEditC13();
	afx_msg void OnEnChangeEditC14();
	afx_msg void OnEnChangeEditC15();
	afx_msg void OnEnChangeEditC16();
	afx_msg void OnEnChangeEditC23();
	afx_msg void OnEnChangeEditC24();
	afx_msg void OnEnChangeEditC25();
	afx_msg void OnEnChangeEditC26();
	afx_msg void OnEnChangeEditC34();
	afx_msg void OnEnChangeEditC35();
	afx_msg void OnEnChangeEditC36();
	afx_msg void OnEnChangeEditC45();
	afx_msg void OnEnChangeEditC46();
	afx_msg void OnEnChangeEditC56();
	*/
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
public :
	static float c[6][6][6];
	static float k[6][3][3];
	static float d[6][3][6];
	static float u[6][3][3];
	static float q[6][3][6];
	static float a[6][3][3];
	// 认为system type为diffusivity和Thermal condcutivity下的k是不一样的
	static float diff[6][3][3];
	static float ther[6][3][3];
public :
	// 用于指向共享矩阵c的指针
	float *** cc;
	void SaveSharedData();
};