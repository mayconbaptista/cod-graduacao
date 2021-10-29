
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"

int menuGrafoSimplesMAD (void);
void Tratamento_de_erros (int cod_erro);
void menu_funcoes (GrafoS *grf);


int main (void)
{
    GrafoS *grf = NULL;

    menu_funcoes(grf);

    libera_grafoAD(grf);
    return 0;
}
// funçoes aux

int menuGrafoSimplesMAD (void)
{
    system("clear");
    printf("\n ========================Menu Principal========================\n");
    printf("1 - Cria grafo - Matriz de adjacencia\n");
    printf("2 - Insere Aresta\n");
    printf("3 - Remove Aresta\n");
    printf("4 - imprime na forma de Matriz de adjacencia\n");
    printf("5 - imprime na forma de Lista de incidencia\n");
    printf("6 - busca em largura\n");
    printf("0 - sair\n");
    printf("Opção: ");
    int opc;
    scanf("%d",&opc);

    while(opc < 0 || opc > 5)
    {
        printf("Opção %d escolhida e inválida por favor entre com uma válida: ",opc);
        scanf("%d",&opc);
    }
    return opc;
}

void menu_funcoes (GrafoS *grf)
{
    int v1, v2;
    int erro, opc;
    do{
        opc = menuGrafoSimplesMAD();
    
        switch (opc)
        {
        case 1:
        {
            printf("Entre com o numero de vertices: ");
            int vertices;
            scanf("%d",&vertices);
            printf("O grafo for Direcionado (1-s/0-n) ? : ");
            int direcionado;
            scanf("%d",&direcionado);
            printf("O grafo e valorado? (1-s/0-n) ?: ");
            int valorado;
            scanf("%d",&valorado);
            grf = cria_grafoAD(vertices, direcionado, valorado);

            if(grf != NULL)
                printf("Operação concluida com sucesso\n");
            else
                printf("Operação concluida com exito\n");
        }
            break;

        case 2:
            while(true)
            {
                printf("++++++++++++++++++++++++\n");
                printf("Entre com a numeração dos dois vertes que deseja ligar: ");
                scanf("%d %d",&v1, &v2);

                erro = insereArestaAD(grf, v1, v2, 1);
                Tratamento_de_erros (erro);

                printf("Deseja inserir mais arestas (1-S/0-N) ?: ");
                int opc2;
                scanf("%d",&opc2);
                if(opc2 != 1)
                    break;
            }
            break;

        case 3:
            while(true)
            {
                printf("+++++++++++++++++++++++++++\n");
                printf("Entre com com dois vertices que deseja remover a aresta: ");
                scanf("%d %d",&v1, &v2);

                erro = remove_ArestaAD(grf, v1, v2);
                Tratamento_de_erros (erro);

                printf("Deseja inserir mais arestas (1-S/0-N) ?: ");
                int opc2;
                scanf("%d",&opc2);
                if(opc2 != 1)
                    break;
            }        
            break;

        case 4:
            exibir_matrizAD(grf);
            printf("Digite qualquer tecla para continuar...");
            setbuf(stdin, NULL);
            getchar (); // pause para visualizar
            break;

        case 5:
            imprime_listaAD(grf);
            printf("Digite qualquer tecla para continuar...");
            setbuf(stdin, NULL);
            getchar(); // pausa para visualisar
            break;

        case 6:
            printf("Entre com vertice que deseja ");

        default:
            break;
        }

    }while(opc != 0);

    return;
}

void Tratamento_de_erros (int cod_erro)
{
    switch (cod_erro)
    {
    case 1:
        printf("Operação concluida com sucesso\n");
        break;
    case 0:
        printf("Erro operação invadida");
        break;

    case -1:
        printf("Ponteiro Invalido\n");
        break;

    case -2:
        printf("Memoria Indisponivel\n");
        break;
    case -3:
        printf("Fora do alcanse\n");
        break;

    default:
        break;
    }
}