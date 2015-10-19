#pragma once

#include "ElectricModelingDLGPiezomagnetic.h"

// ElectricModelingDLGMorePiezomagnetic dialog

class ElectricModelingDLGMorePiezomagnetic : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMorePiezomagnetic)

public:
	ElectricModelingDLGMorePiezomagnetic(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMorePiezomagnetic();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MORE_PIEZOMAGNETIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_caption;
	int m_PhaseCount;
	int m_simulationType;
	void SetPhaseCount( int phaseCount );
	void SetSimulationType( int simulationType);
	ElectricModelingDLGPiezomagnetic  * m_pelectricModelingDLGPiezomagnetic[6];
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabMorePiezomagnetic(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_TabMorePiezomagnetic;
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();
};
