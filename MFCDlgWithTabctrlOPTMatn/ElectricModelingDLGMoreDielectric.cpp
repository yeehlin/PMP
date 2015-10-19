// ElectricModelingDLGMoreDielectric.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGMoreDielectric.h"
#include "afxdialogex.h"

#include "ElectricModelingDLGMoreElastic.h"

// ElectricModelingDLGMoreDielectric dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMoreDielectric, CDialog)

ElectricModelingDLGMoreDielectric::ElectricModelingDLGMoreDielectric(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMoreDielectric::IDD, pParent)
{

	m_PhaseCount = 0;
	m_simulationType = 0;
	// 获取共享矩阵c的指针
	kk = (float ***)(ElectricModelingDLGMoreElastic::k);
	for (int i=0;i < 6;i++)
	{
		m_pelectricModelingDLGDielectric[i] = new ElectricModelingDLGDielectric();
		// 分配共享矩阵指针
		m_pelectricModelingDLGDielectric[i]->kkk=(float **)((float *)kk + i*3*3);
	}
	//m_pelectricModelingDLGExternal = new ElectricModelingDLGExternal();
	m_caption =_T("Dialog");
}

ElectricModelingDLGMoreDielectric::~ElectricModelingDLGMoreDielectric()
{
	// 在持有者的析构函数中销毁动态内存
	for (int i=0;i < 6;i++){
		if (m_pelectricModelingDLGDielectric[i] != NULL){
			delete m_pelectricModelingDLGDielectric[i];
		}
	}
	/*
	if (m_pelectricModelingDLGExternal != NULL){
		delete m_pelectricModelingDLGExternal;
	}
	*/
}

void ElectricModelingDLGMoreDielectric::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MORE_DIELECTRIC, m_TabMoreDielectric);
}


BEGIN_MESSAGE_MAP(ElectricModelingDLGMoreDielectric, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MORE_DIELECTRIC, &ElectricModelingDLGMoreDielectric::OnTcnSelchangeTabMoreDielectric)
	ON_BN_CLICKED(IDOK, &ElectricModelingDLGMoreDielectric::OnBnClickedOk)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

void ElectricModelingDLGMoreDielectric::SetPhaseCount( int phaseCount )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_PhaseCount = phaseCount;
}

void ElectricModelingDLGMoreDielectric::SetSimulationType( int simulationType )
{
	//throw std::Exception("The method or operation is not implemented.");
	this->m_simulationType = simulationType;
}

// ElectricModelingDLGMoreDielectric message handlers


BOOL ElectricModelingDLGMoreDielectric::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	CString str;
	CString properties="Properties of ";
	TCITEM temp[6];
	CRect tabRect;
	m_TabMoreDielectric.GetClientRect(&tabRect);
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
		m_TabMoreDielectric.InsertItem(i,&temp[i]);
		// 利用一个模版创建多个子对话框
		// 确保只创建一次并持有对象
		if (m_pelectricModelingDLGDielectric[i] == NULL){

			m_pelectricModelingDLGDielectric[i] = new ElectricModelingDLGDielectric();
		}
		m_pelectricModelingDLGDielectric[i]->Create(IDD_MODELING_DLG_DIELECTRIC,GetDlgItem(IDC_TAB_MORE_DIELECTRIC));
		m_pelectricModelingDLGDielectric[i]->m_StaticPropertiesPHNox.SetWindowTextA(properties+str);
		// 将子对话框移动到指定的位置
		m_pelectricModelingDLGDielectric[i]->MoveWindow(&tabRect);

	}
	// simulation type 选择了Material response to an external field时加入相应的选项
	/*
	if (this->m_simulationType == 1){
		TCITEM external;
		external.mask = TCIF_TEXT;
		external.pszText = "External Field external";
		if (m_pelectricModelingDLGExternal == NULL){

			m_pelectricModelingDLGExternal = new ElectricModelingDLGExternal();
		}
		m_pelectricModelingDLGExternal->Create(IDD_MODELING_DLG_EXTERNAL,GetDlgItem(IDC_TAB_MORE_DIELECTRIC));
		
		m_TabMoreDielectric.InsertItem(m_PhaseCount,&external);
		m_pelectricModelingDLGExternal->MoveWindow(&tabRect);
		m_pelectricModelingDLGExternal->ShowWindow(SW_HIDE);
	}
	*/
	m_pelectricModelingDLGDielectric[0]->ShowWindow(SW_SHOW);

	for (int i =1;i<m_PhaseCount;i++)
	{
		m_pelectricModelingDLGDielectric[i]->ShowWindow(SW_HIDE);
	}
	/*
	if (m_pelectricModelingDLGExternal != NULL){
		m_pelectricModelingDLGExternal->Create(IDD_MODELING_DLG_EXTERNAL,GetDlgItem(IDC_TAB_MORE_DIELECTRIC));
		m_pelectricModelingDLGExternal->ShowWindow(SW_HIDE);
	}
	*/


	// 给对话框设置标题
	this->SetWindowTextA(m_caption);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElectricModelingDLGMoreDielectric::OnTcnSelchangeTabMoreDielectric(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	int cur = m_TabMoreDielectric.GetCurSel();
	if (cur >=0 && cur<m_PhaseCount){
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			if (i == cur){
				m_pelectricModelingDLGDielectric[cur]->ShowWindow(SW_SHOW);
			}else{
				m_pelectricModelingDLGDielectric[i]->ShowWindow(SW_HIDE);
			}
		}

	}

	*pResult = 0;
}


void ElectricModelingDLGMoreDielectric::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		m_pelectricModelingDLGDielectric[i]->UpdateData(TRUE);
	}
	/*
	if(m_pelectricModelingDLGExternal != NULL && m_simulationType == 1){
		m_pelectricModelingDLGExternal->UpdateData(TRUE);
	}
	*/
	SaveSharedData();
	CDialog::OnOK();
}


void ElectricModelingDLGMoreDielectric::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if(m_pelectricModelingDLGDielectric[i]!=NULL){
			m_pelectricModelingDLGDielectric[i]->UpdateData(TRUE);
		}
	}
	/*
	if(m_pelectricModelingDLGExternal != NULL && m_simulationType == 1){
		m_pelectricModelingDLGExternal->UpdateData(TRUE);
	}
	*/
	SaveSharedData();
	CDialog::OnClose();
}

void ElectricModelingDLGMoreDielectric::SaveSharedData(){
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGDielectric[i] != NULL){
			//float * * * tc =(float ***) m_pelectricModelingDLGElastic[i]->c;
			// 保存数据到公共数据区
			// 保存k矩阵
			for (int m=0;m<3;m++)
			{
				for (int n=0;n<3;n++)
				{
					*((float *)kk + i*3*3+m*3+n) = *(m_pelectricModelingDLGDielectric[i]->k[m][n]);
				}
			}
		}

	}
}