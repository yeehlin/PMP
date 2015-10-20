#pragma once


// PMPDlgJobs dialog

class PMPDlgJobs : public CDialog
{
	DECLARE_DYNAMIC(PMPDlgJobs)

public:
	PMPDlgJobs(CWnd* pParent = NULL);   // standard constructor
	virtual ~PMPDlgJobs();

// Dialog Data
	enum { IDD = IDD_DLG_JOBS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboPmpserverip();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonLink();
	CComboBox m_Combo_PmpServerIP;
	CComboBox m_Combo_PmpServerPort;
	CString m_Combo_PmpServerIP_str;
	CString m_Combo_PmpServerPort_str;
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonReceive();
};
