// ElectricModelingDLGThermalExternal.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "ElectricModelingDLGThermalExternal.h"
#include "afxdialogex.h"


// ElectricModelingDLGThermalExternal dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGThermalExternal, CDialog)

ElectricModelingDLGThermalExternal::ElectricModelingDLGThermalExternal(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGThermalExternal::IDD, pParent)
{
	m_edit_ele_e1 = 0.0f;
	m_edit_ele_e2 = 0.0f;
	m_edit_ele_e3 = 0.0f;
}

ElectricModelingDLGThermalExternal::~ElectricModelingDLGThermalExternal()
{
}

void ElectricModelingDLGThermalExternal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ELE_E1, m_edit_ele_e1);
	DDX_Text(pDX, IDC_EDIT_ELE_E2, m_edit_ele_e2);
	DDX_Text(pDX, IDC_EDIT_ELE_E3, m_edit_ele_e3);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGThermalExternal, CDialog)
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGThermalExternal::OnBnClickedOk)
END_MESSAGE_MAP()


// ElectricModelingDLGThermalExternal message handlers


void ElectricModelingDLGThermalExternal::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	this->UpdateData(TRUE);
	//CDialog::OnOK();
}


BOOL ElectricModelingDLGThermalExternal::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
