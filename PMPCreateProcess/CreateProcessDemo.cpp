#include "afx.h"
#include <windows.h> 
#include <stdio.h> 
void cp();
void cp2();
void myReader1();
void myReader2();
class CPMPProcessCreater:public CObject{
public:
	CPMPProcessCreater();
	virtual ~CPMPProcessCreater();
public :
	// 持有进程信息
	PROCESS_INFORMATION pi;
	// 根据命令行和工作目录创建进程
	bool PMPCreateProcess(CString pmpcmdline,CString workdirectory);
	// 终止进程
	bool PMPTerminateProcess();
};
CPMPProcessCreater::CPMPProcessCreater()
{
}

CPMPProcessCreater::~CPMPProcessCreater()
{
}
bool CPMPProcessCreater::PMPCreateProcess(CString pmpcmdline,CString workdirectory){

			//TCHAR cmdline[] ={pmpcmdline};
			SECURITY_ATTRIBUTES sa={sizeof ( sa ),NULL,TRUE};
			sa.bInheritHandle=true;
			sa.lpSecurityDescriptor=NULL;
			SECURITY_ATTRIBUTES *psa=NULL;
			DWORD dwShareMode=FILE_SHARE_READ|FILE_SHARE_WRITE;
			//*
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
			//*/
			//根据版本设置共享模式和安全属性
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
			//si.dwFlags =STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
			si.dwFlags =STARTF_USESHOWWINDOW;
			//使用标准柄和显示窗口
			//si.hStdOutput =hConsoleRedirect;//将文件作为标准输出句柄
			si.wShowWindow = SW_HIDE; //TRUE表示显示创建的进程的窗口
			BOOL bRet = ::CreateProcess( 
				NULL,
				(LPSTR)(LPCTSTR)pmpcmdline, //在Unicode版本中此参数不能为常量字符串，因为此参数会被修改
				NULL,
				NULL,
				TRUE,
				CREATE_NEW_CONSOLE,
				NULL,
				workdirectory, 
				&si,
				&(this->pi)); 

			int error = GetLastError();
			if(bRet) 
			{ 
				//::CloseHandle (pi.hThread); 
				//::CloseHandle (pi.hProcess); 

				//printf(" 新进程的进程ID号：%d \n", pi.dwProcessId); 
				//printf(" 新进程的主线程ID号：%d \n", pi.dwThreadId); 
			} 
			else
			{
				//printf("error code:%d\n",error );
			}
			CloseHandle ( hConsoleRedirect );
			return TRUE;
}

bool CPMPProcessCreater::PMPTerminateProcess(){
	TerminateThread(this->pi.hThread,0);
	TerminateProcess(this->pi.hProcess,0);
	::CloseHandle (this->pi.hThread); 
	::CloseHandle (this->pi.hProcess); 


	return TRUE;
}

int main(){ 
	// 主要展示读取控制台信息技术
	//cp2();
	//printf("returned!");
	//myReader2();
	//printf("跳过reader");
	CPMPProcessCreater PMPcp ;
	CString cmdline = ".\\spin\\Spinodal01.exe";
	CString workdirectory = "F:\\PMPWorkspace\\spin";
	PMPcp.PMPCreateProcess(cmdline,workdirectory);
	char yesorno;
	yesorno = getchar();
	while(TRUE){
		if (yesorno == 'y')
		{
			PMPcp.PMPTerminateProcess();
			break;
		}
		yesorno = getchar();
	}
	return 0;
}

void cp(){

	CString path;
	char curpath[256];
	GetCurrentDirectory(256,curpath);
	path =(CString)curpath;
	path.Append("\\spin");
	printf ("调用开始\n");
	STARTUPINFO si = { sizeof(si) }; 
	PROCESS_INFORMATION pi; 
	//SetCurrentDirectory("");
	si.dwFlags = STARTF_USESHOWWINDOW; 
	si.wShowWindow = TRUE; //TRUE表示显示创建的进程的窗口
	TCHAR cmdline[] =TEXT(".\\Spinodal01.exe .\\input.dat");
	BOOL bRet = ::CreateProcess ( 
		NULL,
		cmdline, //在Unicode版本中此参数不能为常量字符串，因为此参数会被修改
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		path, 
		&si,
		&pi); 

	int error = GetLastError();
	if(bRet) 
	{ 
		
		//::CloseHandle (pi.hThread); 
		//::CloseHandle (pi.hProcess); 

		printf(" 新进程的进程ID号：%d \n", pi.dwProcessId); 
		printf(" 新进程的主线程ID号：%d \n", pi.dwThreadId); 
	} 
	else
	{
		printf("error code:%d\n",error );
	}
	printf("调用结束");
}

