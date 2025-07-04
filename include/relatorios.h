#ifndef RELATORIOS_H
#define RELATORIOS_H

#include <stdbool.h>
#include "types.h"
#include "utils.h"
#include "buscas.h"

void detalhes_mostrar_jogos(FILE *output, no_jogos_t *jogo, bool eh_csv, bool eh_html);
void detalhes_mostrar_jogo_h(FILE *output, bool eh_csv, bool eh_html);


void detalhes_mostrar_jogadores(FILE *output, no_jogadores_t *jogador, bool eh_csv, bool eh_html);
void detalhes_mostrar_jogador_h(FILE *output, bool eh_csv, bool eh_html);

//relatorios jogadores
void listar_jogadores(no_jogadores_t *ptr_lista_jogadores);
void mostrar_dados_registro_jogadores(no_jogadores_t *registro);
void relatorio_faixa_idades(no_jogadores_t *ptr_lista_jogadores, int idadeMin, int idadeMax);
void listar_jogadores_vendidos(no_jogadores_t *ptr_lista_jogadores );
void relatorio_valor_time(no_jogadores_t *ptr_lista_jogadores);  //em relacao ao preco de venda dos jogadores.
//

//relatorios jogos
void relatorio_partidas_resultado(no_jogos_t *ptr_lista_jogos);
void relatorio_confrontos_time_adversario(no_jogos_t *ptr_lista_jogos);
void relatorio_aproveitamento_time(no_jogos_t *ptr_lista_jogos); //jogos vencidos pelo total de jogos realizados
//


#endif