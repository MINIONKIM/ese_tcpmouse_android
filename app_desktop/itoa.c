#include <stdio.h>
#include <stdlib.h>

// integer to char
// if itoa(50,10) dec "50"
char* itoa(int val,int base)
{
	static char buf[32] = {0};
	int i=30;

	for(;val && i; --i, val /= base)
	buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}

int main(int argc, char *argv[])
{
	char strbuf[256];
	char* str;
	memset(strbuf,0x00,256);

	str = itoa(-234, 10);

	printf("%s\n", strbuf);
}
