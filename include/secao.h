#ifndef SECAO_H
#define SECAO_H

#include "listaencadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_material NoMaterial;

struct secao {
  char nome[50];
  char local[50];
  NoMaterial *materiais;
};

typedef struct secao Secao;

ListaSecoes *criarSecao(char nome[50], char local[50], ListaSecoes *lista);

#endif
