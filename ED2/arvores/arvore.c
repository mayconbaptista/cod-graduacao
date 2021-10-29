#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore.h"

typedef unsigned int uint;

struct TREE_NODE
{
    int key;
    char info[31];
    struct TREE_NODE *left;
    struct TREE_NODE *right;
};

struct BIN_SEARCH_TREE
{
    struct TREE_NODE *raiz;
    uint size;
};

// funçoes auxiliares  não aparecem no .h

struct TREE_NODE* constructor_node (int key, char *nome)
{
    struct TREE_NODE *node = (struct TREE_NODE*) malloc (sizeof(struct TREE_NODE));

    if(node != NULL)
    {
        node->key = key;
        strcpy(node->info, nome);
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}// okay testado

void free_node (struct TREE_NODE *node)
{
    if(node != NULL)
    {
        free_node(node->left);
        free_node(node->right);
        free(node);
        node = NULL;
    }
}// okay


// -------------------------------- funçoes da classe bst ----------------------------------


BIN_SEARCH_TREE* constructor_BST (void)
{
    BIN_SEARCH_TREE *tree = (BIN_SEARCH_TREE*) malloc (sizeof(BIN_SEARCH_TREE));

    if(tree == NULL) return NULL;

    tree->raiz = NULL;
    tree->size = 0;
    return tree;
}// okay testado!


void clear_BTS (BIN_SEARCH_TREE *tree)
{
    if(tree != NULL)
    {
        free_node(tree->raiz);
        tree->raiz = NULL;
        tree->size = 0;
    }
}

void destructor_BST (BIN_SEARCH_TREE *tree)
{
    if(tree != NULL)
    {
        free_node(tree->raiz);
        free(tree);
        tree = NULL;
    }
}// okay testado


// funçoes de inserção

int insert_BST (BIN_SEARCH_TREE *tree, int key, char *info)
{
    if(tree == NULL) return INVALID_POINTER;

    struct TREE_NODE *aux, *newnode = constructor_node(key, info);

    if(newnode == NULL)
        return OUT_NOT_MEMORY;
    else if(tree->raiz == NULL)
    {
        tree->raiz = newnode;
    }
    else
    {
        aux = tree->raiz;

        while(aux != NULL)
        {
            if(key < aux->key)
            {
                if(aux->left == NULL)
                {
                    aux->left = newnode;
                    break;
                }
                else
                    aux = aux->left;
            }
            else if(key > aux->key)
            {
                if(aux->right == NULL)
                {
                    aux->right = newnode;
                    break;
                }
                else
                    aux = aux->right;
            }
            else
            {
                free(newnode);
                return EXISTING_ELEMENT;
            }
        }
    }
    return SUCCESS;
}

// funçõe de busca


char* search_BTS (BIN_SEARCH_TREE *tree, int key)
{
    if(tree != NULL && tree->raiz != NULL)
    {
        struct TREE_NODE *aux = tree->raiz;


        while(aux != NULL)
        {
            if(key < aux->key)
            {
                aux = aux->left;
            }
            else if(key > aux->key)
            {
                aux = aux->right;
            }
            else
                return aux->info;// sucess
        }

        return NULL;
    }
    return NULL;
}// parece okay

// funçoes de remoção e auxiliares


int search_max_BST (struct TREE_NODE* node) // fun aux pega o maior elem a esq e ordena os ponteiros
{
    if(node != NULL)
    {
        struct TREE_NODE *ant = node, *atual = node;

        while(atual->right != NULL)
        {
            ant = atual;
            atual = atual->right;
        }
        
        ant->right = atual->left;
        int temp = atual->key;
        free(atual);

        return temp;
    }
    return INVALID_POINTER;
}

int search_min_BST (struct TREE_NODE* node) // fun aux pega o  menor elem a dir e orden os ponteiros
{
    if(node != NULL)
    {
        struct TREE_NODE *ant = node, *atual = node;

        while(atual->left != NULL)
        {
            ant = atual;
            atual = atual->left;
        }

        ant->left = atual->right;
        int temp = atual->key;
        free(atual);

        return temp;
    }
    return INVALID_POINTER;
}

int remove_BTS (BIN_SEARCH_TREE *tree, int key)
{
    if(tree == NULL || tree->raiz == NULL) return INVALID_POINTER;
    
    struct TREE_NODE *ant = tree->raiz, *atual = tree->raiz;

    while(atual != NULL)
    {
        if(key < atual->key)
        {
            ant = atual;
            atual = atual->left;
        }
        else if(key > atual->key)
        {
            ant = atual;
            atual = atual->right;
        }
        else
        {
            if(atual->left == NULL && atual->right == NULL) // caso 1 no folha
            {
                if(tree->raiz == atual) // ok
                    tree->raiz = NULL; 
                if(ant->left == atual) // ok
                    ant->left = NULL;
                else if(ant->right == atual) // ok
                    ant->right = NULL;
                free(atual);
            }// okay testado
            else if (atual->left == NULL || atual->right == NULL) // caso 2 umlado e nulo
            {
                if(atual->left == NULL) // não exist sub arv a esq
                {
                    if(tree->raiz == atual)
                    {
                        tree->raiz = tree->raiz->right;
                    }
                    else
                    {
                        if (ant->left == atual)
                        {
                            ant->left = atual->right;
                        }// ok
                        else
                        {
                            ant->right = atual->right;
                        }// ok
                        
                    }
                }// ok
                else // não existe sub arv a dir
                {
                    if(tree->raiz == atual) // elem e a raiz
                    {
                        tree->raiz = tree->raiz->left;
                    }
                    else // não e a raiz
                    {
                        if (ant->right == atual)
                        {
                            ant->right = atual->left;
                        }// ok
                        else
                        {
                            ant->left = atual->left;
                        }// ok
                        
                    }// ok
                }
                free(atual);
            }
            else // exist sub arv a dir e esq
            {
                int result = search_max_BST (atual->left);

                if(result > 0)
                    atual->key = result;
                else
                    return result;
            }// okay
            tree->size--;
            return SUCCESS;
        }
    }
    return ELEMENT_NOT_FOUND;
}


// funçoes de percurso

void pre_order (struct TREE_NODE* node)
{
    if(node != NULL)
    {
        printf("%d ",node->key);
        pre_order (node->left);
        pre_order (node->right);
    }
}

void BST_pre_order (BIN_SEARCH_TREE *tree) 
{
    if(tree != NULL)
    {
        printf("PRE_ORDER: ");
        pre_order (tree->raiz);
        printf("\n");
    }
}

void in_order (struct TREE_NODE* node)
{
    if(node != NULL)
    {
        in_order (node->left);
        printf("%d ",node->key);
        in_order (node->right);
    }
}

void BST_in_order (BIN_SEARCH_TREE *tree)
{
    if(tree != NULL)
    {
        printf("IN_ORDER: ");
        in_order (tree->raiz);
        printf("\n");
    }
}

void pos_order (struct TREE_NODE* node)
{
    if(node != NULL)
    {
        pos_order (node->left);
        pos_order (node->right);
        printf("%d ",node->key);
    }
}

void BST_pos_order (BIN_SEARCH_TREE *tree)
{
    if(tree != NULL)
    {
        printf("POS_ORDER: ");
        pos_order (tree->raiz);
        printf("\n");
    }
}

// funçoes relacionadas ao tamanho da arvore

int BTS_empty (BIN_SEARCH_TREE *tree)
{
    if(tree == NULL)
        return INVALID_POINTER;
    else if(tree->size >= 1)
        return SUCCESS;
    else
        return 0; // false
}


// +++++++++++++++++++++++++++++++++++++++++++  funçoes  da lista de arvores++++++++++++++++++++++++++++++++++
// exe1 Escreva uma funcao que conta o numero de nós de uma arvore binaria

int contaNos (struct TREE_NODE *raiz)// função aux
{
    if(raiz != NULL)
    {
        return 1 + (contaNos(raiz) + contaNos(raiz));
    }
    return 0;
}

int num_nos (BIN_SEARCH_TREE *tree)
{
    if(tree == NULL) return INVALID_POINTER;
    
    return contaNos(tree->raiz);
}// ta dando erro

// Escreva uma funcao que conta o numero de nos nao-folha de uma arvore binaria.

int conta_nos_nao_folhas(struct TREE_NODE *node)
{
    if(node->left != NULL && node->right != NULL)
    {
        return 1 + (conta_nos_nao_folhas(node->left) + conta_nos_nao_folhas(node->right));
    }
    else if(node->left == NULL && node->right == NULL)
    {
        return 1 + conta_nos_nao_folhas(node->right);
    }
    else if(node->right == NULL && node->left == NULL)
    {
        return 1 + conta_nos_nao_folhas(node->left);
    }

    return 0;
}

int num_nos_nao_folhas (BIN_SEARCH_TREE *tree)
{
    if(tree == NULL) return INVALID_POINTER;

    return conta_nos_nao_folhas(tree->raiz);
}// flha de segmentação

// Escreva uma funcao que conta o numero de folhas de uma arvore binaria.

int conta_folhas (struct TREE_NODE *node)
{
    if(node->left != NULL)
    {
        conta_folhas(node->left);
    }
    if(node->right != NULL)
    {
        conta_folhas(node->right);
    }
    else
        return 1;

    return 0;
}

int size_folhas (BIN_SEARCH_TREE *tree)
{
    if(tree == NULL ) return INVALID_POINTER;

    return conta_folhas(tree->raiz);
}
