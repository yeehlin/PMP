#pragma once


// CIsosurfaceDlg dialog

class CIsosurfaceDlg : public CDialog
{
	DECLARE_DYNAMIC(CIsosurfaceDlg)

public:
	CIsosurfaceDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CIsosurfaceDlg();

// Dialog Data
	enum { IDD = IDD_ISOSURFACE_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_edit_min_iso_value_double;
	double m_edit_max_iso_value_double;
	CSliderCtrl m_SliderIsofurface;
	double m_edit_cur_value_double;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMCustomdrawSliderIsosurface(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
