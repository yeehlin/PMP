// ElectricModelingDLGMoreThermal.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "ElectricModelingDLGMoreThermal.h"
#include "afxdialogex.h"


// ElectricModelingDLGMoreThermal dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMoreThermal, CDialog)

ElectricModelingDLGMoreThermal::ElectricModelingDLGMoreThermal(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMoreThermal::IDD, pParent)
{

	m_caption =_T("Dialog");
	m_simulationType = 0;
	// 初始化指针
	// 初始状态numbers of phases为1，所以应该创建一个
	m_pelectricModelingDLGThermal[0] = new ElectricModelingDLGThermal();
	for (int i=1;i < 6;i++)
	{
		m_pelectricModelingDLGThermal[i] = NULL;
	}
}

ElectricModelingDLGMoreThermal::~ElectricModelingDLGMoreThermal()
{
		// 在持有者的析构函数中销毁动态内存
	//*
	for (int i=0;i < 6;i++){
		if (m_pelectricModelingDLGThermal[i] != NULL){
			delete m_pelectricModelingDLGThermal[i];
		}
	}
	//*/
}

void ElectricModelingDLGMoreThermal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MORE_THERMAL, m_TabMoreThermal);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMoreThermal, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MORE_THERMAL, &ElectricModelingDLGMoreThermal::OnTcnSelchangeTabMoreThermal)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGMoreThermal::OnBnClickedOk)
END_MESSAGE_MAP()

void ElectricModelingDLGMoreThermal::SetPhaseCount( int phaseCount )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_PhaseCount = phaseCount;
}

void ElectricModelingDLGMoreThermal::SetSimulationType( int simulationType )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_simulationType = simulationType;
}


// ElectricModelingDLGMoreThermal message handlers


BOOL ElectricModelingDLGMoreThermal::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here


	CString str;
	CString properties="Properties of ";
	TCITEM temp[6];
	CRect tabRect;
	m_TabMoreThermal.GetClientRect(&tabRect);
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
		m_TabMoreThermal.InsertItem(i,&temp[i]);
		// 利用一个模版创建多个子对话框
		// 确保创建一次并持有对象
		if (m_pelectricModelingDLGThermal[i] ==  NULL){
			// 很矛盾，如果没有则创建
			//::MessageBox(NULL,_T("DLGElastic分配内存"),_T("OKOK"),MB_OK);
			m_pelectricModelingDLGThermal[i] = new ElectricModelingDLGThermal();
		}
		m_pelectricModelingDLGThermal[i]->Create(IDD_MODELING_DLG_THERMAL,GetDlgItem(IDC_TAB_MORE_THERMAL));
		//m_electricModelingDLGElastic[i].SetParent(GetDlgItem(IDC_TAB_MORE_ELASTIC));
		//properties +=str;
		m_pelectricModelingDLGThermal[i]->m_StaticPropertiesPHNox.SetWindowTextA(properties+str);
		// 将子对话框移动到指定的位置
		m_pelectricModelingDLGThermal[i]->MoveWindow(&tabRect);

	}
	m_pelectricModelingDLGThermal[0]->ShowWindow(SW_SHOW);
	for (int i =1;i<m_PhaseCount;i++)
	{
		m_pelectricModelingDLGThermal[i]->ShowWindow(SW_HIDE);
	}

	// 设置标题
	this->SetWindowTextA(m_caption);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGMoreThermal::OnTcnSelchangeTabMoreThermal(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here

	int cur = m_TabMoreThermal.GetCurSel();
	CString curstr;
	curstr.Format("%d",cur);
	//::MessageBox(NULL,curstr,_T("OKOK"),MB_OK);
	if (cur >=0 && cur <m_PhaseCount){
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			if (i==cur){
				m_pelectricModelingDLGThermal[cur]->ShowWindow(SW_SHOW);
			}else{
				m_pelectricModelingDLGThermal[i]->ShowWindow(SW_HIDE);
			}
		}
	}

	*pResult = 0;
}


void ElectricModelingDLGMoreThermal::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGThermal[i] != NULL){
			m_pelectricModelingDLGThermal[i]->UpdateData(TRUE);

		}

	}
	CDialog::OnClose();
}


void ElectricModelingDLGMoreThermal::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGThermal[i] != NULL){
			m_pelectricModelingDLGThermal[i]->UpdateData(TRUE);

		}

	}
	CDialog::OnOK();
}
