#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------*/

void imprimefila(fila* fila){

    if(verivazia(fila)){                //Se a fila estiver vazia não há o que imprimir.

        printf("A fila está vazia\n");

        return;

    }//end if()

    item* item = fila->primeiro;        //O ponteiro item recebe o primeiro da fila.

    while(item != NULL){                //Enquanto a fila não chega ao final continue.

        printf("%d --> ", item->node);  //Impressão da fila.

        item = item->proximo;           //Atualização do valor do ponteiro item que pega o endereço do próximo da fila.

    }//end while()

    printf(" NULL\n");                  //Final da fila.

}//end imprimefila()

/*------------------------------------*/

void inserir(fila* fila, t_node* node){

    item* item = alocaitem(node);           //O ponteiro item recebe o elemento alocado e com o valor incluido.

    if(verivazia(fila)){                    //Se a fila estiver vazia o primeiro da fila é o que está sendo inserido.

        fila->primeiro = item;

    } else {

        fila->ultimo->proximo = item;       //Se a fila não estiver vazia o ponteiro proximo do ultimo elemento aponta pra item.

    }

    fila->ultimo = item;                    //O ponteiro ultimo recebe item.

}//end inserir()

/*------------------------------------*/

t_node* retirar(fila* fila){

    item* item = fila->primeiro;                //O ponteiro item recebe o ponteiro para o primeiro da fila.

    t_node* retorno = NULL;                     //Variável de retorno.

    if(verivazia(fila)){                        //Se a fila estiver vazia não é possível retirar valores.

        printf("A fila está vazia\n");

        free(fila);

        exit(1);

    }//end if()

    retorno = item->node;                       /*A variável de retorno recebe o dado do primeiro item da fila.*/

    if(fila->primeiro == fila->ultimo){
        fila->ultimo = NULL;
    }

    fila->primeiro = fila->primeiro->proximo;   /*O primeiro da fila agora aponta para o próximo da fila.*/

    free(item);                                 //O valor retirado é liberado da fila.

    return retorno;                             //O valor é retornado.

}//end retirar()

/*------------------------------------*/

void apagafila(fila* fila){

    item* item = fila->primeiro;                        //O ponteiro item recebe o endereço do primeiro item da fila.

    if(!verivazia(fila)){                               //Se a fila não estiver vazia o while tem que ser executado.

        while(item != NULL){                            //Enquanto o ponteiro item não chega ao final da fila o while continua.

            fila->primeiro = fila->primeiro->proximo;   //O ponteiro para o primeiro recebe o próximo da fila.

            free(item);                                 //O endereço de item é liberado.

            item = fila->primeiro;                      //O ponteiro item recebe o endereço do ponteiro primeiro.

        }//end while()
    }//end if()

    free(fila);                                         //Por fim a fila é liberada.

}//end apagafila()

/*------------------------------------*/

int verivazia(fila* fila){

    if(fila->primeiro == NULL && fila->ultimo == NULL){     //Se o primeiro e o ultimo apontarem para NULL então a fila está vazia e com isso a função retorna 1 caso contrario retorna 0.

        return 1;

    } else {

        return 0;

    }//end if()

}//end verivazia()

/*------------------------------------*/

fila* alocafila(){

    fila* ptr = (fila *) malloc(sizeof(fila));  //Aloca a fila.

    ptr->primeiro = NULL;

    ptr->ultimo   = NULL;

    return ptr;

}//end alocafila()

/*------------------------------------*/

item* alocaitem(t_node* node){          //Aloca o item da fila.

    item* ptr = (item *) malloc(sizeof(item));

    ptr->node = node;               //O valor passado é inserido na fila.

    ptr->proximo = NULL;

    return ptr;

}//end alocaitem()
