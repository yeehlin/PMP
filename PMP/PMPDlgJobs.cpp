// PMPDlgJobs.cpp : implementation file
//

#include "stdafx.h"

#include "PMPSocket.h"

#include "PMP.h"
#include "PMPDlgJobs.h"
#include "afxdialogex.h"



// PMPDlgJobs dialog

IMPLEMENT_DYNAMIC(PMPDlgJobs, CDialog)

PMPDlgJobs::PMPDlgJobs(CWnd* pParent /*=NULL*/)
	: CDialog(PMPDlgJobs::IDD, pParent)
{

	m_Combo_PmpServerIP_str = _T("");
	m_Combo_PmpServerPort_str = _T("");
}

PMPDlgJobs::~PMPDlgJobs()
{
}

void PMPDlgJobs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PMPSERVERIP, m_Combo_PmpServerIP);
	DDX_Control(pDX, IDC_COMBO_PMPSERVERPORT, m_Combo_PmpServerPort);
	DDX_CBString(pDX, IDC_COMBO_PMPSERVERIP, m_Combo_PmpServerIP_str);
	DDV_MaxChars(pDX, m_Combo_PmpServerIP_str, 19);
	DDX_CBString(pDX, IDC_COMBO_PMPSERVERPORT, m_Combo_PmpServerPort_str);
}


BEGIN_MESSAGE_MAP(PMPDlgJobs, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_PMPSERVERIP, &PMPDlgJobs::OnCbnSelchangeComboPmpserverip)
	ON_BN_CLICKED(IDC_BUTTON_LINK, &PMPDlgJobs::OnBnClickedButtonLink)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &PMPDlgJobs::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_RECEIVE, &PMPDlgJobs::OnBnClickedButtonReceive)
END_MESSAGE_MAP()


// PMPDlgJobs message handlers


void PMPDlgJobs::OnCbnSelchangeComboPmpserverip()
{
	// TODO: Add your control notification handler code here
}


BOOL PMPDlgJobs::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	m_Combo_PmpServerIP_str = "10.141.25.153";
	m_Combo_PmpServerPort_str = "6666";
	m_Combo_PmpServerIP.AddString(m_Combo_PmpServerIP_str);
	m_Combo_PmpServerPort.AddString(m_Combo_PmpServerPort_str);

	m_Combo_PmpServerIP.SetCurSel(0);
	m_Combo_PmpServerPort.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void PMPDlgJobs::OnBnClickedButtonSend()
{
	// TODO: Add your control notification handler code here
	int flag = PMPReqSendParamFile();
	if (flag == 0){
		MessageBox(TEXT("发送成功！"),"Info",MB_OK);
	}else{
		MessageBox(TEXT("发送失败！"),"Info",MB_OK);
	}
}

void PMPDlgJobs::OnBnClickedButtonLink()
{
	// TODO: Add your control notification handler code here
	//MessageBox(m_Combo_PmpServerIP_str,"IP",MB_OK);
	int flag = PMPReqExeCmd();
	if (flag == 1){
		MessageBox(TEXT("调用成功！"),"Info",MB_OK);
	}else{
		MessageBox(TEXT("调用失败！"),"Info",MB_OK);
	}
}

void PMPDlgJobs::OnBnClickedButtonReceive()
{
	// TODO: Add your control notification handler code here
	
	int flag = PMPReqReceiveResultFile();
	if (flag == 0){
		MessageBox(TEXT("接收成功！"),"Info",MB_OK);
	}else{
		MessageBox(TEXT("接收失败！"),"Info",MB_OK);
	}
}

