#include <stdio.h>

#ifndef TRABRETORNOS_H
#define TRABRETORNOS_H

#define SIZE_CHAR 70

struct DADO
{
    char palavra[SIZE_CHAR];
    char classificacao[SIZE_CHAR];
    char significado[SIZE_CHAR];
};


#define INVALID_OPERATION -2 
#define INVALID_POINTER -1
#define ERROR 0
#define FALSE 0
#define SUCCESS 1
#define OUT_NOT_MEMORY 2
#define OUT_NOT_RANGE 3
#define ELEMENT_NOT_FOUND 4

#endif