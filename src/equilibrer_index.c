#include "../include/equilibrer_index.h"
// TODO Mettre à jour les headers
int id = 0;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  afficher_tableau
 *  Description:  
 * =====================================================================================
 */
    void
afficher_tableau ( char mots[25][25], int taille )
{
    
    for ( int i = 0; i < taille; i ++ ) {
        printf("%s\t",mots[i]);
    }
    printf("\n\n");
}		/* -----  end of function afficher_tableau  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  parcours_arbre
 *  Description:  
 * =====================================================================================
 */
void stockage_mots (t_noeud *noeud, char mots[25][25])
{
/*      if(noeud == NULL)
 *           return;
 * 
 *      mots[i] = noeud->mot;
 *      i++;
 *      if(noeud->filsGauche != NULL)
 *           stockage_mots(noeud->filsGauche, mots, i);
 *      if(noeud->filsDroit != NULL)
 *           stockage_mots(noeud->filsDroit, mots, i);
 * 
 */
/*     
 *     strcpy(mots[id],noeud->mot);
 *     id++;
 *     stockage_mots(mots, noeud->filsDroit, id);
 */
    if(noeud == NULL)
        return;
    stockage_mots(noeud->filsGauche, mots);
    //printf("id = %d mot = %s \t",id++,noeud->mot);
    strcpy(mots[id++],noeud->mot);
    stockage_mots(noeud->filsDroit, mots);



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
    printf("%d\n",nombre_mots);
    char mots[25][25];
    //tableau mots = malloc(nombre_mots*sizeof(mot));
    //
    
    //for ( int i = 0; i < nombre_mots; i += 1 ) strcpy(mots[i],"tesmorts");
    //afficher_tableau(mots,nombre_mots);

    //Stockage des nombres dans le tableau
    int i = 0;
    stockage_mots(index->racine,mots);
    afficher_tableau(mots,nombre_mots);
    

    return index_equilibre;
}		/* -----  end of function equilibrer_index  ----- */
