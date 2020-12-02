#include "../include/ajouter_noeud.h"
#include "../include/chaines.h"
#define SUCCES 1

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ajouter_noeud
 *  Description:  
 * =====================================================================================
 */

// TODO A modifier 
/**
 * @brief Crée une liste de positions vide
 * @return Renvoie la liste, si echec renvoie NULL
 */


//FIXME Faut - il modifier la racine ou pas ?
t_Noeud *rechercher_noeud(t_Index *index, t_Noeud *noeud)
{
    char *nouvChaine = malloc(sizeof(0));
    char *nouvChaine2 = malloc(sizeof(0));
    t_Noeud *noeudEnCours = index->racine;
    printf("\nla racine : %s",index->racine->mot);
    char *motEnCours=NULL;
    int cmpChar;
    //printf("\ncoucou4"); // TODO Supprimer
    while(noeudEnCours != NULL){
        printf("\ncoucou5"); // TODO Supprimer
        //strcpy(motEnCours,noeudEnCours->mot); // FIXME ATTENTION REMPALCEMENT bon ou pas ?

        printf("\nLe mot en cours est %s",noeudEnCours->mot); // FIXME à la deuxième itération le mot en cours prend la valeur du noeud à chercher directement
        printf("\nLe mot à chercher est %s",noeud->mot);

        cmpChar = strcmp(strtolower(nouvChaine,noeudEnCours->mot),strtolower(nouvChaine2,noeud->mot));
        //printf("\ncoucou6"); // TODO Supprimer
        if (!cmpChar){
            printf("Le mot est déjà présent dans l'abr, rien n'a été ajouté\n");
            return NULL; 
        }
        else if(cmpChar<0){  //FIXME TOLOWER
            // noeudEnCours->mot est lexicalement plus petit que noeud->mot
            if(noeudEnCours->filsDroit == NULL){
                printf("\nfils droit null");
                return(noeudEnCours);
            }
            printf("\nfils droit non null\n");
            printf("Fils droit : %s\n",noeudEnCours->filsDroit->mot);
            noeudEnCours = noeudEnCours->filsDroit;
        } else if(cmpChar>0){
            // noeudEnCours->mot est lexicalement plus grand que noeud->mot
            if(noeudEnCours->filsGauche == NULL){
                printf("\nfils gauche null");
                return(noeudEnCours);
            }
            printf("\nfils gauche non null");
            noeudEnCours = noeudEnCours->filsGauche;
        }
        printf("\n fin itér: Le mot en cours sera %s",noeudEnCours->mot); // FIXME à la deuxième itération le mot en cours prend la valeur du noeud à chercher directement
        printf("\n fin itér: Le mot à chercher est %s",noeud->mot);
        //motEnCours=malloc(0); // FIXME UTILE OU PAS ?
    }
    return noeudEnCours;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ajouter_noeud
 *  Description:  
 * =====================================================================================
 */
int ajouter_noeud ( t_Index *index, t_Noeud *noeud) 
{
    //t_Noeud* noeudTmp = noeud; // FIXME à modifier comme avant avec juste noeud
    printf("\ncoucou1\n"); // TODO Supprimer
    if (index == NULL){
        printf("Erreur : l'index fourni en paramètre n'existe pas\n");
        return !SUCCES;
    }
    // Cas lorsque la racine est vide, le noeud ajouté devient la racine
    if(index->racine==NULL)
    {
        printf("\ncoucou2\n"); // TODO Supprimer
        //index->racine->mot=malloc(strlen(noeud->mot));
        /*index->racine=noeud;
          strcpy(index->racine->mot,noeud->mot);*/
        index->racine=malloc(sizeof(t_Noeud));
        // it's a deep copy
        memcpy (index->racine, noeud, sizeof (*(index->racine)));
        index->racine->mot = strdup (noeud->mot);

        return SUCCES;
    }

    else
        printf("\n La valeur de la racine est %s\n",index->racine->mot); // TODO Supprimer
    printf("\ncoucou3\n"); // TODO Supprimer
    t_Noeud *noeudPrecedent = rechercher_noeud(index,noeud);

    if (noeudPrecedent == NULL){
        printf("Erreur lors de l'ajout du noeud\n");
        return !SUCCES;
    }
    if(strcmp(noeud->mot,noeudPrecedent->mot)>0){  //FIXME j'ai inversé demander confirmation ???
        // noeudPrecedent->mot est lexicalement plus grand que mot
        noeudPrecedent->filsDroit = noeud;
        printf("\nLe noeud a bien été ajouté");
        return SUCCES;
    }
    else if(strcmp(noeud->mot,noeudPrecedent->mot)<0) {  //FIXME j'ai inversé demander confirmation ???
        // noeud->mot est lexicalement plus petit que noeudPrecedent->mot
        printf("\nLe noeud a bien été ajouté");
        noeudPrecedent->filsGauche = noeud;
        return SUCCES;
    }
}		/* -----  end of function ajouter_noeud  ----- */


