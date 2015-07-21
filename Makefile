CC = gcc

INCLUDE = {./,./src}
CFLAGS = -g -c -Wall -I$(INCLUDE) -std=c99 -Werror 
OBJLIBS = Network.o Threads.o Client.o Server.o Interface.o
LDFLAGS = -pthread -lncurses
EXE = tschat
SRC_DIR = ./src
# I have no idea how makefiles work...

all: clean $(EXE) 

$(EXE): tschat.o $(OBJLIBS)
	$(CC) -o $(EXE) tschat.o $(OBJLIBS) $(LDFLAGS) 

tschat.o:
	$(CC) $(CFLAGS) tschat.c 

Network.o:
	$(CC) $(CFLAGS) $(SRC_DIR)/Network/Network.c

Threads.o:
	$(CC) $(CFLAGS) $(SRC_DIR)/Threads/Threads.c

Client.o:
	$(CC) $(CFLAGS) $(SRC_DIR)/Client/Client.c

Server.o:
	$(CC) $(CFLAGS) $(SRC_DIR)/Server/Server.c

Interface.o:
	$(CC) $(CFLAGS) $(SRC_DIR)/Interface/Interface.c

clean:
	-rm *.o 
