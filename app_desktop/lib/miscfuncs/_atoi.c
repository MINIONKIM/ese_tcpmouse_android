#include "miscfuncs.h"
#include <math.h>
#include <string.h>

int _atoi(char *str)
{
	int len = strlen(str);
	int i;
	int radix = 0;
	int result = 0;

	if(str[0] == '-'){
		radix = (int)pow((double)10, (double)len-2);

		for(i=1; i<=len; i++){
			result += (str[i] - '0') * radix;
			radix /= 10;
		}

		result = -result;
	} else {
		radix = (int)pow((double)10, (double)len-1);

		for(i=0; i<=len; i++){
			result += (str[i] - '0') * radix;
			radix /= 10;
		}
	}

	return -result/50;
}
