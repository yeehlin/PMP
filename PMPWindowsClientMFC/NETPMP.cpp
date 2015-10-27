// NETPMP.cpp : implementation file
//

#include "stdafx.h"
#include "PMPWindowsClientMFC.h"
#include "NETPMP.h"
#include "afxdialogex.h"


// NETPMP dialog

IMPLEMENT_DYNAMIC(NETPMP, CDialog)

// static
char NETPMP::szIPAddr[32]= { "131.107.13.100" };
//char NETPMP::szIPAddr[32]= { "10.141.25.153" };
HWND   NETPMP::hwndButton=NULL, NETPMP::hwndEdit=NULL;
SOCKET NETPMP::sock =NULL;
struct sockaddr_in NETPMP::sa ={0};
TCHAR  NETPMP::szOKLabel[32] ={0};
NETPMP::NETPMP(CWnd* pParent /*=NULL*/)
	: CDialog(NETPMP::IDD, pParent)
{

	iError=0, iSize =0;
	ulTime=0 ;
	wEvent=0, wError=0 ;
	strcpy(buffer,"Windows !");
}

NETPMP::~NETPMP()
{
}

void NETPMP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXTOUT, m_EditTextOut);
}


BEGIN_MESSAGE_MAP(NETPMP, CDialog)
	ON_BN_CLICKED(IDC_SERVER, &NETPMP::OnClickedServer)
	ON_BN_CLICKED(IDOK, &NETPMP::OnBnClickedGo)
	ON_WM_TIMER()
	ON_MESSAGE(WM_SOCKET_NOTIFY, &NETPMP::OnSocketNotify) 
	ON_COMMAND(IDCANCEL, &NETPMP::OnIdcancel)
	ON_BN_CLICKED(IDC_CLOSE, &NETPMP::OnClickedClose)
//	ON_WM_CLOSE()
END_MESSAGE_MAP()


// NETPMP message handlers


BOOL NETPMP::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here


	hwndButton  = (HWND)GetDlgItem (IDOK) ;
	hwndEdit = (HWND)GetDlgItem (IDC_TEXTOUT) ;



	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void NETPMP::OnClickedServer()
{
	// TODO: Add your control notification handler code here

	//m_EditTextOut.ReplaceSel("10.10.10.10",FALSE);
	//SendMessage(WM_SOCKET_NOTIFY,sock,FD_WRITE);
}


void NETPMP::OnBnClickedGo()
{
	// TODO: Add your control notification handler code here

	// Call "WSAStartup" and display description text


	if (iError = WSAStartup (MAKEWORD(2,0), &WSAData))
	{
		EditPrintf (hwndEdit, TEXT ("Startup error #%i.\r\n"), 
			iError) ;
		return ;
	}
	EditPrintf (hwndEdit, TEXT ("Started up %hs\r\n"), 
		WSAData.szDescription);

	// Call "socket"

	sock = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP) ;

	if (sock == INVALID_SOCKET)
	{
		EditPrintf (hwndEdit, 
			TEXT ("Socket creation error #%i.\r\n"), 
			WSAGetLastError ()) ;
		WSACleanup () ;
		return  ;
	}
	EditPrintf (hwndEdit, TEXT ("Socket %i created.\r\n"), sock) ;

	// Call "WSAAsyncSelect" 

	if (SOCKET_ERROR == WSAAsyncSelect (sock, this->GetSafeHwnd(), WM_SOCKET_NOTIFY, 
		FD_CONNECT | FD_READ | FD_WRITE ))
	{
		EditPrintf (hwndEdit, 
			TEXT ("WSAAsyncSelect error #%i.\r\n"),
			WSAGetLastError ()) ;
		closesocket (sock) ;
		WSACleanup () ;
		return  ;
	}

	// Call "connect" with IP address and time-server port

	sa.sin_family           = AF_INET ;
	sa.sin_port             = htons (IPPORT_TIMESERVER) ; 
	//sa.sin_port             = htons (IPPORT_PMPSERVER) ;
	sa.sin_addr.S_un.S_addr = inet_addr (szIPAddr) ;

	connect(sock, (SOCKADDR *) &sa, sizeof (sa)) ;

	// "connect" will return SOCKET_ERROR because even if it
	// succeeds, it will require blocking. The following only
	// reports unexpected errors.

	if (WSAEWOULDBLOCK != (iError = WSAGetLastError ()))
	{
		EditPrintf (hwndEdit, TEXT ("Connect error #%i.\r\n"), 
			iError) ;
		closesocket (sock) ;
		WSACleanup () ;
		return  ;
	}
	EditPrintf (hwndEdit, TEXT ("Connecting to %hs..."), szIPAddr) ;

	// The result of the "connect" call will be reported 
	// through the WM_SOCKET_NOTIFY message.
	// Set timer and change the button to "Cancel"

	SetTimer (ID_TIMER,1000, NULL) ;

	//SendMessage(WM_SOCKET_NOTIFY,(WPARAM)buffer,FD_WRITE);
	
	//GetWindowText (hwndButton, szOKLabel, sizeof (szOKLabel) /
	//	sizeof (TCHAR)) ;
	//SetWindowText (hwndButton, TEXT ("Cancel")) ;
	//SetWindowLong (hwndButton, GWL_ID, IDCANCEL) ;

	//CDialog::OnOK();
}

