
// PMPFileViewer.h : main header file for the PMPFileViewer application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPMPFileViewerApp:
// See PMPFileViewer.cpp for the implementation of this class
//

class CPMPFileViewerApp : public CWinAppEx
{
public:
	CPMPFileViewerApp();


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

	afx_msg void OnMainfrmSpinodaldecompositionCalculate();
	afx_msg void OnMainfrmPhasemodelingCalculate();
public :
	CMultiDocTemplate * m_pTxtDocTemplate;
	CMultiDocTemplate * m_pBmpDocTemplate;
	CMultiDocTemplate * m_pDatDocTemplate;
};

extern CPMPFileViewerApp theApp;
