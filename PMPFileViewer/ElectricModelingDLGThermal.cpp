// ElectricModelingDLGThermal.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "ElectricModelingDLGThermal.h"
#include "afxdialogex.h"


// ElectricModelingDLGThermal dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGThermal, CDialog)

ElectricModelingDLGThermal::ElectricModelingDLGThermal(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGThermal::IDD, pParent)
{


	m_edit_k11 = 0.0f;
	m_edit_k12 = 0.0f;
	m_edit_k13 = 0.0f;
	m_edit_k21 = 0.0f;
	m_edit_k22 = 0.0f;
	m_edit_k23 = 0.0f;
	m_edit_k31 = 0.0f;
	m_edit_k32 = 0.0f;
	m_edit_k33 = 0.0f;
}

ElectricModelingDLGThermal::~ElectricModelingDLGThermal()
{
}

void ElectricModelingDLGThermal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_K11, m_edit_k11);
	DDX_Text(pDX, IDC_EDIT_K12, m_edit_k12);
	DDX_Text(pDX, IDC_EDIT_K13, m_edit_k13);
	DDX_Text(pDX, IDC_EDIT_K21, m_edit_k21);
	DDX_Text(pDX, IDC_EDIT_K22, m_edit_k22);
	DDX_Text(pDX, IDC_EDIT_K23, m_edit_k23);
	DDX_Text(pDX, IDC_EDIT_K31, m_edit_k31);
	DDX_Text(pDX, IDC_EDIT_K32, m_edit_k32);
	DDX_Text(pDX, IDC_EDIT_K33, m_edit_k33);
	DDX_Control(pDX, IDC_STATIC_PROPERTIES_PH_NOX, m_StaticPropertiesPHNox);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGThermal, CDialog)
	ON_EN_CHANGE(IDC_EDIT_K12, &ElectricModelingDLGThermal::OnEnChangeEditK12)
	ON_EN_CHANGE(IDC_EDIT_K13, &ElectricModelingDLGThermal::OnEnChangeEditK13)
	ON_EN_CHANGE(IDC_EDIT_K23, &ElectricModelingDLGThermal::OnEnChangeEditK23)
END_MESSAGE_MAP()


// ElectricModelingDLGThermal message handlers


BOOL ElectricModelingDLGThermal::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	((CEdit *)(this->GetDlgItem(IDC_EDIT_K21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_K31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_K32)))->SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void ElectricModelingDLGThermal::OnEnChangeEditK12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_K12,str);
	SetDlgItemText(IDC_EDIT_K21,str);
}


void ElectricModelingDLGThermal::OnEnChangeEditK13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_K13,str);
	SetDlgItemText(IDC_EDIT_K31,str);
}


void ElectricModelingDLGThermal::OnEnChangeEditK23()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_K23,str);
	SetDlgItemText(IDC_EDIT_K32,str);
}