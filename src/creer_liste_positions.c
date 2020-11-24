#include "../include/TP4.h"
#include <stdio.h>

t_ListePositions* creer_liste_postions(){
    t_ListePositions* myListePositions = malloc(sizeof(t_ListePositions));
    if (!myListePositions)
    {
        return NULL;
    }
    
    myListePositions->debut=NULL;
    myListePositions->nb_elements=0;
    return myListePositions;
}