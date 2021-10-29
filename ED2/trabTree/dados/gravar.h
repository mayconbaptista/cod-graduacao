#include "../Retornos.h"
#include "../fila/Fila.h"
#include "../arvore/Tree.h"
#include "../lista/List.h"

#ifndef TRABGRAVARDICTIONARY_H
#define TRABGRAVARDICTIONARY_H

int read_dictionary (AVL_Tree *Tree, TADList *list);

int write_dictionary_pre (const AVL_Tree *tree);

int write_dictionary_in (const AVL_Tree *tree);

int write_dictionary_pos (const AVL_Tree *tree);

#endif