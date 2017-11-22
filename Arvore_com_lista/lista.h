#ifndef __TIPO__CHARACTER_
#define __TIPO__CHARACTER_

typedef struct {

   char *name;
   char *house;

   int agility;     /* Valores de 0 a 100 */
   int strength;
   int intelligence;
   int health;

} Character;

#endif

#ifndef ___LISTA___
#define ___LISTA___

/* leia o leiame pls */

typedef struct nodeq {

   Character* character;
   struct nodeq *next;
   struct nodeq *prev;

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
void character_free ( Character *character );

#endif
