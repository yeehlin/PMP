#pragma once


// ElectricModelingDLGPhaseNo2 dialog

class ElectricModelingDLGPhaseNo2 : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGPhaseNo2)

public:
	ElectricModelingDLGPhaseNo2(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGPhaseNo2();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_PHASE_NO2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	// 响应System type
	BOOL ResponseSignal(int mysignal);
	// 不提供输入服务
	void NoInputService();
	int SameSignalFlag;
	float m_edit_phase_no2_c11;
	float m_edit_phase_no2_c12;
	float m_edit_phase_no2_c13;
	float m_edit_phase_no2_c14;
	float m_edit_phase_no2_c15;
	float m_edit_phase_no2_c16;
	float m_edit_phase_no2_c21;
	float m_edit_phase_no2_c22;
	float m_edit_phase_no2_c23;
	float m_edit_phase_no2_c24;
	float m_edit_phase_no2_c25;
	float m_edit_phase_no2_c26;
	float m_edit_phase_no2_c31;
	float m_edit_phase_no2_c32;
	float m_edit_phase_no2_c33;
	float m_edit_phase_no2_c34;
	float m_edit_phase_no2_c35;
	float m_edit_phase_no2_c36;
	float m_edit_phase_no2_c41;
	float m_edit_phase_no2_c42;
	float m_edit_phase_no2_c43;
	float m_edit_phase_no2_c44;
	float m_edit_phase_no2_c45;
	float m_edit_phase_no2_c46;
	float m_edit_phase_no2_c51;
	float m_edit_phase_no2_c52;
	float m_edit_phase_no2_c53;
	float m_edit_phase_no2_c54;
	float m_edit_phase_no2_c55;
	float m_edit_phase_no2_c56;
	float m_edit_phase_no2_c61;
	float m_edit_phase_no2_c62;
	float m_edit_phase_no2_c63;
	float m_edit_phase_no2_c64;
	float m_edit_phase_no2_c65;
	float m_edit_phase_no2_c66;
	float m_edit_phase_no2_d11;
	float m_edit_phase_no2_d12;
	float m_edit_phase_no2_d13;
	float m_edit_phase_no2_d14;
	float m_edit_phase_no2_d15;
	float m_edit_phase_no2_d16;
	float m_edit_phase_no2_d21;
	float m_edit_phase_no2_d22;
	float m_edit_phase_no2_d23;
	float m_edit_phase_no2_d24;
	float m_edit_phase_no2_d25;
	float m_edit_phase_no2_d26;
	float m_edit_phase_no2_d31;
	float m_edit_phase_no2_d32;
	float m_edit_phase_no2_d33;
	float m_edit_phase_no2_d34;
	float m_edit_phase_no2_d35;
	float m_edit_phase_no2_d36;
	float m_edit_phase_no2_k11;
	float m_edit_phase_no2_k12;
	float m_edit_phase_no2_k13;
	float m_edit_phase_no2_k21;
	float m_edit_phase_no2_k22;
	float m_edit_phase_no2_k23;
	float m_edit_phase_no2_k31;
	float m_edit_phase_no2_k32;
	float m_edit_phase_no2_k33;
	afx_msg void OnEnChangeEditPhaseNo2C12();
	afx_msg void OnEnChangeEditPhaseNo2C13();
	afx_msg void OnEnChangeEditPhaseNo2C14();
	afx_msg void OnEnChangeEditPhaseNo2C15();
	afx_msg void OnEnChangeEditPhaseNo2C16();
	afx_msg void OnEnChangeEditPhaseNo2C23();
	afx_msg void OnEnChangeEditPhaseNo2C24();
	afx_msg void OnEnChangeEditPhaseNo2C25();
	afx_msg void OnEnChangeEditPhaseNo2C26();
	afx_msg void OnEnChangeEditPhaseNo2C34();
	afx_msg void OnEnChangeEditPhaseNo2C35();
	afx_msg void OnEnChangeEditPhaseNo2C36();
	afx_msg void OnEnChangeEditPhaseNo2C45();
	afx_msg void OnEnChangeEditPhaseNo2C46();
	afx_msg void OnEnChangeEditPhaseNo2C56();
	afx_msg void OnEnChangeEditPhaseNo2K12();
	afx_msg void OnChangeEditPhaseNo2K13();
	afx_msg void OnChangeEditPhaseNo2K23();
};
