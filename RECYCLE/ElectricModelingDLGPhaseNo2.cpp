// ElectricModelingDLGPhaseNo2.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGPhaseNo2.h"
#include "afxdialogex.h"


// ElectricModelingDLGPhaseNo2 dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGPhaseNo2, CDialog)

ElectricModelingDLGPhaseNo2::ElectricModelingDLGPhaseNo2(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGPhaseNo2::IDD, pParent)
{
	SameSignalFlag = -1;
	m_edit_phase_no2_c11 = 0.0f;
	m_edit_phase_no2_c12 = 0.0f;
	m_edit_phase_no2_c13 = 0.0f;
	m_edit_phase_no2_c14 = 0.0f;
	m_edit_phase_no2_c15 = 0.0f;
	m_edit_phase_no2_c16 = 0.0f;
	m_edit_phase_no2_c21 = 0.0f;
	m_edit_phase_no2_c22 = 0.0f;
	m_edit_phase_no2_c23 = 0.0f;
	m_edit_phase_no2_c24 = 0.0f;
	m_edit_phase_no2_c25 = 0.0f;
	m_edit_phase_no2_c26 = 0.0f;
	m_edit_phase_no2_c31 = 0.0f;
	m_edit_phase_no2_c32 = 0.0f;
	m_edit_phase_no2_c33 = 0.0f;
	m_edit_phase_no2_c34 = 0.0f;
	m_edit_phase_no2_c35 = 0.0f;
	m_edit_phase_no2_c36 = 0.0f;
	m_edit_phase_no2_c41 = 0.0f;
	m_edit_phase_no2_c42 = 0.0f;
	m_edit_phase_no2_c43 = 0.0f;
	m_edit_phase_no2_c44 = 0.0f;
	m_edit_phase_no2_c45 = 0.0f;
	m_edit_phase_no2_c46 = 0.0f;
	m_edit_phase_no2_c51 = 0.0f;
	m_edit_phase_no2_c52 = 0.0f;
	m_edit_phase_no2_c53 = 0.0f;
	m_edit_phase_no2_c54 = 0.0f;
	m_edit_phase_no2_c55 = 0.0f;
	m_edit_phase_no2_c56 = 0.0f;
	m_edit_phase_no2_c61 = 0.0f;
	m_edit_phase_no2_c62 = 0.0f;
	m_edit_phase_no2_c63 = 0.0f;
	m_edit_phase_no2_c65 = 0.0f;
	m_edit_phase_no2_c64 = 0.0f;
	m_edit_phase_no2_c65 = 0.0f;
	m_edit_phase_no2_c66 = 0.0f;
	m_edit_phase_no2_d11 = 0.0f;
	m_edit_phase_no2_d12 = 0.0f;
	m_edit_phase_no2_d13 = 0.0f;
	m_edit_phase_no2_d14 = 0.0f;
	m_edit_phase_no2_d15 = 0.0f;
	m_edit_phase_no2_d16 = 0.0f;
	m_edit_phase_no2_d21 = 0.0f;
	m_edit_phase_no2_d22 = 0.0f;
	m_edit_phase_no2_d23 = 0.0f;
	m_edit_phase_no2_d24 = 0.0f;
	m_edit_phase_no2_d25 = 0.0f;
	m_edit_phase_no2_d26 = 0.0f;
	m_edit_phase_no2_d31 = 0.0f;
	m_edit_phase_no2_d32 = 0.0f;
	m_edit_phase_no2_d33 = 0.0f;
	m_edit_phase_no2_d34 = 0.0f;
	m_edit_phase_no2_d35 = 0.0f;
	m_edit_phase_no2_d36 = 0.0f;
	m_edit_phase_no2_k11 = 0.0f;
	m_edit_phase_no2_k12 = 0.0f;
	m_edit_phase_no2_k13 = 0.0f;
	m_edit_phase_no2_k21 = 0.0f;
	m_edit_phase_no2_k22 = 0.0f;
	m_edit_phase_no2_k23 = 0.0f;
	m_edit_phase_no2_k31 = 0.0f;
	m_edit_phase_no2_k32 = 0.0f;
	m_edit_phase_no2_k33 = 0.0f;

}

ElectricModelingDLGPhaseNo2::~ElectricModelingDLGPhaseNo2()
{
}

