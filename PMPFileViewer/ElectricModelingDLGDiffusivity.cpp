// ElectricModelingDLGDiffusivity.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "ElectricModelingDLGDiffusivity.h"
#include "afxdialogex.h"


// ElectricModelingDLGDiffusivity dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGDiffusivity, CDialog)

ElectricModelingDLGDiffusivity::ElectricModelingDLGDiffusivity(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGDiffusivity::IDD, pParent)
{

	m_edit_diff11 = 0.0f;
	m_edit_diff12 = 0.0f;
	m_edit_diff13 = 0.0f;
	m_edit_diff21 = 0.0f;
	m_edit_diff22 = 0.0f;
	m_edit_diff23 = 0.0f;
	m_edit_diff31 = 0.0f;
	m_edit_diff32 = 0.0f;
	m_edit_diff33 = 0.0f;

}

ElectricModelingDLGDiffusivity::~ElectricModelingDLGDiffusivity()
{
}

void ElectricModelingDLGDiffusivity::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_DIFF11, m_edit_diff11);
	DDX_Text(pDX, IDC_EDIT_DIFF12, m_edit_diff12);
	DDX_Text(pDX, IDC_EDIT_DIFF13, m_edit_diff13);
	DDX_Text(pDX, IDC_EDIT_DIFF21, m_edit_diff21);
	DDX_Text(pDX, IDC_EDIT_DIFF22, m_edit_diff22);
	DDX_Text(pDX, IDC_EDIT_DIFF23, m_edit_diff23);
	DDX_Text(pDX, IDC_EDIT_DIFF31, m_edit_diff31);
	DDX_Text(pDX, IDC_EDIT_DIFF32, m_edit_diff32);
	DDX_Text(pDX, IDC_EDIT_DIFF33, m_edit_diff33);
	DDX_Control(pDX, IDC_STATIC_PROPERTIES_PH_NOX, m_StaticPropertiesPHNox);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGDiffusivity, CDialog)
	ON_EN_CHANGE(IDC_EDIT_K12, &ElectricModelingDLGDiffusivity::OnEnChangeEditDiff12)
	ON_EN_CHANGE(IDC_EDIT_K13, &ElectricModelingDLGDiffusivity::OnEnChangeEditDiff13)
	ON_EN_CHANGE(IDC_EDIT_K23, &ElectricModelingDLGDiffusivity::OnEnChangeEditDiff23)
END_MESSAGE_MAP()


// ElectricModelingDLGDiffusivity message handlers


BOOL ElectricModelingDLGDiffusivity::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	((CEdit *)(this->GetDlgItem(IDC_EDIT_DIFF21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_DIFF31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_DIFF32)))->SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGDiffusivity::OnEnChangeEditDiff12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_DIFF12,str);
	SetDlgItemText(IDC_EDIT_DIFF21,str);
}


void ElectricModelingDLGDiffusivity::OnEnChangeEditDiff13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_DIFF13,str);
	SetDlgItemText(IDC_EDIT_DIFF31,str);
}


void ElectricModelingDLGDiffusivity::OnEnChangeEditDiff23()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_DIFF23,str);
	SetDlgItemText(IDC_EDIT_DIFF32,str);
}