#pragma once


// CStreamlineSeedsDlg dialog

class CStreamlineSeedsDlg : public CDialog
{
	DECLARE_DYNAMIC(CStreamlineSeedsDlg)

public:
	CStreamlineSeedsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CStreamlineSeedsDlg();

// Dialog Data
	enum { IDD = IDD_STREAMLINE_SEEDS_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_edit_streamline_seeds_x_int;
	int m_edit_streamline_seeds_y_int;
	int m_edit_streamline_seeds_z_int;
	int m_edit_streamline_seeds_points_int;
	float m_edit_streamline_seeds_radius_float;
	virtual BOOL OnInitDialog();
	CString m_caption;
};
