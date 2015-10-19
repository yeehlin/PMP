#pragma once


// ElectricModelingDLGPiezomagnetic dialog

class ElectricModelingDLGPiezomagnetic : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGPiezomagnetic)

public:
	ElectricModelingDLGPiezomagnetic(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGPiezomagnetic();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_PIEZOMAGNETIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
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

	float m_edit_u11;
	float m_edit_u12;
	float m_edit_u13;
	float m_edit_u21;
	float m_edit_u22;
	float m_edit_u23;
	float m_edit_u31;
	float m_edit_u32;
	float m_edit_u33;

	float m_edit_q11;
	float m_edit_q12;
	float m_edit_q13;
	float m_edit_q14;
	float m_edit_q15;
	float m_edit_q16;
	float m_edit_q21;
	float m_edit_q22;
	float m_edit_q23;
	float m_edit_q24;
	float m_edit_q25;
	float m_edit_q26;
	float m_edit_q31;
	float m_edit_q32;
	float m_edit_q33;
	float m_edit_q34;
	float m_edit_q35;
	float m_edit_q36;

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

	afx_msg void OnEnChangeEditU12();
	afx_msg void OnEnChangeEditU13();
	afx_msg void OnEnChangeEditU23();
	CButton m_StaticPropertiesPHNox;
};
