#ifndef structure_H

#define structure_H

#include <stdio.h>
#include <stdlib.h>


typedef struct t_position t_Position;

struct t_position
{
    int numero_ligne;
    int ordre;
    int numero_phrase;
    t_Position* suivant;
};


typedef struct t_listePositions
{
    t_Position* debut;
    int nb_elements;
}t_listePositions;

typedef t_listePositions t_ListePositions;

typedef struct t_noeud
{
    char* mot;
    int nb_occurences;
    t_ListePositions* positions;
    struct t_noeud* filsGauche;
    struct t_noeud* filsDroit;
}t_noeud;

typedef t_noeud t_Noeud;

typedef struct t_index
{
    t_Noeud* racine;
    int nb_mots_differents;
    int nb_mots_total;
}t_index;

typedef t_index t_Index;




typedef struct p_Mot
{
    char* mot;
    struct p_Mot* suivant;
}p_Mot;

typedef p_Mot* listeMots;

typedef struct p_Noeud
{
    listeMots listemots; //  TODO pointeur
    int numero_phrase;
    struct p_Noeud* suivant;
}p_Noeud;

typedef p_Noeud* listeNoeud;

typedef struct p_Index
{
    p_Noeud* racine;
}p_Index;



#endif
