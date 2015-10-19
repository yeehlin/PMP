// ElectricModelingDLGPiezoelectric.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "ElectricModelingDLGPiezoelectric.h"
#include "afxdialogex.h"


// ElectricModelingDLGPiezoelectric dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGPiezoelectric, CDialog)

ElectricModelingDLGPiezoelectric::ElectricModelingDLGPiezoelectric(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGPiezoelectric::IDD, pParent)
{
	m_edit_c11 = 0.0f;
	m_edit_c12 = 0.0f;
	m_edit_c13 = 0.0f;
	m_edit_c14 = 0.0f;
	m_edit_c15 = 0.0f;
	m_edit_c16 = 0.0f;
	m_edit_c21 = 0.0f;
	m_edit_c22 = 0.0f;
	m_edit_c23 = 0.0f;
	m_edit_c24 = 0.0f;
	m_edit_c25 = 0.0f;
	m_edit_c26 = 0.0f;
	m_edit_c31 = 0.0f;
	m_edit_c32 = 0.0f;
	m_edit_c33 = 0.0f;
	m_edit_c34 = 0.0f;
	m_edit_c35 = 0.0f;
	m_edit_c36 = 0.0f;
	m_edit_c41 = 0.0f;
	m_edit_c42 = 0.0f;
	m_edit_c43 = 0.0f;
	m_edit_c44 = 0.0f;
	m_edit_c45 = 0.0f;
	m_edit_c46 = 0.0f;
	m_edit_c51 = 0.0f;
	m_edit_c52 = 0.0f;
	m_edit_c53 = 0.0f;
	m_edit_c54 = 0.0f;
	m_edit_c55 = 0.0f;
	m_edit_c56 = 0.0f;
	m_edit_c61 = 0.0f;
	m_edit_c62 = 0.0f;
	m_edit_c63 = 0.0f;
	m_edit_c65 = 0.0f;
	m_edit_c64 = 0.0f;
	m_edit_c65 = 0.0f;
	m_edit_c66 = 0.0f;
	m_edit_d11 = 0.0f;
	m_edit_d12 = 0.0f;
	m_edit_d13 = 0.0f;
	m_edit_d14 = 0.0f;
	m_edit_d15 = 0.0f;
	m_edit_d16 = 0.0f;
	m_edit_d21 = 0.0f;
	m_edit_d22 = 0.0f;
	m_edit_d23 = 0.0f;
	m_edit_d24 = 0.0f;
	m_edit_d25 = 0.0f;
	m_edit_d26 = 0.0f;
	m_edit_d31 = 0.0f;
	m_edit_d32 = 0.0f;
	m_edit_d33 = 0.0f;
	m_edit_d34 = 0.0f;
	m_edit_d35 = 0.0f;
	m_edit_d36 = 0.0f;
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

ElectricModelingDLGPiezoelectric::~ElectricModelingDLGPiezoelectric()
{
}

void ElectricModelingDLGPiezoelectric::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PIEZO_PROPERTIS_PH_NOX, m_StaticPiezoPropertiesPHNox);
	DDX_Text(pDX, IDC_EDIT_C11, m_edit_c11);
	DDX_Text(pDX, IDC_EDIT_C12, m_edit_c12);
	DDX_Text(pDX, IDC_EDIT_C13, m_edit_c13);
	DDX_Text(pDX, IDC_EDIT_C14, m_edit_c14);
	DDX_Text(pDX, IDC_EDIT_C15, m_edit_c15);
	DDX_Text(pDX, IDC_EDIT_C16, m_edit_c16);
	DDX_Text(pDX, IDC_EDIT_C21, m_edit_c21);
	DDX_Text(pDX, IDC_EDIT_C22, m_edit_c22);
	DDX_Text(pDX, IDC_EDIT_C23, m_edit_c23);
	DDX_Text(pDX, IDC_EDIT_C24, m_edit_c24);
	DDX_Text(pDX, IDC_EDIT_C25, m_edit_c25);
	DDX_Text(pDX, IDC_EDIT_C26, m_edit_c26);
	DDX_Text(pDX, IDC_EDIT_C31, m_edit_c31);
	DDX_Text(pDX, IDC_EDIT_C32, m_edit_c32);
	DDX_Text(pDX, IDC_EDIT_C33, m_edit_c33);
	DDX_Text(pDX, IDC_EDIT_C34, m_edit_c34);
	DDX_Text(pDX, IDC_EDIT_C35, m_edit_c35);
	DDX_Text(pDX, IDC_EDIT_C36, m_edit_c36);
	DDX_Text(pDX, IDC_EDIT_C41, m_edit_c41);
	DDX_Text(pDX, IDC_EDIT_C42, m_edit_c42);
	DDX_Text(pDX, IDC_EDIT_C43, m_edit_c43);
	DDX_Text(pDX, IDC_EDIT_C44, m_edit_c44);
	DDX_Text(pDX, IDC_EDIT_C45, m_edit_c45);
	DDX_Text(pDX, IDC_EDIT_C46, m_edit_c46);
	DDX_Text(pDX, IDC_EDIT_C51, m_edit_c51);
	DDX_Text(pDX, IDC_EDIT_C52, m_edit_c52);
	DDX_Text(pDX, IDC_EDIT_C53, m_edit_c53);
	DDX_Text(pDX, IDC_EDIT_C54, m_edit_c54);
	DDX_Text(pDX, IDC_EDIT_C55, m_edit_c55);
	DDX_Text(pDX, IDC_EDIT_C56, m_edit_c56);
	DDX_Text(pDX, IDC_EDIT_C61, m_edit_c61);
	DDX_Text(pDX, IDC_EDIT_C62, m_edit_c62);
	DDX_Text(pDX, IDC_EDIT_C63, m_edit_c63);
	DDX_Text(pDX, IDC_EDIT_C64, m_edit_c65);
	DDX_Text(pDX, IDC_EDIT_C64, m_edit_c64);
	DDX_Text(pDX, IDC_EDIT_C65, m_edit_c65);
	DDX_Text(pDX, IDC_EDIT_C66, m_edit_c66);
	DDX_Text(pDX, IDC_EDIT_D11, m_edit_d11);
	DDX_Text(pDX, IDC_EDIT_D12, m_edit_d12);
	DDX_Text(pDX, IDC_EDIT_D13, m_edit_d13);
	DDX_Text(pDX, IDC_EDIT_D14, m_edit_d14);
	DDX_Text(pDX, IDC_EDIT_D15, m_edit_d15);
	DDX_Text(pDX, IDC_EDIT_D16, m_edit_d16);
	DDX_Text(pDX, IDC_EDIT_D21, m_edit_d21);
	DDX_Text(pDX, IDC_EDIT_D22, m_edit_d22);
	DDX_Text(pDX, IDC_EDIT_D23, m_edit_d23);
	DDX_Text(pDX, IDC_EDIT_D24, m_edit_d24);
	DDX_Text(pDX, IDC_EDIT_D25, m_edit_d25);
	DDX_Text(pDX, IDC_EDIT_D26, m_edit_d26);
	DDX_Text(pDX, IDC_EDIT_D31, m_edit_d31);
	DDX_Text(pDX, IDC_EDIT_D32, m_edit_d32);
	DDX_Text(pDX, IDC_EDIT_D33, m_edit_d33);
	DDX_Text(pDX, IDC_EDIT_D34, m_edit_d34);
	DDX_Text(pDX, IDC_EDIT_D35, m_edit_d35);
	DDX_Text(pDX, IDC_EDIT_D36, m_edit_d36);
	DDX_Text(pDX, IDC_EDIT_K11, m_edit_k11);
	DDX_Text(pDX, IDC_EDIT_K12, m_edit_k12);
	DDX_Text(pDX, IDC_EDIT_K13, m_edit_k13);
	DDX_Text(pDX, IDC_EDIT_K21, m_edit_k21);
	DDX_Text(pDX, IDC_EDIT_K22, m_edit_k22);
	DDX_Text(pDX, IDC_EDIT_K23, m_edit_k23);
	DDX_Text(pDX, IDC_EDIT_K31, m_edit_k31);
	DDX_Text(pDX, IDC_EDIT_K32, m_edit_k32);
	DDX_Text(pDX, IDC_EDIT_K33, m_edit_k33);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGPiezoelectric, CDialog)
	ON_EN_CHANGE(IDC_EDIT_C12, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC12)
	ON_EN_CHANGE(IDC_EDIT_C13, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC13)
	ON_EN_CHANGE(IDC_EDIT_C14, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC14)
	ON_EN_CHANGE(IDC_EDIT_C15, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC15)
	ON_EN_CHANGE(IDC_EDIT_C16, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC16)
	ON_EN_CHANGE(IDC_EDIT_C23, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC23)
	ON_EN_CHANGE(IDC_EDIT_C24, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC24)
	ON_EN_CHANGE(IDC_EDIT_C25, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC25)
	ON_EN_CHANGE(IDC_EDIT_C26, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC26)
	ON_EN_CHANGE(IDC_EDIT_C34, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC34)
	ON_EN_CHANGE(IDC_EDIT_C35, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC35)
	ON_EN_CHANGE(IDC_EDIT_C36, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC36)
	ON_EN_CHANGE(IDC_EDIT_C45, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC45)
	ON_EN_CHANGE(IDC_EDIT_C46, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC46)
	ON_EN_CHANGE(IDC_EDIT_C56, &ElectricModelingDLGPiezoelectric::OnEnChangeEditC56)
	ON_EN_CHANGE(IDC_EDIT_K12, &ElectricModelingDLGPiezoelectric::OnEnChangeEditK12)
	ON_EN_CHANGE(IDC_EDIT_K13, &ElectricModelingDLGPiezoelectric::OnEnChangeEditK13)
	ON_EN_CHANGE(IDC_EDIT_K23, &ElectricModelingDLGPiezoelectric::OnEnChangeEditK23)
