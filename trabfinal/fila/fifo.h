#ifndef TRABLIST_H
#define TRABLIST_H

#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_NOT_RANGE -2

struct pixel
{
    unsigned char let;
    int x;
    int y;
};

typedef struct FIFO Fila;

Fila* criate_fila (int tamanho);

void freequeue(Fila *fi);

int enqueue (Fila *Fi,int cordx, int cordy, unsigned char vlr);

int dequeue (Fila *Fi);

int full_queue (Fila *Fi);

int empty_queue (Fila *Fi);

int conexos (Fila *Fi, int cordx, int cordy, unsigned char vlr);

int front_queue (Fila *fi, int *lin, int *col, unsigned char *let);

typedef struct FIFO Fila;

#endif