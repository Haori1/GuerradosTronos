
#include "lista.h"
#ifndef ______ARVORE___H__
#define ______ARVORE___H__
typedef struct node {
    Character* character;
    struct node* left;
    struct node* right;
} t_node;

/** \brief Função 1 - Lista com personagens*/
/**

    \details Chama a função create_roster() para preencher a lista com os personagens.
    \param Recebe uma lista vazia.
    \return Retorna a lista com os personagens.

*/
cList* list_fill(cList* list);

/*--------------------------------------------------------------------------------------------*/

/** \brief Função 2 - Impressão por pré-ordem*/
/**

    \details Imprime os nós da árvore recursivamente no modelo pré-ordem.
    \param Recebe o nó raiz.
    \return Não retorna valores apenas imprime a árvore.

*/

void tree_print_preorder(t_node* root);

/*--------------------------------------------------------------------------------------------*/

/** \brief Função 3 - Impressão por largura*/
/**

    \details Imprime os nós da árvore recursivamente no modelo de largura.
    \param Recebe o nó raiz.
    \return Não retorna valores apenas imprime a árvore.

*/

void tree_print_width(t_node* root);

/*--------------------------------------------------------------------------------------------*/

/** \brief Função 4 - Impressão do nó*/
/**

    \details Imprime o personagem do nó.
    \param Recebe um nó.
    \return Não retorna valores apenas imprime o nó.

*/

void print_node(t_node* root);

/*--------------------------------------------------------------------------------------------*/

/** \brief Função 5 - Libera a árvore*/
/**

    \details Libera a memória da árvore de forma recursiva.
    \param Recebe o nó raiz da árvore.
    \return Não retorna valores apenas libera memória da árvore.

*/

void tree_free(t_node* tree);

/*--------------------------------------------------------------------------------------------*/

/** \brief Função 6 - Personagens na árvore*/
/**

    \details Preenche os nós folhas da árvore com os personagens de forma recursiva com percorrimento em largura.
    \param Recebe o nó raiz da árvore, a lista com os personagens e um ponteiro de um elemento da lista auxiliar.
    \return Não retorna valores apenas preenche a árvore com os personagens em memória.

*/

void tree_character_fill(t_node* root, cList* list, cNode* aux);

/*--------------------------------------------------------------------------------------------*/

/** \brief Função 7 - Busca na árvore*/
/**

    \details Procura um personagem da lista na árvore de forma recursiva.
    \param Recebe o nó raiz da árvore, o personagem da lista e um ponteiro de um nó auxiliar para retorno.
    \return Retorna o nó com o personagem correspondente.

*/

t_node* character_search_tree(cNode* element, t_node* root, t_node *retorno);

/*--------------------------------------------------------------------------------------------*/

/** \brief Função 8 - Criação da árvore*/
/**

    \details Chama a função tree_fill() 4 vezes para criar a árvore.
    \param Não possui parâmetros.
    \return Retorna o nó raiz com a árvore formada.

*/

t_node* tree_create();

/*--------------------------------------------------------------------------------------------*/

/** \brief Função 9 - Criação dos níveis da árvore*/
/**

    \details Cria de forma recursiva um nível da árvore.
    \param Recebe o nó raiz da árvore.
    \return Retorna o nó raiz com o nível da árvore formada.

*/

t_node* tree_fill(t_node* root);

/*--------------------------------------------------------------------------------------------*/

/** \brief Função 10 - Criação do nó*/
/**

    \details Função que aloca o nó dinâmicamente.
    \param Não possui parâmetros.
    \return Retorna o nó alocado dinâmicamente.

*/

t_node* node_create();

#endif
