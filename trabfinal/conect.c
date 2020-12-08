#include "fila/fifo.h"
#include "lib/Mat2d.h"
#include <stdlib.h>


int rotula_adjacentes (Fila *fi, matriz *img)
{
    if(fi == NULL || img == NULL)
        return INVALID_NULL_POINTER;
    else if(size(img) < 1)
        return OUT_NOT_RANGE;
    else
    {   unsigned char temp;
        for (int i = 0; i < linhas(img); i++)
        {
            for (int j = 0; j < colunas(img); j++)
            {
                matrizGetValue(img, i , j, &temp);
                if(conexos(fi, i, j, temp) == SUCESS)
                {
                    enqueue(fi, i, j, temp);
                }
            }
            
        }
        
    }
    return SUCESS;
}

int preenche (matriz *img_res)
{
    if(img_res == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        for (int i = 0; i < linhas(img_res); i++)
        {
            for (int j = 0; j < colunas(img_res); j++)
            {
                matrizSetValue(img_res, i, j, 0);
            }
            
        }
        return SUCESS;
    }
}

matriz* matrizconexa (matriz *img)
{
    if(img == NULL)
        return NULL;
    else
    {
        Fila *fi = criate_fila(size(img));
        matriz *img_res = allocMatriz(linhas(img), colunas(img));
        if(fi == NULL || img_res == NULL)
            return NULL;
        else
        {
            preenche(img_res);
            unsigned char aux, aux2, temp;
            int rotulo=1, x, y;
            for (int lin = 0; lin < linhas(img); lin++)
            {
                for(int col = 0; col < colunas(img); col++)
                {
                    matrizGetValue(img, lin, col, &aux);
                    matrizGetValue(img_res, lin, col, &aux2);
                    if(aux == '1' && aux2 == 0)// não rotulado
                    {
                        enqueue(fi, lin, col, '1');
                        rotula_adjacentes(fi, img);
                    }
                    if(size(img) > 0)
                        rotulo++;
                    while (empty_queue(fi) != SUCESS )
                    {
                        // pega todos o pixel adjacentes listados e coloca na imagem 2;
                        front_queue(fi, &x, &y, &temp);
                        dequeue(fi);
                        matrizSetValue(img_res, x, y, rotulo);
                    }
                    
                }
            }
            
        }
        freequeue(fi);
        freeMatriz(img);
        return img_res;
    }
}
