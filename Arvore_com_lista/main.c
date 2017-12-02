#include <stdio.h>
#include "arvore.h"
#include "lista.h"
#include "lertxt.h"
#include "escolha.h"
#include "fila.h"
#include "batalha.h"

int main(void){
    t_node* root = tree_create();
    cList* list = NULL;
    list = list_fill(list);
    cNode* aux = NULL;
    t_node* player = NULL;
    t_node *retorno = NULL;
    tree_character_fill(root, list, aux);
    tree_print_preorder(root);
    printList ( list ) ;
    int i = escolha(list);
    aux = character_search(i - 1, list);
    player = character_search_tree(aux, root, retorno);
    battle_finder ( root, player );
    printf("%s\n", player->character->name);
    log_print();
    free_list(list);
    tree_free(root);
    return 0;
}
