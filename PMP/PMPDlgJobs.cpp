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
		MessageBox(TEXT("���ͳɹ���"),"Info",MB_OK);
	}else{
		MessageBox(TEXT("����ʧ�ܣ�"),"Info",MB_OK);
	}
}

void PMPDlgJobs::OnBnClickedButtonLink()
{
	// TODO: Add your control notification handler code here
	//MessageBox(m_Combo_PmpServerIP_str,"IP",MB_OK);
	int flag = PMPReqExeCmd();
	if (flag == 1){
		MessageBox(TEXT("���óɹ���"),"Info",MB_OK);
	}else{
		MessageBox(TEXT("����ʧ�ܣ�"),"Info",MB_OK);
	}
}

void PMPDlgJobs::OnBnClickedButtonReceive()
{
	// TODO: Add your control notification handler code here
	
	int flag = PMPReqReceiveResultFile();
	if (flag == 0){
		MessageBox(TEXT("���ճɹ���"),"Info",MB_OK);
	}else{
		MessageBox(TEXT("����ʧ�ܣ�"),"Info",MB_OK);
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
	
	// ��һ����
	// �ͻ��ˣ�ȡ�������е��ļ����ƣ���ָ���ļ����͸��������������ʶ����SENDFILE
	// ����ˣ��������˽����ļ�
	// �ͻ��ˣ�
	// ���ȷ����������ͱ�ʶ��
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
	// ����ͨ����������ķ�ʽ
	printf("I'am sending!\n");
	
    char file_name_buffer[BUFFER_SIZE];  
    memset(file_name_buffer, 0,sizeof(file_name_buffer));  
    strncpy(file_name_buffer, file_name, strlen(file_name) > BUFFER_SIZE ? BUFFER_SIZE : strlen(file_name));  
    // �����������buffer�е����ݣ���ʱbuffer�д�ŵ��ǿͻ�����Ҫ���յ��ļ�������
	printf("file name:%s\n file name size:%d\n",file_name_buffer,strlen(file_name_buffer));
    send(ClientSocket, file_name_buffer, strlen(file_name_buffer), 0);  
	
	char buffer[BUFFER_SIZE];
    FILE *fp = fopen(file_name, "r");  
    if (fp == NULL)  
    {  
        printf("File:%s Can Not Open To Write!\n", file_name);  
        exit(1);  
    }  else{
		// �ӿͻ��˷������ݵ�buffer��  
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
	
	// �ڶ�����
	// �ͻ��ˣ����������еĿ�ִ���ļ����ƣ�
	// ����ˣ��������˰���ִ���ļ�����ִ�иÿ�ִ���ļ�
	// �ͻ��ˣ�
	// ���ȷ����������ͱ�ʶ��
	char requesttype[10];
    memset(requesttype, 0,sizeof(requesttype));  
	sprintf(requesttype,"%d",EXECMD);
	send(ClientSocket, requesttype, 1, 0); 
	
	//���÷��Ϳ�ִ���ļ����ƵĹ���
	//printf("���������У��ɴ���������\n");
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
	
	// ��������
	// �ͻ��ˣ����շ��������ͻ�����*.dat�ļ���
	// ����ˣ���������ɨ�����������ɵ�*.dat�ļ���������*.dat�ļ����Ʒ��͸��ͻ��ˣ��ÿͻ���ѡ���ȡ��Щ�ļ�
	// ���߽������ļ�������͸��ͻ���
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
    // �����������buffer�е����ݣ���ʱbuffer�д�ŵ��ǿͻ�����Ҫ���յ��ļ�������  
    send(ClientSocket, buffer, BUFFER_SIZE, 0);  
	
    FILE *fp = fopen(file_name, "w");  
    if (fp == NULL)  
    {  
        //printf("File:\t%s Can Not Open To Write!\n", file_name);  
		MessageBox(NULL,"�ļ�дʧ��","Info",MB_OK);
        exit(1);  
    }  
	
    // �ӷ������˽������ݵ�buffer��    
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


	// ���ý����ļ��Ĺ���

	/* close socket */
    closesocket(ClientSocket);
    WSACleanup();
    return 0;  
}
