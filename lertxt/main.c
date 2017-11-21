#include "lertxt.h"

int main () {

   int num, *vec = NULL;
   char *vecstr = NULL;
   cList *list;
   FILE *fp;

   fp = fopen ( "personagens.txt", "r" );
   
   list = create_roster ( fp );
   
   printList ( list );
   free_list ( list );
   
   
   fclose ( fp );
   return 0;
}


