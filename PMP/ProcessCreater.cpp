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
			si.wShowWindow = showType; //TRUE��ʾ��ʾ�����Ľ��̵Ĵ���
			BOOL bRet = ::CreateProcess ( 
				NULL,
				(LPSTR)(LPCTSTR)pmpcmdline, //��Unicode�汾�д˲�������Ϊ�����ַ�������Ϊ�˲����ᱻ�޸�
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

				//printf(" �½��̵Ľ���ID�ţ�%d \n", pi.dwProcessId); 
				//printf(" �½��̵����߳�ID�ţ�%d \n", pi.dwThreadId); 
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