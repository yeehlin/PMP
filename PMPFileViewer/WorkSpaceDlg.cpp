// WorkSpaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PMPFileViewer.h"
#include "WorkSpaceDlg.h"
#include "afxdialogex.h"


// CWorkSpaceDlg dialog

IMPLEMENT_DYNAMIC(CWorkSpaceDlg, CDialog)

CWorkSpaceDlg::CWorkSpaceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWorkSpaceDlg::IDD, pParent)
{
	folderpath = "";

	m_combo_workspace_string = _T("");
}

CWorkSpaceDlg::~CWorkSpaceDlg()
{
}

void CWorkSpaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_WORKSPACE, m_ComboWorkspace);
	DDX_CBString(pDX, IDC_COMBO_WORKSPACE, m_combo_workspace_string);
}


BEGIN_MESSAGE_MAP(CWorkSpaceDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_WORKSPACE, &CWorkSpaceDlg::OnBnClickedButtonSelectWorkspace)
END_MESSAGE_MAP()


// CWorkSpaceDlg message handlers


void CWorkSpaceDlg::OnBnClickedButtonSelectWorkspace()
{
	// TODO: Add your control notification handler code here
		//// TODO: 在此添加控件通知处理程序代码
	folderpath = CWorkSpaceDlg::Show();
	SetDlgItemText(IDC_COMBO_WORKSPACE,folderpath);
	/*
		CString m_FileDir;
		BROWSEINFO bi;
		ZeroMemory(&bi, sizeof(BROWSEINFO));
		bi.hwndOwner = m_hWnd;
		bi.ulFlags   = BIF_RETURNONLYFSDIRS;
		LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
		BOOL bRet = FALSE;
		TCHAR szFolder[MAX_PATH*2];
		szFolder[0] = _T('/0');
		if (pidl)
		{
			if (SHGetPathFromIDList(pidl, szFolder))  
				bRet = TRUE;
			IMalloc *pMalloc = NULL;
			if (SUCCEEDED(SHGetMalloc(&pMalloc)) && pMalloc)
			{ 
				pMalloc->Free(pidl); 
				pMalloc->Release();
			}
		}
		m_FileDir = szFolder;//选择的文件夹路径
		TRACE("/n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&/n");
		TRACE(m_FileDir);
		TRACE("/n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&/n");
		SetDlgItemText(IDC_COMBO_WORKSPACE,m_FileDir);
		OnPaint();
		*/
}


BOOL CWorkSpaceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	// 读取工作空间目录，回填到下拉框
	CString workpath="";
	CStdioFile temp;
	if(temp.Open("workspace.txt",CFile::modeRead|CFile::typeText)){
		temp.ReadString(workpath);
		folderpath = workpath;
	}
	m_ComboWorkspace.AddString(workpath);
	m_ComboWorkspace.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
