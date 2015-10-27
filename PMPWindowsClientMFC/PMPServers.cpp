// PMPServers.cpp : implementation file
//

#include "stdafx.h"
#include "PMPWindowsClientMFC.h"
#include "PMPServers.h"
#include "afxdialogex.h"


// PMPServers dialog

IMPLEMENT_DYNAMIC(PMPServers, CDialog)

PMPServers::PMPServers(CWnd* pParent /*=NULL*/)
	: CDialog(PMPServers::IDD, pParent)
{

}

PMPServers::~PMPServers()
{
}

void PMPServers::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PMPServers, CDialog)
END_MESSAGE_MAP()


// PMPServers message handlers
