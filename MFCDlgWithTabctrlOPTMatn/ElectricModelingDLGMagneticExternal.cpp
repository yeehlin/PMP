// ElectricModelingDLGMagneticExternal.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGMagneticExternal.h"
#include "afxdialogex.h"


// ElectricModelingDLGMagneticExternal dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMagneticExternal, CDialog)

ElectricModelingDLGMagneticExternal::ElectricModelingDLGMagneticExternal(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMagneticExternal::IDD, pParent)
{
	m_edit_mag_h1 = 0.0f;
	m_edit_mag_h2 = 0.0f;
	m_edit_mag_h3 = 0.0f;
}

ElectricModelingDLGMagneticExternal::~ElectricModelingDLGMagneticExternal()
{
}

void ElectricModelingDLGMagneticExternal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MAG_H1, m_edit_mag_h1);
	DDX_Text(pDX, IDC_EDIT_MAG_H2, m_edit_mag_h2);
	DDX_Text(pDX, IDC_EDIT_MAG_H3, m_edit_mag_h3);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMagneticExternal, CDialog)
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGMagneticExternal::OnBnClickedOk)
END_MESSAGE_MAP()


// ElectricModelingDLGMagneticExternal message handlers


void ElectricModelingDLGMagneticExternal::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	this->UpdateData(TRUE);
	//CDialog::OnOK();
}


BOOL ElectricModelingDLGMagneticExternal::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
