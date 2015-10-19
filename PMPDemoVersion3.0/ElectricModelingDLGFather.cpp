// ElectricModelingDLGFather.cpp : implementation file
//

#include "stdafx.h"
#include "VTKMFCCreateBMPActors.h"
#include "ElectricModelingDLGFather.h"
#include "afxdialogex.h"


// ElectricModelingDLGFather dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGFather, CDialog)

ElectricModelingDLGFather::ElectricModelingDLGFather(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGFather::IDD, pParent)
{

	m_pelectricModelingDLGChild1 = new ElectricModelingDLGChild1();
	m_caption =_T("Dialog");
	//currentSelectedTab = 0;
}

ElectricModelingDLGFather::~ElectricModelingDLGFather()
{
	// 关闭窗口会销毁对象吗
	//::MessageBox(NULL,_T("DLGFather"),_T("OKOK"),MB_OK);
	if (m_pelectricModelingDLGChild1 != NULL)
	{
		delete m_pelectricModelingDLGChild1;
	}
}

void ElectricModelingDLGFather::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MODELING_DLG_TAB, m_tab);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGFather, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_MODELING_DLG_TAB, &ElectricModelingDLGFather::OnTcnSelchangeModelingDlgTab)
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGFather::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_ADD_TAB, &ElectricModelingDLGFather::OnBnClickedButtonAddTab)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_ELECTRIC_BUTTON_RUN, &ElectricModelingDLGFather::OnBnClickedElectricButtonRun)
	ON_BN_CLICKED(IDC_ELECTRIC_BUTTON_RUN_FILE, &ElectricModelingDLGFather::OnBnClickedElectricButtonRunFile)
	ON_BN_CLICKED(IDCANCEL, &ElectricModelingDLGFather::OnBnClickedCancel)
END_MESSAGE_MAP()


// ElectricModelingDLGFather message handlers


