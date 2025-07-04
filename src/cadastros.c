#include "../include/cadastros.h"
#include "../include/utils.h"


//funcoes de data management
bool is_lista_jogos_vazia(no_jogos_t *ptr_lista_jogos)
{
    if(ptr_lista_jogos) return false; //lista nao vazia

    return true; //lista vazia
}
bool is_lista_jogadores_vazia(no_jogadores_t *ptr_lista_jogadores)
{
    if(ptr_lista_jogadores) return false; //lista nao vazia
    
    return true; //lista vazia
}

void inicializa_lista_jogos(lista_t *lista_jogos)
{
    lista_jogos->cabeca_jogos = NULL;
    lista_jogos->nr_nos_jogos = 0;
}
void inicializa_lista_jogadores(lista_t *lista_jogadores)
{
    lista_jogadores->cabeca_jogadores = NULL;
    lista_jogadores->nr_nos_jogadores = 0;
}

no_jogos_t *localizar_ultimo_registro_jogos(no_jogos_t *ptr_lista_jogos)
{
    if(ptr_lista_jogos == NULL) return NULL;
    
    while(ptr_lista_jogos->proximo)
    {
        ptr_lista_jogos = ptr_lista_jogos->proximo;
    }

    return ptr_lista_jogos;
}
no_jogadores_t *localizar_ultimo_registro_jogadores(no_jogadores_t *ptr_lista_jogadores)
{
    if(ptr_lista_jogadores == NULL) return NULL;

    while(ptr_lista_jogadores->proximo)
    {
        ptr_lista_jogadores = ptr_lista_jogadores->proximo;
    }
    return ptr_lista_jogadores;

}

//O cadastro em si
no_jogos_t *novo_registro_jogos(lista_t *lista)
{
    no_jogos_t *novo_jogo;
    
    //aloca um novo registro na heap
    novo_jogo = (no_jogos_t*)malloc(sizeof(no_jogos_t));

    if(!novo_jogo) return NULL;

    //interage com o usuario

    printf("Cadastrar jogo\n");
    
    //nome do time adversario
    printf("\nNome do time adversario: ");
    fgets(novo_jogo->dados_jogos.nome_time_adversario, T_STR, stdin);
    retirar_enter(novo_jogo->dados_jogos.nome_time_adversario);

    printf("Data do jogo:\n");
	scanf("%d/%d/%d",&novo_jogo->dados_jogos.data.dia_jogo,&novo_jogo->dados_jogos.data.mes_jogo,&novo_jogo->dados_jogos.data.ano_jogo);
    getchar();

    //local do jogo
    printf("Local do jogo: ");
    fgets(novo_jogo->dados_jogos.local_jogo, T_STR, stdin);
    retirar_enter(novo_jogo->dados_jogos.local_jogo);
    

    //resultado do jogo
    printf("Resultado do jogo: ");
    fgets(novo_jogo->dados_jogos.resultado, T_STR, stdin);
    retirar_enter(novo_jogo->dados_jogos.resultado);
    

    //time escalados
    printf("Escalamento do time: ");
    no_jogadores_t *jogador_atual = lista->cabeca_jogadores;
    //listagem dos jogadores desponiveis para escalar
    if(lista->nr_nos_jogadores == 0)
    {
        printf("Nenhum jogador cadastrado para escalar.\n");
        return NULL;
    }

    printf("\n--- Jogadores ativos Cadastrados (Nome, ID, Posicao, Status) ---\n");
    printf("%-20s %-5s %-15s %s\n", "|Nome", "ID", "Posicao", "Status");
    printf("-----------------------------------------------------------\n");

    while(jogador_atual != NULL)
    {
        if(jogador_atual->dados_jogadores.status == ATIVO)
        {
        printf("%-20s %-5u %-15s ", jogador_atual->dados_jogadores.nome,jogador_atual->dados_jogadores.id_jogador, jogador_atual->dados_jogadores.posicao_jogador);
        printf("Ativo\n");
        }
        jogador_atual = jogador_atual->proximo;
    }
    printf("-----------------------------------------------------------\n\n");
    
    //o proprio escalamnto
printf("---Escalar Jogadores---\n");

uint32_t id_temp_jogos;
int jogadores_adicionados_atuais = 0;
novo_jogo->dados_jogos.qtd_jogadores_escalados = 0;

while(jogadores_adicionados_atuais < MAX_JOG)
{
    printf("ID do Jogador #%d (pressione 0 para finalizar): ", jogadores_adicionados_atuais + 1);
    scanf("%u", &id_temp_jogos);
    getchar();

    if (id_temp_jogos == 0) 
    { 
        break;
    }

    no_jogadores_t *jogador_achou = localizar_jogador_por_id(lista, id_temp_jogos);

    if (jogador_achou != NULL)
    {
        bool ja_esta_na_lsta = false;
        for (int i = 0; i < jogadores_adicionados_atuais; i++) {
            if (novo_jogo->dados_jogos.ids_jogadores_escalados[i] == id_temp_jogos) {
               ja_esta_na_lsta = true;
                break;
            }
        }

        if (ja_esta_na_lsta) {
            printf("Jogador '%s' (ID: %u) ja esta na escalacao.\n", jogador_achou->dados_jogadores.nome, jogador_achou->dados_jogadores.id_jogador);
        } else if (jogador_achou->dados_jogadores.status == ATIVO) 
        {
            novo_jogo->dados_jogos.ids_jogadores_escalados[jogadores_adicionados_atuais] = id_temp_jogos;
            jogadores_adicionados_atuais++;
            novo_jogo->dados_jogos.qtd_jogadores_escalados = jogadores_adicionados_atuais;
            printf("Jogador '%s' (ID: %u) adicionado a escalacao.\n", jogador_achou->dados_jogadores.nome, jogador_achou->dados_jogadores.id_jogador);
        } else 
        {
            printf("Jogador '%s' (ID: %u) nao esta ATIVO. Tente outro ID.\n", jogador_achou->dados_jogadores.nome, jogador_achou->dados_jogadores.id_jogador);
        }
    } else
    {
        printf("ID %u nao foi achado. Tente outro ID.\n", id_temp_jogos);
    }
}

if(jogadores_adicionados_atuais == 11)
{
    printf("Minimo de jogadores atingido, pressione 0 para finalizar ou continue\n");
}


        
    //fim do escalamento de jogadores

    //quantidade de substituicoes
    printf("Quantidades de substituicoes do time de casa: ");
    scanf("%d", &novo_jogo->dados_jogos.qtd_subst);
    getchar();

    //inicializar o ponteiro proximo
    novo_jogo->proximo = NULL;

    return novo_jogo;
}

