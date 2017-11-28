#include "escolha.h"

void escolha(cList* list){
    cNode* element = NULL;
    element = list->first;
    srand(time(NULL));
    int choice = srand();
    for(int i = 0; i < NUM; i++){

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

}/*end escolha()*/
