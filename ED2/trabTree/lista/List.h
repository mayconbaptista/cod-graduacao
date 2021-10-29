#include "../Retornos.h"

#ifndef TADLISTDICTIONARY
#define TADLISTDICTIONARY

typedef struct TADList TADList;

void clear_List (struct TADList *list);

void desctructor_TADList (struct TADList *list);

struct TADList* constructor_TADList (void);

int insert_TADList(struct TADList *list, struct DADO info);

struct DADO busca_list (const TADList *list, char chave[]);

void print_TADList(struct TADList *list);

int empty_TADList(struct TADList* list);

int size_TADList (struct TADList *list);

int remove_TADList(struct TADList *list, char chave[]);

#endif

