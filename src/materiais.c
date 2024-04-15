#include "../include/materiais.h"
#include "../include/secao.h"
#include "../include/sistema.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarMaterial(Secao **secoes) {
  if (*secoes == NULL) {
    printf("Erro: Nao ha secoes para adicionar materiais.\n");
    return;
  }

  char nomeSecao[50];
  printf("Digite o nome da secao para adicionar o material: ");
  scanf(" %[^\n]", nomeSecao);
  *nomeSecao = *formatarString(nomeSecao);

  Secao *secaoAtual = *secoes;
  while (secaoAtual != NULL && strcmp(secaoAtual->nome, nomeSecao) != 0) {
    secaoAtual = secaoAtual->prox;
  }

  if (secaoAtual == NULL) {
    printf("Erro: Secao nao encontrada.\n");
    return;
  }

  Material *novoMaterial = (Material *)malloc(sizeof(Material));
  if (novoMaterial == NULL) {
    printf("Erro: Nao foi possivel alocar memoria para o novo material.\n");
    return;
  }

  do {
    printf("Digite o nome do material: ");
    scanf(" %[^\n]", novoMaterial->nome);
    *novoMaterial->nome = *formatarString(novoMaterial->nome);
    int i = 0;
    while (novoMaterial->nome[i] != '\0') {
      if (!isalpha(novoMaterial->nome[i]) && novoMaterial->nome[i] != ' ') {
        printf("Erro: O nome da secao nao pode conter numeros, acentos ou "
               "caracteres especiais.\n");
        free(novoMaterial);
        return;
      }
      i++;
    }
  } while (novoMaterial->nome[0] == '\0');

  do {
    printf("Digite o tipo do material: ");
    scanf(" %[^\n]", novoMaterial->tipo);
    *novoMaterial->tipo = *formatarString(novoMaterial->tipo);
    int i = 0;
    while (novoMaterial->tipo[i] != '\0') {
      if (!isalpha(novoMaterial->tipo[i]) && novoMaterial->tipo[i] != ' ') {
        printf("Erro: O nome da secao nao pode conter numeros, acentos ou "
               "caracteres especiais.\n");
        free(novoMaterial); 
        return;
      }
      i++;
    }
  } while (novoMaterial->tipo[0] == '\0');

  do {
    printf("Digite o preco do material: ");
    if (scanf("%f", &novoMaterial->preco) != 1 || novoMaterial->preco <= 0) {
      printf("Erro: Preco do material invalido.\n");
      while (getchar() != '\n')
        ; // Limpar o buffer de entrada
    }
  } while (novoMaterial->preco <= 0);
  
  printf("Insira a quantidade a ser adicionada: ");
  int quantidade = lerNumeroInteiro();
  novoMaterial->quantidade = quantidade;

  // Encontrar o ponto de insercao correto na lista de materiais da secao
  Material *atual = secaoAtual->materiais;
  Material *anterior = NULL;

  while (atual != NULL && strcmp(novoMaterial->nome, atual->nome) > 0) {
    anterior = atual;
    atual = atual->prox;
  }

  // Inserir o novo material na posicao correta
  novoMaterial->prox = atual;
  if (anterior == NULL) {
    secaoAtual->materiais = novoMaterial;
  } else {
    anterior->prox = novoMaterial;
  }

  printf("Material adicionado com sucesso a secao %s.\n", nomeSecao);
}

// Funcao para remover um material de uma secao
void removerMaterial(Secao *head) {
  // Verifica se a lista de secoes esta vazia
  if (head == NULL) {
    printf("Nao ha secoes disponiveis.\n");
    return;
  }

  char nomeMaterial[50];
  printf("Digite o nome do material que deseja remover: ");
  scanf("%s", nomeMaterial);
  *nomeMaterial = *formatarString(nomeMaterial);

  // Percorre a lista de secoes
  Secao *atualSecao = head;
  while (atualSecao != NULL) {
    // Verifica se ha materiais na secao atual
    if (atualSecao->materiais != NULL) {
      Material *anterior = NULL;
      Material *atualMaterial = atualSecao->materiais;
      // Percorre a lista de materiais na secao atual
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
        // Avanca para o proximo material
        anterior = atualMaterial;
        atualMaterial = atualMaterial->prox;
      }
    }
    // Avanca para a proxima secao
    atualSecao = atualSecao->prox;
  }

  // Se o material nao foi encontrado em nenhuma secao
  printf("Material nao encontrado.\n");
}

void realizarVenda(Secao *head) {
  if (head == NULL) {
    printf("Erro: Nao ha secoes para vender materiais.\n");
    return;
  }

  char nomeMaterial[50];
  printf("Digite o nome do material a ser vendido: ");
  scanf(" %[^\n]", nomeMaterial);
  *nomeMaterial = *formatarString(nomeMaterial);
  Secao *atualSecao = head;
  while (atualSecao != NULL) {
    Material *atualMaterial = atualSecao->materiais;
    while (atualMaterial != NULL &&
           strcmp(atualMaterial->nome, nomeMaterial) != 0) {
      atualMaterial = atualMaterial->prox;
    }
    if (atualMaterial != NULL) {
      int quantidade;
      printf("Digite a quantidade a ser vendida: ");
      quantidade = lerNumeroInteiro();
      atualMaterial->quantidade -= quantidade;
      printf("Venda realizada com sucesso.\n");
      return; // Encerra a funcao apos a venda
    }
    atualSecao = atualSecao->prox;
  }

  printf("Erro: Material nao encontrado.\n");
}

void buscarMaterial(Secao *head) {
  char nome[50];
  printf("Digite o nome do material a ser buscado: ");
  scanf(" %[^\n]", nome);
  Secao *atualSecao = head;
  while (atualSecao != NULL) {
    Material *atualMaterial = atualSecao->materiais;
    while (atualMaterial != NULL) {
      if (strcmp(atualMaterial->nome, formatarString(nome)) == 0) {
        printf("Material encontrado na secao %s:\n", atualSecao->nome);
        printf("Nome: %s\n", atualMaterial->nome);
        printf("Tipo: %s\n", atualMaterial->tipo);
        printf("Preco: %.2f\n", atualMaterial->preco);
        printf("Quantidade em estoque: %d\n", atualMaterial->quantidade);
        return; // Encerra a busca apos encontrar o material
      }
      atualMaterial = atualMaterial->prox;
    }
    atualSecao = atualSecao->prox;
  }

  printf("Erro: Material nao encontrado.\n");
}
