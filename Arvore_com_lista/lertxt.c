#include "lertxt.h"

/* FUNCAO 1 --- IDENTIFICA NUMERO DE PERSONAGENS NO ARQUIVO DE ENTRADA */

int character_number( FILE *fp ) {

   int num = 0;
   char cur;

   while ( cur != EOF ) {

      cur = fgetc ( fp );
      if ( cur == 012 ) {  /* ASCII 012 == newline */

         num++;

      }

   }

   return num;
}

/* FUNCAO 2 --- GERA UM VETOR COM 16 NUMEROS ALEATORIOS E UNICOS ENTRE 1 e n, ONDE n == VALOR DE ENTRADA */

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

         if ( vec[ctrb] == numb ) {
            break;
         } else {
            ctrb++;
         }

      }
      if ( ctrb == 16 ) {
         vec[ctra] = numb;
         ctra++;
      }
      ctrb = 0;
   }

   return vec;
}

/* FUNCAO 3 --- RETORNA UM VETOR CONTENDO UMA STRING LIDA DE UM ARQUIVO DE ENTRADA, LE ATE ENCONTRAR UMA VIRGULA */

char* string_read ( FILE *fp ) {

   fpos_t pos;
   int tam = 0, ctr = 0;

   fgetpos ( fp, &pos );
   while ( fgetc ( fp ) != 054 ) { /* ASCII 054 == virgula */

      tam++;

   }
   char *vec = ( char * ) malloc ( ( tam + 1 ) * sizeof ( char ) );
   vec[tam] = 000; /* ASCII 000 == NULL */  // possível erro para a função de buscar o personagem na árvore
   fsetpos ( fp, &pos );

   while ( ctr < tam ) {

      vec[ctr] = fgetc ( fp );
      ctr++;

   }
   fseek ( fp, 2, SEEK_CUR ); /* Avanca o cursor duas posicoes, 'engolindo' a virgula e o espaco que vem a seguir. */


   return vec;
}

/* FUNCAO 4 --- MOVE O CURSOR PARA A LINHA DO ARQUIVO INFORMADA */

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

/* FUNCAO 5 --- PREENCHE UMA LISTA COM OS PERSONAGENS */

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

/* FUNCAO 6 --- ALOCA MEMORIA PARA O PERSONAGEM */

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

/* FUNCAO 7 --- LE ARQUIVO E GERA LISTA COM PERSONAGENS ALEATORIOS */

cList* create_roster ( FILE *fp ) {

   int num = character_number( fp );
   int *vec = lucky_sixteen ( num );
   cList *list = list_create();
   list_populate ( fp, vec, list );

   return list;
}
