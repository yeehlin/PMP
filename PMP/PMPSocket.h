#include <stdio.h>
#include <winsock2.h>
#include <Windows.h>

#pragma comment(lib,"ws2_32")
#define  PORT 4000
#define  IP_ADDRESS "10.141.25.153"

#define HELLO_WORLD_SERVER_PORT       6666  
#define BUFFER_SIZE                   1024  
#define FILE_NAME_MAX_SIZE            512  

// �������ͱ�ʶ�����������͵�����ʵ�ָ�֪������������������������������Ӧ����
#define SENDFILE 1
#define EXECMD 2
#define RECEIVEFILE 3


typedef struct {
	char parameter_in[128];
	char struct_in[128];
	char exe_name[128];
	char data_file_name[128];
}
PMPRequest,*PPMPRequest;

//�����Ͳ����ļ�
int PMPReqSendParamFile();
int PMPReqExeCmd();
int PMPReqReceiveResultFile();
//��ʼ��Socket
