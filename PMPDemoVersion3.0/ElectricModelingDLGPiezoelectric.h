#pragma once

// ElectricModelingDLGPiezoelectric dialog

class ElectricModelingDLGPiezoelectric : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGPiezoelectric)

public:
	ElectricModelingDLGPiezoelectric(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGPiezoelectric();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_PIEZOELECTRIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_StaticPiezoPropertiesPHNox;
	virtual BOOL OnInitDialog();
	float m_edit_c11;
	float m_edit_c12;
	float m_edit_c13;
	float m_edit_c14;
	float m_edit_c15;
	float m_edit_c16;
	float m_edit_c21;
	float m_edit_c22;
	float m_edit_c23;
	float m_edit_c24;
	float m_edit_c25;
	float m_edit_c26;
	float m_edit_c31;
	float m_edit_c32;
	float m_edit_c33;
	float m_edit_c34;
	float m_edit_c35;
	float m_edit_c36;
	float m_edit_c41;
	float m_edit_c42;
	float m_edit_c43;
	float m_edit_c44;
	float m_edit_c45;
	float m_edit_c46;
	float m_edit_c51;
	float m_edit_c52;
	float m_edit_c53;
	float m_edit_c54;
	float m_edit_c55;
	float m_edit_c56;
	float m_edit_c61;
	float m_edit_c62;
	float m_edit_c63;
	float m_edit_c64;
	float m_edit_c65;
	float m_edit_c66;
	float m_edit_d11;
	float m_edit_d12;
	float m_edit_d13;
	float m_edit_d14;
	float m_edit_d15;
	float m_edit_d16;
	float m_edit_d21;
	float m_edit_d22;
	float m_edit_d23;
	float m_edit_d24;
	float m_edit_d25;
	float m_edit_d26;
	float m_edit_d31;
	float m_edit_d32;
	float m_edit_d33;
	float m_edit_d34;
	float m_edit_d35;
	float m_edit_d36;
	float m_edit_k11;
	float m_edit_k12;
	float m_edit_k13;
	float m_edit_k21;
	float m_edit_k22;
	float m_edit_k23;
	float m_edit_k31;
	float m_edit_k32;
	float m_edit_k33;
	afx_msg void OnEnChangeEditC12();
	afx_msg void OnEnChangeEditC13();
	afx_msg void OnEnChangeEditC14();
	afx_msg void OnEnChangeEditC15();
	afx_msg void OnEnChangeEditC16();
	afx_msg void OnEnChangeEditC23();
	afx_msg void OnEnChangeEditC24();
	afx_msg void OnEnChangeEditC25();
	afx_msg void OnEnChangeEditC26();
	afx_msg void OnEnChangeEditC34();
	afx_msg void OnEnChangeEditC35();
	afx_msg void OnEnChangeEditC36();
	afx_msg void OnEnChangeEditC45();
	afx_msg void OnEnChangeEditC46();
	afx_msg void OnEnChangeEditC56();
	afx_msg void OnEnChangeEditK12();
	afx_msg void OnEnChangeEditK13();
	afx_msg void OnEnChangeEditK23();
};
