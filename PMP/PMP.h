
// PMP.h : main header file for the PMP application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPMPApp:
// See PMP.cpp for the implementation of this class
//

class CPMPApp : public CWinAppEx
{
public:
	CPMPApp();


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
public :
	// ����ĸ�ģ�棬������һ��δʹ��
	CMultiDocTemplate * m_pPMPDocTemplate;
	CMultiDocTemplate * m_pBmpDocTemplate;
	CMultiDocTemplate * m_pTxtDocTemplate;
	// ����ͼģ��
	CMultiDocTemplate * m_pDatDocTemplate;
	CMultiDocTemplate * m_pDatDocStrmlineTemplate;
	CMultiDocTemplate * m_pDatDocVolumeTemplate;
	// ����ͼģ��
	CMultiDocTemplate * m_pTensorDatDocTemplate;
	CMultiDocTemplate * m_pTensorDatDocTensoTemplate;
	CMultiDocTemplate * m_pTensorDatDocMultiTemplate;
	// ����ͼģ��
	CMultiDocTemplate * m_pScalarDatDocTemplate;
	CMultiDocTemplate * m_pScalarDatDocGridTemplate;


};

extern CPMPApp theApp;
