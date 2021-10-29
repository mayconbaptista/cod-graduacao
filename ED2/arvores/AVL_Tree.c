#include <stdlib.h>
#include <string.h>
#include "AVL_Tree.h"

struct AVL_Node
{
    int key;
    char info[31];
    int height;
    struct AVL_Node *left;
    struct AVL_Node *right; 
};

struct AVL_Node* constructorAVL_Node (int key, char *info)
{
    struct AVL_Node * newnode = malloc (sizeof(struct AVL_Node));

    if(newnode != NULL)
    {
        newnode->key = key;
        strcpy(newnode->info, info);
        newnode->height = 0;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    return newnode;
};

struct AVL_Tree
{
    struct AVL_Node *raiz;
    int size;
};

AVL_Tree* constructor_AVL_tree (void)
{
    AVL_Tree *tree = (AVL_Tree*) malloc (sizeof(AVL_Tree));

    if(tree != NULL)
    {
        tree->raiz = NULL;
        tree->size = 0;
    }

    return tree;
}// testado okay!

// ++++++++++++++++++++++++++++++++++++++ funçoes auxiliares
void limpa (struct AVL_Node* node)
{
    if(node != NULL)
    {
        limpa(node->left);
        limpa(node->right);
        free(node);
        node = NULL;
    }
}

int altura_AVL_Node (struct AVL_Node *node)
{
    if(node == NULL)
        return NULL;
    else
        return node->height;
}

// end

void destructor_AVL_Tree (AVL_Tree *tree)
{
    if(tree != NULL)
    {
        limpa(tree->raiz);
        free(tree);
        tree = NULL;
    }
}// testado okay!

// funçoes da classe avl tree incerção

int insert_AVL_TREE (AVL_Tree *tree, int key, char *info)
{
    if(tree == NULL)
        return INVALID_POINTER;
    
    struct AVL_Node *aux, *newNode = (struct AVL_Node*) malloc (sizeof(struct AVL_Node));

    if(newNode == NULL) OUT_NOT_MEMORY;
    else if (tree->raiz == NULL)
    {
        tree->raiz = newNode;
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
                    aux->left = newNode;
                    break;
                }
                else
                    aux = aux->left;
            }
            else if (key > aux->key)
            {
                if(aux->right == NULL)
                {
                    aux->right = newNode;
                    break;
                }
                else
                    aux = aux->right;
            }
            else
            {
                strcpy(aux->info, newNode->info); // atualiza informação;
                free(newNode);
                break;
            }
            
        }
    }
    tree->size++;
    return SUCCESS;
}