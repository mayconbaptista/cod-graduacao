#include "../Retornos.h"
#ifndef TRABFILADICTIONARY_H
#define TRABFILADICTIONARY_H


typedef struct FILA FILA;

FILA* constructor_FILA (void);

void clear_FILA (FILA *Fila);

void destructor_FILA (FILA *Fila);

int push_FILA (FILA *Fila, struct DADO dado);

int remove_FILA (FILA *Fila);

struct DADO front_FILA (FILA *Fila);

int empty_FILA (FILA *Fila);

int size_FILA (FILA *Fila);

void exibir_FilA(FILA *Fila);

#endif