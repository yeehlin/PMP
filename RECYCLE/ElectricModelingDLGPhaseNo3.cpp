// ElectricModelingDLGPhaseNo3.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGPhaseNo3.h"
#include "afxdialogex.h"


// ElectricModelingDLGPhaseNo3 dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGPhaseNo3, CDialog)

ElectricModelingDLGPhaseNo3::ElectricModelingDLGPhaseNo3(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGPhaseNo3::IDD, pParent)
{
	m_edit_phase_no3_c11 = 0.0f;
	m_edit_phase_no3_c12 = 0.0f;
	m_edit_phase_no3_c13 = 0.0f;
	m_edit_phase_no3_c14 = 0.0f;
	m_edit_phase_no3_c15 = 0.0f;
	m_edit_phase_no3_c16 = 0.0f;
	m_edit_phase_no3_c21 = 0.0f;
	m_edit_phase_no3_c22 = 0.0f;
	m_edit_phase_no3_c23 = 0.0f;
	m_edit_phase_no3_c24 = 0.0f;
	m_edit_phase_no3_c25 = 0.0f;
	m_edit_phase_no3_c26 = 0.0f;
	m_edit_phase_no3_c31 = 0.0f;
	m_edit_phase_no3_c32 = 0.0f;
	m_edit_phase_no3_c33 = 0.0f;
	m_edit_phase_no3_c34 = 0.0f;
	m_edit_phase_no3_c35 = 0.0f;
	m_edit_phase_no3_c36 = 0.0f;
	m_edit_phase_no3_c41 = 0.0f;
	m_edit_phase_no3_c42 = 0.0f;
	m_edit_phase_no3_c43 = 0.0f;
	m_edit_phase_no3_c44 = 0.0f;
	m_edit_phase_no3_c45 = 0.0f;
	m_edit_phase_no3_c46 = 0.0f;
	m_edit_phase_no3_c51 = 0.0f;
	m_edit_phase_no3_c52 = 0.0f;
	m_edit_phase_no3_c53 = 0.0f;
	m_edit_phase_no3_c54 = 0.0f;
	m_edit_phase_no3_c55 = 0.0f;
	m_edit_phase_no3_c56 = 0.0f;
	m_edit_phase_no3_c61 = 0.0f;
	m_edit_phase_no3_c62 = 0.0f;
	m_edit_phase_no3_c63 = 0.0f;
	m_edit_phase_no3_c65 = 0.0f;
	m_edit_phase_no3_c64 = 0.0f;
	m_edit_phase_no3_c65 = 0.0f;
	m_edit_phase_no3_c66 = 0.0f;
	m_edit_phase_no3_d11 = 0.0f;
	m_edit_phase_no3_d12 = 0.0f;
	m_edit_phase_no3_d13 = 0.0f;
	m_edit_phase_no3_d14 = 0.0f;
	m_edit_phase_no3_d15 = 0.0f;
	m_edit_phase_no3_d16 = 0.0f;
	m_edit_phase_no3_d21 = 0.0f;
	m_edit_phase_no3_d22 = 0.0f;
	m_edit_phase_no3_d23 = 0.0f;
	m_edit_phase_no3_d24 = 0.0f;
	m_edit_phase_no3_d25 = 0.0f;
	m_edit_phase_no3_d26 = 0.0f;
	m_edit_phase_no3_d31 = 0.0f;
	m_edit_phase_no3_d32 = 0.0f;
	m_edit_phase_no3_d33 = 0.0f;
	m_edit_phase_no3_d34 = 0.0f;
	m_edit_phase_no3_d35 = 0.0f;
	m_edit_phase_no3_d36 = 0.0f;
	m_edit_phase_no3_k11 = 0.0f;
	m_edit_phase_no3_k12 = 0.0f;
	m_edit_phase_no3_k13 = 0.0f;
	m_edit_phase_no3_k21 = 0.0f;
	m_edit_phase_no3_k22 = 0.0f;
	m_edit_phase_no3_k23 = 0.0f;
	m_edit_phase_no3_k31 = 0.0f;
	m_edit_phase_no3_k32 = 0.0f;
	m_edit_phase_no3_k33 = 0.0f;
}

ElectricModelingDLGPhaseNo3::~ElectricModelingDLGPhaseNo3()
{
}

