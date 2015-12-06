libscaledata.a : scaledata.c
	ar rv libscaledata.a scaledata.o
scaledata.o : scaledata.c
	gcc -c -g -I../../include clickMouse.c -o clickMouse.o

clean :
	rm -f scaledata.o libscaledata.a
