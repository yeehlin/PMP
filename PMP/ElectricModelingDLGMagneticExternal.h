#pragma once


// ElectricModelingDLGMagneticExternal dialog

class ElectricModelingDLGMagneticExternal : public CDialog
{
	DECLARE_DYNAMIC(ElectricModelingDLGMagneticExternal)

public:
	ElectricModelingDLGMagneticExternal(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElectricModelingDLGMagneticExternal();

// Dialog Data
	enum { IDD = IDD_MODELING_DLG_MAGNETIC_EXTERNAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	float m_edit_mag_h1;
	float m_edit_mag_h2;
	float m_edit_mag_h3;
	virtual BOOL OnInitDialog();
};
