#include <stdio.h>
#include <stdlib.h>

typedef struct t_position
{
    int numero_ligne;
    int ordre;
    int numero_phrase;
    t_position* suivant;
}t_position;

typedef struct t_listePositions
{
    t_listePositions* debut;
    int nb_elements;
}t_listePositions;

typedef t_noeud t_Noeud;

typedef struct t_noeud
{
    char* mot;
    int nb_occurences;
    t_listePositions positions;
    t_Noeud* filsGauche;
    t_Noeud* filsDroit;
}t_noeud;

typedef t_index t_Index;

typedef struct t_index
{
    t_Noeud* racine;
    int nb_mots_differents;
    int nb_mots_total;
}t_index;

