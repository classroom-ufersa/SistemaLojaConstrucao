#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/materiais.h"
#include "../include/secao.h"

void adicionarMaterial(Material **head, Secao **secoes) {
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

    printf("Digite o nome do material: ");
    scanf(" %[^\n]", novoMaterial->nome);
    printf("Digite o tipo do material: ");
    scanf(" %[^\n]", novoMaterial->tipo);
    printf("Digite o preço do material: ");
    scanf("%f", &novoMaterial->preco);
    printf("Digite a quantidade em estoque do material: ");
    scanf("%d", &novoMaterial->quantidade);

    novoMaterial->prox = secaoAtual->materiais;
    secaoAtual->materiais = novoMaterial;

    printf("Material adicionado com sucesso à seção %s.\n", nomeSecao);
}


void removerMaterial(Material **head) {
    if (*head == NULL) {
        printf("Erro: Não há materiais para remover.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do material a ser removido: ");
    scanf(" %[^\n]", nome);

    Material *atual = *head;
    Material *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Erro: Material não encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *head = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Material removido com sucesso.\n");
}

void realizarVenda(Material **head) {
    if (*head == NULL) {
        printf("Erro: Não há materiais para vender.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do material a ser vendido: ");
    scanf(" %[^\n]", nome);

    Material *atual = *head;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Erro: Material não encontrado.\n");
        return;
    }

    int quantidade;
    printf("Digite a quantidade a ser vendida: ");
    scanf("%d", &quantidade);

    if (atual->quantidade < quantidade) {
        printf("Erro: Não há quantidade suficiente em estoque.\n");
        return;
    }

    atual->quantidade -= quantidade;
    printf("Venda realizada com sucesso.\n");
}

void buscarMaterial(Material *head) {
    if (head == NULL) {
        printf("Erro: Não há materiais cadastrados.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do material a ser buscado: ");
    scanf(" %[^\n]", nome);

    Material *atual = head;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Erro: Material não encontrado.\n");
        return;
    }

    printf("Nome: %s\n", atual->nome);
    printf("Tipo: %s\n", atual->tipo);
    printf("Preço: %.2f\n", atual->preco);
    printf("Quantidade em estoque: %d\n", atual->quantidade);
}