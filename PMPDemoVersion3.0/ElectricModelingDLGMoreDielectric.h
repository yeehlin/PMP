#pragma once

#include "ElectricModelingDLGDielectric.h"
#include "ElectricModelingDLGExternal.h"

// ElectricModelingDLGMoreDielectric dialog

class ElectricModelingDLGMoreDielectric : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMoreDielectric)

public:
	ElectricModelingDLGMoreDielectric(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMoreDielectric();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MORE_DIELECTRIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_TabMoreDielectric;
	void SetPhaseCount( int phaseCount );
	void SetSimulationType( int simulationType);
	int m_PhaseCount;
	// 持有对象
	//ElectricModelingDLGDielectric m_electricModelingDLGDielectric[6];
	//ElectricModelingDLGExternal m_electricModelingDLGExternal;
	// 优化持有对象
	ElectricModelingDLGDielectric * m_pelectricModelingDLGDielectric[6];
	ElectricModelingDLGExternal  *m_pelectricModelingDLGExternal;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabMoreDielectric(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditK12();
	afx_msg void OnEnChangeEditK13();
	afx_msg void OnEnChangeEditK23();
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
	int m_simulationType;
	CString m_caption;
};
