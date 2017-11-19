#include "lista.h"
#include <stdio.h>
int main (void){
    cList* list = list_create();
    add_cNode(0, 10, list);
    add_cNode(1, 21, list);
    add_cNode(2, -91, list);
    printList(list);
    printf("----------------------\n");
    rem_cNode(1, list);
    add_cNode(25, 33, list);
    printList(list);
    printf("----------------------\n");
    rem_cNode(3, list);
    printList(list);



    free_list(list);
    return 0;
}
