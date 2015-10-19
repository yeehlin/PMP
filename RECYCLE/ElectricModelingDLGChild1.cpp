// ElectricModelingDLGChild1.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGChild1.h"
#include "ElectricModelingDLGMore.h"
#include "ElectricModelingDLGMoreElastic.h"
#include "ElectricModelingDLGMoreDielectric.h"
#include "ElectricModelingDLGMorePiezoelectric.h"
#include "afxdialogex.h"


// ElectricModelingDLGChild1 dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGChild1, CDialog)

ElectricModelingDLGChild1::ElectricModelingDLGChild1(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGChild1::IDD, pParent)
{

	m_edit_nums_phases = 1;
	m_combo_sys_type = _T("");
	m_edit_mesh_nx = 0;
	m_edit_mesh_ny = 0;
	m_edit_mesh_nz = 0;
	m_edit_size_lx = 0;
	m_edit_size_ly = 0;
	m_edit_size_lz = 0;
	m_combo_file_format = _T("");
	m_combo_simulation_type = _T("");
	m_combo_simulation_type_int = 0;
	m_combo_sys_type_int = 0;
	m_combo_file_format_int = 0;
}

ElectricModelingDLGChild1::~ElectricModelingDLGChild1()
{
}

void ElectricModelingDLGChild1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SYS_TYPE, m_ComboSysType);
	DDX_Control(pDX, IDC_COMBO_FILE_FORMAT, m_ComboFileFormat);
	DDX_Control(pDX, IDC_COMBO_SIMULATION_TYPE, m_ComboSimulationType);
	DDX_Text(pDX, IDC_EDIT_NUMS_PHASES, m_edit_nums_phases);
	DDV_MinMaxInt(pDX, m_edit_nums_phases, 1, 6);
	DDX_Control(pDX, IDC_SPIN_NUMS_PHASES, m_SpinNumsPhases);
	DDX_CBString(pDX, IDC_COMBO_SYS_TYPE, m_combo_sys_type);
	DDX_Text(pDX, IDC_EDIT_MESH_NX, m_edit_mesh_nx);
	DDX_Text(pDX, IDC_EDIT_MESH_NY, m_edit_mesh_ny);
	DDX_Text(pDX, IDC_EDIT_MESH_NZ, m_edit_mesh_nz);
	DDX_Text(pDX, IDC_EDIT_SIZE_LX, m_edit_size_lx);
	DDX_Text(pDX, IDC_EDIT_SIZE_LY, m_edit_size_ly);
	DDX_Text(pDX, IDC_EDIT_SIZE_LZ, m_edit_size_lz);
	DDX_CBString(pDX, IDC_COMBO_FILE_FORMAT, m_combo_file_format);
	DDX_CBString(pDX, IDC_COMBO_SIMULATION_TYPE, m_combo_simulation_type);
	DDX_CBIndex(pDX, IDC_COMBO_SIMULATION_TYPE, m_combo_simulation_type_int);
	DDX_CBIndex(pDX, IDC_COMBO_SYS_TYPE, m_combo_sys_type_int);
	DDX_CBIndex(pDX, IDC_COMBO_FILE_FORMAT, m_combo_file_format_int);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGChild1, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_SYS_TYPE, &ElectricModelingDLGChild1::OnCbnSelchangeComboSysType)
//	ON_BN_CLICKED(IDC_BUTTON1, &ElectricModelingDLGChild1::OnBnClickedButton1)
//ON_BN_CLICKED(IDC_BUTTON1, &ElectricModelingDLGChild1::OnBnClickedButton1)
//ON_BN_CLICKED(IDC_BUTTON3, &ElectricModelingDLGChild1::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON_MORE, &ElectricModelingDLGChild1::OnBnClickedButtonMore)
ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_NUMS_PHASES, &ElectricModelingDLGChild1::OnDeltaposSpinNumsPhases)
ON_EN_CHANGE(IDC_EDIT_NUMS_PHASES, &ElectricModelingDLGChild1::OnEnChangeEditNumsPhases)
ON_EN_CHANGE(IDC_EDIT_SIZE_LY, &ElectricModelingDLGChild1::OnEnChangeEditSizeLy)
ON_BN_CLICKED(IDOK, &ElectricModelingDLGChild1::OnBnClickedOk)
END_MESSAGE_MAP()


