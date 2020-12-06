#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/structure.h"



int hauteur_bst(t_Noeud* monNoeud)  
{ 
   if (monNoeud==NULL)  
       return 0; 
   else 
   { 
       /* détermine la hauteur des sous arbres gauche et droit */
       int hauteur_SAG = hauteur_bst(monNoeud->filsGauche); 
       int hauteur_SAD = hauteur_bst(monNoeud->filsDroit); 
  
       /* on retourne le plus grand */
       if (hauteur_SAG > hauteur_SAD)
       {
            return(hauteur_SAG+1); 
       }  
       else
       {
            return(hauteur_SAD+1); 
       } 
   } 
}


int est_Equilibre(t_Noeud* racine) 
{ 
    int hauteur_SAG;
    int hauteur_SAD;
  
    /* si l'arbre est vide */
    if (racine == NULL) 
        return 1; 
  
    /* obtenir la hauteur des sous arbre gauhce et droit */
    hauteur_SAG = hauteur_bst(racine->filsGauche); 
    hauteur_SAD = hauteur_bst(racine->filsDroit); 
  
    if (abs(hauteur_SAD - hauteur_SAG) <= 1 && est_Equilibre(racine->filsGauche) && est_Equilibre(racine->filsDroit))
    {
        return 1; 
    } 
  

    return 0; // alors l'arbre n'est pas équilibré
} 
