#include "../include/afficher_index.h"
#include "../include/rechercher_mot.h"
#include "../include/chaines.h"

//TODO : mettre à jour le header
//TODO : Rassembler les fonctions pour manipuler les chaines dans un fichier qu'on pourra inclure où on veut

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  afficher_noeud
 *  Description:  
 * =====================================================================================
 */
void
afficher_noeud ( t_Noeud *noeud, char lettre )
{
    char *lettreNoeud; //FIXME Pas testé mais je le sens mal
    strcpy(lettreNoeud,str_sub(noeud->mot,0,1));
    if (*lettreNoeud == lettre){
        printf("|-- %s\n",noeud->mot);
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
    printf("teeeeest");
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
    
    for ( char i = 'a'; i <= 'z'; i ++ ) {
        printf("%c",i);
        parcours_arbre(abr,i);
    }

    
}		/* -----  end of function afficher_index  ----- */
