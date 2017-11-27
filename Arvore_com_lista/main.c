#include <stdio.h>
#include "arvore.h"
#include "lista.h"
#include "lertxt.h"

int main(void){
    t_node* root = tree_create();
    cList* list = NULL;
    list = list_fill(list);
    tree_character_fill(root, list);
    tree_print_preorder(root);
    printf("%d\n", height(root));


    return 0;
}
