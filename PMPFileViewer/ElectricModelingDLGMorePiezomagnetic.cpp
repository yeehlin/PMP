// ElectricModelingDLGMorePiezomagnetic.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "ElectricModelingDLGMorePiezomagnetic.h"
#include "afxdialogex.h"


// ElectricModelingDLGMorePiezomagnetic dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMorePiezomagnetic, CDialog)

ElectricModelingDLGMorePiezomagnetic::ElectricModelingDLGMorePiezomagnetic(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMorePiezomagnetic::IDD, pParent)
{

	m_caption =_T("Dialog");
	m_simulationType = 0;
	// 初始化指针
	// 初始状态numbers of phases为1，所以应该创建一个
	m_pelectricModelingDLGPiezomagnetic[0] = new ElectricModelingDLGPiezomagnetic();
	for (int i=1;i < 6;i++)
	{
		m_pelectricModelingDLGPiezomagnetic[i] = NULL;
	}

}

ElectricModelingDLGMorePiezomagnetic::~ElectricModelingDLGMorePiezomagnetic()
{
		// 在持有者的析构函数中销毁动态内存
	//*
	for (int i=0;i < 6;i++){
		if (m_pelectricModelingDLGPiezomagnetic[i] != NULL){
			delete m_pelectricModelingDLGPiezomagnetic[i];
		}
	}
	//*/
}

void ElectricModelingDLGMorePiezomagnetic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MORE_PIEZOMAGNETIC, m_TabMorePiezomagnetic);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMorePiezomagnetic, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MORE_PIEZOMAGNETIC, &ElectricModelingDLGMorePiezomagnetic::OnTcnSelchangeTabMorePiezomagnetic)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGMorePiezomagnetic::OnBnClickedOk)
END_MESSAGE_MAP()

void ElectricModelingDLGMorePiezomagnetic::SetPhaseCount( int phaseCount )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_PhaseCount = phaseCount;
}

void ElectricModelingDLGMorePiezomagnetic::SetSimulationType( int simulationType )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_simulationType = simulationType;
}


// ElectricModelingDLGMorePiezomagnetic message handlers


BOOL ElectricModelingDLGMorePiezomagnetic::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here


	CString str;
	CString properties="Properties of ";
	TCITEM temp[6];
	CRect tabRect;
	m_TabMorePiezomagnetic.GetClientRect(&tabRect);
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
		m_TabMorePiezomagnetic.InsertItem(i,&temp[i]);
		// 利用一个模版创建多个子对话框
		// 确保创建一次并持有对象
		if (m_pelectricModelingDLGPiezomagnetic[i] ==  NULL){
			// 很矛盾，如果没有则创建
			//::MessageBox(NULL,_T("DLGElastic分配内存"),_T("OKOK"),MB_OK);
			m_pelectricModelingDLGPiezomagnetic[i] = new ElectricModelingDLGPiezomagnetic();
		}
		m_pelectricModelingDLGPiezomagnetic[i]->Create(IDD_MODELING_DLG_PIEZOMAGNETIC,GetDlgItem(IDC_TAB_MORE_PIEZOMAGNETIC));
		//m_electricModelingDLGElastic[i].SetParent(GetDlgItem(IDC_TAB_MORE_ELASTIC));
		//properties +=str;
		m_pelectricModelingDLGPiezomagnetic[i]->m_StaticPropertiesPHNox.SetWindowTextA(properties+str);
		// 将子对话框移动到指定的位置
		m_pelectricModelingDLGPiezomagnetic[i]->MoveWindow(&tabRect);

	}
	m_pelectricModelingDLGPiezomagnetic[0]->ShowWindow(SW_SHOW);
	for (int i =1;i<m_PhaseCount;i++)
	{
		m_pelectricModelingDLGPiezomagnetic[i]->ShowWindow(SW_HIDE);
	}

	// 设置标题

	this->SetWindowTextA(m_caption);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGMorePiezomagnetic::OnTcnSelchangeTabMorePiezomagnetic(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here

	int cur = m_TabMorePiezomagnetic.GetCurSel();
	CString curstr;
	curstr.Format("%d",cur);
	//::MessageBox(NULL,curstr,_T("OKOK"),MB_OK);
	if (cur >=0 && cur <m_PhaseCount){
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			if (i==cur){
				m_pelectricModelingDLGPiezomagnetic[cur]->ShowWindow(SW_SHOW);
			}else{
				m_pelectricModelingDLGPiezomagnetic[i]->ShowWindow(SW_HIDE);
			}
		}
	}

	*pResult = 0;
}


void ElectricModelingDLGMorePiezomagnetic::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGPiezomagnetic[i] != NULL){
			m_pelectricModelingDLGPiezomagnetic[i]->UpdateData(TRUE);

		}

	}
	CDialog::OnClose();
}


void ElectricModelingDLGMorePiezomagnetic::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGPiezomagnetic[i] != NULL){
			m_pelectricModelingDLGPiezomagnetic[i]->UpdateData(TRUE);

		}

	}
	CDialog::OnOK();
}
