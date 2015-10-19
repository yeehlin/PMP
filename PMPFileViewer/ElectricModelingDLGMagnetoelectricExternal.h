#pragma once


// ElectricModelingDLGMagnetoelectricExternal dialog

class ElectricModelingDLGMagnetoelectricExternal : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMagnetoelectricExternal)

public:
	ElectricModelingDLGMagnetoelectricExternal(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMagnetoelectricExternal();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MAGNETOELECTRIC_EXTERNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CComboBox m_ComboMechanicalBoundary;
	CString m_combo_mechanical_boundary_string;
	int m_combo_mechanical_boundary_int;
	CStatic m_StaticEq11;
	CStatic m_StaticEq12;
	CStatic m_StaticEq13;
	CStatic m_StaticEq22;
	CStatic m_StaticEq23;
	CStatic m_StaticEq33;
	CString m_static_eq11;
	CString m_static_eq12;
	CString m_static_eq13;
	CString m_static_eq22;
	CString m_static_eq23;
	CString m_static_eq33;
	float m_edit_eq11;
	float m_edit_eq12;
	float m_edit_eq13;
	float m_edit_eq22;
	float m_edit_eq23;
	float m_edit_eq33;
	float m_edit_ele_e1;
	float m_edit_ele_e2;
	float m_edit_ele_e3;
	float m_edit_mag_h1;
	float m_edit_mag_h2;
	float m_edit_mag_h3;
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboMechanicalBoundary();
};
