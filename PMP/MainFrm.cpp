
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "PMP.h"

#include "MainFrm.h"

#include "WorkSpaceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWndEx)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_WINDOW_MANAGER, &CMainFrame::OnWindowManager)
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_WM_SETTINGCHANGE()
//	ON_COMMAND(ID_MAINFRM_PHASEMODELING_CALCULATE, &CMainFrame::OnMainfrmPhasemodelingCalculate)
//	ON_COMMAND(ID_MAINFRM_SPINODALDECOMPOSITION_CALCULATE, &CMainFrame::OnMainfrmSpinodaldecompositionCalculate)
//	ON_COMMAND(ID_BUTTON_SUSPEND_256, &CPMPView::OnButtonSuspend256)
//	ON_COMMAND(ID_BUTTON_RESUME_256, &CPMPView::OnButtonResume256)
//	ON_COMMAND(ID_BUTTON_STOP_256, &CPMPView::OnButtonStop256)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_VS_2008);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

		// 要求用户设置工作控件目录
	///*
	CWorkSpaceDlg workSpaceDlg ;
	if(workSpaceDlg.DoModal()==IDOK && workSpaceDlg.folderpath != ""){
		// 取得用户指定的文件夹
		m_workSpacePath = workSpaceDlg.folderpath;
		// 将该文件夹名称留存，以便下次回填
		CStdioFile workspace ;
		workspace.Open("workspace.txt",CFile::modeCreate|CFile::modeWrite|CFile::typeText);
		workspace.WriteString(m_workSpacePath);
		// 如果工作空间目录不存在则创建
		DWORD dwAttr = GetFileAttributes(m_workSpacePath);
		if(dwAttr==-1||(dwAttr&FILE_ATTRIBUTE_DIRECTORY)==0)//目录不存在
		{
			if ( !MakeDir(m_workSpacePath))
			{
				AfxMessageBox("can't create directionary:"+m_workSpacePath);
				PostMessage(WM_QUIT,0,0);
				//return;
			}
		}
		// 将工作目录分发给fileview;
		m_wndFileView.workspace = m_workSpacePath;

	}else{
		PostMessage(WM_QUIT,0,0);
	}
	//*/


	if (CMDIFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;
	// set the visual manager and style based on persisted value
	OnApplicationLook(theApp.m_nAppLook);

	CMDITabInfo mdiTabParams;
	mdiTabParams.m_style = CMFCTabCtrl::STYLE_3D_ONENOTE; // other styles available...
	mdiTabParams.m_bActiveTabCloseButton = TRUE;      // set to FALSE to place close button at right of tab area
	mdiTabParams.m_bTabIcons = FALSE;    // set to TRUE to enable document icons on MDI taba
	mdiTabParams.m_bAutoColor = TRUE;    // set to FALSE to disable auto-coloring of MDI tabs
	mdiTabParams.m_bDocumentMenu = TRUE; // enable the document menu at the right edge of the tab area
	EnableMDITabbedGroups(TRUE, mdiTabParams);

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("Failed to create menubar\n");
		return -1;      // fail to create
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

	// prevent the menu bar from taking the focus on activation
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(theApp.m_bHiColorIcons ? IDR_MAINFRAME_256 : IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	CString strToolBarName;
	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	ASSERT(bNameValid);
	m_wndToolBar.SetWindowText(strToolBarName);

	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);
	m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);

	// Allow user-defined toolbars operations:
	InitUserToolbars(NULL, uiFirstUserToolBarId, uiLastUserToolBarId);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these five lines if you don't want the toolbar and menubar to be dockable
	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndMenuBar);
	DockPane(&m_wndToolBar);


	// enable Visual Studio 2005 style docking window behavior
	CDockingManager::SetDockingMode(DT_SMART);
	// enable Visual Studio 2005 style docking window auto-hide behavior
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// Load menu item image (not placed on any standard toolbars):
	CMFCToolBar::AddToolBarForImageCollection(IDR_MENU_IMAGES, theApp.m_bHiColorIcons ? IDB_MENU_IMAGES_24 : 0);

	// create docking windows
	// 创建类视图，文件视图，但是这里不需要类视图
	if (!CreateDockingWindows())
	{
		TRACE0("Failed to create docking windows\n");
		return -1;
	}

	m_wndFileView.EnableDocking(CBRS_ALIGN_ANY);
	m_wndClassView.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndFileView);
	CDockablePane* pTabbedBar = NULL;
	// 去掉类视图
	//m_wndClassView.AttachToTabWnd(&m_wndFileView, DM_SHOW, TRUE, &pTabbedBar);
	m_wndOutput.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndOutput);
	m_wndProperties.EnableDocking(CBRS_ALIGN_ANY);
	// 去掉属性视图
	//DockPane(&m_wndProperties);


	// Enable enhanced windows management dialog
	EnableWindowsDialog(ID_WINDOW_MANAGER, ID_WINDOW_MANAGER, TRUE);

	// Enable toolbar and docking window menu replacement
	EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// enable quick (Alt+drag) toolbar customization
	CMFCToolBar::EnableQuickCustomization();

	if (CMFCToolBar::GetUserImages() == NULL)
	{
		// load user-defined toolbar images
		if (m_UserImages.Load(_T(".\\UserImages.bmp")))
		{
			CMFCToolBar::SetUserImages(&m_UserImages);
		}
	}

	// enable menu personalization (most-recently used commands)
	// TODO: define your own basic commands, ensuring that each pulldown menu has at least one basic command.
	// 菜单默认展开
	/*
	CList<UINT, UINT> lstBasicCommands;

	lstBasicCommands.AddTail(ID_FILE_NEW);
	lstBasicCommands.AddTail(ID_FILE_OPEN);
	lstBasicCommands.AddTail(ID_FILE_SAVE);
	lstBasicCommands.AddTail(ID_FILE_PRINT);
	lstBasicCommands.AddTail(ID_APP_EXIT);
	lstBasicCommands.AddTail(ID_EDIT_CUT);
	lstBasicCommands.AddTail(ID_EDIT_PASTE);
	lstBasicCommands.AddTail(ID_EDIT_UNDO);
	lstBasicCommands.AddTail(ID_APP_ABOUT);
	lstBasicCommands.AddTail(ID_VIEW_STATUS_BAR);
	lstBasicCommands.AddTail(ID_VIEW_TOOLBAR);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2003);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_VS_2005);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_BLUE);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_SILVER);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_BLACK);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_OFF_2007_AQUA);
	lstBasicCommands.AddTail(ID_VIEW_APPLOOK_WINDOWS_7);
	lstBasicCommands.AddTail(ID_SORTING_SORTALPHABETIC);
	lstBasicCommands.AddTail(ID_SORTING_SORTBYTYPE);
	lstBasicCommands.AddTail(ID_SORTING_SORTBYACCESS);
	lstBasicCommands.AddTail(ID_SORTING_GROUPBYTYPE);

	CMFCToolBar::SetBasicCommands(lstBasicCommands);
	//*/

	// Switch the order of document name and application name on the window title bar. This
	// improves the usability of the taskbar because the document name is visible with the thumbnail.
	ModifyStyle(0, FWS_PREFIXTITLE);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

