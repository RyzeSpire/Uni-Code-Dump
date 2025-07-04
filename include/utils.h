#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include "types.h"


void retirar_enter(string str);
int string_case_compare(const string str1, const string str2);
void limpar_tela();
void msg_press_enter();
void msg_cabecalho(string msg);


#endif