void cp2(){
		char cmdLine[MAX_PATH];
		wsprintf ( cmdLine,"Spinodal01.exe input.dat");
		SECURITY_ATTRIBUTES sa={sizeof ( sa ),NULL,TRUE};
		sa.bInheritHandle=true;
		sa.lpSecurityDescriptor=NULL;
		SECURITY_ATTRIBUTES *psa=NULL;
		DWORD dwShareMode=FILE_SHARE_READ|FILE_SHARE_WRITE;
		//*
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
		//*/
		//根据版本设置共享模式和安全属性
		HANDLE hConsoleRedirect=CreateFile (
			"F:\\output.txt",
			GENERIC_WRITE,
			dwShareMode,
			psa,
			CREATE_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL );
		ASSERT ( hConsoleRedirect!=INVALID_HANDLE_VALUE );
		STARTUPINFO si={sizeof ( si ) };
		PROCESS_INFORMATION pi;
		si.dwFlags =STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
		//使用标准柄和显示窗口
		si.hStdOutput =hConsoleRedirect;//将文件作为标准输出句柄
		si.wShowWindow =SW_SHOW;//隐藏控制台窗口
		bool bf = ::CreateProcess ( 
			NULL,
			cmdLine,
			NULL,
			NULL,
			TRUE,
			CREATE_NEW_CONSOLE,
			NULL,
			NULL,
			&si,
			&pi);
		if (bf){
			//创建进程,执行Ping程序,测试网络是否连通
			//WaitForSingleObject ( pi.hProcess ,INFINITE );
			//等待进程执行完毕
			//::CloseHandle ( pi.hProcess );
			//::CloseHandle ( pi.hThread );
			//关闭进程和主线程句柄
			printf(" 新进程的进程ID号：%d \n", pi.dwProcessId); 
			printf(" 新进程的主线程ID号：%d \n", pi.dwThreadId); 
		}
		CloseHandle ( hConsoleRedirect );
}

void myReader1(){
	CFile cf;
	CString str;
	char ch[128];
	int i;
	if(cf.Open("F:\\output.txt",CFile::modeRead | FILE_SHARE_WRITE)){
		cf.Read(ch,128);
		for (i=0;i<128;i++)
		{
			putchar(ch[i]);
		}
		cf.Close();
	}else{
		printf("打开失败");
	}
}
void myReader2(){
	int flagsize=0;
	int fileSize =0;
	char * pBuffer;
	DWORD RSize;
	int i;


	while(1){
		HANDLE hOpenFile = (HANDLE)CreateFile("F:\\output.txt", GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
		if (hOpenFile == INVALID_HANDLE_VALUE)
		{
			hOpenFile = NULL;
			MessageBoxA(NULL, "Can not open the file", "Playwav", MB_OK);
		}
	//fileSize = GetFileSize(hOpenFile, NULL);
	//
		fileSize = GetFileSize(hOpenFile, NULL);
		if (fileSize > flagsize){
			pBuffer = (CHAR *) malloc(fileSize);
			OVERLAPPED o;
			ReadFile(hOpenFile, pBuffer, fileSize, &RSize, NULL);
			//可将pBuffer显示在某区域或写入另一个文件来检查读出是否正确
			//for (i=flagsize;i<fileSize;i++)
			//{
			//	putchar(pBuffer[i]);
			//}
			CString output =pBuffer;
			output = output.Mid(flagsize,fileSize-flagsize);
			printf(output);
			free(pBuffer);
			flagsize=fileSize;
		}
		//Sleep(3000);
		CloseHandle ( hOpenFile );
	}
}