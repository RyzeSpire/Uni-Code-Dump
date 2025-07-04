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