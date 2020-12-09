#include "../include/afficher_occurence.h"
#include "../include/chaines.h"
#include "../include/rechercher_mot.h"


#include <stdio.h>
#define TAILLE_MAX 10000


p_Noeud* creer_noeud_phrase(){
    p_Noeud* mon_nouveau_noeud_phrase = malloc(sizeof(p_Noeud));
    if (!mon_nouveau_noeud_phrase)
    {
        return NULL;
    }
    
    mon_nouveau_noeud_phrase->phrase = malloc(sizeof(0));
    mon_nouveau_noeud_phrase->numero_phrase = 0;
    mon_nouveau_noeud_phrase->suivant = NULL;
    
    return mon_nouveau_noeud_phrase;
}


p_Noeud* ajouterNoeudPhrase(listeNoeudPhrase* listePhrases, int num_phrase,char *phrase)
{
    p_Noeud* nouveau_noeud_phrase=creer_noeud_phrase();

    if (nouveau_noeud_phrase!=NULL)
    {
    nouveau_noeud_phrase->numero_phrase=num_phrase;
    nouveau_noeud_phrase->phrase=phrase;
    nouveau_noeud_phrase->suivant = *listePhrases;
    *listePhrases=nouveau_noeud_phrase;
    return nouveau_noeud_phrase;
    }
    else
    {
        return NULL;
    }
    

}


int indexer_fichier_bis(listeNoeudPhrase* listePhrases, char *filename)
{
    char phrase [TAILLE_MAX];
    int num_phrase = 1; // numéro et nombre de phrases
    char ch;
    int nb_char_phrase = 0;

    FILE *fptxt;
    fptxt=fopen(filename,"r");

    if (fptxt==NULL)
    {
        printf("erreur lecture fichier");
    }
    else
    {
        while ((ch = fgetc(fptxt)) != EOF) {
        
        if (isalnum(ch)||ch == ' ' || ch == '\0' || ch == '\n'|| ch=='.')
        {   
            phrase[nb_char_phrase]=ch;
            nb_char_phrase++;
        }
        
        if (ch == '.')
            {
                ajouterNoeudPhrase(listePhrases,num_phrase,phrase);
                num_phrase++;
                strcpy(phrase,""); // on vide la phrase
                nb_char_phrase=0;
            }
        } 

        fclose(fptxt);
    }       
    return num_phrase-1;
}

void affichage_Noeud(listeNoeudPhrase listePhrases){
    
   p_Noeud* phraseEnCours;
   phraseEnCours = listePhrases;
   while (phraseEnCours!=NULL)
   {
       printf("Phrase %d est : %s \n\n",phraseEnCours->numero_phrase,phraseEnCours->phrase);
       phraseEnCours=phraseEnCours->suivant;
       printf("\n");
   }
}

/* 
 * ===  FUNCTION  ===============================================================================
 *         Name:  updatePosition
 *  Description: mise à jour des positions de chaque noeud en remplissant le nouveau champ "phrase"
 * ==============================================================================================
 */

/* A noter qu'à la place de cette fonction, nous aurions pu aussi modifier la position directement à partir de l'indexage du fichier*/
int updatePosition (t_Noeud *noeud, listeNoeudPhrase listePhrase)
{
 
    if(noeud == NULL){
        return 0;
    }
    p_Noeud* phraseEnCours = listePhrase;
    t_Position* positionEnCours = noeud->positions->debut;
    updatePosition(noeud->filsGauche,listePhrase);
    while (positionEnCours!=NULL)
    {
        while (phraseEnCours!=NULL && phraseEnCours->numero_phrase!=noeud->positions->debut->numero_phrase)
        {
            if (phraseEnCours->numero_phrase==noeud->positions->debut->numero_phrase)
            {
                noeud->positions->debut->phrase=strdup(phraseEnCours->phrase);
            }
            phraseEnCours=phraseEnCours->suivant;
        }
    
        positionEnCours=positionEnCours->suivant;
    }
    
    updatePosition(noeud->filsDroit,listePhrase);
    return 1;
}


 void afficher_occurences_mot(t_Index *index, char *mot)
 {
    t_Noeud* noeud_trouve;
    noeud_trouve = rechercher_mot(index,mot);
    t_Position* positionEnCours = noeud_trouve->positions->debut;
    printf("Mot = %s\n",noeud_trouve->mot);
    printf("Occurences = %d\n",noeud_trouve->nb_occurences);
    while (positionEnCours!=NULL)
    {
        printf("| Ligne %d, mot %d : %s\n",positionEnCours->numero_ligne,positionEnCours->ordre,positionEnCours->phrase);
        positionEnCours=positionEnCours->suivant;
    }
 }

