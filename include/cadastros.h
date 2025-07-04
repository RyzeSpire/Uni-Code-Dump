#ifndef CADASTROS_H
#define CADASTROS_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "types.h"

//funcoes de data management
bool is_lista_jogos_vazia(no_jogos_t *ptr_lista_jogos);
bool is_lista_jogadores_vazia(no_jogadores_t *ptr_lista_jogadores);
void mostrar_detalhes_jogos(FILE *output, no_jogos_t *jogo, lista_t *lista, bool eh_csv, bool eh_html);
void mostrar_detalhes_jogo_h(FILE *output, bool eh_csv, bool eh_html);

void inicializa_lista_jogos(lista_t *lista_jogos);
void inicializa_lista_jogadores(lista_t *lista_jogadores);

no_jogos_t *localizar_ultimo_registro_jogos(no_jogos_t *ptr_lista_jogos);
no_jogadores_t *localizar_ultimo_registro_jogadores(no_jogadores_t *ptr_lista_jogadores);

//O cadastro em si
no_jogos_t *novo_registro_jogos();
no_jogadores_t *novo_registro_jogadores();
void insere_registro_inicio_jogos(no_jogos_t *novo, lista_t *lista_jogos);
void insere_registro_inicio_jogadores(no_jogadores_t *novo, lista_t *lista_jogadores);
//////////////////////////////////////////////////////////////////////////////////////
void insere_registro_fim_jogos(no_jogos_t *novo, lista_t *lista_jogos);
void insere_registro_fim_jogadores(no_jogadores_t *novo, lista_t *lista_jogadores);
//

//edicao de cadastro
void excluir_registro_jogos(no_jogos_t *registro, lista_t *lista_jogos);
void excluir_registro_jogadores(no_jogadores_t *registro, lista_t *lista_jogadores);
////////////////////////////////////////////////////////////////////////////////////
void inativar_jogador(no_jogadores_t *registro);
//


#endif