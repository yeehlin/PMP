// ScaleFactorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ScaleFactorDlg.h"
#include "afxdialogex.h"


// CScaleFactorDlg dialog

IMPLEMENT_DYNAMIC(CScaleFactorDlg, CDialog)

CScaleFactorDlg::CScaleFactorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScaleFactorDlg::IDD, pParent)
{

	m_edit_scale_factor = 0.0;
	m_caption=_T("Scale Factor");
	fadefault = 0.0;
}

CScaleFactorDlg::~CScaleFactorDlg()
{
}

void CScaleFactorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SCALE_FACTOR, m_edit_scale_factor);
}


BEGIN_MESSAGE_MAP(CScaleFactorDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SCALEFACTOR_DEFAULT, &CScaleFactorDlg::OnClickedButtonScalefactorDefault)
END_MESSAGE_MAP()


// CScaleFactorDlg message handlers


BOOL CScaleFactorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	this->SetWindowTextA(m_caption);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CScaleFactorDlg::OnClickedButtonScalefactorDefault()
{
	// TODO: Add your control notification handler code here
	CString str;
	str.Format("%g",fadefault);
	((CEdit *)GetDlgItem(IDC_EDIT_SCALE_FACTOR))->SetWindowTextA(str);
}
