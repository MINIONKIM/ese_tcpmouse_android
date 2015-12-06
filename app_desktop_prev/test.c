#include <stdlib.h>

int main (int argc, char *argv[])
{
	int i=10;
	char buf[128];
	itoa(10,buf, 10);
	printf("%s\n",buf);

	return 0;
}
