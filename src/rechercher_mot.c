#include "../include/rechercher_mot.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>



char * strtolower( char * destination, char * source ) {
    char *  nouvelleChaine = destination;
    // on crée une liste supplémenatire car on ne peut pas modifier le pointeur de la chaine à retourner
    while( *destination++ = tolower( *source++ ) );
    return nouvelleChaine;
}


/**
 * @brief Rechercher un mot dans un index. 
 * Index est un ABR. 
 * Donc il faut appliquer l'algorithme connu de recherche dans un ABR.
 * @param mot le mot recherché
 * @return Renvoie, si le mot existe, le noeud correspondant, sinon renvoie NULL
*/

t_Noeud* rechercher_mot(t_Index *index, char *mot){
    t_Noeud* noeudEnCours = index->racine;
    char *nouvChaine = malloc(sizeof(0));
    char *nouvChaine2 = malloc(sizeof(0));
    int OK = 0;
    int cmpChar;
    while (!OK && noeudEnCours!=NULL)
    {
        cmpChar = strcmp(strtolower(nouvChaine,noeudEnCours->mot),strtolower(nouvChaine2,mot));
        
        if (cmpChar<0) 
        // noeudEnCours->mot est lexicalement plus petit que mot
        {
           noeudEnCours = noeudEnCours->filsGauche;
        }
        else if (cmpChar>0)
        // noeudEnCours->mot est lexicalement plus grand que mot
        {
            noeudEnCours = noeudEnCours->filsDroit;
        }
        else
        {
            OK=1;
        }
    }

    if (OK)
    {
        return noeudEnCours;
    }
    else
    {
        printf("Le noeud n'existe pas");
        return NULL;
    }

}

