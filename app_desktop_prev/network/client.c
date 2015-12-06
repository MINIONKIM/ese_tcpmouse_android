#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <errno.h>

// -------------------- client -----------------------

int main(void)
{
	int iSock;
	struct sockaddr_in staddr;
	int iRet;	
	unsigned char ucBuff[250];
	
	// IPv4�� ����ϰ� TCP��� ����ϴ� ������ ����
	iSock = socket(AF_INET,SOCK_STREAM,0); 
	

	
	if(0 > iSock) // �����߻���
	{
		perror("socket() ");
		return 0;
	}

	staddr.sin_family 	= AF_INET;
	staddr.sin_port		= htons(PORT); // '4030'�� port�� ������ �����̴�.
	staddr.sin_addr.s_addr		= inet_addr("192.168.10.250"); // ���ڿ�(IP)�� int�� �ٲپ��ִ� �Լ�
	

	iRet = connect(iSock,(struct sockaddr*)&staddr,sizeof(staddr));


	if(0 > iRet) // connect()���н� ������ ��ȯ�ϹǷ�
	{
		perror("connect() ");
		close(iSock);
		return 0;
	}
	
	
	printf("\niSock = [%d] �Դϴ�.\n\n",iSock);

	
	iRet = read(iSock,ucBuff,sizeof(ucBuff)); // server.c�� "WELCOME"�� �д´�.
	ucBuff[iRet] = 0; // WELCOME ���� �迭�� '0'�� ����
	
	printf("[%s]\n",ucBuff);
	
	close(iSock);	// ������ ������ close()���

	return 0;
}

/*
int main(void)
{
	int iSock;
	struct sockaddr_in staddr;
	struct sockaddr_in stClient1;
	int iRet;	
	unsigned int uiSize;
	int iClient1;
	
	// IPv4�� ����ϰ� TCP��� ����ϴ� ������ ����
	iSock = socket(AF_INET,SOCK_STREAM,0); 

	if(0 > iSock) // �����߻���
	{
		perror("isock() ");
		return 0;
	}

	staddr.sin_family 	= AF_INET;
	staddr.sin_port		= htons(PORT); // '4030'�� port�� ������ �����̴�.
	staddr.sin_addr.s_addr		= inet_addr("192.168.10.250"); // ���ڿ�(IP)�� int�� �ٲپ��ִ� �Լ�
	

	iRet = bind(iSock,(struct sockaddr*)&staddr,sizeof(staddr));


	if(0 > iRet) // connect()���н� ������ ��ȯ�ϹǷ�
	{
		perror("bind() ");
		close(iSock);
		return 0;
	}

	iRet = listen(iSock,5); // ���ť �� 5�� �����Ѵ�.

	
	if(0 > iRet) // �����߻���
	{
		perror("listen() ");
		return 0;
	
	}
	

	
	uiSize = sizeof(staddr);
	iClient1 = accept(iSock,(struct sockaddr*)&stClient1,&uiSize); // accept();

	
	if(0 > iClient1) // accept()�� �����߻���
	{
		perror("accept() ");
		return 0;
	
	}

	
	printf("\niSock = [%d] �Դϴ�.\n\n",iSock);
	printf("\niClient1 = [%d] �Դϴ�.\n\n",iClient1);



	write(iClient1,"WELCOME",7); // ���濡�� ����


	
	close(iSock);	// ������ ������ close()���
	close(iClient1);
	
	return 0;
}
*/
