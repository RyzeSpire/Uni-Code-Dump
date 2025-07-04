#include "../include/menus.h"

uint8_t menu_principal()
{
    limpar_tela();

    uint8_t opcao;

    printf("\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("__________}=[Gerenciador de Time]={____________\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("\n");
    printf("___[1]. Cadastros..............................\n");
    printf("___[2]. Relatórios.............................\n");
    printf("___[3]. Buscas.................................\n");
    printf("___[4]. Manipular Arquivos.....................\n");
    printf("\n");
    printf("|/////////////////////////////////////////////|\n");
    printf("\n");
    printf("___[0]. Sair...................................\n");
    printf("\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;
}
uint8_t menu_cadastros()
{
    limpar_tela();

    uint8_t opcao;

    printf("\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("________________}=[Cadastro]={_________________\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("\n");
    printf("___[1]. Cadastrar Jogador......................\n");
    printf("___[2]. Cadastrar Jogo Realizado...............\n");
    printf("___[3]. Inativar Jogador.......................\n");
    printf("\n");
    printf("|/////////////////////////////////////////////|\n");
    printf("\n");
    printf("___[0]. Voltar.................................\n");
    printf("\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;
}

uint8_t menu_relatorios()
{
    limpar_tela();

    uint8_t opcao;

    printf("\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("_______________}=[Relatorios]={________________\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("\n");
    printf("___[1]. Relatorio completo dos Jogadores.......\n");
    printf("___[2]. Relatorio de Jogadores por idade.......\n");
    printf("___[3]. Relatorio de resultado das partidas....\n");
    printf("___[4]. Relatorio de confrontos com adversarios\n");
    printf("___[5]. Relatorio de jogadores vendidos........\n");
    printf("___[6]. Relatorio do valor do time.............\n");
    printf("___[7]. Relatorio de aproveitamento do time....\n");
    printf("\n");
    printf("|/////////////////////////////////////////////|\n");
    printf("\n");
    printf("___[0]. Voltar.................................\n");
    printf("\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;
}

uint8_t menu_buscas()
{
    limpar_tela();

    uint8_t opcao;

    printf("\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("__________________}=[Buscas]={_________________\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("\n");
    printf("___[1]. Localizar jogador por nome.............\n");
    printf("___[2]. Localizar jogadores por posicao........\n");
    printf("___[3]. Localizar jogos por time adversario....\n");
    printf("___[4]. Localizar jogador com maior salario....\n");
    printf("___[5]. Localizar jogadores por faixa salarial.\n");
    printf("\n");
    printf("|/////////////////////////////////////////////|\n");
    printf("\n");
    printf("___[0]. Voltar.................................\n");
    printf("\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;
}


uint8_t menu_manipulacao_arquivos() //salvar os dados para que eles sejam carregados novamente quando o programa for aberto de novo
{
    limpar_tela();

    uint8_t opcao;

    printf("\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("__________}=[Manipulacao de Arquivos]={________\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("\n");
    printf("___[1]. Salvar Jogadores em arquivo binario....\n");
    printf("___[2]. Salvar Jogos em arquivo binario........\n");
    printf("\n");
    printf("|/////////////////////////////////////////////|\n");
    printf("\n");
    printf("___[0]. Voltar.................................\n");
    printf("\n");
    printf("|/||/||/||/||/||/||/||/||/||/||/||/||/||/||/||/\n");
    printf("\n");
    printf("::: ");
    scanf("%hhi", &opcao);
    getchar();

    return opcao;
}

