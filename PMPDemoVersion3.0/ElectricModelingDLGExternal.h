#pragma once

// ElectricModelingDLGExternal dialog

class ElectricModelingDLGExternal : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGExternal)

public:
	ElectricModelingDLGExternal(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGExternal();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_EXTERNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	float m_edit_e1;
	float m_edit_e2;
	float m_edit_eo3;
	virtual BOOL OnInitDialog();
};
