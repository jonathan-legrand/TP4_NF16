#include <stdio.h>
#include "../include/creer_liste_positions.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  creer_liste_positions
 *  Description:  
 * =====================================================================================
 */

t_ListePositions* creer_liste_positions(){
    t_ListePositions* myListePositions = malloc(sizeof(t_ListePositions));
    if (!myListePositions)
    {
        return NULL;
    }
    
    myListePositions->debut=NULL;
    myListePositions->nb_elements=0;
    return myListePositions;
}