
// PMPView.cpp : implementation of the CPMPView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PMP.h"
#endif

#include "PMPDoc.h"
#include "PMPView.h"

#include "vtkWin32OpenGLRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkCallbackCommand.h"
#include "vtkInteractorStyleTrackballCamera.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPMPView

IMPLEMENT_DYNCREATE(CPMPView, CView)

BEGIN_MESSAGE_MAP(CPMPView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPMPView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_COMMAND(ID_SPINODALDECOMPOSITION_CALCULATE, &CPMPView::OnSpinodaldecompositionCalculate)
	ON_COMMAND(ID_PHASEMODELING_CALCULATE, &CPMPView::OnPhasemodelingCalculate)
	ON_COMMAND(ID_BUTTON_SUSPEND_256, &CPMPView::OnButtonSuspend256)
	ON_COMMAND(ID_BUTTON_RESUME_256, &CPMPView::OnButtonResume256)
	ON_COMMAND(ID_BUTTON_STOP_256, &CPMPView::OnButtonStop256)
	ON_WM_CLOSE()
	ON_COMMAND(ID_TOOLS_PATTERNRECOGNITION, &CPMPView::OnToolsPatternrecognition)
END_MESSAGE_MAP()

// CPMPView construction/destruction

CPMPView::CPMPView()
{
	// TODO: add construction code here
	this->m_pvtkMFCWindow = NULL;
	this->m_pvtkRenderer = vtkRenderer::New();
	this->i=1;
	//*************��ʼ���Ի���ָ��************
	this->m_pcalculateDlgFather = NULL;
	this->m_pelectricModelingDLGFather = NULL;
	// ��������ģ���ʶ
	this->m_CurrentMoldule = 0;
	flagsize =0;

	// ָ���ʼ��
	m_pSpinodalpc = NULL;
	m_pPiezopc = NULL;
	m_pPaternRecpc = NULL;
	// ����Ĭ�ϵĹ���Ŀ¼
	workdirectory = "F:\\PMPWorkspace";
	// ��MainFrame�еõ������ռ�·��
	CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
	workdirectory = pMainFrame->m_workSpacePath;
	
}

CPMPView::~CPMPView()
{
	if (this->m_pvtkMFCWindow) delete this->m_pvtkMFCWindow;
	if (this->m_pvtkRenderer) this->m_pvtkRenderer->Delete();
	//if (this->m_pcalculateDlgFather != NULL){
	//	delete this->m_pcalculateDlgFather;
	//}

	//TerminateThread(pi.hThread,0);
	//TerminateProcess(pi.hProcess,0);

	//::CloseHandle (pi.hThread); 
	//::CloseHandle (pi.hProcess); 
	if (m_pSpinodalpc !=NULL)
	{
		m_pSpinodalpc->PMPTerminateProcess();
	}
	if (m_pPiezopc != NULL)
	{
		m_pPiezopc->PMPTerminateProcess();
	}
	if (m_pPaternRecpc != NULL)
	{
		m_pPaternRecpc->PMPTerminateProcess();
	}
}

BOOL CPMPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPMPView drawing

void CPMPView::OnDraw(CDC* pDC)
{
	CPMPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	if (this->m_pvtkMFCWindow)
	{
		if (pDC->IsPrinting())
			this->m_pvtkMFCWindow->DrawDC(pDC);
	}
}


// CPMPView printing


void CPMPView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPMPView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPMPView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPMPView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPMPView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPMPView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPMPView diagnostics

#ifdef _DEBUG
void CPMPView::AssertValid() const
{
	CView::AssertValid();
}

void CPMPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPMPDoc* CPMPView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPMPDoc)));
	return (CPMPDoc*)m_pDocument;
}
#endif //_DEBUG


static void handle_double_click(vtkObject* obj, unsigned long,
	void*, void*)
{
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::SafeDownCast(obj);
	if(iren && iren->GetRepeatCount())
	{
		AfxMessageBox("Double Click");
	}
}
void CPMPView::ExecutePipeline()
{
	if (this->m_pvtkMFCWindow == NULL){
		this->m_pvtkMFCWindow = new vtkMFCWindow(this);
	}
	vtkInteractorStyleTrackballCamera *style =
		vtkInteractorStyleTrackballCamera::New();
	this->m_pvtkRenderer->SetBackground(0.0,0.0,0.4);
	this->m_pvtkMFCWindow->GetInteractor()->SetInteractorStyle(style);
	this->m_pvtkMFCWindow->GetRenderWindow()->AddRenderer(this->m_pvtkRenderer);
	// get double click events
	vtkCallbackCommand * callback = vtkCallbackCommand::New();
	callback->SetCallback(handle_double_click);
	this->m_pvtkMFCWindow->GetInteractor()->AddObserver(vtkCommand::LeftButtonPressEvent, callback, 1.0);
	callback->Delete();
}