BOOL CMainFrame::CreateDockingWindows()
{
	BOOL bNameValid;

	// Create class view
	CString strClassView;
	bNameValid = strClassView.LoadString(IDS_CLASS_VIEW);
	ASSERT(bNameValid);
	if (!m_wndClassView.Create(strClassView, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_CLASSVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create Class View window\n");
		return FALSE; // failed to create
	}

	// Create file view
	CString strFileView;
	bNameValid = strFileView.LoadString(IDS_FILE_VIEW);
	ASSERT(bNameValid);
	if (!m_wndFileView.Create(strFileView, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_FILEVIEW, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT| CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create File View window\n");
		return FALSE; // failed to create
	}

	// Create output window
	CString strOutputWnd;
	bNameValid = strOutputWnd.LoadString(IDS_OUTPUT_WND);
	ASSERT(bNameValid);
	if (!m_wndOutput.Create(strOutputWnd, this, CRect(0, 0, 100, 100), TRUE, ID_VIEW_OUTPUTWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create Output window\n");
		return FALSE; // failed to create
	}

	// Create properties window
	CString strPropertiesWnd;
	bNameValid = strPropertiesWnd.LoadString(IDS_PROPERTIES_WND);
	ASSERT(bNameValid);
	if (!m_wndProperties.Create(strPropertiesWnd, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_PROPERTIESWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_RIGHT | CBRS_FLOAT_MULTI))
	{
		TRACE0("Failed to create Properties window\n");
		return FALSE; // failed to create
	}

	SetDockingWindowIcons(theApp.m_bHiColorIcons);
	return TRUE;
}

void CMainFrame::SetDockingWindowIcons(BOOL bHiColorIcons)
{
	HICON hFileViewIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_FILE_VIEW_HC : IDI_FILE_VIEW), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndFileView.SetIcon(hFileViewIcon, FALSE);

	HICON hClassViewIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_CLASS_VIEW_HC : IDI_CLASS_VIEW), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndClassView.SetIcon(hClassViewIcon, FALSE);

	HICON hOutputBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_OUTPUT_WND_HC : IDI_OUTPUT_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndOutput.SetIcon(hOutputBarIcon, FALSE);

	HICON hPropertiesBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_PROPERTIES_WND_HC : IDI_PROPERTIES_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndProperties.SetIcon(hPropertiesBarIcon, FALSE);

	UpdateMDITabbedBarsIcons();
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnWindowManager()
{
	ShowWindowsDialog();
}

void CMainFrame::OnViewCustomize()
{
	CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog(this, TRUE /* scan menus */);
	pDlgCust->EnableUserDefinedToolbars();
	pDlgCust->Create();
}

LRESULT CMainFrame::OnToolbarCreateNew(WPARAM wp,LPARAM lp)
{
	LRESULT lres = CMDIFrameWndEx::OnToolbarCreateNew(wp,lp);
	if (lres == 0)
	{
		return 0;
	}

	CMFCToolBar* pUserToolbar = (CMFCToolBar*)lres;
	ASSERT_VALID(pUserToolbar);

	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	return lres;
}

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}

BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext) 
{
	// base class does the real work

	if (!CMDIFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}


	// enable customization button for all user toolbars
	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	for (int i = 0; i < iMaxUserToolbars; i ++)
	{
		CMFCToolBar* pUserToolbar = GetUserToolBarByIndex(i);
		if (pUserToolbar != NULL)
		{
			pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
		}
	}

	return TRUE;
}


