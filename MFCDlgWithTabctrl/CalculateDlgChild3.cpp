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

	// ���ÿؼ���ʼ״̬
	this->m_comboGateway.AddString(_T("localhost"));
	this->m_comboGateway.SetCurSel(0);

	// ������ת��ť�Ļ��༭���
	// �༭���ID����ͨ��һ�·������
	// ͨ��ID���Ի����ϵĿؼ����Ӷ������ؼ�
	// ����һ��SetDlgItemText(IDC_EDIT1,strNumber);
	// ��������CEdit* edt=(CEdit*)GetDlgItem(IDC_EDIT1);edt->SetWindowText(strNumber);
	// ���û��
	CEdit * tempEdit = (CEdit *)GetDlgItem(IDC_EDIT_RUN_PARS);
	//this->m_spinRunPars.SetBuddy(tempEdit);
	// ���÷�Χ
	this->m_spinRunPars.SetRange(1,4);
	// ���û�ֵ
	//this->m_spinRunPars.SetBase(1);
	// 
	this->m_spinRunPars.SetPos(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
