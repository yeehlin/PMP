#pragma once

#include "stdafx.h"
// 自定义的类，用于左边文件管理
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