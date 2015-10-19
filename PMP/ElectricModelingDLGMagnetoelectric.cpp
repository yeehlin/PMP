// ElectricModelingDLGMagnetoelectric.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ElectricModelingDLGMagnetoelectric.h"
#include "afxdialogex.h"


// ElectricModelingDLGMagnetoelectric dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMagnetoelectric, CDialog)

ElectricModelingDLGMagnetoelectric::ElectricModelingDLGMagnetoelectric(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMagnetoelectric::IDD, pParent)
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
	m_edit_k11 = 0.0f;
	m_edit_k12 = 0.0f;
	m_edit_k13 = 0.0f;
	m_edit_k21 = 0.0f;
	m_edit_k22 = 0.0f;
	m_edit_k23 = 0.0f;
	m_edit_k31 = 0.0f;
	m_edit_k32 = 0.0f;
	m_edit_k33 = 0.0f;
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
	m_edit_a11 = 0.0f;
	m_edit_a12 = 0.0f;
	m_edit_a13 = 0.0f;
	m_edit_a21 = 0.0f;
	m_edit_a22 = 0.0f;
	m_edit_a23 = 0.0f;
	m_edit_a31 = 0.0f;
	m_edit_a32 = 0.0f;
	m_edit_a33 = 0.0f;

	// ÃÓ≥‰cæÿ’Û
	c[0][0] = &m_edit_c11;c[0][1] = &m_edit_c12;c[0][2] = &m_edit_c13;c[0][3] = &m_edit_c14;c[0][4] = &m_edit_c15;c[0][5] = &m_edit_c16;
	c[1][0] = &m_edit_c21;c[1][1] = &m_edit_c22;c[1][2] = &m_edit_c23;c[1][3] = &m_edit_c24;c[1][4] = &m_edit_c25;c[1][5] = &m_edit_c26;
	c[2][0] = &m_edit_c31;c[2][1] = &m_edit_c32;c[2][2] = &m_edit_c33;c[2][3] = &m_edit_c34;c[2][4] = &m_edit_c35;c[2][5] = &m_edit_c36;
	c[3][0] = &m_edit_c41;c[3][1] = &m_edit_c42;c[3][2] = &m_edit_c43;c[3][3] = &m_edit_c44;c[3][4] = &m_edit_c45;c[3][5] = &m_edit_c46;
	c[4][0] = &m_edit_c51;c[4][1] = &m_edit_c52;c[4][2] = &m_edit_c53;c[4][3] = &m_edit_c54;c[4][4] = &m_edit_c55;c[4][5] = &m_edit_c56;
	c[5][0] = &m_edit_c61;c[5][1] = &m_edit_c62;c[5][2] = &m_edit_c63;c[5][3] = &m_edit_c64;c[5][4] = &m_edit_c65;c[5][5] = &m_edit_c66;
	// ÃÓ≥‰kæÿ’Û
	k[0][0] = &m_edit_k11;k[0][1] = &m_edit_k12;k[0][2] = &m_edit_k13;
	k[1][0] = &m_edit_k21;k[1][1] = &m_edit_k22;k[1][2] = &m_edit_k23;
	k[2][0] = &m_edit_k31;k[2][1] = &m_edit_k32;k[2][2] = &m_edit_k33;
	// ÃÓ≥‰dæÿ’Û
	d[0][0] = &m_edit_d11;d[0][1] = &m_edit_d12;d[0][2] = &m_edit_d13;d[0][3] = &m_edit_d14;d[0][4] = &m_edit_d15;d[0][5] = &m_edit_d16;
	d[1][0] = &m_edit_d21;d[1][1] = &m_edit_d22;d[1][2] = &m_edit_d23;d[1][3] = &m_edit_d24;d[1][4] = &m_edit_d25;d[1][5] = &m_edit_d26;
	d[2][0] = &m_edit_d31;d[2][1] = &m_edit_d32;d[2][2] = &m_edit_d33;d[2][3] = &m_edit_d34;d[2][4] = &m_edit_d35;d[2][5] = &m_edit_d36;
	// ÃÓ≥‰uæÿ’Û
	u[0][0] = &m_edit_u11;u[0][1] = &m_edit_u12;u[0][2] = &m_edit_u13;
	u[1][0] = &m_edit_u21;u[1][1] = &m_edit_u22;u[1][2] = &m_edit_u23;
	u[2][0] = &m_edit_u31;u[2][1] = &m_edit_u32;u[2][2] = &m_edit_u33;
	// ÃÓ≥‰qæÿ’Û
	q[0][0] = &m_edit_q11;q[0][1] = &m_edit_q12;q[0][2] = &m_edit_q13;q[0][3] = &m_edit_q14;q[0][4] = &m_edit_q15;q[0][5] = &m_edit_q16;
	q[1][0] = &m_edit_q21;q[1][1] = &m_edit_q22;q[1][2] = &m_edit_q23;q[1][3] = &m_edit_q24;q[1][4] = &m_edit_q25;q[1][5] = &m_edit_q26;
	q[2][0] = &m_edit_q31;q[2][1] = &m_edit_q32;q[2][2] = &m_edit_q33;q[2][3] = &m_edit_q34;q[2][4] = &m_edit_q35;q[2][5] = &m_edit_q36;
	// ÃÓ≥‰aæÿ’Û
	a[0][0] = &m_edit_a11;a[0][1] = &m_edit_a12;a[0][2] = &m_edit_a13;
	a[1][0] = &m_edit_a21;a[1][1] = &m_edit_a22;a[1][2] = &m_edit_a23;
	a[2][0] = &m_edit_a31;a[2][1] = &m_edit_a32;a[2][2] = &m_edit_a33;

}

