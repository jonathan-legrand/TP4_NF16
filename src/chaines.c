#include "../include/chaines.h"


char * strtolower( char * destination, char * source ) {
    char *  nouvelleChaine = destination;
    // on crée une liste supplémenatire car on ne peut pas modifier le pointeur de la chaine à retourner
    while( *destination++ = tolower( *source++ ) );
    return nouvelleChaine;
}


