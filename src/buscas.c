#include "../include/buscas.h"
#include "../include/utils.h"
#include "../include/types.h"


void localizar_nome(no_jogadores_t *ptr_lista_jogadores, string str)
{
    msg_cabecalho("BUSCA DE JOGADORES POR NOME");


    if(ptr_lista_jogadores == NULL)
    {
        printf("nenhum jogador cadastrado\n");
        msg_press_enter();
        return;
    }
    bool achou = false;
    no_jogadores_t *jogador_atual = ptr_lista_jogadores;

    printf("Digite o nome (NOME COMPLETO) para a busca: ");
    fgets(str,T_STR,stdin);
    retirar_enter(str);

    printf("\nResultados da busca por '%s' (Nome):\n", str);
    printf("-----------------------------------------------------------\n");

    while(jogador_atual != NULL)
    {
        if(string_case_compare(jogador_atual->dados_jogadores.nome, str)==0)
        {
            printf("Nome: %s\n", jogador_atual->dados_jogadores.nome);
            printf("ID: %u\n", jogador_atual->dados_jogadores.id_jogador);
            printf("Idade: %d\n",jogador_atual->dados_jogadores.idade);
            printf("Posicao: %s\n",jogador_atual->dados_jogadores.posicao_jogador);
            if(jogador_atual->dados_jogadores.status == INATIVO)
            {
                printf("Status: Inativo");
                if(jogador_atual->dados_jogadores.status_2 == RECUPERACAO)
                {
                    printf(", em recuperacao medica\n");
                }
                if(jogador_atual->dados_jogadores.status_2 == VENDIDO)
                {
                    printf(", jogador vendido\n");
                    printf("Valor de venda: %.2f\n",jogador_atual->dados_jogadores.valor_venda);
                }
            } else printf("Status: Ativo\n");
            printf("-----------------------------------------------------------\n");
            achou = true;
        }
        jogador_atual = jogador_atual->proximo;
    }

    if(!achou)
    {
        printf("Nenhum jogador encontrado com o nome '%s'.\n", str);
    }
    msg_press_enter();
}

void localizar_posicao(no_jogadores_t *ptr_lista_jogadores, string str)
{
    msg_cabecalho("BUSCA DE JOGADORES POR POSICAO");


    if(ptr_lista_jogadores == NULL)
    {
        printf("nenhum jogador cadastrado\n");
        msg_press_enter();
        return;
    }
    bool achou = false;
    no_jogadores_t *jogador_atual = ptr_lista_jogadores;

    printf("Digite a posicao para a busca: ");
    fgets(str,T_STR,stdin);
    retirar_enter(str);

    printf("\nResultados da busca por '%s' (Posicao):\n", str);
    printf("-----------------------------------------------------------\n");

    while(jogador_atual != NULL)
    {
        if(string_case_compare(jogador_atual->dados_jogadores.posicao_jogador, str)==0)
        {
            printf("Nome: %s\n", jogador_atual->dados_jogadores.nome);
            printf("Posicao: %s\n",jogador_atual->dados_jogadores.posicao_jogador);
            printf("ID: %u\n", jogador_atual->dados_jogadores.id_jogador);
            printf("Idade: %d\n",jogador_atual->dados_jogadores.idade);
            
            if(jogador_atual->dados_jogadores.status == INATIVO)
            {
                printf("Status: Inativo");
                if(jogador_atual->dados_jogadores.status_2 == RECUPERACAO)
                {
                    printf(", em recuperacao medica\n");
                }
                if(jogador_atual->dados_jogadores.status_2 == VENDIDO)
                {
                    printf(", jogador vendido\n");
                    printf("Valor de venda: %.2f\n",jogador_atual->dados_jogadores.valor_venda);
                }
            } else printf("Status: Ativo\n");
            printf("-----------------------------------------------------------\n");
            achou = true;
        }
        jogador_atual = jogador_atual->proximo;
    }

    if(!achou)
    {
        printf("Nenhum jogador encontrado com a posicao '%s'.\n", str);
    }
    msg_press_enter();
}

