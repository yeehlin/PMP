// ElectricModelingDLGPiezomagnetic.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "ElectricModelingDLGPiezomagnetic.h"
#include "afxdialogex.h"


// ElectricModelingDLGPiezomagnetic dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGPiezomagnetic, CDialog)

ElectricModelingDLGPiezomagnetic::ElectricModelingDLGPiezomagnetic(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGPiezomagnetic::IDD, pParent)
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
	m_edit_u11 = 0.0f;
	m_edit_u12 = 0.0f;
	m_edit_u13 = 0.0f;
	m_edit_u21 = 0.0f;
	m_edit_u22 = 0.0f;
	m_edit_u23 = 0.0f;
	m_edit_u31 = 0.0f;
	m_edit_u32 = 0.0f;
	m_edit_u33 = 0.0f;
	m_edit_q11 = 0.0f;
	m_edit_q12 = 0.0f;
	m_edit_q13 = 0.0f;
	m_edit_q14 = 0.0f;
	m_edit_q15 = 0.0f;
	m_edit_q16 = 0.0f;
	m_edit_q21 = 0.0f;
	m_edit_q22 = 0.0f;
	m_edit_q23 = 0.0f;
	m_edit_q24 = 0.0f;
	m_edit_q25 = 0.0f;
	m_edit_q26 = 0.0f;
	m_edit_q31 = 0.0f;
	m_edit_q32 = 0.0f;
	m_edit_q33 = 0.0f;
	m_edit_q34 = 0.0f;
	m_edit_q35 = 0.0f;
	m_edit_q36 = 0.0f;

}

ElectricModelingDLGPiezomagnetic::~ElectricModelingDLGPiezomagnetic()
{
}

void ElectricModelingDLGPiezomagnetic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

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
	DDX_Text(pDX, IDC_EDIT_U11, m_edit_u11);
	DDX_Text(pDX, IDC_EDIT_U12, m_edit_u12);
	DDX_Text(pDX, IDC_EDIT_U13, m_edit_u13);
	DDX_Text(pDX, IDC_EDIT_U21, m_edit_u21);
	DDX_Text(pDX, IDC_EDIT_U22, m_edit_u22);
	DDX_Text(pDX, IDC_EDIT_U23, m_edit_u23);
	DDX_Text(pDX, IDC_EDIT_U31, m_edit_u31);
	DDX_Text(pDX, IDC_EDIT_U32, m_edit_u32);
	DDX_Text(pDX, IDC_EDIT_U33, m_edit_u33);
	DDX_Text(pDX, IDC_EDIT_Q11, m_edit_q11);
	DDX_Text(pDX, IDC_EDIT_Q12, m_edit_q12);
	DDX_Text(pDX, IDC_EDIT_Q13, m_edit_q13);
	DDX_Text(pDX, IDC_EDIT_Q14, m_edit_q14);
	DDX_Text(pDX, IDC_EDIT_Q15, m_edit_q15);
	DDX_Text(pDX, IDC_EDIT_Q16, m_edit_q16);
	DDX_Text(pDX, IDC_EDIT_Q21, m_edit_q21);
	DDX_Text(pDX, IDC_EDIT_Q22, m_edit_q22);
	DDX_Text(pDX, IDC_EDIT_Q23, m_edit_q23);
	DDX_Text(pDX, IDC_EDIT_Q24, m_edit_q24);
	DDX_Text(pDX, IDC_EDIT_Q25, m_edit_q25);
	DDX_Text(pDX, IDC_EDIT_Q26, m_edit_q26);
	DDX_Text(pDX, IDC_EDIT_Q31, m_edit_q31);
	DDX_Text(pDX, IDC_EDIT_Q32, m_edit_q32);
	DDX_Text(pDX, IDC_EDIT_Q33, m_edit_q33);
	DDX_Text(pDX, IDC_EDIT_Q34, m_edit_q34);
	DDX_Text(pDX, IDC_EDIT_Q35, m_edit_q35);
	DDX_Text(pDX, IDC_EDIT_Q36, m_edit_q36);
	DDX_Control(pDX, IDC_STATIC_PIEZO_PROPERTIS_PH_NOX, m_StaticPropertiesPHNox);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGPiezomagnetic, CDialog)

	ON_EN_CHANGE(IDC_EDIT_C12, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC12)
	ON_EN_CHANGE(IDC_EDIT_C13, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC13)
	ON_EN_CHANGE(IDC_EDIT_C14, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC14)
	ON_EN_CHANGE(IDC_EDIT_C15, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC15)
	ON_EN_CHANGE(IDC_EDIT_C16, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC16)
	ON_EN_CHANGE(IDC_EDIT_C23, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC23)
	ON_EN_CHANGE(IDC_EDIT_C24, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC24)
	ON_EN_CHANGE(IDC_EDIT_C25, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC25)
	ON_EN_CHANGE(IDC_EDIT_C26, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC26)
	ON_EN_CHANGE(IDC_EDIT_C34, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC34)
	ON_EN_CHANGE(IDC_EDIT_C35, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC35)
	ON_EN_CHANGE(IDC_EDIT_C36, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC36)
	ON_EN_CHANGE(IDC_EDIT_C45, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC45)
	ON_EN_CHANGE(IDC_EDIT_C46, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC46)
	ON_EN_CHANGE(IDC_EDIT_C56, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditC56)
	ON_EN_CHANGE(IDC_EDIT_U12, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditU12)
	ON_EN_CHANGE(IDC_EDIT_U13, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditU13)
	ON_EN_CHANGE(IDC_EDIT_U23, &ElectricModelingDLGPiezomagnetic::OnEnChangeEditU23)
END_MESSAGE_MAP()


// ElectricModelingDLGPiezomagnetic message handlers


BOOL ElectricModelingDLGPiezomagnetic::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	// c对称
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
	// u对称
	((CEdit *)(this->GetDlgItem(IDC_EDIT_U21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_U31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_U32)))->SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC12()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC13()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC14()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC15()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC16()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC23()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC24()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC25()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC26()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC34()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC35()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC36()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC45()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC46()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditC56()
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

void ElectricModelingDLGPiezomagnetic::OnEnChangeEditU12()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditU13()
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


void ElectricModelingDLGPiezomagnetic::OnEnChangeEditU23()
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