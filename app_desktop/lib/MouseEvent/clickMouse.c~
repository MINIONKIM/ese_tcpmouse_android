#include <string.h>
#include <stdlib.h>

void clickMouse(int _d)
{
	// 1 -> left 3 -> right
	char* instruction = "xdotool click ";
	char d[2] = {0, 0};
	char inst[30] = {0, };

	d[0] = _d + '0';
	strcat(inst, instruction);
	strcat(inst, d);

	system(inst);
}
