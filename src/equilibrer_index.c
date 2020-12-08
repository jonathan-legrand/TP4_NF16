#include "../include/equilibrer_index.h"
// TODO Mettre à jour les headers
// TODO Vérifier si l'index est déjà équilibré
// FIXME Les caractéristiques du nouvel index
int id = 0;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  afficher_tableau
 *  Description:  
 * =====================================================================================
 */
    void
afficher_tableau ( t_Noeud *noeuds[25], int taille )
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
void stockage_noeuds (t_noeud *noeud, t_Noeud *noeuds[25])
{

    if(noeud == NULL)
        return;
    stockage_noeuds(noeud->filsGauche, noeuds);
    //printf("id = %d mot = %s \t",id++,noeud->mot);
    memcpy(noeuds[id++],noeud,sizeof(t_Noeud)); //TODO affecter pointeur
    stockage_noeuds(noeud->filsDroit, noeuds);



}		


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  creer_abr
 *  Description:  
 * =====================================================================================
 */
t_Noeud *creer_abr ( t_Noeud *noeuds[TAILLE_MAX], int debut, int fin )

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
    //Création du nouvel index 
    t_Index *index_equilibre;
    index_equilibre = creer_index(); 


    //Initialisation du tableau
    //char mot[TAILLE_MAX]; 
    int nombre_noeuds = index->nb_mots_differents;
    printf("%d\n",nombre_noeuds);
    t_Noeud *noeuds[TAILLE_MAX];
    int i = 0;
    for ( i = 0; i < nombre_noeuds; i += 1 ) {
        noeuds[i] = malloc(sizeof(t_Noeud));
    }
    //tableau noeuds = malloc(nombre_noeuds*sizeof(mot));
    //
    
    //for ( int i = 0; i < nombre_noeuds; i += 1 ) strcpy(noeuds[i],"tesmorts");
    //afficher_tableau(noeuds,nombre_noeuds);

    //Stockage des nombres dans le tableau
    stockage_noeuds(index->racine,noeuds);
    afficher_tableau(noeuds,nombre_noeuds);

    t_noeud *abr;
    abr = creer_abr(noeuds,0,nombre_noeuds-1);

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
    

}		/* -----  end of function equilibrer_index  ----- */
