#include "arvore.h"
#include "lertxt.h"
#include "lista.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------------------------*/

cList* list_fill(cList* list){
    FILE* fp = fopen("personagens.txt", "r");           /*O ponteiro fp recebe o arquivo.*/

    list = create_roster(fp);                           /*Lista com os personagens.*/

    fclose(fp);

    return list;
}

/*--------------------------------------------------------------------------------------------*/

void tree_character_fill(t_node* root, cList* list, cNode* aux){    /*Preenche os nós folhas da árvore com os personagens*/
    if(root == NULL){

        return;
    }
    fila* fila = alocafila();

    t_node* node = NULL;

    inserir(fila, root);

    aux = list->first;

    while(!verivazia(fila)){
        node = retirar(fila);

        if(node->left == NULL && node->right == NULL){
            node->character = aux->character;
            aux = aux->next;
        }

        if(node->left != NULL){
            inserir(fila, node->left);
        }
        if(node->right != NULL){
            inserir(fila, node->right);
        }


    }/*end while()*/

    apagafila(fila);


    return;
}/*end tree_character_fill()*/

/*--------------------------------------------------------------------------------------------*/
void tree_print_preorder(t_node* root){
    if(root == NULL){                   /*Se a raiz estiver vazia a função retorna.*/

        return;

    }

    if(root->character != NULL){

        print_node(root);                   /*Processa a raiz.*/
    }
    tree_print_preorder(root->left);    /*Chamada recursiva a esquerda.*/
    tree_print_preorder(root->right);   /*Chamada recursiva a direita.*/

    return;

}


void tree_print_width(t_node* root){
    if(root == NULL){

        return;
    }
    fila* fila = alocafila();

    t_node* node = NULL;

    inserir(fila, root);

    while(!verivazia(fila)){

        node = retirar(fila);

        printf("%s\n", root->character->name);

        if(node->left != NULL){
            inserir(fila, node->left);
        }
        if(node->right != NULL){
            inserir(fila, node->right);
        }


    }

    apagafila(fila);
    
    return;
}

/*--------------------------------------------------------------------------------------------*/

t_node* character_search_tree(cNode* element, t_node* root, t_node *retorno){    /**/

    if(root == NULL){
        return NULL;
    }

    if(root->character == element->character){

        retorno = root;
        return retorno;

    }

    if ( retorno == NULL ) {
    retorno = character_search_tree(element, root->left, retorno);
    }
    if ( retorno == NULL ) {
    retorno = character_search_tree(element, root->right, retorno);
    }

    return retorno;

}//end character_search_tree()

/*--------------------------------------------------------------------------------------------*/

t_node* tree_create(){                              /*Chama a função tree_fill() 4 vezes para preencher os níveis da árvore*/

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

/*--------------------------------------------------------------------------------------------*/

void tree_free(t_node* tree){                           /*Função que libera a árvore de forma recursiva*/
    if(tree == NULL){
        return;
    }

    tree_free(tree->left);
    tree_free(tree->right);
    free(tree);
}

/*--------------------------------------------------------------------------------------------*/

void print_node(t_node* root){
    printf("%s\n", root->character->name);
}
