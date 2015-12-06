CC = gcc
CFLAGS = -g -Wall
OUTPUT = libmiscfunc.a
AR = ar
OBJFILES = _atoi.o _itoa.o cleararr.o parsing.o

$(OUTPUT): $(OBJFILES)
	$(AR) rv $(OUTPUT) $(OBJFILES)

_atoi.o: _atoi.c
	$(CC) $(CFLAGS) -c _atoi.c -o _atoi.o -I../../include

_itoa.o: _itoa.c
	$(CC) $(CFLAGS) -c _itoa.c -o _itoa.o -I../../include

cleararr.o: cleararr.c
	$(CC) $(CFLAGS) -c cleararr.c -o cleararr.o -I../../include

parsing.o: parsing.c
	$(CC) $(CFLAGS) -c parsing.c -o parsing.o -I../../include

clean:
	rm *.o $(OUTPUT)
