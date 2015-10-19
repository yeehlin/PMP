// IsosurfaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "IsosurfaceDlg.h"
#include "afxdialogex.h"


// CIsosurfaceDlg dialog

IMPLEMENT_DYNAMIC(CIsosurfaceDlg, CDialog)

CIsosurfaceDlg::CIsosurfaceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIsosurfaceDlg::IDD, pParent)
{

	m_edit_min_iso_value_double = 0.0;
	m_edit_max_iso_value_double = 0.0;
	m_edit_cur_iso_value_double = 0.0;
	m_edit_cur_iso_value2 = 0.0;
	m_edit_min_opa_value_double = 0.0;
	m_edit_max_opa_value_double = 1.0;
	m_edit_cur_opa_value_double = 0.5;
	m_edit_cur_opa_value2_double = 0.7;
	m_caption = _T("Set isosurface value");
}

CIsosurfaceDlg::~CIsosurfaceDlg()
{
}

void CIsosurfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_ISOSURFACE, m_SliderIsosurface);
	DDX_Text(pDX, IDC_EDIT_MIN_ISO_VALUE, m_edit_min_iso_value_double);
	DDX_Text(pDX, IDC_EDIT_MAX_ISO_VALUE, m_edit_max_iso_value_double);
	DDX_Text(pDX, IDC_EDIT_CUR_ISO_VALUE, m_edit_cur_iso_value_double);
	DDX_Text(pDX, IDC_EDIT_CUR_ISO_VALUE2, m_edit_cur_iso_value2);
	DDX_Control(pDX, IDC_SLIDER_ISOSURFACE2, m_SliderIsosurface2);
	DDX_Text(pDX, IDC_EDIT_MIN_OPA_VALUE, m_edit_min_opa_value_double);
	DDV_MinMaxDouble(pDX, m_edit_min_opa_value_double, 0, 1);
	DDX_Text(pDX, IDC_EDIT_MAX_OPA_VALUE, m_edit_max_opa_value_double);
	DDV_MinMaxDouble(pDX, m_edit_max_opa_value_double, 0, 1);
	DDX_Control(pDX, IDC_SLIDER_OPACITY, m_SliderOpacity);
	DDX_Control(pDX, IDC_SLIDER_OPACITY2, m_SliderOpacity2);
	DDX_Text(pDX, IDC_EDIT_CUR_OPA_VALUE, m_edit_cur_opa_value_double);
	DDV_MinMaxDouble(pDX, m_edit_cur_opa_value_double, 0, 1);
	DDX_Text(pDX, IDC_EDIT_CUR_OPA_VLAUE2, m_edit_cur_opa_value2_double);
	DDV_MinMaxDouble(pDX, m_edit_cur_opa_value2_double, 0, 1);
}


BEGIN_MESSAGE_MAP(CIsosurfaceDlg, CDialog)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_ISOSURFACE, &CIsosurfaceDlg::OnNMCustomdrawSliderIsosurface)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_ISOSURFACE2, &CIsosurfaceDlg::OnNMCustomdrawSliderIsosurface2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_OPACITY, &CIsosurfaceDlg::OnNMCustomdrawSliderOpacity)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_OPACITY2, &CIsosurfaceDlg::OnNMCustomdrawSliderOpacity2)
END_MESSAGE_MAP()


// CIsosurfaceDlg message handlers


BOOL CIsosurfaceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	// 对于等值面值
	m_SliderIsosurface.SetRange(0,100);
	m_SliderIsosurface.SetTicFreq(5);
	int pos = int(((m_edit_cur_iso_value_double-m_edit_min_iso_value_double)/(m_edit_max_iso_value_double-m_edit_min_iso_value_double))*100.0);
	m_SliderIsosurface.SetPos(pos);

	m_SliderIsosurface2.SetRange(0,100);
	m_SliderIsosurface2.SetTicFreq(5);
	int pos2 = int(((m_edit_cur_iso_value2-m_edit_min_iso_value_double)/(m_edit_max_iso_value_double-m_edit_min_iso_value_double))*100.0);
	m_SliderIsosurface2.SetPos(pos2);

	//对于透明值
	m_SliderOpacity.SetRange(0,100);
	m_SliderOpacity.SetTicFreq(5);
	int pos3 = int(((m_edit_cur_opa_value_double-m_edit_min_opa_value_double)/(m_edit_max_opa_value_double-m_edit_min_opa_value_double))*100.0);
	m_SliderOpacity.SetPos(pos3);

	m_SliderOpacity2.SetRange(0,100);
	m_SliderOpacity2.SetTicFreq(5);
	int pos4 = int(((m_edit_cur_opa_value2_double-m_edit_min_opa_value_double)/(m_edit_max_opa_value_double-m_edit_min_opa_value_double))*100.0);
	m_SliderOpacity2.SetPos(pos4);
	// 设置标题
	this->SetWindowText(m_caption);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CIsosurfaceDlg::OnNMCustomdrawSliderIsosurface(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SliderIsosurface.GetPos();
	m_edit_cur_iso_value_double = m_edit_min_iso_value_double+(pos/100.0)*(m_edit_max_iso_value_double-m_edit_min_iso_value_double);
	CString str;
	str.Format("%g",m_edit_cur_iso_value_double);
	SetDlgItemText(IDC_EDIT_CUR_ISO_VALUE,str);
	UpdateData(FALSE);


	*pResult = 0;
}


void CIsosurfaceDlg::OnNMCustomdrawSliderIsosurface2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	int pos = m_SliderIsosurface2.GetPos();
	m_edit_cur_iso_value2 = m_edit_min_iso_value_double+(pos/100.0)*(m_edit_max_iso_value_double-m_edit_min_iso_value_double);
	CString str;
	str.Format("%g",m_edit_cur_iso_value2);
	SetDlgItemText(IDC_EDIT_CUR_ISO_VALUE2,str);
	UpdateData(TRUE);
	*pResult = 0;
}


void CIsosurfaceDlg::OnNMCustomdrawSliderOpacity(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SliderOpacity.GetPos();
	m_edit_cur_opa_value_double = m_edit_min_opa_value_double+(pos/100.0)*(m_edit_max_opa_value_double-m_edit_min_opa_value_double);
	CString str;
	str.Format("%g",m_edit_cur_opa_value_double);
	SetDlgItemText(IDC_EDIT_CUR_OPA_VALUE,str);
	UpdateData(FALSE);
	*pResult = 0;
}


void CIsosurfaceDlg::OnNMCustomdrawSliderOpacity2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int pos = m_SliderOpacity2.GetPos();
	m_edit_cur_opa_value2_double = m_edit_min_opa_value_double+(pos/100.0)*(m_edit_max_opa_value_double-m_edit_min_opa_value_double);
	CString str;
	str.Format("%g",m_edit_cur_opa_value_double);
	SetDlgItemText(IDC_EDIT_CUR_OPA_VLAUE2,str);
	UpdateData(FALSE);
	*pResult = 0;
}