// ElectricModelingDLGChild1 message handlers


BOOL ElectricModelingDLGChild1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	// ������������
	m_ComboSysType.InsertString(0,_T("Elastic"));
	m_ComboSysType.InsertString(1,_T("Dielectric"));
	m_ComboSysType.InsertString(2,_T("Piezoelectric"));
	// ��������Ĭ��ѡ��
	// ���������ֵ�����ǹ̶���ֵ
	// m_ComboSysType.SetCurSel(0);
	m_ComboSysType.SetCurSel(m_combo_sys_type_int);

	// ������ת�ؼ��Ļ��ؼ�����ǰ����auto buddy,set buddy integer=true��
	m_SpinNumsPhases.SetBuddy((CEdit *)GetDlgItem(IDC_EDIT_NUMS_PHASES));
	m_SpinNumsPhases.SetRange(1,6);

	// ������������
	m_ComboFileFormat.InsertString(0,_T("Phase fraction array"));
	m_ComboFileFormat.InsertString(1,_T("Phase id array"));
	// ��������Ĭ��ѡ��
	// ���������ֵ�������ǹ̶���ֵ
	// m_ComboFileFormat.SetCurSel(0);
	m_ComboFileFormat.SetCurSel(m_combo_file_format_int);

	// ������������
	m_ComboSimulationType.InsertString(0,_T("Effective properties"));
	m_ComboSimulationType.InsertString(1,_T("Material response to an external field"));
	// ����Ĭ��ѡ��
	// ���������ֵ�������ǹ̶���ֵ
	m_ComboSimulationType.SetCurSel(m_combo_simulation_type_int);

	// ��ҳ����������Լ��ĳ�ʼ״̬֮�⣬���ø�������ĳ�ʼ״̬����Phase No.x��״̬��
	// Phase numΪ1��System type��Ϊelasticʱ��״̬

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGChild1::OnCbnSelchangeComboSysType()
{
	// TODO: Add your control notification handler code here
	// ������Ͽ��е�ѡ�����phase No.x�е�״̬
	// ����number of phases ����Ҫ���ļ���phases
	CString numsphases ;
	GetDlgItemText(IDC_EDIT_NUMS_PHASES,numsphases);
	//::MessageBox(NULL,numsphases,_T("OKOK"),MB_OK);
	int phases = atoi(numsphases);
	int curSel = m_ComboSysType.GetCurSel();
	//*
	switch(phases){
	case 1:
		//::MessageBox(NULL,"��Ҫ����Phase No.1",_T("OKOK"),MB_OK);
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->NoInputService();
		//m_pElectricModelingDLGPhaseNo3->NoInputService();
		//m_pElectricModelingDLGPhaseNo4->NoInputService();
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		break;
	case 2:
		//::MessageBox(NULL,"��Ҫ����Phase No.1 Phase No.2",_T("OKOK"),MB_OK);
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->NoInputService();
		//m_pElectricModelingDLGPhaseNo4->NoInputService();
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 3:
		//::MessageBox(NULL,"��Ҫ����Phase No.1 Phase No.2 No.3",_T("OKOK"),MB_OK);
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->NoInputService();
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 4:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 5:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo5->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 6:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo5->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo6->ResponseSignal(curSel);
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	default:
		break;
	}
	//*/
	/*
	switch (curSel){
	case 0:
		//::MessageBox(NULL,_T("����case 0:"),_T("OKOK"),MB_OK);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K11)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K12)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K13)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K21)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K22)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K23)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K31)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K32)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K33)))->SetReadOnly(TRUE);

		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D11)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D12)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D13)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D14)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D15)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D16)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D21)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D22)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D23)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D24)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D25)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D26)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D31)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D32)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D33)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D34)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D35)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D36)))->SetReadOnly(TRUE);

		// external field
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO1)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO2)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO3)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO4)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO5)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO6)))->SetReadOnly(FALSE);


		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_E1)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_E2)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_E3)))->SetReadOnly(TRUE);
		break;
	case 1:

		//::MessageBox(NULL,_T("����case 1:"),_T("OKOK"),MB_OK);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C11)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C12)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C13)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C14)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C15)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C16)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C21)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C22)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C23)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C24)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C25)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C26)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C31)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C32)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C33)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C34)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C35)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C36)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C41)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C42)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C43)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C44)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C45)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C46)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C51)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C52)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C53)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C54)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C55)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C56)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C61)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C62)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C63)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C64)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C65)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C66)))->SetReadOnly(TRUE);


		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K11)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K12)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K13)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K21)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K22)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K23)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K31)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K32)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K33)))->SetReadOnly(FALSE);

		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D11)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D12)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D13)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D14)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D15)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D16)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D21)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D22)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D23)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D24)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D25)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D26)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D31)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D32)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D33)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D34)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D35)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D36)))->SetReadOnly(TRUE);

		// external field
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO1)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO2)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO3)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO4)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO5)))->SetReadOnly(TRUE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO6)))->SetReadOnly(TRUE);


		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_E1)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_E2)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_E3)))->SetReadOnly(FALSE);

		break;
	case 2:

		//::MessageBox(NULL,_T("����case 2:"),_T("OKOK"),MB_OK);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C11)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C12)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C13)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C14)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C15)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C16)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C21)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C22)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C23)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C24)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C25)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C26)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C31)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C32)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C33)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C34)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C35)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C36)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C41)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C42)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C43)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C44)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C45)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C46)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C51)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C52)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C53)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C54)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C55)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C56)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C61)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C62)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C63)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C64)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C65)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_C66)))->SetReadOnly(FALSE);

		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K11)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K12)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K13)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K21)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K22)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K23)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K31)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K32)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_K33)))->SetReadOnly(FALSE);

		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D11)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D12)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D13)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D14)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D15)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D16)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D21)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D22)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D23)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D24)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D25)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D26)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D31)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D32)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D33)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D34)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D35)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild2->GetDlgItem(IDC_EDIT_D36)))->SetReadOnly(FALSE);

		// external field
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO1)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO2)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO3)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO4)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO5)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_EO6)))->SetReadOnly(FALSE);


		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_E1)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_E2)))->SetReadOnly(FALSE);
		((CEdit *)(m_pelectricModelingDLGChild3->GetDlgItem(IDC_EDIT_E3)))->SetReadOnly(FALSE);

		break;
	default:
		break;
	}
	//*/

}
//void ElectricModelingDLGChild1::OnBnClickedButton1()
//{
//	// TODO: Add your control notification handler code here
//}


