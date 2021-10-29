
#ifndef TADAVLTREE_H
#define TADAVLTREE_H

#define INVALID_OPERATION -4
#define OUT_NOT_MEMORY -3
#define ELEMENT_NOT_FOUND -2
#define INVALID_POINTER -1
#define EXISTING_ELEMENT 0
#define SUCCESS 1

typedef struct AVL_Tree AVL_Tree;

AVL_Tree* constructor_AVL_tree (void);

void destructor_AVL_Tree (AVL_Tree *tree);

#endif