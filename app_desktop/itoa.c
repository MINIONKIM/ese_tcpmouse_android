#include <stdio.h>
#include <stdlib.h>

// integer to char
// itoa : convert to character in s
// if itoa(50,10) dec "50"


char* itoa(int val,int base)
{
	static char buf[32] = {0,};
	int i=30;
	char result[10] = {0,};
	int k = 0;
	
	if(val < 0)
	{
		val = val*-1;
		//printf("%d\n",val);
		result[k] = '-';
		k++;
	}
	for(;val && i; --i, val /= base)
	{
		buf[i] = "0123456789abcdef"[val % base];
		//printf("%d %c\n" , i,buf[i]);
	}
	
	for(i=0; i<32; i++)
	{
		if(buf[i] != 0)
		{
			result[k] = buf[i];
			//printf("%c",buf[i]);
			k++;	
		}
		
	}
	printf("ascii value : %s \n", result);
	//return &result[k+1];
	return result;
}

/*
char* itoa(int value, int jinsu)
{
	int i = 0;
	int sign = 0;
	char buf[] = {0,};
 
	while((value /= jinsu) >0)
	{
		buf[i++] = value % jinsu + '0';
	};

	return buf;
}
*/
int main (void)
{
	int i = 100;
	char test[10] = {0,};
	//char *test ;

	printf("prev value : %d \n",i);
	test[] = itoa(i,10);
	printf("ascii value : %s \n", test);
	return 0;
}
