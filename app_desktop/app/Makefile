CC = gcc
CFLAGS = -g -Wall
OUTPUT = libapps.a
AR = ar
OBJFILES = app.o

$(OUTPUT): $(OBJFILES)
	$(AR) rv $(OUTPUT) $(OBJFILES)

app.o : app.c
	$(CC) $(CFLAGS) -c app.c -o app.o -I../include `pkg-config --cflags --libs gtk+-2.0` 


clean:
	rm *.o $(OUTPUT)
