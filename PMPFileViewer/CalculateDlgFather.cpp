// CalculateDlgFather.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
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

// 通过类向导添加该函数，在该函数中实现父对话框与子对话框的关系，这个关系要通过tab控件配合
BOOL CalculateDlgFather::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	// 初始化Tab

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
	// 添加tab页
	this->m_tab.InsertItem(2,&tcitem2);
	this->m_tab.InsertItem(3,&tcitem3);
	// 获得Tab控件的坐标，用于放置选项卡
	CRect tabRect;
	m_tab.GetClientRect(&tabRect);
	// 定位选项卡位置
	tabRect.bottom -=10;
	tabRect.left +=10;
	tabRect.top +=25;
	tabRect.right-=10;
	// 创建子对话框
	//calculateDlgChild[0].Create(IDD_CALCULATE_DLG_CHILD1,GetDlgItem(IDC_CALCULATE_DLG_TAB));
	//calculateDlgChild[1].Create(IDD_CALCULATE_DLG_CHILD2,GetDlgItem(IDC_CALCULATE_DLG_TAB));
	//calculateDlgChild[2].Create(IDD_CALCULATE_DLG_CHILD3,GetDlgItem(IDC_CALCULATE_DLG_TAB));
	m_calculateDlgChild1->Create(IDD_CALCULATE_DLG_CHILD1,GetDlgItem(IDC_CALCULATE_DLG_TAB));
	m_calculateDlgChild2->Create(IDD_CALCULATE_DLG_CHILD2,GetDlgItem(IDC_CALCULATE_DLG_TAB));
	m_calculateDlgChild3->Create(IDD_CALCULATE_DLG_CHILD3,GetDlgItem(IDC_CALCULATE_DLG_TAB));

	// 将子对话框移动到指定的位置
	//calculateDlgChild[0].MoveWindow(&tabRect);
	//calculateDlgChild[1].MoveWindow(&tabRect);
	//calculateDlgChild[2].MoveWindow(&tabRect);
	m_calculateDlgChild1->MoveWindow(&tabRect);
	m_calculateDlgChild2->MoveWindow(&tabRect);
	m_calculateDlgChild3->MoveWindow(&tabRect);
	// 显示子页面，但是绘制第一个子对话框，而隐藏其他的两个
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

// 在资源视图中，打开父对话框资源，双击Tab控件，出现相应处理函数，或者右键相关控件也会出现针对该控件的处理函数
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


// 接口：该接口可以将对话框中的参数写入一个文件
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
	// 设置运行类别
	this->m_RunType = 1;
	CDialog::OnOK();

}

void CalculateDlgFather::OnBnClickedButtonFile()
{
	this->m_RunType = 2;
	// TODO: Add your control notification handler code here
	CString FilePathName;
	CString temp;
	CFileDialog dlg(TRUE);///TRUE为OPEN对话框，FALSE为SAVE AS对话框
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
		//printf ("调用开始\n");
		STARTUPINFO si = { sizeof(si) }; 
		PROCESS_INFORMATION pi; 

		si.dwFlags = STARTF_USESHOWWINDOW; 
		si.wShowWindow = TRUE; //TRUE表示显示创建的进程的窗口
		TCHAR cmdline[] =TEXT(".\\spin\\Spinodal01.exe .\\spin\\input.dat");
		BOOL bRet = ::CreateProcess ( 
			NULL,
			cmdline, //在Unicode版本中此参数不能为常量字符串，因为此参数会被修改
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

			//printf(" 新进程的进程ID号：%d \n", pi.dwProcessId); 
			//printf(" 新进程的主线程ID号：%d \n", pi.dwThreadId); 
		} 
		else
		{
			//printf("error code:%d\n",error );
		}
		//printf("调用结束");
		CDialog::OnOK();
	}

}
