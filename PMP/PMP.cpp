
// PMP.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "PMP.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "PMPDoc.h"
#include "PMPView.h"
#include "PMPBmpDoc.h"
#include "PMPBmpView.h"
#include "PMPTxtDoc.h"
#include "PMPTxtView.h"
#include "PMPDatDoc.h"
#include "PMPDatView.h"
#include "PMPDatStreamlineView.h"
#include "PMPTensorDatDoc.h"
#include "PMPTensorDatView.h"
#include "PMPTensorDatTensoView.h"
#include "PMPTensorDatMultiView.h"
#include "PMPScalarDatDoc.h"
#include "PMPScalarDatView.h"
#include "PMPScalarDatGridView.h"
#include "PMPVectorDatVolumeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPMPApp

BEGIN_MESSAGE_MAP(CPMPApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CPMPApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CPMPApp construction

CPMPApp::CPMPApp()
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
	SetAppID(_T("PMP.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CPMPApp object

CPMPApp theApp;


// CPMPApp initialization

BOOL CPMPApp::InitInstance()
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
	/////////////////////////////////////添加模板/////////////////////////////////////
	// 用于动画显示图片
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_PMPTYPE,
		RUNTIME_CLASS(CPMPDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);
	// 用于显示图片
	m_pBmpDocTemplate = new CMultiDocTemplate(IDR_BMPTYPE,
		RUNTIME_CLASS(CPMPBmpDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPBmpView));
	if (!m_pBmpDocTemplate)
		return FALSE;
	AddDocTemplate(m_pBmpDocTemplate);
	// 用于显示文本
	m_pTxtDocTemplate = new CMultiDocTemplate(IDR_TXTTYPE,
		RUNTIME_CLASS(CPMPTxtDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPTxtView));
	if (!m_pTxtDocTemplate)
		return FALSE;
	AddDocTemplate(m_pTxtDocTemplate);
	////////////////////////////////////向量图模板//////////////////////////////////////
	// 用于绘图-向量图polarization
	m_pDatDocTemplate = new CMultiDocTemplate(IDR_VECTORDATTYPE,
		RUNTIME_CLASS(CPMPDatDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPDatView));
	if (!m_pDatDocTemplate)
		return FALSE;
	AddDocTemplate(m_pDatDocTemplate);

	// 用于绘图-向量图streamline
	m_pDatDocStrmlineTemplate = new CMultiDocTemplate(IDR_VECTORDATTYPE,
		RUNTIME_CLASS(CPMPDatDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPDatStreamlineView));
	if (!m_pDatDocStrmlineTemplate)
		return FALSE;
	AddDocTemplate(m_pDatDocStrmlineTemplate);
	// 用于绘图向量数据Volume
	m_pDatDocVolumeTemplate = new CMultiDocTemplate(IDR_VECTORDATTYPE,
		RUNTIME_CLASS(CPMPDatDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPVectorDatVolumeView));
	if (!m_pDatDocVolumeTemplate)
		return FALSE;
	AddDocTemplate(m_pDatDocVolumeTemplate);
	////////////////////////////////////张量图模板//////////////////////////////////////
	// 用于绘图-张量量图strain
	m_pTensorDatDocTemplate = new CMultiDocTemplate(IDR_TENSORDATTYPE,
		RUNTIME_CLASS(CPMPTensorDatDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPTensorDatView));
	if (!m_pTensorDatDocTemplate)
		return FALSE;
	AddDocTemplate(m_pTensorDatDocTemplate);
	// 用于绘图-张量量图tensor
	m_pTensorDatDocTensoTemplate = new CMultiDocTemplate(IDR_TENSORDATTYPE,
		RUNTIME_CLASS(CPMPTensorDatDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPTensorDatTensoView));
	if (!m_pTensorDatDocTensoTemplate)
		return FALSE;
	AddDocTemplate(m_pTensorDatDocTensoTemplate);
	// 用于绘图-张量量图multiview
	m_pTensorDatDocMultiTemplate = new CMultiDocTemplate(IDR_TENSORDATTYPE,
		RUNTIME_CLASS(CPMPTensorDatDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPTensorDatMultiView));
	if (!m_pTensorDatDocMultiTemplate)
		return FALSE;
	AddDocTemplate(m_pTensorDatDocMultiTemplate);

	//////////////////////////////////标量图模板////////////////////////////////////////
	// 用于绘图-标量图
	m_pScalarDatDocTemplate = new CMultiDocTemplate(IDR_SCALARDATTYPE,
		RUNTIME_CLASS(CPMPScalarDatDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPScalarDatView));
	if (!m_pScalarDatDocTemplate)
		return FALSE;
	AddDocTemplate(m_pScalarDatDocTemplate);
	m_pScalarDatDocGridTemplate = new CMultiDocTemplate(IDR_SCALARDATTYPE,
		RUNTIME_CLASS(CPMPScalarDatDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPMPScalarDatGridView));
	if (!m_pScalarDatDocGridTemplate)
		return FALSE;
	AddDocTemplate(m_pScalarDatDocGridTemplate);
	////////////////////////////////////模板创建结束//////////////////////////////////////
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
	//cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;

	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The main window has been initialized, so show and update it
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CPMPApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	// 销毁模板
	//if (m_pPMPDocTemplate != NULL){delete m_pPMPDocTemplate;}
	//if (m_pBmpDocTemplate != NULL){delete m_pBmpDocTemplate;}
	//if (m_pTxtDocTemplate != NULL){delete m_pTxtDocTemplate;}
	//if (m_pDatDocTemplate != NULL){delete m_pDatDocTemplate;}

	return CWinAppEx::ExitInstance();
}

// CPMPApp message handlers


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
void CPMPApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CPMPApp customization load/save methods

void CPMPApp::PreLoadState()
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

void CPMPApp::LoadCustomState()
{
}

void CPMPApp::SaveCustomState()
{
}

// CPMPApp message handlers



