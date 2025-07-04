#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"


void retirar_enter(string str);
int string_case_compare(const string str1, const string str2);
void limpar_tela();
void msg_press_enter();
void msg_cabecalho(string msg);


void salvar_jogadores_binario(const lista_t *lista, const char *filename);
void carregar_jogadores_binario(lista_t *lista, const char *filename);
void salvar_jogos_binario(const lista_t *lista, const char *filename);
void carregar_jogos_binario(lista_t *lista, const char *filename);

void exibir_jogadores_ativos(no_jogadores_t *ptr_lista_jogadores);

#endif