no_jogadores_t *novo_registro_jogadores()
{
    char opc;
    no_jogadores_t *novo_jogador;
    
    //aloca um novo registro na heap
    novo_jogador = (no_jogadores_t*)malloc(sizeof(no_jogadores_t));


    if (!novo_jogador) return NULL;

    //interage com o usuario

    getchar();
    printf("Cadastro de Jogador\n");

    //nome
    printf("Nome do jogador: ");
    fgets(novo_jogador->dados_jogadores.nome, T_STR, stdin);
    retirar_enter(novo_jogador->dados_jogadores.nome);

    //identificador
    printf("presione enter para gerar o id do jogador: ");
    getchar();
    srand(time(NULL));
    int id_temp = 10000 + rand() % 90000;
    novo_jogador->dados_jogadores.id_jogador = id_temp;

    //idade
    printf("Idade: ");
    scanf("%d", &novo_jogador->dados_jogadores.idade);
    getchar();
    
    //altura
    printf("Altura: ");
    scanf("%f", &novo_jogador->dados_jogadores.altura);
    getchar();

    //peso
    printf("Peso: ");
    scanf("%f", &novo_jogador->dados_jogadores.peso);
    getchar();

    //posicao
    printf("Posicao: ");
    fgets(novo_jogador->dados_jogadores.posicao_jogador,T_STR,stdin);
    retirar_enter(novo_jogador->dados_jogadores.posicao_jogador);

    //valor de compra
    printf("Valor de aquisicao: ");
    scanf("%f", &novo_jogador->dados_jogadores.valor_aquisicao);
    getchar();

    //salario
    printf("Salario: ");
    scanf("%f", &novo_jogador->dados_jogadores.salario);
    getchar();



    //status
    novo_jogador->dados_jogadores.status = ATIVO;

    //inicializar o ponteiro proximo
    novo_jogador->proximo = NULL;
    return novo_jogador;

}

void insere_registro_inicio_jogos(no_jogos_t *novo_jogo, lista_t *lista_jogos)
{
    ++lista_jogos->nr_nos_jogos;

    if(is_lista_jogos_vazia(lista_jogos->cabeca_jogos))
    {
        lista_jogos->cabeca_jogos = novo_jogo;
        return;
    }

    novo_jogo->proximo = lista_jogos->cabeca_jogos;
    lista_jogos->cabeca_jogos = novo_jogo;
}
void insere_registro_inicio_jogadores(no_jogadores_t *novo_jogador, lista_t *lista_jogadores)
{
    ++lista_jogadores->nr_nos_jogadores;

    if(is_lista_jogadores_vazia(lista_jogadores->cabeca_jogadores))
    {
        lista_jogadores->cabeca_jogadores = novo_jogador;
        return;
    }

    novo_jogador->proximo = lista_jogadores->cabeca_jogadores;
    lista_jogadores->cabeca_jogadores = novo_jogador;
}

//////////////////////////////////////////////////////////////////////////////////////

