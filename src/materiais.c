#include "../include/materiais.h"
#include "../include/secao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarMaterial(Secao **secoes) {
  if (*secoes == NULL) {
    printf("Erro: Não há seções para adicionar materiais.\n");
    return;
  }

  char nomeSecao[50];
  printf("Digite o nome da seção para adicionar o material: ");
  scanf(" %[^\n]", nomeSecao);

  Secao *secaoAtual = *secoes;
  while (secaoAtual != NULL && strcmp(secaoAtual->nome, nomeSecao) != 0) {
    secaoAtual = secaoAtual->prox;
  }

  if (secaoAtual == NULL) {
    printf("Erro: Seção não encontrada.\n");
    return;
  }

  Material *novoMaterial = (Material *)malloc(sizeof(Material));
  if (novoMaterial == NULL) {
    printf("Erro: Não foi possível alocar memória para o novo material.\n");
    return;
  }

  do {
    printf("Digite o nome do material: ");
    scanf(" %[^\n]", novoMaterial->nome);
    if (strlen(novoMaterial->nome) == 0) {
      printf("Erro: Nome do material não pode ser vazio.\n");
    }
  } while (strlen(novoMaterial->nome) == 0);

  do {
    printf("Digite o tipo do material: ");
    scanf(" %[^\n]", novoMaterial->tipo);
    if (strlen(novoMaterial->tipo) == 0) {
      printf("Erro: Tipo do material não pode ser vazio.\n");
    }
  } while (strlen(novoMaterial->tipo) == 0);

  printf("Digite o preço do material: ");
  scanf("%f", &novoMaterial->preco);

  do {
    printf("Digite a quantidade em estoque do material: ");
    scanf("%d", &novoMaterial->quantidade);
    if (novoMaterial->quantidade < 0) {
      printf("Erro: Quantidade em estoque não pode ser negativa.\n");
    }
  } while (novoMaterial->quantidade < 0);

  // Encontrar o ponto de inserção correto na lista de materiais da seção
  Material *atual = secaoAtual->materiais;
  Material *anterior = NULL;
  while (atual != NULL && strcmp(novoMaterial->nome, atual->nome) > 0) {
    anterior = atual;
    atual = atual->prox;
  }

  // Inserir o novo material na posição correta
  novoMaterial->prox = atual;
  if (anterior == NULL) {
    secaoAtual->materiais = novoMaterial;
  } else {
    anterior->prox = novoMaterial;
  }

  printf("Material adicionado com sucesso à seção %s.\n", nomeSecao);
}

// Função para remover um material de uma seção
void removerMaterial(Secao *head) {
    // Verifica se a lista de seções está vazia
    if (head == NULL) {
        printf("Não há seções disponíveis.\n");
        return;
    }

    char nomeMaterial[50];
    printf("Digite o nome do material que deseja remover: ");
    scanf("%s", nomeMaterial);

    // Percorre a lista de seções
    Secao *atualSecao = head;
    while (atualSecao != NULL) {
        // Verifica se há materiais na seção atual
        if (atualSecao->materiais != NULL) {
            Material *anterior = NULL;
            Material *atualMaterial = atualSecao->materiais;
            // Percorre a lista de materiais na seção atual
            while (atualMaterial != NULL) {
                // Verifica se o material atual tem o nome especificado
                if (strcmp(atualMaterial->nome, nomeMaterial) == 0) {
                    // Remove o material da lista
                    if (anterior == NULL) {
                        // Se for o primeiro material da lista
                        atualSecao->materiais = atualMaterial->prox;
                    } else {
                        anterior->prox = atualMaterial->prox;
                    }
                    free(atualMaterial);
                    printf("Material removido com sucesso.\n");
                    return;
                }
                // Avança para o próximo material
                anterior = atualMaterial;
                atualMaterial = atualMaterial->prox;
            }
        }
        // Avança para a próxima seção
        atualSecao = atualSecao->prox;
    }

    // Se o material não foi encontrado em nenhuma seção
    printf("Material não encontrado.\n");
}


void realizarVenda(Secao *head) {
    if (head == NULL) {
        printf("Erro: Não há seções para vender materiais.\n");
        return;
    }

    char nomeMaterial[50];
    printf("Digite o nome do material a ser vendido: ");
    scanf(" %[^\n]", nomeMaterial);

    Secao *atualSecao = head;
    while (atualSecao != NULL) {
        Material *atualMaterial = atualSecao->materiais;
        while (atualMaterial != NULL && strcmp(atualMaterial->nome, nomeMaterial) != 0) {
            atualMaterial = atualMaterial->prox;
        }
        if (atualMaterial != NULL) {
            int quantidade;
            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &quantidade);

            if (atualMaterial->quantidade < quantidade) {
                printf("Erro: Não há quantidade suficiente em estoque.\n");
                return;
            }

            atualMaterial->quantidade -= quantidade;
            printf("Venda realizada com sucesso.\n");
            return; // Encerra a função após a venda
        }
        atualSecao = atualSecao->prox;
    }

    printf("Erro: Material não encontrado.\n");
}


void buscarMaterial(Secao *head) {
  char nome[50];
  printf("Digite o nome do material a ser buscado: ");
  scanf(" %[^\n]", nome);

  Secao *atualSecao = head;
  while (atualSecao != NULL) {
    Material *atualMaterial = atualSecao->materiais;
    while (atualMaterial != NULL) {
      if (strcmp(atualMaterial->nome, nome) == 0) {
        printf("Material encontrado na seção %s:\n", atualSecao->nome);
        printf("Nome: %s\n", atualMaterial->nome);
        printf("Tipo: %s\n", atualMaterial->tipo);
        printf("Preço: %.2f\n", atualMaterial->preco);
        printf("Quantidade em estoque: %d\n", atualMaterial->quantidade);
        return; // Encerra a busca após encontrar o material
      }
      atualMaterial = atualMaterial->prox;
    }
    atualSecao = atualSecao->prox;
  }

  printf("Erro: Material não encontrado.\n");
}