// CPMPView message handlers



void CPMPView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	GetParent()->SetWindowTextA(GetDocument()->GetTitle());
	//ExecutePipeline();
}


void CPMPView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (this->m_pvtkMFCWindow)
	{
		this->m_pvtkMFCWindow->MoveWindow(0, 0, cx, cy);
	}
}


void CPMPView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	switch(nIDEvent){
	case 1:
			this->NextActor(this->i);
			ReadCMDOutput();
			//SetOutputList(m_outputList);
			break;
	case 2:
		ReadCMDOutput();
		break;
	}
	CView::OnTimer(nIDEvent);
}

void CPMPView::NextActor(int i)
{
	CString bmpname;
	if (i<10){
		bmpname.Format("%s%d%s","00",i,"comp.bmp");
	}else if (i <100){
		bmpname.Format("%s%d%s","0",i,"comp.bmp");
	}else {
		bmpname.Format("%d%s",i,"comp.bmp");
	}
	CString path;
	path =(CString)workdirectory;
	path.Append("\\spin\\");
	path.Append(bmpname);
	if(fileFind.FindFile(path)){
		if((bmpfile.Open(path,CFile::modeRead | CFile::typeBinary))){
			// �ܹ���˵������ļ����ڣ�����������ʾ
			bmpfile.Close();

			CRect vtkClient ;
			GetClientRect(&vtkClient);
			if (this->i==1){
				this->GetDocument()->CreateActors();
				this->GetDocument()->ExecutePipeline(path);
				this->ExecutePipeline();
				this->i++;
				this->GetDocument()->AddActors();
				this->m_pvtkMFCWindow->RedrawWindow(vtkClient);
			}else{
				this->GetDocument()->RemoveActors();
				this->GetDocument()->DestroyActors();

				this->GetDocument()->CreateActors();
				this->GetDocument()->ExecutePipeline(path);
				this->i++;
				this->GetDocument()->AddActors();
				this->m_pvtkMFCWindow->RedrawWindow(vtkClient);
			}

		}else{
		}
	}else{
		if(this->i==1){}
		else{this->i--;}
		
	}
	// ����ҵ���100ͼƬ�������ʱ��
	if (this->i==101){
		KillTimer(TIMER_ONE_SECOND);
	}
}

int CPMPView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	//SetTimer(TIMER_ONE_SECOND,3000,NULL);
	return 0;
}

