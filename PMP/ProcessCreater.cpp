// PMPTransformer.cpp : implementation file
//

#include "stdafx.h"
#include "PMP.h"
#include "ProcessCreater.h"

// CProcessCreater

CProcessCreater::CProcessCreater()
{
}

CProcessCreater::~CProcessCreater()
{
}

bool CProcessCreater::PMPCreateProcess(CString pmpcmdline,CString workdirectory,int showType){
			//CString path;
			//char curpath[256];
			//GetCurrentDirectory(256,curpath);
			//path =(CString)curpath;
			//path.Append("\\piez");

			//TCHAR cmdline[] =TEXT(".\\piez\\pieze.exe");
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
			si.dwFlags =STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
			//使用标准柄和显示窗口
			si.hStdOutput =hConsoleRedirect;//将文件作为标准输出句柄
			si.wShowWindow = showType; //TRUE表示显示创建的进程的窗口
			BOOL bRet = ::CreateProcess ( 
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

bool CProcessCreater::PMPTerminateProcess(){
	TerminateThread(this->pi.hThread,0);
	TerminateProcess(this->pi.hProcess,0);
	::CloseHandle (this->pi.hThread); 
	::CloseHandle (this->pi.hProcess); 
	return TRUE;
}

BOOL CProcessCreater::PMPSuspendProcess(){
	SuspendThread(this->pi.hThread);
	return TRUE;
}
BOOL CProcessCreater::PMPResumeProcess(){
	ResumeThread(this->pi.hThread);
	return TRUE;
}