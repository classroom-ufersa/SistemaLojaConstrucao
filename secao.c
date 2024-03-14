#include "secao.h"

void criar_secao(char nome[50], char local[50]){
    Secao *nova_secao = (Secao *)malloc(sizeof(Secao));
    strcpy(nova_secao->nome, nome);

    strcpy(nova_secao->local, local);

    printf("Seção %s criada com sucesso! \n", nome);
};
void remover_secao(Secao* secao) {
    // validar se sessao existe

    free(secao);

    printf("Seção %s removida com sucesso!\n", secao->nome);
};

void listar_secoes() {
    /// adicionar logica
};
