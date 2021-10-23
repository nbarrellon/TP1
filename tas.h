#include <stdlib.h>
#include <stdio.h>

typedef enum Bool{
    false,
    true
}Bool;

int *initialisation(int n);
int valeur_mini_tas(int *tas,int n);
Bool est_vide(int *tas,int n);
Bool est_plein(int *tas,int n);
void affiche_tas(int *tas,int n);
int *insere_dans_tas(int *tas,int val,int n);
int *supprime_dans_tas(int *tas,int n);