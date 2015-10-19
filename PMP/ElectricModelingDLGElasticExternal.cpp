// ElectricModelingDLGElasticExternal.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ElectricModelingDLGElasticExternal.h"
#include "afxdialogex.h"


// ElectricModelingDLGElasticExternal dialog

// 共享变量的初始化
float ElectricModelingDLGElasticExternal::eqe[6] = {0.0f};
float ElectricModelingDLGElasticExternal::eqq[6] = {0.0f};
float ElectricModelingDLGElasticExternal::ele[3] = {0.0f};
float ElectricModelingDLGElasticExternal::magh[3] = {0.0f};

IMPLEMENT_DYNAMIC(ElectricModelingDLGElasticExternal, CDialog)

ElectricModelingDLGElasticExternal::ElectricModelingDLGElasticExternal(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGElasticExternal::IDD, pParent)
{
	m_combo_mechanical_boundary_string = _T("");
	m_combo_mechanical_boundary_int = 0;
	m_static_eq11 = _T("ε11");
	m_static_eq12 = _T("ε12");
	m_static_eq13 = _T("ε13");
	m_static_eq22 = _T("ε22");
	m_static_eq23 = _T("ε23");
	m_static_eq33 = _T("ε33");
	m_edit_eq11 = 0.0f;
	m_edit_eq12 = 0.0f;
	m_edit_eq13 = 0.0f;
	m_edit_eq22 = 0.0f;
	m_edit_eq23 = 0.0f;
	m_edit_eq33 = 0.0f;
}

ElectricModelingDLGElasticExternal::~ElectricModelingDLGElasticExternal()
{
}

void ElectricModelingDLGElasticExternal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO_MECHANICAL_BOUNDARY, m_ComboMechanicalBoundary);
	DDX_CBString(pDX, IDC_COMBO_MECHANICAL_BOUNDARY, m_combo_mechanical_boundary_string);
	DDX_CBIndex(pDX, IDC_COMBO_MECHANICAL_BOUNDARY, m_combo_mechanical_boundary_int);
	DDX_Control(pDX, IDC_STATIC_EQ11, m_StaticEq11);
	DDX_Control(pDX, IDC_STATIC_EQ12, m_StaticEq12);
	DDX_Control(pDX, IDC_STATIC_EQ13, m_StaticEq13);
	DDX_Control(pDX, IDC_STATIC_EQ22, m_StaticEq22);
	DDX_Control(pDX, IDC_STATIC_EQ23, m_StaticEq23);
	DDX_Control(pDX, IDC_STATIC_EQ33, m_StaticEq33);
	DDX_Text(pDX, IDC_STATIC_EQ11, m_static_eq11);
	DDX_Text(pDX, IDC_STATIC_EQ12, m_static_eq12);
	DDX_Text(pDX, IDC_STATIC_EQ13, m_static_eq13);
	DDX_Text(pDX, IDC_STATIC_EQ22, m_static_eq22);
	DDX_Text(pDX, IDC_STATIC_EQ23, m_static_eq23);
	DDX_Text(pDX, IDC_STATIC_EQ33, m_static_eq33);
	DDX_Text(pDX, IDC_EDIT_EQ11, m_edit_eq11);
	DDX_Text(pDX, IDC_EDIT_EQ12, m_edit_eq12);
	DDX_Text(pDX, IDC_EDIT_EQ13, m_edit_eq13);
	DDX_Text(pDX, IDC_EDIT_EQ22, m_edit_eq22);
	DDX_Text(pDX, IDC_EDIT_EQ23, m_edit_eq23);
	DDX_Text(pDX, IDC_EDIT_EQ33, m_edit_eq33);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGElasticExternal, CDialog)
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGElasticExternal::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO_MECHANICAL_BOUNDARY, &ElectricModelingDLGElasticExternal::OnCbnSelchangeComboMechanicalBoundary)
END_MESSAGE_MAP()


// ElectricModelingDLGElasticExternal message handlers


void ElectricModelingDLGElasticExternal::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	this->UpdateData(TRUE);
	//CDialog::OnOK();
}


BOOL ElectricModelingDLGElasticExternal::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	m_ComboMechanicalBoundary.AddString(_T("Applied strain ε"));
	m_ComboMechanicalBoundary.AddString(_T("Applied stress σ (Pa)"));
	m_ComboMechanicalBoundary.SetCurSel(m_combo_mechanical_boundary_int);

	m_StaticEq11.SetWindowTextA(m_static_eq11);
	m_StaticEq22.SetWindowTextA(m_static_eq22);
	m_StaticEq33.SetWindowTextA(m_static_eq33);
	m_StaticEq23.SetWindowTextA(m_static_eq23);
	m_StaticEq12.SetWindowTextA(m_static_eq12);
	m_StaticEq13.SetWindowTextA(m_static_eq13);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGElasticExternal::OnCbnSelchangeComboMechanicalBoundary()
{
	// TODO: Add your control notification handler code here
	int curSel = m_ComboMechanicalBoundary.GetCurSel();
	switch (curSel)
	{
	case 0:
		m_static_eq11=_T("ε11");
		m_static_eq22=_T("ε22");
		m_static_eq33=_T("ε33");
		m_static_eq23=_T("ε23");
		m_static_eq13=_T("ε13");
		m_static_eq12=_T("ε12");
		m_StaticEq11.SetWindowTextA(m_static_eq11);
		m_StaticEq22.SetWindowTextA(m_static_eq22);
		m_StaticEq33.SetWindowTextA(m_static_eq33);
		m_StaticEq23.SetWindowTextA(m_static_eq23);
		m_StaticEq12.SetWindowTextA(m_static_eq12);
		m_StaticEq13.SetWindowTextA(m_static_eq13);
		break;
	case 1:
		m_static_eq11=_T("σ11");
		m_static_eq22=_T("σ22");
		m_static_eq33=_T("σ33");
		m_static_eq23=_T("σ23");
		m_static_eq13=_T("σ13");
		m_static_eq12=_T("σ12");
		m_StaticEq11.SetWindowTextA(m_static_eq11);
		m_StaticEq22.SetWindowTextA(m_static_eq22);
		m_StaticEq33.SetWindowTextA(m_static_eq33);
		m_StaticEq23.SetWindowTextA(m_static_eq23);
		m_StaticEq12.SetWindowTextA(m_static_eq12);
		m_StaticEq13.SetWindowTextA(m_static_eq13);
		break;
	}
}
