// ElectricModelingDLGMagnetoelectricExternal.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ElectricModelingDLGMagnetoelectricExternal.h"
#include "afxdialogex.h"


// ElectricModelingDLGMagnetoelectricExternal dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMagnetoelectricExternal, CDialog)

ElectricModelingDLGMagnetoelectricExternal::ElectricModelingDLGMagnetoelectricExternal(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMagnetoelectricExternal::IDD, pParent)
{

	m_combo_mechanical_boundary_string = _T("");
	m_combo_mechanical_boundary_int = 0;
	m_static_eq11 = _T("¦Å11");
	m_static_eq12 = _T("¦Å12");
	m_static_eq13 = _T("¦Å13");
	m_static_eq22 = _T("¦Å22");
	m_static_eq23 = _T("¦Å23");
	m_static_eq33 = _T("¦Å33");
	m_edit_eq11 = 0.0f;
	m_edit_eq12 = 0.0f;
	m_edit_eq13 = 0.0f;
	m_edit_eq22 = 0.0f;
	m_edit_eq23 = 0.0f;
	m_edit_eq33 = 0.0f;

	m_edit_ele_e1 = 0.0f;
	m_edit_ele_e2 = 0.0f;
	m_edit_ele_e3 = 0.0f;

	m_edit_mag_h1 = 0.0f;
	m_edit_mag_h2 = 0.0f;
	m_edit_mag_h3 = 0.0f;
}

ElectricModelingDLGMagnetoelectricExternal::~ElectricModelingDLGMagnetoelectricExternal()
{
}

void ElectricModelingDLGMagnetoelectricExternal::DoDataExchange(CDataExchange* pDX)
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

	DDX_Text(pDX, IDC_EDIT_ELE_E1, m_edit_ele_e1);
	DDX_Text(pDX, IDC_EDIT_ELE_E2, m_edit_ele_e2);
	DDX_Text(pDX, IDC_EDIT_ELE_E3, m_edit_ele_e3);

	DDX_Text(pDX, IDC_EDIT_MAG_H1, m_edit_mag_h1);
	DDX_Text(pDX, IDC_EDIT_MAG_H2, m_edit_mag_h2);
	DDX_Text(pDX, IDC_EDIT_MAG_H3, m_edit_mag_h3);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMagnetoelectricExternal, CDialog)
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGMagnetoelectricExternal::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO_MECHANICAL_BOUNDARY, &ElectricModelingDLGMagnetoelectricExternal::OnCbnSelchangeComboMechanicalBoundary)
END_MESSAGE_MAP()


// ElectricModelingDLGMagnetoelectricExternal message handlers


void ElectricModelingDLGMagnetoelectricExternal::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	this->UpdateData(TRUE);
	//CDialog::OnOK();
}


BOOL ElectricModelingDLGMagnetoelectricExternal::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	m_ComboMechanicalBoundary.AddString(_T("Applied strain ¦Å"));
	m_ComboMechanicalBoundary.AddString(_T("Applied stress ¦Ò (Pa)"));
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


void ElectricModelingDLGMagnetoelectricExternal::OnCbnSelchangeComboMechanicalBoundary()
{
	// TODO: Add your control notification handler code here
	int curSel = m_ComboMechanicalBoundary.GetCurSel();
	switch (curSel)
	{
	case 0:
		m_static_eq11=_T("¦Å11");
		m_static_eq22=_T("¦Å22");
		m_static_eq33=_T("¦Å33");
		m_static_eq23=_T("¦Å23");
		m_static_eq13=_T("¦Å13");
		m_static_eq12=_T("¦Å12");
		m_StaticEq11.SetWindowTextA(m_static_eq11);
		m_StaticEq22.SetWindowTextA(m_static_eq22);
		m_StaticEq33.SetWindowTextA(m_static_eq33);
		m_StaticEq23.SetWindowTextA(m_static_eq23);
		m_StaticEq12.SetWindowTextA(m_static_eq12);
		m_StaticEq13.SetWindowTextA(m_static_eq13);
		break;
	case 1:
		m_static_eq11=_T("¦Ò11");
		m_static_eq22=_T("¦Ò22");
		m_static_eq33=_T("¦Ò33");
		m_static_eq23=_T("¦Ò23");
		m_static_eq13=_T("¦Ò13");
		m_static_eq12=_T("¦Ò12");
		m_StaticEq11.SetWindowTextA(m_static_eq11);
		m_StaticEq22.SetWindowTextA(m_static_eq22);
		m_StaticEq33.SetWindowTextA(m_static_eq33);
		m_StaticEq23.SetWindowTextA(m_static_eq23);
		m_StaticEq12.SetWindowTextA(m_static_eq12);
		m_StaticEq13.SetWindowTextA(m_static_eq13);
		break;
	}
}
