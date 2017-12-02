#include "batalha.h"

void battle_finder ( t_node* root, t_node* player ) {

   if ( root->left->character != NULL ) {

      if ( root->left->character == player->character ) {

         root->character = player_battle ( player, root->right );

      } else if ( root->right->character == player->character ) {

         root->character = player_battle ( player, root->left );

      } else {

         srand ( time ( NULL ) );
         int stat = ( rand () % 4 ) + 1;
         root->character = fight ( root->right->character, root->left->character, stat);

      }

   return;

   }

   battle_finder ( root->left, player );
   battle_finder ( root->right, player );
   
   return;
}

Character* player_battle ( t_node *player, t_node *enemy ) {

   printf("Seu personagem: %s da Casa %s\n", player->character->name, player->character->house);
   
   if ( player->character->agility < 101 ) {
      printf("1) Agility      : %d\n", player->character->agility);
   } else {
      printf("X)              : XX");
   }

   if ( player->character->strength < 101 ) {
      printf("2) Strength     : %d\n", player->character->strength);
   } else {
      printf("X)              : XX\n");
   }

   if ( player->character->intelligence < 101 ) {
      printf("3) Intelligence : %d\n", player->character->intelligence);
   } else {
      printf("X)              : XX\n");
   }

   if ( player->character->health < 101 ) {
      printf("4) Health       : %d\n\n", player->character->health);
   } else {
      printf("X)              : XX\n\n");
   }

   int choice, stat;
   printf("O adversario: %s da Casa %s\n\nSelecione um atributo: ", enemy->character->name, enemy->character->house);
   scanf( "%d", &choice );

   while ( !validStat ( player, choice ) ) {

      printf("Escolha invalida.\n\nSelecione um atributo: ");
      scanf( "%d", &choice );

   }

   return fight ( player->character, enemy->character, choice );  
}

int validStat ( t_node* player, int choice ) {

   switch ( choice ) {

      case 1: 
         if ( player->character->strength < 101 ) {
            return 1;
         } else {
            return 0;
         }

      case 2:
         if ( player->character->strength < 101 ) {
            return 1;
         } else {
            return 0;
         }

      case 3:
         if ( player->character->strength < 101 ) {
            return 1;
         } else {
            return 0;
         }
      case 4:
         if ( player->character->strength < 101 ) {
            return 1;
         } else {
            return 0;
         }

      default:
         return 0;
      }
   
}

Character* fight ( Character* fighter_one, Character* fighter_two, int atribute ) {

   switch ( atribute ) {

      case 1: 
         if ( (fighter_one->agility) > (fighter_two->agility) ) {
            return fighter_one;
         } else {
            return fighter_two;
         }

      case 2:
         if ( (fighter_one->strength) > (fighter_two->strength) ) {
            return fighter_one;
         } else {
            return fighter_two;
         }

      case 3:
         if ( (fighter_one->intelligence) > (fighter_two->intelligence) ) {
            return fighter_one;
         } else {
            return fighter_two;
         }
      case 4:
         if ( (fighter_one->health) > (fighter_two->health) ) {
            return fighter_one;
         } else {
            return fighter_two;
         }

      default:
         return 0;
      }
   
}
