#include "../include/TP4.h"
#include <stdio.h>

int ajouter_position(t_ListePositions *listeP, int ligne, int ordre, int num_phrase){
    t_ListePositions *positionEnCours = listeP;
    
    while (ligne>=positionEnCours->ligne)
    {
        positionEnCours=positionEnCours->suivant;
    }
    while (ordre>=positionEnCours->ordre)
    {
        positionEnCours=positionEnCours->suivant;
    }
    while (num_phrase>=positionEnCours)
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
        printf("La position souhaitée a bien été ajoutée");
        return 1;
    }
    
}