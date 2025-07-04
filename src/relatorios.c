#include "../include/relatorios.h"
#include "../include/utils.h"


void detalhes_mostrar_jogos(FILE *output, no_jogos_t *jogo, bool eh_csv, bool eh_html)
{
    if (eh_csv)
    {
        fprintf(output, "%d/%d/%d;%s;%s;%s\n",
                jogo->dados_jogos.data.dia_jogo,
                jogo->dados_jogos.data.mes_jogo,
                jogo->dados_jogos.data.ano_jogo,
                jogo->dados_jogos.nome_time_adversario,
                jogo->dados_jogos.resultado,
                jogo->dados_jogos.local_jogo);
    }
    else if (eh_html)
    {
        fprintf(output, "  <tr>\n");
        fprintf(output, "    <td>%d/%d/%d</td>\n",
                jogo->dados_jogos.data.dia_jogo,
                jogo->dados_jogos.data.mes_jogo,
                jogo->dados_jogos.data.ano_jogo);
        fprintf(output, "    <td>%s</td>\n", jogo->dados_jogos.nome_time_adversario);
        fprintf(output, "    <td>%s</td>\n", jogo->dados_jogos.resultado);
        fprintf(output, "    <td>%s</td>\n", jogo->dados_jogos.local_jogo);
        fprintf(output, "  </tr>\n");
    }
    else
    {
        fprintf(output, "Data: %d/%d/%d\n",
                jogo->dados_jogos.data.dia_jogo,
                jogo->dados_jogos.data.mes_jogo,
                jogo->dados_jogos.data.ano_jogo);
        fprintf(output, "Adversario: %s\n", jogo->dados_jogos.nome_time_adversario);
        fprintf(output, "Resultado: %s\n", jogo->dados_jogos.resultado);
        fprintf(output, "Local: %s\n", jogo->dados_jogos.local_jogo);
        fprintf(output, "-----------------------------------------------------------\n");
    }
}
void detalhes_mostrar_jogo_h(FILE *output, bool eh_csv, bool eh_html)
{
    if (eh_csv)
    {
        fprintf(output, "Data;Time Adversario;Resultado;Local\n");
    }
    else if (eh_html)
    {
        fprintf(output, "    <thead>\n");
        fprintf(output, "      <tr>\n");
        fprintf(output, "        <th>Data</th>\n");
        fprintf(output, "        <th>Time Adversario</th>\n");
        fprintf(output, "        <th>Resultado</th>\n");
        fprintf(output, "        <th>Local</th>\n");
        fprintf(output, "      </tr>\n");
        fprintf(output, "    </thead>\n");
        fprintf(output, "    <tbody>\n");
    }
    else
    {
        fprintf(output, "%-12s %-20s %-10s %-15s\n",
                "Data", "Time Adversario", "Resultado", "Local");
        fprintf(output, "------------------------------------------------------------------------------------------------------\n");
    }
}

