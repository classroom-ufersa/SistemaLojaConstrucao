#include "../include/materiais.h"
#include "../include/secao.h"

// Função para adicionar um novo material a uma seção de forma ordenada
void adicionar_material(Secao *secao, char nome[50], char tipo[50], float preco, int qtdEstoque) {
    // Aloca memória para o novo material
    Material *novoMaterial = (Material *)malloc(sizeof(Material));
    if (novoMaterial == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo material.\n");
        return;
    }

    // Copia os dados do material para a estrutura
    strcpy(novoMaterial->nome, nome);
    strcpy(novoMaterial->tipo, tipo);
    novoMaterial->preco = preco;
    novoMaterial->qtdEstoque = qtdEstoque;

    // Cria um novo nó para o material e o adiciona à lista de materiais da seção
    NoMaterial *novoNo = (NoMaterial *)malloc(sizeof(NoMaterial));
    if (novoNo == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo nó de material.\n");
        free(novoMaterial);
        return;
    }
    novoNo->material = novoMaterial;
    novoNo->prox = NULL;

    // Verifica se a lista de materiais da seção está vazia
    if (secao->materiais == NULL) {
        secao->materiais = novoNo; // Se estiver vazia, o novo nó é o primeiro da lista
        novoNo->ant = NULL;
    } else {
        // Se não estiver vazia, percorre a lista até encontrar o último nó
        NoMaterial *atual = secao->materiais;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        // Adiciona o novo nó como o próximo do último nó da lista
        atual->prox = novoNo;
        novoNo->ant = atual;
    }

    // Ordena a lista de materiais da seção após adicionar o novo material
    ordenarMateriais(secao);
}



void remover_material(Material *material, Secao *secao) {
    if (secao->materiais == NULL) {
        printf("A lista de materiais está vazia na seção %s.\n", secao->nome);
        return;
    }

    NoMaterial *atual = secao->materiais;
    NoMaterial *anterior = NULL;
    
    do {
        if (strcmp(atual->material->nome, material->nome) == 0 &&
            strcmp(atual->material->tipo, material->tipo) == 0) {
            if (atual->prox == atual) { // Único nó na lista
                secao->materiais = NULL;
            } else {
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
                if (secao->materiais == atual) { // Se o nó removido é o primeiro
                    secao->materiais = atual->prox;
                }
            }
            printf("Material removido com sucesso da seção %s!\n", secao->nome);
            free(atual->material); // Liberar memória do material
            free(atual);            // Liberar memória do nó
            return;
        }
        anterior = atual;  
        atual = atual->prox;
    } while (atual != secao->materiais);

    printf("Material não encontrado na seção %s.\n", secao->nome);
}



void buscar_material(Material *material, ListaSecoes *listaSecoes) {
  ListaSecoes *p = listaSecoes;

  while (p != NULL) {
    NoMaterial *atualMaterial = p->secao->materiais;

    while (atualMaterial != NULL) {
      if (strcmp(atualMaterial->material->nome, material->nome) == 0 &&
          strcmp(atualMaterial->material->tipo, material->tipo) == 0) {
        printf("Material encontrado na seção %s!\n", p->secao->nome);
        printf("\t Nome: %s\n", atualMaterial->material->nome);
        printf("\t Tipo: %s\n", atualMaterial->material->tipo);
        printf("\t Preço: %.2f\n", atualMaterial->material->preco);
        printf("\t Quantidade em estoque: %d\n",
               atualMaterial->material->qtdEstoque);
        return;
      }
      atualMaterial = atualMaterial->prox;
    }
    p = p->prox;
  }

  printf("Material não encontrado em nenhuma seção.\n");
}

void imprimirListaMateriais(Secao *secao) {
  if (secao->materiais == NULL) {
    printf("A lista de materiais está vazia na seção %s.\n", secao->nome);
    return;
  }

  NoMaterial *atual = secao->materiais;
  while (atual != NULL) {
    printf("\t Material: %s \t Tipo: %s \t Preço: %.2f \t Quantidade: %d\n",
           atual->material->nome, atual->material->tipo, atual->material->preco,
           atual->material->qtdEstoque);
    atual = atual->prox;
  }
}

void ordenarMateriais(Secao *secao) {
    if (secao == NULL || secao->materiais == NULL || secao->materiais->prox == NULL) {
        return; 
    }

    NoMaterial *current = secao->materiais->prox->prox;
    while (current != NULL) {
        Material *materialAtual = current->material;
        NoMaterial *prev = current->ant;

        while (prev != NULL && strcmp(materialAtual->nome, prev->material->nome) < 0) {
            prev->prox->material = prev->material;
            prev = prev->ant;
        }
        if (prev == NULL) {
            secao->materiais->material = materialAtual;
        } else {
            prev->prox->material = materialAtual;
        }

        current = current->prox;
    }
}

