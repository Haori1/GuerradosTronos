#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

#ifndef __BATALHA__
#define __BATALHA__

/*-----------------------------------------------------------------------------------------*/
/** \brief Função 1 - Batalha entre player e cpu*/
/**

    \details Imprime o nome do personagem e a casa do player e os status para serem utilizados durante a batalha, pega a escolha de atributo para ser utilizada na batalha, chama a função validStat() para verificar se a escolha do player é válida, ocorre a luta entre o player e a cpu, se o player perde o arquivo do log é marcado e a última batalha do player é inserida no arquivo de log, e o vencedor é retornado.
    \param Recebe o nó do player e o nó do inimigo.
    \return Retorna o personagem vencedor.

*/

Character* player_battle (t_node *player, t_node *enemy);

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 2 - Batalha entre cpu e cpu*/
/**

    \details A função procura o nó pai do player, quando o pai do player é encontrado a função player_battle() é executada passando o nó do player e o nó do cpu, se forem dois personagens que não são o player é escolhido o atributo de forma aleatória e passado para a função fight() para que ocorra a luta e o nó pai dos dois personagens receba o vencedor entre os dois.
    \param Recebe o nó raiz e o nó do player.
    \return Não retorna valores.

*/


void battle_finder (t_node* root, t_node* player);

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 3 - Validação dos atributos*/
/**

    \details Verifica se o status do atributo é válido, se o atributo for maior que 100 ele não está disponível para ser utilizado.
    \param Recebe o nó do player e o atributo selecionado.
    \return Retorna 1 para se o status do atributo for válido ou 0 se o status não for válido.

*/

int validStat (t_node* player, int choice);

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 4 - Luta*/
/**

    \details Compara os atributos, atualiza o log com o vencedor e o perdedor e retorna o vencedor da luta.
    \param Recebe o personagem 1, o personagem 2 e o atributo selecionado.
    \return Retorna o vencedor da luta.

*/

Character* fight (Character* fighter_one, Character* fighter_two, int atribute);

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 4 - Atualização dos status*/
/**

    \details Adiciona 100 no atributo que foi utilizado na batalha atual e retira 100 para o atributo que estava inválido na rodada passada.
    \param Recebe o personagem do player e o atributo selecionado.
    \return Não retorna valores apenas atualiza o status dos atributos.

*/

void update_stat (Character* player, int choice);

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 5 - Atualização do log*/
/**

    \details Os Logs das batalhas vão sendo colocados no arquivo log.txt de acordo com a escolha de atributos utilizados, os vencedores e os perdedores.
    \param Recebe o personagem vencedor, o personagem perdedor o atributo selecionado.
    \return Não retorna valores apenas atualiza o log.

*/

void log_update (Character* winner, Character* loser, int choice);

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 6 - Atualização do round no log*/
/**

    \details O log round() insere o número do round no arquivo log.txt.
    \param Recebe o número do round.
    \return Não retorna valores apenas atualiza o log.

*/

void log_round (int num);

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 7 - Atualização do último round no log*/
/**

    \details Insere a última batalha do player no log2.txt.
    \param Recebe o personagem do player, o personagem inimigo e a escolha de atributo.
    \return Não retorna valores apenas atualiza o log.

*/

void log_end (Character* player, Character* enemy, int choice);

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 8 - Atualização do vencedor no log*/
/**

    \details Insere no arquivo log2.txt o vencedor do torneio.
    \param Recebe o personagem vencedor.
    \return Não retorna valores apenas atualiza o log.

*/

void log_victory (Character* winner);

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 9 - Condição de impressão do log*/
/**

    \details Insere o símbolo ~ (126) como condição de parada de impressão.
    \param Não recebe valores.
    \return Não retorna valores apenas atualiza o log.

*/

void log_terminate ();

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 10 - Impressão do log*/
/**

    \details Imprime o log até o final do arquivo ou até encontrar o símbolo ~ (126).
    \param Não recebe valores.
    \return Não retorna valores apenas imprime o log.

*/

void log_print ();

/*-----------------------------------------------------------------------------------------*/

/** \brief Função 11 - Apaga o log*/
/**

    \details Apaga o log para as proximas partidas.
    \param Não recebe valores.
    \return Não retorna valores apenas apaga o log.

*/

void log_clear ();

#endif
