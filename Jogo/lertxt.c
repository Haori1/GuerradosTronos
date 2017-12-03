#include "lertxt.h"

/*-----------------------------------------------------------------------------------*/

int character_number( FILE *fp, int num, char cur ) {

   while ( cur != EOF ) {   /*End of file*/

      cur = fgetc ( fp );
      if ( cur == 012 ) {  /* ASCII 012 == newline */

         num++;

      }

   }

   return num;
}

/*-----------------------------------------------------------------------------------*/

int* lucky_sixteen( int num ) {

   srand ( time ( NULL ) );   /* Define a semente a ser usada */

   int *vec = ( int * ) malloc ( 16 * (sizeof ( int ) ) ),
        ctra = 0, ctrb = 0, numb = 0                      ;

   while ( ctrb < 16 ) {   /* Garante que nao tenha nenhum lixo no vetor */

      vec[ctrb] = -1;
      ctrb++;

   }
   ctrb = 0;

   while ( ctra < 16 ) {

      numb = ( rand() % ( num + 1 ) ) ;
      while ( ctrb < 16 ) {

         if ( vec[ctrb] == numb ) {             /*Se o número sorteado for igual o número do vetor, valor sorteado não é inserido no vetor*/
            break;
         } else {
            ctrb++;
         }

      }
      if ( ctrb == 16 ) {                       /*Quando o vetor chega ao final e não há números repetidos o número é colocado no vetor e a posição do vetor é incrementada*/
         vec[ctra] = numb;
         ctra++;
      }
      ctrb = 0;
   }

   return vec;
}

/*-----------------------------------------------------------------------------------*/

char* string_read ( FILE *fp ) {

   fpos_t pos;
   int tam = 0, ctr = 0;

   fgetpos ( fp, &pos );                /*Salva a posição do cursor dentro do arquivo*/
   while ( fgetc ( fp ) != 054 ) { /* ASCII 054 == virgula */   /*Conta o numero de letras ate a virgula*/

      tam++;

   }
   char *vec = ( char * ) malloc ( ( tam + 1 ) * sizeof ( char ) );
   vec[tam] = 000; /* ASCII 000 == NULL */  // possível erro para a função de buscar o personagem na árvore
   fsetpos ( fp, &pos );

   while ( ctr < tam ) {

      vec[ctr] = fgetc ( fp );
      ctr++;

   }
   fseek ( fp, 2, SEEK_CUR ); /* Avanca o cursor duas posicoes, 'engolindo' a virgula e o espaco que vem a seguir. */ /*Pula 2 bytes, espaço e vírgula*/


   return vec;
}

/*-----------------------------------------------------------------------------------*/

void line_locate ( FILE *fp, int line ) {

      int ctr = 1;

      rewind ( fp );

      while ( ctr < line ) {

         if ( fgetc ( fp ) == 012 ) { /* ASCII 012 == newline */
            ctr++;
         }

      }


   return;
}

/*-----------------------------------------------------------------------------------*/

void list_populate ( FILE *fp, int *vec, cList *list ) {

   Character *character_cast, *character;
   int ctr = 0;

   while ( ctr < 16 ) {

      character_cast = (Character * ) malloc ( sizeof ( Character ) );
      line_locate ( fp, vec[ctr] );
      character_cast->name  = string_read ( fp );
      character_cast->house = string_read ( fp );
      fscanf ( fp, "%d, %d, %d, %d", &character_cast->agility, &character_cast->strength, &character_cast->intelligence, &character_cast->health);

      character = character_create ( character_cast->name, character_cast->house, character_cast->agility, character_cast->strength, character_cast->intelligence, character_cast->health );

      add_cNode ( ctr, character, list );

      character_free ( character_cast );

      ctr++;

   }

   free ( vec );
   return;
}

/*-----------------------------------------------------------------------------------*/

Character* character_create ( char *_name, char *_house, int _agility, int _strength, int _intelligence, int _health) {

   Character *character = (Character *) malloc ( sizeof ( Character ) );
   character->name  = ( char * ) malloc ( sizeof(char) * ( strlen (_name) + 1 ) );
   character->house = ( char * ) malloc ( sizeof(char) * ( strlen (_house) + 1 ) );

   strcpy ( character->name, _name );
   strcpy ( character->house, _house );

   character->agility = _agility;
   character->strength = _strength;
   character->intelligence = _intelligence;
   character->health = _health;

   return character;
}

/*-----------------------------------------------------------------------------------*/

cList* create_roster ( FILE *fp ) {
   int num = 0;
   char cur = '0';
   num = character_number( fp, num, cur );
   int *vec = lucky_sixteen ( num );
   cList *list = list_create();
   list_populate ( fp, vec, list );

   return list;
}
