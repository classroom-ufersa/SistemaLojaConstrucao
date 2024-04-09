#include "../include/secao.h"
#include "../include/materiais.h"
#include "../include/sistema.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarSecao(Secao **head) {
  // Verificar se o ponteiro para a lista encadeada e nulo
  if (head == NULL) {
    printf("Erro: Ponteiro para a lista de secoes e nulo.\n");
    return;
  }

  Secao *novaSecao = (Secao *)malloc(sizeof(Secao));
  if (novaSecao == NULL) {
    printf("Erro: Nao foi possivel alocar memoria para a nova secao.\n");
    return;
  }

  printf("Digite o nome da secao: ");
  if (scanf(" %[^\n]", novaSecao->nome) != 1 || novaSecao->nome[0] == '\0') {
    printf("Erro: Nome da secao invalido.\n");
    free(novaSecao); // Liberar memoria alocada
    return;
  }
  *novaSecao->nome = *formatarString(novaSecao->nome);

  int i = 0;
  while (novaSecao->nome[i] != '\0') {
    if (!isalpha(novaSecao->nome[i]) && novaSecao->nome[i] != ' ') {
      printf("Erro: O nome da secao nao pode conter numeros, acentos ou "
             "caracteres especiais.\n");
      free(novaSecao); // Liberar memoria alocada
      return;
    }
    i++;
  }

  printf("Digite a localizacao da secao: ");
  if (scanf(" %[^\n]", novaSecao->localizacao) != 1 ||
      novaSecao->localizacao[0] == '\0') {
    printf("Erro: Localizacao da secao invalida.\n");
    free(novaSecao); // Liberar memoria alocada
    return;
  }

  // Verificar se a secao ja existe na lista
  Secao *atual = *head;
  while (atual != NULL) {
    if (strcmp(novaSecao->nome, atual->nome) == 0) {
      printf("Erro: Ja existe uma secao com este nome.\n");
      free(novaSecao); // Liberar memoria alocada
      return;
    }
    atual = atual->prox;
  }

  // Encontrar o ponto de insercao correto
  atual = *head;
  Secao *anterior = NULL;
  while (atual != NULL && strcmp(novaSecao->nome, atual->nome) > 0) {
    anterior = atual;
    atual = atual->prox;
  }

  // Inserir a nova secao na posicao correta
  novaSecao->prox = atual;
  if (anterior == NULL) {
    *head = novaSecao;
  } else {
    anterior->prox = novaSecao;
  }

  printf("Secao adicionada com sucesso.\n");
}

void removerSecao(Secao **head) {
  if (*head == NULL) {
    printf("Erro: Nao ha secoes para remover.\n");
    return;
  }

  char nome[50];
  printf("Digite o nome da secao a ser removida: ");
  scanf(" %[^\n]", nome);
  *nome = *formatarString(nome);
  Secao *atual = *head;
  Secao *anterior = NULL;

  while (atual != NULL && strcmp(atual->nome, nome) != 0) {
    anterior = atual;
    atual = atual->prox;
  }

  if (atual == NULL) {
    printf("Erro: Secao nao encontrada.\n");
    return;
  }

  if (anterior == NULL) {
    *head = atual->prox;
  } else {
    anterior->prox = atual->prox;
  }

  free(atual);
  printf("Secao removida com sucesso.\n");
}

void listarSecoes(Secao *head) {
  if (head == NULL) {
    printf("Erro: Nao ha secoes cadastradas.\n");
    return;
  }

  printf("Lista de secoes:\n");
  Secao *atualSecao = head;
  while (atualSecao != NULL) {
    printf("Nome da secao: %s, Localizacao: %s\n", atualSecao->nome,
           atualSecao->localizacao);
    printf("Materiais:\n");
    Material *atualMaterial = atualSecao->materiais;
    while (atualMaterial != NULL) {
      printf("  Nome: %s, Tipo: %s, Preco: %.2f, Quantidade: %d\n",
             atualMaterial->nome, atualMaterial->tipo, atualMaterial->preco,
             atualMaterial->quantidade);
      atualMaterial = atualMaterial->prox;
    }
    atualSecao = atualSecao->prox;
  }
}

