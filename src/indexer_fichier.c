#include "../include/indexer_fichier.h"
#include <stdio.h>
#define TAILLE_MAX 100

/**
 * @brief Indexer un fichier texte.
 * Cette fonction lit le fichier et ajoute tous les mots qu’il contient dans un index. 
 * Elle renvoie le nombre de mots lus.
 * @param filename le nom d'un fichier importé.
 * @return Revoie le nombre de mots lus
 */

int indexer_fichier(t_Index *index, char *filename)
{
    t_Noeud* noeud = index->racine;
    char ligne[TAILLE_MAX];
    const char * separateurs = " .";
    char * strToken;
    int nbr_mots = 0;
    FILE *fptxt;
    int i=0;
    fptxt=fopen(filename,"r");
    if (fptxt==NULL)
    {
        printf("erreur lecture fichier");
    }
    else
    {
        while (fgets(ligne,TAILLE_MAX,fptxt)!=NULL){
            printf("\nLigne\n\n");
            strToken = strtok (ligne,separateurs);
            
            while ( strToken != NULL ) {

                printf ( "%s\n", strToken );
                nbr_mots++;
                // On demande le token suivant.
                strToken = strtok ( NULL, separateurs );
            }
            
        }
        
    }
    fclose(fptxt);
    return nbr_mots;
}

/* int main(){

    char nomFichier[200];
    t_Index* monIndex = malloc(sizeof(t_Index));
    t_Noeud* monNoeud = malloc(sizeof(t_Noeud));
    indexer_fichier(monIndex, "test.txt");
    return 0;
}
*/