void CPMPView::OnSpinodaldecompositionCalculate()
{
	// TODO: Add your command handler code here
	if (m_pcalculateDlgFather == NULL){
		this->m_pcalculateDlgFather = new CalculateDlgFather();
	}
	if(this->m_pcalculateDlgFather->DoModal()==IDOK){
		// ����iew�е�ʱ��
		//POSITION pos = this->GetFirstViewPosition();
		//CPMPView * pCPMPView = (CPMPView *)this->GetNextView(pos);
		switch (m_pcalculateDlgFather->m_RunType)
		{
		case 1:
			/*
			CString path;
			char curpath[256];
			GetCurrentDirectory(256,curpath);
			path =(CString)curpath;
			path.Append("\\spin");

			TCHAR cmdline[] =TEXT(".\\spin\\Spinodal01.exe .\\spin\\input.dat");
			SECURITY_ATTRIBUTES sa={sizeof ( sa ),NULL,TRUE};
			sa.bInheritHandle=true;
			sa.lpSecurityDescriptor=NULL;
			SECURITY_ATTRIBUTES *psa=NULL;
			DWORD dwShareMode=FILE_SHARE_READ|FILE_SHARE_WRITE;
			
			OSVERSIONINFO osVersion;
			osVersion.dwOSVersionInfoSize =sizeof ( osVersion );
			if ( GetVersionEx ( &osVersion ) )
			{
				if ( osVersion.dwPlatformId ==VER_PLATFORM_WIN32_NT )
				{
					psa=&sa;
					dwShareMode|=FILE_SHARE_DELETE;
				}
			}
			
			//���ݰ汾���ù���ģʽ�Ͱ�ȫ����
			HANDLE hConsoleRedirect=CreateFile (
				".\\output.txt",
				GENERIC_WRITE,
				dwShareMode,
				psa,
				CREATE_ALWAYS,
				FILE_ATTRIBUTE_NORMAL,
				NULL );
			ASSERT ( hConsoleRedirect!=INVALID_HANDLE_VALUE );
			STARTUPINFO si={ sizeof ( si ) };
			si.dwFlags =STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
			//ʹ�ñ�׼������ʾ����
			si.hStdOutput =hConsoleRedirect;//���ļ���Ϊ��׼������
			si.wShowWindow = SW_HIDE; //TRUE��ʾ��ʾ�����Ľ��̵Ĵ���
			BOOL bRet = ::CreateProcess ( 
				NULL,
				cmdline, //��Unicode�汾�д˲�������Ϊ�����ַ�������Ϊ�˲����ᱻ�޸�
				NULL,
				NULL,
				TRUE,
				NULL,
				NULL,
				path, 
				&si,
				&pi); 

			int error = GetLastError();
			if(bRet) 
			{ 
				//::CloseHandle (pi.hThread); 
				//::CloseHandle (pi.hProcess); 

				//printf(" �½��̵Ľ���ID�ţ�%d \n", pi.dwProcessId); 
				//printf(" �½��̵����߳�ID�ţ�%d \n", pi.dwThreadId); 
			} 
			else
			{
				//printf("error code:%d\n",error );
			}
			CloseHandle ( hConsoleRedirect );
			//*/
			//printf("���ý���");

			// ������װ�Ľ��̹��������������

			if (m_pSpinodalpc == NULL)
			{
				m_pSpinodalpc = new CProcessCreater();
			}
			CString cmdline = ".\\spin\\Spinodal01.exe";
			CString moduleWorkDirectory = workdirectory + "\\spin";
			// Ϊģ�����û���
			EnviornmentConfig(1);
			// ����������Ϸ�����������
			m_pSpinodalpc->PMPCreateProcess(cmdline,moduleWorkDirectory,SW_HIDE);

			SetTimer(TIMER_ONE_SECOND,1000,NULL);
			// ����FileView�е�ʱ��
			CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
			pMainFrame->getFileView()->SetTimer(TIMER_TWO_SECOND,5000,NULL);
			//pMainFrame->getFileView()->FillFileViewByType(1);
			break;
		}

	}
}


void CPMPView::OnPhasemodelingCalculate()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here

	CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
	if (m_pelectricModelingDLGFather == NULL){
		this->m_pelectricModelingDLGFather = new ElectricModelingDLGFather();
		// �ڶԻ�����ʾ����֮ǰ����ȡparameter.in�ļ�����Ի������
		// �жϲ����ļ��Ƿ����
		if (PathFileExists(".\\piez\\parameter.in")){
			m_pelectricModelingDLGFather->LoadParameter(".\\piez\\parameter.in");
		}
	}
	// ��ʾ֮ǰ��һ������
	m_pelectricModelingDLGFather->m_caption = _T("Modeling Calculate");

	if(this->m_pelectricModelingDLGFather->DoModal()==IDOK){
		// ����iew�е�ʱ��
		//POSITION pos = this->GetFirstViewPosition();
		//CPMPView * pCPMPView = (CPMPView *)this->GetNextView(pos);
		switch (m_pelectricModelingDLGFather->m_RunType)
		{
		case 2:
			/*
			CString path;
			char curpath[256];
			GetCurrentDirectory(256,curpath);
			path =(CString)curpath;
			path.Append("\\piez");

			TCHAR cmdline[] =TEXT(".\\piez\\pieze.exe");
			SECURITY_ATTRIBUTES sa={sizeof ( sa ),NULL,TRUE};
			sa.bInheritHandle=true;
			sa.lpSecurityDescriptor=NULL;
			SECURITY_ATTRIBUTES *psa=NULL;
			DWORD dwShareMode=FILE_SHARE_READ|FILE_SHARE_WRITE;
			
			OSVERSIONINFO osVersion;
			osVersion.dwOSVersionInfoSize =sizeof ( osVersion );
			if ( GetVersionEx ( &osVersion ) )
			{
				if ( osVersion.dwPlatformId ==VER_PLATFORM_WIN32_NT )
				{
					psa=&sa;
					dwShareMode|=FILE_SHARE_DELETE;
				}
			}
			
			//���ݰ汾���ù���ģʽ�Ͱ�ȫ����
			HANDLE hConsoleRedirect=CreateFile (
				".\\output.txt",
				GENERIC_WRITE,
				dwShareMode,
				psa,
				CREATE_ALWAYS,
				FILE_ATTRIBUTE_NORMAL,
				NULL );
			ASSERT ( hConsoleRedirect!=INVALID_HANDLE_VALUE );
			STARTUPINFO si={ sizeof ( si ) };
			si.dwFlags =STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
			//ʹ�ñ�׼������ʾ����
			si.hStdOutput =hConsoleRedirect;//���ļ���Ϊ��׼������
			si.wShowWindow = SW_HIDE; //TRUE��ʾ��ʾ�����Ľ��̵Ĵ���
			BOOL bRet = ::CreateProcess ( 
				NULL,
				cmdline, //��Unicode�汾�д˲�������Ϊ�����ַ�������Ϊ�˲����ᱻ�޸�
				NULL,
				NULL,
				TRUE,
				NULL,
				NULL,
				path, 
				&si,
				&pi); 

			int error = GetLastError();
			if(bRet) 
			{ 
				//::CloseHandle (pi.hThread); 
				//::CloseHandle (pi.hProcess); 

				//printf(" �½��̵Ľ���ID�ţ�%d \n", pi.dwProcessId); 
				//printf(" �½��̵����߳�ID�ţ�%d \n", pi.dwThreadId); 
			} 
			else
			{
				//printf("error code:%d\n",error );
			}
			CloseHandle ( hConsoleRedirect );
			//*/
			//printf("���ý���");
			if (m_pPiezopc == NULL)
			{
				m_pPiezopc = new CProcessCreater();
			}
			CString cmdline = ".\\piez\\pieze.exe";
			CString moduleWorkDirectory = workdirectory + "\\piez";
			// Ϊģ�����û���
			EnviornmentConfig(2);
			// ����������Ϸ�����������
			m_pPiezopc->PMPCreateProcess(cmdline,moduleWorkDirectory,SW_HIDE);

			SetTimer(TIMER_PIEZ_OUTPUT,1000,NULL);
			// ����FileView�е�ʱ��
			CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
			pMainFrame->getFileView()->SetTimer(TIMER_PIEZ_SECOND,5000,NULL);
			//pMainFrame->getFileView()->FillFileViewByType(2);
			break;
		}

	}
}


