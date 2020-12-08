#include "../include/equilibrer_index.h"
// TODO Mettre à jour les headers
int id = 0;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  afficher_tableau
 *  Description:  
 * =====================================================================================
 */
void afficher_tableau ( t_noeud **noeuds, int taille )
{

    for ( int i = 0; i < taille; i ++ ) {
        //printf("%s\t",noeuds[i]->mot);
        afficher_noeud(noeuds[i],toupper(noeuds[i]->mot[0]));
    }
    printf("\n\n");
}		/* -----  end of function afficher_tableau  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  parcours_arbre
 *  Description:  
 * =====================================================================================
 */
void stockage_noeuds (t_noeud *noeud, t_Noeud **noeuds)
{

    if(noeud == NULL)
        return;
    stockage_noeuds(noeud->filsGauche, noeuds);
    //printf("id = %d mot = %s \t",id++,noeud->mot);
    noeuds[id++] = noeud;
    stockage_noeuds(noeud->filsDroit, noeuds);



}		


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  creer_abr
 *  Description:  
 * =====================================================================================
 */
t_Noeud *creer_abr ( t_Noeud **noeuds, int debut, int fin )

{
    if (debut>fin) return NULL;
    int milieu = (debut+fin)/2;
    //printf("milieu = %d ",milieu);

    t_Noeud *racine = creer_noeud();
    if (racine == NULL){
        printf("Erreur lors de la création de la racine\n");
        exit(EXIT_FAILURE);
    }
    racine->positions = noeuds[milieu]->positions;
    racine->mot = strdup(noeuds[milieu]->mot);
    racine->nb_occurences = noeuds[milieu]->nb_occurences;


    racine->filsGauche = creer_abr(noeuds,debut,milieu-1);
    racine->filsDroit = creer_abr(noeuds,milieu+1,fin);

    return racine;
}		/* -----  end of function creer_abr  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  equilibrer_index
 *  Description:  
 * =====================================================================================
 */
t_Index *equilibrer_index (t_Index *index)
{
    //On vérifie si l'index fourni est déjà équilibré
    if(est_Equilibre(index->racine)){
        printf("L'index fourni est déjà équilibré, rien n'a été fait\n");
        return index;
    }
    


    //Création du nouvel index 
    t_Index *index_equilibre;
    index_equilibre = creer_index(); 


    //Initialisation du tableau de noeuds
    int nombre_noeuds = index->nb_mots_differents;
    printf("%d\n",nombre_noeuds);
    t_Noeud **noeuds = malloc(nombre_noeuds*sizeof(t_Noeud*));
    
    //Stockage des noeuds dans le tableau
    stockage_noeuds(index->racine,noeuds);
    afficher_tableau(noeuds,nombre_noeuds);

    //Création de l'abr équilibré
    printf("Création de l'abr équilibré...");
    t_noeud *abr = NULL;
    abr = creer_abr(noeuds,0,nombre_noeuds-1);
    if(abr == NULL){
        printf("Erreur : l'abr n'a pas été créé\n");
        return NULL;
    }
    printf(" Terminée\n");


    //Libération de la mémoire allouée dynamiquement pour le tableau de noeuds
    free(noeuds);
    

    //On vérifie si l'arbre créé est équilibré
    if(est_Equilibre(abr)){
        index_equilibre->racine = abr;
        index_equilibre->nb_mots_differents = index->nb_mots_differents;
        index_equilibre->nb_mots_total = index->nb_mots_total;
        free(index);
        return index_equilibre;
    } else {
        printf("Erreur : l'arbre créé n'est pas équilibré\n");
        return NULL;
    }
    
    return NULL;

}		/* -----  end of function equilibrer_index  ----- */
