#ifndef SECAO_H
#define SECAO_H

#include "listaencadeada.h" // Inclui a definição da estrutura ListaSecoes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura NoMaterial para a lista de materiais
typedef struct no_material NoMaterial;

// Definição da estrutura Secao
struct secao {
  char nome[50];          // Nome da seção
  char local[50];         // Localização da seção
  NoMaterial *materiais;  // Ponteiro para a lista de materiais na seção
};

typedef struct secao Secao; // Define o tipo Secao

/**
 * @brief Cria uma nova seção e adiciona à lista de seções.
 * 
 * @param nome Nome da nova seção.
 * @param local Localização da nova seção.
 * @param lista Ponteiro para a lista de seções onde a nova seção será adicionada.
 * @return ListaSecoes* Ponteiro para a lista de seções atualizada.
 */
ListaSecoes *criarSecao(char nome[50], char local[50], ListaSecoes *lista);

#endif

