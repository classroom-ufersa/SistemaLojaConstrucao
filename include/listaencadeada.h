#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct secao Secao;

typedef struct listasecoes {
  Secao *secao;
  struct listasecoes *prox;
  struct listasecoes *ant;
} ListaSecoes;

ListaSecoes *criarListaSecoes(void);

ListaSecoes *adicionarSecao(ListaSecoes *lista, Secao *secao);

ListaSecoes *buscarSecao(ListaSecoes *lista, Secao *secao);

ListaSecoes *removerSecao(ListaSecoes *lista, Secao *secao);

int verificarListaVazia(ListaSecoes *lista);

void imprimirListaSecoes(ListaSecoes *lista);

#endif
