/*
    \mainpage
    \author Henrique Mendes de Freitas Mariano & Gabriel Santos Menezes
    \version 1.0
    \date 2017

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista.h"

#ifndef __ler_txt___
#define __ler_txt___

/*-----------------------------------------------------------------------------------*/

/** \brief Função 1 - Número de personagens*/
/**

    \details Identifica numero de personagens contidos no arquivo. * Usada internamente pela funcao cList* create_roster()
    \param Recebe como entrada o arquivo a ser lido e um inteiro e um char declarados previamente.
    \return Retorna o número de personagens no arquivo de entrada.

*/
int character_number(FILE *fp, int num, char cur);

/*-----------------------------------------------------------------------------------*/

/** \brief Função 2 - Números Aleatórios */
/**

    \details Gera um vetor com 16 números aleatórios e únicos entre 1 e n, onde n == valor de entrada.
    \param Número de personagens.
    \return Retorna um vetor com números aleatórios.

*/

int* lucky_sixteen(int num);

/*-----------------------------------------------------------------------------------*/

/** \brief Função 3 - Nome e Casa */
/**

    \details Retorna um vetor contendo uma string lida de um arquivo de entrada, lê até encontrar uma vírgula.
    \param Arquivo.
    \return Retorna uma string contendo nome e casa do personagem.

*/

char* string_read (FILE *fp);

/*-----------------------------------------------------------------------------------*/

/** \brief Função 4 - Cursor */
/**

    \details Move o cursor para a linha do arquivo informada.
    \param Arquivo e linha.
    \return Retorna a posição do cursor para a linha desejada.

*/
void line_locate(FILE *fp, int line);

/*-----------------------------------------------------------------------------------*/

/** \brief Função 5 - Lista com personagens */
/**

    \details Insere os personagens na lista por cópia. *O vetor deve ser gerado pela funcao int* lucky_sixteen(). **Usada internamente pela funcao cList* create_roster().
    \param Arquivo de entrada, um vetor de inteiros aleatórios, e uma lista encadeada que suporte o tipo Character.
    \return Nao retorna valor algum, apenas modifica os valores contidos em memória.

*/

void list_populate (FILE *fp, int *vec, cList *list);

/*-----------------------------------------------------------------------------------*/

/** \brief Função 6 - Aloca personagem */
/**

    \details Aloca memória para o personagem.
    \param Nome, casa, agilidade, força, inteligência e vida.
    \return Retorno o endereço de memória do character alocado dinâmicamente.

*/

Character* character_create (char *_name, char *_house, int _agility, int _strength, int _intelligence, int _health);

/*-----------------------------------------------------------------------------------*/

/** \brief Função 7 - Lê arquivo e gera lista com personagens aleatórios */
/**

    \details Gera como saida o endereco da lista contendo 16 personagens escolhidos aleatoriamente a partir de um arquivo formatado conforme declarado na especificacao do trabalho.
    \param Recebe como entrada o arquivo a ser lido.
    \return Retorna uma lista com personagens de forma aleatória.

*/

cList* create_roster (FILE *fp);

#endif