void CMainFrame::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CMDIFrameWndEx::OnSettingChange(uFlags, lpszSection);
	m_wndOutput.UpdateFonts();
}

//void CMainFrame::OnMainfrmSpinodaldecompositionCalculate()
//{
//	// TODO: Add your command handler code here
//	if (m_pcalculateDlgFather == NULL){
//		this->m_pcalculateDlgFather = new CalculateDlgFather();
//	}
//	if(this->m_pcalculateDlgFather->DoModal()==IDOK){
//		// 启动iew中的时钟
//		//POSITION pos = this->GetFirstViewPosition();
//		//CPMPView * pCPMPView = (CPMPView *)this->GetNextView(pos);
//		switch (m_pcalculateDlgFather->m_RunType)
//		{
//		case 1:
//			CString path;
//			char curpath[256];
//			GetCurrentDirectory(256,curpath);
//			path =(CString)curpath;
//			path.Append("\\spin");
//
//			TCHAR cmdline[] =TEXT(".\\spin\\Spinodal01.exe .\\spin\\input.dat");
//			SECURITY_ATTRIBUTES sa={sizeof ( sa ),NULL,TRUE};
//			sa.bInheritHandle=true;
//			sa.lpSecurityDescriptor=NULL;
//			SECURITY_ATTRIBUTES *psa=NULL;
//			DWORD dwShareMode=FILE_SHARE_READ|FILE_SHARE_WRITE;
//			//*
//			OSVERSIONINFO osVersion;
//			osVersion.dwOSVersionInfoSize =sizeof ( osVersion );
//			if ( GetVersionEx ( &osVersion ) )
//			{
//				if ( osVersion.dwPlatformId ==VER_PLATFORM_WIN32_NT )
//				{
//					psa=&sa;
//					dwShareMode|=FILE_SHARE_DELETE;
//				}
//			}
//			//*/
//			//根据版本设置共享模式和安全属性
//			HANDLE hConsoleRedirect=CreateFile (
//				"F:\\output.txt",
//				GENERIC_WRITE,
//				dwShareMode,
//				psa,
//				OPEN_ALWAYS,
//				FILE_ATTRIBUTE_NORMAL,
//				NULL );
//			ASSERT ( hConsoleRedirect!=INVALID_HANDLE_VALUE );
//			STARTUPINFO si={ sizeof ( si ) };
//			si.dwFlags =STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
//			//使用标准柄和显示窗口
//			si.hStdOutput =hConsoleRedirect;//将文件作为标准输出句柄
//			si.wShowWindow = SW_SHOW; //TRUE表示显示创建的进程的窗口
//			BOOL bRet = ::CreateProcess ( 
//				NULL,
//				cmdline, //在Unicode版本中此参数不能为常量字符串，因为此参数会被修改
//				NULL,
//				NULL,
//				TRUE,
//				CREATE_NEW_CONSOLE,
//				NULL,
//				path, 
//				&si,
//				&pi); 
//
//			int error = GetLastError();
//			if(bRet) 
//			{ 
//				//::CloseHandle (pi.hThread); 
//				//::CloseHandle (pi.hProcess); 
//
//				//printf(" 新进程的进程ID号：%d \n", pi.dwProcessId); 
//				//printf(" 新进程的主线程ID号：%d \n", pi.dwThreadId); 
//			} 
//			else
//			{
//				//printf("error code:%d\n",error );
//			}
//			CloseHandle ( hConsoleRedirect );
//			//printf("调用结束");
//			SetTimer(TIMER_ONE_SECOND,1000,NULL);
//			// 启动FileView中的时钟
//			CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
//			pMainFrame->getFileView()->SetTimer(TIMER_TWO_SECOND,5000,NULL);
//			pMainFrame->getFileView()->FillFileViewByType(1);
//			break;
//		}
//
//	}
//}


