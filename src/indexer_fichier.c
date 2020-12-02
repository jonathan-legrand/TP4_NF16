//FIXME Problème de linker
#include "../include/indexer_fichier.h"
#include "../include/ajouter_noeud.h"
#include "../include/ajouter_position.h"
#include "../include/creer_liste_positions.h"

#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 1000

/**
 * @brief Indexer un fichier texte.
 * Cette fonction lit le fichier et ajoute tous les mots qu’il contient dans un index. 
 * @param filename le nom d'un fichier importé.
 * @return Revoie le nombre de mots lus
 */

t_Index* creer_index(){
    t_Index* mon_nouveau_index = malloc(sizeof(t_Index));
    if (!mon_nouveau_index)
    {
        return NULL;
    }
    
    // mon_nouveau_index->racine=malloc(sizeof(t_Noeud)); // FIXME DOUTE
    mon_nouveau_index->racine = NULL; // FIXME DOUTE
    mon_nouveau_index->nb_mots_differents=0;
    mon_nouveau_index->nb_mots_total=0;
    return mon_nouveau_index;
}

int indexer_fichier(t_Index *index, char *filename)
{
    
    //index->racine->mot=malloc(sizeof(0));
    t_Noeud* noeud=malloc(sizeof(t_Noeud));
    noeud->mot= malloc(sizeof(0));
    //t_ListePositions* maListePositions = creer_liste_positions();
    // TODO association avec noeud -> position ?

    char ligne[TAILLE_MAX];
    const char * separateurs = "\n .";
    char * strToken;
    int ajout_noeud;

    int nbr_mots = 0;
    int num_ligne = 0;
    //int num_phrase = 0; non utilisé
    int ordre = 0;

    FILE *fptxt;
    fptxt=fopen(filename,"r");

    if (fptxt==NULL)
    {
        printf("erreur lecture fichier");
    }
    else
    {
        while (fgets(ligne,TAILLE_MAX,fptxt)!=NULL){
            //printf("\nLigne\n\n"); //TODO Supprimer
            strToken = strtok (ligne,separateurs);
            num_ligne++;
            //TODO update le num_phrase (complexe vu que je supprime les points...)
            
            while (strToken != NULL) {
                /*if (index->racine!=NULL)
                {
                    printf("\nLa racine3 est %s\n",index->racine->mot); //TODO Supprimer
                }*/
                //noeud->mot = malloc(0); // libération
                if (index->racine!=NULL && index->racine->filsDroit!=NULL)
                    printf("je suis dans index avant le strcpy, le mot ajouté précédement : %s\n",index->racine->filsDroit->mot);
                
                strcpy(noeud->mot,strToken); // FIXME Le fait de modifier le noeud-> mot cela modifie l'indexe racine.
                //printf("Le mot lu est %s\n",noeud->mot);  //TODO Supprimer

                ordre ++;

                /*if (index->racine!=NULL)
                {
                    printf("\nLa racine est de mon arbre est %s\n",index->racine->mot); //TODO Supprimer

                }*/
                 if (index->racine!=NULL && index->racine->filsDroit!=NULL)
                    printf("je suis dans index après le strcpy le mot ajouté précédement : %s\n",index->racine->filsDroit->mot);
                

                
                ajout_noeud = ajouter_noeud(index,noeud);
               
                //printf("\nLa racine est %s\n",index->racine->mot); //TODO Supprimer

                /*if (!ajout_noeud) //FIXME je ne veux gérer que le cas correspondant au noeud deja "existant"
                {
                    ajouter_position(maListePositions,num_ligne,ordre,num_phrase);
                }*/
                nbr_mots++;
                //printf("%s\n",strToken);  //TODO Supprimer
                //printf("\nLa racine0 est %s\n",index->racine->mot); //TODO Supprimer
                //noeud->mot = malloc(0); // FIXME Problème modifie la racine
                // On demande le token suivant.
                //printf("\nLa racine1 est %s\n",index->racine->mot); //TODO Supprimer
                strToken = strtok ( NULL, separateurs );
                //printf("\nLa racine2 est %s\n",index->racine->mot); //TODO Supprimer

            }
            ordre = 0;
        }

        fclose(fptxt);
    }

    return nbr_mots;
}
// 
// int main(){
// 
//    char nomFichier[100];
//    int nbr_mots;
//    t_Index* monIndex = malloc(sizeof(t_Index));
//    //t_Noeud* monNoeud = malloc(sizeof(t_Noeud));
//     nbr_mots = indexer_fichier(monIndex, "test.txt");
//     printf("\n\n Voici le nb de mot : %d\n\n",nbr_mots); 
//     return 0;
// }
// 
//gcc indexer_fichier.c -o indexer_fichier
//./indexer_fichier
 
