#pragma once


// ElectricModelingDLGPhaseNo5 dialog

class ElectricModelingDLGPhaseNo5 : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGPhaseNo5)

public:
	ElectricModelingDLGPhaseNo5(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGPhaseNo5();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_PHASE_NO5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	BOOL ResponseSignal(int mysignal);
	// 不提供输入服务
	void NoInputService();
	float m_edit_phase_no5_c11;
	float m_edit_phase_no5_c12;
	float m_edit_phase_no5_c13;
	float m_edit_phase_no5_c14;
	float m_edit_phase_no5_c15;
	float m_edit_phase_no5_c16;
	float m_edit_phase_no5_c21;
	float m_edit_phase_no5_c22;
	float m_edit_phase_no5_c23;
	float m_edit_phase_no5_c24;
	float m_edit_phase_no5_c25;
	float m_edit_phase_no5_c26;
	float m_edit_phase_no5_c31;
	float m_edit_phase_no5_c32;
	float m_edit_phase_no5_c33;
	float m_edit_phase_no5_c34;
	float m_edit_phase_no5_c35;
	float m_edit_phase_no5_c36;
	float m_edit_phase_no5_c41;
	float m_edit_phase_no5_c42;
	float m_edit_phase_no5_c43;
	float m_edit_phase_no5_c44;
	float m_edit_phase_no5_c45;
	float m_edit_phase_no5_c46;
	float m_edit_phase_no5_c51;
	float m_edit_phase_no5_c52;
	float m_edit_phase_no5_c53;
	float m_edit_phase_no5_c54;
	float m_edit_phase_no5_c55;
	float m_edit_phase_no5_c56;
	float m_edit_phase_no5_c61;
	float m_edit_phase_no5_c62;
	float m_edit_phase_no5_c63;
	float m_edit_phase_no5_c64;
	float m_edit_phase_no5_c65;
	float m_edit_phase_no5_c66;
	float m_edit_phase_no5_d11;
	float m_edit_phase_no5_d12;
	float m_edit_phase_no5_d13;
	float m_edit_phase_no5_d14;
	float m_edit_phase_no5_d15;
	float m_edit_phase_no5_d16;
	float m_edit_phase_no5_d21;
	float m_edit_phase_no5_d22;
	float m_edit_phase_no5_d23;
	float m_edit_phase_no5_d24;
	float m_edit_phase_no5_d25;
	float m_edit_phase_no5_d26;
	float m_edit_phase_no5_d31;
	float m_edit_phase_no5_d32;
	float m_edit_phase_no5_d33;
	float m_edit_phase_no5_d34;
	float m_edit_phase_no5_d35;
	float m_edit_phase_no5_d36;
	float m_edit_phase_no5_k11;
	float m_edit_phase_no5_k12;
	float m_edit_phase_no5_k13;
	float m_edit_phase_no5_k21;
	float m_edit_phase_no5_k22;
	float m_edit_phase_no5_k23;
	float m_edit_phase_no5_k31;
	float m_edit_phase_no5_k32;
	float m_edit_phase_no5_k33;
	afx_msg void OnChangeEditPhaseNo5C12();
	afx_msg void OnChangeEditPhaseNo5C13();
	afx_msg void OnChangeEditPhaseNo5C14();
	afx_msg void OnChangeEditPhaseNo5C15();
	afx_msg void OnChangeEditPhaseNo5C16();
	afx_msg void OnChangeEditPhaseNo5C23();
	afx_msg void OnChangeEditPhaseNo5C24();
	afx_msg void OnChangeEditPhaseNo5C25();
	afx_msg void OnChangeEditPhaseNo5C26();
	afx_msg void OnChangeEditPhaseNo5C34();
	afx_msg void OnChangeEditPhaseNo5C35();
	afx_msg void OnChangeEditPhaseNo5C36();
	afx_msg void OnChangeEditPhaseNo5C45();
	afx_msg void OnChangeEditPhaseNo5C46();
	afx_msg void OnChangeEditPhaseNo5C56();
	afx_msg void OnChangeEditPhaseNo5K12();
	afx_msg void OnChangeEditPhaseNo5K13();
	afx_msg void OnChangeEditPhaseNo5K23();
};
