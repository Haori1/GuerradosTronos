#include "main.h"
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
            //jogo();
        } else {
            printf("Caracter inválido, tente novamente\n");
        }
    }







    return 0;
}
