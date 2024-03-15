#include "../include/secao.h"
#include "../include/listaencadeada.h"


void criarSecao(char nome[50], char local[50], ListaSecoes *lista){
    Secao *nova_secao = (Secao *)malloc(sizeof(Secao));
    strcpy(nova_secao->nome, nome);
    strcpy(nova_secao->local, local);
    adicionarSecao(lista, nova_secao);

    printf("Seção %s criada com sucesso! \n", nome);
};