void ElectricModelingDLGPhaseNo2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C11, m_edit_phase_no2_c11);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C12, m_edit_phase_no2_c12);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C13, m_edit_phase_no2_c13);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C14, m_edit_phase_no2_c14);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C15, m_edit_phase_no2_c15);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C16, m_edit_phase_no2_c16);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C21, m_edit_phase_no2_c21);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C22, m_edit_phase_no2_c22);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C23, m_edit_phase_no2_c23);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C24, m_edit_phase_no2_c24);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C25, m_edit_phase_no2_c25);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C26, m_edit_phase_no2_c26);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C31, m_edit_phase_no2_c31);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C32, m_edit_phase_no2_c32);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C33, m_edit_phase_no2_c33);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C34, m_edit_phase_no2_c34);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C35, m_edit_phase_no2_c35);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C36, m_edit_phase_no2_c36);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C41, m_edit_phase_no2_c41);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C42, m_edit_phase_no2_c42);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C43, m_edit_phase_no2_c43);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C44, m_edit_phase_no2_c44);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C45, m_edit_phase_no2_c45);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C46, m_edit_phase_no2_c46);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C51, m_edit_phase_no2_c51);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C52, m_edit_phase_no2_c52);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C53, m_edit_phase_no2_c53);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C54, m_edit_phase_no2_c54);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C55, m_edit_phase_no2_c55);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C56, m_edit_phase_no2_c56);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C61, m_edit_phase_no2_c61);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C62, m_edit_phase_no2_c62);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C63, m_edit_phase_no2_c63);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C64, m_edit_phase_no2_c65);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C64, m_edit_phase_no2_c64);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C65, m_edit_phase_no2_c65);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_C66, m_edit_phase_no2_c66);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D11, m_edit_phase_no2_d11);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D12, m_edit_phase_no2_d12);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D13, m_edit_phase_no2_d13);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D14, m_edit_phase_no2_d14);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D15, m_edit_phase_no2_d15);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D16, m_edit_phase_no2_d16);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D21, m_edit_phase_no2_d21);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D22, m_edit_phase_no2_d22);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D23, m_edit_phase_no2_d23);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D24, m_edit_phase_no2_d24);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D25, m_edit_phase_no2_d25);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D26, m_edit_phase_no2_d26);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D31, m_edit_phase_no2_d31);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D32, m_edit_phase_no2_d32);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D33, m_edit_phase_no2_d33);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D34, m_edit_phase_no2_d34);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D35, m_edit_phase_no2_d35);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_D36, m_edit_phase_no2_d36);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_K11, m_edit_phase_no2_k11);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_K12, m_edit_phase_no2_k12);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_K13, m_edit_phase_no2_k13);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_K21, m_edit_phase_no2_k21);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_K22, m_edit_phase_no2_k22);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_K23, m_edit_phase_no2_k23);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_K31, m_edit_phase_no2_k31);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_K32, m_edit_phase_no2_k32);
	DDX_Text(pDX, IDC_EDIT_PHASE_NO2_K33, m_edit_phase_no2_k33);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGPhaseNo2, CDialog)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C12, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C12)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C13, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C13)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C14, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C14)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C15, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C15)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C16, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C16)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C23, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C23)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C24, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C24)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C25, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C25)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C26, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C26)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C34, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C34)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C35, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C35)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C36, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C36)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C45, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C45)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C46, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C46)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_C56, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C56)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_K12, &ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2K12)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_K13, &ElectricModelingDLGPhaseNo2::OnChangeEditPhaseNo2K13)
	ON_EN_CHANGE(IDC_EDIT_PHASE_NO2_K23, &ElectricModelingDLGPhaseNo2::OnChangeEditPhaseNo2K23)
END_MESSAGE_MAP()


// ElectricModelingDLGPhaseNo2 message handlers


