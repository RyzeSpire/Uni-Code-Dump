#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>
#include <stdint.h>

#define T_STR 100
#define MAX_JOG 23


// Define tipo string
typedef char string[T_STR];

// Define tipo status
typedef enum {ATIVO = 0, INATIVO = 1} status_t;
// Define tipo status_2
typedef enum {RECUPERACAO = 0, VENDIDO = 1} status_2_t;

//definir o tipo data
typedef struct data
{
    int dia_jogo;
    int mes_jogo;
    int ano_jogo;
} data_t;

// Define o tipo dados jogos
typedef struct dados_jogos
{
    string nome_time_adversario;
    string local_jogo;
    data_t data;
    string resultado;
    uint32_t ids_jogadores_escalados[MAX_JOG];
    int qtd_jogadores_escalados;
    int qtd_subst;
} dados_jogos_t;


// Define o tipo dados jogadores
typedef struct dados_jogadores
{
    string nome;
    uint32_t id_jogador;
    int idade;
    float altura;
    float peso;
    string posicao_jogador;
    float valor_venda;
    float valor_aquisicao;
    float salario;
    status_t status;
    status_2_t status_2;

} dados_jogadores_t;


// Define membro da lista jogos(no/nodo)
typedef struct no_jogos {
    dados_jogos_t dados_jogos;
    struct no_jogos *proximo;
} no_jogos_t;


// Define membro da lista jogadores(no/nodo)
typedef struct no_jogadores {
    dados_jogadores_t dados_jogadores;
    struct no_jogadores *proximo;
} no_jogadores_t;


// Define tipo lista;
typedef struct lista {
    no_jogos_t *cabeca_jogos;
    no_jogadores_t *cabeca_jogadores;
    uint8_t nr_nos_jogos;
    uint8_t nr_nos_jogadores;
} lista_t;

#endif