int PMPReqSendParamFile(){
	//if (argc != 2)  
    //{  
    //    printf("Usage: ./%s ServerIPAddress\n", argv[0]);  
    //    exit(1);  
   // }  
	
	WSADATA  Ws;
    SOCKET ClientSocket;
    struct sockaddr_in ClientAddr;
    int Ret = 0;
    char SendBuffer[BUFFER_SIZE];
	
	/* Init Windows Socket */
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        printf("Init Windows Socket Failed::%d\n", GetLastError());
        return -1;
    }
	
    /* Create Socket */
    ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( ClientSocket == INVALID_SOCKET )
    {
        printf("Create Socket Failed::%d\n", GetLastError());
        return -1;
    }
	
    ClientAddr.sin_family = AF_INET;
    ClientAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    ClientAddr.sin_port = htons(HELLO_WORLD_SERVER_PORT);
    memset(ClientAddr.sin_zero, 0x00, 8);
	
	/* connect socket */
    Ret = connect(ClientSocket,(struct sockaddr*)&ClientAddr, sizeof(ClientAddr));
    if ( Ret == SOCKET_ERROR )
    {
        printf("Connect Error::%d\n", GetLastError());
        return -1;
    }else
    {
        printf("Connect succeeded!\n");
    }
	
	if ( Ret == SOCKET_ERROR )
	{
		printf("Send Info Error::%d\n", GetLastError());
		return -1;
    }
	
	// 第一步：
	// 客户端：取出请求中的文件名称，将指定文件发送给服务器，请求标识符：SENDFILE
	// 服务端：服务器端接收文件
	// 客户端：
	// 首先发送请求类型标识符
	char requesttype[10];
    memset(requesttype, 0,sizeof(requesttype));  
	sprintf(requesttype,"%d",SENDFILE);
	send(ClientSocket, requesttype, 10, 0); 
	
	// 
    char file_name[FILE_NAME_MAX_SIZE + 1];  
    memset(file_name, 0,sizeof(file_name));  
    printf("Please Input File Name On Client:\n");  
    //scanf("%s", file_name);
	strncpy(file_name,"parameter.in",strlen("parameter.in"));
	//printf("%s\n",pPMPReq->parameter_in);
	// 改用通过变量传入的方式
	printf("I'am sending!\n");
	
    char file_name_buffer[BUFFER_SIZE];  
    memset(file_name_buffer, 0,sizeof(file_name_buffer));  
    strncpy(file_name_buffer, file_name, strlen(file_name) > BUFFER_SIZE ? BUFFER_SIZE : strlen(file_name));  
    // 向服务器发送buffer中的数据，此时buffer中存放的是客户端需要接收的文件的名字
	printf("file name:%s\n file name size:%d\n",file_name_buffer,strlen(file_name_buffer));
    send(ClientSocket, file_name_buffer, strlen(file_name_buffer), 0);  
	
	char buffer[BUFFER_SIZE];
    FILE *fp = fopen(file_name, "r");  
    if (fp == NULL)  
    {  
        printf("File:%s Can Not Open To Write!\n", file_name);  
        exit(1);  
    }  else{
		// 从客户端发送数据到buffer中  
		memset(buffer,0, sizeof(buffer));
		int file_block_length = 0;
		while( (file_block_length = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0)
		{
			printf("file_block_length = %d\n", file_block_length);
			printf("%s\n",buffer);
			
			if (send(ClientSocket, buffer, file_block_length, 0) < 0)
				//if (send(ClientSocket, buffer, sizeof(buffer), 0) < 0)
			{
				printf("Send File:%s Failed!\n", file_name);
				break;
			}
			
			memset(buffer, 0,BUFFER_SIZE);
		}
		fclose(fp);
	}
	
	//printf("File:%s Transfer Finished to Server [%s]!\n", file_name, argv[1]);
	// printf("Recieve File:\t %s From Server[%s] Finished!\n", file_name, argv[1]);  

	/* close socket */
    closesocket(ClientSocket);
    WSACleanup();
    return 0;  
}


int PMPReqExeCmd(){
	//	if (argc != 2)  
    //{  
    //    printf("Usage: ./%s ServerIPAddress\n", argv[0]);  
    //    exit(1);  
   // }  
	
	WSADATA  Ws;
    SOCKET ClientSocket;
    struct sockaddr_in ClientAddr;
    int Ret = 0;
    char SendBuffer[BUFFER_SIZE];
	
	/* Init Windows Socket */
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        printf("Init Windows Socket Failed::%d\n", GetLastError());
        return -1;
    }
	
    /* Create Socket */
    ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( ClientSocket == INVALID_SOCKET )
    {
        printf("Create Socket Failed::%d\n", GetLastError());
        return -1;
    }
	
    ClientAddr.sin_family = AF_INET;
    ClientAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    ClientAddr.sin_port = htons(HELLO_WORLD_SERVER_PORT);
    memset(ClientAddr.sin_zero, 0x00, 8);
	
	/* connect socket */
    Ret = connect(ClientSocket,(struct sockaddr*)&ClientAddr, sizeof(ClientAddr));
    if ( Ret == SOCKET_ERROR )
    {
        printf("Connect Error::%d\n", GetLastError());
        return -1;
    }else
    {
        printf("Connect succeeded!\n");
    }
	
	if ( Ret == SOCKET_ERROR )
	{
		printf("Send Info Error::%d\n", GetLastError());
		return -1;
    }
	
	// 第二步：
	// 客户端：发送请求中的可执行文件名称；
	// 服务端：服务器端按可执行文件名称执行该可执行文件
	// 客户端：
	// 首先发送请求类型标识符
	char requesttype[10];
    memset(requesttype, 0,sizeof(requesttype));  
	sprintf(requesttype,"%d",EXECMD);
	send(ClientSocket, requesttype, 1, 0); 
	
	//做好发送可执行文件名称的工作
	//printf("输入命令行（可带参数）：\n");
	//gets(SendBuffer);
	/* send data to server */
	//Ret = send(ClientSocket, SendBuffer, (int)strlen(SendBuffer), 0);
	Ret = send(ClientSocket, "Hello EffProperty", (int)strlen("Hello EffProperty"), 0);
	if ( Ret == SOCKET_ERROR )
	{
		printf("Send Info Error::%d\n", GetLastError());
		return -1;
	//	break;
    }

	/* close socket */
    closesocket(ClientSocket);
    WSACleanup();
    return 1;  

}

