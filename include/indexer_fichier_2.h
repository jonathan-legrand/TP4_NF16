#ifndef  indexer_fichier_bis_H
#define  indexer_fichier_bis_H
#include "structure.h"

p_Noeud* creer_noeud_phrase();
p_Noeud* ajouterNoeudPhrase(listeNoeudPhrase* listePhrases, int num_phrase,char *phrase);
int indexer_fichier_bis(listeNoeudPhrase* listePhrases, char *filename);

void affichage_Noeud(listeNoeudPhrase listePhrases);

#endif 