void detalhes_mostrar_jogadores(FILE *output, no_jogadores_t *jogador, bool eh_csv, bool eh_html)
{
    if(eh_csv)
    {
        fprintf(output,"%s;%u;%d;%.2f;%.2f;%s;%.2f;%.2f;%.2f;",
                jogador->dados_jogadores.nome,
                jogador->dados_jogadores.id_jogador,
                jogador->dados_jogadores.idade,
                jogador->dados_jogadores.altura,
                jogador->dados_jogadores.peso,
                jogador->dados_jogadores.posicao_jogador,
                jogador->dados_jogadores.valor_venda,
                jogador->dados_jogadores.valor_aquisicao,
                jogador->dados_jogadores.salario);

        if(jogador->dados_jogadores.status == ATIVO)
        {
            fprintf(output,"Ativo;;\n");
        } else
        {
            fprintf(output,"Inativo;");
            if(jogador->dados_jogadores.status_2 == RECUPERACAO)
            {
                fprintf(output, "em recuperacao medica;\n");
            } else if(jogador->dados_jogadores.status_2 == VENDIDO)
            {
                fprintf(output,"vendido;\n");
            }
        }
    }
    else if(eh_html)
    {
        fprintf(output, "  <tr>\n");
        fprintf(output, "    <td>%s</td>\n", jogador->dados_jogadores.nome);
        fprintf(output, "    <td>%u</td>\n", jogador->dados_jogadores.id_jogador);
        fprintf(output, "    <td>%d</td>\n", jogador->dados_jogadores.idade);
        fprintf(output, "    <td>%.2f</td>\n", jogador->dados_jogadores.altura);
        fprintf(output, "    <td>%.2f</td>\n", jogador->dados_jogadores.peso);
        fprintf(output, "    <td>%s</td>\n", jogador->dados_jogadores.posicao_jogador);
        fprintf(output, "    <td>R$ %.2f</td>\n", jogador->dados_jogadores.valor_venda);
        fprintf(output, "    <td>R$ %.2f</td>\n", jogador->dados_jogadores.valor_aquisicao);
        fprintf(output, "    <td>R$ %.2f</td>\n", jogador->dados_jogadores.salario);

        fprintf(output, "    <td>");
        if (jogador->dados_jogadores.status == ATIVO) {
            fprintf(output, "Ativo");
        } else {
            fprintf(output, "Inativo");
            if (jogador->dados_jogadores.status_2 == RECUPERACAO) {
                fprintf(output, " (Recuperacao Medica)");
            } else if (jogador->dados_jogadores.status_2 == VENDIDO) {
                fprintf(output, " (Vendido - R$ %.2f)", jogador->dados_jogadores.valor_venda);
            }
        }
        fprintf(output, "</td>\n");
        fprintf(output, "  </tr>\n");
    } 
    else
    {
        printf("Nome: %s\n", jogador->dados_jogadores.nome);
        printf("ID: %u\n", jogador->dados_jogadores.id_jogador);
        printf("Idade: %d\n", jogador->dados_jogadores.idade);
        printf("Altura: %.2f m\n", jogador->dados_jogadores.altura);
        printf("Peso: %.2f kg\n", jogador->dados_jogadores.peso);
        printf("Posicao: %s\n", jogador->dados_jogadores.posicao_jogador);
        printf("Valor de Venda: R$ %.2f\n", jogador->dados_jogadores.valor_venda);
        printf("Valor de Aquisicao: R$ %.2f\n", jogador->dados_jogadores.valor_aquisicao);
        printf("Salario: R$ %.2f\n", jogador->dados_jogadores.salario);
        
        if (jogador->dados_jogadores.status == INATIVO) {
            printf("Status: Inativo");
            if (jogador->dados_jogadores.status_2 == RECUPERACAO) {
                printf(", em recuperacao medica\n");
            } else if (jogador->dados_jogadores.status_2 == VENDIDO) {
                printf(", jogador vendido\n");
            }
        } else {
            printf("Status: Ativo\n");
        }
        printf("-----------------------------------------------------------\n");
    }
}

void detalhes_mostrar_jogador_h(FILE *output, bool eh_csv, bool eh_html)
{
    if(eh_csv)
    {
        fprintf(output, "Nome;ID;Idade;Altura;Peso;Posicao;Valor Venda;Valor Aquisicao;Salario;Status;Motivo Inativacao\n");
    } 
    else if (eh_html) 
    {
        fprintf(output, "    <thead>\n");
        fprintf(output, "      <tr>\n");
        fprintf(output, "        <th>Nome</th>\n");
        fprintf(output, "        <th>ID</th>\n");
        fprintf(output, "        <th>Idade</th>\n");
        fprintf(output, "        <th>Altura</th>\n");
        fprintf(output, "        <th>Peso</th>\n");
        fprintf(output, "        <th>Posicao</th>\n");
        fprintf(output, "        <th>Valor de Venda</th>\n");
        fprintf(output, "        <th>Valor de Aquisicao</th>\n");
        fprintf(output, "        <th>Salario</th>\n");
        fprintf(output, "        <th>Status</th>\n");
        fprintf(output, "        <th>Motivo Inativacao</th>\n");
        fprintf(output, "      </tr>\n");
        fprintf(output, "    </thead>\n");
        fprintf(output, "    <tbody>\n");
    } 
    else
    {
        printf("%-20s %-5s %-4s %-6s %-6s %-15s %-12s %-12s %-10s %s\n",
               "Nome", "ID", "Idade", "Altura", "Peso", "Posicao", 
               "V.Venda", "V.Aquis.", "Salario", "Status");
        printf("------------------------------------------------------------------------------------------------------\n");
    }
}

