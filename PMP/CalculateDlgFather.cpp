// CalculateDlgFather.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "CalculateDlgFather.h"
#include "afxdialogex.h"


// CalculateDlgFather dialog

IMPLEMENT_DYNAMIC(CalculateDlgFather, CDialog)

CalculateDlgFather::CalculateDlgFather(CWnd* pParent /*=NULL*/)
	: CDialog(CalculateDlgFather::IDD, pParent)
{
	this->m_calculateDlgChild1 =  new CalculateDlgChild1();
	this->m_calculateDlgChild2 =  new CalculateDlgChild2();
	this->m_calculateDlgChild3 =  new CalculateDlgChild3();

}

CalculateDlgFather::~CalculateDlgFather()
{
	if (m_calculateDlgChild1 !=NULL){
		delete m_calculateDlgChild1;
	}
	if (m_calculateDlgChild2 !=NULL){
		delete m_calculateDlgChild1;
	}
	if (m_calculateDlgChild3 !=NULL){
		delete m_calculateDlgChild1;
	}
}

void CalculateDlgFather::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_CALCULATE_DLG_TAB, m_tab);
}


BEGIN_MESSAGE_MAP(CalculateDlgFather, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_CALCULATE_DLG_TAB, &CalculateDlgFather::OnTcnSelchangeCalculateDlgTab)
	ON_BN_CLICKED(IDC_RUN, &CalculateDlgFather::OnBnClickedRun)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CalculateDlgFather::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_FILE, &CalculateDlgFather::OnBnClickedButtonFile)
END_MESSAGE_MAP()


// CalculateDlgFather message handlers

// ͨ��������Ӹú������ڸú�����ʵ�ָ��Ի������ӶԻ���Ĺ�ϵ�������ϵҪͨ��tab�ؼ����
BOOL CalculateDlgFather::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	// ��ʼ��Tab

	TCITEM  tcitem1;
	TCITEM  tcitem2;
	TCITEM  tcitem3;
	tcitem1.mask = TCIF_TEXT;
	tcitem1.pszText=_T("Setup");
	this->m_tab.InsertItem(1,&tcitem1);
	//*/
	tcitem2.mask = TCIF_TEXT;
	tcitem2.pszText=_T("Output");
	tcitem3.mask = TCIF_TEXT;
	tcitem3.pszText=_T("Job Control");
	// ���tabҳ
	this->m_tab.InsertItem(2,&tcitem2);
	this->m_tab.InsertItem(3,&tcitem3);
	// ���Tab�ؼ������꣬���ڷ���ѡ�
	CRect tabRect;
	m_tab.GetClientRect(&tabRect);
	// ��λѡ�λ��
	tabRect.bottom -=10;
	tabRect.left +=10;
	tabRect.top +=25;
	tabRect.right-=10;
	// �����ӶԻ���
	//calculateDlgChild[0].Create(IDD_CALCULATE_DLG_CHILD1,GetDlgItem(IDC_CALCULATE_DLG_TAB));
	//calculateDlgChild[1].Create(IDD_CALCULATE_DLG_CHILD2,GetDlgItem(IDC_CALCULATE_DLG_TAB));
	//calculateDlgChild[2].Create(IDD_CALCULATE_DLG_CHILD3,GetDlgItem(IDC_CALCULATE_DLG_TAB));
	m_calculateDlgChild1->Create(IDD_CALCULATE_DLG_CHILD1,GetDlgItem(IDC_CALCULATE_DLG_TAB));
	m_calculateDlgChild2->Create(IDD_CALCULATE_DLG_CHILD2,GetDlgItem(IDC_CALCULATE_DLG_TAB));
	m_calculateDlgChild3->Create(IDD_CALCULATE_DLG_CHILD3,GetDlgItem(IDC_CALCULATE_DLG_TAB));

	// ���ӶԻ����ƶ���ָ����λ��
	//calculateDlgChild[0].MoveWindow(&tabRect);
	//calculateDlgChild[1].MoveWindow(&tabRect);
	//calculateDlgChild[2].MoveWindow(&tabRect);
	m_calculateDlgChild1->MoveWindow(&tabRect);
	m_calculateDlgChild2->MoveWindow(&tabRect);
	m_calculateDlgChild3->MoveWindow(&tabRect);
	// ��ʾ��ҳ�棬���ǻ��Ƶ�һ���ӶԻ��򣬶���������������
	//calculateDlgChild[0].ShowWindow(SW_SHOW);
	//calculateDlgChild[1].ShowWindow(SW_HIDE);
	//calculateDlgChild[2].ShowWindow(SW_HIDE);
	m_calculateDlgChild1->ShowWindow(SW_SHOW);
	m_calculateDlgChild2->ShowWindow(SW_HIDE);
	m_calculateDlgChild3->ShowWindow(SW_HIDE);
	//*/

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

