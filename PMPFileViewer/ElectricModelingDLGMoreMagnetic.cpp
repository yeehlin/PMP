// ElectricModelingDLGMoreMagnetic.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "ElectricModelingDLGMoreMagnetic.h"
#include "afxdialogex.h"


// ElectricModelingDLGMoreMagnetic dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMoreMagnetic, CDialog)

ElectricModelingDLGMoreMagnetic::ElectricModelingDLGMoreMagnetic(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMoreMagnetic::IDD, pParent)
{
	m_caption =_T("Dialog");
	m_simulationType = 0;
	// 初始化指针
	// 初始状态numbers of phases为1，所以应该创建一个
	m_pelectricModelingDLGMagnetic[0] = new ElectricModelingDLGMagnetic();
	for (int i=1;i < 6;i++)
	{
		m_pelectricModelingDLGMagnetic[i] = NULL;
	}

}

ElectricModelingDLGMoreMagnetic::~ElectricModelingDLGMoreMagnetic()
{
		// 在持有者的析构函数中销毁动态内存
	//*
	for (int i=0;i < 6;i++){
		if (m_pelectricModelingDLGMagnetic[i] != NULL){
			delete m_pelectricModelingDLGMagnetic[i];
		}
	}
	//*/
}

void ElectricModelingDLGMoreMagnetic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MORE_MAGNETIC, m_TabMoreMagnetic);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMoreMagnetic, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MORE_MAGNETIC, &ElectricModelingDLGMoreMagnetic::OnTcnSelchangeTabMoreMagnetic)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGMoreMagnetic::OnBnClickedOk)
END_MESSAGE_MAP()

void ElectricModelingDLGMoreMagnetic::SetPhaseCount( int phaseCount )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_PhaseCount = phaseCount;
}

void ElectricModelingDLGMoreMagnetic::SetSimulationType( int simulationType )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_simulationType = simulationType;
}


// ElectricModelingDLGMoreMagnetic message handlers


BOOL ElectricModelingDLGMoreMagnetic::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here


	CString str;
	CString properties="Properties of ";
	TCITEM temp[6];
	CRect tabRect;
	m_TabMoreMagnetic.GetClientRect(&tabRect);
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
		m_TabMoreMagnetic.InsertItem(i,&temp[i]);
		// 利用一个模版创建多个子对话框
		// 确保创建一次并持有对象
		if (m_pelectricModelingDLGMagnetic[i] ==  NULL){
			// 很矛盾，如果没有则创建
			//::MessageBox(NULL,_T("DLGElastic分配内存"),_T("OKOK"),MB_OK);
			m_pelectricModelingDLGMagnetic[i] = new ElectricModelingDLGMagnetic();
		}
		m_pelectricModelingDLGMagnetic[i]->Create(IDD_MODELING_DLG_MAGNETIC,GetDlgItem(IDC_TAB_MORE_MAGNETIC));
		//m_electricModelingDLGElastic[i].SetParent(GetDlgItem(IDC_TAB_MORE_ELASTIC));
		//properties +=str;
		m_pelectricModelingDLGMagnetic[i]->m_StaticPropertiesPHNox.SetWindowTextA(properties+str);
		// 将子对话框移动到指定的位置
		m_pelectricModelingDLGMagnetic[i]->MoveWindow(&tabRect);

	}
	m_pelectricModelingDLGMagnetic[0]->ShowWindow(SW_SHOW);
	for (int i =1;i<m_PhaseCount;i++)
	{
		m_pelectricModelingDLGMagnetic[i]->ShowWindow(SW_HIDE);
	}

	// 设置标题
	SetWindowTextA(m_caption);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGMoreMagnetic::OnTcnSelchangeTabMoreMagnetic(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here


	int cur = m_TabMoreMagnetic.GetCurSel();
	CString curstr;
	curstr.Format("%d",cur);
	//::MessageBox(NULL,curstr,_T("OKOK"),MB_OK);
	if (cur >=0 && cur <m_PhaseCount){
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			if (i==cur){
				m_pelectricModelingDLGMagnetic[cur]->ShowWindow(SW_SHOW);
			}else{
				m_pelectricModelingDLGMagnetic[i]->ShowWindow(SW_HIDE);
			}
		}
	}

	*pResult = 0;
}


void ElectricModelingDLGMoreMagnetic::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGMagnetic[i] != NULL){
			m_pelectricModelingDLGMagnetic[i]->UpdateData(TRUE);

		}

	}
	CDialog::OnClose();
}


void ElectricModelingDLGMoreMagnetic::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGMagnetic[i] != NULL){
			m_pelectricModelingDLGMagnetic[i]->UpdateData(TRUE);

		}

	}
	CDialog::OnOK();
}
