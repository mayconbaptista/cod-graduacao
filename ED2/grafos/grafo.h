#include <stdlib.h>
#include <stdio.h>

#ifndef grafoS_H
#define grafoS_H

#define SUCESSO 1
#define ERROR 0
#define PONTEIRO_INVALIDO -1
#define MEMORIA_INDISPONIVEL -2
#define FORA_DO_ALCANCE -3

typedef struct grafoS GrafoS; // ponteiro para um grafo simples

// funçoes auxiliares
void exibir_matrizAD (GrafoS *grf);
void imprime_listaAD (GrafoS *grf);

// construtor do tipo GrafoS
GrafoS* cria_grafoAD (int vertices, int direcionado, int valorado);

// destrutor
void libera_grafoAD (GrafoS *grf);

// funçoes
int insereArestaAD (GrafoS *grf, int orig, int dest, int peso);

int remove_ArestaAD (GrafoS *grf, int orig, int dest);

// operaçoes em grafos
void BFS (GrafoS *grf, int lin, int dis);


#endif