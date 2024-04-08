#include "../include/secao.h"
#include "../include/materiais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void adicionarSecao(Secao **head) {
  // Verificar se o ponteiro para a lista encadeada é nulo
  if (head == NULL) {
    printf("Erro: Ponteiro para a lista de seções é nulo.\n");
    return;
  }

  Secao *novaSecao = (Secao *)malloc(sizeof(Secao));
  if (novaSecao == NULL) {
    printf("Erro: Não foi possível alocar memória para a nova seção.\n");
    return;
  }

  printf("Digite o nome da seção: ");
  if (scanf(" %[^\n]", novaSecao->nome) != 1 || novaSecao->nome[0] == '\0') {
    printf("Erro: Nome da seção inválido.\n");
    free(novaSecao); // Liberar memória alocada
    return;
  }

  // Verificar se o nome da seção contém apenas letras
  for (int i = 0; novaSecao->nome[i] != '\0'; i++) {
    if (!isalpha(novaSecao->nome[i])) {
      printf("Erro: O nome da seção não pode conter números.\n");
      free(novaSecao); // Liberar memória alocada
      return;
    }
  }

  printf("Digite a localização da seção: ");
  if (scanf(" %[^\n]", novaSecao->localizacao) != 1 || novaSecao->localizacao[0] == '\0') {
    printf("Erro: Localização da seção inválida.\n");
    free(novaSecao); // Liberar memória alocada
    return;
  }

  // Verificar se a seção já existe na lista
  Secao *atual = *head;
  while (atual != NULL) {
    if (strcmp(novaSecao->nome, atual->nome) == 0) {
      printf("Erro: Já existe uma seção com este nome.\n");
      free(novaSecao); // Liberar memória alocada
      return;
    }
    atual = atual->prox;
  }

  // Encontrar o ponto de inserção correto
  atual = *head;
  Secao *anterior = NULL;
  while (atual != NULL && strcmp(novaSecao->nome, atual->nome) > 0) {
    anterior = atual;
    atual = atual->prox;
  }

  // Inserir a nova seção na posição correta
  novaSecao->prox = atual;
  if (anterior == NULL) {
    *head = novaSecao;
  } else {
    anterior->prox = novaSecao;
  }

  printf("Seção adicionada com sucesso.\n");
}

void removerSecao(Secao **head) {
  if (*head == NULL) {
    printf("Erro: Não há seções para remover.\n");
    return;
  }

  char nome[50];
  printf("Digite o nome da seção a ser removida: ");
  scanf(" %[^\n]", nome);

  Secao *atual = *head;
  Secao *anterior = NULL;

  while (atual != NULL && strcmp(atual->nome, nome) != 0) {
    anterior = atual;
    atual = atual->prox;
  }

  if (atual == NULL) {
    printf("Erro: Seção não encontrada.\n");
    return;
  }

  if (anterior == NULL) {
    *head = atual->prox;
  } else {
    anterior->prox = atual->prox;
  }

  free(atual);
  printf("Seção removida com sucesso.\n");
}

void listarSecoes(Secao *head) {
  if (head == NULL) {
    printf("Erro: Não há seções cadastradas.\n");
    return;
  }

  printf("Lista de seções:\n");
  Secao *atualSecao = head;
  while (atualSecao != NULL) {
    printf("Nome da seção: %s, Localização: %s\n", atualSecao->nome,
           atualSecao->localizacao);
    printf("Materiais:\n");
    Material *atualMaterial = atualSecao->materiais;
    while (atualMaterial != NULL) {
      printf("  Nome: %s, Tipo: %s, Preço: %.2f, Quantidade: %d\n",
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
    printf("Erro: Não foi possível abrir o arquivo para escrita.\n");
    return;
  }

  Secao *atualSecao = head;
  while (atualSecao != NULL) {
    fprintf(arquivo, "Seção: %s\n", atualSecao->nome);
    fprintf(arquivo, "Localização: %s\n", atualSecao->localizacao);

    Material *atualMaterial = atualSecao->materiais;
    while (atualMaterial != NULL) {
      fprintf(arquivo, "  Material: %s\n", atualMaterial->nome);
      fprintf(arquivo, "    Tipo: %s\n", atualMaterial->tipo);
      fprintf(arquivo, "    Preço: %.2f\n", atualMaterial->preco);
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
    printf("Erro: Não foi possível alocar memória para o novo material.\n");
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

void carregarSecoesMateriais(Secao **head) {
  FILE *arquivo = fopen("dados.txt", "r");
  if (arquivo == NULL) {
    printf("Erro: Não foi possível abrir o arquivo para leitura.\n");
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
    if (sscanf(buffer, "Seção: %[^\n]", nomeSecao) == 1) {
      // Adicionar uma nova seção à lista encadeada
      Secao *novaSecao = (Secao *)malloc(sizeof(Secao));
      if (novaSecao == NULL) {
        printf("Erro: Não foi possível alocar memória para a nova seção.\n");
        return;
      }
      strcpy(novaSecao->nome, nomeSecao);

      fgets(buffer, sizeof(buffer),
            arquivo); // Ler a linha seguinte contendo a localização
      sscanf(buffer, "Localização: %[^\n]", localizacaoSecao);
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
      // Adicionar um novo material à última seção criada
      Material *novoMaterial = (Material *)malloc(sizeof(Material));
      if (novoMaterial == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo material.\n");
        return;
      }
      strcpy(novoMaterial->nome, nomeMaterial);

      fgets(buffer, sizeof(buffer),
            arquivo); // Ler a linha seguinte contendo o tipo do material
      sscanf(buffer, "    Tipo: %[^\n]", tipoMaterial);
      strcpy(novoMaterial->tipo, tipoMaterial);

      fgets(buffer, sizeof(buffer),
            arquivo); // Ler a linha seguinte contendo o preço e a quantidade
      sscanf(buffer, "    Preço: %f", &precoMaterial);
      sscanf(buffer, "    Quantidade: %d", &quantidadeMaterial);
      novoMaterial->preco = precoMaterial;
      novoMaterial->quantidade = quantidadeMaterial;

      novoMaterial->prox = ultimaSecao->materiais;
      ultimaSecao->materiais = novoMaterial;
    }
  }

  fclose(arquivo);
  printf("Dados carregados com sucesso.\n");
}
