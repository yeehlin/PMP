#pragma once

// CProcessCreater command target

class CProcessCreater : public CObject
{
public:
	CProcessCreater();
	virtual ~CProcessCreater();
public :
	// 持有进程信息
	PROCESS_INFORMATION pi;
	// 根据命令行和工作目录创建进程
	bool PMPCreateProcess(CString cmdline,CString workdirectory,int showType);
	// 暂停进程
	BOOL PMPSuspendProcess();
	// 恢复进程
	BOOL PMPResumeProcess();
	// 终止进程
	bool PMPTerminateProcess();
};