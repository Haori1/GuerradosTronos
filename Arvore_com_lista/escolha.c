#include "escolha.h"

void escolha(cList* list){
    cNode* element = NULL;
    element = list->first;

    for(int i = 0; i < NUM; i++){

        printf("Personagem %d:\n", (i + 1));
        printf("Agility: %d  Strength: %d  Intelligence: %d  Health: %d\n", element->character->agility, element->character->strength, element->character->intelligence, element->character->health);
        element = element->next;

    }/*end for()*/

}/*end escolha()*/