END_MESSAGE_MAP()


// ElectricModelingDLGPiezoelectric message handlers


BOOL ElectricModelingDLGPiezoelectric::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here



	// 由于对话框中的矩阵是对称矩阵，故初始状态设置下半部分为只读，通过填写山部分自动填入下半部分
	// 设置C值矩阵的初始状态为：下半部分只读
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_C31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C32)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_C41)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C42)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C43)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_C51)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C52)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C53)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C54)))->SetReadOnly(TRUE);


	((CEdit *)(this->GetDlgItem(IDC_EDIT_C61)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C62)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C63)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C64)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_C65)))->SetReadOnly(TRUE);

	// 设置K值矩阵的初始状态为：下半部分为只读
	((CEdit *)(this->GetDlgItem(IDC_EDIT_K21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_K31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_K32)))->SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	// 编辑C12时自动填充C21
	CString str;
	GetDlgItemText(IDC_EDIT_C12,str);
	SetDlgItemText(IDC_EDIT_C21,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C13,str);
	SetDlgItemText(IDC_EDIT_C31,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC14()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C14,str);
	SetDlgItemText(IDC_EDIT_C41,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC15()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C15,str);
	SetDlgItemText(IDC_EDIT_C51,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC16()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C16,str);
	SetDlgItemText(IDC_EDIT_C61,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC23()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C23,str);
	SetDlgItemText(IDC_EDIT_C32,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC24()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C24,str);
	SetDlgItemText(IDC_EDIT_C42,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC25()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C25,str);
	SetDlgItemText(IDC_EDIT_C52,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC26()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C26,str);
	SetDlgItemText(IDC_EDIT_C62,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC34()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C34,str);
	SetDlgItemText(IDC_EDIT_C43,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC35()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C35,str);
	SetDlgItemText(IDC_EDIT_C53,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC36()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C36,str);
	SetDlgItemText(IDC_EDIT_C63,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC45()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C45,str);
	SetDlgItemText(IDC_EDIT_C54,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC46()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C46,str);
	SetDlgItemText(IDC_EDIT_C64,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditC56()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_C56,str);
	SetDlgItemText(IDC_EDIT_C65,str);
}


void ElectricModelingDLGPiezoelectric::OnEnChangeEditK12()
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


void ElectricModelingDLGPiezoelectric::OnEnChangeEditK13()
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


void ElectricModelingDLGPiezoelectric::OnEnChangeEditK23()
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