void salvarDados(Secao *head) {
  FILE *arquivo = fopen("dados.txt", "w");
  if (arquivo == NULL) {
    printf("Erro: Nao foi possivel abrir o arquivo para escrita.\n");
    return;
  }

  Secao *atualSecao = head;
  while (atualSecao != NULL) {
    fprintf(arquivo, "Secao: %s\n", atualSecao->nome);
    fprintf(arquivo, "Localizacao: %s\n", atualSecao->localizacao);

    Material *atualMaterial = atualSecao->materiais;
    while (atualMaterial != NULL) {
      fprintf(arquivo, "  Material: %s\n", atualMaterial->nome);
      fprintf(arquivo, "    Tipo: %s\n", atualMaterial->tipo);
      fprintf(arquivo, "    Preco: %.2f\n", atualMaterial->preco);
      fprintf(arquivo, "    Quantidade: %d\n", atualMaterial->quantidade);
      atualMaterial = atualMaterial->prox;
    }
    fprintf(arquivo, "\n");
    atualSecao = atualSecao->prox;
  }

  fclose(arquivo);
  printf("Dados salvos com sucesso.\n");
}

void adicionarMaterialArgs(Material **head, char nome[], char tipo[],
                           float preco, int quantidade) {
  Material *novoMaterial = (Material *)malloc(sizeof(Material));
  if (novoMaterial == NULL) {
    printf("Erro: Nao foi possivel alocar memoria para o novo material.\n");
    return;
  }

  strcpy(novoMaterial->nome, nome);
  strcpy(novoMaterial->tipo, tipo);
  novoMaterial->preco = preco;
  novoMaterial->quantidade = quantidade;

  novoMaterial->prox = *head;
  *head = novoMaterial;

  printf("Material adicionado com sucesso.\n");
}

void carregarDados(Secao **head) {
  FILE *arquivo = fopen("dados.txt", "r");
  if (arquivo == NULL) {
    printf("Erro: Nao foi possivel abrir o arquivo para leitura.\n");
    return;
  }

  char buffer[100];
  char nomeSecao[50];
  char localizacaoSecao[50];
  char nomeMaterial[50];
  char tipoMaterial[50];
  float precoMaterial;
  int quantidadeMaterial;

  Secao *ultimaSecao = NULL;

  while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
    if (sscanf(buffer, "Secao: %[^\n]", nomeSecao) == 1) {
      // Adicionar uma nova secao a lista encadeada
      Secao *novaSecao = (Secao *)malloc(sizeof(Secao));
      if (novaSecao == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para a nova secao.\n");
        return;
      }
      strcpy(novaSecao->nome, nomeSecao);

      fgets(buffer, sizeof(buffer),
            arquivo); // Ler a linha seguinte contendo a localizacao
      sscanf(buffer, "Localizacao: %[^\n]", localizacaoSecao);
      strcpy(novaSecao->localizacao, localizacaoSecao);

      novaSecao->materiais = NULL;
      novaSecao->prox = NULL;

      if (*head == NULL) {
        *head = novaSecao;
      } else {
        ultimaSecao->prox = novaSecao;
      }
      ultimaSecao = novaSecao;
    } else if (sscanf(buffer, "  Material: %[^\n]", nomeMaterial) == 1) {
      // Adicionar um novo material a ultima secao criada
      Material *novoMaterial = (Material *)malloc(sizeof(Material));
      if (novoMaterial == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para o novo material.\n");
        return;
      }
      strcpy(novoMaterial->nome, nomeMaterial);

      fgets(buffer, sizeof(buffer),
            arquivo); // Ler a linha seguinte contendo o tipo do material
      sscanf(buffer, "    Tipo: %[^\n]", tipoMaterial);
      strcpy(novoMaterial->tipo, tipoMaterial);

      fgets(buffer, sizeof(buffer), arquivo);
      sscanf(buffer, "    Preco: %f", &precoMaterial);
      novoMaterial->preco = precoMaterial;

      fgets(buffer, sizeof(buffer), arquivo);
      sscanf(buffer, "    Quantidade: %d", &quantidadeMaterial);
      novoMaterial->quantidade = quantidadeMaterial;
      
      novoMaterial->prox = ultimaSecao->materiais;
      ultimaSecao->materiais = novoMaterial;
    }
  }

  fclose(arquivo);
  printf("Dados carregados com sucesso.\n");
}

void liberarMemoria(Secao **head) {
  if (*head == NULL) {
    printf("Erro: Nao ha secoes para liberar memoria.\n");
    return;
  }

  Secao *atualSecao = *head;
  while (atualSecao != NULL) {
    Material *atualMaterial = atualSecao->materiais;
    while (atualMaterial != NULL) {
      Material *temp = atualMaterial;
      atualMaterial = atualMaterial->prox;
      free(temp); // Liberar memoria do material
    }

    Secao *tempSecao = atualSecao;
    atualSecao = atualSecao->prox;
    free(tempSecao); // Liberar memoria da secao
  }

  *head = NULL; // Definir o ponteiro da lista como nulo
}