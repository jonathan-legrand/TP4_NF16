
#include <stdio.h>
#include <string.h>

/*int cmp_ordre_lexicometrique (char* chaine1, char* chaine2){
    int tailleChaine1 = strlen(chaine1);
    int tailleChaine2 = strlen(chaine2);
    
}*/


// https://openclassrooms.com/forum/sujet/trier-une-liste-de-mots-par-ordre-alphabetique

// OPENCLASSROOM

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
 
const char *words[]={"force", "élève", "enlève",
                     "élevé", "enlevé", "Encore",
                     "Évident", "Erreur", "Faiblement",
                     "encore", "en-dessous"
                    };
const size_t size_words=sizeof words/sizeof *words;
 
void print_array(const char * const array[], size_t size)
{
  for(size_t i=0; i<size; ++i)
    printf("\t%2zu : %s\n", i, array[i]);
}
 
int compare(const void *d1, const void *d2)
{
  const char * const *p1=d1;
  const char * const *p2=d2;
  return strcoll(*p1, *p2);
}
 
void sort_array(const char *array[], size_t size)
{
  qsort(array, size, sizeof *array, compare);
}
 
int main(void)
{
  setlocale(LC_COLLATE, "fr_FR.UTF-8");
 
  printf("Array\n");
  print_array(words,size_words);
  printf("\n");
 
  sort_array(words, size_words);
 
  printf("Array sorted\n");
  print_array(words,size_words);
  printf("\n");
 
  return 0;
}

*/

