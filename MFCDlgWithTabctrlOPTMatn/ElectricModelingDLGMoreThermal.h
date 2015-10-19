#pragma once

#include "ElectricModelingDLGThermal.h"

// ElectricModelingDLGMoreThermal dialog

class ElectricModelingDLGMoreThermal : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMoreThermal)

public:
	ElectricModelingDLGMoreThermal(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMoreThermal();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MORE_THERMAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	CString m_caption;
	int m_PhaseCount;
	int m_simulationType;
	void SetPhaseCount( int phaseCount );
	void SetSimulationType( int simulationType);
	ElectricModelingDLGThermal  * m_pelectricModelingDLGThermal[6];
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabMoreThermal(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_TabMoreThermal;
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();
public :
	// 用于指向共享矩阵k的指针
	float *** kk;
	void SaveSharedData();
};
