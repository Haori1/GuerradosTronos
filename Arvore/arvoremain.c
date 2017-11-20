#include "arvore.h"
#include <stdio.h>

int main(void){

    t_node* node = node_create();
    tree_fill( node );
    tree_fill( node );

    printf("%x", node->right->right); /* pa comprova */

    return 0;
}
