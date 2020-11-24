#include <stdio.h>
#include <stdlib.h>

typedef struct t_position
{
    int numero_ligne;
    int ordre;
    int numero_phrase;
    t_position* suivant;
}t_position;
