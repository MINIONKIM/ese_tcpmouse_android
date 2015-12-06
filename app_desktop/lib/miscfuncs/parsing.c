#include "miscfuncs.h"
#include <stdio.h>

int parsing(char* buf, char* x, char* y, char* z)
{
        if (buf[0] == 'L'){
		return 888;

	}
        else if (buf[0] == 'R'){
		return 999;
	}

        int i=0;
        int idx=0;

        cleararr(x);
        cleararr(y);
        cleararr(z);
        i=0;

        while(buf[idx]!=' '){
                x[i]=buf[idx];
                i++;
                idx++;
        }

        i=0;
        idx++;

        while(buf[idx]!=' '){
                y[i]=buf[idx];
                i++;
                idx++;
        }

        i=0;
        idx++;

        while(buf[idx]!=' '){
                y[i]=buf[idx];
                i++;
                idx++;
        }

        i=0;
        idx++;

        while(buf[idx]!=' '){
		z[i]=buf[idx];
                i++;
                idx++;
        }

        printf("pa----- %s %s %s \n ",x,y,z);

	return 1;
}


