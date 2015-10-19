// ElectricModelingDLGPhaseNo4.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGPhaseNo4.h"
#include "afxdialogex.h"


// ElectricModelingDLGPhaseNo4 dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGPhaseNo4, CDialog)

ElectricModelingDLGPhaseNo4::ElectricModelingDLGPhaseNo4(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGPhaseNo4::IDD, pParent)
{
	m_edit_phase_no4_c11 = 0.0f;
	m_edit_phase_no4_c12 = 0.0f;
	m_edit_phase_no4_c13 = 0.0f;
	m_edit_phase_no4_c14 = 0.0f;
	m_edit_phase_no4_c15 = 0.0f;
	m_edit_phase_no4_c16 = 0.0f;
	m_edit_phase_no4_c21 = 0.0f;
	m_edit_phase_no4_c22 = 0.0f;
	m_edit_phase_no4_c23 = 0.0f;
	m_edit_phase_no4_c24 = 0.0f;
	m_edit_phase_no4_c25 = 0.0f;
	m_edit_phase_no4_c26 = 0.0f;
	m_edit_phase_no4_c31 = 0.0f;
	m_edit_phase_no4_c32 = 0.0f;
	m_edit_phase_no4_c33 = 0.0f;
	m_edit_phase_no4_c34 = 0.0f;
	m_edit_phase_no4_c35 = 0.0f;
	m_edit_phase_no4_c36 = 0.0f;
	m_edit_phase_no4_c41 = 0.0f;
	m_edit_phase_no4_c42 = 0.0f;
	m_edit_phase_no4_c43 = 0.0f;
	m_edit_phase_no4_c44 = 0.0f;
	m_edit_phase_no4_c45 = 0.0f;
	m_edit_phase_no4_c46 = 0.0f;
	m_edit_phase_no4_c51 = 0.0f;
	m_edit_phase_no4_c52 = 0.0f;
	m_edit_phase_no4_c53 = 0.0f;
	m_edit_phase_no4_c54 = 0.0f;
	m_edit_phase_no4_c55 = 0.0f;
	m_edit_phase_no4_c56 = 0.0f;
	m_edit_phase_no4_c61 = 0.0f;
	m_edit_phase_no4_c62 = 0.0f;
	m_edit_phase_no4_c63 = 0.0f;
	m_edit_phase_no4_c65 = 0.0f;
	m_edit_phase_no4_c64 = 0.0f;
	m_edit_phase_no4_c65 = 0.0f;
	m_edit_phase_no4_c66 = 0.0f;
	m_edit_phase_no4_d11 = 0.0f;
	m_edit_phase_no4_d12 = 0.0f;
	m_edit_phase_no4_d13 = 0.0f;
	m_edit_phase_no4_d14 = 0.0f;
	m_edit_phase_no4_d15 = 0.0f;
	m_edit_phase_no4_d16 = 0.0f;
	m_edit_phase_no4_d21 = 0.0f;
	m_edit_phase_no4_d22 = 0.0f;
	m_edit_phase_no4_d23 = 0.0f;
	m_edit_phase_no4_d24 = 0.0f;
	m_edit_phase_no4_d25 = 0.0f;
	m_edit_phase_no4_d26 = 0.0f;
	m_edit_phase_no4_d31 = 0.0f;
	m_edit_phase_no4_d32 = 0.0f;
	m_edit_phase_no4_d33 = 0.0f;
	m_edit_phase_no4_d34 = 0.0f;
	m_edit_phase_no4_d35 = 0.0f;
	m_edit_phase_no4_d36 = 0.0f;
	m_edit_phase_no4_k11 = 0.0f;
	m_edit_phase_no4_k12 = 0.0f;
	m_edit_phase_no4_k13 = 0.0f;
	m_edit_phase_no4_k21 = 0.0f;
	m_edit_phase_no4_k22 = 0.0f;
	m_edit_phase_no4_k23 = 0.0f;
	m_edit_phase_no4_k31 = 0.0f;
	m_edit_phase_no4_k32 = 0.0f;
	m_edit_phase_no4_k33 = 0.0f;
}

