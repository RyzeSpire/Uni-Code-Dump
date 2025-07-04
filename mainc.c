#include "types.h"
#include "utils.h"
#include "relatorios.h"
#include "menus.h"
#include "cadastros.h"
#include "buscas.h"



#define JOGADORES_FILE "jogadores.bin"
#define JOGOS_FILE "jogos.bin"

int main() 
{
    lista_t lista;
    inicializa_lista_jogos(&lista);
    inicializa_lista_jogadores(&lista);
    
    // Carregar dados dos arquivos
    carregar_jogadores_binario(&lista, JOGADORES_FILE);
    carregar_jogos_binario(&lista, JOGOS_FILE);
    
    uint8_t opcao;
    bool sair = false;
    
    while (!sair) 
    {
        opcao = menu_principal();
        
        switch (opcao) 
        {
            case 1: 
            { // Cadastros
                uint8_t opcao_cad = menu_cadastros();
                
                switch (opcao_cad) 
                {
                    case 1: 
                    { // Cadastrar Jogador
                        no_jogadores_t *novo_jogador = novo_registro_jogadores();
                        if (novo_jogador) 
                        {
                            insere_registro_fim_jogadores(novo_jogador, &lista);
                            printf("Jogador cadastrado com sucesso!\n");
                        } else 
                        {
                            printf("Erro ao cadastrar jogador.\n");
                        }
                        msg_press_enter();
                        break;
                    }
                    case 2: 
                    { // Cadastrar Jogo
                        no_jogos_t *novo_jogo = novo_registro_jogos(&lista);
                        if (novo_jogo) 
                        {
                            insere_registro_fim_jogos(novo_jogo, &lista);
                            printf("Jogo cadastrado com sucesso!\n");
                        } else 
                        {
                            printf("Erro ao cadastrar jogo.\n");
                        }
                        msg_press_enter();
                        break;
                    }
                    
                    case 3:
                    {
                        msg_cabecalho("INATIVAR JOGADOR");
                        if (is_lista_jogadores_vazia(lista.cabeca_jogadores)) {
                            printf("Nenhum jogador cadastrado para inativar.\n");
                            msg_press_enter();
                            break;
                        }

                        exibir_jogadores_ativos(lista.cabeca_jogadores);

                        uint32_t id_jogador_inativar;
                        printf("Digite o ID do jogador que deseja inativar: ");
                        scanf("%u", &id_jogador_inativar);
                        getchar();

                        no_jogadores_t *jogador_encontrado = localizar_jogador_por_id(&lista, id_jogador_inativar);

                        if (jogador_encontrado != NULL) {
                            inativar_jogador(jogador_encontrado);
                            printf("\nProcesso de inativacao concluido.\n");
                        } else {
                            printf("Jogador com ID %u nao encontrado.\n", id_jogador_inativar);
                        }
                        msg_press_enter();
                        break;

                    }
                    case 0: // Voltar
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        msg_press_enter();
                }
                break;
            }
            case 2: 
            { // Relatórios
                uint8_t opcao_rel = menu_relatorios();
                
                switch (opcao_rel) 
                {
                    case 1: // Listar todos jogadores
                        listar_jogadores(lista.cabeca_jogadores);
                        break;
                    case 2: { // Faixa de idades
                        int idadeMin, idadeMax;
                        relatorio_faixa_idades(lista.cabeca_jogadores, idadeMin, idadeMax);
                        break;
                    }
                    case 3: // Resultado partidas
                        relatorio_partidas_resultado(lista.cabeca_jogos);
                        break;
                    case 4: // Confrontos adversários
                        relatorio_confrontos_time_adversario(lista.cabeca_jogos);
                        break;
                    case 5: // Jogadores vendidos
                        listar_jogadores_vendidos(lista.cabeca_jogadores);
                        break;
                    case 6: // Valor do time
                        relatorio_valor_time(lista.cabeca_jogadores);
                        break;
                    case 7: // Aproveitamento
                        relatorio_aproveitamento_time(lista.cabeca_jogos);
                        break;
                    case 0: // Voltar
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        msg_press_enter();
                }
                break;
            }
            case 3: 
            { // Buscas
                uint8_t opcao_busca = menu_buscas();
                string busca_str;
                float salMin, salMax;
                
                switch (opcao_busca) 
                {
                    case 1: // Por nome
                        localizar_nome(lista.cabeca_jogadores, busca_str);
                        break;
                    case 2: // Por posição
                        localizar_posicao(lista.cabeca_jogadores, busca_str);
                        break;
                    case 3: // Por adversário
                        localizar_jogos_por_adversario(lista.cabeca_jogos, busca_str, &lista);
                        break;
                    case 4: // Maior salário
                        localizar_maior_salario(lista.cabeca_jogadores);
                        break;
                    case 5: // Faixa salarial
                        localizar_salario_faixa(lista.cabeca_jogadores,salMin,salMax);
                        break;
                    case 0: // Voltar
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        msg_press_enter();
                }
                break;
            }
            case 4: 
            { // Manipulação de arquivos
                uint8_t opcao_arq = menu_manipulacao_arquivos();
                
                switch (opcao_arq) 
                {
                    case 1: // Salvar jogadores
                        salvar_jogadores_binario(&lista, JOGADORES_FILE);
                        printf("Jogadores salvos com sucesso em %s\n", JOGADORES_FILE);
                        msg_press_enter();
                        break;
                    case 2: // Salvar jogos
                        salvar_jogos_binario(&lista, JOGOS_FILE);
                        printf("Jogos salvos com sucesso em %s\n", JOGOS_FILE);
                        msg_press_enter();
                        break;
                    case 0: // Voltar
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        msg_press_enter();
                }
                break;
            }
            case 0: // Sair
                sair = true;
                // Salvar dados antes de sair
                salvar_jogadores_binario(&lista, JOGADORES_FILE);
                salvar_jogos_binario(&lista, JOGOS_FILE);
                printf("Dados salvos. Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                msg_press_enter();
        }
    }
    
    // Liberar memória alocada para as listas
    no_jogadores_t *jogador_atual = lista.cabeca_jogadores;
    while (jogador_atual != NULL) 
    {
        no_jogadores_t *proximo = jogador_atual->proximo;
        free(jogador_atual);
        jogador_atual = proximo;
    }
    
    no_jogos_t *jogo_atual = lista.cabeca_jogos;
    while (jogo_atual != NULL) 
    {
        no_jogos_t *proximo = jogo_atual->proximo;
        free(jogo_atual);
        jogo_atual = proximo;
    }
    
    return 0;
}