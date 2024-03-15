#ifndef SECAO_H
#define SECAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/listaencadeada.h"

struct secao {
    char nome[50];
    char local[50];
};

typedef struct secao Secao;

void criarSecao(char nome[50], char local[50], ListaSecoes *lista);

#endif
