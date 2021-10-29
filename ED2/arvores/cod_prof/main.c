#include <stdio.h>
#include <stdlib.h>
#include "avrbinbusca.h"

int main(){
    int res,elem;   
    Arv *a=NULL, *b;
    int v[] = {8,6,2,4,1,18,9,12,5,0,7,3};
    int i, tam = 12;

    // Criação da árvore binária de busca
    for(i=0;i<tam;i++) 
       a = arv_insere(v[i],a);

    printf("\nPercurso em Ordem: ");
    arv_imprime_em(a); 
    printf("\nPercurso em Niveis: ");
    arv_imprime_niveis(a);
    
    elem = 18;   
    res = arv_busca(a,elem);
    if (res==1)
        printf("\n\nResultado da busca: Elemento %d encontrado",elem);
    else printf("\n\nResultado da busca: Elemento %d não encontrado",elem);

    b = arv_maior(a);
    if (b!=NULL) printf("\n\nMaior elemento: %d",b->info);

    b = arv_menor(a);
    if (b!=NULL) printf("\nMenor elemento: %d\n",b->info);

    a = arv_remove(a,18);
    printf("\nApós remoção do elemento 8:");
    printf("\nPercurso em Ordem: ");
    arv_imprime_em(a); 
    printf("\nPercurso em Niveis: ");
    arv_imprime_niveis(a);
}

/*
8,6,2,4,1,18,9,12,5,0,7,3

           8
        /     \
       6      18
      / \    /
     2   7  9 
    / \      \
   1   4      12
  /   / \
 0   3   5 
 
*/