void ElectricModelingDLGPhaseNo3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C11, m_edit_phase_no3_c11);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C12, m_edit_phase_no3_c12);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C13, m_edit_phase_no3_c13);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C14, m_edit_phase_no3_c14);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C15, m_edit_phase_no3_c15);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C16, m_edit_phase_no3_c16);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C21, m_edit_phase_no3_c21);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C22, m_edit_phase_no3_c22);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C23, m_edit_phase_no3_c23);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C24, m_edit_phase_no3_c24);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C25, m_edit_phase_no3_c25);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C26, m_edit_phase_no3_c26);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C31, m_edit_phase_no3_c31);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C32, m_edit_phase_no3_c32);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C33, m_edit_phase_no3_c33);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C34, m_edit_phase_no3_c34);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C35, m_edit_phase_no3_c35);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C36, m_edit_phase_no3_c36);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C41, m_edit_phase_no3_c41);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C42, m_edit_phase_no3_c42);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C43, m_edit_phase_no3_c43);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C44, m_edit_phase_no3_c44);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C45, m_edit_phase_no3_c45);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C46, m_edit_phase_no3_c46);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C51, m_edit_phase_no3_c51);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C52, m_edit_phase_no3_c52);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C53, m_edit_phase_no3_c53);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C54, m_edit_phase_no3_c54);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C55, m_edit_phase_no3_c55);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C56, m_edit_phase_no3_c56);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C61, m_edit_phase_no3_c61);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C62, m_edit_phase_no3_c62);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C63, m_edit_phase_no3_c63);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C64, m_edit_phase_no3_c65);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C64, m_edit_phase_no3_c64);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C65, m_edit_phase_no3_c65);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_C66, m_edit_phase_no3_c66);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D11, m_edit_phase_no3_d11);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D12, m_edit_phase_no3_d12);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D13, m_edit_phase_no3_d13);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D14, m_edit_phase_no3_d14);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D15, m_edit_phase_no3_d15);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D16, m_edit_phase_no3_d16);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D21, m_edit_phase_no3_d21);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D22, m_edit_phase_no3_d22);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D23, m_edit_phase_no3_d23);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D24, m_edit_phase_no3_d24);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D25, m_edit_phase_no3_d25);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D26, m_edit_phase_no3_d26);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D31, m_edit_phase_no3_d31);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D32, m_edit_phase_no3_d32);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D33, m_edit_phase_no3_d33);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D34, m_edit_phase_no3_d34);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D35, m_edit_phase_no3_d35);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_D36, m_edit_phase_no3_d36);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_K11, m_edit_phase_no3_k11);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_K12, m_edit_phase_no3_k12);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_K13, m_edit_phase_no3_k13);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_K21, m_edit_phase_no3_k21);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_K22, m_edit_phase_no3_k22);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_K23, m_edit_phase_no3_k23);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_K31, m_edit_phase_no3_k31);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_K32, m_edit_phase_no3_k32);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO3_K33, m_edit_phase_no3_k33);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGPhaseNo3, CDialog)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C12, &ElectricModelingDLGPhaseNo3::OnEnChangeEditPhaseNo3C12)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C13, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C13)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C14, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C14)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C15, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C15)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C16, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C16)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C23, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C23)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C24, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C24)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C25, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C25)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C26, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C26)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C34, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C34)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C35, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C35)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C36, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C36)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C45, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C45)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C46, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C46)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_C56, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C56)
//	ON_COMMAND(IDC_EDIT_PHASE_NO2_K12, &ElectricModelingDLGPhaseNo3::OnEditPhaseNo2K12)
//	ON_COMMAND(IDC_EDIT_PHASE_NO2_K13, &ElectricModelingDLGPhaseNo3::OnEditPhaseNo2K13)
//	ON_COMMAND(IDC_EDIT_PHASE_NO2_K23, &ElectricModelingDLGPhaseNo3::OnEditPhaseNo2K23)
ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_K12, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3K12)
ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_K13, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3K13)
ON_EN_CHANGE(IDC_EDIT_PHASE_NO3_K23, &ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3K23)
END_MESSAGE_MAP()


// ElectricModelingDLGPhaseNo3 message handlers


