// PMPVisualizationDLG.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "PMPVisualizationDLG.h"
#include "afxdialogex.h"


// CPMPVisualizationDLG dialog

IMPLEMENT_DYNAMIC(CPMPVisualizationDLG, CDialog)

CPMPVisualizationDLG::CPMPVisualizationDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CPMPVisualizationDLG::IDD, pParent)
{

	m_list_visualizationtype_string = _T("");
	m_list_visualizationtype_int = 0;
	m_visualization_type = 0;
	m_caption = _T("Visualization type");
	m_combo_volume_int = 0;
}

CPMPVisualizationDLG::~CPMPVisualizationDLG()
{
}

void CPMPVisualizationDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_VISUALIZATIONTYPE, m_ListVisualizationtype);
	DDX_LBString(pDX, IDC_LIST_VISUALIZATIONTYPE, m_list_visualizationtype_string);
	DDX_LBIndex(pDX, IDC_LIST_VISUALIZATIONTYPE, m_list_visualizationtype_int);
	DDX_Control(pDX, IDC_COMBO_VOLUME, m_ComboVolume);
	DDX_CBIndex(pDX, IDC_COMBO_VOLUME, m_combo_volume_int);
	DDV_MinMaxInt(pDX, m_combo_volume_int, 0, 5);
}


BEGIN_MESSAGE_MAP(CPMPVisualizationDLG, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST_VISUALIZATIONTYPE, &CPMPVisualizationDLG::OnLbnSelchangeListVisualizationtype)
	ON_BN_CLICKED(IDOK, &CPMPVisualizationDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// CPMPVisualizationDLG message handlers


BOOL CPMPVisualizationDLG::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	// 张量数据给出的绘图选项
	if(m_visualization_type == 3){
		m_ListVisualizationtype.InsertString(0,_T("Tensor"));
		m_ListVisualizationtype.InsertString(1,_T("Multiview"));
		m_ListVisualizationtype.InsertString(2,_T("Volume"));
		m_ListVisualizationtype.SetCurSel(m_list_visualizationtype_int);

		m_ComboVolume.InsertString(0,_T("11"));
		m_ComboVolume.InsertString(1,_T("22"));
		m_ComboVolume.InsertString(2,_T("33"));
		m_ComboVolume.InsertString(3,_T("23"));
		m_ComboVolume.InsertString(4,_T("13"));
		m_ComboVolume.InsertString(5,_T("12"));
		m_ComboVolume.SetCurSel(m_combo_volume_int);
		m_ComboVolume.ShowWindow(SW_HIDE);
	}
	// 向量数据给出的绘图选项
	if(m_visualization_type == 2){
		m_ListVisualizationtype.InsertString(0,_T("Vector"));
		m_ListVisualizationtype.InsertString(1,_T("Streamline"));
		m_ListVisualizationtype.InsertString(2,_T("Volume"));
		m_ListVisualizationtype.SetCurSel(m_list_visualizationtype_int);

		m_ComboVolume.InsertString(0,"1");
		m_ComboVolume.InsertString(1,"2");
		m_ComboVolume.InsertString(2,"3");
		m_ComboVolume.SetCurSel(m_combo_volume_int);
		m_ComboVolume.ShowWindow(SW_HIDE);
	}
	// 标量数据给出绘图选项
	if(m_visualization_type == 1){
		m_ListVisualizationtype.InsertString(0,_T("Scalar"));
		m_ListVisualizationtype.InsertString(1,_T("Volume"));
		m_ListVisualizationtype.SetCurSel(m_list_visualizationtype_int);

		m_ComboVolume.InsertString(0,_T("1"));
		m_ComboVolume.SetCurSel(m_combo_volume_int);
		m_ComboVolume.ShowWindow(SW_HIDE);
	}

	this->SetWindowTextA(this->m_caption);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CPMPVisualizationDLG::OnLbnSelchangeListVisualizationtype()
{
	// TODO: Add your control notification handler code here
	CString tempstr;
	int temp ;
	int count = m_ListVisualizationtype.GetCount();
	temp = m_ListVisualizationtype.GetCurSel();
	m_ListVisualizationtype.GetText(temp,tempstr);
	if ( temp== count -1)
	{
		this->m_ComboVolume.ShowWindow(SW_SHOW);
		
	}else{
		this->m_ComboVolume.ShowWindow(SW_HIDE);
	}
}


void CPMPVisualizationDLG::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	this->UpdateData(TRUE);

	CDialog::OnOK();
}