ElectricModelingDLGPhaseNo4::~ElectricModelingDLGPhaseNo4()
{
}

void ElectricModelingDLGPhaseNo4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C11, m_edit_phase_no4_c11);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C12, m_edit_phase_no4_c12);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C13, m_edit_phase_no4_c13);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C14, m_edit_phase_no4_c14);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C15, m_edit_phase_no4_c15);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C16, m_edit_phase_no4_c16);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C21, m_edit_phase_no4_c21);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C22, m_edit_phase_no4_c22);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C23, m_edit_phase_no4_c23);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C24, m_edit_phase_no4_c24);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C25, m_edit_phase_no4_c25);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C26, m_edit_phase_no4_c26);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C31, m_edit_phase_no4_c31);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C32, m_edit_phase_no4_c32);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C33, m_edit_phase_no4_c33);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C34, m_edit_phase_no4_c34);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C35, m_edit_phase_no4_c35);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C36, m_edit_phase_no4_c36);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C41, m_edit_phase_no4_c41);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C42, m_edit_phase_no4_c42);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C43, m_edit_phase_no4_c43);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C44, m_edit_phase_no4_c44);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C45, m_edit_phase_no4_c45);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C46, m_edit_phase_no4_c46);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C51, m_edit_phase_no4_c51);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C52, m_edit_phase_no4_c52);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C53, m_edit_phase_no4_c53);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C54, m_edit_phase_no4_c54);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C55, m_edit_phase_no4_c55);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C56, m_edit_phase_no4_c56);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C61, m_edit_phase_no4_c61);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C62, m_edit_phase_no4_c62);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C63, m_edit_phase_no4_c63);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C64, m_edit_phase_no4_c65);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C64, m_edit_phase_no4_c64);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C65, m_edit_phase_no4_c65);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_C66, m_edit_phase_no4_c66);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D11, m_edit_phase_no4_d11);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D12, m_edit_phase_no4_d12);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D13, m_edit_phase_no4_d13);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D14, m_edit_phase_no4_d14);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D15, m_edit_phase_no4_d15);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D16, m_edit_phase_no4_d16);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D21, m_edit_phase_no4_d21);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D22, m_edit_phase_no4_d22);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D23, m_edit_phase_no4_d23);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D24, m_edit_phase_no4_d24);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D25, m_edit_phase_no4_d25);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D26, m_edit_phase_no4_d26);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D31, m_edit_phase_no4_d31);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D32, m_edit_phase_no4_d32);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D33, m_edit_phase_no4_d33);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D34, m_edit_phase_no4_d34);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D35, m_edit_phase_no4_d35);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_D36, m_edit_phase_no4_d36);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_K11, m_edit_phase_no4_k11);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_K12, m_edit_phase_no4_k12);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_K13, m_edit_phase_no4_k13);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_K21, m_edit_phase_no4_k21);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_K22, m_edit_phase_no4_k22);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_K23, m_edit_phase_no4_k23);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_K31, m_edit_phase_no4_k31);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_K32, m_edit_phase_no4_k32);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO4_K33, m_edit_phase_no4_k33);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGPhaseNo4, CDialog)
//	ON_COMMAND(IDC_EDIT_PHASE_NO3_C56, &ElectricModelingDLGPhaseNo4::OnEditPhaseNo3C56)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C12, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C12)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C13, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C13)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C14, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C14)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C15, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C15)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C16, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C16)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C23, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C23)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C24, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C24)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C25, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C25)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C26, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C26)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C34, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C34)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C35, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C35)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C36, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C36)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C45, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C45)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C46, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C46)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_C56, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C56)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_K12, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4K12)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_K13, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4K13)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO4_K23, &ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4K23)
END_MESSAGE_MAP()


// ElectricModelingDLGPhaseNo4 message handlers