ElectricModelingDLGMagnetoelectric::~ElectricModelingDLGMagnetoelectric()
{
}

void ElectricModelingDLGMagnetoelectric::DoDataExchange(CDataExchange* pDX)
{
	// ‘ÿ»Îπ≤œÌ ˝æ›
	LoadSharedData();
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
	DDX_Text(pDX, IDC_EDIT_K11, m_edit_k11);
	DDX_Text(pDX, IDC_EDIT_K12, m_edit_k12);
	DDX_Text(pDX, IDC_EDIT_K13, m_edit_k13);
	DDX_Text(pDX, IDC_EDIT_K21, m_edit_k21);
	DDX_Text(pDX, IDC_EDIT_K22, m_edit_k22);
	DDX_Text(pDX, IDC_EDIT_K23, m_edit_k23);
	DDX_Text(pDX, IDC_EDIT_K31, m_edit_k31);
	DDX_Text(pDX, IDC_EDIT_K32, m_edit_k32);
	DDX_Text(pDX, IDC_EDIT_K33, m_edit_k33);
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
	DDX_Text(pDX, IDC_EDIT_A11, m_edit_a11);
	DDX_Text(pDX, IDC_EDIT_A12, m_edit_a12);
	DDX_Text(pDX, IDC_EDIT_A13, m_edit_a13);
	DDX_Text(pDX, IDC_EDIT_A21, m_edit_a21);
	DDX_Text(pDX, IDC_EDIT_A22, m_edit_a22);
	DDX_Text(pDX, IDC_EDIT_A23, m_edit_a23);
	DDX_Text(pDX, IDC_EDIT_A31, m_edit_a31);
	DDX_Text(pDX, IDC_EDIT_A32, m_edit_a32);
	DDX_Text(pDX, IDC_EDIT_A33, m_edit_a33);

	DDX_Control(pDX, IDC_STATIC_PIEZO_PROPERTIS_PH_NOX, m_StaticPropertiesPHNox);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMagnetoelectric, CDialog)
	ON_EN_CHANGE(IDC_EDIT_C12, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC12)
	ON_EN_CHANGE(IDC_EDIT_C13, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC13)
	ON_EN_CHANGE(IDC_EDIT_C14, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC14)
	ON_EN_CHANGE(IDC_EDIT_C15, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC15)
	ON_EN_CHANGE(IDC_EDIT_C16, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC16)
	ON_EN_CHANGE(IDC_EDIT_C23, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC23)
	ON_EN_CHANGE(IDC_EDIT_C24, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC24)
	ON_EN_CHANGE(IDC_EDIT_C25, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC25)
	ON_EN_CHANGE(IDC_EDIT_C26, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC26)
	ON_EN_CHANGE(IDC_EDIT_C34, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC34)
	ON_EN_CHANGE(IDC_EDIT_C35, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC35)
	ON_EN_CHANGE(IDC_EDIT_C36, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC36)
	ON_EN_CHANGE(IDC_EDIT_C45, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC45)
	ON_EN_CHANGE(IDC_EDIT_C46, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC46)
	ON_EN_CHANGE(IDC_EDIT_C56, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditC56)
	ON_EN_CHANGE(IDC_EDIT_K12, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditK12)
	ON_EN_CHANGE(IDC_EDIT_K13, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditK13)
	ON_EN_CHANGE(IDC_EDIT_K23, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditK23)
	ON_EN_CHANGE(IDC_EDIT_U12, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditU12)
	ON_EN_CHANGE(IDC_EDIT_U13, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditU13)
	ON_EN_CHANGE(IDC_EDIT_U23, &ElectricModelingDLGMagnetoelectric::OnEnChangeEditU23)
