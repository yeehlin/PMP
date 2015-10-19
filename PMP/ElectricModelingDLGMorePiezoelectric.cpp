// ElectricModelingDLGMorePiezoelectric.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ElectricModelingDLGMorePiezoelectric.h"
#include "afxdialogex.h"

#include "ElectricModelingDLGMoreElastic.h"

// ElectricModelingDLGMorePiezoelectric dialog

IMPLEMENT_DYNAMIC(ElectricModelingDLGMorePiezoelectric, CDialog)

ElectricModelingDLGMorePiezoelectric::ElectricModelingDLGMorePiezoelectric(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMorePiezoelectric::IDD, pParent)
{

	m_PhaseCount = 0;
	m_simulationType = 0;
	// 获取共享矩阵c的指针
	cc = (float ***)(ElectricModelingDLGMoreElastic::c);
	kk = (float ***)(ElectricModelingDLGMoreElastic::k);
	dd = (float ***)(ElectricModelingDLGMoreElastic::d);
	// 初始化指针
	for (int i=0;i < 6;i++)
	{
		m_pelectricModelingDLGPiezoelectric[i] = new ElectricModelingDLGPiezoelectric();
		m_pelectricModelingDLGPiezoelectric[i]->ccc=(float **)((float *)cc + i*6*6);
		m_pelectricModelingDLGPiezoelectric[i]->kkk=(float **)((float *)kk + i*3*3);
		m_pelectricModelingDLGPiezoelectric[i]->ddd=(float **)((float *)dd + i*3*6);
	}
	//m_pelectricModelingDLGMechanical = NULL;
	//m_pelectricModelingDLGExternal = NULL;
	//m_pelectricModelingDLGChild3 = new ElectricModelingDLGChild3();
	m_caption =_T("Dialog");
}

ElectricModelingDLGMorePiezoelectric::~ElectricModelingDLGMorePiezoelectric()
{
	// 在持有者的析构函数中销毁动态内存
	for (int i=0;i < 6;i++){
		if (m_pelectricModelingDLGPiezoelectric[i] != NULL){
			delete m_pelectricModelingDLGPiezoelectric[i];
		}
	}
	/*
	if (m_pelectricModelingDLGMechanical != NULL){
		delete m_pelectricModelingDLGMechanical;
	}
	if (m_pelectricModelingDLGExternal != NULL){
		delete m_pelectricModelingDLGExternal;
	}
	*/
	/*
	if (m_pelectricModelingDLGChild3 != NULL){
		delete m_pelectricModelingDLGChild3;
	}
	*/
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
	CString properties="Properties of ";
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
		// 确保创建一次并持有对象
		if (m_pelectricModelingDLGPiezoelectric[i] == NULL){
			m_pelectricModelingDLGPiezoelectric[i] = new ElectricModelingDLGPiezoelectric();
		}
		m_pelectricModelingDLGPiezoelectric[i]->Create(IDD_MODELING_DLG_PIEZOELECTRIC,GetDlgItem(IDC_TAB_MORE_PIEZOELECTRIC));
		
		//properties+=str;
		m_pelectricModelingDLGPiezoelectric[i]->m_StaticPiezoPropertiesPHNox.SetWindowTextA(properties+str);
		// 将子对话框移动到指定的位置
		m_pelectricModelingDLGPiezoelectric[i]->MoveWindow(&tabRect);

	}
	// simulation type 选择了Material response to an external field时加入相应的选项
	/*
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
	/*
		TCITEM child3;
		child3.mask = TCIF_TEXT;
		child3.pszText = "External Field";
		// 确保创建一次，并持有对象
		if (m_pelectricModelingDLGChild3 == NULL){
			m_pelectricModelingDLGChild3 = new ElectricModelingDLGChild3();
		}
		m_pelectricModelingDLGChild3->Create(IDD_MODELING_DLG_CHILD3,GetDlgItem(IDC_TAB_MORE_PIEZOELECTRIC));
		m_TabMorePiezoelectric.InsertItem(m_PhaseCount+1,&child3);
		m_pelectricModelingDLGChild3->MoveWindow(&tabRect);
		m_pelectricModelingDLGChild3->ShowWindow(SW_HIDE);
	}
*/
	m_pelectricModelingDLGPiezoelectric[0]->ShowWindow(SW_SHOW);

	for (int i =1;i<m_PhaseCount;i++)
	{
		m_pelectricModelingDLGPiezoelectric[i]->ShowWindow(SW_HIDE);
	}
	/*
	if (m_pelectricModelingDLGChild3 != NULL){
		m_pelectricModelingDLGChild3->Create(IDD_MODELING_DLG_CHILD3,GetDlgItem(IDC_TAB_MORE_PIEZOELECTRIC));
		m_pelectricModelingDLGChild3->ShowWindow(SW_HIDE);
	}
	*/


	// 给对话框设置标题
	this->SetWindowTextA(m_caption);

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
				m_pelectricModelingDLGPiezoelectric[cur]->ShowWindow(SW_SHOW);
			}else{
				m_pelectricModelingDLGPiezoelectric[i]->ShowWindow(SW_HIDE);
			}
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
		if (m_pelectricModelingDLGPiezoelectric[i]){
			m_pelectricModelingDLGPiezoelectric[i]->UpdateData(TRUE);
		}
	}
	// 保存到公共矩阵
	SaveSharedData();
	CDialog::OnOK();
}


void ElectricModelingDLGMorePiezoelectric::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGPiezoelectric[i] != NULL){
			m_pelectricModelingDLGPiezoelectric[i]->UpdateData(TRUE);
		}
	}
	SaveSharedData();
	/*
	if (m_pelectricModelingDLGChild3 != NULL && m_simulationType == 1){
		m_pelectricModelingDLGChild3->UpdateData(TRUE);
	}
	*/
	/*
	if (m_pelectricModelingDLGMechanical != NULL){
		m_pelectricModelingDLGMechanical->UpdateData(TRUE);
	}
	if (m_pelectricModelingDLGExternal != NULL){
		m_pelectricModelingDLGExternal->UpdateData(TRUE);
	}
	*/
	CDialog::OnClose();
}

void ElectricModelingDLGMorePiezoelectric::SaveSharedData(){
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGPiezoelectric[i] != NULL){
			//float * * * tc =(float ***) m_pelectricModelingDLGElastic[i]->c;
			// 保存数据到公共数据区
			// 保存c矩阵
			for (int m=0;m<6;m++)
			{
				for (int n=0;n<6;n++)
				{
					*((float *)cc + i*6*6+m*6+n) = *(m_pelectricModelingDLGPiezoelectric[i]->c[m][n]);
				}
			}
			// 保存k矩阵
			for (int m=0;m<3;m++)
			{
				for (int n=0;n<3;n++)
				{
					*((float *)kk + i*3*3+m*3+n) = *(m_pelectricModelingDLGPiezoelectric[i]->k[m][n]);
				}
			}
			// 保存d矩阵
			for (int m=0;m<3;m++)
			{
				for (int n=0;n<6;n++)
				{
					*((float *)dd + i*3*6+m*6+n) = *(m_pelectricModelingDLGPiezoelectric[i]->d[m][n]);
				}
			}
		}

	}
}