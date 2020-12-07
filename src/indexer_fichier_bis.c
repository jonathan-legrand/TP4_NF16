#include "../include/indexer_fichier_bis.h"
#include "../include/ajouter_noeud.h"
#include "../include/ajouter_position.h"
#include "../include/creer_liste_positions.h"
#include "../include/chaines.h"
#include "../include/rechercher_mot.h"

// TODO l'idée est de créer un arbre uniquement en fonctions du numero de phrase. On va obtenir un arbre full droit
// TODO il faut créer une fonction de recherche qui prend on entrée le numero de la phrase
// TODO pour moi pas besoin de creer finalement in autre index genre on creer une liste qui s'appelle listephrase qui contient les mots de chaque phrase
// TODO occurence prend index en pointeur
#include <stdio.h>
#define TAILLE_MAX 1000

/**
 * @brief Indexer un fichier texte.
 * Cette fonction lit le fichier et ajoute tous les mots qu’il contient dans un index. 
 * @param filename le nom d'un fichier importé.
 * @return Revoie le nombre de mots lus
 */

p_Index* creer_index_bis(){
    p_Index* mon_nouveau_index = malloc(sizeof(p_Index));
    if (!mon_nouveau_index)
    {
        return NULL;
    }
    
    mon_nouveau_index->racine = NULL;
    
    return mon_nouveau_index;
}

p_Noeud* creer_noeud_bis(){
    p_Noeud* mon_nouveau_noeud_phrase = malloc(sizeof(p_Noeud));
    if (!mon_nouveau_noeud_phrase)
    {
        return NULL;
    }
    
    mon_nouveau_noeud_phrase->listemots = creer_mot();
    mon_nouveau_noeud_phrase->numero_phrase = 0;
    mon_nouveau_noeud_phrase->suivant = NULL;
    
    return mon_nouveau_noeud_phrase;
}

p_Mot* creer_mot(){
    p_Mot* mon_nouveau_mot = malloc(sizeof(p_Mot));
    if (!mon_nouveau_mot)
    {
        return NULL;
    }
    
    mon_nouveau_mot->mot = malloc(sizeof(0));
    mon_nouveau_mot->suivant = NULL;

    return mon_nouveau_mot;
}

p_Mot* ajouterMots(listeMots* liste_de_mots, char* mot){
    p_Mot* nouveau_mot_phrase;
    nouveau_mot_phrase=malloc(sizeof(p_Mot));
            //printf("test1\n");

    if (nouveau_mot_phrase!=NULL)
    {
        //printf("test2\n");

        nouveau_mot_phrase->mot = strdup (mot);
        //printf("\nmot ajouté : %s\n",nouveau_mot_phrase->mot);
        nouveau_mot_phrase->suivant = liste_de_mots;
        liste_de_mots=nouveau_mot_phrase;
                //printf("test3\n");

        return nouveau_mot_phrase;
    }
    else
    {
        return NULL;
    }
}

p_Noeud* ajouterNoeuds (listeNoeud* listenoeud, char *filename)
{
    
    //p_Noeud* noeud_phrase = creer_noeud_bis();
    //index->racine = creer_noeud_bis();
    //p_Noeud *abr = index->racine;

    p_Noeud* nouveau_noeud;
    nouveau_noeud=creer_noeud_bis();

    char *mot_phrase = malloc(sizeof(0));
    int num_ligne = 1;
    int num_phrase = 1;
    int ordre = 0;
    char ch;
    int in_word; // flag : si le charactere n'est pas un espace on met le flag à 1
    int nb_char_mot = 0;
    FILE *fptxt;
    fptxt=fopen(filename,"r");

    if (fptxt==NULL)
    {
        printf("erreur lecture fichier");
    }
    else
    {
        while ((ch = fgetc(fptxt)) != EOF) {
        
        if (isalnum(ch))
        {   
            //printf("Carac : %c\n",ch);
            *(mot_phrase + nb_char_mot)=ch;
            nb_char_mot++;
        }
        
        
        if(ch == ' ' || ch == '\0' || ch == '\n'|| ch=='.') {

            if (in_word) {

                in_word = 0;
                printf("%s\n",mot_phrase);

                ajouterMots(&(nouveau_noeud->listemots),mot_phrase);
                printf("\nle mot ajoutée dans index est : %s\n\n",nouveau_noeud->listemots->mot);
                mot_phrase=malloc(0);
                        //printf("test4\n");
                nb_char_mot=0;
                

            }

            if (ch == '.')
            {
                nouveau_noeud->numero_phrase=num_phrase;
                num_phrase++;
                        //printf("test5\n");

                //nouveau_noeud->suivant=creer_noeud_bis();
                nouveau_noeud->suivant = listenoeud;
                listenoeud=nouveau_noeud;
                free(nouveau_noeud);
                nouveau_noeud=creer_noeud_bis();

            }
            
            if(ch == '\0' || ch == '\n')
            {
                num_ligne++;
                // TODO A rajouter
            } 
        
        } 

        else {
            in_word = 1;
        }
    }       

        fclose(fptxt);
    }

    
    return nouveau_noeud;

}

 
/*afficher_index_bis(p_Index *index)
{
    p_Noeud *abr = index->racine;
    p_Mot* motEnCours = index->racine->listemots;
    while (abr!=NULL)
    {
        printf("Voici la phrase %d : \n\n",abr->numero_phrase);
        while (motEnCours!=NULL)
        {
            printf("%s\n",motEnCours->mot);
            motEnCours=motEnCours->suivant;
        }
        abr=abr->filsDroit;
        
    }
    
}*/

void affichage_Noeud(listeNoeud listenoeud){
    
   p_Noeud* noeudEnCours;
   p_Mot* liste_de_mots = NULL;
   noeudEnCours = listenoeud;
   while (listenoeud->suivant!=NULL)
   {
       printf("Phrase %d : \n\n",noeudEnCours->numero_phrase);
       liste_de_mots = noeudEnCours->listemots;
       printf("Liste des mots : \n\n");
       while (liste_de_mots->suivant!=NULL) 
       {
           printf("%s\n",liste_de_mots->mot);
           liste_de_mots=liste_de_mots->suivant;
           printf("\n");
       }
       noeudEnCours=noeudEnCours->suivant;
       printf("\n");
   }
    
    //return provided_affichage_Patients(listePatients);
}