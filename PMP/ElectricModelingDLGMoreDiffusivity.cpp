// ElectricModelingDLGMoreDiffusivity.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ElectricModelingDLGMoreDiffusivity.h"
#include "afxdialogex.h"

#include "ElectricModelingDLGMoreElastic.h"

// ElectricModelingDLGMoreDiffusivity dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMoreDiffusivity, CDialog)

ElectricModelingDLGMoreDiffusivity::ElectricModelingDLGMoreDiffusivity(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMoreDiffusivity::IDD, pParent)
{

	m_caption =_T("Dialog");
	m_simulationType = 0;
	// 获取共享矩阵c的指针
	kk = (float ***)(ElectricModelingDLGMoreElastic::diff);
	// 初始化指针
	
	for (int i=0;i < 6;i++)
	{
		m_pelectricModelingDLGDiffusivity[i] = new ElectricModelingDLGDiffusivity();
		// 分配共享矩阵指针
		m_pelectricModelingDLGDiffusivity[i]->kkk=(float **)((float *)kk + i*3*3);
	}
}

ElectricModelingDLGMoreDiffusivity::~ElectricModelingDLGMoreDiffusivity()
{
		// 在持有者的析构函数中销毁动态内存
	//*
	for (int i=0;i < 6;i++){
		if (m_pelectricModelingDLGDiffusivity[i] != NULL){
			delete m_pelectricModelingDLGDiffusivity[i];
		}
	}
	//*/
}

void ElectricModelingDLGMoreDiffusivity::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MORE_DIFFUSIVITY, m_TabMoreDiffusivity);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMoreDiffusivity, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MORE_DIFFUSIVITY, &ElectricModelingDLGMoreDiffusivity::OnTcnSelchangeTabMoreDiffusivity)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGMoreDiffusivity::OnBnClickedOk)
END_MESSAGE_MAP()

void ElectricModelingDLGMoreDiffusivity::SetPhaseCount( int phaseCount )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_PhaseCount = phaseCount;
}

void ElectricModelingDLGMoreDiffusivity::SetSimulationType( int simulationType )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_simulationType = simulationType;
}



// ElectricModelingDLGMoreDiffusivity message handlers


BOOL ElectricModelingDLGMoreDiffusivity::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	CString str;
	CString properties="Properties of ";
	TCITEM temp[6];
	CRect tabRect;
	m_TabMoreDiffusivity.GetClientRect(&tabRect);
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
		m_TabMoreDiffusivity.InsertItem(i,&temp[i]);
		// 利用一个模版创建多个子对话框
		// 确保创建一次并持有对象
		if (m_pelectricModelingDLGDiffusivity[i] ==  NULL){
			// 很矛盾，如果没有则创建
			//::MessageBox(NULL,_T("DLGElastic分配内存"),_T("OKOK"),MB_OK);
			m_pelectricModelingDLGDiffusivity[i] = new ElectricModelingDLGDiffusivity();
		}
		m_pelectricModelingDLGDiffusivity[i]->Create(IDD_MODELING_DLG_DIFFUSIVITY,GetDlgItem(IDC_TAB_MORE_DIFFUSIVITY));
		//m_electricModelingDLGElastic[i].SetParent(GetDlgItem(IDC_TAB_MORE_ELASTIC));
		//properties +=str;
		m_pelectricModelingDLGDiffusivity[i]->m_StaticPropertiesPHNox.SetWindowTextA(properties+str);
		// 将子对话框移动到指定的位置
		m_pelectricModelingDLGDiffusivity[i]->MoveWindow(&tabRect);

	}
	m_pelectricModelingDLGDiffusivity[0]->ShowWindow(SW_SHOW);
	for (int i =1;i<m_PhaseCount;i++)
	{
		m_pelectricModelingDLGDiffusivity[i]->ShowWindow(SW_HIDE);
	}

	// 设置标题
	SetWindowTextA(m_caption);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGMoreDiffusivity::OnTcnSelchangeTabMoreDiffusivity(NMHDR *pNMHDR, LRESULT *pResult)
{
	
	// TODO: Add your control notification handler code here

	int cur = m_TabMoreDiffusivity.GetCurSel();
	CString curstr;
	curstr.Format("%d",cur);
	//::MessageBox(NULL,curstr,_T("OKOK"),MB_OK);
	if (cur >=0 && cur <m_PhaseCount){
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			if (i==cur){
				m_pelectricModelingDLGDiffusivity[cur]->ShowWindow(SW_SHOW);
			}else{
				m_pelectricModelingDLGDiffusivity[i]->ShowWindow(SW_HIDE);
			}
		}
	}

	*pResult = 0;
}


void ElectricModelingDLGMoreDiffusivity::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGDiffusivity[i] != NULL){
			m_pelectricModelingDLGDiffusivity[i]->UpdateData(TRUE);

		}

	}
	SaveSharedData();
	CDialog::OnClose();
}


void ElectricModelingDLGMoreDiffusivity::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGDiffusivity[i] != NULL){
			m_pelectricModelingDLGDiffusivity[i]->UpdateData(TRUE);

		}

	}
	SaveSharedData();
	CDialog::OnOK();
}

void ElectricModelingDLGMoreDiffusivity::SaveSharedData(){
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGDiffusivity[i] != NULL){
			//float * * * tc =(float ***) m_pelectricModelingDLGElastic[i]->c;
			// 保存数据到公共数据区
			// 保存k矩阵
			for (int m=0;m<3;m++)
			{
				for (int n=0;n<3;n++)
				{
					*((float *)kk + i*3*3+m*3+n) = *(m_pelectricModelingDLGDiffusivity[i]->k[m][n]);
				}
			}
		}

	}
}