END_MESSAGE_MAP()


// ElectricModelingDLGMagnetoelectric message handlers


BOOL ElectricModelingDLGMagnetoelectric::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	// c∂‘≥∆
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
	// k∂‘≥∆
	((CEdit *)(this->GetDlgItem(IDC_EDIT_K21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_K31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_K32)))->SetReadOnly(TRUE);
	// u∂‘≥∆
	((CEdit *)(this->GetDlgItem(IDC_EDIT_U21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_U31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_U32)))->SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	// ±‡º≠C12 ±◊‘∂ØÃÓ≥‰C21
	CString str;
	GetDlgItemText(IDC_EDIT_C12,str);
	SetDlgItemText(IDC_EDIT_C21,str);
}


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC13()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC14()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC15()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC16()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC23()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC24()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC25()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC26()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC34()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC35()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC36()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC45()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC46()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditC56()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditK12()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditK13()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditK23()
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

void ElectricModelingDLGMagnetoelectric::OnEnChangeEditU12()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditU13()
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


void ElectricModelingDLGMagnetoelectric::OnEnChangeEditU23()
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

void ElectricModelingDLGMagnetoelectric::LoadSharedData(){
	// ‘ÿ»Îπ≤œÌ ˝æ›
	// ‘ÿ»Îcæÿ’Û
	for (int m=0;m<6;m++)
	{
		for (int n=0;n<6;n++)
		{
			*(c[m][n]) = *((float *)ccc +m*6+n);
		}
	}
	// ‘ÿ»Îkæÿ’Û
	for (int m=0;m<3;m++)
	{
		for (int n=0;n<3;n++)
		{
			*(k[m][n]) = *((float *)kkk +m*3+n);
		}
	}
	// ‘ÿ»Îdæÿ’Û
	for (int m=0;m<3;m++)
	{
		for (int n=0;n<6;n++)
		{
			*(d[m][n]) = *((float *)ddd +m*6+n);
		}
	}
	// ‘ÿ»Îuæÿ’Û
	for (int m=0;m<3;m++)
	{
		for (int n=0;n<3;n++)
		{
			*(u[m][n]) = *((float *)uuu +m*3+n);
		}
	}
	// ‘ÿ»Îqæÿ’Û
	for (int m=0;m<3;m++)
	{
		for (int n=0;n<6;n++)
		{
			*(q[m][n]) = *((float *)qqq +m*6+n);
		}
	}
	// ‘ÿ»Îaæÿ’Û
	for (int m=0;m<3;m++)
	{
		for (int n=0;n<3;n++)
		{
			*(a[m][n]) = *((float *)aaa +m*3+n);
		}
	}
}