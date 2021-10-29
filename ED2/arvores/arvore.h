

#ifndef TADSTREES_H
#define TADSTREES_H

#define INVALID_OPERATION -4
#define OUT_NOT_MEMORY -3
#define ELEMENT_NOT_FOUND -2
#define INVALID_POINTER -1
#define EXISTING_ELEMENT 0
#define SUCCESS 1

typedef struct BIN_SEARCH_TREE BIN_SEARCH_TREE;


BIN_SEARCH_TREE* constructor_BST (void);

void destructor_BST (BIN_SEARCH_TREE *tree);

int insert_BST (BIN_SEARCH_TREE *tree, int key, char *nome);

char* search_BTS (BIN_SEARCH_TREE *tree, int key);

int remove_BTS (BIN_SEARCH_TREE *tree, int key);

void BST_pre_order (BIN_SEARCH_TREE *tree);

void BST_in_order (BIN_SEARCH_TREE *tree);

void BST_pos_order (BIN_SEARCH_TREE *tree);

void clear_BTS (BIN_SEARCH_TREE *tree);


// funçoes da lista de exe
int num_nos (BIN_SEARCH_TREE *tree); // exe
int num_nos_nao_folhas (BIN_SEARCH_TREE *tree); // exe

#endif