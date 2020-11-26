HEADERS =  include/*.h
SRC = src/*.c
OBJ = $(SRC:.c=.o)
CC = gcc
EXEC = abr


all: $(EXEC)
	

abr:
	$(CC) $(SRC) -o bin/$@

clean:
	rm -f *.o

mrproper: clean
	rm -f bin/abr

