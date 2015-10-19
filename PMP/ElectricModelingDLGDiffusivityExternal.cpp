// ElectricModelingDLGDiffusivityExternal.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ElectricModelingDLGDiffusivityExternal.h"
#include "afxdialogex.h"


// ElectricModelingDLGDiffusivityExternal dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGDiffusivityExternal, CDialog)

ElectricModelingDLGDiffusivityExternal::ElectricModelingDLGDiffusivityExternal(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGDiffusivityExternal::IDD, pParent)
{

	m_edit_ele_e1 = 0.0f;
	m_edit_ele_e2 = 0.0f;
	m_edit_ele_e3 = 0.0f;
	m_static_avrg_cont_grad_string = _T("¨Œc( kg/m^4)");
}

ElectricModelingDLGDiffusivityExternal::~ElectricModelingDLGDiffusivityExternal()
{
}

void ElectricModelingDLGDiffusivityExternal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ELE_E1, m_edit_ele_e1);
	DDX_Text(pDX, IDC_EDIT_ELE_E2, m_edit_ele_e2);
	DDX_Text(pDX, IDC_EDIT_ELE_E3, m_edit_ele_e3);
	DDX_Text(pDX, IDC_STATIC_AVRG_CONT_GRAD, m_static_avrg_cont_grad_string);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGDiffusivityExternal, CDialog)
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGDiffusivityExternal::OnBnClickedOk)
END_MESSAGE_MAP()


// ElectricModelingDLGDiffusivityExternal message handlers


void ElectricModelingDLGDiffusivityExternal::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	this->UpdateData(TRUE);
	//CDialog::OnOK();
}


BOOL ElectricModelingDLGDiffusivityExternal::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	m_static_avrg_cont_grad_string = _T("¨Œc( kg/m^4)");

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
