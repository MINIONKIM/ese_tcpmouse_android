#include <stdio.h>
#include <unistd.h>
//#include <stdlib.h>
#include <string.h>

char* itoa(int val,int base)
{
	static char buf[32] = {0};
	int i=30;

	for(;val && i; --i, val /= base)
	buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}

void chand_coord(char _x_coord char _y_coord)
{
	*x_coord=iota(_x_coord,10);
	*y_coord=itoa(_y_coord,10);
	return ;
}

char get_x_coord()
{
	return system(xdotool getmousecursor x);
}
char get_y_coord()
{
	return system(xdotool getmousecursor y);
}
int main()
{
	int i = 0;
//	char *temp;
	char* instruction = "xdotool mousemove ";
	char* x_coord;
	char* y_coord = " 300";
	char inst[27];
	
	//printf("%s \n",instruction);

	for(i=0;i<500;i++)
	{
		//strcpy(temp,itoa(i,10));
		x_coord = itoa(i,10);

		strcat(inst, instruction);
		strcat(inst, x_coord);
		strcat(inst, y_coord);

		printf("%s\n", inst);

		//execlp("xdotool","xdotool","mousemove",temp,"300",NULL);
		system(inst);
		usleep(100);
		memset(inst, NULL, sizeof(inst));
	}
	return 0;

}
