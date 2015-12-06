#include <stdlib.h>
#include <string.h>

void scaledata(char* arr)
{
	int int_arr;
	int_arr = _atoi(arr);
	//printf("------------>%d\n",int_arr);
	_itoa(int_arr,10,arr);
}
