#ifndef  equilibrer_index_INC
#define  equilibrer_index_INC
#include "structure.h"
#include "chaines.h"
#include "indexer_fichier.h"
#include "afficher_index.h"
#include "ajouter_noeud.h"
#include "verifier_equilibre.h"
void afficher_tableau ( t_noeud **noeuds, int taille );
void stockage_noeuds (t_noeud *noeud, t_Noeud **noeuds);
t_Noeud *creer_abr ( t_Noeud **noeuds, int debut, int fin );
t_Index* equilibrer_index(t_Index *index);
#endif   /* ----- #ifndef equilibrer_index_INC  ----- */
