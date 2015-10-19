// ElectricModelingDLGMoreMagnetoelectric.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGMoreMagnetoelectric.h"
#include "afxdialogex.h"

#include "ElectricModelingDLGMoreElastic.h"

// ElectricModelingDLGMoreMagnetoelectric dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMoreMagnetoelectric, CDialog)

ElectricModelingDLGMoreMagnetoelectric::ElectricModelingDLGMoreMagnetoelectric(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMoreMagnetoelectric::IDD, pParent)
{

	m_caption =_T("Dialog");
	m_simulationType = 0;
	// 获取共享矩阵c的指针
	cc = (float ***)(ElectricModelingDLGMoreElastic::c);
	kk = (float ***)(ElectricModelingDLGMoreElastic::k);
	dd = (float ***)(ElectricModelingDLGMoreElastic::d);
	uu = (float ***)(ElectricModelingDLGMoreElastic::u);
	qq = (float ***)(ElectricModelingDLGMoreElastic::q);
	aa = (float ***)(ElectricModelingDLGMoreElastic::a);
	// 初始化指针

	// 初始状态numbers of phases为1，所以应该创建一个
	for (int i=0;i < 6;i++)
	{
		m_pelectricModelingDLGMagnetoelectric[i] = new ElectricModelingDLGMagnetoelectric();
		// 分配共享矩阵指针
		m_pelectricModelingDLGMagnetoelectric[i]->ccc=(float **)((float *)cc + i*6*6);
		m_pelectricModelingDLGMagnetoelectric[i]->kkk=(float **)((float *)kk + i*3*3);
		m_pelectricModelingDLGMagnetoelectric[i]->ddd=(float **)((float *)dd + i*3*6);
		m_pelectricModelingDLGMagnetoelectric[i]->uuu=(float **)((float *)uu + i*3*3);
		m_pelectricModelingDLGMagnetoelectric[i]->qqq=(float **)((float *)qq + i*3*6);
		m_pelectricModelingDLGMagnetoelectric[i]->aaa=(float **)((float *)aa + i*3*3);

	}

}

ElectricModelingDLGMoreMagnetoelectric::~ElectricModelingDLGMoreMagnetoelectric()
{
		// 在持有者的析构函数中销毁动态内存
	//*
	for (int i=0;i < 6;i++){
		if (m_pelectricModelingDLGMagnetoelectric[i] != NULL){
			delete m_pelectricModelingDLGMagnetoelectric[i];
		}
	}
	//*/
}

void ElectricModelingDLGMoreMagnetoelectric::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MORE_MAGNETOELECTRIC, m_TabMoreMagnetoelectric);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMoreMagnetoelectric, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MORE_MAGNETOELECTRIC, &ElectricModelingDLGMoreMagnetoelectric::OnTcnSelchangeTabMoreMagnetoelectric)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGMoreMagnetoelectric::OnBnClickedOk)
END_MESSAGE_MAP()

void ElectricModelingDLGMoreMagnetoelectric::SetPhaseCount( int phaseCount )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_PhaseCount = phaseCount;
}

void ElectricModelingDLGMoreMagnetoelectric::SetSimulationType( int simulationType )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_simulationType = simulationType;
}


// ElectricModelingDLGMoreMagnetoelectric message handlers