BOOL ElectricModelingDLGFather::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	TCITEM  tcitemsetup;
	/*
	TCITEM  tcitemphase1;
	TCITEM  tcitemphase2;
	TCITEM  tcitemphase3;
	TCITEM  tcitemphase4;
	TCITEM  tcitemphase5;
	TCITEM  tcitemphase6;
	TCITEM  tcitemexternal;
	//*/
	tcitemsetup.mask = TCIF_TEXT;
	tcitemsetup.pszText=_T("System Setup");
	this->m_tab.InsertItem(0,&tcitemsetup);
	/* 添加tab页
	tcitemphase1.mask = TCIF_TEXT;
	tcitemphase1.pszText=_T("Phase No.1");
	this->m_tab.InsertItem(1,&tcitemphase1);

	tcitemphase2.mask = TCIF_TEXT;
	tcitemphase2.pszText=_T("Phase No.2");
	this->m_tab.InsertItem(2,&tcitemphase2);

	tcitemphase3.mask = TCIF_TEXT;
	tcitemphase3.pszText=_T("Phase No.3");
	this->m_tab.InsertItem(3,&tcitemphase3);

	tcitemphase4.mask = TCIF_TEXT;
	tcitemphase4.pszText=_T("Phase No.4");
	this->m_tab.InsertItem(4,&tcitemphase4);

	tcitemphase5.mask = TCIF_TEXT;
	tcitemphase5.pszText=_T("Phase No.5");
	this->m_tab.InsertItem(5,&tcitemphase5);

	tcitemphase6.mask = TCIF_TEXT;
	tcitemphase6.pszText=_T("Phase No.6");
	this->m_tab.InsertItem(6,&tcitemphase6);

	tcitemexternal.mask = TCIF_TEXT;
	tcitemexternal.pszText=_T("External Field");
	this->m_tab.InsertItem(7,&tcitemexternal);
	//*/
	// 获得Tab控件的坐标，用于放置选项卡
	CRect tabRect;
	m_tab.GetClientRect(&tabRect);
	// 定位选项卡位置
	tabRect.bottom -=8;
	tabRect.left +=8;
	tabRect.top +=20;
	tabRect.right-=8;
	//*/ 创建子对话框
	if (m_pelectricModelingDLGChild1==NULL){
		m_pelectricModelingDLGChild1 = new ElectricModelingDLGChild1();
	}
	m_pelectricModelingDLGChild1->Create(IDD_MODELING_DLG_CHILD1,GetDlgItem(IDC_MODELING_DLG_TAB));
	/*
	m_electricModelingDLGChild2.Create(IDD_MODELING_DLG_CHILD2,GetDlgItem(IDC_MODELING_DLG_TAB));
	m_electricModelingDLGPhaseNo2.Create(IDD_MODELING_DLG_PHASE_NO2,GetDlgItem(IDC_MODELING_DLG_TAB));
	m_electricModelingDLGPhaseNo3.Create(IDD_MODELING_DLG_PHASE_NO3,GetDlgItem(IDC_MODELING_DLG_TAB));
	m_electricModelingDLGPhaseNo4.Create(IDD_MODELING_DLG_PHASE_NO4,GetDlgItem(IDC_MODELING_DLG_TAB));
	m_electricModelingDLGPhaseNo5.Create(IDD_MODELING_DLG_PHASE_NO5,GetDlgItem(IDC_MODELING_DLG_TAB));
	m_electricModelingDLGPhaseNo6.Create(IDD_MODELING_DLG_PHASE_NO6,GetDlgItem(IDC_MODELING_DLG_TAB));
	m_electricModelingDLGChild3.Create(IDD_MODELING_DLG_CHILD3,GetDlgItem(IDC_MODELING_DLG_TAB));

	m_electricModelingDLGChild1.m_pelectricModelingDLGChild2 = &m_electricModelingDLGChild2;
	m_electricModelingDLGChild1.m_pElectricModelingDLGPhaseNo2 = &m_electricModelingDLGPhaseNo2;
	m_electricModelingDLGChild1.m_pElectricModelingDLGPhaseNo3 = &m_electricModelingDLGPhaseNo3;
	m_electricModelingDLGChild1.m_pElectricModelingDLGPhaseNo4 = &m_electricModelingDLGPhaseNo4;
	m_electricModelingDLGChild1.m_pElectricModelingDLGPhaseNo5 = &m_electricModelingDLGPhaseNo5;
	m_electricModelingDLGChild1.m_pElectricModelingDLGPhaseNo6 = &m_electricModelingDLGPhaseNo6;
	m_electricModelingDLGChild1.m_pelectricModelingDLGChild3 = &m_electricModelingDLGChild3;
//	m_electricModelingDLGChild1.m_pelectricModelingDLGFather = this;
//*/
	// 将子对话框移动到指定的位置
	m_pelectricModelingDLGChild1->MoveWindow(&tabRect);
	/*
	m_electricModelingDLGChild2.MoveWindow(&tabRect);
	m_electricModelingDLGPhaseNo2.MoveWindow(&tabRect);
	m_electricModelingDLGPhaseNo3.MoveWindow(&tabRect);
	m_electricModelingDLGPhaseNo4.MoveWindow(&tabRect);
	m_electricModelingDLGPhaseNo5.MoveWindow(&tabRect);
	m_electricModelingDLGPhaseNo6.MoveWindow(&tabRect);
	m_electricModelingDLGChild3.MoveWindow(&tabRect);

	//把对话框对象指针保存起来
	//*
	modelingDlgChild[0] = &m_electricModelingDLGChild1;
	modelingDlgChild[1] = &m_electricModelingDLGChild2;
	modelingDlgChild[2] = &m_electricModelingDLGPhaseNo2;
	modelingDlgChild[3] = &m_electricModelingDLGPhaseNo3;
	modelingDlgChild[4] = &m_electricModelingDLGPhaseNo4;
	modelingDlgChild[5] = &m_electricModelingDLGPhaseNo5;
	modelingDlgChild[6] = &m_electricModelingDLGPhaseNo6;
	modelingDlgChild[7] = &m_electricModelingDLGChild3;
	//*/

	// 显示子页面，但是绘制第一个子对话框，而隐藏其他的两个
	m_pelectricModelingDLGChild1->ShowWindow(SW_SHOW);
	/*
	m_electricModelingDLGChild2.ShowWindow(SW_HIDE);
	m_electricModelingDLGPhaseNo2.ShowWindow(SW_HIDE);
	m_electricModelingDLGPhaseNo3.ShowWindow(SW_HIDE);
	m_electricModelingDLGPhaseNo4.ShowWindow(SW_HIDE);
	m_electricModelingDLGPhaseNo5.ShowWindow(SW_HIDE);
	m_electricModelingDLGPhaseNo6.ShowWindow(SW_HIDE);
	m_electricModelingDLGChild3.ShowWindow(SW_HIDE);
	//*/
	// 给对话框设置标题
	this->SetWindowTextA(m_caption);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGFather::OnTcnSelchangeModelingDlgTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here


		// 父对话框上的tab控件消息响应函数
	/*/
	modelingDlgChild[m_tab.GetCurSel()]->ShowWindow(SW_SHOW);

	for (int i = 0;i<=7;i++)
	{
		if (i!=m_tab.GetCurSel())
		modelingDlgChild[i]->ShowWindow(SW_HIDE);
	}
	//*/
	/*
	switch (m_tab.GetCurSel())
	{
	case 0:
		// 显示第一个子对话框，隐藏其他子对话框
		m_electricModelingDLGChild1.ShowWindow(SW_SHOW);
		m_electricModelingDLGChild2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo3.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo4.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo5.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo6.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild3.ShowWindow(SW_HIDE);
		break;
	case 1:
		// 显示第一个子对话框，隐藏其他子对话框
		m_electricModelingDLGChild1.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild2.ShowWindow(SW_SHOW);
		m_electricModelingDLGPhaseNo2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo3.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo4.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo5.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo6.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild3.ShowWindow(SW_HIDE);
		break;
	case 2:
		// 显示第一个子对话框，隐藏其他子对话框
		m_electricModelingDLGChild1.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo2.ShowWindow(SW_SHOW);
		m_electricModelingDLGPhaseNo3.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo4.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo5.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo6.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild3.ShowWindow(SW_HIDE);
		break;
	case 3:
		m_electricModelingDLGChild1.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo3.ShowWindow(SW_SHOW);
		m_electricModelingDLGPhaseNo4.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo5.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo6.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild3.ShowWindow(SW_HIDE);
		break;
	case 4:
		m_electricModelingDLGChild1.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo3.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo4.ShowWindow(SW_SHOW);
		m_electricModelingDLGPhaseNo5.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo6.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild3.ShowWindow(SW_HIDE);
		break;
	case 5:
		m_electricModelingDLGChild1.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo3.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo4.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo5.ShowWindow(SW_SHOW);
		m_electricModelingDLGPhaseNo6.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild3.ShowWindow(SW_HIDE);
		break;
	case 6:
		m_electricModelingDLGChild1.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo3.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo4.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo5.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo6.ShowWindow(SW_SHOW);
		m_electricModelingDLGChild3.ShowWindow(SW_HIDE);
		break;
	case 7:
		m_electricModelingDLGChild1.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo2.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo3.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo4.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo5.ShowWindow(SW_HIDE);
		m_electricModelingDLGPhaseNo6.ShowWindow(SW_HIDE);
		m_electricModelingDLGChild3.ShowWindow(SW_SHOW);
		break;
	default:
		// 不知道这里干什么
		break;
	}
	//*/


	*pResult = 0;
}


