#include "Tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct AVL_Node
{
    char chave[SIZE_CHAR];
    struct DADO infor;
    int altura;

    struct AVL_Node *esq;
    struct AVL_Node *dir;
};

// contrutores e destrutores

AVL_Tree* constructor_AVL_Tree (void)
{
    AVL_Tree *raiz = (AVL_Tree*) malloc (sizeof(AVL_Tree));

    if(raiz != NULL)
    {
        *(raiz) = NULL;
    }
    return raiz;
}
// ++++++++++++++++++++++++++++++++++ funçoes auxiliaxes +++++++++++++++++++++++++++++++++

int altura_node (struct AVL_Node *node)
{
    if(node == NULL) return INVALID_POINTER;
    else
        return node->altura;
}

int fator_balanceamento_node (struct AVL_Node *node)
{
    return labs(altura_node(node->esq) - altura_node(node->dir));
}

int maior (int x,int y){return x > y ? x : y; }

void remove_endl (char str[])
{
    for(unsigned int i = 0; i < SIZE_CHAR; i++)
    {
        if(str[i] == '\n')
        {
            str[i] = '\0';
            return;
        }
    }
}

// ********************************* funçoes de rotação **********************************

void Rotacao_SimpDir (AVL_Tree *A)
{
    struct AVL_Node *B;

    B = (*A)->esq;

    (*A)->esq = B->dir;

    B->dir = *A;

    (*A)->altura = maior(altura_node((*A)->esq), altura_node((*A)->dir)) +1;

    B->altura = maior(altura_node(B->esq), (*A)->altura) +1;

    (*A) = B;
} // LL

void Rotacao_SimpEsq (AVL_Tree *A)
{
    struct AVL_Node *B;
    
    B = (*A)->dir;

    (*A)->dir = B->esq;

    B->esq = (*A);

    (*A)->altura = maior (altura_node((*A)->esq), altura_node((*A)->dir)) +1;

    B->altura = maior (altura_node(B->dir), (*A)->altura) +1;

    (*A) = B;
} // RR

void Rotacao_DupDir (AVL_Tree *A)
{
    Rotacao_SimpEsq (&(*A)->esq);
    Rotacao_SimpDir (A);
} // LR

void Rotacao_DupEsq (AVL_Tree *A)
{
    Rotacao_SimpDir (&(*A)->dir);
    Rotacao_SimpEsq (A);
} // RL

// +++++++++++++++++++++++++++++++ funçoe de incerção ++++++++++++++++++++++++++++++++++++++

int insere_AVL_Tree (AVL_Tree *raiz, char chave[],struct DADO infor)
{
    int retorno;
    
    if(*raiz == NULL)
    {
        struct AVL_Node *novo = (struct AVL_Node*) malloc (sizeof(struct AVL_Node));

        if(novo == NULL) return OUT_NOT_MEMORY;

        strcpy(novo->chave, chave);
        novo->infor = infor;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->altura = 0;
    
        *raiz = novo;

        return SUCCESS;
    }

    struct AVL_Node *atual = *raiz;

    if(strcasecmp(chave, atual->chave ) < 0)
    {
        retorno = insere_AVL_Tree(&(atual->esq), chave, infor);

        if(retorno == 1)
        {
            if(fator_balanceamento_node (atual) >= 2)
            {
                if(strcasecmp(chave, (*raiz)->esq->chave) < 0)
                {
                    Rotacao_SimpDir (raiz); // ll simples direita
                }
                else
                {
                    Rotacao_DupDir (raiz); // lr dupla direita
                }
            }
        }
    }
    else if(strcasecmp(chave, atual->chave) > 0)
    {
        retorno = insere_AVL_Tree(&(atual->dir), chave, infor);

        if(retorno == 1)
        {
            if(fator_balanceamento_node(atual) >= 2)
            {
                if(strcasecmp(chave, (*raiz)->dir->chave) > 0)
                {
                    Rotacao_SimpEsq (raiz); // rr simpes esquerda
                }
                else
                {
                    Rotacao_DupEsq (raiz); // rl dupla direita
                }
            }
        }
    }
    else
    {
        return INVALID_OPERATION;
    }
    
    atual->altura = maior(altura_node(atual->esq), altura_node(atual->dir)) + 1;

    return retorno;
}// valgrind okay

// ==================================================== função de busca


struct DADO busca_AVL_Tree (const AVL_Tree *tree, char chave[])
{
    struct DADO dados;
    strcpy(dados.palavra, "Null\n\0");
    strcpy(dados.classificacao, "Null\n\0");
    strcpy(dados.significado, "Null\n\0");

    if(tree != NULL && (*tree) != NULL)
    {
        struct AVL_Node *aux = *(tree);

        while(aux != NULL)
        {
            if(strcasecmp(chave, aux->chave) < 0)
            {
                aux = aux->esq;
            }
            else if(strcasecmp(chave, aux->chave) > 0)
            {
                aux = aux->dir;
            }
            else
            {
                dados = aux->infor;
                break;
            }
        }
    }

