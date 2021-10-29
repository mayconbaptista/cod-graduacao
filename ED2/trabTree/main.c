#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "Retornos.h"
#include "lista/List.h"
#include "arvore/Tree.h"
#include "dados/gravar.h"
#include "testes.h"

void exibir_dado (const struct DADO *dado)
{
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("chave: %s",dado->palavra);
    printf("class: %s",dado->classificacao);
    printf("signi: %s",dado->significado);
} 

int menu_principal (void)
{
    system("clear");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>> MENU <<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("1 - Atualizer dicionarios (lista & avl)\n");
    printf("2 - busca (avl)\n");
    printf("3 - coparar tempos de busca da avl e da lista\n");
    printf("4 - Insert nova paravla (lista & avl)\n");
    printf("5 - remover uma palavra (lista & avl)\n");
    printf("6 - exibir todos os significados de uma frase (avl)\n");
    printf("7 - exibir relátorio\n");
    printf("8 -  salvar em txt\n");
    printf("9 - imprime (avl & list)\n");
    printf("0 - sair\n");
    printf("entre com uma opção: ");

    int opc = 0;
    scanf("%d",&opc);
    return opc;
}

void tratamento(int resposta)
{
    switch (resposta)
    {
    case -2:
        printf("Operação invalida não existe ou uso incorreto\n");
        break;
    case -1:
        printf("Ponteiro para TAD invalido!\n");
        break;
    case 0:
        printf("False ou error!\n");
        break;
    case 1:
        printf("Operação finalizada com sucesso\n");
        break;
    case 2:
        printf("Falta de memoria\n");
        break;
    case 3:
        printf("Não encontrado!\n");
        break;
    default:
        break;
    }
}

void func2 (const AVL_Tree *tree)
{
    struct DADO dado;

    printf("Entre com a palavra que deseja buscar: ");
    setbuf(stdin, NULL);
    fgets(dado.palavra, SIZE_CHAR, stdin);
    dado = busca_AVL_Tree(tree, dado.palavra);
    exibir_dado(&dado);
}

void func3 (const AVL_Tree *tree, const TADList *list)
{
    struct DADO dado;

    printf("entre com a chave que deseja buscar: ");
    setbuf(stdin, NULL);
    fgets(dado.palavra, SIZE_CHAR, stdin);

    clock_t inicio = clock();
    dado = busca_AVL_Tree(tree, dado.palavra);
    clock_t fim = clock();

    double tempo_tree = (double) (fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo gasto na busca pela arvore: %lf\n",tempo_tree);
    exibir_dado(&dado);

    inicio = clock();
    dado = busca_list(list, dado.palavra);
    fim = clock(); 

    double tempo_list = (double) (fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo gasto na busca pela arvore: %lf\n",tempo_list);
    exibir_dado(&dado);
}

void func4 (AVL_Tree *tree, TADList *list)
{
    struct DADO dado;

    printf("Entre com a palavra que deseja inserir: ");
    setbuf(stdin, NULL);
    fgets(dado.palavra, SIZE_CHAR, stdin);

    printf("Entre com a classificação: ");
    setbuf(stdin, NULL);
    fgets(dado.classificacao, SIZE_CHAR, stdin);

    printf("Entre com o signicado: ");
    setbuf(stdin, NULL);
    fgets(dado.significado, SIZE_CHAR, stdin);

    tratamento(insere_AVL_Tree(tree, dado.palavra, dado));
                
    tratamento(insert_TADList(list, dado));
}

void func5 (AVL_Tree *tree, TADList *list)
{
    struct DADO dado;

    printf("entre com a chave que deseja remover: ");
    setbuf(stdin, NULL);
    fgets(dado.palavra, SIZE_CHAR, stdin);

    tratamento( remove_AVL_Tree(tree, dado.palavra));

    tratamento( remove_TADList(list, dado.palavra));
}

void func6 (AVL_Tree *tree)
{
    printf("enre com a frase: ");
    setbuf(stdin, NULL);

    char frase[100], palavra[SIZE_CHAR];
    struct DADO aux;

    fgets(frase, 100, stdin);

    for(int i = 0, j = 0; i < strlen(frase); i++)
    {
        if(isalpha(frase[i]))
        {
            palavra[j++] = frase[i];
        }
        else if(frase[i] == '\0')
            break;
        else if(frase[i] == ' ' || frase[i] == '\n')
        {
            palavra[j++] = '\n';
            palavra[j] = '\0';
            j = 0;

            aux = busca_AVL_Tree(tree, palavra);

            printf("\n\nResultado para %s",palavra);
            exibir_dado(&aux);
        }
    }
}// okay

void func8 (const AVL_Tree *tree)
{
    int resposta = 0, temp = 0;
    printf("(1-pre| 2-in| 3-pos) entre com a forma que deseja salvar: ");
    scanf("%d",&temp);

    if(temp == 1)
    {
        resposta = write_dictionary_pre(tree);
    }
    else if(temp == 2)
    {
        resposta = write_dictionary_in(tree);
    }
    else if(temp == 3)
    {
        resposta = write_dictionary_pos(tree);
    }
    else
    {
        printf("Opção invalida!\n");
        return;
    }

    tratamento(resposta);
}

int main (void)
{
    AVL_Tree *tree = constructor_AVL_Tree();
    TADList *list = constructor_TADList();

    if(tree != NULL && list != NULL)
    {
        int resposta = 0, opc = 0;
        do
        {
            opc = menu_principal();

            switch (opc)
            { 
            case 1:
                resposta = read_dictionary(tree, list);
                tratamento(resposta);
                break;

            case 2:
                func2 (tree);
                break;

            case 3:
                func3(tree, list);
                break;

            case 4:
                func4(tree, list);
                break;

            case 5:
                func5 (tree, list);
                break;

            case 6:
                func6(tree);
                break;

            case 7:
                printf("ainda falta\n");
                break;

            case 8:
                func8 (tree);
                break;
                
            case 9:
                exibir_AVL_Tree(tree);
                print_TADList(list);
                break;

            case 0:
                continue;
            
            default:
                printf("Entre com uma opção valida!\n");
                break;
            }

            setbuf(stdin, NULL);
            printf("press to continue... ");
            getchar();

        }while (opc != 0);
        
        descructor_AVL_Tree(tree);
        desctructor_TADList(list);
    }
    return 0;
}
