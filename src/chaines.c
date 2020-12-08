#include "../include/chaines.h"

// @batp380 Je sais pas si j'en ai oublié ou pas mais voilà c'est déjà plus propre

char * strtolower( char * destination, char * source ) {
    char *  nouvelleChaine = destination;
    // on crée une liste supplémenatire car on ne peut pas modifier le pointeur de la chaine à retourner
    while( *destination++ = tolower( *source++ ) );
    return nouvelleChaine;
}


