#include <stdio.h>
#include "arvore.h"
#include "lista.h"
#include "lertxt.h"
#include "escolha.h"
#include "fila.h"

int main(void){
    t_node* root = tree_create();
    cList* list = NULL;
    list = list_fill(list);
    cNode* aux = NULL;
    t_node* player = NULL;
    tree_character_fill(root, list, aux);
    tree_print_preorder(root);
    printf("%d\n", height(root));
    int i = escolha(list);
    aux = character_search(i - 1, list);
    player = character_search_tree(aux, root);
    printf("%s\n", player->character->name);
    free_list(list);
    tree_free(root);
    return 0;
}