BOOL ElectricModelingDLGPhaseNo4::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here



	// 由于对话框中的矩阵是对称矩阵，故初始状态设置下半部分为只读，通过填写山部分自动填入下半部分
	// 设置C值矩阵的初始状态为：下半部分只读
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C32)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C41)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C42)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C43)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C51)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C52)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C53)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C54)))->SetReadOnly(TRUE);


	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C61)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C62)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C63)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C64)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C65)))->SetReadOnly(TRUE);

	// 设置K值矩阵的初始状态为：下半部分为只读
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K32)))->SetReadOnly(TRUE);

	// 由于初始状态下：System Type选则elastic，Number of phase为1，故设置如下
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C16)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C26)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C31)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C36)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C41)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C42)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C43)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C44)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C45)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C46)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C51)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C52)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C53)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C54)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C55)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C56)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C61)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C62)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C63)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C64)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C65)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C66)))->SetReadOnly(TRUE);


	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K13)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K21)))->SetReadOnly(FALSE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K23)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K31)))->SetReadOnly(FALSE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K32)))->SetReadOnly(FALSE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K33)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D16)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D26)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D36)))->SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
BOOL ElectricModelingDLGPhaseNo4::ResponseSignal(int mysignal){
	switch(mysignal){
	case 0:
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C13)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C14)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C15)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C16)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C23)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C24)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C25)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C26)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C33)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C34)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C35)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C36)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C41)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C42)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C43)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C44)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C45)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C46)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C51)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C52)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C53)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C54)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C55)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C56)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C61)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C62)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C63)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C64)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C65)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C66)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K13)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K23)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K31)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K33)))->SetReadOnly(TRUE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D13)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D14)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D15)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D16)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D23)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D24)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D25)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D26)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D31)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D33)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D34)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D35)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D36)))->SetReadOnly(TRUE);
		break;
	case 1:
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C13)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C14)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C15)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C16)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C23)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C24)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C25)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C26)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C31)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C33)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C34)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C35)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C36)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C41)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C42)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C43)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C44)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C45)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C46)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C51)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C52)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C53)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C54)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C55)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C56)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C61)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C62)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C63)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C64)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C65)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C66)))->SetReadOnly(TRUE);


		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K13)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K23)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K33)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D13)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D14)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D15)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D16)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D23)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D24)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D25)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D26)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D31)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D33)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D34)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D35)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D36)))->SetReadOnly(TRUE);

		break;
	case 2:
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C13)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C14)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C15)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C16)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C23)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C24)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C25)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C26)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C33)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C34)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C35)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C36)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C41)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C42)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C43)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C44)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C45)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C46)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C51)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C52)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C53)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C54)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C55)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C56)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C61)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C62)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C63)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C64)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C65)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C66)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K13)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K23)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K33)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D13)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D14)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D15)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D16)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D23)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D24)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D25)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D26)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D31)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D33)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D34)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D35)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D36)))->SetReadOnly(FALSE);

		break;
	default:
		break;
	}
	return TRUE;
}

// 设置自己不提供输入服务
void ElectricModelingDLGPhaseNo4::NoInputService(){
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C16)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C26)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C31)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C36)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C41)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C42)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C43)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C44)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C45)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C46)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C51)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C52)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C53)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C54)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C55)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C56)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C61)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C62)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C63)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C64)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C65)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_C66)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K13)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K23)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K31)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_K33)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D16)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D26)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO4_D36)))->SetReadOnly(TRUE);
}

//void ElectricModelingDLGPhaseNo4::OnEditPhaseNo3C56()
//{
//	// TODO: Add your command handler code here
//}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C12,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C21,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C13,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C31,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C14()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C14,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C41,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C15()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C15,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C51,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C16()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C16,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C61,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C23()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C23,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C32,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C24()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C24,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C42,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C25()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C25,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C52,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C26()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C26,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C62,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C34()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C34,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C43,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C35()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C35,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C53,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C36()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C36,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C63,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C45()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C45,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C54,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C46()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C46,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C64,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4C56()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_C56,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_C65,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4K12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_K12,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_K21,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4K13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_K13,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_K31,str);
}


void ElectricModelingDLGPhaseNo4::OnChangeEditPhaseNo4K23()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO4_K23,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO4_K32,str);
}
