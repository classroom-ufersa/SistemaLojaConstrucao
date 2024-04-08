#ifndef MATERIAL_H
#define MATERIAL_H

#include "secao.h"

typedef struct material {
    char nome[50];
    char tipo[50];
    float preco;
    int quantidade;
    struct material *prox;
} Material;


/*  
 * @brief Funcao para adicionar um novo material para a secao 
 *
 * @param Material **head Lista encadeada de materiais 
 * @param Secao **secoes Lista encadeada de secoes
 * 
 * @return void
 *  */
void adicionarMaterial(Secao **secoes);


/*  
 * @brief Funcao para buscar um novo material na lista de secoes
 *
 * @param head Lista encadeada de secoes
 * 
 * @return void
 *  */
void buscarMaterial(Secao *head);

/*  
 * @brief Funcao para realizar a venda de um material 
 * 
 * @param head Lista encadeada de secoes
 *
 * @return void
 *  */
void realizarVenda(Secao *head);

/*  
 * @brief Funcao para remover um material
 * 
 * @param head Lista encadeada de secoes
 * 
 * @return void
 *
 *  */
void removerMaterial(Secao *head);


#endif /* MATERIAL_H */

