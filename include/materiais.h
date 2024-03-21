#ifndef MATERIAIS_H
#define MATERIAIS_H

#include "secao.h" // Inclui a definição da estrutura Secao

// Definição da estrutura Material
struct material {
  char nome[50];     // Nome do material
  char tipo[50];     // Tipo do material
  float preco;       // Preço do material
  int qtdEstoque;    // Quantidade em estoque do material
};

typedef struct material Material; // Define o tipo Material

// Definição da estrutura NoMaterial para a lista de materiais
struct no_material {
  Material *material;           // Ponteiro para o material
  struct no_material *prox;     // Ponteiro para o próximo nó na lista
};

typedef struct no_material NoMaterial; // Define o tipo NoMaterial

/**
 * @brief Adiciona um novo material a uma seção.
 * 
 * @param secao Ponteiro para a seção onde o material será adicionado.
 * @param nome Nome do material a ser adicionado.
 * @param tipo Tipo do material a ser adicionado.
 * @param preco Preço do material a ser adicionado.
 * @param qtdEstoque Quantidade em estoque do material a ser adicionado.
 */
void adicionar_material(Secao *secao, char nome[50], char tipo[50], float preco, int qtdEstoque);

/**
 * @brief Remove um material de uma seção.
 * 
 * @param material Ponteiro para o material a ser removido.
 * @param secao Ponteiro para a seção onde o material está localizado.
 */
void remover_material(Material *material, Secao *secao);

/**
 * @brief Busca por um material em todas as seções.
 * 
 * @param material Ponteiro para o material a ser buscado.
 * @param listaSecoes Ponteiro para a lista de seções onde será realizada a busca.
 */
void buscar_material(Material *material, ListaSecoes *listaSecoes);

/**
 * @brief Imprime a lista de materiais de uma seção.
 * 
 * @param secao Ponteiro para a seção cuja lista de materiais será impressa.
 */
void imprimirListaMateriais(Secao *secao);

#endif

