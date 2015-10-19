// ElectricModelingDLGMagnetic.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGMagnetic.h"
#include "afxdialogex.h"


// ElectricModelingDLGMagnetic dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMagnetic, CDialog)

ElectricModelingDLGMagnetic::ElectricModelingDLGMagnetic(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMagnetic::IDD, pParent)
{

	m_edit_u11 = 0.0f;
	m_edit_u12 = 0.0f;
	m_edit_u13 = 0.0f;
	m_edit_u21 = 0.0f;
	m_edit_u22 = 0.0f;
	m_edit_u23 = 0.0f;
	m_edit_u31 = 0.0f;
	m_edit_u32 = 0.0f;
	m_edit_u33 = 0.0f;

	// 填充u矩阵
	u[0][0] = &m_edit_u11;u[0][1] = &m_edit_u12;u[0][2] = &m_edit_u13;
	u[1][0] = &m_edit_u21;u[1][1] = &m_edit_u22;u[1][2] = &m_edit_u23;
	u[2][0] = &m_edit_u31;u[2][1] = &m_edit_u32;u[2][2] = &m_edit_u33;
}

ElectricModelingDLGMagnetic::~ElectricModelingDLGMagnetic()
{
}

void ElectricModelingDLGMagnetic::DoDataExchange(CDataExchange* pDX)
{
	// 载入共享数据
	LoadSharedData();
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_U11, m_edit_u11);
	DDX_Text(pDX, IDC_EDIT_U12, m_edit_u12);
	DDX_Text(pDX, IDC_EDIT_U13, m_edit_u13);
	DDX_Text(pDX, IDC_EDIT_U21, m_edit_u21);
	DDX_Text(pDX, IDC_EDIT_U22, m_edit_u22);
	DDX_Text(pDX, IDC_EDIT_U23, m_edit_u23);
	DDX_Text(pDX, IDC_EDIT_U31, m_edit_u31);
	DDX_Text(pDX, IDC_EDIT_U32, m_edit_u32);
	DDX_Text(pDX, IDC_EDIT_U33, m_edit_u33);
	DDX_Control(pDX, IDC_STATIC_PROPERTIES_PH_NOX, m_StaticPropertiesPHNox);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMagnetic, CDialog)
	ON_EN_CHANGE(IDC_EDIT_U12, &ElectricModelingDLGMagnetic::OnEnChangeEditU12)
	ON_EN_CHANGE(IDC_EDIT_U13, &ElectricModelingDLGMagnetic::OnEnChangeEditU13)
	ON_EN_CHANGE(IDC_EDIT_U23, &ElectricModelingDLGMagnetic::OnEnChangeEditU23)
END_MESSAGE_MAP()


// ElectricModelingDLGMagnetic message handlers


BOOL ElectricModelingDLGMagnetic::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	((CEdit *)(this->GetDlgItem(IDC_EDIT_U21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_U31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_U32)))->SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGMagnetic::OnEnChangeEditU12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_U12,str);
	SetDlgItemText(IDC_EDIT_U21,str);
}


void ElectricModelingDLGMagnetic::OnEnChangeEditU13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_U13,str);
	SetDlgItemText(IDC_EDIT_U31,str);
}


void ElectricModelingDLGMagnetic::OnEnChangeEditU23()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_U23,str);
	SetDlgItemText(IDC_EDIT_U32,str);
}
void ElectricModelingDLGMagnetic::LoadSharedData(){
	// 载入共享数据
	// 载入u矩阵
	for (int m=0;m<3;m++)
	{
		for (int n=0;n<3;n++)
		{
			*(u[m][n]) = *((float *)uuu +m*3+n);
		}
	}
}