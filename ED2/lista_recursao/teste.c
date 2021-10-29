#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int menor_vet (int *vet, int n)
{
    if(n == 0)
        return vet[n];
    else
    {
        if(vet[n] < vet[n-1])
        {
            vet[n - 1] = vet[n];
        }
        menor_vet(vet, n -1);
    }
}// exe 33 - okay

int auxiliar33 (void)
{
    printf("entre com tamanho do vetor: ");
    int n;
    scanf("%d",&n);

    int vet[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d ",&vet[i]);
    }
    printf("o menor é %d\n",menor_vet(vet, n)); 
    return 0;
}// lendo um num a mais

int free_liberaEcolocaNulo (void)
{
    int *vet = (int*)  malloc (5*sizeof(int));

    if(vet != NULL)
    {
        printf("alocado ! ");

        free(vet);
        if(vet == NULL)
            printf("Sim coloca nulo\n");
        else
            printf("Não, não coloca nulo\n");
    }
    return 0;
}