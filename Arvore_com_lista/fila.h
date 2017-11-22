#ifndef ____FILA____H__
#define ____FILA____H__
#include "lista.h"
#include "arvore.h"

typedef struct item{

    t_node* node;

    struct item* proximo;

}item;

typedef struct{

    item* primeiro;

    item* ultimo;

}fila;

void    imprimefila(fila* fila);
void    inserir  (fila* fila, t_node* node);
t_node* retirar  (fila* fila);
void    apagafila(fila* fila);
int     verivazia(fila* fila);
fila*   alocafila();
item*   alocaitem(t_node* node);






#endif
