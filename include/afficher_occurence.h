#ifndef  afficher_occurence_H
#define  afficher_occurence_H
#include "structure.h"

p_Noeud* creer_noeud_phrase();
p_Noeud* ajouterNoeudPhrase(listeNoeudPhrase* listePhrases, int num_phrase,char *phrase);
int indexer_fichier_bis(listeNoeudPhrase* listePhrases, char *filename);
void affichage_Noeud(listeNoeudPhrase listePhrases);
int updatePosition (t_Noeud *noeud, listeNoeudPhrase listePhrase);
void afficher_occurences_mot(t_Index *index, char *mot);

#endif 