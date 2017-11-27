#include "arvore.h"
#include "lertxt.h"
#include "lista.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------------------------*/

int height(t_node* root){
    if(root == NULL){
        return -1;
    }

    int hl = height(root->left);

    int hr = height(root->right);

    if (hl < hr){

        return hr + 1;

    } else {

        return hl + 1;

    }
}

/*--------------------------------------------------------------------------------------------*/

void tree_complete(cList* list){
 list = list_fill(list);

}

/*--------------------------------------------------------------------------------------------*/

cList* list_fill(cList* list){
    FILE* fp = fopen("personagens.txt", "r");           /*O ponteiro fp recebe o arquivo.*/

    list = create_roster(fp);                           /*Lista com os personagens.*/

    fclose(fp);

    return list;
}

/*--------------------------------------------------------------------------------------------*/

void tree_character_fill(t_node* root, cList* list){
    if(root == NULL){

        return;
    }

    cNode* aux;                                         /*Var. Aux.*/

    aux = list->first;                                  /*A var. aux recebe o primeiro da lista.*/


    if(root->left == NULL && root->right == NULL){

        root->character = aux->character;

        rem_cNode(0, list);
        
        return;
    } else {
        tree_character_fill(root->right, list);
        tree_character_fill(root->left, list);
    }
    return;
}

/*--------------------------------------------------------------------------------------------*/
void tree_print_preorder(t_node* root){
    if(root == NULL){                   /*Se a raiz estiver vazia a função retorna.*/

        return;

    } else {

    if(root->character != NULL){

        print_node(root);                   /*Processa a raiz.*/
    }
    tree_print_preorder(root->left);    /*Chamada recursiva a esquerda.*/
    tree_print_preorder(root->right);   /*Chamada recursiva a direita.*/

    }
}


/*--------------------------------------------------------------------------------------------*/

t_node* tree_create(){

    t_node* root = node_create();
    for(int i = 0; i < 4; i++){
        tree_fill(root);
    }
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

void print_node(t_node* root){
    printf(" %s\n", root->character->name);
}
