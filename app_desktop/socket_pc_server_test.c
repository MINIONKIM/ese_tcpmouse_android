#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>

#define MAXBUF 256

void parsing(char* buf,char* x,char* y,char* z)
{
	int i=0;
	int idx=0;

	for(i=0;i<10;i++)
	{
		x[i]=0;
		y[i]=0;
		z[i]=0;
	}
	i=0;
	while(buf[idx]!=' ')
	{
		x[i]=buf[idx];
		i++;
		idx++;
	}
	i=0;
	idx++;
	while(buf[idx]!=' ')
	{
		y[i]=buf[idx];
		i++;
		idx++;
	}
	i=0;
	idx++;
	while(buf[idx]!=' ')
	{
		z[i]=buf[idx];
		i++;
		idx++;
	}
	printf("pa----- %s %s %s \n ",x,y,z);
}

int main(int argc, const char* argv[])
{
	int time = 0;
        int ssock, csock;
        int clen;
        struct sockaddr_in client_addr, server_addr;
        char buf[MAXBUF] = "Im server connecting success.";

        //make server socket
        if((ssock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        {       perror("Failed to make socket discriptor");
               exit(1);
        }

        clen = sizeof(client_addr);

        //setting address structure
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        server_addr.sin_port = htons(9999);

    //binding
   if(bind(ssock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
   {       perror("Failed to binding server socket");
           exit(1);
   }

        //wait for client
        if(listen(ssock, 8) <0 )
        {       perror("listen error : ");
               exit(1);
        }

        char readbuf[MAXBUF];
        memset(&readbuf, 0, MAXBUF);

        int i=0;
	int idx=0;
	char x[10]={0,};
	char y[10]={0,};
	char z[10]={0,};

        while(1)
        {     csock = accept(ssock, (struct sockaddr *)&client_addr, &clen);
               i++;
	         //if(write(csock, buf, MAXBUF) <= 0)
                 //      perror("Writing error : ");

               if(read(csock, readbuf, MAXBUF) < 0)
                       perror("Reading error : ");

               fprintf(stderr, "[client] %s\n", readbuf);
               parsing(readbuf,x,y,z);
               close(csock);

        }
        return 0;
}
