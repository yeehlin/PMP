#include "afx.h"
#include <windows.h> 
#include <stdio.h> 
#include "stdio.h"

DWORD  spin;
PROCESS_INFORMATION temp;
void MoniTimer(CString str);
void CallSpin();
void CallSpinTest();
void CallPiez();
void CallPiezTest();
void ArrayDemo();
void filedemo();
void strtokDemo();
int main(){
	//CallPiezTest();
	strtokDemo();
	return 0;
}

void strtokDemo(){
	CString str= "   1     1     1  1.03189759E-03  3.37393410E-05 -4.36950390E-07 -6.90732108E-06  2.29561866E-05  5.52860695E-05 ";
	str.Trim();
	int in=0;
	char *p[10];
	char *buf = (LPSTR)(LPCTSTR)str;
	while((p[in]=strtok(buf," "))!=NULL) {
		in++;
		buf=NULL; }
	printf("%d个数\n",in);
	for (int i=0;i<in;i++)
	{
		printf("%s\n",p[i]);
	}
}

void ArrayDemo(){
	
	CStringArray demo;
	demo.Add("尼玛");
	demo.Add("你爸");
	demo.Add("尼玛");
	for (int i=0;i<demo.GetSize();i++)
	{
		printf(demo.GetAt(i));
	}
}
void filedemo(){

	CFile myfileread1;
	CFile myfileread2;
	CFileFind finder;
	CString str;
	CString name;
	name="001comp.bmp";
	str =".\\spin\\"+name;
	if(finder.FindFile(str)){
		printf("找到");
		if(myfileread1.Open(str,CFile::modeRead | CFile::typeBinary)){
			printf("可以打开");
			myfileread1.Close();
			printf("已关闭");
		}
	}
}


void CallSpin(){

	CString path;
	char curpath[256];
	//SetCurrentDirectory("F:\\output");
	GetCurrentDirectory(256,curpath);
	
	//path =(CString)curpath;
char mypath[] = "F:\\output";
	//printf("%s\n",curpath);
	//path.Append("\\spin");
	printf ("调用开始\n");
	STARTUPINFO si = { sizeof(si) }; 
	PROCESS_INFORMATION pi;
	
	//SetCurrentDirectory("F:\\output");
	//SetCurrentDirectory("");
	
	si.dwFlags = STARTF_USESHOWWINDOW; 
	si.wShowWindow = TRUE; //TRUE表示显示创建的进程的窗口
	char appname[]="Spinodal01.exe ";
	char mycmdline[]="D:\\Toolkits\\VTK\\Examples\\PMP\\PMP-build\\PMPCallConsole\\input.dat";
	TCHAR cmdline[] =TEXT("D:\\Toolkits\\VTK\\Examples\\PMP\\PMP-build\\PMPCallConsole\\Spinodal01.exe D:\\Toolkits\\VTK\\Examples\\PMP\\PMP-build\\PMPCallConsole\\input.dat");
	BOOL bRet = ::CreateProcess ( 
		appname,
		mycmdline, //在Unicode版本中此参数不能为常量字符串，因为此参数会被修改
		NULL,
		NULL,
		TRUE,
		CREATE_NEW_CONSOLE,
		NULL,
		mypath,
		&si,
		&pi); 

	int error = GetLastError();
	if(bRet) 
	{ 
		//spin = pi.hThread;
		//::CloseHandle (pi.hThread); 
		//::CloseHandle (pi.hProcess); 
		printf(" 新进程的进程ID号：%d \n", pi.dwProcessId); 
		printf(" 新进程的主线程ID号：%d \n", pi.dwThreadId); 
		temp = pi;
	} 
	else
	{
		printf("error code:%d\n",error );
	}
}
void MoniTimer(CString str){
	CFileFind finder;

	// build a string with wildcards
	CString strWildcard(str);
	strWildcard += _T("\\bin\\*.bmp");

	// start working for files
	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{
		bWorking = finder.FindNextFile();

		// skip . and .. files; otherwise, we'd
		// recur infinitely!

		if (finder.IsDots())
			continue;
		// if it's a directory, recursively search it

		if (!finder.IsDirectory())
		{
			CString str = finder.GetFileName();
			printf("%s\n",str);
			//cout << (LPCTSTR) str << endl;
			MoniTimer(str);
		}
	}

	finder.Close();
}

void CallSpinTest(){
	// 主要展示线程的暂停、恢复、停止等操作
	CallSpin();
	printf("调用结束");
	Sleep(3000);
	printf("%d\n",temp.dwProcessId);
	SuspendThread(temp.hThread);
	Sleep(4000);
	ResumeThread(temp.hThread);
	Sleep(5000);
	TerminateThread(temp.hThread,0);
	TerminateProcess(temp.hProcess,0);
}

void CallPiez(){

	CString path;
	char curpath[256];
	//SetCurrentDirectory("F:\\output");
	GetCurrentDirectory(256,curpath);

	//path =(CString)curpath;
	char mypath[] = "F:\\output\\piez";
	//printf("%s\n",curpath);
	//path.Append("\\spin");
	printf ("调用开始\n");
	STARTUPINFO si = { sizeof(si) }; 
	PROCESS_INFORMATION pi;

	//SetCurrentDirectory("F:\\output");
	//SetCurrentDirectory("");

	si.dwFlags = STARTF_USESHOWWINDOW; 
	si.wShowWindow = TRUE; //TRUE表示显示创建的进程的窗口
	char appname[]=".\\piez\\pieze.exe ";
	char mycmdline[]="";
	TCHAR cmdline[] =TEXT("D:\\Toolkits\\VTK\\Examples\\PMP\\PMP-build\\PMPCallConsole\\Spinodal01.exe D:\\Toolkits\\VTK\\Examples\\PMP\\PMP-build\\PMPCallConsole\\input.dat");
	BOOL bRet = ::CreateProcess ( 
		appname,
		mycmdline, //在Unicode版本中此参数不能为常量字符串，因为此参数会被修改
		NULL,
		NULL,
		TRUE,
		CREATE_NEW_CONSOLE,
		NULL,
		mypath,
		&si,
		&pi); 

	int error = GetLastError();
	if(bRet) 
	{ 
		//spin = pi.hThread;
		//::CloseHandle (pi.hThread); 
		//::CloseHandle (pi.hProcess); 
		printf(" 新进程的进程ID号：%d \n", pi.dwProcessId); 
		printf(" 新进程的主线程ID号：%d \n", pi.dwThreadId); 
		temp = pi;
	} 
	else
	{
		printf("error code:%d\n",error );
	}
}
void CallPiezTest(){
	// 主要展示线程的暂停、恢复、停止等操作
	CallPiez();
	printf("调用结束");
	Sleep(300000);
	printf("%d\n",temp.dwProcessId);
	SuspendThread(temp.hThread);
	Sleep(400000);
	ResumeThread(temp.hThread);
	Sleep(500000);
	TerminateThread(temp.hThread,0);
	TerminateProcess(temp.hProcess,0);
}