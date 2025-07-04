#include "../include/utils.h"

void retirar_enter(string str)
{
    if(str[strlen(str) - 1] == '\n')
    {
        *(str+strlen(str)-1) = '\0';
    }
}

int string_case_compare(const string str1, const string str2)
{
    return strcasecmp(str1, str2);
}

void limpar_tela()
{
    system("clear");
}

void msg_press_enter()
{
    printf("\n-----------------------------------------------\n");
    printf("..........Pressione ENTER para continuar.........\n");
    getchar();
}

void msg_cabecalho(string msg)
{
    printf("----------------------------------------------\n");
    printf("%s\n", msg);
    printf("----------------------------------------------\n\n");
}

void salvar_jogadores_binario(const lista_t *lista, const char *filename) 
{
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erro ao abrir arquivo para salvar jogadores");
        return;
    }

    no_jogadores_t *atual = lista->cabeca_jogadores;
    while (atual != NULL) {
        fwrite(&atual->dados_jogadores, sizeof(dados_jogadores_t), 1, file);
        atual = atual->proximo;
    }

    fclose(file);
}

void carregar_jogadores_binario(lista_t *lista, const char *filename) 
{
    FILE *file = fopen(filename, "rb");
    if (!file) 
    {
        return;
    }

    dados_jogadores_t jogador;
    while (fread(&jogador, sizeof(dados_jogadores_t), 1, file) == 1) 
    {
        no_jogadores_t *novo = malloc(sizeof(no_jogadores_t));
        if (!novo) {
            perror("Erro ao alocar memória para jogador");
            fclose(file);
            return;
        }
        novo->dados_jogadores = jogador;
        novo->proximo = NULL;

        if (lista->cabeca_jogadores == NULL) 
        {
            lista->cabeca_jogadores = novo;
        } else {
            no_jogadores_t *ultimo = lista->cabeca_jogadores;
            while (ultimo->proximo != NULL) 
            {
                ultimo = ultimo->proximo;
            }
            ultimo->proximo = novo;
        }
        lista->nr_nos_jogadores++;
    }

    fclose(file);
}

void salvar_jogos_binario(const lista_t *lista, const char *filename) 
{
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erro ao abrir arquivo para salvar jogos");
        return;
    }

    no_jogos_t *atual = lista->cabeca_jogos;
    while (atual != NULL) {
        fwrite(&atual->dados_jogos, sizeof(dados_jogos_t), 1, file);
        atual = atual->proximo;
    }

    fclose(file);
}

void carregar_jogos_binario(lista_t *lista, const char *filename) 
{
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return;
    }

    dados_jogos_t jogo;
    while (fread(&jogo, sizeof(dados_jogos_t), 1, file) == 1) 
    {
        no_jogos_t *novo = malloc(sizeof(no_jogos_t));
        if (!novo) {
            perror("Erro ao alocar memória para jogo");
            fclose(file);
            return;
        }
        novo->dados_jogos = jogo;
        novo->proximo = NULL;

        if (lista->cabeca_jogos == NULL) 
        {
            lista->cabeca_jogos = novo;
        } else {
            no_jogos_t *ultimo = lista->cabeca_jogos;
            while (ultimo->proximo != NULL) 
            {
                ultimo = ultimo->proximo;
            }
            ultimo->proximo = novo;
        }
        lista->nr_nos_jogos++;
    }

    fclose(file);
}

void exibir_jogadores_ativos(no_jogadores_t *ptr_lista_jogadores)
{
    if (ptr_lista_jogadores == NULL)
    {
        printf("Nenhum jogador cadastrado.\n");
        return;
    }

    printf("\n--- Jogadores Ativos Cadastrados (Nome, ID, Posicao, Status) ---\n");
    printf("%-20s %-5s %-15s %s\n", "Nome", "ID", "Posicao", "Status"); // Removed leading '|' for alignment
    printf("-----------------------------------------------------------\n");

    no_jogadores_t *jogador_atual = ptr_lista_jogadores;
    bool encontrou_ativo = false;

    while (jogador_atual != NULL)
    {
        // Assuming ATIVO is an enum value
        if (jogador_atual->dados_jogadores.status == ATIVO)
        {
            printf("%-20s %-5u %-15s %s\n",
                   jogador_atual->dados_jogadores.nome,
                   jogador_atual->dados_jogadores.id_jogador,
                   jogador_atual->dados_jogadores.posicao_jogador,
                   "Ativo");
            encontrou_ativo = true;
        }
        jogador_atual = jogador_atual->proximo;
    }

    if (!encontrou_ativo) {
        printf("Nenhum jogador ATIVO encontrado.\n");
    }
    printf("-----------------------------------------------------------\n\n");
}