#include <stdio.h>
#include <stdio_ext.h>
#include "arvore.h"
#include "lista.h"
#include "lertxt.h"
#include "escolha.h"
#include "fila.h"
#include "batalha.h"
#include "game.h"
void game(){
    t_node* root = tree_create();
    cList* list = NULL;
    list = list_fill(list);
    cNode* aux = NULL;
    t_node* player = NULL;
    t_node *retorno = NULL;
    tree_character_fill(root, list, aux);
    int i = escolha(list);
    aux = character_search(i - 1, list);
    player = character_search_tree(aux, root, retorno);
    log_clear ();
    log_round ( 1 );
    battle_finder ( root, player );
    log_round ( 2 );
    battle_finder ( root, player );
    log_round ( 3 );
    battle_finder ( root, player );
    log_round ( 4 );
    battle_finder ( root, player );
    log_victory ( root->character );
    log_print();
    printf("Pressione qualquer tecla para prosseguir: ");
    fflush(stdin);
    __fpurge(stdin);
    getchar();
    free_list(list);
    tree_free(root);
    return;
}
