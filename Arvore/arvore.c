#include "arvore.h"
#include <stdlib.h>






/*--------------------------------------------------------------------------------------------*/

t_node* tree_create(){
    t_node* root = node_create();






    return root;
}

/*--------------------------------------------------------------------------------------------*/

t_node* tree_fill(t_node* root){





    return root;
}

/*--------------------------------------------------------------------------------------------*/

t_node* node_create(){                                  //Função que aloca o nó dinâmicamente.

    t_node* node = (t_node *) malloc(sizeof(t_node));   //Alocação de memória na heap.

    node->character = NULL;                             //Os valores do nó são setados em NULL.

    node->left = NULL;

    node->right = NULL;

    return node;                                        //Retorno do nó criado.
}
