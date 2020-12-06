#include <stdlib.h>
#include <stdio.h>
#include "../include/structure.h"
#include "../include/indexer_fichier.h"
#include "../include/ajouter_noeud.h"
#include "../include/ajouter_position.h"
#include "../include/creer_liste_positions.h"
#include "../include/rechercher_mot.h"
#include "../include/afficher_index.h"



#define CHARGER_FICHIER 1
#define CARACTERISTIQUES 2
#define AFFICHER_INDEX 3
#define RECHERCHER 4
#define AFFICHER_OCCURENCES 5 
#define EQUILIBRER 6
#define QUITTER 7



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int main ( int argc, char *argv[] )

    {

        int choix;
        char nomFichier[20];
        t_Index* monIndex = creer_index(); 
        int nbr_mots;
    
        do {


            /* affichage menu */
            printf("1.Charger fichier\n"
                    "2.Caracteristiques\n"
                    "3.Afficher_index\n"
                    "4.Rechercher\n"
                    "5.Afficher_occurences\n"
                    "6.Equilibrer\n"
                    "7.Quitter\n"
                );

            fflush(stdin);
            printf("\nVotre choix ? ");
            scanf("%d",&choix);
            fflush(stdin);
            /* suppression des caracteres dans stdin */

            switch(choix)
            {
                case CHARGER_FICHIER:
                    printf("Choix 1\n");
                    /*printf ("Nom du fichier : ");
                    fflush(stdin);
                    scanf("%s",nomFichier);*/
                    nbr_mots = indexer_fichier(monIndex, "fichier2.txt");
                    printf("\n\n Voici le nb de mot : %d\n\n",nbr_mots);                     
                    break;
                    

                case CARACTERISTIQUES:
                    printf("Choix 2\n");
                    if(est_Equilibre(monIndex->racine))
                    {
                        printf("\nL'index est équilibré\n");
                    }
                    else
                    {
                        printf("\nL'index n'est pas équilibré\n");
                    }
                    
                    printf("\nVoici les caractéristiques de l'index : \n\n");
                    printf("-Le nombre de mots total est : %d\n",monIndex->nb_mots_total);
                    printf("-Le nombre de mots différents est : %d\n\n",monIndex->nb_mots_differents);
                    break;

                case AFFICHER_INDEX:
                    printf("Choix 3\n");
                    
                    afficher_index(monIndex);
                    
                    break;

                case RECHERCHER:
                    break;

                case AFFICHER_OCCURENCES:
                    break;

                case EQUILIBRER:
                    break;

                case QUITTER:
                    break;

                default:
                    printf("Choix erroné\n\n\n");
            }
        }while (choix != QUITTER); 

        return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

/* Conseil pour la manipulation des chaines de caractères. Les bibliothèques C contiennent plusieurs fonctions qui vous seront utiles lors du TP, vous avez <ctype.h> pour les fonctions sur les caractères et <string.h> pour les chaines de caractères. Avant d'implémenter vos propres traitements sur les chaines de caractères, vérifiez s'il existe des fonctions C qui le font. Ca vous éviteras du travail en plus. Si elles ne sont pas dans ces deux bibliothèques, elle peuvent être dans une autre. Google, stackoverflow et la documentation du langage C sont vos amis https://fr.cppreference.com/w/c Lien vers la documentation C 
*/