BOOL ElectricModelingDLGMoreMagnetoelectric::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here


	CString str;
	CString properties="Properties of ";
	TCITEM temp[6];
	CRect tabRect;
	m_TabMoreMagnetoelectric.GetClientRect(&tabRect);
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
		m_TabMoreMagnetoelectric.InsertItem(i,&temp[i]);
		// 利用一个模版创建多个子对话框
		// 确保创建一次并持有对象
		if (m_pelectricModelingDLGMagnetoelectric[i] ==  NULL){
			// 很矛盾，如果没有则创建
			//::MessageBox(NULL,_T("DLGElastic分配内存"),_T("OKOK"),MB_OK);
			m_pelectricModelingDLGMagnetoelectric[i] = new ElectricModelingDLGMagnetoelectric();
		}
		m_pelectricModelingDLGMagnetoelectric[i]->Create(IDD_MODELING_DLG_MAGNETOELECTRIC,GetDlgItem(IDC_TAB_MORE_MAGNETOELECTRIC));
		//m_electricModelingDLGElastic[i].SetParent(GetDlgItem(IDC_TAB_MORE_ELASTIC));
		//properties +=str;
		m_pelectricModelingDLGMagnetoelectric[i]->m_StaticPropertiesPHNox.SetWindowTextA(properties+str);
		// 将子对话框移动到指定的位置
		m_pelectricModelingDLGMagnetoelectric[i]->MoveWindow(&tabRect);

	}
	m_pelectricModelingDLGMagnetoelectric[0]->ShowWindow(SW_SHOW);
	for (int i =1;i<m_PhaseCount;i++)
	{
		m_pelectricModelingDLGMagnetoelectric[i]->ShowWindow(SW_HIDE);
	}

	// 设置标题
	SetWindowTextA(m_caption);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGMoreMagnetoelectric::OnTcnSelchangeTabMoreMagnetoelectric(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here

	int cur = m_TabMoreMagnetoelectric.GetCurSel();
	CString curstr;
	curstr.Format("%d",cur);
	//::MessageBox(NULL,curstr,_T("OKOK"),MB_OK);
	if (cur >=0 && cur <m_PhaseCount){
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			if (i==cur){
				m_pelectricModelingDLGMagnetoelectric[cur]->ShowWindow(SW_SHOW);
			}else{
				m_pelectricModelingDLGMagnetoelectric[i]->ShowWindow(SW_HIDE);
			}
		}
	}

	*pResult = 0;
}


void ElectricModelingDLGMoreMagnetoelectric::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGMagnetoelectric[i] != NULL){
			m_pelectricModelingDLGMagnetoelectric[i]->UpdateData(TRUE);

		}

	}
	SaveSharedData();
	CDialog::OnClose();
}


void ElectricModelingDLGMoreMagnetoelectric::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGMagnetoelectric[i] != NULL){
			m_pelectricModelingDLGMagnetoelectric[i]->UpdateData(TRUE);

		}

	}
	SaveSharedData();
	CDialog::OnOK();
}

void ElectricModelingDLGMoreMagnetoelectric::SaveSharedData(){
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGMagnetoelectric[i] != NULL){
			//float * * * tc =(float ***) m_pelectricModelingDLGElastic[i]->c;
			// 保存数据到公共数据区
			// 保存c矩阵
			for (int m=0;m<6;m++)
			{
				for (int n=0;n<6;n++)
				{
					*((float *)cc + i*6*6+m*6+n) = *(m_pelectricModelingDLGMagnetoelectric[i]->c[m][n]);
				}
			}
			// 保存k矩阵
			for (int m=0;m<3;m++)
			{
				for (int n=0;n<3;n++)
				{
					*((float *)kk + i*3*3+m*3+n) = *(m_pelectricModelingDLGMagnetoelectric[i]->k[m][n]);
				}
			}
			// 保存d矩阵
			for (int m=0;m<3;m++)
			{
				for (int n=0;n<6;n++)
				{
					*((float *)dd + i*3*6+m*6+n) = *(m_pelectricModelingDLGMagnetoelectric[i]->d[m][n]);
				}
			}
			// 保存u矩阵
			for (int m=0;m<3;m++)
			{
				for (int n=0;n<3;n++)
				{
					*((float *)uu + i*3*3+m*3+n) = *(m_pelectricModelingDLGMagnetoelectric[i]->u[m][n]);
				}
			}
			// 保存q矩阵
			for (int m=0;m<3;m++)
			{
				for (int n=0;n<6;n++)
				{
					*((float *)qq + i*3*6+m*6+n) = *(m_pelectricModelingDLGMagnetoelectric[i]->q[m][n]);
				}
			}
			// 保存a矩阵
			for (int m=0;m<3;m++)
			{
				for (int n=0;n<3;n++)
				{
					*((float *)aa + i*3*3+m*3+n) = *(m_pelectricModelingDLGMagnetoelectric[i]->a[m][n]);
				}
			}
		}

	}
}