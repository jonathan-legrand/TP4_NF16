#include <stdlib.h>
#include <stdio.h>
#include "../include/structure.h"
#include "../include/indexer_fichier.h"
#include "../include/ajouter_noeud.h"
#include "../include/ajouter_position.h"
#include "../include/creer_liste_positions.h"
#include "../include/rechercher_mot.h"
#include "../include/afficher_index.h"
#include "../include/verifier_equilibre.h"
#include "../include/rechercher_mot.h"
#include "../include/chaines.h"
#include "../include/equilibrer_index.h"
#include "../include/afficher_occurence.h"



#define CHARGER_FICHIER 1
#define CARACTERISTIQUES 2
#define AFFICHER_INDEX 3
#define RECHERCHER 4
#define AFFICHER_OCCURENCES 5 
#define EQUILIBRER 6
#define QUITTER 7
#define TAILLE_MAX 25



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int main ( int argc, char *argv[] )

    {

        int choix;
        char nomFichier[TAILLE_MAX];
        t_Index* monIndex = creer_index(); 
        int nbr_mots;
        listeNoeudPhrase maListePhrases;

        //Déclarations case rechercher
        char mot_recherche[TAILLE_MAX];
        t_Noeud *noeud_recherche;

        //Déclarations case équilibrer

    
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
                    printf ("Nom du fichier : ");
                    fflush(stdin);
                    scanf("%s",nomFichier);
                    nbr_mots = indexer_fichier(monIndex, nomFichier);
                    printf("\n\n Voici le nb de mot : %d\n\n",nbr_mots);                     
                    break;
                    

                case CARACTERISTIQUES:
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
                    
                    afficher_index(monIndex);
                    
                    break;

                case RECHERCHER:
                    printf("Entrez le mot à rechercher : ");
                    scanf("%s",mot_recherche);
                    noeud_recherche = rechercher_mot(monIndex,mot_recherche);
                    if (noeud_recherche == NULL){
                        printf("Le mot n'est pas présent dans l'index\n\n");
                    } else {
                        afficher_noeud(noeud_recherche,toupper(mot_recherche[0]));          
                    }
                    break;

                case AFFICHER_OCCURENCES:
                    printf("\nNous sommes navrés de vous annoncer que nous n'avons pas réussi à implémenter cette fonction correctement.\n"
                    "Nous vous invitons à regarder le fichier afficher_occurence.c qui rassemble \nl'ensemble des fonctions que nous avons implémentées.\n");
                    printf("Le test suivant va malheureusement renvoyer des phrases null.\n\n");
                    indexer_fichier_bis(&maListePhrases, "fichier_equilibre.txt");
                    updatePosition (monIndex->racine, maListePhrases);
                    strcpy(mot_recherche,""); // si l'utilisateur à fait un case RECHERCHER avant
                    printf("Entrez le mot à rechercher : ");
                    scanf("%s",mot_recherche);
                    afficher_occurences_mot(monIndex, mot_recherche);
                    printf("\n");
                    break;

                case EQUILIBRER:
                        monIndex = equilibrer_index(monIndex);
                    break;

                case QUITTER:
                    free(monIndex);
                    break;

                default:
                    printf("Choix erroné\n\n\n");
            }
        }while (choix != QUITTER); 

        return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */




