#pragma once

// CalculateDlgChild1 dialog
#include "resource.h"
class CalculateDlgChild1 : public CDialog
{
	DECLARE_DYNAMIC(CalculateDlgChild1)

public:
	CalculateDlgChild1(CWnd* pParent = NULL);   // standard constructor
	virtual ~CalculateDlgChild1();

// Dialog Data
	enum { IDD = IDD_CALCULATE_DLG_CHILD1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	float m_edit_dx;
	float m_edit_dy;
	CComboBox m_comboRegsize;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadioRegsize();
	afx_msg void OnDeltaposSpinDx(NMHDR *pNMHDR, LRESULT *pResult);
	CButton m_RadioRegSize;
	CSpinButtonCtrl m_SpinDx;
	CSpinButtonCtrl m_SpinDy;
	CSpinButtonCtrl m_SpinDz;
	CEdit m_EditDx;
	CEdit m_EditDy;
	CEdit m_EditDz;
	afx_msg void OnDeltaposSpinDy(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinDz(NMHDR *pNMHDR, LRESULT *pResult);
	float m_edit_dz;
	float m_edit_time_step_size;
	float m_edit_atmmobility;
	float m_edit_gradcoef;
	afx_msg void OnDeltaposSpinTimeStepSize(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinAtmmobility(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinGradcoef(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_EditTimeStepSize;
	CEdit m_EditATMMobility;
	CEdit m_EditGradCoef;
	CEdit m_EidtNoise;
	float m_edit_noise;
	CSpinButtonCtrl m_SpinTimeStepSize;
	CSpinButtonCtrl m_SpinATMMobility;
	CSpinButtonCtrl m_SpinGradCoef;
	CSpinButtonCtrl m_SpinNoise;
	CSpinButtonCtrl m_SpinRandomSeed;
	afx_msg void OnDeltaposSpinNoise(NMHDR *pNMHDR, LRESULT *pResult);
	int m_edit_random_seed;
	CEdit m_EditRandomSeed;
	afx_msg void OnDeltaposSpinRandomSeed(NMHDR *pNMHDR, LRESULT *pResult);
	BOOL m_radio_regsize;
	CString m_combo_regsize;
	CString m_edit_x;
	CString m_edit_y;
	CButton m_RadioNewStart;
	BOOL m_radio_new_start;
};
