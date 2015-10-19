#pragma once


// ElectricModelingDLGDiffusivityExternal dialog

class ElectricModelingDLGDiffusivityExternal : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGDiffusivityExternal)

public:
	ElectricModelingDLGDiffusivityExternal(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGDiffusivityExternal();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_DIFFUSIVITY_EXTERNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	float m_edit_ele_e1;
	float m_edit_ele_e2;
	float m_edit_ele_e3;
	virtual BOOL OnInitDialog();
	CString m_static_avrg_cont_grad_string;
};
