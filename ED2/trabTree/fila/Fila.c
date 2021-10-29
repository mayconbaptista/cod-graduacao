#include "Fila.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct FILA_Node
{
    struct DADO info;
    struct FILA_Node *next;
};

struct FILA
{
    struct FILA_Node *begin;
    struct FILA_Node *end;
    unsigned int size;
};

// *********************************** construtores 

struct FILA_Node* constructor_FILA_Node (struct DADO dado)
{
    struct FILA_Node *node = (struct FILA_Node*) malloc (sizeof(struct FILA_Node));

    if(node != NULL)
    {
        node->info = dado;
        node->next = NULL;
    }
    return node;
}

FILA* constructor_FILA (void)
{
    FILA *Fila = (FILA*) malloc (sizeof(FILA));

    if(Fila != NULL)
    {
        Fila->begin = NULL;
        Fila->end = NULL;
        Fila->size = 0;
    }
    return Fila;
}

// --------------------------------------- destrutores

void clear (struct FILA_Node *node)
{
    if(node != NULL)
    {
        clear(node->next);
        free(node);
        node = NULL;
    }
}

void clear_FILA (FILA *Fila)
{
    if(Fila != NULL)
    {
        clear(Fila->begin);
        Fila->begin = NULL;
        Fila->end = NULL;
        Fila->size = 0;
    }
}

void destructor_FILA (FILA *Fila)
{
    if(Fila != NULL)
    {
        clear_FILA(Fila);
        Fila = NULL;
    }
}

// ++++++++++++++++++++++++++++++++++++++++ função de adição 

int push_FILA (FILA *Fila, struct DADO dado)
{
    if(Fila == NULL) return INVALID_POINTER;

    struct FILA_Node *new = constructor_FILA_Node(dado);

    if(new == NULL) return OUT_NOT_MEMORY;

    if(Fila->begin == NULL && Fila->end == NULL)
    {
        Fila->begin = new;
        Fila->end = new;
    }
    else
    {
        Fila->end->next = new;
        Fila->end = new;
    }

    Fila->size++;
    return SUCCESS;
}

// ---------------------------------------- função de remocão

int remove_FILA (FILA *Fila)
{
    if(Fila == NULL) return INVALID_POINTER;
    else if (Fila->begin == NULL && Fila->end == NULL)
    {
        return OUT_NOT_RANGE;
    }
    
    struct FILA_Node *aux = Fila->begin;

    if(Fila->size == 1)
    {
        Fila->begin = NULL;
        Fila->end = NULL;
    }
    else
    {
        Fila->begin = Fila->begin->next;
    }

    free(aux);
    Fila->size--;
    return SUCCESS;
}

// ========================================== função de consulta

struct DADO front_FILA (FILA *Fila)
{
    struct DADO dado;

    strcpy(dado.palavra, "\0");
    strcpy(dado.classificacao, "\0" );
    strcpy(dado.significado, "\0");

    if(Fila == NULL || (Fila->begin == NULL && Fila->end == NULL)) return dado;

    dado = Fila->begin->info;

    return dado;
}

// **************************************** funçoes de tamanho
int empty_FILA (FILA *Fila)
{
    if(Fila == NULL) return INVALID_POINTER;
    if(Fila->size > 0)
        return 0;
    else
        return SUCCESS;
}

int size_FILA (FILA *Fila)
{
    if(Fila == NULL) return INVALID_POINTER;
    else
        return Fila->size;
}

// ##################################### ebibir fila

void exibir_FilA(FILA *Fila)
{
    if(Fila == NULL) return;
    
    struct FILA_Node *aux = Fila->begin;

    printf("===================== | exibindo fila | =====================\n\n");
    while(aux != NULL)
    {
        printf("______________________________________________________________\n");
        printf("chave -> %s\n",aux->info.palavra);
        printf("classificacão -> %s\n",aux->info.classificacao);
        printf("significado -> %s\n",aux->info.significado);

        aux = aux->next;
    }
    printf("======================== | end | =============================\n\n");
}