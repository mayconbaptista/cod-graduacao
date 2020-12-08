#include "Mat2d.h"
#include <stdio.h>

struct matriz{
  int col;
  int row;
  unsigned char *data;
};

matriz* allocMatriz(int i, int j){
  if(i<=0||j<=0)return NULL;
  matriz *m;
  m = (matriz*)malloc(sizeof(matriz));
  m->row=i;
  if(m==NULL)return NULL;
  m->col=j;
  m->data = malloc(sizeof(unsigned char)*i*j);
  if(m->data==NULL){
    free(m);
    return NULL;
  }
  return m;
}

void freeMatriz(matriz* m){
  free(m->data);
  free(m);
}

int matrizSetValue(matriz *m,int i,int j,unsigned char n){
  if(i>m->row||i<0||j>m->col||j<0)return -1;
  if(m==NULL)return -1;
  if(m->data == NULL)return -1;
  m->data[j*m->row+i]=n;
  return 0;
}

int matrizGetValue(matriz *m,int i,int j,unsigned char *n){
  if(i<0||j<0||j>=m->col||i>=m->row)return -1;
  if(m==NULL)return -1;
  if(m->data == NULL)return -1;
  *n = m->data[j*m->row+i];
  return 0;
}

int linhas(matriz *m){
  if(m==NULL)return -1;
  return m->row;
}

int colunas(matriz *m){
  if(m==NULL)return -1;
  return m->col;
}

int size (matriz *m)
{
  if(m == NULL)
    return -1;
  else
    return (m->row * m->col);
}

unsigned char pontos (matriz *m, int i, int j)
{
  if(m == NULL)
    return '0';
  else if(i < 0 || j < 0 || i >= m->row || j >= m->col)
    return '0';
  else
  {
    return m->data[j*m->row+i];
  }
}

void print_matriz (matriz *img)
{
  if(img != NULL)
    {
      for (int i = 0; i < img->row; i++)
      {
        for (int j = 0; j < img->col ; j++)
        {
          printf("%3d ",img->data[i]);
        }
        printf("\n");
      }

    }
  return;
}