#include "../include/ajouter_position.h"
#include <stdio.h>

int ajouter_position(t_ListePositions *listeP, int ligne, int ordre, int num_phrase){

    t_ListePositions *positionEnCours = listeP;
    
    while (positionEnCours->ligne < ligne)
    {
        positionEnCours=positionEnCours->suivant;
    }

    while (positionEnCours->ordre < ordre)
    {
        positionEnCours=positionEnCours->suivant;
    }

    while (positionEnCours < num_phrase)
    {
        positionEnCours=positionEnCours->suivant;

    }

    if ((ligne==positionEnCours->ligne) && (ordre==positionEnCours->ordre) && (num_phrase==positionEnCours))
    {
        printf("La position souhaitée exite déjà");
        return 0;
    }
    else
    {
        //malloc ajout trivial dans une liste cf TP3
        printf("La position souhaitée a bien été ajoutée");
        return 1;
    }
    
}