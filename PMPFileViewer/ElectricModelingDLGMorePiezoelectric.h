#pragma once

#include "ElectricModelingDLGPiezoelectric.h"

// ElectricModelingDLGMorePiezoelectric dialog

class ElectricModelingDLGMorePiezoelectric : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMorePiezoelectric)

public:
	ElectricModelingDLGMorePiezoelectric(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMorePiezoelectric();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MORE_PIEZOELECTRIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_caption;
	int m_PhaseCount;
	int m_simulationType;
	void SetPhaseCount( int phaseCount );
	void SetSimulationType( int simulationType);
	CTabCtrl m_TabMorePiezoelectric;
	// 持有对象
	//ElectricModelingDLGPiezoelectric m_electricModelingDLGPiezoelectric[6];
	//ElectricModelingDLGMechanical m_electricModelingDLGMechanical;
	//ElectricModelingDLGExternal m_electricModelingDLGExternal;
	//ElectricModelingDLGChild3 m_electricModelingDLGChild3;
	// 持有对象的优化，动态分配内存
	ElectricModelingDLGPiezoelectric *m_pelectricModelingDLGPiezoelectric[6];
	//ElectricModelingDLGMechanical *m_pelectricModelingDLGMechanical;
	//ElectricModelingDLGExternal *m_pelectricModelingDLGExternal;
	afx_msg void OnTcnSelchangeTabMorePiezoelectric(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
};
