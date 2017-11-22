#include "arvore.h"
#include "lertxt.h"
#include "lista.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------------------------*/

t_node* tree_character_fill(t_node* root){
    if(root == NULL){

        return root;
    }

    FILE* fp = fopen("personagens.txt", "r");           //O ponteiro fp recebe o arquivo.

    cList* list = create_roster(fp);                    //Lista com os personagens.

    fclose(fp);

    fila* fila = alocafila();                           //Criação da fila.

    t_node* node = NULL;                                //Nó que recebe da fila.

    cNode* aux = NULL;                                  //Var. Aux.

    inserir(fila, root);                                //A raiz é enfileirada.

    aux = list->first;                                  //A var. aux recebe o primeiro da lista.

    while(!verivazia(fila)){                            //Enquanto a fila não estiver vazia o processo continua.

        node = retirar(fila);                           //O nó recebe o primeiro da fila.

        if(node->left == NULL && node->right == NULL){  //Se o nó for folha ele recebe um personagem da lista.

            node->character = aux->character;

            aux = aux->next;

        }

        if(node->left != NULL){                         //A fila permite percorrer a arvore em largura.

            inserir(fila, node->left);

        } else if(node->right != NULL){

            inserir(fila, node->right);

        }//end if() largura
    }//end while()



    apagafila(fila);
    return root;
}

/*--------------------------------------------------------------------------------------------*/
void tree_print_preorder(t_node* root){
    if(root == NULL){                   //Se a raiz estiver vazia a função retorna.

        return;

    } else {

    print_node(root);                   //Processa a raiz.
    tree_print_preorder(root->left);    //Chamada recursiva a esquerda.
    tree_print_preorder(root->right);   //Chamada recursiva a direita.

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