BOOL ElectricModelingDLGPhaseNo3::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here


	// 由于对话框中的矩阵是对称矩阵，故初始状态设置下半部分为只读，通过填写山部分自动填入下半部分
	// 设置C值矩阵的初始状态为：下半部分只读
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C32)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C41)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C42)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C43)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C51)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C52)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C53)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C54)))->SetReadOnly(TRUE);


	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C61)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C62)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C63)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C64)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C65)))->SetReadOnly(TRUE);

	// 设置K值矩阵的初始状态为：下半部分为只读
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K32)))->SetReadOnly(TRUE);

	// 由于初始状态下：System Type选则elastic，Number of phase为1，故设置如下
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C16)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C26)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C31)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C36)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C41)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C42)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C43)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C44)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C45)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C46)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C51)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C52)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C53)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C54)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C55)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C56)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C61)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C62)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C63)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C64)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C65)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C66)))->SetReadOnly(TRUE);


	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K13)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K23)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K31)))->SetReadOnly(FALSE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K32)))->SetReadOnly(FALSE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K33)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D16)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D26)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D36)))->SetReadOnly(TRUE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
BOOL ElectricModelingDLGPhaseNo3::ResponseSignal(int mysignal){
	switch(mysignal){
	case 0:
		//::MessageBox(NULL,_T("进了phase No.3"),_T("OKOK"),MB_OK);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C13)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C14)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C15)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C16)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C23)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C24)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C25)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C26)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C33)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C34)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C35)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C36)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C41)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C42)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C43)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C44)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C45)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C46)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C51)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C52)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C53)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C54)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C55)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C56)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C61)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C62)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C63)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C64)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C65)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C66)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K13)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K23)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K31)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K33)))->SetReadOnly(TRUE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D13)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D14)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D15)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D16)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D23)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D24)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D25)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D26)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D31)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D33)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D34)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D35)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D36)))->SetReadOnly(TRUE);
		break;
	case 1:
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C13)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C14)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C15)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C16)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C23)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C24)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C25)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C26)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C31)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C33)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C34)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C35)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C36)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C41)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C42)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C43)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C44)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C45)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C46)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C51)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C52)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C53)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C54)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C55)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C56)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C61)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C62)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C63)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C64)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C65)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C66)))->SetReadOnly(TRUE);


		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K13)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K23)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K33)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D13)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D14)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D15)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D16)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D23)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D24)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D25)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D26)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D31)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D33)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D34)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D35)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D36)))->SetReadOnly(TRUE);

		break;
	case 2:
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C13)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C14)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C15)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C16)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C23)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C24)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C25)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C26)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C33)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C34)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C35)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C36)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C41)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C42)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C43)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C44)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C45)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C46)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C51)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C52)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C53)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C54)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C55)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C56)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C61)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C62)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C63)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C64)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C65)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C66)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K13)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K23)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K33)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D13)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D14)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D15)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D16)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D23)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D24)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D25)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D26)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D31)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D33)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D34)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D35)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D36)))->SetReadOnly(FALSE);

		break;
	default:
		break;
	}
	return TRUE;
}

// 设置自己不提供输入服务
void ElectricModelingDLGPhaseNo3::NoInputService(){
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C16)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C26)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C31)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C36)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C41)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C42)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C43)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C44)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C45)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C46)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C51)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C52)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C53)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C54)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C55)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C56)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C61)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C62)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C63)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C64)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C65)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_C66)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K13)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K23)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K31)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_K33)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D16)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D26)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO3_D36)))->SetReadOnly(TRUE);
}

void ElectricModelingDLGPhaseNo3::OnEnChangeEditPhaseNo3C12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C12,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C21,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C13,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C31,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C14()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C14,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C41,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C15()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C15,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C51,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C16()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C16,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C61,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C23()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C23,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C32,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C24()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C24,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C42,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C25()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C25,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C52,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C26()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C26,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C62,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C34()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C34,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C43,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C35()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C35,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C53,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C36()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C36,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C63,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C45()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C45,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C54,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C46()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C46,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C64,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3C56()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_C56,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_C65,str);
}


//void ElectricModelingDLGPhaseNo3::OnEditPhaseNo2K12()
//{
//	// TODO: Add your command handler code here
//}


//void ElectricModelingDLGPhaseNo3::OnEditPhaseNo2K13()
//{
//	// TODO: Add your command handler code here
//}


//void ElectricModelingDLGPhaseNo3::OnEditPhaseNo2K23()
//{
//	// TODO: Add your command handler code here
//}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3K12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_K12,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_K21,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3K13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_K13,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_K31,str);
}


void ElectricModelingDLGPhaseNo3::OnChangeEditPhaseNo3K23()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO3_K23,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO3_K32,str);
}
