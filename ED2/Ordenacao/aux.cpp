#include <iostream>

void selectionSort (int vet[], int inicio, int size)
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
}// o

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

void QuickSort2 (int vet[], int begin, int end)
{
    if(begin < end)
    {
        int pivo = QuickPart (vet, begin, end);
        QuickSort2(vet, begin, pivo - 1);// part da esquerda
        QuickSort2(vet, pivo + 1, end); // part da direira
    }
}// okay testado!


int main (void)
{
    
}