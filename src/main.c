#include "../include/listaencadeada.h"
#include "../include/materiais.h"
#include <stdio.h>
#include <stdlib.h>

// Função para imprimir uma seção e seus materiais
void imprimirSecao(FILE *arquivo, Secao *secao) {
  fprintf(arquivo, "Seção: %s\n", secao->nome);
  fprintf(arquivo, "\tLocalização: %s\n", secao->local);
  if (secao->materiais != NULL) {
    fprintf(arquivo, "\tLista de Materiais:\n");
    NoMaterial *temp = secao->materiais;
    while (temp != NULL) {
      fprintf(arquivo, "\t\tMaterial: %s\n", temp->material->nome);
      fprintf(arquivo, "\t\t\tCategoria: %s\n", temp->material->tipo);
      fprintf(arquivo, "\t\t\tPreço: %.2f\n", temp->material->preco);
      fprintf(arquivo, "\t\t\tQuantidade: %d\n", temp->material->qtdEstoque);
      temp = temp->prox;
    }
  } else {
    fprintf(arquivo, "\tA lista de materiais está vazia na seção %s.\n",
            secao->nome);
  }
  fprintf(arquivo, "\n");
}

void imprimirArquivo(ListaSecoes *listaSecoes) {
  FILE *arquivo = fopen("secoes_materiais.txt", "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return;
  }

  ListaSecoes *ptr = listaSecoes;
  while (ptr != NULL) {
    imprimirSecao(arquivo, ptr->secao);
    ptr = ptr->prox;
  }

  fclose(arquivo);
}

ListaSecoes *lerArquivoSecoesMateriais() {
    FILE *arquivo = fopen("secoes_materiais.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    ListaSecoes *listaSecoes = NULL;
    Secao *secaoAtual = NULL;
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strncmp(linha, "Seção: ", 7) == 0) {
            char nomeSecao[50], localizacao[50];
            sscanf(linha, "Seção: %[^\n], Localização: %[^\n]", nomeSecao, localizacao);
            Secao *novaSecao = criarSecao(nomeSecao, localizacao, listaSecoes);
            if (novaSecao == NULL) {
                printf("Erro ao criar nova seção.\n");
                fclose(arquivo);
                return NULL;
            }
            ListaSecoes *novoNoSecao = (ListaSecoes *)malloc(sizeof(ListaSecoes));
            if (novoNoSecao == NULL) {
                printf("Erro ao alocar memória para o novo nó de seção.\n");
                fclose(arquivo);
                return NULL;
            }
            novoNoSecao->secao = novaSecao;
            novoNoSecao->prox = NULL;
            if (listaSecoes == NULL) {
                listaSecoes = novoNoSecao;
            } else {
                ListaSecoes *temp = listaSecoes;
                while (temp->prox != NULL) {
                    temp = temp->prox;
                }
                temp->prox = novoNoSecao;
            }
            secaoAtual = novaSecao;
        } else if (strncmp(linha, "  Material: ", 12) == 0 && secaoAtual != NULL) {
            char nomeMaterial[50], tipoMaterial[50];
            float precoMaterial;
            int quantidadeMaterial;
            sscanf(linha, "  Material: %[^\n], Categoria: %[^\n], Preço: %f, Quantidade: %d",
                   nomeMaterial, tipoMaterial, &precoMaterial, &quantidadeMaterial);
            adicionar_material(secaoAtual, nomeMaterial, tipoMaterial, precoMaterial, quantidadeMaterial);
        }
    }

    fclose(arquivo);
    return listaSecoes;
}

void exibirMenu() {
  printf("\n=== Menu ===\n");
  printf("1. Criar uma nova seção\n");
  printf("2. Adicionar material a uma seção\n");
  printf("3. Remover material de uma seção\n");
  printf("4. Buscar material em todas as seções\n");
  printf("5. Imprimir lista de seções e materiais\n");
  printf("6. Sair\n");
}

void limparBufferEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Função principal
int main() {
  ListaSecoes *listaSecoes = criarListaSecoes();
//  listaSecoes = lerArquivoSecoesMateriais(listaSecoes);
  int escolha;
  do {
    exibirMenu();
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    limparBufferEntrada(); // Limpar o buffer de entrada após a leitura

    switch (escolha) {
    case 1: {
      char nome[50], local[50];
      printf("Digite o nome da nova seção: ");
      fgets(nome, 50, stdin);
      printf("Digite a localização da nova seção: ");
      fgets(local, 50, stdin);
      listaSecoes = criarSecao(nome, local, listaSecoes);
      break;
    }
    case 2: {
      char nome[50], tipo[50];
      float preco;
      int qtdEstoque;
      printf("Digite o nome do material: ");
      fgets(nome, 50, stdin);
      printf("Digite o tipo do material: ");
      fgets(tipo, 50, stdin);
      printf("Digite o preço do material: ");
      scanf("%f", &preco);
      printf("Digite a quantidade em estoque do material: ");
      scanf("%d", &qtdEstoque);
      limparBufferEntrada();
      printf("Em qual seção deseja adicionar o material? Digite o nome da "
             "seção: ");
      char nomeSecao[50];
      fgets(nomeSecao, 50, stdin);
      ListaSecoes *secao = listaSecoes;
      while (secao != NULL) {
        if (strcmp(secao->secao->nome, nomeSecao) == 0) {
          adicionar_material(secao->secao, nome, tipo, preco, qtdEstoque);
          break;
        }
        secao = secao->prox;
      }
      break;
    }
    case 3: {
      char nome[50], tipo[50];
      printf("Digite o nome do material a ser removido: ");
      fgets(nome, 50, stdin);
      printf("Digite o tipo do material a ser removido: ");
      fgets(tipo, 50, stdin);
      Material material;
      strcpy(material.nome, nome);
      strcpy(material.tipo, tipo);
      buscar_material(&material, listaSecoes);
      break;
    }
    case 4: {
      char nome[50], tipo[50];
      printf("Digite o nome do material a ser buscado: ");
      fgets(nome, 50, stdin);
      printf("Digite o tipo do material a ser buscado: ");
      fgets(tipo, 50, stdin);
      Material material;
      strcpy(material.nome, nome);
      strcpy(material.tipo, tipo);
      buscar_material(&material, listaSecoes);
      break;
    }
    case 5: {
      printf("\nLista de Seções e Materiais:\n");
      imprimirListaSecoes(listaSecoes);
      break;
    }
    case 6: {
      printf("Volte sempre!!!\n");
      break;
    }
    default:
      printf("Opção inválida. Por favor, escolha uma opção válida.\n");
    }
  } while (escolha != 6);

  // Salvando as seções e materiais em um arquivo
  ordenarListaSecoes(listaSecoes);
  imprimirArquivo(listaSecoes);

  return 0;
}
