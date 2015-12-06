CC = gcc
CFLAGS = -g -Wall -I../include -L../lib/miscfuncs -L../lib/MouseEvent
GTKFLAGS = -export-dynamic `pkg-config --cflags --libs gtk+-2.0` 
OUTPUT = app

app : app.c
	$(CC) $(CFLAGS) app.c -o app -lmiscfunc -lMouseEvent $(GTKFLAGS)
clean:
	rm $(OUTPUT)
