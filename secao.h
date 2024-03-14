#ifndef SECAO_H
#define SECAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct secao {
    char nome[50];
    char local[50];
};

typedef struct secao Secao;

void listar_secoes();

void remover_secao(Secao* secao);

void criar_secao(char nome[50], char local[50]);

#endif