no_jogadores_t *localizar_jogador_por_id(lista_t *lista, uint32_t id)
{
    if (lista == NULL || lista->cabeca_jogadores == NULL) return NULL;


    no_jogadores_t *jogador_atual = lista->cabeca_jogadores;


    while (jogador_atual != NULL) {

        if (jogador_atual->dados_jogadores.id_jogador == id) {

            return jogador_atual;
        }

        jogador_atual = jogador_atual->proximo;
    }
    return NULL;
}

void localizar_jogos_por_adversario(no_jogos_t *ptr_lista_jogos, string str, lista_t *lista)
{
    msg_cabecalho("BUSCA DE JOGOS POR TIME ADVERSARIO");


    if(ptr_lista_jogos == NULL)
    {
        printf("nenhum jogo cadastrado\n");
        msg_press_enter();
        return;
    }
    bool achou = false;
    int vitorias = 0;
    int derrotas = 0;
    int empates = 0;
    no_jogos_t *jogo_atual = ptr_lista_jogos;

    printf("Digite o nome do time adversario para a busca: ");
    fgets(str,T_STR,stdin);
    retirar_enter(str);

    printf("\nResultados da busca de jogos por '%s' (NOME DO TIME ADVERSARIO):\n", str);
    printf("-----------------------------------------------------------\n");

    while(jogo_atual != NULL)
    {
        if(string_case_compare(jogo_atual->dados_jogos.nome_time_adversario, str)==0)
        {
            printf("Jogo contra: %s\n",jogo_atual->dados_jogos.nome_time_adversario);
            printf("Local do jogo: %s\n", jogo_atual->dados_jogos.local_jogo);
            printf("Data do jogo:%d/%d/%d\n",jogo_atual->dados_jogos.data.dia_jogo,jogo_atual->dados_jogos.data.mes_jogo,jogo_atual->dados_jogos.data.ano_jogo);
            printf("Resultado do jogo: %s\n",jogo_atual->dados_jogos.resultado);
            printf("Jogadores escalados(%d)\n: ",jogo_atual->dados_jogos.qtd_jogadores_escalados);
            if(jogo_atual->dados_jogos.qtd_jogadores_escalados > 0)
            {
                printf("  ");
                for(size_t i = 0; i < jogo_atual->dados_jogos.qtd_jogadores_escalados;i++)
                {
                    uint32_t id_achar = jogo_atual->dados_jogos.ids_jogadores_escalados[i];

                    no_jogadores_t *jogador_escalado = localizar_jogador_por_id(lista,id_achar);

                    if(jogador_escalado != NULL)
                    {
                        printf("%s (ID: %u)", jogador_escalado->dados_jogadores.nome,id_achar);

                    }
                    else
                    {
                        printf("[Jogador ID %u Nao Encontrado]\n", id_achar);
                    }

                    if(i<jogo_atual->dados_jogos.qtd_jogadores_escalados - 1)
                    {
                        printf(", ");
                    }
                
                }
                printf("\n");
            } else printf("Nenhum jogador escalado para esta partida.\n");
            printf("Quantidade de substituicoes: %d", jogo_atual->dados_jogos.qtd_subst);            
            printf("-----------------------------------------------------------\n");
            if (strcasecmp(jogo_atual->dados_jogos.resultado, "Vitoria") == 0)
            {
                vitorias++;
            }
            else if (strcasecmp(jogo_atual->dados_jogos.resultado, "Derrota") == 0)
            {
                derrotas++;
            }
            else if (strcasecmp(jogo_atual->dados_jogos.resultado, "Empate") == 0)
            {
                empates++;
            }
            achou = true;
        }
        jogo_atual = jogo_atual->proximo;
    }
    if(achou)
    {
        printf("\nResumo dos Resultados contra '%s':\n", str);
        printf("Vitórias: %d\n", vitorias);
        printf("Derrotas: %d\n", derrotas);
        printf("Empates: %d\n", empates);
        printf("\n");
    }
    if(!achou)
    {
        printf("Nenhum jogo encontrado contra o time: '%s'.\n", str);
    }
    msg_press_enter();
}

