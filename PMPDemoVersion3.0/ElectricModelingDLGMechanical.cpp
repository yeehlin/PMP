// ElectricModelingDLGMechanical.cpp : implementation file
//

#include "stdafx.h"
#include "VTKMFCCreateBMPActors.h"
#include "ElectricModelingDLGMechanical.h"
#include "afxdialogex.h"


// ElectricModelingDLGMechanical dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMechanical, CDialog)

ElectricModelingDLGMechanical::ElectricModelingDLGMechanical(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMechanical::IDD, pParent)
{

	m_edit_eo1 = 0.0f;
	m_combo_bondary_condition_string = _T("");
	m_combo_bondary_condition_int = 0;
	m_edit_eo2 = 0.0f;
	m_edit_eo3 = 0.0f;
	m_edit_eo4 = 0.0f;
	m_edit_eo5 = 0.0f;
	m_edit_eo6 = 0.0f;
}

ElectricModelingDLGMechanical::~ElectricModelingDLGMechanical()
{
}

void ElectricModelingDLGMechanical::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_BONDARY_CONDITION, m_ComboBondaryCondition);
	DDX_Text(pDX, IDC_EDIT_EO1, m_edit_eo1);
	DDX_CBString(pDX, IDC_COMBO_BONDARY_CONDITION, m_combo_bondary_condition_string);
	DDX_CBIndex(pDX, IDC_COMBO_BONDARY_CONDITION, m_combo_bondary_condition_int);
	DDX_Text(pDX, IDC_EDIT_EO2, m_edit_eo2);
	DDX_Text(pDX, IDC_EDIT_EO3, m_edit_eo3);
	DDX_Text(pDX, IDC_EDIT_EO4, m_edit_eo4);
	DDX_Text(pDX, IDC_EDIT_EO5, m_edit_eo5);
	DDX_Text(pDX, IDC_EDIT_EO6, m_edit_eo6);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMechanical, CDialog)
END_MESSAGE_MAP()


// ElectricModelingDLGMechanical message handlers


BOOL ElectricModelingDLGMechanical::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	m_ComboBondaryCondition.InsertString(0,"Applied strain ¦Å1~¦Å6");
	m_ComboBondaryCondition.InsertString(1,"Applied stress ¦Ò1~¦Ò6(Pa)");
	m_ComboBondaryCondition.SetCurSel(m_combo_bondary_condition_int);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
