#pragma once

#include "ElectricModelingDLGDiffusivity.h"

// ElectricModelingDLGMoreDiffusivity dialog

class ElectricModelingDLGMoreDiffusivity : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMoreDiffusivity)

public:
	ElectricModelingDLGMoreDiffusivity(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMoreDiffusivity();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MORE_DIFFUSIVITY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_caption;
	int m_PhaseCount;
	int m_simulationType;
	void SetPhaseCount( int phaseCount );
	void SetSimulationType( int simulationType);
	ElectricModelingDLGDiffusivity  * m_pelectricModelingDLGDiffusivity[6];
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabMoreDiffusivity(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_TabMoreDiffusivity;
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();

public :
	// 用于指向共享矩阵k的指针
	float *** kk;
	void SaveSharedData();
};
