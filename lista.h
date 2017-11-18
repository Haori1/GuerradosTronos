#ifndef ___LISTA___
#define ___LISTA___

/* leia o leiame pls */

typedef struct node {

   int data; /* Trocar para o tipo 'character' quando for definido */
   struct node *next;
   struct node *prev;

} cNode;

typedef struct {

   cNode *first;
   cNode *last;

} cList; 

cList* list_create();
cNode* cNode_create ( int dado );
void free_list ( cList *list );
void add_cNode ( int pos, int data, cList *list );
void rem_cNode ( int pos, cList *list );
void printList ( cList *list );

#endif
