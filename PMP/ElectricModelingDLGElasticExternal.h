#pragma once


// ElectricModelingDLGElasticExternal dialog

class ElectricModelingDLGElasticExternal : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGElasticExternal)

public:
	ElectricModelingDLGElasticExternal(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGElasticExternal();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_ELASTIC_EXTERNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CComboBox m_ComboMechanicalBoundary;
	CString m_combo_mechanical_boundary_string;
	int m_combo_mechanical_boundary_int;
	CStatic m_StaticEq11;
	CStatic m_StaticEq12;
	CStatic m_StaticEq13;
	CStatic m_StaticEq22;
	CStatic m_StaticEq23;
	CStatic m_StaticEq33;
	CString m_static_eq11;
	CString m_static_eq12;
	CString m_static_eq13;
	CString m_static_eq22;
	CString m_static_eq23;
	CString m_static_eq33;
	float m_edit_eq11;
	float m_edit_eq12;
	float m_edit_eq13;
	float m_edit_eq22;
	float m_edit_eq23;
	float m_edit_eq33;
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboMechanicalBoundary();

public :
	// 定义external区域的共享变量，该类也是共享变量的维护者
	static float eqe[6];
	static float eqq[6];
	static float ele[3];
	static float magh[3];
public :
	// 用于指向共享变量eqe的指针
	float * seqe;
};
