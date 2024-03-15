#ifndef MATERIAIS_H
#define MATERIAIS_H
#include "secao.h"

/*Nono tipo de estrutura material. Armazena os informações dos materiais.
*/
struct material{
  char nome[50];
  char tipo[50];
  float preco;
  int qtdEstoque;
};

  typedef struct material Material;

/*Função para adicionar materiais.
*/
void adicionar_material(Secao* secao, char nome[50], char tipo[50], float preco,int qtdEstoque);

/*Função para remover materiais
*/
void remover_material(Material * material, Secao * secao);


/*Função para buscar materiais.
*/
void buscar_material(Material * material);

#endif