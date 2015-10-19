// ElectricModelingDLGMoreElastic.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFCDlgWithTabctrl.h"
#include "ElectricModelingDLGMoreElastic.h"
#include "afxdialogex.h"

// ElectricModelingDLGMoreElastic dialog
float ElectricModelingDLGMoreElastic::c[6][6][6]={0.0f};
float ElectricModelingDLGMoreElastic::k[6][3][3]={0.0f};
float ElectricModelingDLGMoreElastic::d[6][3][6]={0.0f};
float ElectricModelingDLGMoreElastic::u[6][3][3]={0.0f};
float ElectricModelingDLGMoreElastic::q[6][3][6]={0.0f};
float ElectricModelingDLGMoreElastic::a[6][3][3]={0.0f};
float ElectricModelingDLGMoreElastic::diff[6][3][3]={0.0f};
float ElectricModelingDLGMoreElastic::ther[6][3][3]={0.0f};


IMPLEMENT_DYNAMIC(ElectricModelingDLGMoreElastic, CDialog)
ElectricModelingDLGMoreElastic::ElectricModelingDLGMoreElastic(CWnd* pParent /*=NULL*/)
	: CDialog(ElectricModelingDLGMoreElastic::IDD, pParent)
{

	m_caption =_T("Dialog");
	m_simulationType = 0;
	// 获取共享矩阵c的指针
	cc = (float ***)(ElectricModelingDLGMoreElastic::c);
	// 初始化指针
	// 初始状态numbers of phases为1，所以应该创建一个
	for (int i=0;i < 6;i++)
	{
		m_pelectricModelingDLGElastic[i] = new ElectricModelingDLGElastic();
		m_pelectricModelingDLGElastic[i]->ccc=(float **)((float *)cc + i*36);
	}

}

ElectricModelingDLGMoreElastic::~ElectricModelingDLGMoreElastic()
{
	// 在持有者的析构函数中销毁动态内存
	//*
	for (int i=0;i < 6;i++){
		if (m_pelectricModelingDLGElastic[i] != NULL){
			delete m_pelectricModelingDLGElastic[i];
		}
	}
	//*/
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
	CString properties="Properties of ";
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
		// 确保创建一次并持有对象
		if (m_pelectricModelingDLGElastic[i] ==  NULL){
			// 很矛盾，如果没有则创建
			//::MessageBox(NULL,_T("DLGElastic分配内存"),_T("OKOK"),MB_OK);
			m_pelectricModelingDLGElastic[i] = new ElectricModelingDLGElastic();
		}
		m_pelectricModelingDLGElastic[i]->Create(IDD_MODELING_DLG_ELASTIC,GetDlgItem(IDC_TAB_MORE_ELASTIC));
		//m_electricModelingDLGElastic[i].SetParent(GetDlgItem(IDC_TAB_MORE_ELASTIC));
		//properties +=str;
		m_pelectricModelingDLGElastic[i]->m_StaticPropertiesPHNox.SetWindowTextA(properties +str);
		// 将子对话框移动到指定的位置
		m_pelectricModelingDLGElastic[i]->MoveWindow(&tabRect);

	}
	// simulation type 选择了Material response to an external field时加入相应的选项
	/*
	if (this->m_simulationType == 1){
		//::MessageBox(NULL,_T("选择了Material response to an external field"),_T("OKOK"),MB_OK);
		TCITEM mechanical;
		mechanical.mask = TCIF_TEXT;
		mechanical.pszText = "External Field mechanical";
		// 确保创建一次，并持有对象
		if (m_pelectricModelingDLGMechanical == NULL){
			m_pelectricModelingDLGMechanical = new ElectricModelingDLGMechanical();
		}
		m_pelectricModelingDLGMechanical->Create(IDD_MODELING_DLG_MECHANICAL,GetDlgItem(IDC_TAB_MORE_ELASTIC));
		m_TabMoreElastic.InsertItem(m_PhaseCount,&mechanical);
		m_pelectricModelingDLGMechanical->MoveWindow(&tabRect);
		m_pelectricModelingDLGMechanical->ShowWindow(SW_HIDE);
	}
	*/
	m_pelectricModelingDLGElastic[0]->ShowWindow(SW_SHOW);
	for (int i =1;i<m_PhaseCount;i++)
	{
		m_pelectricModelingDLGElastic[i]->ShowWindow(SW_HIDE);
	}
	/*
	if (m_pelectricModelingDLGMechanical != NULL){
		m_pelectricModelingDLGMechanical->Create(IDD_MODELING_DLG_MECHANICAL,GetDlgItem(IDC_TAB_MORE_ELASTIC));
		m_pelectricModelingDLGMechanical->ShowWindow(SW_HIDE);
	}
	*/



	// 给对话框设置标题
	this->SetWindowTextA(m_caption);


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
				m_pelectricModelingDLGElastic[cur]->ShowWindow(SW_SHOW);
			}else{
				m_pelectricModelingDLGElastic[i]->ShowWindow(SW_HIDE);
			}
		}
		// 
		if (m_simulationType == 1){
			//m_pelectricModelingDLGMechanical->ShowWindow(SW_HIDE);
		}
	}
	else if (cur==this->m_PhaseCount){
		for (int i=0;i<this->m_PhaseCount;i++)
		{
			m_pelectricModelingDLGElastic[i]->ShowWindow(SW_HIDE);
		}
		//m_pelectricModelingDLGMechanical->ShowWindow(SW_SHOW);
	}

	*pResult = 0;
}

void ElectricModelingDLGMoreElastic::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGElastic[i] != NULL){
			m_pelectricModelingDLGElastic[i]->UpdateData(TRUE);
		}
	
	}

	SaveSharedData();
	
	CDialog::OnOK();
}


void ElectricModelingDLGMoreElastic::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGElastic[i] != NULL){
			m_pelectricModelingDLGElastic[i]->UpdateData(TRUE);

		}
	}
	/*
	if (m_pelectricModelingDLGMechanical !=NULL&& m_simulationType == 1){
		m_pelectricModelingDLGMechanical->UpdateData(TRUE);
	}
	*/
	SaveSharedData();
	CDialog::OnClose();
}

void ElectricModelingDLGMoreElastic::SaveSharedData(){
	// 保存输入用于回填
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGElastic[i] != NULL){
			//float * * * tc =(float ***) m_pelectricModelingDLGElastic[i]->c;
			// 保存数据到公共数据区
			for (int m=0;m<6;m++)
			{
				for (int n=0;n<6;n++)
				{
					*((float *)cc + i*36+m*6+n) = *(m_pelectricModelingDLGElastic[i]->c[m][n]);
				}
			}
		}

	}
}