BOOL ElectricModelingDLGPhaseNo2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	SameSignalFlag = -1;

	// 由于对话框中的矩阵是对称矩阵，故初始状态设置下半部分为只读，通过填写山部分自动填入下半部分
	// 设置C值矩阵的初始状态为：下半部分只读
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C32)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C41)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C42)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C43)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C51)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C52)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C53)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C54)))->SetReadOnly(TRUE);


	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C61)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C62)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C63)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C64)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C65)))->SetReadOnly(TRUE);

	// 设置K值矩阵的初始状态为：下半部分为只读
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K21)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K32)))->SetReadOnly(TRUE);


	// 由于初始状态下：System Type选则elastic，Number of phase为1，故设置如下
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C16)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C26)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C31)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C36)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C41)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C42)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C43)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C44)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C45)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C46)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C51)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C52)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C53)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C54)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C55)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C56)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C61)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C62)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C63)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C64)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C65)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C66)))->SetReadOnly(TRUE);


	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K13)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K21)))->SetReadOnly(FALSE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K23)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K31)))->SetReadOnly(FALSE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K32)))->SetReadOnly(FALSE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K33)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D16)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D26)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D36)))->SetReadOnly(TRUE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
BOOL ElectricModelingDLGPhaseNo2::ResponseSignal(int mysignal){
	switch(mysignal){
	case 0:
		//::MessageBox(NULL,_T("进了phase No.2"),_T("OKOK"),MB_OK);
		// 似乎问题出在this上面，可以想象，对话框根本没有调用构造函数构造对象（这样也就不存在this和类的属性了）
		((CEdit *)(GetDlgItem(IDC_EDIT_PHASE_NO2_C11)))->SetReadOnly(FALSE);
		//::MessageBox(NULL,_T("进了phase No.2第一步"),_T("OKOK"),MB_OK);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C13)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C14)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C15)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C16)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C23)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C24)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C25)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C26)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C33)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C34)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C35)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C36)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C41)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C42)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C43)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C44)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C45)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C46)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C51)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C52)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C53)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C54)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C55)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C56)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C61)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C62)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C63)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C64)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C65)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C66)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K13)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K23)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K31)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K33)))->SetReadOnly(TRUE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D13)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D14)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D15)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D16)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D23)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D24)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D25)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D26)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D31)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D33)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D34)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D35)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D36)))->SetReadOnly(TRUE);
		break;
	case 1:
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C13)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C14)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C15)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C16)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C23)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C24)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C25)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C26)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C31)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C33)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C34)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C35)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C36)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C41)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C42)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C43)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C44)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C45)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C46)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C51)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C52)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C53)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C54)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C55)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C56)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C61)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C62)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C63)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C64)))->SetReadOnly(TRUE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C65)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C66)))->SetReadOnly(TRUE);


		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K13)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K23)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K33)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D11)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D12)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D13)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D14)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D15)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D16)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D21)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D22)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D23)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D24)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D25)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D26)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D31)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D32)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D33)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D34)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D35)))->SetReadOnly(TRUE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D36)))->SetReadOnly(TRUE);

		break;
	case 2:
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C13)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C14)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C15)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C16)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C23)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C24)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C25)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C26)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C33)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C34)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C35)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C36)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C41)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C42)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C43)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C44)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C45)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C46)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C51)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C52)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C53)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C54)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C55)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C56)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C61)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C62)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C63)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C64)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C65)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C66)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K13)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K23)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K31)))->SetReadOnly(FALSE);
		//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K33)))->SetReadOnly(FALSE);

		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D11)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D12)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D13)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D14)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D15)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D16)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D21)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D22)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D23)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D24)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D25)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D26)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D31)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D32)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D33)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D34)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D35)))->SetReadOnly(FALSE);
		((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D36)))->SetReadOnly(FALSE);

		break;
	default:
		break;
	}
	return TRUE;
}

// 设置自己不提供输入服务
void ElectricModelingDLGPhaseNo2::NoInputService(){
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C16)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C26)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C31)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C36)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C41)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C42)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C43)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C44)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C45)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C46)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C51)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C52)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C53)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C54)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C55)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C56)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C61)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C62)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C63)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C64)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C65)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_C66)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K13)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K23)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K31)))->SetReadOnly(TRUE);
	//((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_K33)))->SetReadOnly(TRUE);

	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D11)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D12)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D13)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D14)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D15)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D16)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D21)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D22)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D23)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D24)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D25)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D26)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D31)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D32)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D33)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D34)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D35)))->SetReadOnly(TRUE);
	((CEdit *)(this->GetDlgItem(IDC_EDIT_PHASE_NO2_D36)))->SetReadOnly(TRUE);
}

void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C12,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C21,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C13,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C31,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C14()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C14,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C41,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C15()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C15,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C51,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C16()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C16,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C61,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C23()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C23,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C32,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C24()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C24,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C42,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C25()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C25,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C52,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C26()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C26,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C62,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C34()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C34,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C43,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C35()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C35,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C53,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C36()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C36,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C63,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C45()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C45,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C54,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C46()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C46,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C64,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2C56()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_C56,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_C65,str);
}


void ElectricModelingDLGPhaseNo2::OnEnChangeEditPhaseNo2K12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_K12,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_K21,str);
}


void ElectricModelingDLGPhaseNo2::OnChangeEditPhaseNo2K13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_K13,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_K31,str);
}


void ElectricModelingDLGPhaseNo2::OnChangeEditPhaseNo2K23()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT_PHASE_NO2_K23,str);
	SetDlgItemText(IDC_EDIT_PHASE_NO2_K32,str);
}
