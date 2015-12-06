CC=gcc
PORT=4030

MSG_BEGIN = ------------- BEGIN -------------
MSG_END	= 	-------------- END --------------

all: begin client server end

client:client.c
	$(CC) -o client -DPORT=$(PORT) client.c

begin:
	@echo $(MSG_BEGIN)

end:
	@echo $(MSG_END)

server: server.c
	$(CC) -o server -DPORT=$(PORT) server.c

clean:
	@rm -rf client.o
	@rm -rf client

	@rm -rf server.o
	@rm -rf server
