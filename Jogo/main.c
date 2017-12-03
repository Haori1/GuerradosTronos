#include "main.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    int n = 0;

    while(true){

        tela_inicial();

        scanf("%d", &n);

        if(n == 2){

            break;

        } else if(n == 1){

            game();

        } else {

            printf("Caracter inválido, tente novamente\n");

        }/*end if()*/
    }/*end while()*/

    return 0;
}
