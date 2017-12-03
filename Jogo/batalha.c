#include "batalha.h"

void battle_finder (t_node* root, t_node* player) {

   if ( root->left->character != NULL ) {

      if ( root->left->character == player->character ) {   /*Procura o nó pai do player antes de ocorrer a batalha*/

         root->character = player_battle ( player, root->right );

      } else if ( root->right->character == player->character ) {

         root->character = player_battle ( player, root->left );

     } else {                                              /*Se o personagem não for um player, os personagens lutam escolhendo um atributo aleatório*/

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

Character* player_battle (t_node *player, t_node *enemy) {            /*Imprime o nome do personagem e a casa do player e os status para serem utilizados durante a batalha, pega a escolha de atributo para ser utilizada na batalha, chama a função validStat() para verificar se a escolha do player é válida, ocorre a luta entre o player e a cpu, se o player perde o arquivo do log é marcado e a última batalha do player é inserida no arquivo de log, e o vencedor é retornado*/

   printf("Seu personagem: %s da Casa %s\n", player->character->name, player->character->house);

   if ( player->character->agility < 101 ) {
      printf("1) Agility      : %d\n", player->character->agility);
   } else {
      printf("X)              : XX\n");
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

   int choice;
   printf("O adversario: %s da Casa %s\n\nSelecione um atributo: ", enemy->character->name, enemy->character->house);
   scanf( "%d", &choice );

   while ( !validStat ( player, choice ) ) {            /*Verifica se a escolha é válida*/

      printf("Escolha invalida.\n\nSelecione um atributo: ");
      scanf( "%d", &choice );

   }

   Character* winner = fight ( player->character, enemy->character, choice );       /*Após a escolha de atributos a luta é realizada pegando o vencedor da luta*/
   update_stat ( player->character, choice );                                       /*Atualiza os status dos atributos*/

   if ( winner != player->character ) {                                             /*Player não for o ganhador a função log_terminate() insere um símbolo para marcar o arquivo onde o player foi derrotado*/

      log_terminate ( );
      log_end ( player->character , enemy->character, choice );                     /*Última batalha do player é inserida no log*/

   }

   return winner;                                                                   /*O vencedor é retornado*/

}

int validStat (t_node* player, int choice) {          /*Verifica se o status do atributo é válido se for válido ele retorna 1 se não for válido ele retorna 0*/

   switch ( choice ) {

      case 1:
         if ( player->character->agility < 101 ) {
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
         if ( player->character->intelligence < 101 ) {
            return 1;
         } else {
            return 0;
         }
      case 4:
         if ( player->character->health < 101 ) {
            return 1;
         } else {
            return 0;
         }

      default:
         return 0;
      }

}

Character* fight (Character* fighter_one, Character* fighter_two, int atribute) { /*Compara os atributos, atualiza o log e retorna o vencedor da luta*/

   switch ( atribute ) {

      case 1:
         if ( (fighter_one->agility) >= (fighter_two->agility) ) {
            log_update ( fighter_one, fighter_two, 1 );
            return fighter_one;
         } else {
            log_update ( fighter_two, fighter_one, 1 );
            return fighter_two;
         }

      case 2:
         if ( (fighter_one->strength) >= (fighter_two->strength) ) {
            log_update ( fighter_one, fighter_two, 2 );
            return fighter_one;
         } else {
            log_update ( fighter_two, fighter_one, 2 );
            return fighter_two;
         }

      case 3:
         if ( (fighter_one->intelligence) >= (fighter_two->intelligence) ) {
            log_update ( fighter_one, fighter_two, 3 );
            return fighter_one;
         } else {
            log_update ( fighter_two, fighter_one, 3 );
            return fighter_two;
         }
      case 4:
         if ( (fighter_one->health) >= (fighter_two->health) ) {
            log_update ( fighter_one, fighter_two, 4 );
            return fighter_one;
         } else {
            log_update ( fighter_two, fighter_one, 4 );
            return fighter_two;
         }

      default:
         return 0;
      }

}

void update_stat (Character* player, int choice) {    /*Retira ou adiciona 100 para atualizar os status dos atributos*/

   if ( player->agility > 101 ) {
            player->agility -= 100;
   }

   if ( player->strength > 101 ) {
            player->strength -= 100;
   }

   if ( player->intelligence > 101 ) {
            player->intelligence -= 100;
   }

   if ( player->health > 101 ) {
            player->health -= 100;
   }

   switch ( choice ) {

      case 1:
         if ( player->agility < 101 ) {
            player->agility += 100;
            break;
         }

      case 2:
         if ( player->strength < 101 ) {
            player->strength += 100;
            break;
         }

      case 3:
         if ( player->intelligence < 101 ) {
            player->intelligence += 100;
            break;
         }

      case 4:
         if ( player->health < 101 ) {
            player->health += 100;
            break;
         }

      default:
         break;
      }

   return;
}

void log_update (Character* winner, Character* loser, int choice) {  /*Os Logs das batalhas vão sendo colocados no arquivo log.txt*/

   FILE *arq = fopen ( "log.txt", "a" );

   switch ( choice ) {

      case 1:
         fprintf (arq, "%s (%d %s) x %s (%d %s)\n", winner->name, winner->agility, "Agility", loser->name, loser->agility, "Agility");
         break;
      case 2:
         fprintf (arq, "%s (%d %s) x %s (%d %s)\n", winner->name, winner->strength, "Strength", loser->name, loser->strength, "Strength");
         break;
      case 3:
         fprintf (arq, "%s (%d %s) x %s (%d %s)\n", winner->name, winner->intelligence, "Intelligence", loser->name, loser->intelligence, "Intelligence");
         break;
      case 4:
         fprintf (arq, "%s (%d %s) x %s (%d %s)\n", winner->name, winner->health, "Health", loser->name, loser->health, "Health");
         break;
      default:
         break;
      }



   fclose ( arq );

}

void log_round (int num) {    /*O log round insere o número do round no arquivo log.txt*/

   FILE *arq = fopen ( "log.txt", "a+" );

   fprintf ( arq, "\nROUND %d:\n\n", num );

   fclose ( arq );

}

void log_end (Character* player, Character* enemy, int choice) {      /*Insere a última batalha do player no log2.txt*/

   FILE *arq = fopen ( "log2.txt", "a+" );

   switch ( choice ) {

      case 1:
         fprintf (arq, "%s (%d %s) x %s (%d %s)\n", player->name, player->agility - 100, "Agility", enemy->name, enemy->agility, "Agility");
         break;
      case 2:
         fprintf (arq, "%s (%d %s) x %s (%d %s)\n", player->name, player->strength - 100, "Strength", enemy->name, enemy->strength, "Strength");
         break;
      case 3:
         fprintf (arq, "%s (%d %s) x %s (%d %s)\n", player->name, player->intelligence - 100, "Intelligence", enemy->name, enemy->intelligence, "Intelligence");
         break;
      case 4:
         fprintf (arq, "%s (%d %s) x %s (%d %s)\n", player->name, player->health - 100, "Health", enemy->name, enemy->health, "Health");
         break;
      default:
         break;
      }

   fclose ( arq );

   return;
}

void log_victory (Character* winner) {        /*Insere no arquivo log2.txt o vencedor da batalha*/

   FILE *arq = fopen ( "log2.txt", "a+" );

   fprintf ( arq, "%s da Casa %s foi vitorioso. ", winner->name, winner->house);

   fclose ( arq );

}

void log_terminate () {           /*Insere o símbolo ~ (126) - condição de parada de impressão*/

   FILE *arq = fopen ( "log.txt", "a+" );

   fputc ( 126, arq );

   fclose ( arq );

}

void log_print () {                /*Imprime o log até o final do arquivo ou encontrar o símbolo ~ (126)*/

   FILE *arq = fopen ( "log2.txt", "r" );   /*Imprime o campẽao e o último round do player*/
   rewind ( arq );
   char cursor = 0;

   while ( 1 ) {

      cursor = getc ( arq );                /*O char do arquivo vai sendo passado para o cursor e vai sendo imprimido na tela*/
      if ( feof( arq ) ) {
         break;
      }

      printf("%c", cursor);

   }

   fclose ( arq );

   arq = fopen ( "log.txt", "r" );  /*Imprime as batalhas ocorridas nos rounds*/
   rewind ( arq );                  /*Move o cursor para o início do arquivo*/
   printf("\n\n");

   while ( 1 ) {

      cursor = fgetc ( arq );   /*O char do arquivo vai sendo passado para o cursor e vai sendo imprimido na tela*/
      if ( cursor == 126 ) {    /*O arquivo para de ser impresso quando o ~ (126) é encontrado*/
         break;
      }
      if ( feof ( arq ) ) {     /*Se o arquivo não tiver o símbolo, a impressão é parada ao final do arquivo*/
         break;
      }
      printf("%c", cursor);

   }

   fclose ( arq );
}

void log_clear () {

   remove ( "log2.txt" );       /*Apaga o log para as proximas partidas*/
   remove ( "log.txt");

}
