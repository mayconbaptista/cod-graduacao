#include <time.h>
#include <stdlib.h>

#ifndef ORDQUICKSORT_H
#define ORDQUICKSORT_H

int QuickPart (int vet[], int inicio, int fim)
{
    int pivo = inicio;

    int indice_esq = inicio + 1;
    int indice_dir = fim;

    while(indice_esq < indice_dir)
    {
        while (vet[indice_esq] <= vet[pivo])
        {
            indice_esq++;
        }
        while (vet[indice_dir] > vet[pivo])
        {
            indice_dir--;
        }
        if(indice_esq < indice_dir)
        {
            int temp = vet[indice_esq];
            vet[indice_esq] = vet[indice_dir];
            vet[indice_dir] = temp;
        }
    }

    int temp = vet[pivo];
    vet[pivo] = vet[indice_dir];
    vet[indice_dir] = temp;

    return indice_dir;
}

int QuickPartRand (int vet[], int inicio, int fim)
{
    srand(time(NULL));
    int pivo = (rand () % (fim - inicio)) + inicio;

    int temp = vet[pivo];
    vet[pivo] = vet[inicio];
    vet[inicio] = temp;
    

    int indice_esq = inicio + 1;
    int indice_dir = fim;

    while(indice_esq < indice_dir)
    {
        while (vet[indice_esq] <= vet[pivo])
        {
            indice_esq++;
        }
        while (vet[indice_dir] > vet[pivo])
        {
            indice_dir--;
        }
        if(indice_esq < indice_dir)
        {
            temp = vet[indice_esq];
            vet[indice_esq] = vet[indice_dir];
            vet[indice_dir] = temp;
        }
    }

    temp = vet[pivo];
    vet[pivo] = vet[indice_dir];
    vet[indice_dir] = temp;

    return indice_dir;
}

void QuickSort (int vet[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int pivo = QuickPartRand (vet, inicio, fim);
        QuickSort(vet, inicio, pivo - 1);
        QuickSort(vet, pivo + 1, fim); 
    }
}

#endif