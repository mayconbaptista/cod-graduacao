#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef TRABALHO_ORDENACAO_H
#define TRABALHO_ORDENACAO_H

#define const_k 5

void troca (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void imprime (int vet[], int inicio, int fim)
{
    for(int i = inicio; i <= fim; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
}

int QuickPartRand (int vet[], int begin, int end)
{
    int menores = begin;
    int maiores = end;

    srand(time(NULL));
    int pos_pivo = rand() % (end - begin + 1) + begin;
    int pivo = vet[pos_pivo];

    while (menores < maiores)// 1
    {
        while((vet[maiores] >= pivo) && maiores > begin)// 1.2
        {
            maiores--;
        }
        while((vet[menores] <= pivo) && menores < end)// 1.1
        {
            menores++;
        }
        if(menores < maiores) // 1.3
        {
            imprime(vet, begin, end);
            printf("antes troca pivo %d[%d]-> menores[%d] maiores[%d]\n",pos_pivo, pivo, vet[menores], vet[maiores]);
            int temp = vet[menores];
            vet[menores] = vet[maiores];
            vet[maiores] = temp;
            printf(" apos troca: ");
            imprime(vet, begin, end);
            printf("\n\n");
        }
        //imprime(vet, begin, end);
    }
    if(pivo > vet[maiores])
    {
        vet[pos_pivo] = vet[maiores];
        vet[maiores] = pivo;
        pos_pivo =  maiores;
    }
    else
    {
        vet[pos_pivo] = vet[menores];
        vet[menores] = pivo;
        pos_pivo = menores;
    }
    
    printf("fim ciclo inicio %d pos_pivo %d pivo %d fim %d\n",begin, pos_pivo,pivo, end);
    printf("indices maiores %d, menores %d\n",maiores,menores);
    imprime(vet, begin, end);
    getchar();
    return pos_pivo;
}

void insertionSort(int arr[], int inicio, int fim){
    int i, key, j;
    
    for (i = inicio + 1; i <= const_k; i++)
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

// quick sort
int QuickPart (int vet[], int begin, int end)
{
    int menores = begin + 1;
    int maiores = end;
    int pivo = vet[begin];

    while (menores < maiores)// 1
    {
        while((vet[menores] <= pivo) && menores < end)// 1.1
        {
            menores++;
        }
        while((vet[maiores] > pivo) && maiores > begin)// 1.2
        {
            maiores--;
        }
        if(menores < maiores) // 1.3
        {
            int temp = vet[menores];
            vet[menores] = vet[maiores];
            vet[maiores] = temp;
        }
        //imprime(vet, begin, end);
    }
    if(vet[begin] != vet[maiores])// 2.0 evitar trocas desnecessarias
    {
        vet[begin] = vet[maiores];
        vet[maiores] = pivo;
    }
    
    return maiores;
}

void QuickSort2 (int vet[], int begin, int end)
{
    if(begin < end)
    {
        int pivo = QuickPartRand (vet, begin, end);
        QuickSort2(vet, begin, pivo - 1);// part da esquerda
        QuickSort2(vet, pivo + 1, end); // part da direira
    }
}// quick sort classico!

// hibrido Quick-insection_sort
void QuickSort_InsectionSort (int vet[], int begin, int end)
{
    if((end - begin) <= 5)
        insertionSort (vet, begin, end); // insection
    else
    {
        int pivo = QuickPart (vet, begin, end);
        QuickSort2(vet, begin, pivo - 1);// part da esquerda
        QuickSort2(vet, pivo + 1, end); // part da direira
    }
}

// MergeSort *************************************************************************
// func MergeSort O(log N) + func Merge O (N) -> O (N log N)

void Merge (int vet[], int inicio, int meio, int fim)
{
    // obtendo tamanho da partição
    int tamanho = (inicio - fim) + 1;
    // iniciando vet aux
    int vet_aux[tamanho];
    // controla indice do subvetor 1 "inicio ate meio"
    int pos_pat1 = inicio;
    // contrla indice do subvetor 2 "meio ate fim"
    int pos_part2 = meio + 1;

    int pos_k = 0;

    // buscando o menor elemento de cada vetor e iserindo ordenado em um vetor auxiliar
    printf("erro na ordenação\n");
    while (pos_pat1 <= meio && pos_part2 <= fim)
    {
        if(vet[pos_pat1] < vet[pos_part2])
        {
            vet_aux[pos_k++] = vet[pos_pat1++];
        }
        else
        {
            vet_aux[pos_k++] = vet[pos_part2++];
        }
    }

    // se vetor 2 tiver acabado mais ainda tiver numero no vetor 1
    printf("erro em pegar resto do vet1\n");
    while(pos_pat1 <= meio )
    {
        vet_aux[pos_k++] = vet[pos_pat1++]; 
    }
    
    // se vetor 1 tiver acabado mais ainda tiver numero no vetor 2
    printf("erro em pegar resto do vet2\n");
    while (pos_part2 <= fim)
    {
        vet_aux[pos_k++] = vet[pos_part2++];
    }

    // copiado o vetor ordenado!
    printf("erro na parte de copiar!\n");
    for(int i = inicio, j = 0; i <= fim; i++, j++)
    {
        vet[i] = vet_aux[j];
    }
}

void MergeSort (int vet[], int  inicio, int fim)
{
    if((fim - inicio) > 1)
    {
        int meio = (fim + inicio) / 2;

        MergeSort(vet, inicio, meio);
        MergeSort(vet, meio + 1, fim);

        Merge(vet, inicio, meio, fim);
    }
}

#endif