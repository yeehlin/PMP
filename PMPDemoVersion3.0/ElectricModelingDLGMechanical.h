#pragma once

// ElectricModelingDLGMechanical dialog

class ElectricModelingDLGMechanical : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMechanical)

public:
	ElectricModelingDLGMechanical(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMechanical();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MECHANICAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ComboBondaryCondition;
	float m_edit_eo1;
	CString m_combo_bondary_condition_string;
	int m_combo_bondary_condition_int;
	float m_edit_eo2;
	float m_edit_eo3;
	float m_edit_eo4;
	float m_edit_eo5;
	float m_edit_eo6;
	virtual BOOL OnInitDialog();
};
