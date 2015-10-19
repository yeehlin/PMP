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
	// ��ȡ�������c��ָ��
	cc = (float ***)(ElectricModelingDLGMoreElastic::c);
	// ��ʼ��ָ��
	// ��ʼ״̬numbers of phasesΪ1������Ӧ�ô���һ��
	for (int i=0;i < 6;i++)
	{
		m_pelectricModelingDLGElastic[i] = new ElectricModelingDLGElastic();
		m_pelectricModelingDLGElastic[i]->ccc=(float **)((float *)cc + i*36);
	}

}

ElectricModelingDLGMoreElastic::~ElectricModelingDLGMoreElastic()
{
	// �ڳ����ߵ��������������ٶ�̬�ڴ�
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

	// �ǹ��캯���ȱ������𣿣��ǵģ�
	/*
	CString temp;
	temp.Format("%d",this->m_PhaseCount);
	::MessageBox(NULL,_T("����OnInitDialog"+temp),_T("OKOK"),MB_OK);
	*/
	CString str;
	CString properties="Properties of ";
	TCITEM temp[6];
	CRect tabRect;
	m_TabMoreElastic.GetClientRect(&tabRect);
	// ��λѡ�λ��
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
		// ����һ��ģ�洴������ӶԻ���
		// ȷ������һ�β����ж���
		if (m_pelectricModelingDLGElastic[i] ==  NULL){
			// ��ì�ܣ����û���򴴽�
			//::MessageBox(NULL,_T("DLGElastic�����ڴ�"),_T("OKOK"),MB_OK);
			m_pelectricModelingDLGElastic[i] = new ElectricModelingDLGElastic();
		}
		m_pelectricModelingDLGElastic[i]->Create(IDD_MODELING_DLG_ELASTIC,GetDlgItem(IDC_TAB_MORE_ELASTIC));
		//m_electricModelingDLGElastic[i].SetParent(GetDlgItem(IDC_TAB_MORE_ELASTIC));
		//properties +=str;
		m_pelectricModelingDLGElastic[i]->m_StaticPropertiesPHNox.SetWindowTextA(properties +str);
		// ���ӶԻ����ƶ���ָ����λ��
		m_pelectricModelingDLGElastic[i]->MoveWindow(&tabRect);

	}
	// simulation type ѡ����Material response to an external fieldʱ������Ӧ��ѡ��
	/*
	if (this->m_simulationType == 1){
		//::MessageBox(NULL,_T("ѡ����Material response to an external field"),_T("OKOK"),MB_OK);
		TCITEM mechanical;
		mechanical.mask = TCIF_TEXT;
		mechanical.pszText = "External Field mechanical";
		// ȷ������һ�Σ������ж���
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



	// ���Ի������ñ���
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
	// �����������ڻ���
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

	// �����������ڻ���
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
	// �����������ڻ���
	for (int i = 0;i<this->m_PhaseCount;i++)
	{
		if (m_pelectricModelingDLGElastic[i] != NULL){
			//float * * * tc =(float ***) m_pelectricModelingDLGElastic[i]->c;
			// �������ݵ�����������
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