#include "../include/ajouter_position.h"
#include <stdio.h>

/**
 * @brief Ajouter un élément dans une liste de positions triées. 
 * Les positions d’une liste doivent être uniques et ordonnées dans l’ordre croissant du numéro de ligne et de l’ordre du mot dans la ligne.
 * @param listeP une liste de positions
 * @param ligne un numero de ligne
 * @param ordre un numero indiquant la position dans une ligne
 * @param num_phrase un numero de phrase
 * @return Renvoie 1 en cas de succès, 0 sinon.
*/

t_Position* creer_position()
{
    t_Position* new_position = malloc(sizeof(t_Position));
    new_position->numero_ligne = 0;
    new_position->numero_phrase = 0;
    new_position->ordre = 0;
    new_position->suivant=NULL; 
    return new_position;
}

int ajouter_position(t_ListePositions *listeP, int ligne, int ordre, int num_phrase){

    if(listeP==NULL){
        printf("Erreur : la liste n'existe pas\n");
    }
    t_Position* positionEnCours = creer_position();
    positionEnCours = listeP->debut;

    if (listeP->debut!=NULL)
    {          
            while (positionEnCours->suivant!=NULL && positionEnCours->numero_ligne < ligne)
            {
                positionEnCours=positionEnCours->suivant;
            }

            while (positionEnCours->suivant!=NULL && positionEnCours->ordre < ordre)
            {
                positionEnCours=positionEnCours->suivant;
            }


            while (positionEnCours->suivant!=NULL && positionEnCours->numero_phrase < num_phrase) 
            {
                positionEnCours=positionEnCours->suivant;

            }
    }


    if (listeP->debut == NULL || (ligne!=positionEnCours->numero_ligne) || (ordre!=positionEnCours->ordre) || (num_phrase!=positionEnCours->numero_phrase))


    {

        t_Position *nouvellePosition = creer_position();
        nouvellePosition->numero_ligne = ligne;
        nouvellePosition->ordre = ordre;
        nouvellePosition->numero_phrase = num_phrase;

        if (listeP->debut == NULL)
        {
            listeP->debut = nouvellePosition;
            nouvellePosition->suivant = NULL;

        }

        else
        {
            nouvellePosition->suivant=positionEnCours->suivant;
            positionEnCours->suivant = nouvellePosition;
        }

        listeP->nb_elements++;
        return 1;

    }

    else
    {
        return 0;
    }


}