void NETPMP::EditPrintf (HWND hwndEdit, TCHAR * szFormat, ...)
{
	TCHAR   szBuffer [1024] ;
	va_list pArgList ;

	va_start (pArgList, szFormat) ;
	wvsprintf (szBuffer, szFormat, pArgList) ;
	va_end (pArgList) ;
	//MessageBox("KO");
	m_EditTextOut.SetSel(-1,-1);
	m_EditTextOut.ReplaceSel(szBuffer);
	//::SendMessage (hwndEdit,EM_SETSEL, (WPARAM) -1, (LPARAM) -1) ;
	//::SendMessage (hwndEdit,EM_REPLACESEL, FALSE, (LPARAM) szBuffer) ;
	//::SendMessage (hwndEdit,EM_SCROLLCARET, 0, 0) ;
}

void NETPMP::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	EditPrintf (hwndEdit, TEXT (".")) ;
	CDialog::OnTimer(nIDEvent);
}

LRESULT NETPMP::OnSocketNotify(WPARAM wParam, LPARAM lParam){
	wEvent = WSAGETSELECTEVENT (lParam) ;   // ie, LOWORD
	wError = WSAGETSELECTERROR (lParam) ;   // ie, HIWORD

	// Process two events specified in WSAAsyncSelect

	switch (wEvent)
	{
		// This event occurs as a result of the "connect" call

	case FD_CONNECT:
		EditPrintf (hwndEdit, TEXT ("\r\n")) ;

		if (wError)
		{
			EditPrintf (hwndEdit, TEXT ("Connect error #%i."), 
				wError) ;
			SendMessage (WM_COMMAND, IDCANCEL, 0) ;
			return TRUE ;
		}
		EditPrintf (hwndEdit, TEXT ("Connected to %hs.\r\n"), szIPAddr) ;

		// Try to receive data. The call will generate an error
		// of WSAEWOULDBLOCK and an event of FD_READ

		recv (sock, (char *) &ulTime, 4, MSG_PEEK) ;
		//recv(sock,buffer,BUFFER_SIZE,MSG_PEEK);
		EditPrintf (hwndEdit, TEXT ("Waiting to receive...")) ;
		return TRUE ;

		// This even occurs when the "recv" call can be made

	case FD_READ:
		KillTimer (ID_TIMER) ;
		EditPrintf (hwndEdit, TEXT ("\r\n")) ;

		if (wError)
		{
			EditPrintf (hwndEdit, TEXT ("FD_READ error #%i."), 
				wError) ;
			SendMessage (WM_COMMAND, IDCANCEL, 0) ;
			return TRUE ;
		}
		// Get the time and swap the bytes
//
		iSize = recv (sock, (char *) &ulTime, 4, 0) ;
		//iSize = recv (sock, buffer, BUFFER_SIZE, 0) ;
		ulTime = ntohl (ulTime) ;
		EditPrintf (hwndEdit, 
			TEXT ("Received current time of %u seconds ")
			TEXT ("since Jan. 1 1900.\r\n"), ulTime) ;

		// Change the system time
		//EditPrintf (hwndEdit, buffer);
		SendMessage (WM_COMMAND, IDCANCEL, 0) ;
		return TRUE ;
	case FD_WRITE:

		
		if (wError)
		{
			EditPrintf (hwndEdit, TEXT ("FD_WRITE error #%i."), 
				wError) ;
			SendMessage (WM_COMMAND, IDCANCEL, 0) ;
			return TRUE ;
		}
		send(sock,"Message from client",sizeof("Message from client"),0);
		return TRUE;
	}
	return FALSE ;
}




void NETPMP::OnIdcancel()
{
	// TODO: Add your command handler code here
	closesocket (sock) ;
	sock = 0 ;
	WSACleanup () ;
	//hwndButton->SetWindowText (szOKLabel) ;
	//SetWindowLong (hwndButton, GWL_ID, IDOK) ;

	KillTimer (ID_TIMER) ;
	EditPrintf (hwndEdit, TEXT ("\r\nSocket closed.\r\n")) ;

}


void NETPMP::OnClickedClose()
{
	// TODO: Add your control notification handler code here
	if (sock)
		SendMessage (WM_COMMAND, IDCANCEL, 0) ;
	this->ShowWindow(SW_HIDE);
}


//void NETPMP::OnClose()
//{
//	// TODO: Add your message handler code here and/or call default
//	this->IsWindowVisible();
//	CDialog::OnClose();
//}
