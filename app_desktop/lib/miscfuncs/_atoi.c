#include "miscfuncs.h"
#include <string.h>

int _pow(int n)
{
	int i;
	int result = 1;

	for(i=0; i<n; i++)
	{
		result *= 10;
	}

	return result;
}

int _atoi(char *str)
{
	int len = strlen(str);
	int i;
	int radix = 0;
	int result = 0;

	if(str[0] == '-'){
		radix = _pow(len-2);

		for(i=1; i<=len; i++){
			result += (str[i] - '0') * radix;
			radix /= 10;
		}

		result = -result;
	} else {
		radix = _pow(len-1);

		for(i=0; i<=len; i++){
			result += (str[i] - '0') * radix;
			radix /= 10;
		}
	}

	return -result/50;
}
