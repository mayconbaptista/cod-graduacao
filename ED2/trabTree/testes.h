#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lista/List.h"
#include "arvore/Tree.h"
#include "fila/Fila.h"
#include "dados/gravar.h"


struct DADO vet[12] =       {{"sutil\n", "adjetivo\n", "Característica de fino, delgado: um sutil tecido indiano\n"},
                            {"mitigar\n", "verbo pronomial\n", "Fazer com que fique mais brando\n"},
                            {"elegivel\n", "adjetivo\n", "Que pode ser alvo de eleição\n"},
                            {"eximio\n", "adjetivo\n", "Que revela perfeição em tudo o que faz\n"},
                            {"desfecho\n", "subs masculino\n", "Resolução para um problema, para um momento difícil\n"},
                            {"tribulaçao\n", "adjetivo\n", "Que se enganou\n"},
                            {"desdenhar\n", "verbo\n", "demostrar falta de consideração\n"},
                            {"equivocado\n", "adjetivo\n", "Que foi alvo de equívoco; que confundiu uma coisa por outra\n"},
                            {"discrição\n", "subs feminino\n", "Qualidade de discreto, de quem não quer chamar a atenção\n"},
                            {"explicito\n", "adjetivo\n", "Que é expresso sem dúvidas nem ambiguidades\n"},
                            {"contingente\n", "adjetivo\n", "Que pode ou não ocorrer; incerto, duvidoso\n"},
                            {"critério\n", "subs masculino\n", "Capacidade para distinguir o verdadeiro do falso, o bom do ruim\n"}};


void teste1 (void)
{
    AVL_Tree *tree = constructor_AVL_Tree();

    if(tree != NULL)
    {
        for(int i = 0; i < 12; i++)
        {
            insere_AVL_Tree(tree, vet[i].palavra, vet[i]);
        }

        printf("Exibindo:\n\n");
        exibir_AVL_Tree(tree);

        for(int i = 0; i < 12; i++)
        {
            remove_AVL_Tree (tree, vet[i].palavra);
        }

        printf("Removendo:\n\n");
        exibir_AVL_Tree(tree);
    }
    descructor_AVL_Tree(tree);
} // ordenado

void teste2 (void)
{
    AVL_Tree *tree = constructor_AVL_Tree();

    if(tree != NULL)
    {
        for(int i = 11; i >= 0; i--)
        {
            insere_AVL_Tree(tree, vet[i].palavra, vet[i]);
        }

        printf("exibindo ...\n\n");
        exibir_AVL_Tree(tree);

        for(int i = 11; i >= 0; i--)
        {
            remove_AVL_Tree (tree, vet[i].palavra);
        }

        printf("removendo ...\n\n");
        exibir_AVL_Tree(tree);
    }

    descructor_AVL_Tree(tree);
}// inversamente ordenado 

void testefila1 (void)
{
    FILA *fila = constructor_FILA(); 

    if(fila != NULL)
    {
        for(int i = 0; i < 12; i++)
        {
            push_FILA(fila, vet[i]);
        }

        exibir_FilA(fila);

        if(size_FILA(fila) == 12) printf("tamanho okay\n");

        while(!empty_FILA(fila))
        {
            remove_FILA(fila);
        }

        if(empty_FILA(fila)) printf("vazia!\n");
        
        destructor_FILA(fila);
    }
}

void testefila2 (void)
{
    FILA *fila = constructor_FILA(); 

    if(fila != NULL)
    {
        for(int i = 0; i < 12; i++)
        {
            push_FILA(fila, vet[i]);
        }

        struct DADO aux;

        while(!empty_FILA(fila))
        {
            aux = front_FILA(fila);

            printf("%s\n",aux.palavra);
            remove_FILA(fila);
        }

        destructor_FILA(fila);
    }
}

void testeRead ()
{
    AVL_Tree *Tree = constructor_AVL_Tree();
    TADList *list = constructor_TADList();

    if(Tree != NULL)
    {
        read_dictionary (Tree, list);
        exibir_AVL_Tree(Tree);
        print_TADList(list);

        write_dictionary_pre(Tree);
        write_dictionary_in(Tree);
        write_dictionary_pos(Tree);

        descructor_AVL_Tree(Tree);
        desctructor_TADList(list);
    }
}

void testelists (void)
{
    TADList *list = constructor_TADList();

    if(list != NULL)
    {
        printf ("inicio incerção\n");

        for(int i = 0; i < 12; i++)
        {
            if(insert_TADList(list, vet[i]) != 1) printf("%d error\n",i + 1);
        }

        print_TADList(list);

        for(int i = 0; i < 12; i++)
        {
            if(remove_TADList(list, vet[i].palavra) != 1) printf("%d error\n",i + 1);
        }
        
        print_TADList(list);
        desctructor_TADList(list);
    }
}

void testelists2 (void)
{
    TADList *list = constructor_TADList();

    if(list != NULL)
    {
        printf ("inicio incerção\n");

        for(int i = 11; i >= 0; i--)
        {
            if(insert_TADList(list, vet[i]) != 1) printf("%d error\n",i + 1);
        }

        print_TADList(list);

        for(int i = 11; i >= 0; i--)
        {
            if(remove_TADList(list, vet[i].palavra) != 1) printf("%d error\n",i + 1);
        }

        print_TADList(list);

        desctructor_TADList(list);
    }
}

void testelists3 (void) // random
{
    TADList *list = constructor_TADList();

    if(list != NULL)
    {
        printf ("inicio incerção\n");
        srand(time(NULL));
        int aux;
        for(int i = 0; i < 12; i++)
        {
            aux = rand() % 12;

            if(insert_TADList(list, vet[aux]) != 1) printf("%d error\n", aux);
        }

        printf("tamanho da lista %d\n",size_TADList(list));
        print_TADList(list);
        srand(time(NULL));

        for(int i = 0; i < 12; i++)
        {
            aux = rand() % 12;
            printf("----------------------|| Removendo o %s",vet[aux].palavra);
            
            if(remove_TADList(list, vet[aux].palavra) == -2) printf("%d error\n",aux);
            print_TADList(list);
            printf("tamanho da lista %d\n",size_TADList(list));
            getchar();
        }

        desctructor_TADList(list);
    }
}