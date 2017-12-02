
#include "lista.h"
#ifndef ______ARVORE___H__
#define ______ARVORE___H__
typedef struct node {
    Character* character;
    struct node* left;
    struct node* right;
} t_node;

cList* list_fill(cList* list);
void tree_print_preorder(t_node* root);
void print_node(t_node* root);
void tree_free(t_node* tree);
void tree_character_fill(t_node* root, cList* list, cNode* aux);
t_node* character_search_tree(cNode* element, t_node* root, t_node *retorno);
t_node* tree_create();
t_node* tree_fill(t_node* root);
t_node* node_create();

#endif
