#include "../include/indexer_fichier.h"
#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 200

/**
 * @brief Indexer un fichier texte.
 * Cette fonction lit le fichier et ajoute tous les mots qu’il contient dans un index. 
 * @param filename le nom d'un fichier importé.
 * @return Revoie le nombre de mots lus
 */

int indexer_fichier(t_Index *index, char *filename)
{
    t_Noeud* noeud=malloc(sizeof(t_Noeud));
    char ligne[TAILLE_MAX];
    const char * separateurs = "\n .";
    char * strToken;
    int nbr_mots = 0;

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
            
            while ( strToken != NULL ) {
                strcpy(noeud->mot,strToken);
                //printf("%s\n",noeud->mot);  //TODO Supprimer

                //ajouter_noeud(index,noeud); 
                
                nbr_mots++;

                // On demande le token suivant.
                strToken = strtok ( NULL, separateurs );
            }
            
        }
        
    }
    fclose(fptxt);
    return nbr_mots;
}

/*  int main(){
 * 
 *     char nomFichier[TAILLE_MAX];
 *     int nbr_mots;
 *     t_Index* monIndex = malloc(sizeof(t_Index));
 *     //t_Noeud* monNoeud = malloc(sizeof(t_Noeud));
 *     nbr_mots = indexer_fichier(monIndex, "test.txt");
 *     printf("\n\n Voici le nb de mot : %d\n\n",nbr_mots); 
 *     return 0;
 * }
 * 
 */
//C'est quoi cet animal?
