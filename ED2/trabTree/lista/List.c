#include "List.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node_List
{
    struct DADO info;
    struct Node_List *prox;
};


struct TADList
{
    struct Node_List *head;
    unsigned int size; 
};

// construtores e destrutores

struct Node_List* constructor_Node_List (struct DADO info)
{
    struct Node_List* newnode = (struct Node_List*) malloc (sizeof(struct Node_List));

    if(newnode != NULL )
    {
        newnode->info = info;
        newnode->prox = NULL;
    }

    return newnode;
}

struct TADList* constructor_TADList (void)
{
    struct TADList *list = (struct TADList*) malloc (sizeof(struct TADList));

    if(list != NULL )
    {
        list->head = NULL;
        list->size = 0;
    }

    return list;
}

void clear_List (struct TADList *list)
{
    if(list != NULL)
    {
        struct Node_List *ant = NULL, *atual = list->head;

        while (atual != NULL)
        {
            ant = atual;
            atual = atual->prox;

            free(ant);
        }
        list->size = 0; 
        list->head = NULL;
    }
}

void desctructor_TADList (struct TADList *list)
{
    clear_List(list);

    if(list != NULL)
    {
        free(list);
        list = NULL;
    }
}

// ++++++++++++++++++++++++++++++++++++++++++++++ funçoes de incerção

int insert_TADList(struct TADList *list, struct DADO info)
{
    if(list == NULL) return INVALID_POINTER;

    struct Node_List *newnode = constructor_Node_List(info);

    if(newnode == NULL) return OUT_NOT_MEMORY;
    
    else if(list->head == NULL) // ainda esta vazia
    {
        list->head = newnode;
    }
    else
    {
        struct Node_List *ant = NULL, *atual = list->head;

        while(atual != NULL)
        {
            if(strcasecmp(info.palavra, atual->info.palavra) < 0)
                break;
            else if(strcasecmp(info.palavra, atual->info.palavra) == 0)
            {
                free(newnode);
                return INVALID_OPERATION;
            }
            else
            {
                ant = atual;
                atual = atual->prox;
            }
        }

        if(atual == list->head)
        {
            newnode->prox = list->head;
            list->head = newnode;
        }
        else
        {
            newnode->prox = atual;
            ant->prox = newnode;
        }
    }

    list->size++;
    return SUCCESS;
}

// ==================================================== função busca 

struct DADO busca_list (const TADList *list, char chave[])
{
    struct DADO aux;
    strcpy(aux.palavra , "NULL\n\0");
    strcpy(aux.classificacao , "NULL\n\0");
    strcpy(aux.significado , "NULL\n\0");

    if(list != NULL)
    {
        struct Node_List *node = list->head;

        while(node != NULL)
        {
            if(strcasecmp(chave, node->info.palavra) == 0)
            {
                aux = node->info;
                break;
            }
            else if(strcasecmp(chave , node->info.palavra) > 0)
                break;
            else
            {
                node = node->prox;
            }
        }
    }
    return aux;
}

// ---------------------------------------------------- função de remoção

int remove_TADList(struct TADList *list, char chave[])
{
    if(list == NULL) return INVALID_POINTER;
    else if(list->head == NULL)
        return INVALID_OPERATION;

    struct Node_List *ant = NULL, *aux = list->head;

    while(strcasecmp(chave, aux->info.palavra) != 0 && aux != NULL)
    {
        ant = aux;
        aux = aux->prox;
    }

    if(aux == NULL)return ELEMENT_NOT_FOUND;
    if(aux == list->head)
    {
        list->head = list->head->prox;
    }
    else
    {
        ant->prox = aux->prox;
    }

    free(aux);
    list->size--;
    return SUCCESS;
}// testar

// funçoes de tamanho

int empty_TADList(struct TADList* list)
{
    if(list == NULL)
        return INVALID_POINTER;
    else if(list->size > 0)
        return FALSE;
    else
        return SUCCESS;
}

int size_TADList (struct TADList *list)
{
    if(list == NULL)
        return INVALID_POINTER;
    else
        return list->size;
}

// função de impressão

void print_TADList(struct TADList *list)
{
    if(list != NULL)
    {
        struct Node_List *aux = list->head; // var auxiliares
        unsigned int contt = 1;
        printf("=========================== List dictionary ====================\n");
        while(aux != NULL)
        {
            printf("\n+++++++++++++++++++++++++++++++->%d<-+++++++++++++++++++++++++++\n", contt++);
            printf("chave: %s",aux->info.palavra);
            printf("class: %s",aux->info.classificacao);
            printf("signi: %s",aux->info.significado);

            aux = aux->prox;
        }
        printf("================================ |end| =========================\n");
    }
}