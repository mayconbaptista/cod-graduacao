#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int fat (int n)
{
    if(n <= 1)
        return 1;
    else
        return n * fat (n - 1);
}// exercicio 1 - okay

int fibonacci (int n)
{
    if(n == 1)
        return 1;
    else if(n < 1)
        return 0;
    else
        return fibonacci (n - 1) + fibonacci (n -2);
}// exercicio 2 - okay!

int inverte (int n)
{

}// exercicio 3

int soma_recursiva (int *vet, int n)
{
    if(n < 1)
        return 0;
    else
        return vet[n - 1] + soma_recursiva(vet, n - 1);
}// exercicio 4 - okay!

int soma_ate (int n)
{
    if(n <= 0)
        return 0;
    else
        return n + soma_ate (n -1);
}// exercicio 5 - okay!

int pow_recursivo (int base,int potencia)
{
    if(potencia < 2)
        return base;
    else
        return base * pow_recursivo (base, potencia -1);
}// exercicio 6 - okay!

int* inverteVet (int *vet, int inicio, int final)
{
    if(inicio >= final)
        return vet;
    else
    {
        int temp = vet[inicio];
        vet[inicio] = vet[final];
        vet[final] = temp;
        inverteVet(vet, inicio+1, final-1);
    }
}// exe 7 - okay testado!

int mdc (int x, int y)
{
    if(y == 0)
        return x;
    else
        return mdc (x, y % x);
}// exe 8 - com bug !

// o exercicio 9 e igual ao 5

int ocorrencias (int num, int k)
{
    if(num == 0)
        return 0;
    else
    {
        int resto = num % 10;
        num = num / 10;
        if(resto == k)
            return 1 + ocorrencias(num, k);
        else
            return 0 + ocorrencias(num, k);
    }
}// exe 10 - okay testado

int mult_rescursivo (int num, int k)
{
    if(k < 1)
        return 0;
    else
        return num + mult_rescursivo(num, k - 1);
}// exe 11 - Okay!

void print_cres_recursivo (int num)
{
    if(num == 1)
        printf("%d ",num);
    else
    {
        print_cres_recursivo(num - 1);
        printf("%d ",num);
    }
}// exe 12 - Okay!

void print_decr_recursivo (int num)
{
    if(num == 1)
        printf("%d ",num);
    else
    {
        printf("%d ",num);
        print_decr_recursivo(num -1);
    }
}// exe 13 - Okay!

void print_parcres_recursivo (int num)
{
    if(num == 0)
        printf("%d ",num);
    else
    {
        print_parcres_recursivo(num - 1);
        if (num % 2 == 0)
            printf("%d ",num);
    }
}// exe 14 - Okay!

void print_pardecr_recursivo (int num)
{
    if(num == 0)
        printf("%d ",num);
    else
    {
        if (num % 2 == 0)
            printf("%d ",num);
        print_pardecr_recursivo(num - 1);
    }
}// exe 15 - Okay!

int fat_duplo (int num)
{
    if(num <= 1)
        return 1;
    else
    {
        if(num % 2 != 0)
            return num * fat_duplo(num - 2);
        else
            return 1 * fat_duplo(num - 1);
    }
}// exe 16 - Okay!

int fat_quadruplo (int n)
{

}// exe 17 - tenho a minima ideia de como fazer!

int super_fat (int n)
{
    if(n < 1)
        return 1;
    else
        return fat(n)* super_fat(n -1);
}// exe 19 - testado parece okay falta dados para teste!

int hiper_fat (int n)
{
    if(n < 1)
        return 1;
    else
        return pow_recursivo(n, n) * hiper_fat(n -1);
}// exe 19 - okay testado!

int fat_exp (int n)
{

}// exe 20 - socorro! ainda não sei como fazer

