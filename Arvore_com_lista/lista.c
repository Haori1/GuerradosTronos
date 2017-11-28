#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/* FUNC 1 --- ALOCA LISTA */

cList* list_create() {

   cList *list = (cList*) malloc ( sizeof ( cList ) );
   list->first = NULL;
   list->last = NULL;

   return list;
}

/* FUNC 2 --- ALOCA ELEMENTO */

cNode* cNode_create ( Character* character ) {

   cNode *node = (cNode*) malloc ( sizeof ( cNode ) );
   node->character = character;
   node->next = NULL;
   node->prev = NULL;

   return node;
}

/* FUNC 3 --- DESALOCA LISTA */

void free_list ( cList *list ) {
   cNode *aux = NULL;

   if ( list->first != NULL ) {

      while ( list->first != NULL ) {

         aux = list->first->next;   /*Guarda endereco do proximo */

         character_free(list->first->character);
         free( list->first );       /*Apaga o atual */
         list->first = aux;         /*Vai pro proximo */
      }

   }

   free( list );

   return;
}

/* FUNC 4 --- ADICIONA ELEMENTO */

void add_cNode ( int pos, Character* character, cList *list ) {
   cNode *node = cNode_create ( character );
   cNode *curr = list->first;
   int ctr = 0;

   /* INICIO DA LISTA */
   if ( pos <= 0 || list->first == NULL ) {

      if ( list->first != NULL ) {

         list->first->prev = node;

      }
      node->next = list->first;
      list->first = node;

      if ( list->last == NULL ) {

      list->last = list->first;

      }

      return;

   }


   /* FIM DA LISTA */

   if ( pos > 0 ) {

      while ( ctr < ( pos ) ) {

         if ( curr->next == NULL ) {

            curr->next = node;
            node->prev = curr;

            return;

         }


         curr = curr->next;
         ctr++;


      }

   /* MEIO DA LISTA */

   curr = curr->prev;
   node->next = curr->next;
   curr->next->prev = node;
   curr->next = node;

   }


   return;
}

/* FUNC 5 --- REMOVE ELEMENTO */

void rem_cNode ( int pos, cList *list ) {
   cNode *curr = list->first;
   int ctr = 0;

   /* INICIO DA LISTA */

   if ( curr == NULL ) {

      return;

   }

   if ( list->first == list->last ) {


      free ( list->first );
      list->first = NULL;
      list->last = NULL;
      return;

   }

   if ( pos <= 0 ) {

      if ( list->first == list->last ) {

         list->first = NULL;
         list->last = NULL;

         free ( curr );
         return;

      } else {

         list->first = curr->next;

         free ( curr );
         return;

      }

   } else {

   /* FIM DA LISTA */

      while ( ctr < ( pos - 1 ) ) {

         if ( curr->next->next == NULL ) {

            list->last = curr;

            free ( curr->next );
            list->last->next = NULL;
            return;

         }

   /* MEIO DA LISTA */

         curr = curr->next;
         ctr++;

      }

      cNode *aux = curr->next;
      curr->next = aux->next;
      aux->next->prev = curr;


      free ( aux );


   }

   return;
}


/* FUNC 6 --- IMPRIME LISTA */

void printList ( cList *list ) {
   cNode *aux = list->first;

   if ( list->first == NULL ) {

      printf("EMPTY LIST\n");

   }

   while ( aux != NULL ) {

      printf( "%s\n", aux->character->name );
      aux = aux->next;

   }

   return;
}

/* FUNCAO 7 --- LIBERA MEMORIA DE PERSONAGEM */

void character_free ( Character *character ) {

   free (character->name);
   free (character->house);
   free (character);

}
