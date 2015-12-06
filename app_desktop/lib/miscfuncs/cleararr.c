#include "miscfuncs.h"

void cleararr(char buf[])
{
	int i;

	for(i=0; i<10; i++){
		buf[i] = 0;
	}
}
