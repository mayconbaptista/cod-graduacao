#include "fifo.h"
#include <stdlib.h>


struct FIFO
{
    struct pixel *data;
    int size;
    int MAX;
};

Fila* criate_fila (int tamanho)
{
    Fila *Fi = (Fila*) malloc (sizeof(Fila));
    if(Fi != NULL)
    {
        Fi->data = (struct pixel*) malloc (tamanho*sizeof(struct pixel));
        if(Fi->data == NULL)
        {
            free(Fi);
            return NULL;
        }
        else
        {
            Fi->MAX = tamanho;
            Fi->size=0;
        }
    }
    return Fi;
}

void freequeue(Fila *fi)
{
    free(fi->data);
    free(fi);
}

int enqueue (Fila *Fi,int cordx, int cordy, unsigned char vlr)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->size == Fi->size)
        return OUT_NOT_RANGE;
    else
    {
        Fi->data[Fi->size].let = vlr;
        Fi->data[Fi->size].x = cordx;
        Fi->data[Fi->size].y = cordy;
        Fi->size++;
        return SUCESS;
    }
}

int dequeue (Fila *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        for (int i = 0; i < Fi->size; i++)
        {
            Fi->data[i] = Fi->data[i+1];
        }
        
        Fi->size--;
        return SUCESS;
    }
}

int front_queue (Fila *fi, int *lin, int *col, unsigned char *let)
{
    if(fi == NULL)
        return INVALID_NULL_POINTER;
    else if(fi->size == 0)
        return OUT_NOT_RANGE;
    else
    {
        (*let) = fi->data[0].let;
        (*lin) = fi->data[0].x;
        (*col) = fi->data[0].y;
        return SUCESS;
    }
}

int full_queue (Fila *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->size == Fi->MAX)
        return SUCESS;
    else
        return OUT_NOT_RANGE;
}

int empty_queue (Fila *Fi)
{
    if(Fi == NULL)
        return INVALID_NULL_POINTER;
    else if(Fi->size == 0)
        return SUCESS;
    else
        return OUT_NOT_RANGE;
}

int conexos (Fila *Fi, int cordx, int cordy, unsigned char vlr)
{
    if(Fi == 0)
        return INVALID_NULL_POINTER;
    else
    {
        int i=0;
        while(i < Fi->size)
        {
            if(cordx == Fi->data[i].x && cordy == Fi->data[i].y && Fi->data[i].let == vlr)
                return OUT_NOT_RANGE;
            else if(cordx+1 == Fi->data[i].x && cordy == Fi->data[i].y && Fi->data[i].let == vlr)
                break;
            else if(cordx == Fi->data[i].x && cordy+1 == Fi->data[i].y && Fi->data[i].let == vlr)
                break;
            else if(cordx-1 == Fi->data[i].x && cordy == Fi->data[i].y && Fi->data[i].let == vlr)
                break;
            else if(cordx == Fi->data[i].x && cordy-1 == Fi->data[i].y && Fi->data[i].let == vlr)
                break;
            else
                i++;
        }
        if(i < Fi->size)
            return SUCESS;
        else
            return OUT_NOT_RANGE;
    }
}