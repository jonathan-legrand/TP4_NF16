#include "../include/afficher_index.h"
#include "../include/rechercher_mot.h"
#include "../include/chaines.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  afficher_noeud
 *  Description:  
 * =====================================================================================
 */
    void
afficher_noeud ( t_Noeud *noeud, char lettre )
{
    char lettreMin = lettre + ('a'-'A'); 
    if (tolower(noeud->mot[0]) == lettreMin){
        printf("|-- %s\n",noeud->mot); //On affiche le mot

        if(noeud->positions == NULL){
            printf("Erreur : la liste des positions n'existe pas\n");
            exit(EXIT_FAILURE);
        }
        if(noeud->positions->debut == NULL){
            printf("Erreur : la liste des positions est vide\n");
            exit(EXIT_FAILURE);
        }

        t_Position *position;
        position = noeud->positions->debut;

        do{
            printf("|----(l:%d, o:%d, p:%d)\n",position->numero_ligne,position->ordre,position->numero_phrase);
            position = position->suivant;
        } while(position!=NULL);
        printf("|\n");

    }

}		/* -----  end of function afficher_noeud  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  parcours_arbre
 *  Description:  
 * =====================================================================================
 */
    void
parcours_arbre ( t_Noeud *noeud, char lettre )
{
    if(noeud == NULL){
        return;
    }
    parcours_arbre(noeud->filsGauche, lettre);
    //printf("%s",noeud->mot);
    afficher_noeud(noeud, lettre);
    parcours_arbre(noeud->filsDroit, lettre);
    
}		/* -----  end of function parcours_arbre  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  afficher_index
 *  Description:  
 * =====================================================================================
 */
void afficher_index ( t_Index *index )
{
    printf("teeeeest\n");
    t_Noeud *abr = index->racine;
    if (abr == NULL){
        printf("Erreur : index vide\n");
        exit(EXIT_FAILURE);
    }
/*     for ( int i = 'a'; i <= 'z'; i ++ ) {
 *         printf("%d\n",i);
 * 
 * 
 *     }
 */
    
    for ( char i = 'A'; i <= 'Z'; i ++ ) {
        printf("%c\n",i);
        parcours_arbre(abr,i);
    }

    
}		/* -----  end of function afficher_index  ----- */
