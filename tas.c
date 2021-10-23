#include <stdlib.h>
#include <stdio.h>

typedef enum Bool{
    false,
    true
}Bool;


//la derniere case du tableau donne
//le nbre d'élements qui y sont stockés
int *initialisation(int n){
    int *tab ;
    tab = malloc(sizeof(int)*n+1);
    tab[n]=0;
    return tab;
}

Bool est_vide(int *tas,int n){
    if (!tas[n]) 
        return true;
    return false;

}

int valeur_mini_tas(int *tas,int n){
    if (est_vide(tas,n)){
        printf("Le tas est vide !");
        exit(1);
    }else
        return tas[0];
}


Bool est_plein(int *tas,int n){
    if (tas[n]==n)
        return true;
    return false;

}

void affiche_tas(int *tas,int n){
    for (int i=0;i<tas[n];i++){
        printf("%d |",tas[i]);
    }
    printf("\n");
    printf("Taille restante:%d\n",n-tas[n]);
}

int *insere_dans_tas(int *tas,int val,int n){
    //premier cas : le tas est vide
    if (est_vide(tas,n)){
        tas[n]=1;
        tas[0]=val;
        return tas;
    }
    if (est_plein(tas,n)){
        printf("Le tas est plein, insertion impossible\n");
        return tas;
    }
    int ins = tas[n];
    tas[ins]=val;
    //on remonte la feuille tant qu'elle est plus
    //petite que son pere
    int temp;
    int ins_pere = (int)((ins-1)/2);
    while ((ins!=0) && (tas[ins]<tas[ins_pere]))
    {
        temp = tas[ins_pere];
        tas[ins_pere] = tas[ins];
        tas[ins]=temp;
        ins = ins_pere;
        ins_pere = (int)((ins-1)/2);
    }
    tas[n]+=1;
    return tas;


}

int *supprime_dans_tas(int *tas,int n){
    if (est_vide(tas,n)){
            printf("Rien à supprimer, le tas est vide\n");
            return tas;
        }
    tas[0] = tas[tas[n]-1];//je mets le dernier élément à la racine
    tas[n]-=1;//je diminue le nb d'élément dasn le tas
    int supp = 0;
    int fils1 = 1;
    int fils2 = 2;
    int temp;
    while ((fils2<=tas[n]) && ((tas[supp]>tas[fils1]) || (tas[supp]>tas[fils2]))){
        if (tas[fils1]>tas[fils2])
            fils1=fils2;
        temp = tas[fils1];
        tas[fils1]=tas[supp];
        tas[supp]=temp;
        supp = fils1;
        fils1 = 2*supp + 1;
        fils2 = 2*supp + 2;
    }
    return tas;

}