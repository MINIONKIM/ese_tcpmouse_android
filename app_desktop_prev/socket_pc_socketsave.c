//1. 서버

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include <unistd.h>

#include <arpa/inet.h>

#include <sys/socket.h>

 

#define MAX 1000

void changebig(char*);

void stringreverse(char*);

void err_handling(char*);

 

int main(void)

{

int serv_sock;

int clnt_sock;

struct sockaddr_in serv_addr;

struct sockaddr_in clnt_addr;

socklen_t clnt_addr_size;

int recv_cnt = 0;

char buf[MAX];

char *point;

int i, len;

 

 

serv_sock = socket(PF_INET, SOCK_STREAM, 0);

if(serv_sock == -1)

err_handling("socket() error");

 

memset(&serv_addr,0,sizeof(serv_addr));

serv_addr.sin_family = AF_INET;

serv_addr.sin_addr.s_addr = INADDR_ANY;

serv_addr.sin_port = htons(9000);

 

if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)

err_handling("bind() error");

if(listen(serv_sock, 5) == -1)

 

err_handling("listen() error");

printf("TCP echo server ready!!\n");

 

clnt_addr_size = sizeof(clnt_addr);

clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

if(clnt_sock == -1)

err_handling("accept() error");

printf("client connected\n");

 

printf("client message received : ");

while(1)

{

recv_cnt += read(clnt_sock, &buf[recv_cnt], MAX-1);

if((point = strchr(buf,'.')) != NULL || (point = strchr(buf,'\n')) != NULL)

{

point[0] = '\0';

break;

}

}

puts(buf);

changebig(buf);

stringreverse(buf);

len = strlen(buf);

buf[len] = '.';

buf[++len] = '\0';

printf("client messge echo : %s\n",buf);

for(i=0;i < len;i++)

{

write(clnt_sock,buf+i,1);

}

shutdown(clnt_sock, SHUT_WR);

 

close(clnt_sock);

close(serv_sock);

 

return 0;

}

void err_handling(char *msg)

{

fputs(msg,stderr);

fputc('\n',stderr);

exit(1);

}

void changebig(char* s)

{

int i = 0;

while(s[i] != '\0')

{

if(s[i] >= 'a' && s[i] <= 'z')

s[i] -= 'a' - 'A';

i++;

}

}

void stringreverse(char *s)

{

int i = 0, len;

char *t;

 

len = strlen(s);

t = (char*)malloc(sizeof(char)*len+1);

t[len] = '\0';

for(i = 0; i<len;i++)

t[len-1-i] = s[i];

strcpy(s,t);

free(t);

}

 

 

 

 

 

 

//2. 클라이언트

 

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include <unistd.h>

#include <arpa/inet.h>

#include <sys/socket.h>

 

#define MAX 1000

 

void err_handling(char *msg);

 

int main(int argc, char* argv[])

{

int sock;

struct sockaddr_in serv_addr;

int len = 0, read_len = 0, i;

char *point;

char msgbuf[MAX];

char buf[MAX];

 

if(argc != 3)

{

printf("Usage : %s <port>\n", argv[0]);

exit(1);

}

sock = socket(PF_INET, SOCK_STREAM, 0);

if(sock == -1)

err_handling("socket() error");

 

memset(&serv_addr,0,sizeof(serv_addr));

 

serv_addr.sin_family = AF_INET;

serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

serv_addr.sin_port = htons(atoi(argv[2]));

 

if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)

err_handling("connect() error");

else

printf("TCP echo client start\n");

 

printf("client message send : ");

while(1)

{

msgbuf[len] = getchar();

if(msgbuf[len] == '.' || msgbuf[len] == '\n')

{

msgbuf[++len] = '\0';

len = strlen(msgbuf);

break;

}

len++;

}

 

for(i=0;i<len;i++)

{

write(sock,msgbuf+i,1);

}

 

while(1)

{

read_len += read(sock,&buf[read_len], MAX-1);

if((point = strchr(buf,'.'))!=NULL || (point = strchr(buf,'\n')) != NULL)

{

point[0] = '\0';

break;

}

}

 

printf("echo message received : %s\n",buf);

close(sock);

 

return 0;

}

void err_handling(char *msg)

{

fputs(msg,stderr);

fputc('\n',stderr);

exit(1);

}

