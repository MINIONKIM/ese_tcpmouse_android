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
//MoveMouse(10,10) current cursor point -> move x ->10 , y ->10
// need itoa function 
