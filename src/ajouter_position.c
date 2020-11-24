#include "../include/ajouter_position.h"
#include <stdio.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ajouter_position
 *  Description:  
 * =====================================================================================
 */

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
        t_Position *nouvellePosition = malloc(sizeof(t_Position));
        nouvellePosition->ligne = ligne;
        nouvellePosition->ordre = ordre;
        nouvellePosition->num_phrase = num_phrase;
        nouvellePosition->suivant=positionEnCours->suivant;
        positionEnCours->suivant = nouvellePosition;
        printf("La position souhaitée a bien été ajoutée");
        return 1;
    }
    
}

