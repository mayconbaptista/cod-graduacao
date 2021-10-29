#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime (int vet[], int inicio, int fim)
{
    for(int i = inicio; i <= fim; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
}

int QuickPartRand (int vet[], int esq, int dir)
{
    srand(time(NULL));
    int indice_pivo = esq + (rand() % (dir - esq));

    int temp = vet[indice_pivo];
    vet[indice_pivo] = vet[dir];
    vet[dir] = temp;

    int j = esq - 1;
    int i;
    int pivo = vet[dir];

    for(i = esq; i < dir; i++)
    {
        if(vet[i] <= pivo)
        {
            j++;
            int temp = vet[j];
            vet[j] = vet[i];
            vet[i] = temp;
        }
    }

    temp = vet[j + 1];
    vet[j + 1] = vet[dir];
    vet[dir] = temp;

    return j + 1;
}

void Quicksort (int vet[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int pos = QuickPartRand (vet, inicio, fim);
        Quicksort(vet, pos + 1, fim);
        Quicksort(vet, inicio, pos - 1);
    }
}

//****************************************************************
void insertionSort(int arr[], int inicio, int fim){
    int i, key, j;
    
    for (i = inicio + 1; i <= fim; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= inicio && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void QuickSort_InsectionSort (int vet[], int begin, int end)
{
    if((end - begin) <= 5)
        insertionSort (vet, begin, end); // insection
    else
    {
        int pivo = QuickPartRand (vet, begin, end);
        QuickSort_InsectionSort (vet, begin, pivo - 1);// part da esquerda
        QuickSort_InsectionSort (vet, pivo + 1, end); // part da direira
    }
}



int main (void)
{
    int vet[8] = {4,7,2,6,4,1,8,3};

    QuickSort_InsectionSort (vet, 0, 7);
    imprime(vet,0 , 7);

    return 0;
}