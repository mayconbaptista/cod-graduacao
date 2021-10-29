#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
//#include "mergeSort.h"
//#include "quickSort.h"

/*
void imprime (int vet[], int inicio, int fim)
{
    for(int i = inicio; i <= fim; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}
*/

int main (void)
{
    int vet[8] = {4,7,2,6,4,1,8,3};
    // [1,2,3,4,4,6,7,8]
    // [4,3,2,6p,4,1,8if,7]
    // [4,3,2,6p,4,1,8if,7]
    // [4,3,2,8,4,1,6,7]

    insertionSort(vet, 0,7);
    imprime(vet, 0, 7);
    return 0;
}
