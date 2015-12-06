#include "miscfuncs.h"
#include <string.h>

#define null 0

void _itoa(int val, int base, char *arr)
{
	char buf[32] = {0, };
	int i = 30;
	char result[10] = {0, };
	int k = 0;

	if(val == 0){
		arr[0] = '0';
		arr[1] = null;
		return;
	}

	if(val < 0){
		val = -val;
		result[k] = '-';
		k++;
	}

	for(;val && i; --i, val /= base){
		buf[i] = "0123456789abcdef"[val % base];
	}

	for(i=0; i<32; i++){
		if(buf[i] != 0){
			result[k] = buf[i];
			k++;
		}
	}

	cleararr(arr);

	for(i=0; i<strlen(result); i++){
		arr[i] = result[i];
	}
}
