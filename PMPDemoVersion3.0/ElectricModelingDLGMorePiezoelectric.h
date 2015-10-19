#pragma once

#include "ElectricModelingDLGPiezoelectric.h"
#include "ElectricModelingDLGChild3.h"
#include "ElectricModelingDLGMechanical.h"
#include "ElectricModelingDLGExternal.h"

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
	CTabCtrl m_TabMorePiezoelectric;
	void SetPhaseCount( int phaseCount );
	void SetSimulationType( int simulationType);
	int m_PhaseCount;
	// 持有对象
	//ElectricModelingDLGPiezoelectric m_electricModelingDLGPiezoelectric[6];
	//ElectricModelingDLGMechanical m_electricModelingDLGMechanical;
	//ElectricModelingDLGExternal m_electricModelingDLGExternal;
	//ElectricModelingDLGChild3 m_electricModelingDLGChild3;
	// 持有对象的优化，动态分配内存
	ElectricModelingDLGPiezoelectric *m_pelectricModelingDLGPiezoelectric[6];
	//ElectricModelingDLGMechanical *m_pelectricModelingDLGMechanical;
	//ElectricModelingDLGExternal *m_pelectricModelingDLGExternal;
	ElectricModelingDLGChild3 *m_pelectricModelingDLGChild3;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabMorePiezoelectric(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
	int m_simulationType;
	CString m_caption;
};
