#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void MoveMouse(char* x,char* y)
{
	char* instruction = "xdotool mousemove_relative -- ";
	char* sp=" ";
	int i;
	char inst[50]={0,};
	printf("z : %s , x : %s \n",x,y);
	strcat(inst, instruction);
	strcat(inst, x);
	strcat(inst, sp);
	strcat(inst, y);
	printf("%s\n", inst);
	usleep(100);
	for(i=0;i<10;i++) system(inst);

}