void CPMPView::OnButtonSuspend256()
{
	// TODO: Add your command handler code here
	
	if (m_pSpinodalpc != NULL)
	{
		m_pSpinodalpc->PMPSuspendProcess();
	}
	if (m_pPiezopc != NULL)
	{
		m_pPiezopc->PMPSuspendProcess();
	}
	::MessageBox(NULL,_T("Process has been suspend!"),_T("Message"),MB_OK);
	KillTimer(TIMER_ONE_SECOND);
}


void CPMPView::OnButtonResume256()
{
	// TODO: Add your command handler code here
	if (m_pSpinodalpc != NULL)
	{
		m_pSpinodalpc->PMPResumeProcess();
	}
	if (m_pPiezopc != NULL)
	{
		m_pPiezopc->PMPResumeProcess();
	}
	::MessageBox(NULL,_T("Process has been resumed!"),_T("Message"),MB_OK);
	SetTimer(TIMER_ONE_SECOND,1000,NULL);
}


void CPMPView::OnButtonStop256()
{
	// TODO: Add your command handler code here
	KillTimer(TIMER_ONE_SECOND);
	if (m_pSpinodalpc !=NULL)
	{
		m_pSpinodalpc->PMPTerminateProcess();
	}
	if (m_pPiezopc != NULL)
	{
		m_pPiezopc->PMPTerminateProcess();
	}
	::MessageBox(NULL,_T("Process has been terminated!"),_T("Message"),MB_OK);
}
void CPMPView::ReadCMDOutput(){
	
	int fileSize =0;
	char * pBuffer;
	DWORD RSize;

		HANDLE hOpenFile = (HANDLE)CreateFile(".\\output.txt", GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
		if (hOpenFile == INVALID_HANDLE_VALUE)
		{
			hOpenFile = NULL;
			::MessageBoxA(NULL, "Can not open the file", "Playwav", MB_OK);
		}
		//fileSize = GetFileSize(hOpenFile, NULL);
		//
		fileSize = GetFileSize(hOpenFile, NULL);
		if (fileSize > flagsize){
			pBuffer = (CHAR *) malloc(fileSize);
			ReadFile(hOpenFile, pBuffer, fileSize, &RSize, NULL);
			//�ɽ�pBuffer��ʾ��ĳ�����д����һ���ļ����������Ƿ���ȷ
			//for (i=flagsize;i<fileSize;i++)
			//{
			//	putchar(pBuffer[i]);
		//	}
			output = pBuffer;
			output=output.Mid(flagsize,fileSize-flagsize);
			SetOutputList(m_outputList);
			//::MessageBox(NULL,_T("lailiao"),_T("OK"),MB_OK);
			free(pBuffer);
			flagsize=fileSize;
		}
		CloseHandle ( hOpenFile );
}

void CPMPView::SetOutput(CString output){
	CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
	pMainFrame->getOutputWnd()->FillBuildWindowByString(output);
}

void CPMPView::OutputToList(CString output){
	// ���m_outputList��ÿ��ֻ���µĲ���
	m_outputList.RemoveAll();
	int begin =  0;
	for (int i=0;i<output.GetLength();i++)
	{
		if (output.GetAt(i)=='\n'){
			m_outputList.Add(output.Mid(begin,i-begin));
			begin = i+1;
		}
	}
}
void CPMPView::SetOutputList(CStringArray &list){
	OutputToList(output);
	CMainFrame * pMainFrame = (CMainFrame *)AfxGetMainWnd();
	pMainFrame->getOutputWnd()->FillBuildWindowByStringArray(list);
}

void CPMPView::OnClose()
{
	// TODO: Add your message handler code here and/or call default


	if (m_pSpinodalpc !=NULL)
	{
		m_pSpinodalpc->PMPTerminateProcess();
	}
	if (m_pPiezopc != NULL)
	{
		m_pPiezopc->PMPTerminateProcess();
	}
	if (m_pPaternRecpc != NULL)
	{
		m_pPaternRecpc->PMPTerminateProcess();
	}

	CView::OnClose();
}

//����Ŀ¼��֧�ֶ��ش�����
BOOL CPMPView::MakeDir(CString szDirName)
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

BOOL CPMPView::EnviornmentConfig(int moduleType){
	// �鿴Ŀ¼�Ƿ����
	switch (moduleType)
	{
		// Ϊģ��1�������л���
	case 1:
		{

			// �ж�Ŀ¼�Ƿ���ڣ�����������򴴽�
			CString muduleWorkDirectory = workdirectory+"\\spin";
			DWORD dwAttr = GetFileAttributes(muduleWorkDirectory);
			if(dwAttr==-1||(dwAttr&FILE_ATTRIBUTE_DIRECTORY)==0)//Ŀ¼������
			{
				if ( !MakeDir(muduleWorkDirectory))
				{
					AfxMessageBox("can't create directionary:"+muduleWorkDirectory);
					//PostMessage(WM_QUIT,0,0);
					//return;
				}
			}
			// ���������ļ�������Ŀ¼,TRUE��ʾ�����ǿ���
			
			BOOL flag=CopyFile(".\\spin\\input.dat",muduleWorkDirectory+"\\input.dat",FALSE);

			if (flag == FALSE)
			{
				//AfxMessageBox("Configure failed");
			}
		}
		break;
		// Ϊģ��2�������л���
	case 2:	
		{
		// �ж�Ŀ¼�Ƿ���ڣ�����������򴴽�
			CString muduleWorkDirectory = workdirectory+"\\piez";
			DWORD dwAttr = GetFileAttributes(muduleWorkDirectory);
			if(dwAttr==-1||(dwAttr&FILE_ATTRIBUTE_DIRECTORY)==0)//Ŀ¼������
			{
				if ( !MakeDir(muduleWorkDirectory))
				{
					AfxMessageBox("can't create directionary:"+muduleWorkDirectory);
					//PostMessage(WM_QUIT,0,0);
					//return;
				}
			}
			// ���������ļ�������Ŀ¼,TRUE��ʾ�����ǿ���
			BOOL flag1=CopyFile(".\\piez\\parameter.in",muduleWorkDirectory+"\\parameter.in",FALSE);
			BOOL flag2=CopyFile(".\\piez\\struct.in",muduleWorkDirectory+"\\struct.in",FALSE);
			if (flag1 == FALSE || flag2== FALSE)
			{
				//AfxMessageBox("Configure failed");
			}
		}

		break;
	}
	return TRUE;
}

void CPMPView::OnToolsPatternrecognition()
{
	// TODO: Add your command handler code here
	// ����ģʽʶ��ģ�飬��ͼƬ���зָ�ָ������ı��ļ����
	CString cmdline = ".\\mpatternReco\\MPatRecFace.exe";
	CString moduleWorkDirectory = ".\\mpatternReco";
	if (m_pPaternRecpc == NULL)
	{
		m_pPaternRecpc = new CProcessCreater();
	}
	m_pPaternRecpc->PMPCreateProcess(cmdline,moduleWorkDirectory,SW_SHOW);
}