void insere_registro_fim_jogos(no_jogos_t *novo_jogo, lista_t *lista_jogos)
{
   if(is_lista_jogos_vazia(lista_jogos->cabeca_jogos))
   {
    lista_jogos->cabeca_jogos = novo_jogo;
   } else 
    {
        no_jogos_t *ultimo = localizar_ultimo_registro_jogos(lista_jogos->cabeca_jogos);
        ultimo->proximo = novo_jogo;
    }
    lista_jogos->nr_nos_jogos++;
}
void insere_registro_fim_jogadores(no_jogadores_t *novo_jogador, lista_t *lista_jogadores)
{
    if(is_lista_jogadores_vazia(lista_jogadores->cabeca_jogadores))
    {
        lista_jogadores->cabeca_jogadores = novo_jogador;
    } else 
        {
            no_jogadores_t *ultimo = localizar_ultimo_registro_jogadores(lista_jogadores->cabeca_jogadores);
            ultimo->proximo = novo_jogador;
        }
        lista_jogadores->nr_nos_jogadores++;
}
//

//edicao de cadastro
void excluir_registro_jogos(no_jogos_t *registro_p_excl, lista_t *lista_jogos)
{
    if(is_lista_jogos_vazia(lista_jogos->cabeca_jogos))
    {
        printf("Erro, lista de jogos vazia");
        return;
    }

    //excluindo um no na caveca

    if(lista_jogos->cabeca_jogos == registro_p_excl)
    {
        lista_jogos->cabeca_jogos = registro_p_excl->proximo;
        free(registro_p_excl);
        lista_jogos->nr_nos_jogos--;
        printf("Registro de jogo excluido com sucesso\n");
        return;
    }

    //excluir no meio ou no fim
    no_jogos_t *atual_jogos = lista_jogos->cabeca_jogos;
    no_jogos_t *anterior_jogos = NULL;

    while(atual_jogos != NULL && atual_jogos != registro_p_excl)
    {
        anterior_jogos = atual_jogos;
        atual_jogos = atual_jogos->proximo;
    }

    if(!atual_jogos)
    {
        printf("Erro, registro de jogos nao encontrado\n");
        return;
    }

    anterior_jogos->proximo = atual_jogos->proximo;
    free(atual_jogos);
    lista_jogos->nr_nos_jogos--;
    printf("Registro de jogo excluido com sucesso\n");
}

void excluir_registro_jogadores(no_jogadores_t *registro_p_excluir, lista_t *lista_jogadores)
{
    if(is_lista_jogadores_vazia(lista_jogadores->cabeca_jogadores))
    {
        printf("Erro, lista de jogadores vazia");
        return;
    }

    //excluindo um no na cabeca

    if(lista_jogadores->cabeca_jogadores == registro_p_excluir)
    {
        lista_jogadores->cabeca_jogadores = registro_p_excluir->proximo;
        free(registro_p_excluir);
        lista_jogadores->nr_nos_jogadores--;
        printf("Registro de jogador excluido com sucesso\n");
        return;
    }

    //excluir no meio ou no fim
    no_jogadores_t *atual_jogadores = lista_jogadores->cabeca_jogadores;
    no_jogadores_t *anterior_jogadores = NULL;

    while(atual_jogadores != NULL && atual_jogadores != registro_p_excluir)
    {
        anterior_jogadores = atual_jogadores;
        atual_jogadores = atual_jogadores->proximo;
    }

    if(!atual_jogadores)
    {
        printf("Erro, registro de jogadores nao encontrado\n");
        return;
    }

    anterior_jogadores->proximo = atual_jogadores->proximo;
    free(atual_jogadores);
    lista_jogadores->nr_nos_jogadores--;
    printf("Registro de jogadore excluido com sucesso\n");
}
////////////////////////////////////////////////////////////////////////////////////
void inativar_jogador(no_jogadores_t *registro)
{
    if(registro == NULL)
    {
        printf("Erro, registro de jogador invalido");
        return;
    }

    if(registro->dados_jogadores.status == ATIVO)
    {
        printf("Inativando jogador: %s [ID: %u]\n",registro->dados_jogadores.nome,registro->dados_jogadores.id_jogador);
        registro->dados_jogadores.status = INATIVO;

        int opc;
        printf("Qual o motivo da inatividade (0 = RECUPERACAO ou 1 = VENDIDO)?\n");
        printf("Digite o numero: ");
        scanf("%d", &opc);
        getchar();

        if(opc == RECUPERACAO)
        {
            registro->dados_jogadores.status_2 = RECUPERACAO;
            printf("jogador %s inativado por recuperacao medica",registro->dados_jogadores.nome);
        } else if(opc == VENDIDO)
        {
            registro->dados_jogadores.status_2 = VENDIDO;
            printf("jogador %s inativado por ter sido cendido\n\n",registro->dados_jogadores.nome);
            printf("por quanto o jogador foi vendido?\n");
            scanf("%f", registro->dados_jogadores.valor_venda);
            printf("Valor de venda registrado: R$ %.2f\n", registro->dados_jogadores.valor_venda);

        } else
        {
            printf("opcao invalida\n");
        }
    } else
    {
        printf("jogador %s ja esta inativo",registro->dados_jogadores.nome);
    }
}
//