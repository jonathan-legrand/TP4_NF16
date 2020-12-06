#include "../include/ajouter_noeud.h"
#include "../include/chaines.h"
#include "../include/creer_liste_positions.h"
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

t_Noeud* creer_noeud()
{
    t_Noeud* new_noeud = malloc(sizeof(t_Noeud));
    new_noeud->positions = creer_liste_positions();
    printf("adresse liste de positions (dans creer_noeud) : %p\n",new_noeud->positions);
    
    new_noeud->filsGauche=NULL;
    new_noeud->filsDroit=NULL;
    new_noeud->nb_occurences=0;
    new_noeud->mot=NULL;
    return new_noeud;
}



//FIXME Faut - il modifier la racine ou pas ?
t_Noeud *rechercher_noeud(t_Index *index, t_Noeud *noeud)
{
    char *nouvChaine = malloc(sizeof(0));
    char *nouvChaine2 = malloc(sizeof(0));
    t_Noeud *noeudEnCours = index->racine;
    printf("\nla racine : %s",index->racine->mot);
    if (index->racine->filsDroit!=NULL)
        printf("\nle fils droit est %s\n",index->racine->filsDroit->mot);
    //char *motEnCours=NULL; Non utilisé
    int cmpChar;
    //printf("\ncoucou4"); // TODO Supprimer
    while(noeudEnCours != NULL){
        //printf("\ncoucou5"); // TODO Supprimer
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
            //printf("\nfils droit non null\n");
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
t_Noeud* ajouter_noeud ( t_Index *index, t_Noeud *noeud) 
{
    //t_Noeud* noeudTmp = noeud; // FIXME à modifier comme avant avec juste noeud
    //printf("\ncoucou1\n"); // TODO Supprimer
    if (index == NULL){
        printf("Erreur : l'index fourni en paramètre n'existe pas\n");
        return NULL;
    }
    // Cas lorsque la racine est vide, on ajoute le noeud à la racine
    if(index->racine==NULL)
    {
        //printf("\ncoucou2\n"); // TODO Supprimer
        //index->racine->mot=malloc(strlen(noeud->mot));
        /*index->racine=noeud;
          strcpy(index->racine->mot,noeud->mot);*/
        index->racine=creer_noeud();
        // it's a deep copy
        memcpy (index->racine, noeud, sizeof (*(index->racine)));
        index->racine->mot = strdup (noeud->mot);
        printf("adresse liste de positions (dans ajouter_noeud cas racine) : %p\n",index->racine->positions); //TODO Ça vient de là le problème, à mon avis, la liste de positions vaut nil à cet endroit là
        printf("test ajout racine : mot = %s\n",index->racine->mot);
        return index->racine;
    }

    else{
        //printf("\n La valeur de la racine est %s\n",index->racine->mot);  TODO Supprimer
        //printf("\ncoucou3\n"); TODO Supprimer
        t_noeud *noeudPrecedent =creer_noeud();
        noeudPrecedent = rechercher_noeud(index,noeud);
        //noeudPrecedent->filsDroit=malloc(sizeof(t_Noeud));
        //noeudPrecedent->filsGauche=malloc(sizeof(t_Noeud));


        if (noeudPrecedent == NULL){ // si c'est null ça veut dire que le mot existe deja confirmation ???
            printf("Erreur lors de l'ajout du noeud\n");
            // TODO ici pour moi il faut faire appel à la fonction ajouter position car le mot est déjà dans l'arbre
            // TODO en plus du message d'erreur d'ajout on peut dire : "La position du noeud existant a été modifié"
            return NULL;
        }
        if(strcmp(noeud->mot,noeudPrecedent->mot)>0){  // FIXME tolower
            // noeudPrecedent->mot est lexicalement plus grand que mot
            //noeudPrecedent->filsDroit = noeud;
            noeudPrecedent->filsDroit=creer_noeud();
            noeudPrecedent->filsDroit->mot = strdup (noeud->mot);
            printf("\nLe noeud a bien été ajouté\n");
            printf("\nle fils droit qui vient d'être ajouté : %s\n",index->racine->filsDroit->mot);
            return noeudPrecedent->filsDroit;
        }
        else if(strcmp(noeud->mot,noeudPrecedent->mot)<0) {  //FIXME j'ai inversé demander confirmation ???
            // noeud->mot est lexicalement plus petit que noeudPrecedent->mot
            printf("\nLe noeud a bien été ajouté");
            //noeudPrecedent->filsGauche = noeud;
            noeudPrecedent->filsGauche=creer_noeud();
            noeudPrecedent->filsGauche->mot = strdup (noeud->mot);
            return noeudPrecedent->filsGauche;
        }
    } // FIXME parenthese ok ?
    return NULL;
}		/* -----  end of function ajouter_noeud  ----- */


