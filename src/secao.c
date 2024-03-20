#include "../include/secao.h"
#include "../include/listaencadeada.h"

ListaSecoes *criarSecao(char nome[50], char local[50], ListaSecoes *lista) {
  Secao *nova_secao = (Secao *)malloc(sizeof(Secao));
  if (nova_secao == NULL) {
    printf("Erro na alocação de memória\n");
    exit(1);
  }

  strncpy(nova_secao->nome, nome, 50);
  strncpy(nova_secao->local, local, 50);
  lista = adicionarSecao(lista, nova_secao);

  printf("Seção %s criada com sucesso!\n", nome);

  return lista;
}
