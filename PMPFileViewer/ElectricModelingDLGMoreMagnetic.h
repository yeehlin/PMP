#pragma once

#include "ElectricModelingDLGMagnetic.h"

// ElectricModelingDLGMoreMagnetic dialog

class ElectricModelingDLGMoreMagnetic : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMoreMagnetic)

public:
	ElectricModelingDLGMoreMagnetic(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMoreMagnetic();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MORE_MAGNETIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_caption;
	int m_PhaseCount;
	int m_simulationType;
	void SetPhaseCount( int phaseCount );
	void SetSimulationType( int simulationType);
	ElectricModelingDLGMagnetic  * m_pelectricModelingDLGMagnetic[6];
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabMoreMagnetic(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_TabMoreMagnetic;
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();
};
