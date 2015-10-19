
// PMPMyFileViewer.h : main header file for the PMPMyFileViewer application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPMPMyFileViewerApp:
// See PMPMyFileViewer.cpp for the implementation of this class
//

class CPMPMyFileViewerApp : public CWinAppEx
{
public:
	CPMPMyFileViewerApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPMPMyFileViewerApp theApp;
