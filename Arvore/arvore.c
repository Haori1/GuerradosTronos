#include "arvore.h"
#include <stdlib.h>

/*--------------------------------------------------------------------------------------------*/

t_node* tree_create(){

    t_node* root = node_create();


    return root;
}

/*--------------------------------------------------------------------------------------------*/

t_node* tree_fill(t_node* root){                      /* Para uso no trabalho, a entrada deve ser sempre a primeira raiz da arvore. */

   if ( root->right == NULL && root->left == NULL ) { /* Caso essa condicao seja verdadeira, nivel atual == ultimo nivel */

      root->right = node_create();                    /* Cria dois nos no proximo nivel ( novo ultimo nivel ) */
      root->left  = node_create();

   } else {                                           /* Caso falsa, checa ambos os nos proximos do atual */

      tree_fill( root->right );
      tree_fill( root->left  ); 

   }


    return root;
}

/*--------------------------------------------------------------------------------------------*/

t_node* node_create(){                                  /* Função que aloca o nó dinâmicamente. */

    t_node* node = (t_node *) malloc(sizeof(t_node));   /* Alocação de memória na heap. */

    node->character = NULL;                             /* Os valores do nó são setados em NULL. */

    node->left = NULL;

    node->right = NULL;


    return node;                                        /* Retorno do nó criado. */
}