//void ElectricModelingDLGChild1::OnBnClickedButton1()
//{
//	// TODO: Add your control notification handler code here
//	TCITEM  tcitemPhaseNo2;
//	tcitemPhaseNo2.mask = TCIF_TEXT;
//	tcitemPhaseNo2.pszText=_T("System Setup");
//	this->m_pelectricModelingDLGFather->m_tab.InsertItem(3,&tcitemPhaseNo2);
//}


//void ElectricModelingDLGChild1::OnBnClickedButton3()
//{
//	// TODO: Add your control notification handler code here
//
//}


void ElectricModelingDLGChild1::OnBnClickedButtonMore()
{
	// TODO: Add your control notification handler code here
	// ���more��ť��ζ�����System Type��Numbers of phases�е�ֵ������ͬ��ʽ���ں���ͬ��Ŀѡ��ĶԻ���
	// ��ȡSystem type
	CString SystemType;
	// ��ȡNumbers of phases
	CString NumbersOfPhases;
	// ��ȡSimulation type
	int simulationtype;
	int sysType;
	int numbersOfPhases;
	sysType = m_ComboSysType.GetCurSel();
	simulationtype = m_ComboSimulationType.GetCurSel();
	GetDlgItemText(IDC_EDIT_NUMS_PHASES,NumbersOfPhases);
	numbersOfPhases = atoi(NumbersOfPhases);
	switch(sysType){
	case 0:
		{
			// ���󱻳��з��ɻ�����Ի����������ΪElectricModelingDLGChild1��һ������
			// Ҳ������Ϊ�����ߵ����Դ��ڣ��Ϳ��Ի���
			//ElectricModelingDLGMoreElastic electricModelingDLGMoreElastic;
			// ����ElectricModelingDLGMoreElastic�����PhasesCount����Ϊ1
			electricModelingDLGMoreElastic.SetPhaseCount(numbersOfPhases);
			electricModelingDLGMoreElastic.SetSimulationType(simulationtype);
			electricModelingDLGMoreElastic.DoModal();
			break;
		}
	case 1:
		{

			//ElectricModelingDLGMoreDielectric electricModelingDLGMoreDielectric;
			// ����ElectricModelingDLGMoreElastic�����PhasesCount����Ϊ1
			electricModelingDLGMoreDielectric.SetPhaseCount(numbersOfPhases);
			electricModelingDLGMoreDielectric.SetSimulationType(simulationtype);
			electricModelingDLGMoreDielectric.DoModal();
			break;
		}
	case 2:
		{

			//ElectricModelingDLGMorePiezoelectric electricModelingDLGMorePiezoelectric;
			// ����ElectricModelingDLGMoreElastic�����PhasesCount����Ϊ1
			electricModelingDLGMorePiezoelectric.SetPhaseCount(numbersOfPhases);
			electricModelingDLGMorePiezoelectric.SetSimulationType(simulationtype);
			electricModelingDLGMorePiezoelectric.DoModal();
			break;
		}

	}
	
	/*

	// �����ڶԻ����е����Ի���
	ElectricModelingDLGMore electricModelingDLGMore;
	if (electricModelingDLGMore.DoModal()==IDOK)
	{
		// ���ݽ���
	}
	*/

}


