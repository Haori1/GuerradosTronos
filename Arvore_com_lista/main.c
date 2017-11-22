#include <stdio.h>
#include "arvore.h"
#include "lista.h"
#include "lertxt.h"
#include "fila.h"

int main(void){
    t_node* root = tree_create();
    root = tree_character_fill(root);
    tree_print_preorder(root);



    return 0;
}
