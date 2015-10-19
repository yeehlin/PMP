// ElectricModelingDLGDielectric.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ElectricModelingDLGDielectric.h"
#include "afxdialogex.h"


// ElectricModelingDLGDielectric dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGDielectric, CDialog)

ElectricModelingDLGDielectric::ElectricModelingDLGDielectric(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGDielectric::IDD, pParent)
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
	// 填充k矩阵
	k[0][0] = &m_edit_k11;k[0][1] = &m_edit_k12;k[0][2] = &m_edit_k13;
	k[1][0] = &m_edit_k21;k[1][1] = &m_edit_k22;k[1][2] = &m_edit_k23;
	k[2][0] = &m_edit_k31;k[2][1] = &m_edit_k32;k[2][2] = &m_edit_k33;

}

ElectricModelingDLGDielectric::~ElectricModelingDLGDielectric()
{
}

void ElectricModelingDLGDielectric::DoDataExchange(CDataExchange* pDX)
{
	// 载入共享数据
	LoadSharedData();
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


BEGIN_MESSAGE_MAP(ElectricModelingDLGDielectric, CDialog)
	ON_EN_CHANGE(IDC_EDIT_K12, &ElectricModelingDLGDielectric::OnEnChangeEditK12)
	ON_EN_CHANGE(IDC_EDIT_K13, &ElectricModelingDLGDielectric::OnEnChangeEditK13)
	ON_EN_CHANGE(IDC_EDIT_K23, &ElectricModelingDLGDielectric::OnEnChangeEditK23)
//	ON_BN_CLICKED(IDOK, &ElectricModelingDLGDielectric::OnBnClickedOk)
END_MESSAGE_MAP()


// ElectricModelingDLGDielectric message handlers


BOOL ElectricModelingDLGDielectric::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here


	// 由于对话框中的矩阵是对称矩阵，故初始状态设置下半部分为只读，通过填写山部分自动填入下半部分
	// 设置K值矩阵的初始状态为：下半部分为只读
	((CEdit *)(this->GetDlgItem(IDC_EDIT_K21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_K31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_K32)))->SetReadOnly(TRUE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void ElectricModelingDLGDielectric::OnEnChangeEditK12()
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


void ElectricModelingDLGDielectric::OnEnChangeEditK13()
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


void ElectricModelingDLGDielectric::OnEnChangeEditK23()
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

//void ElectricModelingDLGDielectric::OnBnClickedOk()
//{
//	// TODO: Add your control notification handler code here
//
//	CDialog::OnOK();
//}

void ElectricModelingDLGDielectric::LoadSharedData(){
	// 载入共享数据
	// 载入k矩阵
	for (int m=0;m<3;m++)
	{
		for (int n=0;n<3;n++)
		{
			*(k[m][n]) = *((float *)kkk +m*3+n);
		}
	}
}