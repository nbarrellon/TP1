#include <stdio.h>
#include <stdlib.h>
#include "tas.h"

int main(int nb_args,char tab_args[]){
    int *tas;
    int n;
    printf("Quelle est la taille du tas ?");
    scanf("%d",&n);
    tas = initialisation(n);
    tas = insere_dans_tas(tas,3,n);
    affiche_tas(tas,n);
    tas = insere_dans_tas(tas,5,n);
    affiche_tas(tas,n);
    

    tas = insere_dans_tas(tas,9,n);
    tas = insere_dans_tas(tas,7,n);
    affiche_tas(tas,n);
    tas = insere_dans_tas(tas,8,n);
    affiche_tas(tas,n);
    tas = insere_dans_tas(tas,1,n);
    affiche_tas(tas,n);
    tas = insere_dans_tas(tas,2,n);
    affiche_tas(tas,n);
    tas = insere_dans_tas(tas,12,n);
    affiche_tas(tas,n);
    tas = insere_dans_tas(tas,6,n);
    affiche_tas(tas,n);
    printf("val=%d\n",valeur_mini_tas(tas,n));
    tas = supprime_dans_tas(tas,n);
    affiche_tas(tas,n);
    tas = supprime_dans_tas(tas,n);
    affiche_tas(tas,n);
    tas = supprime_dans_tas(tas,n);
    affiche_tas(tas,n);
    tas = supprime_dans_tas(tas,n);
    affiche_tas(tas,n);
    tas = supprime_dans_tas(tas,n);
    affiche_tas(tas,n);
     tas = supprime_dans_tas(tas,n);
    affiche_tas(tas,n);
    if (est_vide(tas,n)) printf("Le tas est vide\n");
    else printf("Le tas n'est pas vide\n");
    free(tas);
    return 0;

}