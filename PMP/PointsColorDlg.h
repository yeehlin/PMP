#pragma once


// CPointsColorDlg dialog

class CPointsColorDlg : public CDialog
{
	DECLARE_DYNAMIC(CPointsColorDlg)

public:
	CPointsColorDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPointsColorDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_POINTS_COLOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_edit_rgb_value_point1_double;
	double m_edit_rgb_value_point2_double;
	double m_edit_rgb_value_point3_double;
	double m_edit_rgb_value_point4_double;
	double m_edit_rgb_value_point5_double;
	double m_edit_rgb_value_point6_double;
	CSliderCtrl m_SlierRgbValue1;
	CSliderCtrl m_SlierRgbValue2;
	CSliderCtrl m_SlierRgbValue3;
	CSliderCtrl m_SlierRgbValue4;
	CSliderCtrl m_SlierRgbValue5;
	CSliderCtrl m_SlierRgbValue6;
	CSliderCtrl m_SlierOpaValue1;
	CSliderCtrl m_SlierOpaValue2;
	CSliderCtrl m_SlierOpaValue3;
	CSliderCtrl m_SlierOpaValue4;
	CSliderCtrl m_SlierOpaValue5;
	CSliderCtrl m_SlierOpaValue6;
	double m_edit_rgb_value_r1;
	double m_edit_rgb_value_r2;
	double m_edit_rgb_value_r3;
	double m_edit_rgb_value_r4;
	double m_edit_rgb_value_r5;
	double m_edit_rgb_value_r6;
	double m_edit_rgb_value_g1;
	double m_edit_rgb_value_g2;
	double m_edit_rgb_value_g3;
	double m_edit_rgb_value_g4;
	double m_edit_rgb_value_g5;
	double m_edit_rgb_value_g6;
	double m_edit_rgb_value_b1;
	double m_edit_rgb_value_b2;
	double m_edit_rgb_value_b3;
	double m_edit_rgb_value_b4;
	double m_edit_rgb_value_b5;
	double m_edit_rgb_value_b6;
	CButton m_ButtonPoint1Add;
	CButton m_ButtonPoint2Add;
	CButton m_ButtonPoint3Add;
	CButton m_ButtonPoint4Add;
	CButton m_ButtonPoint5Add;
	CButton m_ButtonPoint6Add;
	CButton m_ButtonOpaPoint1Add;
	CButton m_ButtonOpaPoint2Add;
	CButton m_ButtonOpaPoint3Add;
	CButton m_ButtonOpaPoint4Add;
	CButton m_ButtonOpaPoint5Add;
	CButton m_ButtonOpaPoint6Add;
	double m_edit_min_value_points;
	double m_edit_max_value_points;
	double m_edit_min_value_opa;
	double m_edit_max_value_opa;
	double m_edit_opa_value_point1;
	double m_edit_opa_value_point2;
	double m_edit_opa_value_point3;
	double m_edit_opa_value_point4;
	double m_edit_opa_value_point5;
	double m_edit_opa_value_point6;
	double m_edit_opa_value1;
	double m_edit_opa_value2;
	double m_edit_opa_value3;
	double m_edit_opa_value4;
	double m_edit_opa_value5;
	double m_edit_opa_value6;
	afx_msg void OnNMCustomdrawSliderRgbValue1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderRgbValue2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderRgbValue3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderRgbValue4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderRgbValue5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderRgbValue6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderOpaValue1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderOpaValue2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderOpaValue3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderOpaValue4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderOpaValue5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderOpaValue6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonPoint1Add();
	afx_msg void OnBnClickedButtonPoint2Add();
	afx_msg void OnBnClickedButtonPoint3Add();
	afx_msg void OnBnClickedButtonPoint4Add();
	afx_msg void OnBnClickedButtonPoint5Add();
	afx_msg void OnBnClickedButtonPoint6Add();
	afx_msg void OnBnClickedButtonOpaPoint1Add();
	afx_msg void OnBnClickedButtonOpaPoint2Add();
	afx_msg void OnBnClickedButtonOpaPoint3Add();
	afx_msg void OnBnClickedButtonOpaPoint4Add();
	afx_msg void OnBnClickedButtonOpaPoint5Add();
	afx_msg void OnBnClickedButtonOpaPoint6Add();
	virtual BOOL OnInitDialog();

public :
	// 设置窗口标题
	CString m_cation;

	CEdit m_EditOpaValuePoint1;
	CEdit m_EditOpaValuePoint2;
	CEdit m_EditOpaValuePoint3;
	CEdit m_EditOpaValuePoint4;
	CEdit m_EditOpaValuePoint5;
	CEdit m_EditOpaValuePoint6;
	CEdit m_EditOpaValue1;
	CEdit m_EditOpaValue2;
	CEdit m_EditOpaValue3;
	CEdit m_EditOpaValue4;
	CEdit m_EditOpaValue5;
	CEdit m_EditOpaValue6;
	CEdit m_EditRgbValueB1;
	CEdit m_EditRgbValueB2;
	CEdit m_EditRgbValueB3;
	CEdit m_EditRgbValueB4;
	CEdit m_EditRgbValueB5;
	CEdit m_EditRgbValueB6;
	CEdit m_EditRgbValueG1;
	CEdit m_EditRgbValueG2;
	CEdit m_EditRgbValueG3;
	CEdit m_EditRgbValueG4;
	CEdit m_EditRgbValueG5;
	CEdit m_EditRgbValueG6;
	CEdit m_EditRgbValuePoint1;
	CEdit m_EditRgbValuePoint2;
	CEdit m_EditRgbValuePoint3;
	CEdit m_EditRgbValuePoint4;
	CEdit m_EditRgbValuePoint5;
	CEdit m_EditRgbValuePoint6;
	CEdit m_EditRgbValueR1;
	CEdit m_EditRgbValueR2;
	CEdit m_EditRgbValueR3;
	CEdit m_EditRgbValueR4;
	CEdit m_EditRgbValueR5;
	CEdit m_EditRgbValueR6;
	//////////////////////////////////值地址////////////////////////////////////////
	// 颜色点值地址
	double * RGBPoints[6];
	double * RGBR[6];
	double * RGBG[6];
	double * RGBB[6];
	double * OPAPoints[6];
	double * OPA[6];
	///////////////////////////////////值地址///////////////////////////////////////
	////////////////////////////////////控件地址//////////////////////////////////////
	// 颜色点控件地址
	CEdit * RGBEditPoints[6];
	// 滑块地址
	CSliderCtrl * RGBSlider[6];
	CEdit * RGBEditR[6];
	CEdit * RGBEditG[6];
	CEdit * RGBEditB[6];
	CButton * RGBButton [6];
	///////////////////////////////////////控件地址///////////////////////////////////
	////////////////////////////////////////控件地址//////////////////////////////////
	// 透明点控件地址
	CEdit * OPAEditPoints[6];
	CSliderCtrl * OPASlider[6];
	// 透明值地址
	CEdit * OPAEdit[6];
	CButton * OPAButton [6];
	////////////////////////////////////////控件地址//////////////////////////////////
	// 表示有多少个点
	int RGBnPoints;
	int OPAnPoints;
	// 表示点是否选中
	BOOL RGBFlag[6];
	BOOL OPAFlag[6];
};
