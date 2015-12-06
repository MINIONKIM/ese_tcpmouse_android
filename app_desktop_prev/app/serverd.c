#include "sock_tcp.h"

int main(int argc, const char* argv[])
{
	int sock_serv;
	
	struct sockaddr_in addr_serv;	
	
	addr_serv.sin_family = AF_INET;
	addr_serv.sin_addr.s_addr = inet_addr("192.168.0.100"); // SERVER IP
	addr_serv.sin_port = htons(9999); // PORT

	if((sock_serv = socket(PF_INET, SOCK_STREAM, 0)) < 0){
		printf("err : cannot create socket");
		exit(1);
	}
}
