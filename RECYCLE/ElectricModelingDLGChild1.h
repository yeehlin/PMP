#pragma once

//
//#include "ElectricModelingDLGChild2.h"
//#include "ElectricModelingDLGPhaseNo2.h"
//#include "ElectricModelingDLGPhaseNo3.h"
//#include "ElectricModelingDLGPhaseNo4.h"
//#include "ElectricModelingDLGPhaseNo5.h"
//#include "ElectricModelingDLGPhaseNo6.h"
//#include "ElectricModelingDLGChild3.h"

#include "ElectricModelingDLGMoreElastic.h"
#include "ElectricModelingDLGMoreDielectric.h"
#include "ElectricModelingDLGMorePiezoelectric.h"

// ElectricModelingDLGChild1 dialog

class ElectricModelingDLGChild1 : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGChild1)

public:
	ElectricModelingDLGChild1(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGChild1();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_CHILD1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ComboSysType;
	CComboBox m_ComboFileFormat;
	CComboBox m_ComboSimulationType;
	virtual BOOL OnInitDialog();
	int m_edit_nums_phases;
	CSpinButtonCtrl m_SpinNumsPhases;
	afx_msg void OnCbnSelchangeComboSysType();
	//ElectricModelingDLGChild2 * m_pelectricModelingDLGChild2;
	//ElectricModelingDLGChild3 * m_pelectricModelingDLGChild3;
	//ElectricModelingDLGPhaseNo2 * m_pElectricModelingDLGPhaseNo2;
	//ElectricModelingDLGPhaseNo3 * m_pElectricModelingDLGPhaseNo3;
	//ElectricModelingDLGPhaseNo4 * m_pElectricModelingDLGPhaseNo4;
	//ElectricModelingDLGPhaseNo5 * m_pElectricModelingDLGPhaseNo5;
	//ElectricModelingDLGPhaseNo6 * m_pElectricModelingDLGPhaseNo6;
	//ElectricModelingDLGFather * m_pelectricModelingDLGFather;
//	afx_msg void OnBnClickedButton1();
//	afx_msg void OnBnClickedButton1();
//	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonMore();
	afx_msg void OnDeltaposSpinNumsPhases(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditNumsPhases();
	CString m_combo_sys_type;
	int m_edit_mesh_nx;
	int m_edit_mesh_ny;
	int m_edit_mesh_nz;
	int m_edit_size_lx;
	int m_edit_size_ly;
	int m_edit_size_lz;
	afx_msg void OnEnChangeEditSizeLy();
	CString m_combo_file_format;
	CString m_combo_simulation_type;
	// 用于回填而持有对象
	ElectricModelingDLGMoreElastic electricModelingDLGMoreElastic;
	ElectricModelingDLGMoreDielectric electricModelingDLGMoreDielectric;
	ElectricModelingDLGMorePiezoelectric electricModelingDLGMorePiezoelectric;
	int m_combo_simulation_type_int;
	afx_msg void OnBnClickedOk();
	int m_combo_sys_type_int;
	int m_combo_file_format_int;
};
