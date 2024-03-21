#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

// Definição da estrutura Secao
typedef struct secao Secao;

// Definição da estrutura ListaSecoes
typedef struct listasecoes {
  Secao *secao;               // Ponteiro para a seção atual
  struct listasecoes *prox;   // Ponteiro para o próximo nó na lista
  struct listasecoes *ant;    // Ponteiro para o nó anterior na lista
} ListaSecoes;

/**
 * @brief Cria uma nova lista encadeada de seções.
 * 
 * @return ListaSecoes* Ponteiro para a lista de seções recém-criada.
 */
ListaSecoes *criarListaSecoes(void);

/**
 * @brief Adiciona uma seção à lista encadeada de seções.
 * 
 * @param lista Ponteiro para a lista de seções.
 * @param secao Ponteiro para a seção a ser adicionada.
 * @return ListaSecoes* Ponteiro para a lista de seções com a seção adicionada.
 */
ListaSecoes *adicionarSecao(ListaSecoes *lista, Secao *secao);

/**
 * @brief Busca uma seção na lista de seções fornecida.
 * 
 * @param lista Ponteiro para a lista de seções.
 * @param secao Ponteiro para a seção a ser pesquisada.
 * @return ListaSecoes* Ponteiro para a seção encontrada, ou NULL se não encontrada.
 */
ListaSecoes *buscarSecao(ListaSecoes *lista, Secao *secao);

/**
 * @brief Remove uma seção da lista de seções.
 * 
 * @param lista Ponteiro para a lista de seções.
 * @param secao Ponteiro para a seção a ser removida.
 * @return ListaSecoes* Ponteiro para a lista de seções com a seção removida.
 */
ListaSecoes *removerSecao(ListaSecoes *lista, Secao *secao);

/**
 * @brief Verifica se a lista de seções está vazia.
 * 
 * @param lista Ponteiro para a lista de seções.
 * @return int 1 se a lista está vazia, 0 se não está vazia.
 */
int verificarListaVazia(ListaSecoes *lista);

/**
 * @brief Imprime a lista de seções.
 * 
 * @param lista Ponteiro para a lista de seções a ser impressa.
 */
void imprimirListaSecoes(ListaSecoes *lista);

void ordenarListaSecoes(ListaSecoes *listaSecoes);

#endif

