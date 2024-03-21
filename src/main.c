#include "../include/listaencadeada.h"
#include "../include/materiais.h"
#include <stdio.h>
#include <stdlib.h>

void imprimirArquivo(ListaSecoes *listaSecoes) {
    FILE *arquivo = fopen("secoes_materiais.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    ListaSecoes *ptr = listaSecoes;
    while (ptr != NULL) {
        fprintf(arquivo, "Seção: %s, Localização: %s\n", ptr->secao->nome, ptr->secao->local);
        NoMaterial *materialPtr = ptr->secao->materiais;
        while (materialPtr != NULL) {
            fprintf(arquivo, "  Material: %s, Categoria: %s, Preço: %.2f, Quantidade: %d\n",
                    materialPtr->material->nome, materialPtr->material->tipo,
                    materialPtr->material->preco, materialPtr->material->qtdEstoque);
            materialPtr = materialPtr->prox;
        }
        fprintf(arquivo, "\n");
        ptr = ptr->prox;
    }

    fclose(arquivo);
}


int main() {
  // Criando uma lista de seções
  ListaSecoes *listaSecoes = criarListaSecoes();

  // Criando algumas seções e adicionando à lista
  listaSecoes = criarSecao("Hidráulica", "Local 3", listaSecoes);
  listaSecoes = criarSecao("Ferramentas", "Local 1", listaSecoes);
  listaSecoes = criarSecao("Decoração", "Local 2", listaSecoes);

  // Adicionando materiais às seções
  adicionar_material(listaSecoes->secao, "Martelo", "Ferramenta", 15.99, 20);
  adicionar_material(listaSecoes->secao, "Aartelo", "Ferramenta", 15.99, 20);
  adicionar_material(listaSecoes->prox->secao, "Vaso", "Decoração", 29.99, 10);
  adicionar_material(listaSecoes->prox->prox->secao, "Encanamento",
                     "Hidráulica", 10.50, 15);

  // Salvando as seções e materiais em um arquivo
  ordenarListaSecoes(listaSecoes);
  imprimirArquivo(listaSecoes);

  return 0;
}
