#pragma once


// CScaleFactorDlg dialog

class CScaleFactorDlg : public CDialog
{
	DECLARE_DYNAMIC(CScaleFactorDlg)

public:
	CScaleFactorDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CScaleFactorDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_SCALEFACTOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_edit_scale_factor;
	virtual BOOL OnInitDialog();
	CString m_caption;
	double fadefault;
	afx_msg void OnClickedButtonScalefactorDefault();
};