//BOOL ElectricModelingDLGFather::DestroyWindow()
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//	for (int i=0;i<=7;i++)
//	{
//		modelingDlgChild[i]->DestroyWindow();
//	}
//
//	return CDialog::DestroyWindow();
//}


void ElectricModelingDLGFather::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// 接收控件数据到成员变量
	m_pelectricModelingDLGChild1->UpdateData(TRUE);
	this->PersistenceParameter();
}


// 接口：该接口供ElectricModelingDLGFather对象将其所持有的输入数据写入文件
// 将什么参数写入，以什么样的格式写入，均可再次进行
void ElectricModelingDLGFather::PersistenceParameter(void)
{
	CString str;
	CStdioFile input;
	input.Open("parameter.in",CFile::modeWrite | CFile::modeCreate | CFile::typeText);
	// 写网格维数
	str.Format("%d         %d         %d\t\t!nx ny nz\n",
		m_pelectricModelingDLGChild1->m_edit_mesh_nx,this->m_pelectricModelingDLGChild1->m_edit_mesh_ny,this->m_pelectricModelingDLGChild1->m_edit_mesh_nz);
	input.WriteString(str);
	// 写系统大小
	str.Format("%d         %d         %d\t\t!lx ly lz\n",m_pelectricModelingDLGChild1->m_edit_size_lx,m_pelectricModelingDLGChild1->m_edit_size_ly,m_pelectricModelingDLGChild1->m_edit_size_lz);
	input.WriteString(str);
	// 写ns 和nf
	str.Format("%d         %d\t\t!ns nf\n",m_pelectricModelingDLGChild1->ns,m_pelectricModelingDLGChild1->nf);
	input.WriteString(str);
	// 写system type代号：np0 1-elastic 2-dielectric 3-piezoelectric       !tuy1
	str.Format("%d                                                                 !np0 1-elastic 2-dielectric 3-piezoelectric       !tuy1\n",m_pelectricModelingDLGChild1->m_combo_sys_type_int+1);
	input.WriteString(str);
	// 写phases总数
	str.Format("%d                                                                 !total # of phases\n",m_pelectricModelingDLGChild1->m_edit_nums_phases);
	input.WriteString(str);
	// 写输入文件格式代号:1-order parameter array 2-phase id array
	str.Format("%d                                                                 !np1: 1-order parameter array 2-phase id array\n",m_pelectricModelingDLGChild1->m_combo_file_format_int+1);
	input.WriteString(str);
	// 循环写入各phases的数据到文件
	int curSel = m_pelectricModelingDLGChild1->m_combo_sys_type_int;
	int phases = m_pelectricModelingDLGChild1->m_edit_nums_phases;
	switch (curSel)
	{
	case 0:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGElastic * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreElastic->m_pelectricModelingDLGElastic[i];
			// 写pphases序号
			str.Format("%d                                                                 !phase id\n",i);
			input.WriteString(str);
			// 写入c矩阵
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c11,c->m_edit_c12,c->m_edit_c13,c->m_edit_c14,c->m_edit_c15,c->m_edit_c16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c11,c->m_edit_c22,c->m_edit_c23,c->m_edit_c24,c->m_edit_c25,c->m_edit_c26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c31,c->m_edit_c32,c->m_edit_c33,c->m_edit_c34,c->m_edit_c35,c->m_edit_c36);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c41,c->m_edit_c42,c->m_edit_c43,c->m_edit_c44,c->m_edit_c45,c->m_edit_c46);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c51,c->m_edit_c52,c->m_edit_c53,c->m_edit_c54,c->m_edit_c55,c->m_edit_c56);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c61,c->m_edit_c62,c->m_edit_c63,c->m_edit_c64,c->m_edit_c65,c->m_edit_c66);
			input.WriteString(str);
		}
		break;
	case 1:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGDielectric * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMoreDielectric->m_pelectricModelingDLGDielectric[i];
			// 写pphases序号
			str.Format("%d                                                                 !phase id\n",i);
			input.WriteString(str);
			// 写入k矩阵
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_k11,c->m_edit_k12,c->m_edit_k13,c->m_edit_k22,c->m_edit_k23,c->m_edit_k33);
			input.WriteString(str);
		}
		break;
	case 2:
		for (int i = 0;i<phases;i++)
		{
			ElectricModelingDLGPiezoelectric * c = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGPiezoelectric[i];
			// 写pphases序号
			str.Format("%d                                                                 !phase id\n",i+1);
			input.WriteString(str);
			// 写入c矩阵
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!c tensor\n",c->m_edit_c11,c->m_edit_c12,c->m_edit_c13,c->m_edit_c14,c->m_edit_c15,c->m_edit_c16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c11,c->m_edit_c22,c->m_edit_c23,c->m_edit_c24,c->m_edit_c25,c->m_edit_c26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c31,c->m_edit_c32,c->m_edit_c33,c->m_edit_c34,c->m_edit_c35,c->m_edit_c36);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c41,c->m_edit_c42,c->m_edit_c43,c->m_edit_c44,c->m_edit_c45,c->m_edit_c46);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c51,c->m_edit_c52,c->m_edit_c53,c->m_edit_c54,c->m_edit_c55,c->m_edit_c56);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_c61,c->m_edit_c62,c->m_edit_c63,c->m_edit_c64,c->m_edit_c65,c->m_edit_c66);
			input.WriteString(str);
			// 写入k矩阵
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!epsil(kappa_r) tensor\n",c->m_edit_k11,c->m_edit_k12,c->m_edit_k13,c->m_edit_k22,c->m_edit_k23,c->m_edit_k33);
			input.WriteString(str);
			// 写入d矩阵
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t!piezoD tensor\n",c->m_edit_d11,c->m_edit_d12,c->m_edit_d13,c->m_edit_d14,c->m_edit_d15,c->m_edit_d16);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_d21,c->m_edit_d22,c->m_edit_d23,c->m_edit_d24,c->m_edit_d25,c->m_edit_d26);
			input.WriteString(str);
			str.Format("%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t\n",c->m_edit_d31,c->m_edit_d32,c->m_edit_d33,c->m_edit_d34,c->m_edit_d35,c->m_edit_d36);
			input.WriteString(str);
		}
		break;
	}
	// 写入simulation type
	str.Format("%d                                                                 !np2: 1-effective properties calculation 2-response to external field\n",m_pelectricModelingDLGChild1->m_combo_simulation_type_int+1);
	input.WriteString(str);
	// 写入elastic boundary condition: 0-applied strain 1-applied stress
	str.Format("%d                                                                 !elastic boundary condition: 0-applied strain 1-applied stress\n",m_pelectricModelingDLGChild1->m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGChild3->m_combo_bondary_condition_int);
	input.WriteString(str);
	// 写入applied strain/stress
	ElectricModelingDLGChild3 * temp = m_pelectricModelingDLGChild1->m_pelectricModelingDLGMorePiezoelectric->m_pelectricModelingDLGChild3;
	str.Format("%f\t\t%f\t\t%f\t\t%f\t\t%f\t\t%f\t\t\n",temp->m_edit_eo1,temp->m_edit_eo2,temp->m_edit_eo3,temp->m_edit_eo4,temp->m_edit_eo5,temp->m_edit_eo6);
	input.WriteString(str);
	// 写入applied electric field
	str.Format("%f\t\t%f\t\t%f\t\t\n",temp->m_edit_e1,temp->m_edit_e2,temp->m_edit_e3);
	input.WriteString(str);
	input.Close();
}


