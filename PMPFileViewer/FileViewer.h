#pragma once

#include "stdafx.h"
// �Զ�����࣬��������ļ�����
class CFileViewer{
private:
	CString FileFullPath;
	CString FileName;
	bool visible;
public :
	CFileViewer();
	virtual ~CFileViewer();
	void setFileFullPath(CString fileFullPath);
	CString getFileFullPath();
	void setFileName(CString fileName);
	CString getFileName();
	void setVisible(bool visible);
	bool getVisible();
};