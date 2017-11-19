#ifndef ___LISTA___
#define ___LISTA___

/* leia o leiame pls */

typedef struct {
    char* name;
    char* house;
    int agility;
    int strength;
    int intelligence;
    int health;
} Character;

typedef struct node {

   Character* character;
   struct node *next;
   struct node *prev;

} cNode;

typedef struct {

   cNode *first;
   cNode *last;

} cList;

cList* list_create();
cNode* cNode_create ( Character* character );
void free_list ( cList *list );
void add_cNode ( int pos, Character* character, cList *list );
void rem_cNode ( int pos, cList *list );
void printList ( cList *list );

#endif
