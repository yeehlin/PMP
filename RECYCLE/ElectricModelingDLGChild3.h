#pragma once


// ElectricModelingDLGChild3 dialog

class ElectricModelingDLGChild3 : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGChild3)

public:
	ElectricModelingDLGChild3(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGChild3();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_CHILD3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_ComboBondaryCondition;
	BOOL ResponseSignal(int mysignal);
};