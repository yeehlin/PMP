#pragma once


// ElectricModelingDLGThermal dialog

class ElectricModelingDLGThermal : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGThermal)

public:
	ElectricModelingDLGThermal(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGThermal();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_THERMAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	float m_edit_k11;
	float m_edit_k12;
	float m_edit_k13;
	float m_edit_k21;
	float m_edit_k22;
	float m_edit_k23;
	float m_edit_k31;
	float m_edit_k32;
	float m_edit_k33;

	afx_msg void OnEnChangeEditK12();
	afx_msg void OnEnChangeEditK13();
	afx_msg void OnEnChangeEditK23();
	CButton m_StaticPropertiesPHNox;
public :
	// 指向共享矩阵的指针
	float ** kkk;
public :
	// 将变量组织成逻辑上的矩阵
	float * k[3][3];

public:
	void LoadSharedData();
};
