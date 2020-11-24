#include <stdio.h>
#include <stdlib.h>

typedef t_position t_Position;

typedef struct t_position
{
    int numero_ligne;
    int ordre;
    int numero_phrase;
    t_Position* suivant;
}t_position;

typedef t_listePositions t_ListePositions;

typedef struct t_listePositions
{
    t_Position* debut;
    int nb_elements;
}t_listePositions;

typedef t_noeud t_Noeud;

typedef struct t_noeud
{
    char* mot;
    int nb_occurences;
    t_ListePositions positions;
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

