#include <stdio.h>
#include <unistd.h>
//#include <stdlib.h>
#include <string.h>

char* x_coord;
char* y_coord = " 300";
char* itoa(int val,int base)
{
	static char buf[32] = {0};
	int i=30;

	for(;val && i; --i, val /= base)
	buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}

void MoveMouse(int x,int y)
{
	char* instruction = "xdotool mousemove_relative ";
	char* x_coord;
	char* y_coord;
	char* sp=" ";
	char inst[50];

	x_coord=itoa(x,10);
	y_coord=itoa(x,10);

	strcat(inst, instruction);
	strcat(inst, x_coord);
	strcat(inst, sp);
	strcat(inst, y_coord);
	printf("%s\n", inst);
	usleep(100);
	system(inst);
	//memset(inst, NULL, sizeof(inst));
}
int main()
{

	MoveMouse(10,10);



/*
	int i = 0;
//	char *temp;
	char* instruction = "xdotool mousemove_relative ";
	
	char inst[27];
	
	//printf("%s \n",instruction);
	
	for(i=0;i<500;i++)
	{
		//strcpy(temp,itoa(i,10));
		//x_coord = itoa(i,10);
		x_coord = itoa(1,10);
		y_coord = " 1";
		strcat(inst, instruction);
		strcat(inst, x_coord);
		strcat(inst, y_coord);

		printf("%s\n", inst);

		//execlp("xdotool","xdotool","mousemove",temp,"300",NULL);
		system(inst);
		usleep(100);
		memset(inst, NULL, sizeof(inst));
	}
	*/

	return 0;

}
