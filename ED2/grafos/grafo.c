#include "grafo.h"

struct grafoS
{
    int **data;
    int num_vertices;
    int num_arestas;
    int direcionado; // 1-> grafo unidirecionado / 0 -> direcionado
    int valorado; // 1 para valorado / 0 para não valorado
};

// funçoes auxiliares

void iniciaAD (GrafoS *grf)
{
    if(grf != NULL && *grf->data != NULL)
    {
        for(int i = 0; i < grf->num_vertices; i++)
        {
            for(int j = 0; j < grf->num_vertices; j++)
            {
                grf->data[i][j] = 0;
            }
        }
    }
}

void exibir_matrizAD (GrafoS *grf)
{
    if(grf != NULL)
    {
        printf("Matriz de adjacencia:\n");

        for(int i = 0; i < grf->num_vertices; i++)
        {
            printf("\tV%d",i);
        }
        printf("\n");

        for(int i = 0; i < grf->num_vertices; i++)
        {
            printf("V%d",i);
            for(int j = 0; j < grf->num_vertices; j++)
            {
                printf("\t%d",grf->data[i][j]);
            }
            printf("\n");
        }
    }
}

void imprime_listaAD (GrafoS *grf)
{
    if(grf != NULL)
    {
        printf("Imprime lista:\n");

        for(int i = 0; i < grf->num_vertices; i++)
        {
            printf("V%d -> ",i);
            for(int j = 0; j < grf->num_vertices; j++)
            {
                if(grf->data[i][j] > 0)
                {
                    printf("V%d ",j);
                }
            }
            printf("\n");
        }
    }
}

// construtor do tipo GrafoS
GrafoS* cria_grafoAD (int vertices, int direcionado, int valorado)
{
    if(vertices < 1)
        return NULL;
    
    GrafoS *grf = (GrafoS*) malloc (sizeof(struct grafoS));

    if(grf == NULL)
        return NULL;

    grf->data = (int**) malloc (vertices*sizeof(int*)); // alocando as linhas
    
    if(grf->data == NULL)
    {
        free(grf);
        return NULL;
    }

    for(int i = 0; i < vertices; i++)
    {
        grf->data[i] = (int*) malloc (vertices*sizeof(int));

        if(grf->data[i] == NULL)
        {
            for(int j = 0; j < i; j++)
            {
                free(*grf->data);
            }
            free(grf);
            return NULL;
        }
    }

    grf->num_vertices = vertices;
    grf->direcionado = direcionado;
    grf->valorado = valorado;
    grf->num_arestas = 0;
    iniciaAD(grf);
    return grf;
}

// destrutor
void libera_grafoAD (GrafoS *grf)
{
    if(grf != NULL)
    {
        for(int i = 0; i < grf->num_vertices; i++)
        {
            free(*grf->data);
        }
        free(*grf->data);
        free(grf);
    }
}

// funçoes

int insereArestaAD (GrafoS *grf, int orig, int dest, int peso)
{
    if(grf == NULL)
        return PONTEIRO_INVALIDO;
    else if(orig < 0 || orig >= grf->num_vertices)
        return FORA_DO_ALCANCE;
    else if(dest < 0 || dest >= grf->num_vertices)
        return FORA_DO_ALCANCE;
    else if(grf->data[orig][dest] == 0)
    {
        if(grf->direcionado == 0 )
        {
            grf->data[dest][orig] = peso;
        }

        grf->data[orig][dest] = peso;
        grf->num_arestas++;
    }
    return SUCESSO;
}

int remove_ArestaAD (GrafoS *grf, int orig, int dest)
{
    if(grf == NULL)
        return PONTEIRO_INVALIDO;
    else if(orig < 0 || orig >= grf->num_vertices)
        return FORA_DO_ALCANCE;
    else if(dest < 0 || dest >= grf->num_vertices)
        return FORA_DO_ALCANCE;
    else if(grf->data[orig][dest] == 0)
        return ERROR;
    
    if(grf->direcionado != 0)
        grf->data[dest][orig] = 0;
    
    grf->data[orig][dest] = 0;
    grf->num_arestas--;
    return SUCESSO;
}

// busca em largura
void BFS (GrafoS *grf, int lin, int dis)
{
    if(grf != NULL && lin >= 0 && lin < grf->num_vertices)
    {
        printf("Vertice %d - dist %d -> ",lin,dis);
        for(int i = 0; i < grf->num_vertices; i++)
        {
            if(grf->data[lin][i] > 0)
            {
                printf("%d ");
                BFS(grf, i, dis + 1);
            }
        }
        printf("\n");
    }
}