    return dados;
}// parece okay

// ----------------------------------------------------- função de remoção

struct AVL_Node* procura_menor (struct AVL_Node *node)
{
    struct AVL_Node *aux = node;

    if(node != NULL)
    {
        while(aux->esq != NULL)
            aux = aux->esq;
    }

    return aux;
}

int remove_AVL_Tree (AVL_Tree *raiz, char chave[])
{
    if(raiz == NULL || (*raiz) == NULL) return OUT_NOT_RANGE;

    int resposta;

    if(strcasecmp(chave, (*raiz)->chave) < 0)
    {
        resposta = remove_AVL_Tree (&(*raiz)->esq, chave);

        if(resposta == SUCCESS)
        {
            if(fator_balanceamento_node(*raiz) >= 2)
            {
                if(altura_node((*raiz)->dir->esq) <= altura_node((*raiz)->dir->dir))
                {
                    Rotacao_SimpEsq (raiz);
                }
                else
                    Rotacao_DupEsq (raiz);
                
            }
        }
    }
    else if(strcasecmp(chave, (*raiz)->chave) > 0)
    {
        resposta = remove_AVL_Tree(&(*raiz)->dir, chave);

        if(resposta == SUCCESS)
        {
            if(fator_balanceamento_node(*raiz) >= 2)
            {
                if(altura_node((*raiz)->esq->dir) <= altura_node((*raiz)->esq->esq))
                {
                    Rotacao_SimpDir(raiz);
                }
                else
                    Rotacao_DupDir(raiz);
            }
        }
    }
    else
    {
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL)
        {
            struct AVL_Node *aux = (*raiz);

            if((*raiz)->esq != NULL)
            {
                (*raiz) = (*raiz)->esq;
            }
            else
                (*raiz) = (*raiz)->dir;
            
            free(aux);
        }
        else
        {
            struct AVL_Node *aux = procura_menor((*raiz)->dir);

            strcpy((*raiz)->chave, aux->chave);

            remove_AVL_Tree(&(*raiz)->dir, (*raiz)->chave);

            if(fator_balanceamento_node(*raiz) >= 2)
            {
                if(altura_node((*raiz)->esq->dir) <= altura_node((*raiz)->esq->esq))
                {
                    Rotacao_SimpDir(raiz);
                }
                else
                    Rotacao_DupDir(raiz);
            }
        }

        if((*raiz) != NULL) (*raiz)->altura = maior(altura_node((*raiz)->esq), altura_node((*raiz)->dir)) +1;

        return SUCCESS;
    }

    (*raiz)->altura = maior(altura_node((*raiz)->esq), altura_node((*raiz)->dir)) +1;

    return resposta;
}

// =============================================== funçoes de percurso

void pre_ordem_AVL(const AVL_Tree *raiz, FILA *fila)
{
    if(raiz != NULL && (*raiz) != NULL && fila != NULL)
    {
        push_FILA(fila, (*raiz)->infor);
        in_ordem_AVL(&(*raiz)->esq, fila);
        in_ordem_AVL(&(*raiz)->dir, fila);
    }
}

void in_ordem_AVL(const AVL_Tree *raiz, FILA *fila)
{
    if(raiz != NULL && (*raiz) != NULL && fila != NULL)
    {
        in_ordem_AVL(&(*raiz)->esq, fila);
        push_FILA(fila, (*raiz)->infor);
        in_ordem_AVL(&(*raiz)->dir, fila);
    }
}

void pos_ordem_AVL(const AVL_Tree *raiz, FILA *fila)
{
    if(raiz != NULL && (*raiz) != NULL && fila != NULL)
    {
        in_ordem_AVL(&(*raiz)->esq, fila);
        in_ordem_AVL(&(*raiz)->dir, fila);
        push_FILA(fila, (*raiz)->infor);
    }
}


void exibir_AVL_Tree (const AVL_Tree *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        exibir_AVL_Tree (&((*raiz)->esq));

        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("chave: %s",(*raiz)->infor.palavra);
        printf("class: %s",(*raiz)->infor.classificacao);
        printf("signi: %s",(*raiz)->infor.significado);

        exibir_AVL_Tree (&((*raiz)->dir));
    }
}// in ordem

// ------------------------------------------------- funçoes de limpeza

void limpa (struct AVL_Node *node)
{
    if(node != NULL)
    {
        limpa(node->esq);
        limpa(node->dir);
        free(node);
        node = NULL;
    }
}// valgrind okay

void descructor_AVL_Tree (AVL_Tree *raiz)
{
    if(raiz != NULL)
    {
        limpa(*raiz);
        free(raiz);
        raiz = NULL;
    }
}// valgrind okay

// fun prova 2

struct arv {
     char info;
     struct arv* esq;
     struct arv* dir;
};
typedef struct arv Arv;

int fmyst (AVL_Tree *a, char c){
    if (a == NULL) return 0;  
    else return &(*a)->chave == c || fmyst (&(*a)->esq,c) || fmyst (&(*a)->dir,c);
}