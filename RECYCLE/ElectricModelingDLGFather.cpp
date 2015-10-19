// ElectricModelingDLGFather.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGFather.h"
#include "afxdialogex.h"


// ElectricModelingDLGFather dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGFather, CDialog)

ElectricModelingDLGFather::ElectricModelingDLGFather(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGFather::IDD, pParent)
{

	//currentSelectedTab = 0;
}

ElectricModelingDLGFather::~ElectricModelingDLGFather()
{
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
	/* ���tabҳ
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
	// ���Tab�ؼ������꣬���ڷ���ѡ�
	CRect tabRect;
	m_tab.GetClientRect(&tabRect);
	// ��λѡ�λ��
	tabRect.bottom -=8;
	tabRect.left +=8;
	tabRect.top +=20;
	tabRect.right-=8;
	//*/ �����ӶԻ���
	m_electricModelingDLGChild1.Create(IDD_MODELING_DLG_CHILD1,GetDlgItem(IDC_MODELING_DLG_TAB));
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
	// ���ӶԻ����ƶ���ָ����λ��
	m_electricModelingDLGChild1.MoveWindow(&tabRect);
	/*
	m_electricModelingDLGChild2.MoveWindow(&tabRect);
	m_electricModelingDLGPhaseNo2.MoveWindow(&tabRect);
	m_electricModelingDLGPhaseNo3.MoveWindow(&tabRect);
	m_electricModelingDLGPhaseNo4.MoveWindow(&tabRect);
	m_electricModelingDLGPhaseNo5.MoveWindow(&tabRect);
	m_electricModelingDLGPhaseNo6.MoveWindow(&tabRect);
	m_electricModelingDLGChild3.MoveWindow(&tabRect);

	//�ѶԻ������ָ�뱣������
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

	// ��ʾ��ҳ�棬���ǻ��Ƶ�һ���ӶԻ��򣬶���������������
	m_electricModelingDLGChild1.ShowWindow(SW_SHOW);
	/*
	m_electricModelingDLGChild2.ShowWindow(SW_HIDE);
	m_electricModelingDLGPhaseNo2.ShowWindow(SW_HIDE);
	m_electricModelingDLGPhaseNo3.ShowWindow(SW_HIDE);
	m_electricModelingDLGPhaseNo4.ShowWindow(SW_HIDE);
	m_electricModelingDLGPhaseNo5.ShowWindow(SW_HIDE);
	m_electricModelingDLGPhaseNo6.ShowWindow(SW_HIDE);
	m_electricModelingDLGChild3.ShowWindow(SW_HIDE);
	//*/


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGFather::OnTcnSelchangeModelingDlgTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here


		// ���Ի����ϵ�tab�ؼ���Ϣ��Ӧ����
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
		// ��ʾ��һ���ӶԻ������������ӶԻ���
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
		// ��ʾ��һ���ӶԻ������������ӶԻ���
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
		// ��ʾ��һ���ӶԻ������������ӶԻ���
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
		// ��֪�������ʲô
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
	// ���տؼ����ݵ���Ա����
	m_electricModelingDLGChild1.UpdateData(TRUE);
	/*
	m_electricModelingDLGChild2.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo2.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo3.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo4.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo5.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo6.UpdateData(TRUE);
	//*/

	/*
	// �������º󣬶����е�ֵ
	//::MessageBox(NULL,_T(m_electricModelingDLGChild1.m_combo_sys_type),_T("OKOK"),MB_OK);
	CString temp;
	temp.Format("%d",m_electricModelingDLGChild1.m_combo_sys_type_int);
	::MessageBox(NULL,_T(temp),_T("OKOK"),MB_OK);
	*/
	// ��ť����ΪΪ
	CDialog::OnOK();
}


// �ӿڣ��ýӿڹ�ElectricModelingDLGFather�����������е���������д���ļ�
// ��ʲô����д�룬��ʲô���ĸ�ʽд�룬�����ٴν���
void ElectricModelingDLGFather::PersistenceParameter(void)
{
	CString str;
	CStdioFile input;
	input.Open("parameter.in",CFile::modeWrite | CFile::modeCreate | CFile::typeText);
	str.Format("%d %d %d                                           !nx ny nz\n",
		m_electricModelingDLGChild1.m_edit_mesh_nx,this->m_electricModelingDLGChild1.m_edit_mesh_ny,this->m_electricModelingDLGChild1.m_edit_mesh_nz);
	input.WriteString(str);
	str.Format("%d %d %d                                           !lx ly lz\n",m_electricModelingDLGChild1.m_edit_size_lx,m_electricModelingDLGChild1.m_edit_size_ly,m_electricModelingDLGChild1.m_edit_size_lz);
	input.WriteString(str);
	str.Format("%d %d                                                    !ns nf\n",0,0);
	input.WriteString(str);
	str.Format("%d                                                            !total # of phases\n",m_electricModelingDLGChild1.m_edit_nums_phases);
	input.WriteString(str);

	input.Close();
}


void ElectricModelingDLGFather::OnBnClickedButtonAddTab()
{
	// TODO: Add your control notification handler code here
	// �����ڶԻ��򴴽���������ĶԻ�������
	TCITEM temp ;
	temp.mask = TCIF_TEXT;
	temp.pszText = _T("temptab");
	this->m_tab.InsertItem(5,&temp);
}


void ElectricModelingDLGFather::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	// ���տؼ����ݵ���Ա����
	// �û��ر�����Ի���ͬ���������������û������δ����
	m_electricModelingDLGChild1.UpdateData(TRUE);
	/*
	m_electricModelingDLGChild2.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo2.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo3.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo4.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo5.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo6.UpdateData(TRUE);
	//*/

	CDialog::OnClose();
}

/*
void ElectricModelingDLGFather::OnBnClickedOk2()
{
	// TODO: Add your control notification handler code here

	// ���տؼ����ݵ���Ա����
	m_electricModelingDLGChild1.UpdateData(TRUE);
	/*
	m_electricModelingDLGChild2.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo2.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo3.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo4.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo5.UpdateData(TRUE);
	m_electricModelingDLGPhaseNo6.UpdateData(TRUE);
	

	CDialog::OnOK();
}
*/