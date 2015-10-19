// ElectricModelingDLGChild3.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGChild3.h"
#include "afxdialogex.h"


// ElectricModelingDLGChild3 dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGChild3, CDialog)

ElectricModelingDLGChild3::ElectricModelingDLGChild3(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGChild3::IDD, pParent)
{

}

ElectricModelingDLGChild3::~ElectricModelingDLGChild3()
{
}

void ElectricModelingDLGChild3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_BONDARY_CONDITION, m_ComboBondaryCondition);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGChild3, CDialog)
END_MESSAGE_MAP()


// ElectricModelingDLGChild3 message handlers


BOOL ElectricModelingDLGChild3::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	// 设置下拉内容
	m_ComboBondaryCondition.AddString("Applied strain ε1~ε6");
	m_ComboBondaryCondition.AddString("Applied stress σ1~σ6(Pa)");
	// 设置下拉默认选项
	m_ComboBondaryCondition.SetCurSel(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL ElectricModelingDLGChild3::ResponseSignal(int mysignal){
	switch(mysignal){
	case 0:
		// external field
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO1)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO2)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO3)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO4)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO5)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO6)))->SetReadOnly(FALSE);


		((CEdit *)(this->GetDlgItem(IDC_EDIT_E1)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_E2)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_E3)))->SetReadOnly(TRUE);
		break;
	case 1:

		// external field
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO1)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO2)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO3)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO4)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO5)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO6)))->SetReadOnly(TRUE);


		((CEdit *)(this->GetDlgItem(IDC_EDIT_E1)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_E2)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_E3)))->SetReadOnly(FALSE);
		break;
	case 2:

		// external field
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO1)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO2)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO3)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO4)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO5)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_EO6)))->SetReadOnly(FALSE);


		((CEdit *)(this->GetDlgItem(IDC_EDIT_E1)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_E2)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_E3)))->SetReadOnly(FALSE);
		break;
	default:
		break;
	}
	return TRUE;
}