//void CMainFrame::OnMainfrmPhasemodelingCalculate()
//{
//	// TODO: Add your command handler code here
//	// TODO: Add your command handler code here
//	if (m_pelectricModelingDLGFather == NULL){
//		this->m_pelectricModelingDLGFather = new ElectricModelingDLGFather();
//	}
//	if(this->m_pelectricModelingDLGFather->DoModal()==IDOK){
//		// 启动iew中的时钟
//		//POSITION pos = this->GetFirstViewPosition();
//		//CPMPView * pCPMPView = (CPMPView *)this->GetNextView(pos);
//		switch (m_pelectricModelingDLGFather->m_RunType)
//		{
//		case 2:
//			CString path;
//			char curpath[256];
//			GetCurrentDirectory(256,curpath);
//			path =(CString)curpath;
//			path.Append("\\piez");
//
//			TCHAR cmdline[] =TEXT(".\\piez\\pieze.exe");
//			SECURITY_ATTRIBUTES sa={sizeof ( sa ),NULL,TRUE};
//			sa.bInheritHandle=true;
//			sa.lpSecurityDescriptor=NULL;
//			SECURITY_ATTRIBUTES *psa=NULL;
//			DWORD dwShareMode=FILE_SHARE_READ|FILE_SHARE_WRITE;
//			//*
//			OSVERSIONINFO osVersion;
//			osVersion.dwOSVersionInfoSize =sizeof ( osVersion );
//			if ( GetVersionEx ( &osVersion ) )
//			{
//				if ( osVersion.dwPlatformId ==VER_PLATFORM_WIN32_NT )
//				{
//					psa=&sa;
//					dwShareMode|=FILE_SHARE_DELETE;
//				}
//			}
//			//*/
//			//根据版本设置共享模式和安全属性
//			HANDLE hConsoleRedirect=CreateFile (
//				"F:\\output.txt",
//				GENERIC_WRITE,
//				dwShareMode,
//				psa,
//				OPEN_ALWAYS,
//				FILE_ATTRIBUTE_NORMAL,
//				NULL );
//			ASSERT ( hConsoleRedirect!=INVALID_HANDLE_VALUE );
//			STARTUPINFO si={ sizeof ( si ) };
//			si.dwFlags =STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
//			//使用标准柄和显示窗口
//			si.hStdOutput =hConsoleRedirect;//将文件作为标准输出句柄
//			si.wShowWindow = SW_SHOW; //TRUE表示显示创建的进程的窗口
//			BOOL bRet = ::CreateProcess ( 
//				NULL,
//				cmdline, //在Unicode版本中此参数不能为常量字符串，因为此参数会被修改
//				NULL,
//				NULL,
//				TRUE,
//				CREATE_NEW_CONSOLE,
//				NULL,
//				path, 
//				&si,
//				&pi); 
//
//			int error = GetLastError();
//			if(bRet) 
//			{ 
//				//::CloseHandle (pi.hThread); 
//				//::CloseHandle (pi.hProcess); 
//
//				//printf(" 新进程的进程ID号：%d \n", pi.dwProcessId); 
//				//printf(" 新进程的主线程ID号：%d \n", pi.dwThreadId); 
//			} 
//			else
//			{
//				//printf("error code:%d\n",error );
//			}
//			CloseHandle ( hConsoleRedirect );
//			//printf("调用结束");
//			SetTimer(TIMER_PIEZ_OUTPUT,1000,NULL);
//			// 启动FileView中的时钟
//			CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
//			pMainFrame->getFileView()->SetTimer(TIMER_PIEZ_SECOND,5000,NULL);
//			pMainFrame->getFileView()->FillFileViewByType(2);
//			break;
//		}
//
//	}
//}
//创建目录（支持多重创建）
BOOL CMainFrame::MakeDir(CString szDirName)
{
	HANDLE fFile;
	WIN32_FIND_DATA fileinfo;
	CStringArray m_arr;
	BOOL tt;
	int x1 = 0;
	CString tem = "";

	fFile = FindFirstFile(szDirName, &fileinfo);

	if (fileinfo.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
	{
		FindClose(fFile);
		return FALSE;
	}
	m_arr.RemoveAll();

	for(x1 = 0; x1 < szDirName.GetLength(); x1 ++)
	{
		if (szDirName.GetAt(x1) != '\\')
			tem += szDirName.GetAt(x1);
		else
		{
			m_arr.Add(tem);
			tem += "\\";
		}

		if (x1 == szDirName.GetLength() - 1)
			m_arr.Add(tem);
	}
	FindClose(fFile);

	for (x1 = 1; x1 < m_arr.GetSize(); x1++)
	{
		tem = m_arr.GetAt(x1);
		tt = CreateDirectory(tem, NULL);
		if (tt)
			SetFileAttributes(tem, FILE_ATTRIBUTE_NORMAL);
	}

	fFile = FindFirstFile(szDirName, &fileinfo);
	m_arr.RemoveAll();
	if (fileinfo.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
	{
		FindClose(fFile);
		return TRUE;
	}
	else
	{
		FindClose(fFile);
		return FALSE;
	}
}