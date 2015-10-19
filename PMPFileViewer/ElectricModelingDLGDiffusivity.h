#pragma once


// ElectricModelingDLGDiffusivity dialog

class ElectricModelingDLGDiffusivity : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGDiffusivity)

public:
	ElectricModelingDLGDiffusivity(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGDiffusivity();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_DIFFUSIVITY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	float m_edit_diff11;
	float m_edit_diff12;
	float m_edit_diff13;
	float m_edit_diff21;
	float m_edit_diff22;
	float m_edit_diff23;
	float m_edit_diff31;
	float m_edit_diff32;
	float m_edit_diff33;

	afx_msg void OnEnChangeEditDiff12();
	afx_msg void OnEnChangeEditDiff13();
	afx_msg void OnEnChangeEditDiff23();
	CButton m_StaticPropertiesPHNox;
};
