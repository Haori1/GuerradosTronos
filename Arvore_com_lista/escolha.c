#include "escolha.h"
#include <stdlib.h>
int escolha(cList* list){
    system("clear");
    cNode* element = NULL;
    element = list->first;
    int choice = rand();
    srand(time(NULL));              /*Define a seed do rand()*/
    printf("Escolha seu personagem:\n");
    for(int i = 0; i < NUM; i++){

        choice = rand();            /*Um número aleatório é gerado a cada laço de repetição*/

        printf("Personagem %d:\n", (i + 1));

        if(choice % 4 == 0){
            printf("Agility: %d  ", element->character->agility);
        } else {
            printf("Agility: **  ");
        }

        if(choice % 4 == 1){
            printf("Strength: %d  ", element->character->strength);
        } else {
            printf("Strength: **  ");
        }

        if(choice % 4 == 2){
            printf("Intelligence: %d  ", element->character->intelligence);
        } else {
            printf("Intelligence: **  ");
        }

        if(choice % 4 == 3){
            printf("Health: %d\n", element->character->health);
        } else {
            printf("Health: **\n");
        }
        element = element->next;

    }/*end for()*/
    printf("\n");
    int n = -1;
    scanf("%d", &n);
    return n;

}/*end escolha()*/
