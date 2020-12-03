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
    //index->racine->positions = *creer_liste_positions();

    ;
    // TODO association avec noeud -> position ?

    int ajout_noeud;

    int nbr_mots = 0;
    int num_ligne = 0;
    int num_phrase = 0;
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
            *(noeud->mot + nb_char_mot)=ch;
            nb_char_mot++;
        }
        else
        {
            //printf("Carac non alphanum : %c\n",ch);
        }
        
        if(ch == ' ' || ch == '\0' || ch == '\n'|| ch=='.') {
            
            if (in_word) {

                in_word = 0;
                nbr_mots++;
                //printf("\n%s\n\n",noeud->mot);
                ajout_noeud = ajouter_noeud(index,noeud);
                //free(noeud);
                noeud->mot=malloc(0);
                nb_char_mot=0;

            }

            if (ch == '.') 
                num_phrase++;
            
            if(ch == '\0' || ch == '\n') 
                num_ligne++;
        
        } 

        else {
            in_word = 1;
        }
    }       

        printf("Le nombre de ligne est %d\n",num_ligne);
        printf("Le nombre de phrases est %d\n",num_phrase);
        
        fclose(fptxt);
    }
    
    return nbr_mots;
}

 