void listar_jogadores(no_jogadores_t *ptr_lista_jogadores)
{
    msg_cabecalho("RELATORIO COMPLETO DE JOGADORES");

    if(ptr_lista_jogadores == NULL)
    {
        printf("Nenhum jogador cadastrado\n");
        msg_press_enter();
        return;
    }

    uint8_t opc;
    FILE *output = stdout;
    string file_nome;
    bool eh_csv = false;
    bool eh_html = false;

    printf("Escolha o tipo de saida:\n");
    printf("[1] Exibir na Tela\n");
    printf("[2] Salvar em Arquivo CSV\n");
    printf("[3] Salvar em Arquivo HTML\n");
    printf("Opcao: ");
    scanf("%hhu", &opc);
    getchar();

    switch(opc)
    {
        case 1: 
            break;

        case 2: 
            eh_csv = true;
            printf("Nome do arquivo CSV (exemplo: jogadores.csv): ");
            fgets(file_nome, T_STR, stdin);
            retirar_enter(file_nome);

            output = fopen(file_nome, "w");
            if(output == NULL)
            {
                printf("Erro, nao foi possivel abrir o arquivo %s\n", file_nome);
                msg_press_enter();
                return;
            }
            break;

        case 3: 
            eh_html = true;
            printf("Nome do arquivo HTML (exemplo: jogadores.html): ");
            fgets(file_nome, T_STR, stdin);
            retirar_enter(file_nome);

            output = fopen(file_nome, "w");
            if(output == NULL)
            {
                printf("Erro, nao foi possivel abrir o arquivo %s\n", file_nome);
                msg_press_enter();
                return;
            }

            fprintf(output, "<!DOCTYPE html>\n");
            fprintf(output, "<html lang=\"pt-BR\">\n");
            fprintf(output, "<head>\n");
            fprintf(output, "  <meta charset=\"UTF-8\">\n");
            fprintf(output, "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
            fprintf(output, "  <title>Relatorio de Jogadores</title>\n");
            fprintf(output, "  <style>\n");
            fprintf(output, "    body { font-family: sans-serif; margin: 20px; }\n");
            fprintf(output, "    table { width: 100%%; border-collapse: collapse; margin-top: 20px; }\n");
            fprintf(output, "    th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }\n");
            fprintf(output, "    th { background-color: #f2f2f2; }\n");
            fprintf(output, "  </style>\n");
            fprintf(output, "</head>\n");
            fprintf(output, "<body>\n");
            fprintf(output, "  <h1>Relatorio Completo de Jogadores</h1>\n");
            fprintf(output, "  <table>\n");
            break;

        default:
            printf("Opcao invalida. Retornando ao menu principal.\n");
            msg_press_enter();
            return;
    }

    if(!eh_csv && !eh_html)
    {
        printf("-----------------------------------------------------------\n");
    }
    detalhes_mostrar_jogador_h(output, eh_csv, eh_html);

    no_jogadores_t *jogador_atual = ptr_lista_jogadores;
    while (jogador_atual != NULL)
    {
        detalhes_mostrar_jogadores(output, jogador_atual, eh_csv, eh_html);
        jogador_atual = jogador_atual->proximo;
    }
    
    if(eh_html)
    {
        fprintf(output, "    </tbody>\n");
        fprintf(output, "  </table>\n");
        fprintf(output, "</body>\n");
        fprintf(output, "</html>\n");
    }
    

    if(output != stdout)
    {
        fclose(output);
    }


    if(!eh_csv && !eh_html)
    {
        msg_press_enter();
    } 
    else
    {
        printf("Relatorio de jogadores exportado com sucesso!\n");
        msg_press_enter();
    }
}

void relatorio_faixa_idades(no_jogadores_t *ptr_lista_jogadores, int idadeMin, int idadeMax)
{
    msg_cabecalho("RELATORIO DE JOGADORES POR FAIXA DE IDADE");
    if(ptr_lista_jogadores == NULL)
    {
        printf("Nenhum jogador cadastrado\n");
        msg_press_enter();
        return;
    }

    uint8_t opc;
    FILE *output = stdout;
    string file_nome;
    bool eh_csv = false;

    printf("Escolha o tipo de saida:\n");
    printf("[1] Exibir na Tela\n");
    printf("[2] Salvar em Arquivo CSV\n");
    printf("Opcao: ");
    scanf("%hhu", &opc);
    int c; while((c = getchar()) != '\n' && c != EOF);

    switch(opc)
    {
        case 1: 
            break;

        case 2: 
            eh_csv = true;
            printf("Nome do arquivo CSV (exemplo: jogadores_idade.csv): ");
            fgets(file_nome, T_STR, stdin);
            retirar_enter(file_nome);

            output = fopen(file_nome, "w");
            if(output == NULL)
            {
                printf("Erro, nao foi possivel abrir o arquivo %s\n", file_nome);
                msg_press_enter();
                return;
            }
            break;

        default:
            printf("Opcao invalida. Retornando ao menu principal.\n");
            msg_press_enter();
            return;
    }

    printf("Digite a faixa de idade:\n");
    printf("Idade minima: ");
    scanf("%d", &idadeMin);
    while((c = getchar()) != '\n' && c != EOF);
    
    printf("Idade maxima: ");
    scanf("%d", &idadeMax);
    while((c = getchar()) != '\n' && c != EOF);

    detalhes_mostrar_jogador_h(output, eh_csv, false); 

    no_jogadores_t *jogador_atual = ptr_lista_jogadores;
    bool achou = false;

    while(jogador_atual != NULL)
    {
        if(jogador_atual->dados_jogadores.idade >= idadeMin && jogador_atual->dados_jogadores.idade <= idadeMax)
        {
            detalhes_mostrar_jogadores(output, jogador_atual, eh_csv, false);
            achou = true;
        }
        jogador_atual = jogador_atual->proximo;
    }

    if(!achou)
    {
        if(output == stdout) {
            printf("Nenhum jogador encontrado na faixa de idade entre %d e %d.\n", idadeMin, idadeMax);
        } else {
            fprintf(output, "Nenhum jogador encontrado na faixa de idade entre %d e %d.\n", idadeMin, idadeMax);
        }
    }

    if(output != stdout)
    {
        fclose(output);
    }

    if(output == stdout)
    {
        msg_press_enter();
    } else
    {
        printf("Relatorio de jogadores por faixa de idade exportado com sucesso!\n");
        msg_press_enter();
    }
}

void listar_jogadores_vendidos(no_jogadores_t *ptr_lista_jogadores )
{
    msg_cabecalho("RELATORIO DE JOGADORES VENDIDOS");
    if(ptr_lista_jogadores == NULL)
    {
        printf("Nenhum jogador cadastrado\n");
        msg_press_enter();
        return;
    }

    uint8_t opc;
    FILE *output = stdout;
    string file_nome;
    bool eh_csv = false;

    printf("Escolha o tipo de saida:\n");
    printf("[1] Exibir na Tela\n");
    printf("[2] Salvar em Arquivo CSV\n");
    printf("Opcao: ");
    scanf("%hhu", &opc);
    int c; while((c = getchar()) != '\n' && c != EOF);

    switch(opc)
    {
        case 1: 
            break;

        case 2: 
            eh_csv = true;
            printf("Nome do arquivo CSV (exemplo: jogadores_vendidos.csv): ");
            fgets(file_nome, T_STR, stdin);
            retirar_enter(file_nome);

            output = fopen(file_nome, "w");
            if(output == NULL)
            {
                printf("Erro, nao foi possivel abrir o arquivo %s\n", file_nome);
                msg_press_enter();
                return;
            }
            break;

        default:
            printf("Opcao invalida. Retornando ao menu principal.\n");
            msg_press_enter();
            return;
    }

    detalhes_mostrar_jogador_h(output, eh_csv, false);

    no_jogadores_t *jogador_atual = ptr_lista_jogadores;
    bool achou = false;

    while(jogador_atual != NULL)
    {
        if(jogador_atual->dados_jogadores.status == INATIVO && jogador_atual->dados_jogadores.status_2 == VENDIDO)
        {
            detalhes_mostrar_jogadores(output, jogador_atual, eh_csv, false);
            achou = true;
        }
        jogador_atual = jogador_atual->proximo;
    }

    if(!achou)
    {
        if(output == stdout) {
            printf("Nenhum jogador vendido encontrado.\n");
        } else {
            fprintf(output, "Nenhum jogador vendido encontrado.\n");
        }
    }

    if(output != stdout)
    {
        fclose(output);
    }

    if(output == stdout)
    {
        msg_press_enter();
    } else
    {
        printf("Relatorio de jogadores vendidos exportado com sucesso!\n");
        msg_press_enter();
    }
}

void relatorio_valor_time(no_jogadores_t *ptr_lista_jogadores)
{
    msg_cabecalho("RELATORIO DO VALOR DO TIME");
    if(ptr_lista_jogadores == NULL)
    {
        printf("Nenhum jogador cadastrado\n");
        msg_press_enter();
        return;
    }

    uint8_t opc;
    FILE *output = stdout;
    string file_nome;
    bool eh_csv = false;

    printf("Escolha o tipo de saida:\n");
    printf("[1] Exibir na Tela\n");
    printf("[2] Salvar em Arquivo CSV\n");
    printf("Opcao: ");
    scanf("%hhu", &opc);
    int c; while((c = getchar()) != '\n' && c != EOF);

    switch(opc)
    {
        case 1: 
            break;

        case 2: 
            eh_csv = true;
            printf("Nome do arquivo CSV (exemplo: valor_time.csv): ");
            fgets(file_nome, T_STR, stdin);
            retirar_enter(file_nome);

            output = fopen(file_nome, "w");
            if(output == NULL)
            {
                printf("Erro, nao foi possivel abrir o arquivo %s\n", file_nome);
                msg_press_enter();
                return;
            }
            break;

        default:
            printf("Opcao invalida. Retornando ao menu principal.\n");
            msg_press_enter();
            return;
    }

    float valor_total_time = 0;
    no_jogadores_t *jogador_atual = ptr_lista_jogadores;

    while(jogador_atual != NULL)
    {
        if(jogador_atual->dados_jogadores.status == ATIVO || jogador_atual->dados_jogadores.status_2 == RECUPERACAO)
        {
            valor_total_time += jogador_atual->dados_jogadores.valor_aquisicao;
        }
        jogador_atual = jogador_atual->proximo;
    }

    if(eh_csv)
    {
        fprintf(output, "Valor Total do Time\n");
        fprintf(output, "R$ %.2f\n", valor_total_time);
    } else
    {
        printf("\nO valor do time (considerando jogadores ativos e em recuperacao) e de: R$ %.2f\n", valor_total_time);
    }

    if(output != stdout)
    {
        fclose(output);
    }

    if(output == stdout)
    {
        msg_press_enter();
    } else
    {
        printf("Relatorio de valor do time exportado com sucesso!\n");
        msg_press_enter();
    }
}

void relatorio_partidas_resultado(no_jogos_t *ptr_lista_jogos)
{
    msg_cabecalho("RELATORIO DE RESULTADO DAS PARTIDAS");
    if(ptr_lista_jogos == NULL)
    {
        printf("Nenhum jogo cadastrado\n");
        msg_press_enter();
        return;
    }

    uint8_t opc;
    FILE *output = stdout;
    string file_nome;
    bool eh_csv = false;

    printf("Escolha o tipo de saida:\n");
    printf("[1] Exibir na Tela\n");
    printf("[2] Salvar em Arquivo CSV\n");
    printf("Opcao: ");
    scanf("%hhu", &opc);
    int c; while((c = getchar()) != '\n' && c != EOF);

    switch(opc)
    {
        case 1: 
            break;

        case 2: 
            eh_csv = true;
            printf("Nome do arquivo CSV (exemplo: resultados_partidas.csv): ");
            fgets(file_nome, T_STR, stdin);
            retirar_enter(file_nome);

            output = fopen(file_nome, "w");
            if(output == NULL)
            {
                printf("Erro, nao foi possivel abrir o arquivo %s\n", file_nome);
                msg_press_enter();
                return;
            }
            break;

        default:
            printf("Opcao invalida. Retornando ao menu principal.\n");
            msg_press_enter();
            return;
    }
    
    detalhes_mostrar_jogo_h(output, eh_csv, false);

    no_jogos_t *jogo_atual = ptr_lista_jogos;
    int vitorias = 0;
    int derrotas = 0;
    int empates = 0;

    while(jogo_atual != NULL)
    {
        detalhes_mostrar_jogos(output, jogo_atual, eh_csv, false);
        
        if (strcasecmp(jogo_atual->dados_jogos.resultado, "Vitoria") == 0)
        {
            vitorias++;
        } else if (strcasecmp(jogo_atual->dados_jogos.resultado, "Derrota") == 0)
        {
            derrotas++;
        } else if (strcasecmp(jogo_atual->dados_jogos.resultado, "Empate") == 0)
        {
            empates++;
        }
        jogo_atual = jogo_atual->proximo;
    }

    if(eh_csv)
    {
        fprintf(output, "\nResumo dos Resultados\n");
        fprintf(output, "Vitorias;%d\n", vitorias);
        fprintf(output, "Derrotas;%d\n", derrotas);
        fprintf(output, "Empates;%d\n", empates);
    } else
    {
        printf("\nResumo dos Resultados:\n");
        printf("Vitórias: %d\n", vitorias);
        printf("Derrotas: %d\n", derrotas);
        printf("Empates: %d\n", empates);
        printf("\n");
    }

    if(output != stdout)
    {
        fclose(output);
    }

    if(output == stdout)
    {
        msg_press_enter();
    } else
    {
        printf("Relatorio de resultados de partidas exportado com sucesso!\n");
        msg_press_enter();
    }
}

void relatorio_confrontos_time_adversario(no_jogos_t *ptr_lista_jogos)
{
    msg_cabecalho("RELATORIO DE CONFRONTOS POR TIME ADVERSARIO");
    if(ptr_lista_jogos == NULL)
    {
        printf("Nenhum jogo cadastrado\n");
        msg_press_enter();
        return;
    }

    uint8_t opc;
    FILE *output = stdout;
    string file_nome;
    bool eh_csv = false;

    printf("Escolha o tipo de saida:\n");
    printf("[1] Exibir na Tela\n");
    printf("[2] Salvar em Arquivo CSV\n");
    printf("Opcao: ");
    scanf("%hhu", &opc);
    int c; while((c = getchar()) != '\n' && c != EOF); 

    switch(opc)
    {
        case 1: 
            break;

        case 2: 
            eh_csv = true;
            printf("Nome do arquivo CSV (exemplo: confrontos.csv): ");
            fgets(file_nome, T_STR, stdin);
            retirar_enter(file_nome);

            output = fopen(file_nome, "w");
            if(output == NULL)
            {
                printf("Erro, nao foi possivel abrir o arquivo %s\n", file_nome);
                msg_press_enter();
                return;
            }
            break;

        default:
            printf("Opcao invalida. Retornando ao menu principal.\n");
            msg_press_enter();
            return;
    }

    string nome_time_adversario_busca;
    printf("Digite o nome do time adversario para a busca: ");
    fgets(nome_time_adversario_busca, T_STR, stdin);
    retirar_enter(nome_time_adversario_busca);

    if(output == stdout) {
        printf("\nResultados da busca de jogos por '%s' (NOME DO TIME ADVERSARIO):\n", nome_time_adversario_busca);
        printf("-----------------------------------------------------------\n");
    } else if (eh_csv) {
        fprintf(output, "Resultados da busca de jogos por '%s' (NOME DO TIME ADVERSARIO)\n", nome_time_adversario_busca);
    }

    detalhes_mostrar_jogo_h(output, eh_csv, false);

    no_jogos_t *jogo_atual = ptr_lista_jogos;
    bool achou = false;
    int vitorias = 0;
    int derrotas = 0;
    int empates = 0;

    while(jogo_atual != NULL)
    {
        if(string_case_compare(jogo_atual->dados_jogos.nome_time_adversario, nome_time_adversario_busca) == 0)
        {
            detalhes_mostrar_jogos(output, jogo_atual, eh_csv, false);
            
            if (strcasecmp(jogo_atual->dados_jogos.resultado, "Vitoria") == 0)
            {
                vitorias++;
            } else if (strcasecmp(jogo_atual->dados_jogos.resultado, "Derrota") == 0)
            {
                derrotas++;
            } else if (strcasecmp(jogo_atual->dados_jogos.resultado, "Empate") == 0)
            {
                empates++;
            }
            achou = true;
        }
        jogo_atual = jogo_atual->proximo;
    }

    if(achou)
    {
        if(eh_csv)
        {
            fprintf(output, "\nResumo dos Resultados contra '%s'\n", nome_time_adversario_busca);
            fprintf(output, "Vitorias;%d\n", vitorias);
            fprintf(output, "Derrotas;%d\n", derrotas);
            fprintf(output, "Empates;%d\n", empates);
        } else
        {
            printf("\nResumo dos Resultados contra '%s':\n", nome_time_adversario_busca);
            printf("Vitórias: %d\n", vitorias);
            printf("Derrotas: %d\n", derrotas);
            printf("Empates: %d\n", empates);
            printf("\n");
        }
    } else
    {
        if(output == stdout) {
            printf("Nenhum jogo encontrado contra o time: '%s'.\n", nome_time_adversario_busca);
        } else {
            fprintf(output, "Nenhum jogo encontrado contra o time: '%s'.\n", nome_time_adversario_busca);
        }
    }

    if(output != stdout)
    {
        fclose(output);
    }

    if(output == stdout)
    {
        msg_press_enter();
    } else
    {
        printf("Relatorio de confrontos por time adversario exportado com sucesso!\n");
        msg_press_enter();
    }
}

void relatorio_aproveitamento_time(no_jogos_t *ptr_lista_jogos)
{
    msg_cabecalho("RELATORIO DE APROVEITAMENTO DO TIME");
    if(ptr_lista_jogos == NULL)
    {
        printf("Nenhum jogo cadastrado\n");
        msg_press_enter();
        return;
    }

    uint8_t opc;
    FILE *output = stdout;
    string file_nome;
    bool eh_csv = false;

    printf("Escolha o tipo de saida:\n");
    printf("[1] Exibir na Tela\n");
    printf("[2] Salvar em Arquivo CSV\n");
    printf("Opcao: ");
    scanf("%hhu", &opc);
    int c; while((c = getchar()) != '\n' && c != EOF); 

    switch(opc)
    {
        case 1: 
            break;

        case 2: 
            eh_csv = true;
            printf("Nome do arquivo CSV (exemplo: aproveitamento_time.csv): ");
            fgets(file_nome, T_STR, stdin);
            retirar_enter(file_nome);

            output = fopen(file_nome, "w");
            if(output == NULL)
            {
                printf("Erro, nao foi possivel abrir o arquivo %s\n", file_nome);
                msg_press_enter();
                return;
            }
            break;

        default:
            printf("Opcao invalida. Retornando ao menu principal.\n");
            msg_press_enter();
            return;
    }

    int total_jogos = 0;
    int vitorias = 0;
    no_jogos_t *jogo_atual = ptr_lista_jogos;

    while(jogo_atual != NULL)
    {
        total_jogos++;
        if (strcasecmp(jogo_atual->dados_jogos.resultado, "Vitoria") == 0)
        {
            vitorias++;
        }
        jogo_atual = jogo_atual->proximo;
    }

    float aproveitamento = 0.0;
    if (total_jogos > 0)
    {
        aproveitamento = (float)vitorias / total_jogos * 100;
    }

    if(eh_csv)
    {
        fprintf(output, "Total de Jogos;Vitorias;Aproveitamento\n");
        fprintf(output, "%d;%d;%.2f%%\n", total_jogos, vitorias, aproveitamento);
    } else
    {
        printf("\nTotal de Jogos Realizados: %d\n", total_jogos);
        printf("Total de Vitórias: %d\n", vitorias);
        printf("Aproveitamento do Time: %.2f%%\n", aproveitamento);
        printf("\n");
    }

    if(output != stdout)
    {
        fclose(output);
    }

    if(output == stdout)
    {
        msg_press_enter();
    } else
    {
        printf("Relatorio de aproveitamento do time exportado com sucesso!\n");
        msg_press_enter();
    }
}
