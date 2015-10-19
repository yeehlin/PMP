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
	// ���н�����Ϣ
	PROCESS_INFORMATION pi;
	// ���������к͹���Ŀ¼��������
	bool PMPCreateProcess(CString pmpcmdline,CString workdirectory);
	// ��ֹ����
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
			//si.dwFlags =STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
			si.dwFlags =STARTF_USESHOWWINDOW;
			//ʹ�ñ�׼������ʾ����
			//si.hStdOutput =hConsoleRedirect;//���ļ���Ϊ��׼������
			si.wShowWindow = SW_HIDE; //TRUE��ʾ��ʾ�����Ľ��̵Ĵ���
			BOOL bRet = ::CreateProcess( 
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

bool CPMPProcessCreater::PMPTerminateProcess(){
	TerminateThread(this->pi.hThread,0);
	TerminateProcess(this->pi.hProcess,0);
	::CloseHandle (this->pi.hThread); 
	::CloseHandle (this->pi.hProcess); 


	return TRUE;
}

int main(){ 
	// ��Ҫչʾ��ȡ����̨��Ϣ����
	//cp2();
	//printf("returned!");
	//myReader2();
	//printf("����reader");
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
	printf ("���ÿ�ʼ\n");
	STARTUPINFO si = { sizeof(si) }; 
	PROCESS_INFORMATION pi; 
	//SetCurrentDirectory("");
	si.dwFlags = STARTF_USESHOWWINDOW; 
	si.wShowWindow = TRUE; //TRUE��ʾ��ʾ�����Ľ��̵Ĵ���
	TCHAR cmdline[] =TEXT(".\\Spinodal01.exe .\\input.dat");
	BOOL bRet = ::CreateProcess ( 
		NULL,
		cmdline, //��Unicode�汾�д˲�������Ϊ�����ַ�������Ϊ�˲����ᱻ�޸�
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

		printf(" �½��̵Ľ���ID�ţ�%d \n", pi.dwProcessId); 
		printf(" �½��̵����߳�ID�ţ�%d \n", pi.dwThreadId); 
	} 
	else
	{
		printf("error code:%d\n",error );
	}
	printf("���ý���");
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
		//���ݰ汾���ù���ģʽ�Ͱ�ȫ����
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
		//ʹ�ñ�׼������ʾ����
		si.hStdOutput =hConsoleRedirect;//���ļ���Ϊ��׼������
		si.wShowWindow =SW_SHOW;//���ؿ���̨����
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
			//��������,ִ��Ping����,���������Ƿ���ͨ
			//WaitForSingleObject ( pi.hProcess ,INFINITE );
			//�ȴ�����ִ�����
			//::CloseHandle ( pi.hProcess );
			//::CloseHandle ( pi.hThread );
			//�رս��̺����߳̾��
			printf(" �½��̵Ľ���ID�ţ�%d \n", pi.dwProcessId); 
			printf(" �½��̵����߳�ID�ţ�%d \n", pi.dwThreadId); 
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
		printf("��ʧ��");
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
			//�ɽ�pBuffer��ʾ��ĳ�����д����һ���ļ����������Ƿ���ȷ
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