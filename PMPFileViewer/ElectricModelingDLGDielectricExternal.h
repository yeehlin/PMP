#pragma once


// ElectricModelingDLGDielectricExternal dialog

class ElectricModelingDLGDielectricExternal : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGDielectricExternal)

public:
	ElectricModelingDLGDielectricExternal(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGDielectricExternal();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_DIELETRIC_EXTERNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	float m_edit_ele_e1;
	float m_edit_ele_e2;
	float m_edit_ele_e3;
	virtual BOOL OnInitDialog();
};
