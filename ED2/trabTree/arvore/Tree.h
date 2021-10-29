#include "../Retornos.h"
#include "../fila/Fila.h"

#ifndef TADTREEDICTIONARY
#define TADTREEDICTIONARY

typedef struct AVL_Node *AVL_Tree;

AVL_Tree* constructor_AVL_Tree (void);

int insere_AVL_Tree (AVL_Tree *raiz, char chave[],struct DADO infor);

struct DADO busca_AVL_Tree (const AVL_Tree *tree, char chave[]);

void exibir_AVL_Tree (const AVL_Tree *raiz);

void descructor_AVL_Tree (AVL_Tree *raiz);

int remove_AVL_Tree (AVL_Tree *raiz, char chave[]);

void pre_ordem_AVL(const AVL_Tree *raiz, FILA *fila);

void in_ordem_AVL(const AVL_Tree *raiz, FILA *fila);

void pos_ordem_AVL(const AVL_Tree *raiz, FILA *fila);

#endif