void localizar_maior_salario(no_jogadores_t *ptr_lista_jogadores)
{
    msg_cabecalho("BUSCA DE JOGADORES COM MAIOR SALARIO");
    if(ptr_lista_jogadores == NULL)
    {
        printf("nenhum jogador cadastrado\n");
        msg_press_enter();
        return;
    }
    float maior_sal = 0;
    no_jogadores_t *jogador_atual = ptr_lista_jogadores;

    maior_sal = jogador_atual->dados_jogadores.salario;

    jogador_atual = jogador_atual->proximo;

    while(jogador_atual != NULL)
    {
        if(jogador_atual->dados_jogadores.salario > maior_sal)
        {
            maior_sal = jogador_atual->dados_jogadores.salario;
        }
        jogador_atual = jogador_atual->proximo;
    }
    printf("\nJogador(es) com o maior salario (R$ %.2f):\n", maior_sal);
    printf("-----------------------------------------------------------\n");

    jogador_atual = ptr_lista_jogadores;

    while(jogador_atual != NULL)
    {
        if(jogador_atual->dados_jogadores.salario == maior_sal)
        {
            printf("Nome: %s\n",jogador_atual->dados_jogadores.nome);
            printf("ID: %u\n",jogador_atual->dados_jogadores.id_jogador);
            printf("Salario: R$ %.2f\n",jogador_atual->dados_jogadores.salario);
            printf("Posicao: %s\n",jogador_atual->dados_jogadores.posicao_jogador);
            if(jogador_atual->dados_jogadores.status == INATIVO)
            {
                printf("Status: Inativo");
                if(jogador_atual->dados_jogadores.status_2 == RECUPERACAO)
                {
                    printf(", em recuperacao medica\n");
                }
                if(jogador_atual->dados_jogadores.status_2 == VENDIDO)
                {
                    printf(", jogador vendido\n");
                    printf("Valor de venda: %.2f\n",jogador_atual->dados_jogadores.valor_venda);
                }
            } else printf("Status: Ativo\n");
            printf("-----------------------------------------------------------\n");
            
        }
        jogador_atual = jogador_atual->proximo;
    }
    msg_press_enter();
}

void localizar_salario_faixa(no_jogadores_t *ptr_lista_jogadores,float SalMin,float SalMax)
{
    msg_cabecalho("BUSCA DE JOGADORES POR FAIXA DE SALARIO");
    if(ptr_lista_jogadores == NULL)
    {
        printf("nenhum jogador cadastrado\n");
        msg_press_enter();
        return;
    }
    
    


    bool achou = false;
    no_jogadores_t *jogador_atual = ptr_lista_jogadores;

    printf("---- Localizar Jogadores por Faixa Salarial ----\n");
    printf("Digite a faixa salarial:\n");

    printf("Menor salario: ");
    scanf("%f", &SalMin);

    printf("Maior salario: ");
    scanf("%f", &SalMax);
    getchar();

    printf("\nResultados para salarios entre R$ %.2f e R$ %.2f:\n", SalMin, SalMax);
    printf("-----------------------------------------------------------\n");

while (jogador_atual != NULL)
    {
        if(jogador_atual->dados_jogadores.salario >= SalMin && jogador_atual->dados_jogadores.salario <=SalMax)
        {
            printf("Nome: %s\n",jogador_atual->dados_jogadores.nome);
            printf("ID: %u\n",jogador_atual->dados_jogadores.id_jogador);
            printf("Salario: R$ %.2f\n",jogador_atual->dados_jogadores.salario);
            printf("Posicao: %s\n",jogador_atual->dados_jogadores.posicao_jogador);
            if(jogador_atual->dados_jogadores.status == INATIVO)
            {
                printf("Status: Inativo");
                if(jogador_atual->dados_jogadores.status_2 == RECUPERACAO)
                {
                    printf(", em recuperacao medica\n");
                }
                if(jogador_atual->dados_jogadores.status_2 == VENDIDO)
                {
                    printf(", jogador vendido\n");
                    printf("Valor de venda: %.2f\n",jogador_atual->dados_jogadores.valor_venda);
                }
            } else printf("Status: Ativo\n");
            printf("-----------------------------------------------------------\n");
            achou = true;
        }
        jogador_atual = jogador_atual->proximo;
    }

    if(!achou)
    {
        printf("Nenhum jogador achado na faixa salarial entre R$ %.2f e R$ %.2f.\n", SalMin, SalMax);
    }
    

    msg_press_enter();
}