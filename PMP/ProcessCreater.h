#pragma once

// CProcessCreater command target

class CProcessCreater : public CObject
{
public:
	CProcessCreater();
	virtual ~CProcessCreater();
public :
	// ���н�����Ϣ
	PROCESS_INFORMATION pi;
	// ���������к͹���Ŀ¼��������
	bool PMPCreateProcess(CString cmdline,CString workdirectory,int showType);
	// ��ͣ����
	BOOL PMPSuspendProcess();
	// �ָ�����
	BOOL PMPResumeProcess();
	// ��ֹ����
	bool PMPTerminateProcess();
};