#pragma once

#include "ElectricModelingDLGMagnetoelectric.h"

// ElectricModelingDLGMoreMagnetoelectric dialog

class ElectricModelingDLGMoreMagnetoelectric : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMoreMagnetoelectric)

public:
	ElectricModelingDLGMoreMagnetoelectric(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMoreMagnetoelectric();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MORE_MAGNETOELECTRIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	CString m_caption;
	int m_PhaseCount;
	int m_simulationType;
	void SetPhaseCount( int phaseCount );
	void SetSimulationType( int simulationType);
	ElectricModelingDLGMagnetoelectric  * m_pelectricModelingDLGMagnetoelectric[6];
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabMoreMagnetoelectric(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_TabMoreMagnetoelectric;
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();
public :
	// 用于指向共享矩阵c的指针
	float *** cc;
	// 用于指向共享矩阵k的指针
	float *** kk;
	// 用于指向共享矩阵d的指针
	float *** dd;
	// 用于指向共享矩阵u的指针
	float *** uu;
	// 用于指向共享矩阵q的指针
	float *** qq;
	// 用于指向共享矩阵a的指针
	float *** aa;
	void SaveSharedData();
};
