// ElectricModelingDLGDiffusivityExternal.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
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

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
