#pragma once


// ElectricModelingDLGPhaseNo3 dialog

class ElectricModelingDLGPhaseNo3 : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGPhaseNo3)

public:
	ElectricModelingDLGPhaseNo3(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGPhaseNo3();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_PHASE_NO3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	// 响应System type
	BOOL ResponseSignal(int mysignal);
	// 不提供输入服务
	void NoInputService();
	float m_edit_phase_no3_c11;
	float m_edit_phase_no3_c12;
	float m_edit_phase_no3_c13;
	float m_edit_phase_no3_c14;
	float m_edit_phase_no3_c15;
	float m_edit_phase_no3_c16;
	float m_edit_phase_no3_c21;
	float m_edit_phase_no3_c22;
	float m_edit_phase_no3_c23;
	float m_edit_phase_no3_c24;
	float m_edit_phase_no3_c25;
	float m_edit_phase_no3_c26;
	float m_edit_phase_no3_c31;
	float m_edit_phase_no3_c32;
	float m_edit_phase_no3_c33;
	float m_edit_phase_no3_c34;
	float m_edit_phase_no3_c35;
	float m_edit_phase_no3_c36;
	float m_edit_phase_no3_c41;
	float m_edit_phase_no3_c42;
	float m_edit_phase_no3_c43;
	float m_edit_phase_no3_c44;
	float m_edit_phase_no3_c45;
	float m_edit_phase_no3_c46;
	float m_edit_phase_no3_c51;
	float m_edit_phase_no3_c52;
	float m_edit_phase_no3_c53;
	float m_edit_phase_no3_c54;
	float m_edit_phase_no3_c55;
	float m_edit_phase_no3_c56;
	float m_edit_phase_no3_c61;
	float m_edit_phase_no3_c62;
	float m_edit_phase_no3_c63;
	float m_edit_phase_no3_c64;
	float m_edit_phase_no3_c65;
	float m_edit_phase_no3_c66;
	float m_edit_phase_no3_d11;
	float m_edit_phase_no3_d12;
	float m_edit_phase_no3_d13;
	float m_edit_phase_no3_d14;
	float m_edit_phase_no3_d15;
	float m_edit_phase_no3_d16;
	float m_edit_phase_no3_d21;
	float m_edit_phase_no3_d22;
	float m_edit_phase_no3_d23;
	float m_edit_phase_no3_d24;
	float m_edit_phase_no3_d25;
	float m_edit_phase_no3_d26;
	float m_edit_phase_no3_d31;
	float m_edit_phase_no3_d32;
	float m_edit_phase_no3_d33;
	float m_edit_phase_no3_d34;
	float m_edit_phase_no3_d35;
	float m_edit_phase_no3_d36;
	float m_edit_phase_no3_k11;
	float m_edit_phase_no3_k12;
	float m_edit_phase_no3_k13;
	float m_edit_phase_no3_k21;
	float m_edit_phase_no3_k22;
	float m_edit_phase_no3_k23;
	float m_edit_phase_no3_k31;
	float m_edit_phase_no3_k32;
	float m_edit_phase_no3_k33;
	afx_msg void OnEnChangeEditPhaseNo3C12();
	afx_msg void OnChangeEditPhaseNo3C13();
	afx_msg void OnChangeEditPhaseNo3C14();
	afx_msg void OnChangeEditPhaseNo3C15();
	afx_msg void OnChangeEditPhaseNo3C16();
	afx_msg void OnChangeEditPhaseNo3C23();
	afx_msg void OnChangeEditPhaseNo3C24();
	afx_msg void OnChangeEditPhaseNo3C25();
	afx_msg void OnChangeEditPhaseNo3C26();
	afx_msg void OnChangeEditPhaseNo3C34();
	afx_msg void OnChangeEditPhaseNo3C35();
	afx_msg void OnChangeEditPhaseNo3C36();
	afx_msg void OnChangeEditPhaseNo3C45();
	afx_msg void OnChangeEditPhaseNo3C46();
	afx_msg void OnChangeEditPhaseNo3C56();
//	afx_msg void OnEditPhaseNo2K12();
//	afx_msg void OnEditPhaseNo2K13();
//	afx_msg void OnEditPhaseNo2K23();
	afx_msg void OnChangeEditPhaseNo3K12();
	afx_msg void OnChangeEditPhaseNo3K13();
	afx_msg void OnChangeEditPhaseNo3K23();
};
