// CalculateDlgChild2.cpp : implementation file
//

#include "stdafx.h"
#include "VTKMFCCreateBMPActors.h"
#include "CalculateDlgChild2.h"
#include "afxdialogex.h"


// CalculateDlgChild2 dialog

IMPLEMENT_DYNAMIC(CalculateDlgChild2, CDialog)

CalculateDlgChild2::CalculateDlgChild2(CWnd* pParent /*=NULL*/)
	: CDialog(CalculateDlgChild2::IDD, pParent)
{

	m_edit_total_nums_of_steps = 0;
	m_edit_time_steps = 0;
	m_edit_time_steps_with_noise = 0;
}

CalculateDlgChild2::~CalculateDlgChild2()
{
}

void CalculateDlgChild2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TOTAL_NUMS_OF_STEPS, m_edit_total_nums_of_steps);
	DDX_Text(pDX, IDC_EDIT_TIME_STEPS, m_edit_time_steps);
	DDX_Text(pDX, IDC_EDIT_TIME_STEPS_WITH_NOISE, m_edit_time_steps_with_noise);
	DDX_Control(pDX, IDC_EDIT_TOTAL_NUMS_OF_STEPS, m_EditTotalNumsOfSteps);
	DDX_Control(pDX, IDC_EDIT_TIME_STEPS, m_EditTimeSteps);
	DDX_Control(pDX, IDC_EDIT_TIME_STEPS_WITH_NOISE, m_EditTimeStepsWithNoise);
}


BEGIN_MESSAGE_MAP(CalculateDlgChild2, CDialog)
END_MESSAGE_MAP()


// CalculateDlgChild2 message handlers


BOOL CalculateDlgChild2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	// 设置编辑框中的初始值
	SetDlgItemText(IDC_EDIT_TOTAL_NUMS_OF_STEPS,"10000");
	SetDlgItemText(IDC_EDIT_TIME_STEPS,"100");
	SetDlgItemText(IDC_EDIT_TIME_STEPS_WITH_NOISE,"100");

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
