// CalculateDlgChild3.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "CalculateDlgChild3.h"
#include "afxdialogex.h"


// CalculateDlgChild3 dialog

IMPLEMENT_DYNAMIC(CalculateDlgChild3, CDialog)

CalculateDlgChild3::CalculateDlgChild3(CWnd* pParent /*=NULL*/)
	: CDialog(CalculateDlgChild3::IDD, pParent)
{

}

CalculateDlgChild3::~CalculateDlgChild3()
{
}

void CalculateDlgChild3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_GATEWAY, m_comboGateway);
	DDX_Control(pDX, IDC_SPIN_RUN_PARS, m_spinRunPars);
}


BEGIN_MESSAGE_MAP(CalculateDlgChild3, CDialog)
END_MESSAGE_MAP()


// CalculateDlgChild3 message handlers


BOOL CalculateDlgChild3::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	// 设置控件初始状态
	this->m_comboGateway.AddString(_T("localhost"));
	this->m_comboGateway.SetCurSel(0);

	// 设置旋转按钮的伙伴编辑框框
	// 编辑框的ID可以通过一下方法获得
	// 通过ID或恶对话框上的控件，从而操作控件
	// 方法一：SetDlgItemText(IDC_EDIT1,strNumber);
	// 方法而：CEdit* edt=(CEdit*)GetDlgItem(IDC_EDIT1);edt->SetWindowText(strNumber);
	// 设置伙伴
	CEdit * tempEdit = (CEdit *)GetDlgItem(IDC_EDIT_RUN_PARS);
	//this->m_spinRunPars.SetBuddy(tempEdit);
	// 设置范围
	this->m_spinRunPars.SetRange(1,4);
	// 设置基值
	//this->m_spinRunPars.SetBase(1);
	// 
	this->m_spinRunPars.SetPos(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
