#pragma once


// ElectricModelingDLGMagnetic dialog

class ElectricModelingDLGMagnetic : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMagnetic)

public:
	ElectricModelingDLGMagnetic(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMagnetic();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MAGNETIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public :

	float m_edit_u11;
	float m_edit_u12;
	float m_edit_u13;
	float m_edit_u21;
	float m_edit_u22;
	float m_edit_u23;
	float m_edit_u31;
	float m_edit_u32;
	float m_edit_u33;
	virtual BOOL OnInitDialog();

	afx_msg void OnEnChangeEditU12();
	afx_msg void OnEnChangeEditU13();
	afx_msg void OnEnChangeEditU23();
	CButton m_StaticPropertiesPHNox;
};