int PMPReqReceiveResultFile(){
	//if (argc != 2)  
    //{  
    //    printf("Usage: ./%s ServerIPAddress\n", argv[0]);  
    //    exit(1);  
   // }  
	
	WSADATA  Ws;
    SOCKET ClientSocket;
    struct sockaddr_in ClientAddr;
    int Ret = 0;
    char SendBuffer[BUFFER_SIZE];
	
	/* Init Windows Socket */
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        //printf("Init Windows Socket Failed::%d\n", GetLastError());
        return -1;
    }
	
    /* Create Socket */
    ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( ClientSocket == INVALID_SOCKET )
    {
        //printf("Create Socket Failed::%d\n", GetLastError());
        return -1;
    }
	
    ClientAddr.sin_family = AF_INET;
    ClientAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    ClientAddr.sin_port = htons(HELLO_WORLD_SERVER_PORT);
    memset(ClientAddr.sin_zero, 0x00, 8);
	
	/* connect socket */
    Ret = connect(ClientSocket,(struct sockaddr*)&ClientAddr, sizeof(ClientAddr));
    if ( Ret == SOCKET_ERROR )
    {
       // printf("Connect Error::%d\n", GetLastError());
        return -1;
    }else
    {
        //printf("Connect succeeded!\n");
    }
	
	if ( Ret == SOCKET_ERROR )
	{
		//printf("Send Info Error::%d\n", GetLastError());
		return 0;
    }
	
	// 第三步：
	// 客户端：接收服务器发送回来的*.dat文件；
	// 服务端：服务器端扫描所有新生成的*.dat文件，将所有*.dat文件名称发送给客户端，让客户端选择获取哪些文件
	// 或者将所有文件逐个发送给客户端
	char requesttype[10];
    memset(requesttype, 0,sizeof(requesttype));  
	sprintf(requesttype,"%d",RECEIVEFILE);
	send(ClientSocket, requesttype, 1, 0); 

	
    char file_name[FILE_NAME_MAX_SIZE + 1];  
    memset(file_name, 0x00,sizeof(file_name));  
    //printf("Please Input File Name On Server.\n");  
    //scanf("%s", file_name);  
	sprintf(file_name,"%s","strain.00000000.dat");
    char buffer[BUFFER_SIZE];  
    memset(buffer, 0x00,sizeof(buffer));  
    strncpy(buffer, file_name, strlen(file_name) > BUFFER_SIZE ? BUFFER_SIZE : strlen(file_name));  
    // 向服务器发送buffer中的数据，此时buffer中存放的是客户端需要接收的文件的名字  
    send(ClientSocket, buffer, BUFFER_SIZE, 0);  
	
    FILE *fp = fopen(file_name, "w");  
    if (fp == NULL)  
    {  
        //printf("File:\t%s Can Not Open To Write!\n", file_name);  
		MessageBox(NULL,"文件写失败","Info",MB_OK);
        exit(1);  
    }  
	
    // 从服务器端接收数据到buffer中    
    memset(buffer, 0x00, sizeof(buffer));  
    int length = 0;  
    while(length = recv(ClientSocket, buffer, BUFFER_SIZE, 0))  
    {  
        if (length < 0)  
        {  
           // printf("Recieve Data From Server %s Failed!\n", argv[1]);  
            break;  
        }  
		
        int write_length = fwrite(buffer, sizeof(char), length, fp);  
		//printf("%d has been wrote.\n",write_length);
        if (write_length < length)  
        {  
            //printf("File:\t%s Write Failed!\n", file_name);  
            break;  
        }  
        memset(buffer, 0x00, BUFFER_SIZE);  
    }  
	fclose(fp);
   // printf("Recieve File:\t %s From Server[%s] Finished!\n", file_name, argv[1]);  


	// 做好接收文件的工作

	/* close socket */
    closesocket(ClientSocket);
    WSACleanup();
    return 0;  
}
