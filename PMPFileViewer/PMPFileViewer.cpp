
// PMPFileViewer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "PMPFileViewer.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "PMPFileViewerDoc.h"
#include "PMPFileViewerView.h"
#include "PMPBMPFile.h"
#include "PMPBMPFileView.h"
#include "PMPDatDoc.h"
#include "PMPDatView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPMPFileViewerApp

BEGIN_MESSAGE_MAP(CPMPFileViewerApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CPMPFileViewerApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	ON_COMMAND(ID_MAINFRM_SPINODALDECOMPOSITION_CALCULATE, &CPMPFileViewerApp::OnMainfrmSpinodaldecompositionCalculate)
	ON_COMMAND(ID_MAINFRM_PHASEMODELING_CALCULATE, &CPMPFileViewerApp::OnMainfrmPhasemodelingCalculate)
END_MESSAGE_MAP()


// CPMPFileViewerApp construction

CPMPFileViewerApp::CPMPFileViewerApp()
{
	m_bHiColorIcons = TRUE;

	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("PMPFileViewer.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CPMPFileViewerApp object

CPMPFileViewerApp theApp;


// CPMPFileViewerApp initialization

BOOL CPMPFileViewerApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	//CMultiDocTemplate* pDocTemplate;
	// 添加新模板，用于读取文本文件，显示文本
	m_pTxtDocTemplate = new CMultiDocTemplate(IDR_TEXTTYPE,
		RUNTIME_CLASS(CPMPBMPFile),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPBMPFileView));
	if (!m_pTxtDocTemplate)
		return FALSE;
	AddDocTemplate(m_pTxtDocTemplate);
	// 添加新模板，用于读取图片文件，显示图片
	m_pBmpDocTemplate = new CMultiDocTemplate(IDR_BMPTYPE,
		RUNTIME_CLASS(CPMPFileViewerDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPFileViewerView));
	if (!m_pBmpDocTemplate)
		return FALSE;
	AddDocTemplate(m_pBmpDocTemplate);
	// 增加新模板，用于读取文本文件，并绘制图形
	m_pDatDocTemplate = new CMultiDocTemplate(IDR_BMPTYPE,
		RUNTIME_CLASS(CPMPDatDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPDatView));
	if (!m_pDatDocTemplate)
		return FALSE;
	//AddDocTemplate(m_pDatDocTemplate);
	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;
	// call DragAcceptFiles only if there's a suffix
	//  In an MDI app, this should occur immediately after setting m_pMainWnd

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	// 新加的行，使软件运行不默认创建新文档
	cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The main window has been initialized, so show and update it
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CPMPFileViewerApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CPMPFileViewerApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CPMPFileViewerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CPMPFileViewerApp customization load/save methods

void CPMPFileViewerApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CPMPFileViewerApp::LoadCustomState()
{
}

void CPMPFileViewerApp::SaveCustomState()
{
}

// CPMPFileViewerApp message handlers





void CPMPFileViewerApp::OnMainfrmSpinodaldecompositionCalculate()
{
	// TODO: Add your command handler code here
	CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
	pMainFrame->getFileViewWnd()->FillFileViewByModuleType(1);
	pMainFrame->getFileViewWnd()->SetModuleType(1);
	pMainFrame->getFileViewWnd()->getFileTreeView()->setModuleType(1);
	pMainFrame->getFileViewWnd()->SetTimer(TIMER_FOR_FILEVIEW,5000,NULL);
}


void CPMPFileViewerApp::OnMainfrmPhasemodelingCalculate()
{
	// TODO: Add your command handler code here
	CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
	pMainFrame->getFileViewWnd()->FillFileViewByModuleType(2);
	pMainFrame->getFileViewWnd()->SetModuleType(2);
	pMainFrame->getFileViewWnd()->getFileTreeView()->setModuleType(2);
	pMainFrame->getFileViewWnd()->SetTimer(TIMER_FOR_FILEVIEW_MDL2,4000,NULL);
}
