// IsosurfaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "IsosurfaceDlg.h"
#include "afxdialogex.h"


// CIsosurfaceDlg dialog

IMPLEMENT_DYNAMIC(CIsosurfaceDlg, CDialog)

CIsosurfaceDlg::CIsosurfaceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIsosurfaceDlg::IDD, pParent)
{

	m_edit_min_iso_value_double = 0.0;
	m_edit_max_iso_value_double = 100;
	m_edit_cur_value_double = m_edit_min_iso_value_double;
}

CIsosurfaceDlg::~CIsosurfaceDlg()
{
}

void CIsosurfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MIN_ISO_VALUE, m_edit_min_iso_value_double);
	DDX_Text(pDX, IDC_EDIT_MAX_ISO_VALUE, m_edit_max_iso_value_double);
	DDX_Control(pDX, IDC_SLIDER_ISOSURFACE, m_SliderIsofurface);
	DDX_Text(pDX, IDC_EDIT_CUR_VALUE, m_edit_cur_value_double);
}


BEGIN_MESSAGE_MAP(CIsosurfaceDlg, CDialog)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_ISOSURFACE, &CIsosurfaceDlg::OnNMCustomdrawSliderIsosurface)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CIsosurfaceDlg message handlers


BOOL CIsosurfaceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	m_SliderIsofurface.SetRange(0,100);
	m_SliderIsofurface.SetTicFreq(10);

	int n = int(m_edit_cur_value_double);
	CString str ;
	str.Format("%e %d",m_edit_cur_value_double,n);
	//::MessageBox(NULL,_T(str),_T("OK"),MB_OK);
	m_SliderIsofurface.SetPos(n);

	m_SliderIsofurface.SetLineSize(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CIsosurfaceDlg::OnNMCustomdrawSliderIsosurface(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	//UpdateData(TRUE);
	int pos = m_SliderIsofurface.GetPos();
	m_edit_cur_value_double = m_edit_min_iso_value_double+(pos/100.0)*(m_edit_max_iso_value_double-m_edit_min_iso_value_double);
	CString str;
	str.Format("%g",m_edit_cur_value_double);
	SetDlgItemText(IDC_EDIT_CUR_VALUE,str);
	UpdateData(TRUE);
	*pResult = 0;
}


void CIsosurfaceDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	CSliderCtrl * temp = (CSliderCtrl *)GetDlgItem(IDC_SLIDER_ISOSURFACE);
	int n =temp->GetPos();
	m_edit_cur_value_double = m_edit_min_iso_value_double+(m_SliderIsofurface.GetPos()/100.0)*(m_edit_max_iso_value_double-m_edit_min_iso_value_double);
	CString str;
	str.Format("%g",m_edit_cur_value_double);
	SetDlgItemText(IDC_EDIT_CUR_VALUE,str);
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
