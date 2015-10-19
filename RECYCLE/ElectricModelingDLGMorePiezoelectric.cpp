// ElectricModelingDLGMorePiezoelectric.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGMorePiezoelectric.h"
#include "afxdialogex.h"


// ElectricModelingDLGMorePiezoelectric dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMorePiezoelectric, CDialog)

ElectricModelingDLGMorePiezoelectric::ElectricModelingDLGMorePiezoelectric(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMorePiezoelectric::IDD, pParent)
{

	m_PhaseCount = 0;
	m_simulationType = 0;
}

ElectricModelingDLGMorePiezoelectric::~ElectricModelingDLGMorePiezoelectric()
{
}

void ElectricModelingDLGMorePiezoelectric::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MORE_PIEZOELECTRIC, m_TabMorePiezoelectric);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMorePiezoelectric, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MORE_PIEZOELECTRIC, &ElectricModelingDLGMorePiezoelectric::OnTcnSelchangeTabMorePiezoelectric)
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGMorePiezoelectric::OnBnClickedOk)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

void ElectricModelingDLGMorePiezoelectric::SetPhaseCount( int phaseCount )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_PhaseCount = phaseCount;
}

void ElectricModelingDLGMorePiezoelectric::SetSimulationType( int simulationType )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_simulationType = simulationType;
}

// ElectricModelingDLGMorePiezoelectric message handlers


BOOL ElectricModelingDLGMorePiezoelectric::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	CString str;
	TCITEM temp[6];
	CRect tabRect;
	m_TabMorePiezoelectric.GetClientRect(&tabRect);
	// 定位选项卡位置
	tabRect.bottom -=8;
	tabRect.left +=8;
	tabRect.top +=18;
	tabRect.right-=8;
	for (int i=0;i<this->m_PhaseCount;i++)
	{
		temp[i].mask=TCIF_TEXT;
		str.Format("%s%d","Phase No.",i+1);
		temp[i].pszText=_T((LPSTR)(LPCTSTR)str);
		m_TabMorePiezoelectric.InsertItem(i,&temp[i]);
		// 利用一个模版创建多个子对话框
		m_electricModelingDLGPiezoelectric[i].Create(IDD_MODELING_DLG_PIEZOELECTRIC,GetDlgItem(IDC_TAB_MORE_PIEZOELECTRIC));
		m_electricModelingDLGPiezoelectric[i].m_StaticPiezoPropertiesPHNox.SetWindowTextA(str);
		// 将子对话框移动到指定的位置
		m_electricModelingDLGPiezoelectric[i].MoveWindow(&tabRect);

	}
	// simulation type 选择了Material response to an external field时加入相应的选项
	if (this->m_simulationType == 1){
		/*
		TCITEM mechanical;
		mechanical.mask = TCIF_TEXT;
		mechanical.pszText = "External Field mechanical";
		m_electricModelingDLGMechanical.Create(IDD_MODELING_DLG_MECHANICAL,GetDlgItem(IDC_TAB_MORE_PIEZOELECTRIC));
		m_TabMorePiezoelectric.InsertItem(m_PhaseCount,&mechanical);
		m_electricModelingDLGMechanical.MoveWindow(&tabRect);

		TCITEM external;
		external.mask = TCIF_TEXT;
		external.pszText = "External Field";
		m_electricModelingDLGExternal.Create(IDD_MODELING_DLG_EXTERNAL,GetDlgItem(IDC_TAB_MORE_PIEZOELECTRIC));
		m_TabMorePiezoelectric.InsertItem(m_PhaseCount+1,&external);
		m_electricModelingDLGExternal.MoveWindow(&tabRect);
		*/
		TCITEM child3;
		child3.mask = TCIF_TEXT;
		child3.pszText = "External Field";
		m_electricModelingDLGChild3.Create(IDD_MODELING_DLG_CHILD3,GetDlgItem(IDC_TAB_MORE_PIEZOELECTRIC));
		m_TabMorePiezoelectric.InsertItem(m_PhaseCount+1,&child3);
		m_electricModelingDLGChild3.MoveWindow(&tabRect);
	}
	m_electricModelingDLGPiezoelectric[0].ShowWindow(SW_SHOW);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGMorePiezoelectric::OnTcnSelchangeTabMorePiezoelectric(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	int cur = m_TabMorePiezoelectric.GetCurSel();
	if (cur >=0 && cur<m_PhaseCount){
		
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			if (i==cur){
				m_electricModelingDLGPiezoelectric[cur].ShowWindow(SW_SHOW);
			}else{
				m_electricModelingDLGPiezoelectric[i].ShowWindow(SW_HIDE);
			}
		}
		if (m_simulationType == 1){
			/*
			m_electricModelingDLGMechanical.ShowWindow(SW_HIDE);
			m_electricModelingDLGExternal.ShowWindow(SW_HIDE);
			*/
			m_electricModelingDLGChild3.ShowWindow(SW_HIDE);
		}
	}else if (cur ==this->m_PhaseCount){
		/*
		m_electricModelingDLGMechanical.ShowWindow(SW_SHOW);
		m_electricModelingDLGExternal.ShowWindow(SW_HIDE);
		*/
		m_electricModelingDLGChild3.ShowWindow(SW_SHOW);
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			m_electricModelingDLGPiezoelectric[i].ShowWindow(SW_HIDE);
		}
	}else if (cur==this->m_PhaseCount+1){
		m_electricModelingDLGMechanical.ShowWindow(SW_HIDE);
		m_electricModelingDLGExternal.ShowWindow(SW_SHOW);
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			m_electricModelingDLGPiezoelectric[i].ShowWindow(SW_HIDE);
		}
	}


	*pResult = 0;
}


void ElectricModelingDLGMorePiezoelectric::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		m_electricModelingDLGPiezoelectric[i].UpdateData(TRUE);
	}
	CDialog::OnOK();
}


void ElectricModelingDLGMorePiezoelectric::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		m_electricModelingDLGPiezoelectric[i].UpdateData(TRUE);
	}
	CDialog::OnClose();
}
