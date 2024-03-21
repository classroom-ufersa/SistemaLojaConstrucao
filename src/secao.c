#include "../include/secao.h"
#include "../include/listaencadeada.h"

ListaSecoes *criarSecao(char nome[50], char local[50], ListaSecoes *lista) {
    Secao *novaSecao = (Secao *)malloc(sizeof(Secao));
    if (novaSecao == NULL) {
        printf("Erro: Não foi possível alocar memória para a nova seção.\n");
        return lista;
    }
    strcpy(novaSecao->nome, nome);
    strcpy(novaSecao->local, local);
    novaSecao->materiais = NULL;

    ListaSecoes *novoNo = (ListaSecoes *)malloc(sizeof(ListaSecoes));
    if (novoNo == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo nó de seção.\n");
        free(novaSecao);
        return lista;
    }
    novoNo->secao = novaSecao;
    novoNo->prox = NULL;

    if (lista == NULL) {
        return novoNo;
    }

    ListaSecoes *atual = lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novoNo;

    ordenarListaSecoes(lista); // Ordenar as seções após adicionar a nova seção

    return lista;
}