void ElectricModelingDLGFather::OnBnClickedButtonAddTab()
{
	// TODO: Add your control notification handler code here
	// 尝试在对话框创建出来后更改对话框的外观
	TCITEM temp ;
	temp.mask = TCIF_TEXT;
	temp.pszText = _T("temptab");
	this->m_tab.InsertItem(5,&temp);
}


void ElectricModelingDLGFather::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	// 接收控件数据到成员变量
	// 用户关闭输入对话框，同样保存数据以免用户误操作未保存
	m_pelectricModelingDLGChild1->UpdateData(TRUE);

	CDialog::OnClose();
}


	void ElectricModelingDLGFather::OnBnClickedElectricButtonRun()
{
	// TODO: Add your control notification handler code here

	WinExec(".\\piez\\pieze.exe parameter.in",SW_HIDE);
	CDialog::OnOK();
}


	void ElectricModelingDLGFather::OnBnClickedElectricButtonRunFile()
	{
		// TODO: Add your control notification handler code here

		CString FilePathName;
		CString temp;
		CFileDialog dlg(TRUE);///TRUE为OPEN对话框，FALSE为SAVE AS对话框
		if(dlg.DoModal()==IDOK){
			FilePathName=dlg.GetPathName();
			::MessageBox(NULL,_T(FilePathName),_T("Run from file"),MB_OK);
			temp.Format("%s %s",".\\piez\\pieze.exe",FilePathName);
			WinExec(temp,SW_HIDE);
		}

		CDialog::OnOK();

	}


	void ElectricModelingDLGFather::OnBnClickedCancel()
	{
		// TODO: Add your control notification handler code here
		CDialog::OnCancel();
	}
