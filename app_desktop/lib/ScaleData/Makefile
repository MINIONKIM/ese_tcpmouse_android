libscaledata.a : scaledata.o
	ar rv libscaledata.a scaledata.o
scaledata.o : scaledata.c
	gcc -c -g -I../../include scaledata.c -o scaledata.o

clean :
	rm -f scaledata.o libscaledata.a
