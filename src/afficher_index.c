#include "../include/afficher_index.h"
#include "../include/rechercher_mot.h"

//TODO : mettre à jour le header
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  afficher_arbre
 *  Description:  
 * =====================================================================================
 */
    void
afficher_arbre ( t_Noeud *noeud )
{
    if(noeud == NULL){
        return;
    }
    afficher_arbre(noeud->filsGauche);
    printf("%s",noeud->mot);
    afficher_arbre(noeud->filsDroit);
    
}		/* -----  end of function afficher_arbre  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  afficher_index
 *  Description:  
 * =====================================================================================
 */
void afficher_index ( t_Index *index )
{
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
    afficher_arbre(abr);

    
}		/* -----  end of function afficher_index  ----- */
