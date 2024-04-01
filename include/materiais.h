#ifndef MATERIAL_H
#define MATERIAL_H

#include "secao.h"

// Estrutura para representar um material
typedef struct material {
    char nome[50];
    char tipo[50];
    float preco;
    int quantidade;
    struct material *prox;
} Material;

// Protótipos das funções relacionadas a materiais
void adicionarMaterial(Material **head, Secao **secoes);
void removerMaterial(Material **head);
void realizarVenda(Material **head);
void buscarMaterial(Material *head);

#endif /* MATERIAL_H */

