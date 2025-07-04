#ifndef BUSCAS_H
#define BUSCAS_H

#include "types.h"
#include <stdbool.h>

void localizar_nome(no_jogadores_t *ptr_lista_jogadores, string str); //loccaliza os jogadores por nome (e os lista)
void localizar_posicao(no_jogadores_t *ptr_lista_jogadores, string str); //localiza jogadores pela sua posicao (e os lista)
no_jogadores_t *localizar_jogador_por_id(lista_t *lista, uint32_t id);
void localizar_jogos_por_adversario(no_jogos_t *ptr_lista_jogos, string str, lista_t *lista); //localiza os jogos pelo nome do time adversario (e os lista)
void localizar_maior_salario(no_jogadores_t *ptr_lista_jogadores); //localiza o(s) jogador(es) com maior salario (e o(s) lista)
void localizar_salario_faixa(no_jogadores_t *ptr_lista_jogadores,float SalMin,float SalMax); //localiza jogadores por uma faixa de salario (e os lista)

#endif