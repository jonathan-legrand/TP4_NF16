HEADERS =  include/*.h
SRC = src/*.c
OBJ = $(SRC:.c=.o)
CC = gcc
EXEC = abr
CFLAGS=-W -Wall -pedantic


all: $(EXEC)
	

abr: $(HEADERS)
	$(CC) $(SRC) -o bin/$@ $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f bin/abr

debug:	$(HEADERS)
	$(CC) -g $(SRC) -o bin/$@ $(CFLAGS)
 

