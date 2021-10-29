#include <stdlib.h>
#include <stdio.h>

#ifndef ORDMERGESORT_H
#define ORDMERGESORT_H

void Merge (int vet[], int inicio, int meio, int fim)
{
    int tamanho = (fim - inicio) + 1; 

    int vet_aux[tamanho];
    
    int indice_subVet1 = inicio;
    int indice_subVet2 = meio + 1;
    int indice_k = 0;

    printf("particionando!\n");
    while(indice_subVet1 <= meio && indice_subVet2 <= fim)
    {
        if(vet[indice_subVet1] < vet[indice_subVet2])
        {
            vet_aux[indice_k++] = vet[indice_subVet1++];
        }
        else
        {
            vet_aux[indice_k++] = vet[indice_subVet2++];
        }
    }

    printf("verificando sobras no sub vetor1\n");
    while (indice_subVet1 <= meio)
    {
        vet_aux[indice_k++] = vet[indice_subVet1++];
    }

    printf("verificando sobras no sub vetor 2\n");
    while (indice_subVet2 <= fim)
    {
        vet_aux[indice_k++] = vet[indice_subVet2++];
    }
        
    printf("inserindo ordenado!\n");
    for(int i = inicio, j = 0; i <= fim; i++, j++)
    {
        vet[i] = vet_aux[j];
    }
}

void Merge2 (int vet[], int inicio, int meio, int fim)
{
    int tamanho = (fim - inicio) + 1;
    int vet_aux[tamanho];  

    int indice_subVet1 = inicio;
    int indice_subVet2 = meio + 1;

    for(int indice_k = 0; indice_k < tamanho; indice_k++)
    {
        if(indice_subVet1 <= meio && indice_subVet2 <= fim)
        {
            if(vet[indice_subVet1] < vet[indice_subVet2])
            {
                vet_aux[indice_k] = vet[indice_subVet1++];
            }
            else
            {
                vet_aux[indice_k] = vet[indice_subVet2++];
            }
        }
        else if(indice_subVet1 <= meio)
        {
            vet_aux[indice_k] = vet[indice_subVet1++];
        }
        else if(indice_subVet2 <= fim)
        {
            vet_aux[indice_k] = vet[indice_subVet2++];
        }
    }

    for(int i = inicio, j = 0; j < tamanho ; i++, j++)
    {
        vet[i] = vet_aux[j];
    }
}

int Merge3 (int vet[], int inicio, int meio, int fim)
{
    int tamanho = (fim - inicio) + 1;

    int size_subVet1 = (meio - inicio) + 1;
    int size_subvet2 = fim - meio;

    int subVet1[size_subVet1];
    int subVet2[size_subvet2];

    for(int i = 0, j = inicio; i < size_subVet1; i++, j++)
    {
        subVet1[i] = vet[j];
    }
    for(int i = 0, j = meio + 1; i < size_subvet2; i++, j++)
    {
        subVet2[i] = vet[j];
    }

    int indice_subVet1 = 0;
    int indice_subVet2 = 0;
    int indice_k = inicio;

    while(indice_subVet1 < size_subVet1 && indice_subVet2 < size_subvet2)
    {
        if(subVet1[indice_subVet1] < subVet2[indice_subVet2])
        {
            vet[indice_k++] = subVet1[indice_subVet1++];
        }
        else
        {
            vet[indice_k++] = subVet2[indice_subVet2++];
        }
    }

    while (indice_subVet1 < size_subVet1)
    {
       vet[indice_k++] = subVet1[indice_subVet1++];
    }
    while(indice_subVet2 < size_subvet2)
    {
        vet[indice_k++] = subVet2[indice_subVet2++];
    }

}

void MergeSort (int vet[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = (inicio + fim) / 2;

        MergeSort(vet, inicio, meio);
        MergeSort(vet, meio + 1, fim);
        Merge3 (vet, inicio, meio, fim);
    }
}

#endif