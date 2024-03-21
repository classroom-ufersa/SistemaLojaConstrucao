#include "../include/listaencadeada.h"
#include "../include/materiais.h"
#include "../include/secao.h"

ListaSecoes *criarListaSecoes(void) { return NULL; };

ListaSecoes *adicionarSecao(ListaSecoes *lista, Secao *secao) {
  if (secao == NULL) {
    printf("Erro: secao é nula\n");
    return lista;
  }

  ListaSecoes *nova_lista = (ListaSecoes *)malloc(sizeof(ListaSecoes));
  if (nova_lista == NULL) {
    printf("Erro na alocação de memória\n");
    exit(1);
  }

  nova_lista->secao = secao;
  nova_lista->prox = NULL;

  if (lista == NULL) {
    nova_lista->prox = nova_lista;
    nova_lista->ant = nova_lista;
    return nova_lista;
  }

  nova_lista->ant = lista->ant;
  lista->ant->prox = nova_lista;
  lista->ant = nova_lista;

  return lista;
}

ListaSecoes *buscarSecao(ListaSecoes *lista, Secao *secao) {
  ListaSecoes *p = lista;
  while (p != NULL && p->prox != lista) {
    if (p->secao == secao) {
      return p;
    }
    p = p->prox;
  }
  return NULL;
}

ListaSecoes *removerSecao(ListaSecoes *lista, Secao *secao) {
  ListaSecoes *p = buscarSecao(lista, secao);

  if (p == NULL) {
    return lista;
  }

  if (lista == p) {
    if (lista->prox == lista) {
      free(lista);
      return NULL;
    } else {
      lista = p->prox;
    }
  }

  p->ant->prox = p->prox;
  p->prox->ant = p->ant;

  if (lista == p) {
    lista = NULL;
  }

  free(p);
  return lista;
}

int verificarListaVazia(ListaSecoes *lista) {
  if (lista == NULL) {
    return 1;
  } else {
    return 0;
  }
}

void imprimirListaSecoes(ListaSecoes *lista) {
  if (verificarListaVazia(lista)) {
    printf("Lista vazia.\n");
    return;
  }
  ListaSecoes *p = lista; // Inicializa um ponteiro para percorrer a lista

  do {
    printf(" Seção: %s \t Local: %s\n", p->secao->nome,
           p->secao->local);
    imprimirListaMateriais(p->secao);
    p = p->prox;
  } while (p != NULL && p != lista);
}
