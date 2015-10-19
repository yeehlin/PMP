#pragma once


// ElectricModelingDLGPhaseNo6 dialog

class ElectricModelingDLGPhaseNo6 : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGPhaseNo6)

public:
	ElectricModelingDLGPhaseNo6(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGPhaseNo6();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_PHASE_NO6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	BOOL ResponseSignal(int mysignal);
	// 不提供输入服务
	void NoInputService();
	float m_edit_phase_no6_c11;
	float m_edit_phase_no6_c12;
	float m_edit_phase_no6_c13;
	float m_edit_phase_no6_c14;
	float m_edit_phase_no6_c15;
	float m_edit_phase_no6_c16;
	float m_edit_phase_no6_c21;
	float m_edit_phase_no6_c22;
	float m_edit_phase_no6_c23;
	float m_edit_phase_no6_c24;
	float m_edit_phase_no6_c25;
	float m_edit_phase_no6_c26;
	float m_edit_phase_no6_c31;
	float m_edit_phase_no6_c32;
	float m_edit_phase_no6_c33;
	float m_edit_phase_no6_c34;
	float m_edit_phase_no6_c35;
	float m_edit_phase_no6_c36;
	float m_edit_phase_no6_c41;
	float m_edit_phase_no6_c42;
	float m_edit_phase_no6_c43;
	float m_edit_phase_no6_c44;
	float m_edit_phase_no6_c45;
	float m_edit_phase_no6_c46;
	float m_edit_phase_no6_c51;
	float m_edit_phase_no6_c52;
	float m_edit_phase_no6_c53;
	float m_edit_phase_no6_c54;
	float m_edit_phase_no6_c55;
	float m_edit_phase_no6_c56;
	float m_edit_phase_no6_c61;
	float m_edit_phase_no6_c62;
	float m_edit_phase_no6_c63;
	float m_edit_phase_no6_c64;
	float m_edit_phase_no6_c65;
	float m_edit_phase_no6_c66;
	float m_edit_phase_no6_d11;
	float m_edit_phase_no6_d12;
	float m_edit_phase_no6_d13;
	float m_edit_phase_no6_d14;
	float m_edit_phase_no6_d15;
	float m_edit_phase_no6_d16;
	float m_edit_phase_no6_d21;
	float m_edit_phase_no6_d22;
	float m_edit_phase_no6_d23;
	float m_edit_phase_no6_d24;
	float m_edit_phase_no6_d25;
	float m_edit_phase_no6_d26;
	float m_edit_phase_no6_d31;
	float m_edit_phase_no6_d32;
	float m_edit_phase_no6_d33;
	float m_edit_phase_no6_d34;
	float m_edit_phase_no6_d35;
	float m_edit_phase_no6_d36;
	float m_edit_phase_no6_k11;
	float m_edit_phase_no6_k12;
	float m_edit_phase_no6_k13;
	float m_edit_phase_no6_k21;
	float m_edit_phase_no6_k22;
	float m_edit_phase_no6_k23;
	float m_edit_phase_no6_k31;
	float m_edit_phase_no6_k32;
	float m_edit_phase_no6_k33;
	afx_msg void OnChangeEditPhaseNo6C12();
	afx_msg void OnChangeEditPhaseNo6C13();
	afx_msg void OnChangeEditPhaseNo6C14();
	afx_msg void OnChangeEditPhaseNo6C15();
	afx_msg void OnChangeEditPhaseNo6C16();
	afx_msg void OnChangeEditPhaseNo6C23();
	afx_msg void OnChangeEditPhaseNo6C24();
	afx_msg void OnChangeEditPhaseNo6C25();
	afx_msg void OnChangeEditPhaseNo6C26();
	afx_msg void OnChangeEditPhaseNo6C34();
	afx_msg void OnChangeEditPhaseNo6C35();
	afx_msg void OnChangeEditPhaseNo6C36();
	afx_msg void OnChangeEditPhaseNo6C45();
	afx_msg void OnChangeEditPhaseNo6C46();
	afx_msg void OnChangeEditPhaseNo6C56();
	afx_msg void OnChangeEditPhaseNo6K12();
	afx_msg void OnChangeEditPhaseNo6K13();
	afx_msg void OnChangeEditPhaseNo6K23();
};
