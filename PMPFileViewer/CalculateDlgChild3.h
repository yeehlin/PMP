#pragma once


// CalculateDlgChild3 dialog

class CalculateDlgChild3 : public CDialog
{
	DECLARE_DYNAMIC(CalculateDlgChild3)

public:
	CalculateDlgChild3(CWnd* pParent = NULL);   // standard constructor
	virtual ~CalculateDlgChild3();

// Dialog Data
	enum { IDD = IDD_CALCULATE_DLG_CHILD3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboGateway;
	virtual BOOL OnInitDialog();
	CSpinButtonCtrl m_spinRunPars;
};
