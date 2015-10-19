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
	CString m_caption;
	CSliderCtrl m_SliderIsosurface;
	CSliderCtrl m_SliderIsosurface2;
	double m_edit_min_iso_value_double;
	double m_edit_max_iso_value_double;
	double m_edit_cur_iso_value_double;
	double m_edit_cur_iso_value2;
	double m_edit_min_opa_value_double;
	double m_edit_max_opa_value_double;
	CSliderCtrl m_SliderOpacity;
	CSliderCtrl m_SliderOpacity2;
	double m_edit_cur_opa_value_double;
	double m_edit_cur_opa_value2_double;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMCustomdrawSliderIsosurface(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderIsosurface2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderOpacity(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderOpacity2(NMHDR *pNMHDR, LRESULT *pResult);
};