void ElectricModelingDLGChild1::OnDeltaposSpinNumsPhases(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here

	// ���û�����ı�numbers of phase��ֵʱ���޸ĸ�����������״̬
	// �õ���ǰ���������
	CString PhaseNumString;
	GetDlgItemText(IDC_EDIT_NUMS_PHASES,PhaseNumString);
	int PhaseNum = atoi(PhaseNumString);

	// �õ�System Type��ѡ�����
	int curSel = ((CComboBox *)GetDlgItem(IDC_COMBO_SYS_TYPE))->GetCurSel();
	switch(PhaseNum){
	case 1:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->NoInputService();
		//m_pElectricModelingDLGPhaseNo3->NoInputService();
		//m_pElectricModelingDLGPhaseNo4->NoInputService();
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 2:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->NoInputService();
		//m_pElectricModelingDLGPhaseNo4->NoInputService();
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 3:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->NoInputService();
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 4:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 5:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo5->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 6:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo5->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo6->ResponseSignal(curSel);
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	default:
		// 1~6��������Ĵ���
		break;
	}


	*pResult = 0;
}


void ElectricModelingDLGChild1::OnEnChangeEditNumsPhases()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	// ���û�����ı�numbers of phase��ֵʱ���޸ĸ�����������״̬
	// �õ���ǰ���������
	CString PhaseNumString;
	GetDlgItemText(IDC_EDIT_NUMS_PHASES,PhaseNumString);
	int PhaseNum = atoi(PhaseNumString);

	// �õ�System Type��ѡ�����
	int curSel = ((CComboBox *)GetDlgItem(IDC_COMBO_SYS_TYPE))->GetCurSel();
	switch(PhaseNum){
	case 1:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->NoInputService();
		//m_pElectricModelingDLGPhaseNo3->NoInputService();
		//m_pElectricModelingDLGPhaseNo4->NoInputService();
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 2:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->NoInputService();
		//m_pElectricModelingDLGPhaseNo4->NoInputService();
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 3:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->NoInputService();
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 4:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo5->NoInputService();
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 5:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo5->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo6->NoInputService();
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	case 6:
		//m_pelectricModelingDLGChild2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo2->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo3->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo4->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo5->ResponseSignal(curSel);
		//m_pElectricModelingDLGPhaseNo6->ResponseSignal(curSel);
		//m_pelectricModelingDLGChild3->ResponseSignal(curSel);
		break;
	default:
		// 1~6��������Ĵ���
		break;
	}
}


void ElectricModelingDLGChild1::OnEnChangeEditSizeLy()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void ElectricModelingDLGChild1::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