int tribonacci (int n)
{
    if(n <= 1)
        return 0;
    else if(n == 2)
        return 1;
    else
    {
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
}// exe 21 - okay testado!

int tetranacci (int n)
{
    if(n <= 1)
        return 0;
    else if(n == 2)
        return 1;
    else if(n == 3)
        return 2;
    else
    {
        return tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
    }
}// exe 22 - okay testado!

int seg_padovan (int n)
{
    if(n == 0 || n == 1 || n == 2)
        return 1;
    else
        return seg_padovan(n - 2) + seg_padovan(n - 3);
}// exe 23- okay testado!

int pell (int n)
{
    if(n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return 2 * pell(n - 1) + pell(n - 2);
}// exe 24 - oky testado!

int catalan (int n)
{
    if(n == 0)
        return 1;
    else
        return ((2 *(2 *n - 1))/ (n + 1)) * catalan(n - 1);
}// exe 25 - erro não sei onde! 

char* fiboString (int n)
{
    if(n == 0)
        return 'b';
    else if(n == 1)
        return 'a';
    else
    {
        return strcat(fiboString(n - 1), fiboString(n - 2)); 
    }
}// exe 26 - não sei como fazer

void print_bin (int n)
{
    if(n == 0)
        printf("%d",n);
    else
    {
        print_bin (n / 10);
        printf("%d",n % 10);
    }
}// exe 27.a) não sei se erra isso mesmo! 

void print_bin (int n)
{
    if(n == 0)
        printf("%d",n);
    else
    {
        print_bin (n / 10);
        printf("%d",n % 10);
    }
}// exe 27.a) não sei se erra isso mesmo! 

int mult (int a, int b)
{
    if(b == 1)
        return a;
    else
        return a + mult(a, b - 1);
}// exe 27.b) so funciona para numeros positivos! :(

char* inverteSTR (char *str,int inicio, int fim)
{
    if(inicio >= fim)
        return str;
    else
    {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;

        inverteSTR(str, inicio + 1, fim - 1);
    }
}// exe 27.c error!

bool palindromo (char *str, int inicio, int fim)
{
    if(inicio >= fim)
        return true;
    else
    {
        if(str[inicio] == str[fim])
            return palindromo(str, inicio + 1, fim - 1);
        else
            return false;
    }
}// exe 27.e okay testado!

int busca_linearResc (int vet[],unsigned int pos, unsigned int fim,int chave)
{
    if(pos >= fim)
        return -1;// não encontrado
    else
    {
        if(chave == vet[pos])
            return pos;// encontrado
        else
            return busca_linearResc(vet, pos + 1, fim, chave);// recursão de calda
    }
}// exe 27.f não era p fazer assim!

int aga (int m, int n)
{
    if(n == 1)
        return m + 1;
    else if(m == 1)
        return m + 1;
    else
        return aga(m, n-1) + aga (m-1, n);
}// exe 29 parece okay!

int eme (int m, int n)
{
    if(m == 0)
        return n + 1;
    else if(m > 0 && n == 0)
        return eme(m - 1, 1);
    else if(m > 0 && n > 0)
        return eme(m - 1, eme(m, n - 1));
    else
        return 0;
}// exe 30 - não sei o que ta acontecendo!

int somaSerie (int i, int j, int k)
{
    if(i == j)
        return i + k;
    else
    {
        return i+k+ somaSerie(i + 1, j, k);
    }
}// exe 31 - okay testado!

double exe32 (int n)
{
    if(n < 2)
        return 2;
    else
        return ((1 + (n * n)) / n) + exe32(n - 1);
}// exe 32 - com algum bug ! com entrada 2 deveria sair 4,5 mais ta saindo 4

void print_vet (int *vet, int n)
{
    if(n == 0)
        printf("%d ",vet[n]);
    else
    {
        print_vet (vet, n - 1);
        printf("%d ",vet[n]);
    }
}// exe 32 part 2 - okay testado enviar o vetor com - 1 posição

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

int main (void)
{
    int n;
    scanf("%d",&n);
    printf("fibonacci de %d é %d\n",n,fibonacci(n));
    return 0;
}