#include "../include/indexer_fichier_bis.h"
#include "../include/ajouter_noeud.h"
#include "../include/ajouter_position.h"
#include "../include/creer_liste_positions.h"
#include "../include/chaines.h"
#include "../include/rechercher_mot.h"


#include <stdio.h>
#define TAILLE_MAX 5000


/*p_Noeud* creer_noeud_phrase(){
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
*/

p_Noeud* ajouterNoeudPhrase(listeNoeudPhrase* listePhrases, int num_phrase,char *phrase)
{
    p_Noeud* nouveau_noeud_phrase=malloc(sizeof(p_Noeud));

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
    int num_ligne = 1;
    int num_phrase = 1;
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
            //printf("Carac : %c\n",ch);
            //*(phrase+ nb_char_phrase)=ch;
            phrase[nb_char_phrase]=ch;
            nb_char_phrase++;
        }
        
        if (ch == '.')
            {
                printf("La phrase lu est :%s\n ",phrase);
                ajouterNoeudPhrase(listePhrases,num_phrase,phrase);
                //printf("Le numero de phrase est :%d\n ",listePhrases->numero_phrase);

                num_phrase++;
                printf("La phrase est :%s\n ",(*listePhrases)->phrase);
                strcpy(phrase,"");
                nb_char_phrase=0;
                //printf("test5\n");
                //phrase = malloc(sizeof(0));

            }


            if(ch == '\0' || ch == '\n')
            {
                num_ligne++;
                strcpy(phrase,"");
                // TODO A rajouter
            } 
        
        } 

        fclose(fptxt);
    }       

    //printf("Le 1er mot est : %s\n",listePhrases->phrase);
    //printf("Le 2ème mot est : %s\n",listePhrases->suivant->phrase); // FIXME n'affiche rien

    //affichage_Noeud(listePhrases);


    return num_phrase;


    }

    

void affichage_Noeud(listeNoeudPhrase listePhrases){
    
   p_Noeud* phraseEnCours;
   phraseEnCours = listePhrases;
   //printf("\ntest1\n");
   while (phraseEnCours!=NULL)
   {
        //printf("\ntest2\n");
       printf("Phrase %d est : %s \n\n",phraseEnCours->numero_phrase,phraseEnCours->phrase);
       phraseEnCours=phraseEnCours->suivant;
       printf("\n");
   }
    
}







