#include "../include/equilibrer_index.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  afficher_tableau
 *  Description:  
 * =====================================================================================
 */
    void
afficher_tableau ( tableau tableau, int taille )
{
    
    for ( int i = 0; i < taille; i ++ ) {
        printf("%s\t",tableau[i]);
    }
    printf("\n\n");
}		/* -----  end of function afficher_tableau  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  parcours_arbre
 *  Description:  
 * =====================================================================================
 */
void stockage_mots (tableau mots, t_noeud *noeud, int id)
{
    if(noeud == NULL){
        return;
    }

    stockage_mots(mots, noeud->filsGauche, id);
    
    printf("id = %d mot = %s \n",id,noeud->mot);
    strcpy(mots[id],noeud->mot);
    printf("%s ajouté case %d \n\n",mots[id],id);
    id++;
    
    stockage_mots(mots, noeud->filsDroit, id);
    
}		


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  equilibrer_index
 *  Description:  
 * =====================================================================================
 */
t_Index *equilibrer_index (t_Index *index)
{
    //Création du nouvel index 
    t_Index *index_equilibre;
    index_equilibre = creer_index(); 


    //Initialisation du tableau
    //char mot[TAILLE_MAX]; 
    int nombre_mots = index->nb_mots_differents;
    char *mots[nombre_mots];
    //tableau mots = malloc(nombre_mots*sizeof(mot));

    //Stockage des nombres dans le tableau
    stockage_mots(mots,index->racine,0);

    return index_equilibre;
}		/* -----  end of function equilibrer_index  ----- */
