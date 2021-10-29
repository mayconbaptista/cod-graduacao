#include "gravar.h"
#include <stdio.h>

// +++++++++++++++++++++++++++++++++++++++++++ função de leitura
int read_dictionary (AVL_Tree *Tree, TADList *list)
{
    if(Tree == NULL || list == NULL) return INVALID_POINTER;

    FILE *arg = fopen("dados/dados.txt", "r");

    if(arg == NULL) return ERROR;

    struct DADO aux;
    char lixo[3];

    while(!feof(arg))
    {
        fgets(aux.palavra, SIZE_CHAR, arg);
        fgets(aux.classificacao, SIZE_CHAR, arg);
        fgets(aux.significado, SIZE_CHAR, arg);
        fgets(lixo, 3, arg);

        insere_AVL_Tree(Tree, aux.palavra, aux);
        insert_TADList(list, aux);
    }

    fclose(arg);
    return SUCCESS;
}

// ++++++++++++++++++++++++++++++++++++++++++++ função de escrita pre

int write_dictionary_pre (const AVL_Tree *tree)
{
    if(tree == NULL) return INVALID_POINTER;

    FILA *fila = constructor_FILA();

    if(fila == NULL ) return ERROR;

    FILE *arg = fopen("dados/preOrdem.txt", "w");

    if(arg == NULL) return ERROR;

    pre_ordem_AVL (tree, fila);

    while(!empty_FILA(fila))
    {

        fprintf(arg, "%s", front_FILA(fila).palavra);
        fprintf(arg, "%s", front_FILA(fila).classificacao);
        fprintf(arg, "%s", front_FILA(fila).significado);

        fprintf(arg, "%s\n", "&");

        remove_FILA(fila);
    }
    fprintf(arg, "%s", "FIM");

    destructor_FILA(fila);
    fclose(arg);
    return SUCCESS;
}

int write_dictionary_in (const AVL_Tree *tree)
{
    if(tree == NULL) return INVALID_POINTER;

    FILA *fila = constructor_FILA();

    if(fila == NULL ) return ERROR;

    FILE *arg = fopen("dados/inOrdem.txt", "w");

    if(arg == NULL) return ERROR;

    in_ordem_AVL(tree, fila);

    while(!empty_FILA(fila))
    {

        fprintf(arg, "%s", front_FILA(fila).palavra);
        fprintf(arg, "%s", front_FILA(fila).classificacao);
        fprintf(arg, "%s", front_FILA(fila).significado);

        fprintf(arg, "%s\n", "&");

        remove_FILA(fila);
    }
    fprintf(arg, "%s", "FIM");

    destructor_FILA(fila);
    fclose(arg);
    return SUCCESS;
}


int write_dictionary_pos (const AVL_Tree *tree)
{
    if(tree == NULL) return INVALID_POINTER;

    FILA *fila = constructor_FILA();

    if(fila == NULL ) return ERROR;

    FILE *arg = fopen("dados/posOrdem.txt", "w");

    if(arg == NULL) return ERROR;

    pos_ordem_AVL (tree, fila);

    while(!empty_FILA(fila))
    {

        fprintf(arg, "%s", front_FILA(fila).palavra);
        fprintf(arg, "%s", front_FILA(fila).classificacao);
        fprintf(arg, "%s", front_FILA(fila).significado);

        fprintf(arg, "%s\n", "&");

        remove_FILA(fila);
    }
    fprintf(arg, "%s", "FIM");

    destructor_FILA(fila);
    fclose(arg);
    return SUCCESS;
}