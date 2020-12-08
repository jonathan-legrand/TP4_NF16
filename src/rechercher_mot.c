#include "../include/rechercher_mot.h"
#include "../include/chaines.h"
#include <stdio.h>


/**
 * @brief Rechercher un mot dans un index. 
 * Index est un ABR. 
 * Donc il faut appliquer l'algorithme connu de recherche dans un ABR.
 * @param mot le mot recherché
 * @return Renvoie, si le mot existe, le noeud correspondant, sinon renvoie NULL
 */

t_Noeud* rechercher_mot(t_Index *index, char *mot){
    t_Noeud* noeudEnCours = index->racine;
    char nouvChaine[25];
    char nouvChaine2[25];
    int cmpChar;
    while (noeudEnCours!=NULL)
    {
        cmpChar = strcmp(strtolower(nouvChaine,noeudEnCours->mot),strtolower(nouvChaine2,mot));

        if (cmpChar<0) 
            // noeudEnCours->mot est lexicalement plus petit que mot
        {
            noeudEnCours = noeudEnCours->filsDroit; 
        }
        else if (cmpChar>0)
            // noeudEnCours->mot est lexicalement plus grand que mot
        {
            noeudEnCours = noeudEnCours->filsGauche;
        }
        else
        {
            return noeudEnCours;
        }
    }
    printf("Le noeud n'existe pas\n");
    return NULL;

}

