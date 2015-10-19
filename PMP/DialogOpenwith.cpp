// DialogOpenwith.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "DialogOpenwith.h"
#include "afxdialogex.h"


// CDialogOpenwith dialog

IMPLEMENT_DYNAMIC(CDialogOpenwith, CDialog)

CDialogOpenwith::CDialogOpenwith(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogOpenwith::IDD, pParent)
{

	//  m_list_openwith = _T("");
	m_list_openwith_string = _T("");
	m_list_openwith_int = 0;
}

CDialogOpenwith::~CDialogOpenwith()
{
}

void CDialogOpenwith::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_OPENWITH, m_ListOpenwith);
	//  DDX_LBString(pDX, IDC_LIST_OPENWITH, m_list_openwith);
	DDX_LBString(pDX, IDC_LIST_OPENWITH, m_list_openwith_string);
	DDX_LBIndex(pDX, IDC_LIST_OPENWITH, m_list_openwith_int);
}


BEGIN_MESSAGE_MAP(CDialogOpenwith, CDialog)
END_MESSAGE_MAP()


// CDialogOpenwith message handlers


BOOL CDialogOpenwith::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	m_ListOpenwith.AddString("notepad");
	m_ListOpenwith.AddString("Windows picture and Fax Viewer");
	m_ListOpenwith.SetCurSel(m_list_openwith_int);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
