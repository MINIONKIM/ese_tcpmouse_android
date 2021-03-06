#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <math.h>

#define MAXBUF 256

void cleararr(char buf[])
{
	int i;
	for(i=0;i<10;i++)
	{
		buf[i]=0;
	}
	//printf("asd : %s",buf);
}

void _itoa(int val, int base, char *arr)
{
	char buf[32] = {0,};
	int i=30;
	char result[10] = {0,};
	int k = 0;

	if(val ==0)
	{
		arr[0]='0';
		arr[1]=0;
		return;
	}
	if(val < 0)
	{
		val = val*-1;
		result[k] = '-';
		k++;
	}
	//printf("----------> original : %d \n",val);
	for(;val && i; --i, val /= base)
	{
		buf[i] = "0123456789abcdef"[val % base];
		//if(buf[i]!=0)printf("%d : %c\n",i,buf[i]);
	}
	//for(i=0;i<32;i++)printf("%d : %c\n",i,buf[i]);
	for(i=0; i<32; i++)
	{
		if(buf[i] != 0)
		{
			result[k] = buf[i];
			//printf("%c",buf[i]);
			k++;
		}

	}
	//printf("ascii value : %s \n", result);
	cleararr(arr);


	for(i=0;i<strlen(result);i++){
		arr[i]=result[i];
	}

	//return &result[k+1];
	//return result;
}

int _atoi(char* str)
{
	int len = strlen(str);
	int i;
	int radix = 0;
	int result = 0;

	if(str[0] == '-')
	{
		radix = (int)pow((double)10, (double)len-2);

		for(i=1; i<=len; i++)
		{
			result += (str[i] - '0') * radix;
			radix /= 10;
		}
		result = 0 - result;
	}
	 else 
	{
		radix = (int)pow((double)10, (double)len-1);

		for(i=0; i<=len; i++)
		{
			result += (str[i] - '0') * radix;
			radix /= 10;
		}
	}
	return -result/50;

}

void parsing(char* buf,char* x,char* y,char* z)
{
	if (buf[0] == 'L')
		clickMouse(1);
	else if (buf[0] == 'R')
		clickMouse(3);

	int i=0;
	int idx=0;

	cleararr(x);
	cleararr(y);
	cleararr(z);
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

void scaledata(char* arr)
{
	int int_arr;
	int_arr = _atoi(arr);
	//printf("------------>%d\n",int_arr);
	_itoa(int_arr,10,arr);
}

void clickMouse(int _d)
{
	// 1 -> left 3 -> right
	char* instruction = "xdotool click ";
	char d[2] = {0, 0};
	char inst[30] = {0, };

	d[0] = _d + '0';
	strcat(inst, instruction);
	strcat(inst, d);

	system(inst);
}

void MoveMouse(char* x,char* y)
{
	char* instruction = "xdotool mousemove_relative -- ";
	char* sp=" ";
	int i;
	char inst[50]={0,};
	printf("z : %s , x : %s \n",x,y);
	strcat(inst, instruction);
	strcat(inst, x);
	strcat(inst, sp);
	strcat(inst, y);
	printf("%s\n", inst);
	usleep(100);
	for(i=0;i<10;i++) system(inst);

	//memset(inst, NULL, sizeof(inst));
}

int main(int argc, const char* argv[])
{
	int time = 0;
        int ssock, csock;
        int clen;
        struct sockaddr_in client_addr, server_addr;
        char buf[MAXBUF] = "Im server connecting success.";

	char readbuf[MAXBUF];
        memset(&readbuf, 0, MAXBUF);

        int i=0;
	int idx=0;
	char x[10]={0,};
	char y[10]={0,};
	char z[10]={0,};

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

        while(1)
        {     csock = accept(ssock, (struct sockaddr *)&client_addr, &clen);
               i++;
	         //if(write(csock, buf, MAXBUF) <= 0)
                 //      perror("Writing error : ");

               if(read(csock, readbuf, MAXBUF) < 0)
                       perror("Reading error : ");

                fprintf(stderr, "[client] %s\n", readbuf);
                parsing(readbuf,x,y,z);
		scaledata(x);
		scaledata(y);
		scaledata(z);
		//printf("sa----- %s %s %s\n ",x,y,z);
		MoveMouse(z,x);
                close(csock);

        }
        return 0;
}


