#ne marche pas sur mon windows :(
OBJS = main.o indexer_fichier.o
HEADERS = structure.h indexer_fichier.h

myapplication : $(OBJS)
    gcc -o $@ $(OBJS)

main.o : main.c $(HEADERS)

indexer_fichier.o : structure.h indexer_fichier.h

.c.o :
    gcc -c $<

clean :
    rm -f myapplication *.o