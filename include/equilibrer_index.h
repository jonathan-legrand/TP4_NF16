#ifndef  equilibrer_index_INC
#define  equilibrer_index_INC
#include "structure.h"
#include "chaines.h"
#include "indexer_fichier.h"
#define TAILLE_MAX 25

typedef char** tableau;
t_Index* equilibrer_index(t_Index *index);
void stockage_mots (tableau mots, t_Noeud *noeud, int id);
#endif   /* ----- #ifndef equilibrer_index_INC  ----- */
