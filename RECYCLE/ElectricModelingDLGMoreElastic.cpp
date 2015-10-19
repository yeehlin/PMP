// ElectricModelingDLGMoreElastic.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGMoreElastic.h"
#include "afxdialogex.h"


// ElectricModelingDLGMoreElastic dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMoreElastic, CDialog)

ElectricModelingDLGMoreElastic::ElectricModelingDLGMoreElastic(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMoreElastic::IDD, pParent)
{

	m_simulationType = 0;
}

ElectricModelingDLGMoreElastic::~ElectricModelingDLGMoreElastic()
{
}

void ElectricModelingDLGMoreElastic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MORE_ELASTIC, m_TabMoreElastic);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMoreElastic, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MORE_ELASTIC, &ElectricModelingDLGMoreElastic::OnTcnSelchangeTabMoreElastic)
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGMoreElastic::OnBnClickedOk)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

void ElectricModelingDLGMoreElastic::SetPhaseCount( int phaseCount )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_PhaseCount = phaseCount;
}

void ElectricModelingDLGMoreElastic::SetSimulationType( int simulationType )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_simulationType = simulationType;
}



// ElectricModelingDLGMoreElastic message handlers


BOOL ElectricModelingDLGMoreElastic::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	// 是构造函数先被调用吗？（是的）
	/*
	CString temp;
	temp.Format("%d",this->m_PhaseCount);
	::MessageBox(NULL,_T("进入OnInitDialog"+temp),_T("OKOK"),MB_OK);
	*/
	CString str;
	TCITEM temp[6];
	CRect tabRect;
	m_TabMoreElastic.GetClientRect(&tabRect);
	// 定位选项卡位置
	tabRect.bottom -=8;
	tabRect.left +=8;
	tabRect.top +=20;
	tabRect.right-=8;
	for (int i=0;i<this->m_PhaseCount;i++)
	{
		temp[i].mask=TCIF_TEXT;
		str.Format("%s%d","Phase No.",i+1);
		temp[i].pszText=_T((LPSTR)(LPCTSTR)str);
		m_TabMoreElastic.InsertItem(i,&temp[i]);
		// 利用一个模版创建多个子对话框
		m_electricModelingDLGElastic[i].Create(IDD_MODELING_DLG_ELASTIC,GetDlgItem(IDC_TAB_MORE_ELASTIC));
		//m_electricModelingDLGElastic[i].SetParent(GetDlgItem(IDC_TAB_MORE_ELASTIC));
		m_electricModelingDLGElastic[i].m_StaticPropertisPHNox.SetWindowTextA(str);
		// 将子对话框移动到指定的位置
		m_electricModelingDLGElastic[i].MoveWindow(&tabRect);

	}
	// simulation type 选择了Material response to an external field时加入相应的选项
	if (this->m_simulationType == 1){
		TCITEM mechanical;
		mechanical.mask = TCIF_TEXT;
		mechanical.pszText = "External Field mechanical";
		m_electricModelingDLGMechanical.Create(IDD_MODELING_DLG_MECHANICAL,GetDlgItem(IDC_TAB_MORE_ELASTIC));
		m_TabMoreElastic.InsertItem(m_PhaseCount,&mechanical);
		m_electricModelingDLGMechanical.MoveWindow(&tabRect);
		m_electricModelingDLGMechanical.ShowWindow(SW_HIDE);
	}
	m_electricModelingDLGElastic[0].ShowWindow(SW_SHOW);
	for (int i =1;i<m_PhaseCount;i++)
	{
		m_electricModelingDLGElastic[i].ShowWindow(SW_HIDE);
	}






	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGMoreElastic::OnTcnSelchangeTabMoreElastic(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	/*
	switch (m_TabMoreElastic.GetCurSel())
	{
	case 0:
		m_electricModelingDLGElastic[0].ShowWindow(SW_SHOW);
		m_electricModelingDLGElastic[1].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[2].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[3].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[4].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[5].ShowWindow(SW_HIDE);
		break;
	case 1:
		m_electricModelingDLGElastic[0].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[1].ShowWindow(SW_SHOW);
		m_electricModelingDLGElastic[2].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[3].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[4].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[5].ShowWindow(SW_HIDE);
		break;
	case 2:
		m_electricModelingDLGElastic[0].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[1].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[2].ShowWindow(SW_SHOW);
		m_electricModelingDLGElastic[3].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[4].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[5].ShowWindow(SW_HIDE);
		break;
	case 3:
		m_electricModelingDLGElastic[0].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[1].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[2].ShowWindow(SW_SHOW);
		m_electricModelingDLGElastic[3].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[4].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[5].ShowWindow(SW_HIDE);
		break;
	case 4:
		m_electricModelingDLGElastic[0].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[1].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[2].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[3].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[4].ShowWindow(SW_SHOW);
		m_electricModelingDLGElastic[5].ShowWindow(SW_HIDE);
		break;
	case 5:
		m_electricModelingDLGElastic[0].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[1].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[2].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[3].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[4].ShowWindow(SW_HIDE);
		m_electricModelingDLGElastic[5].ShowWindow(SW_SHOW);
		break;
	}
	*/
	int cur = m_TabMoreElastic.GetCurSel();
	CString curstr;
	curstr.Format("%d",cur);
	//::MessageBox(NULL,curstr,_T("OKOK"),MB_OK);
	if (cur >=0 && cur <m_PhaseCount){
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			if (i==cur){
				m_electricModelingDLGElastic[cur].ShowWindow(SW_SHOW);
			}else{
				m_electricModelingDLGElastic[i].ShowWindow(SW_HIDE);
			}
		}
		// 
		if (m_simulationType == 1){
			m_electricModelingDLGMechanical.ShowWindow(SW_HIDE);
		}
	}
	else if (cur==this->m_PhaseCount){
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			m_electricModelingDLGElastic[i].ShowWindow(SW_HIDE);
		}
		m_electricModelingDLGMechanical.ShowWindow(SW_SHOW);
	}

	*pResult = 0;
}


void ElectricModelingDLGMoreElastic::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		m_electricModelingDLGElastic[i].UpdateData(TRUE);
	
	}


	CDialog::OnOK();
}


void ElectricModelingDLGMoreElastic::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		m_electricModelingDLGElastic[i].UpdateData(TRUE);

	}
	CDialog::OnClose();
}
