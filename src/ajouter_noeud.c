#include "../include/ajouter_noeud.h"
#include "../include/chaines.h"
#include "../include/creer_liste_positions.h"
#define SUCCES 1

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  creer_noeud
 *  Description:  
 * =====================================================================================
 */



t_Noeud* creer_noeud()
{
    t_Noeud* new_noeud = malloc(sizeof(t_Noeud));
    new_noeud->positions = creer_liste_positions();
    
    new_noeud->filsGauche=NULL;
    new_noeud->filsDroit=NULL;
    new_noeud->nb_occurences=0;
    new_noeud->mot=NULL;
    return new_noeud;
}



t_Noeud *rechercher_noeud(t_Index *index, t_Noeud *noeud)
{
    char *nouvChaine = malloc(sizeof(0));
    char *nouvChaine2 = malloc(sizeof(0));
    t_Noeud *noeudEnCours = index->racine;
    int cmpChar;
    while(noeudEnCours != NULL){


        cmpChar = strcmp(strtolower(nouvChaine,noeudEnCours->mot),strtolower(nouvChaine2,noeud->mot));
        if (!cmpChar){
            printf("Le mot est déjà présent dans l'abr, rien n'a été ajouté\n");
            return NULL; 
        }
        else if(cmpChar<0){ 
            // noeudEnCours->mot est lexicalement plus petit que noeud->mot
            if(noeudEnCours->filsDroit == NULL){
                return(noeudEnCours);
            }
            noeudEnCours = noeudEnCours->filsDroit;
        } else if(cmpChar>0){
            // noeudEnCours->mot est lexicalement plus grand que noeud->mot
            if(noeudEnCours->filsGauche == NULL){
                return(noeudEnCours);
            }
            noeudEnCours = noeudEnCours->filsGauche;
        }
    }
    return noeudEnCours;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ajouter_noeud
 *  Description:  
 * =====================================================================================
 */
t_Noeud* ajouter_noeud ( t_Index *index, t_Noeud *noeud) 
{
    
    if (index == NULL){
        printf("Erreur : l'index fourni en paramètre n'existe pas\n");
        return NULL;
    }
    // Cas lorsque la racine est vide, on ajoute le noeud à la racine
    if(index->racine==NULL)
    {
        
        index->racine=creer_noeud();
        index->racine->mot = strdup (noeud->mot);
        return index->racine;
    }

    else{
        
        t_noeud *noeudPrecedent =creer_noeud();
        noeudPrecedent = rechercher_noeud(index,noeud);
        

        if (noeudPrecedent == NULL){ 
            printf("Erreur lors de l'ajout du noeud\n");
            return NULL;
        }

        int cmpChar;
        char *nouvChaine = malloc(sizeof(noeudPrecedent->mot));
        char *nouvChaine2 = malloc(sizeof(noeud->mot));
        cmpChar = strcmp(strtolower(nouvChaine,noeudPrecedent->mot),strtolower(nouvChaine2,noeud->mot));
        *(noeud->mot+0)=toupper(*(noeud->mot+0)); // Première lettre en maj ( le 0 est inutile c'est juste pour la compréhension)

        if(cmpChar<0){  
            // noeudPrecedent->mot est lexicalement plus petit que mot
            noeudPrecedent->filsDroit=creer_noeud();
            noeudPrecedent->filsDroit->mot = strdup (noeud->mot);
            return noeudPrecedent->filsDroit;
        }
        else if(cmpChar>0) {  
            // noeudPrecedent->mot est lexicalement plus grand que mot
            noeudPrecedent->filsGauche=creer_noeud();
            noeudPrecedent->filsGauche->mot = strdup (noeud->mot);
            return noeudPrecedent->filsGauche;
        }
    }
    return NULL;
}		/* -----  end of function ajouter_noeud  ----- */


