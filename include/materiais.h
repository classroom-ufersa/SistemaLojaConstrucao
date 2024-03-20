#ifndef MATERIAIS_H
#define MATERIAIS_H

#include "secao.h"

struct material {
  char nome[50];
  char tipo[50];
  float preco;
  int qtdEstoque;
};

typedef struct material Material;

struct no_material {
  Material *material;
  struct no_material *prox;
};

typedef struct no_material NoMaterial;

void adicionar_material(Secao *secao, char nome[50], char tipo[50], float preco,
                        int qtdEstoque);

void remover_material(Material *material, Secao *secao);

void buscar_material(Material *material, ListaSecoes *listaSecoes);

void imprimirListaMateriais(Secao *secao);

#endif
