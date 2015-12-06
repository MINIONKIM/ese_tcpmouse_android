libMouseEvent.a : clickMouse.o MoveMouse.o
	ar rv libMouseEvent.a clickMouse.o MoveMouse.o
clickMouse.o : clickMouse.c
	gcc -c -g -I../../include clickMouse.c -o clickMouse.o
MoveMouse.o : MoveMouse.c
	gcc -c -g -I../../include MoveMouse.c -o MoveMouse.o

clean :
	rm -f clickMouse.o MoveMouse.o libMouseEvent.a
