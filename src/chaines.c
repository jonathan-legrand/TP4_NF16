#include "../include/chaines.h"

// @batp380 Je sais pas si j'en ai oublié ou pas mais voilà c'est déjà plus propre
char *str_sub (const char *s, unsigned int start, unsigned int end)
{
    char *new_s = NULL;
    if (s != NULL && start < end)
    {
        /* (1)*/
        new_s = malloc (sizeof (*new_s) * (end - start + 2));
        if (new_s != NULL)
        {
            int i;

            /* (2) */
            for (i = start; i <= end; i++)
            {
                /* (3) */
                new_s[i-start] = s[i];
            }
            new_s[i-start] = '\0';
        }
        else
        {
            fprintf (stderr, "Memoire insuffisante\n");
            exit (EXIT_FAILURE);
        }
    }
    return new_s;
}


char * strtolower( char * destination, char * source ) {
    char *  nouvelleChaine = destination;
    // on crée une liste supplémenatire car on ne peut pas modifier le pointeur de la chaine à retourner
    while( *destination++ = tolower( *source++ ) );
    return nouvelleChaine;
}


