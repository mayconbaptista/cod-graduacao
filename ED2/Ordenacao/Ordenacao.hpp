#include <iostream>
#include <algorithm>

#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP

void troca (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class Ordenacao
{
public:
    Ordenacao ();
    void selectionSortRecur (int vet[],int inicio, int size);
    void selectionSort (int vet[],int inicio, int size);
    void InsectionSort (int vet[], int inicio, int fim);
    int buscaLinear (int vet[], int size, int chave);
    int buscaBinRec (int vet[], int inicio, int fim, int chave);
    void QuickSort2 (int vet[], int inicio, int fim);
    void heapSort (int vet[], uint tam);
    ~Ordenacao ();

private:

};


// --------------------------------------------------------- funções -------------------------
void Ordenacao::selectionSort (int vet[], int inicio, int size)
{
    int pos;

    for(uint i = inicio, j; i < size; i++)
    {
        pos = i;
        for(j = i + 1; j < size; j++)
        {
            if(vet[j] < vet[pos])
            {
                pos = j;
            }
        }
        if(i != pos)
        {
            troca(vet[i], vet[pos]);
        }
    }
}// okay testado!


//*********************************************************************************************
void Ordenacao::selectionSortRecur (int vet[],int inicio, int size)
{
    if(inicio == size)
        return;
    else
    {
        int menor = inicio;

        for(uint i = inicio + 1; i < size; i++)
        {
            if(vet[menor] > vet[i])
            {
                menor = i;
            }
        }

        if(inicio != menor)
            troca(vet[inicio], vet[menor]);

        selectionSortRecur(vet, inicio + 1, size);
    }
}// okay restado

int Ordenacao::buscaLinear (int vet[], int size,int chave)
{
    for(int i = 0; i < size; i++)
    {
        if(vet[i] == chave)
            return i; // pos
    }
    return -1;// não existe;
}

int Ordenacao::buscaBinRec (int vet[], int inicio, int fim, int chave)
{
    if(inicio > fim)
        return -1;
    else
    {
        int meio = (inicio + fim) / 2;

        if(vet[meio] < chave)
            buscaBinRec(vet, meio + 1, fim, chave);
        else if(vet[meio] > chave)
            buscaBinRec(vet, inicio, meio - 1, chave);
        else
            return meio;
    }
}

//************************************************************************** incerção ********

void imprime (int vet[], int inicio, int fim)
{
    for(uint i = inicio; i <= fim; i++)
    {
        printf("%d ",vet[i]);
    }
    printf("\n");
}

void Ordenacao::InsectionSort (int vet[], int begin, int end)
{
    int dado, i, j;

    for(int i = begin + 1; i < end; i++)// 1
    {
        dado = vet[i]; // 1.1
        for(int j = i; (j > begin) && (dado > vet[j - 1]); j--) // 1.2
        {
            vet[j] = vet[j - 1]; // 1.2.1
        }
        if(dado < vet[j])
            vet[j] = dado; // 1.3
        imprime(vet, begin, i);
    }
}

// ************************************************************************* quicksort *******

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
    
    //std::cout << "fim " << std::endl;
    //imprime(vet, begin, end);
    //std::cin.get();
    return maiores;
}

void Ordenacao::QuickSort2 (int vet[], int begin, int end)
{
    if(begin < end)
    {
        int pivo = QuickPart (vet, begin, end);
        QuickSort2(vet, begin, pivo - 1);// part da esquerda
        QuickSort2(vet, pivo + 1, end); // part da direira
    }
}// okay testado!

// ************************************************** metodo heapSort

void heap (int vet[], uint inicio,uint fim)
{
    uint pai = inicio, filhoE = pai * 2 + 1, filhoD = pai * 2 + 2; 
}

void Ordenacao::heapSort (int vet[], uint fim)
{
    for(uint i = 0; i <= fim; i++)
    {
        heap(vet, i, fim);
    }
}

//################################################################## constructors #############
Ordenacao::Ordenacao ()
{

}

Ordenacao::~Ordenacao ()
{

}
#endif