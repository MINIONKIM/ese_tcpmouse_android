#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUF_LEN 64

struct coord{
	int x = 0;
	int y = 0;
}
