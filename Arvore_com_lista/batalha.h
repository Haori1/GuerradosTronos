#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

#ifndef __BATALHA__
#define __BATALHA__

Character* player_battle ( t_node *player, t_node *enemy );
void battle_finder ( t_node* root, t_node* player );
int validStat ( t_node* player, int choice );
Character* fight ( Character* fighter_one, Character* fighter_two, int atribute );
void update_stat ( Character* player, int choice );
void log_update ( Character* winner, Character* loser, int choice );
void log_round ( int num );
void log_end ( Character* player, Character* enemy, int choice );
void log_terminate ( );
void log_print ( );

#endif