// ����Դ��ͼ�У��򿪸��Ի�����Դ��˫��Tab�ؼ���������Ӧ�������������Ҽ���ؿؼ�Ҳ�������Ըÿؼ��Ĵ�����
void CalculateDlgFather::OnTcnSelchangeCalculateDlgTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	//*/
	switch (m_tab.GetCurSel())
	{
	case 0:
		m_calculateDlgChild1->ShowWindow(SW_SHOW);
		m_calculateDlgChild2->ShowWindow(SW_HIDE);
		m_calculateDlgChild3->ShowWindow(SW_HIDE);
		break;
	case 1:
		m_calculateDlgChild1->ShowWindow(SW_HIDE);
		m_calculateDlgChild2->ShowWindow(SW_SHOW);
		m_calculateDlgChild3->ShowWindow(SW_HIDE);
		break;
	case 2:
		m_calculateDlgChild1->ShowWindow(SW_HIDE);
		m_calculateDlgChild2->ShowWindow(SW_HIDE);
		m_calculateDlgChild3->ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}
	//*/
	*pResult = 0;
}


// �ӿڣ��ýӿڿ��Խ��Ի����еĲ���д��һ���ļ�
void CalculateDlgFather::PersistenceParameter()
{
	CString str;
	CStdioFile input;
	input.Open(".\\spin\\input.dat",CFile::modeWrite | CFile::modeCreate | CFile::typeText);
	str.Format("%0.1f %0.1f %0.1f %0.1f      !dx,dy,dz,dt\n",
		this->m_calculateDlgChild1->m_edit_dx,this->m_calculateDlgChild1->m_edit_dy,this->m_calculateDlgChild1->m_edit_dz,this->m_calculateDlgChild1->m_edit_time_step_size);
	input.WriteString(str);
	str.Format("%d %d %d         !numsteps,stepst1,noise_steps\n",m_calculateDlgChild2->m_edit_total_nums_of_steps,m_calculateDlgChild2->m_edit_time_steps,m_calculateDlgChild2->m_edit_time_steps_with_noise);
	input.WriteString(str);
	str.Format("%0.1f %0.1f           !L1,Mc,kappa,kappa_c\n",m_calculateDlgChild1->m_edit_atmmobility,m_calculateDlgChild1->m_edit_gradcoef);
	input.WriteString(str);
	str.Format("%d                    !iseed\n",m_calculateDlgChild1->m_edit_random_seed);
	input.WriteString(str);
	str.Format("%0.1f                   !noise_level\n",m_calculateDlgChild1->m_edit_noise);
	input.WriteString(str);
	if (!m_calculateDlgChild1->m_radio_new_start)
	{
		str.Format("%d %d                   !initflag,initcount",0,0);
		input.WriteString(str);
	}

	input.Close();
}



void CalculateDlgFather::OnBnClickedButtonOk()
{
	// TODO: Add your control notification handler code here

	this->m_calculateDlgChild1->UpdateData(TRUE);
	this->m_calculateDlgChild2->UpdateData(TRUE);
	this->m_calculateDlgChild3->UpdateData(TRUE);
	this->PersistenceParameter();
}


void CalculateDlgFather::OnBnClickedRun()
{
	// TODO: Add your control notification handler code here
	// �����������
	this->m_RunType = 1;
	CDialog::OnOK();

}

void CalculateDlgFather::OnBnClickedButtonFile()
{
	this->m_RunType = 2;
	// TODO: Add your control notification handler code here
	CString FilePathName;
	CString temp;
	CFileDialog dlg(TRUE);///TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
	if(dlg.DoModal()==IDOK){
		FilePathName=dlg.GetPathName();
		::MessageBox(NULL,_T(FilePathName),_T("Input from file"),MB_OK);
		temp.Format("%s %s",".\\spin\\Spinodal01.exe",FilePathName);
		//WinExec(temp,SW_HIDE);

		CString path;
		char curpath[256];
		GetCurrentDirectory(256,curpath);
		//printf("%s\n",curpath);
		path =(CString)curpath;
		path.Append("\\spin");
		//printf ("���ÿ�ʼ\n");
		STARTUPINFO si = { sizeof(si) }; 
		PROCESS_INFORMATION pi; 

		si.dwFlags = STARTF_USESHOWWINDOW; 
		si.wShowWindow = TRUE; //TRUE��ʾ��ʾ�����Ľ��̵Ĵ���
		TCHAR cmdline[] =TEXT(".\\spin\\Spinodal01.exe .\\spin\\input.dat");
		BOOL bRet = ::CreateProcess ( 
			NULL,
			cmdline, //��Unicode�汾�д˲�������Ϊ�����ַ�������Ϊ�˲����ᱻ�޸�
			NULL,
			NULL,
			FALSE,
			CREATE_NO_WINDOW,
			NULL,
			path, 
			&si,
			&pi); 

		int error = GetLastError();
		if(bRet) 
		{ 
			::CloseHandle (pi.hThread); 
			::CloseHandle (pi.hProcess); 

			//printf(" �½��̵Ľ���ID�ţ�%d \n", pi.dwProcessId); 
			//printf(" �½��̵����߳�ID�ţ�%d \n", pi.dwThreadId); 
		} 
		else
		{
			//printf("error code:%d\n",error );
		}
		//printf("���ý���");
		CDialog::OnOK();
	}

}
