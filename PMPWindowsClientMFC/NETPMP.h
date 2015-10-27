#pragma once

#include "PMPServers.h"

#define WM_SOCKET_NOTIFY (WM_USER + 1)
#define ID_TIMER         1
#define BUFFER_SIZE 1024
#define IPPORT_PMPSERVER 6666

// NETPMP dialog

class NETPMP : public CDialog
{
	DECLARE_DYNAMIC(NETPMP)

public:
	NETPMP(CWnd* pParent = NULL);   // standard constructor
	virtual ~NETPMP();

// Dialog Data
	enum { IDD = IDD_NETPMP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
private:
	static char   szIPAddr[32]  ;
	static HWND   hwndButton, hwndEdit ;
	static SOCKET sock ;
	static struct sockaddr_in sa ;
	static TCHAR  szOKLabel[32] ;
	int           iError, iSize ;
	unsigned long ulTime ;
	WORD          wEvent, wError ;
	WSADATA       WSAData ;
	char buffer[BUFFER_SIZE];
private:
	void EditPrintf (HWND hwndEdit, TCHAR * szFormat, ...);

public:
	afx_msg void OnClickedServer();
	afx_msg void OnBnClickedGo();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg LRESULT OnSocketNotify(WPARAM wParam, LPARAM lParam);
	afx_msg void OnIdcancel();
	afx_msg void OnClickedClose();
//	afx_msg void OnClose();
	CEdit m_EditTextOut;
};