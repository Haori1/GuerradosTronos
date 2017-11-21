#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista.h"

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

#ifndef __ler_txt___
#define __ler_txt___

int character_number( FILE *fp );
int* lucky_sixteen( int num );
char* string_read ( FILE *fp );
void list_populate ( FILE *fp, int *vec, cList *list );
Character* character_create ( char *_name, char *_house, int _agility, int _strength, int _intelligence, int _health);
cList* create_roster ( FILE *fp );

#endif
