#pragma once


// ElectricModelingDLGPhaseNo4 dialog

class ElectricModelingDLGPhaseNo4 : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGPhaseNo4)

public:
	ElectricModelingDLGPhaseNo4(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGPhaseNo4();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_PHASE_NO4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	BOOL ResponseSignal(int mysignal);
	// 不提供输入服务
	void NoInputService();
	float m_edit_phase_no4_c11;
	float m_edit_phase_no4_c12;
	float m_edit_phase_no4_c13;
	float m_edit_phase_no4_c14;
	float m_edit_phase_no4_c15;
	float m_edit_phase_no4_c16;
	float m_edit_phase_no4_c21;
	float m_edit_phase_no4_c22;
	float m_edit_phase_no4_c23;
	float m_edit_phase_no4_c24;
	float m_edit_phase_no4_c25;
	float m_edit_phase_no4_c26;
	float m_edit_phase_no4_c31;
	float m_edit_phase_no4_c32;
	float m_edit_phase_no4_c33;
	float m_edit_phase_no4_c34;
	float m_edit_phase_no4_c35;
	float m_edit_phase_no4_c36;
	float m_edit_phase_no4_c41;
	float m_edit_phase_no4_c42;
	float m_edit_phase_no4_c43;
	float m_edit_phase_no4_c44;
	float m_edit_phase_no4_c45;
	float m_edit_phase_no4_c46;
	float m_edit_phase_no4_c51;
	float m_edit_phase_no4_c52;
	float m_edit_phase_no4_c53;
	float m_edit_phase_no4_c54;
	float m_edit_phase_no4_c55;
	float m_edit_phase_no4_c56;
	float m_edit_phase_no4_c61;
	float m_edit_phase_no4_c62;
	float m_edit_phase_no4_c63;
	float m_edit_phase_no4_c64;
	float m_edit_phase_no4_c65;
	float m_edit_phase_no4_c66;
	float m_edit_phase_no4_d11;
	float m_edit_phase_no4_d12;
	float m_edit_phase_no4_d13;
	float m_edit_phase_no4_d14;
	float m_edit_phase_no4_d15;
	float m_edit_phase_no4_d16;
	float m_edit_phase_no4_d21;
	float m_edit_phase_no4_d22;
	float m_edit_phase_no4_d23;
	float m_edit_phase_no4_d24;
	float m_edit_phase_no4_d25;
	float m_edit_phase_no4_d26;
	float m_edit_phase_no4_d31;
	float m_edit_phase_no4_d32;
	float m_edit_phase_no4_d33;
	float m_edit_phase_no4_d34;
	float m_edit_phase_no4_d35;
	float m_edit_phase_no4_d36;
	float m_edit_phase_no4_k11;
	float m_edit_phase_no4_k12;
	float m_edit_phase_no4_k13;
	float m_edit_phase_no4_k21;
	float m_edit_phase_no4_k22;
	float m_edit_phase_no4_k23;
	float m_edit_phase_no4_k31;
	float m_edit_phase_no4_k32;
	float m_edit_phase_no4_k33;
//	afx_msg void OnEditPhaseNo3C56();
	afx_msg void OnChangeEditPhaseNo4C12();
	afx_msg void OnChangeEditPhaseNo4C13();
	afx_msg void OnChangeEditPhaseNo4C14();
	afx_msg void OnChangeEditPhaseNo4C15();
	afx_msg void OnChangeEditPhaseNo4C16();
	afx_msg void OnChangeEditPhaseNo4C23();
	afx_msg void OnChangeEditPhaseNo4C24();
	afx_msg void OnChangeEditPhaseNo4C25();
	afx_msg void OnChangeEditPhaseNo4C26();
	afx_msg void OnChangeEditPhaseNo4C34();
	afx_msg void OnChangeEditPhaseNo4C35();
	afx_msg void OnChangeEditPhaseNo4C36();
	afx_msg void OnChangeEditPhaseNo4C45();
	afx_msg void OnChangeEditPhaseNo4C46();
	afx_msg void OnChangeEditPhaseNo4C56();
	afx_msg void OnChangeEditPhaseNo4K12();
	afx_msg void OnChangeEditPhaseNo4K13();
	afx_msg void OnChangeEditPhaseNo4K23();
};
