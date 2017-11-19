#ifndef ______ARVORE___H__
#define ______ARVORE___H__

typedef struct {
    char* name;
    char* house;
    int agility;
    int strength;
    int intelligence;
    int health;
} Character;

typedef struct node {
    Character* character;
    struct node* left;
    struct node* right;
} t_node;


void tree_print_preorder(t_node* root);
void tree_free(t_node* tree);
t_node* tree_create();
t_node* tree_fill(t_node* root);
t_node* node_create();

#endif
