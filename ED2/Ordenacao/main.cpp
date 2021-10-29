#include "Ordenacao.hpp"
#include <random>
#include <ctime>
#include <string>
#include <fstream>
#include <memory>



class extrai
{
public:
    void cria (std::string, int);
    void ler (std::string, int&);
    extrai ();
    ~extrai (); 
    int *vet;
    void imprime (int);
};

void InsectionSort2 (int *vet, int n)// 1
{
    int aux, i, j; // 2
    for(int i = 1; i < n; i++) // 3
    {
        aux = vet[i]; // 4
        for(int j = i; (j > 0) && (aux < vet[j - 1]); j--) // 5
        {
            vet[j] = vet[j - 1]; // 6
        }
        vet[j] = aux; // 7
    }
}

int main (void)
{
    int size;
    extrai dados;
    Ordenacao sorts;
    dados.ler("numerosAte50.txt",size);

    int vet[6] = {4, 7, 2, 5, 4, 0};

    InsectionSort2 (vet, 6);
    imprime(vet, 0, 5);
    //sorts.InsectionSort (vet, 0, 5);    

    return 0;
}

// *******************************************************************************************************************

void extrai::cria (std::string str, int size)
{
    srand(time(NULL));

    std::ofstream arg;
    arg.open(str);
    arg << size << '\n';

    for(uint i = 0; i < size; i++)
    {
        arg << rand () % size;
        arg << ' ';
    }

    arg.close();
    return;
}

void extrai::ler (std::string str, int &size)
{
    std::ifstream arg;
    arg.open(str);

    if(arg.is_open())
    {
        size = 0;
        arg >> size;

        this->vet = new int [size];

        for(uint i = 0; i < size; i++)
        {
            arg >> vet[i];
        }
    }
    arg.close();
    return;
}

void extrai::imprime (int size)
{
    for(uint i = 0; i < size; i++)
    {
        std::cout << this->vet[i];

        std::cout << "  ";
        
    }
    std::cout << "fim \n\n";
}

extrai::extrai (void)
{
    this->vet = nullptr;
}

extrai::~extrai (void)
{
    if(this->vet != nullptr)
        delete [] this->vet;
}