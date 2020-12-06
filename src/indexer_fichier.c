#include "../include/indexer_fichier.h"
#include "../include/ajouter_noeud.h"
#include "../include/ajouter_position.h"
#include "../include/creer_liste_positions.h"
#include "../include/chaines.h"
#include "../include/rechercher_mot.h"


#include <stdio.h>
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
    //index->racine->positions = *creer_liste_positions();
    t_Noeud* noeud_trouve;
    ;
    // TODO association avec noeud -> position ?

    t_Noeud* nouveau_noeud;

    int nbr_mots = 0;
    int num_ligne = 1;
    int num_phrase = 1;
    int ordre = 0;
    char ch;
    int in_word; // flag : si le charactere n'est pas un espace on met le flag à 1
    int nb_char_mot = 0;
    int nbr_mots_different=0;
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
                ordre++;
                //printf("\n%s\n\n",noeud->mot);
                noeud_trouve = rechercher_mot(index,noeud->mot);
                if (noeud_trouve==NULL)
                {
                    nbr_mots_different++;
                    nouveau_noeud = ajouter_noeud(index,noeud);

                    if(nouveau_noeud->positions==NULL){
                        printf("Erreur : c'est vraiment de la merde\n");
                    }

                    ajouter_position(nouveau_noeud->positions,num_ligne,ordre,num_phrase);
                    nouveau_noeud->nb_occurences++;
                }
                else
                {
                    ajouter_position(noeud_trouve->positions,num_ligne,ordre,num_phrase);
                    noeud_trouve->nb_occurences++;
                }


                //free(noeud);
                noeud->mot=malloc(0);
                // TODO à améliorer
                // TODO l'idée serait de free tout le noeud mais pour ce faire il faudrait créer des malloc de noeud à chaque nouveau mot
                // TODO il faudrait aussi modifier l'initialisation au début du programme de noeud et noeud->mot
                // TODO le but est de passer à ajouter tous les caractéristiques du noeud c'est à dire son mot, sa liste de position etc..
                // TODO car l'objectif est que dans la fonction ajouter noued on fasse appel à la fonction ajouter position quand le noeud->mot est le même
                nb_char_mot=0;

            }

            if (ch == '.')
            {
                num_phrase++;
            }
            
            if(ch == '\0' || ch == '\n')
            {
                num_ligne++;
                ordre = 0;
            } 
        
        } 

        else {
            in_word = 1;
        }
    }       

        printf("Le nombre de ligne est %d\n",num_ligne);
        printf("Le nombre de phrases est %d\n",num_phrase);
        
        fclose(fptxt);
    }

    index->nb_mots_differents = nbr_mots_different;
    index->nb_mots_total = nbr_mots;
    
    return nbr_mots;
}

 
