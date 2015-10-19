#pragma once


// ElectricModelingDLGDielectric dialog

class ElectricModelingDLGDielectric : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGDielectric)

public:
	ElectricModelingDLGDielectric(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGDielectric();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_DIELECTRIC };

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
//	afx_msg void OnBnClickedOk();
	CButton m_StaticPropertiesPHNox;
};
