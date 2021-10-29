#include <vector>
#include <memory>
#include <iostream>
#include <stack>
#include <queue>

#ifndef TADGRAFO_HPP
#define TADGRAFO_HPP

typedef unsigned int uint;

using namespace std;

class grafo
{
protected:
    vector < vector<uint>> data;
    uint sizeVertices;
    bool ponderado;
    bool unidirecionado;
    void busca_larg ( vector <uint>& visitados, uint raiz);
    bool buscalinear(const vector <uint>&, uint);

public:
    grafo (uint num_vertices,bool ponderado, bool unidirecionado);
    grafo();
    int pushAresta (uint V1, uint V2);
    int pushAresta (uint V1, uint V2, uint peso);
    int removeAresta(uint V1, uint V2);
    int dijkstra (uint);
    void exibir (void);
    vector <uint> DFS (uint origem);
    vector <uint> BFS (uint origem);
    bool direcionado ();
    void testeP1exe10 ();
    ~grafo();
};

void grafo::testeP1exe10(void)
{
    vector <vector <uint>> vet = {{0,1,1,1,0,0},
                                {0,0,0,0,0,0},
                                {0,0,0,1,1,1},
                                {0,0,0,0,0,0},
                                {0,0,0,0,1,0}};
    
    this->sizeVertices = 6;
    this->ponderado = false;
    this->unidirecionado = false;
    this->data = vet;
}

//--+++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void grafo::exibir (void)
{
    cout << "Matriz de adjacencia:\n";

    for(int i = 0; i < this->sizeVertices; i++)
    {
        cout << "\tV" << i;
    }

    cout << '\n';

    for(int i = 0; i < this->data.size(); i++)
    {
        cout << 'V' << i;
        
        for(int j = 0; j < this->data[i].size(); j++)
        {
            cout << '\t' << this->data[i][j];
        }
        cout << '\n';
    }
}

// construtores

grafo::grafo (){}; // construtor defalt

grafo::grafo (uint num_vertices,bool ponderado, bool unidirecionado)
{
    this->ponderado = ponderado;
    this->unidirecionado = unidirecionado;

    this->data.resize(num_vertices);
    for(uint i = 0; i < data.size(); i++)
    {
        this->data[i].resize(num_vertices);
    }
    this->sizeVertices = num_vertices;
}

grafo::~grafo()
{

}

// funçoes - adição

int grafo::pushAresta (uint lin, uint col)
{
    if(lin < 0 or col < 0)
        return 0; // error
    else if(lin > this->sizeVertices or col > this->sizeVertices)
        return 0; // error
    else if (this->ponderado == true)
        return 0; // error
    else
    {
        if(this->unidirecionado == true)
        {
            this->data[lin][col] = 1;
            this->data[col][lin] = 1;
        }
        else
        {
            this->data[lin][col] = 1;
        }
    }
    return 1; // sucess
}

int grafo::pushAresta (uint lin, uint col, uint peso)
{
    if(lin < 0 or col < 0)
        return 0; // error
    else if(lin > this->sizeVertices or col > this->sizeVertices)
        return 0; // error
    else if (this->ponderado == true)
        return 0; // error
    else
    {
        if(this->unidirecionado == true)
        {
            this->data[lin][col] = peso;
            this->data[col][lin] = peso;
        }
        else
        {
            this->data[lin][col] = peso;
        }
    }
    return 1; // sucess
}

// remoção

int grafo::removeAresta(uint lin, uint col)
{
    if(lin < 0 or col < 0)
        return 0; // error
    else if(lin > this->sizeVertices or col > this->sizeVertices)
        return 0; // error
    else
    {
        if(this->unidirecionado == true)
        {
            this->data[lin][col] = 0;
            this->data[col][lin] = 0;
        }
        else
        {
            this->data[lin][col] = 0;
        }
    }
    return 1; 
}



// funçoes de busca em grafos

bool grafo::buscalinear(const vector <uint> &vet, uint chave) // função aux
{
    for(uint i = 0; i < vet.size(); i++)
    {
        if(vet[i] == chave)
            return true;
    }
    return false;
}

vector <uint> grafo::BFS (uint origem) // busca em largura
{
    queue <uint> fila;
    vector <uint> visit;

    visit.push_back(origem);
    fila.push(origem);

    uint vertice;

    while(!fila.empty())
    {
        vertice = fila.front();
        for(uint i = 0; i < this->data[vertice].size(); i++)
        {
            if(this->data[vertice][i] > 0 and !buscalinear(visit, i))
            {
                fila.push(i);
                visit.push_back(i);
            }
        }
        fila.pop();
    }
    return visit;
}

void grafo::busca_larg (vector <uint>& visitados, uint raiz)
{
    visitados[raiz] = 1;

    for(uint i = 0; i < this->data[raiz].size(); i++)
    {
        if(this->data[raiz][i] > 0 and visitados[i] != 1)
        {
            cout << "vert ->" << i << '\n'; 
            busca_larg(visitados, i);
        }
    }
}

vector <uint> grafo::DFS (uint origem)
{
    vector <uint> visitados(this->sizeVertices);
    this->busca_larg(visitados, origem);

    return visitados;
}

bool grafo::direcionado ()
{
    for(uint i = 0; i < this->data.size(); i++)
    {
        for(uint j = 0; j < this->data[i].size(); j++)
        {
            if(this->data[i][j] != this->data[j][i])
                return true;
        }
    }
    return true;
}

#endif