#include "../include/secao.h"
#include "../include/materiais.h"

void adicionar_material(Secao *secao, char nome[50], char tipo[50], float preco, int qtdEstoque) {
    // Alocar memória para o novo material
    Material *novo_material = (Material *)malloc(sizeof(Material));
    if (novo_material == NULL) {
        printf("Erro ao alocar memória para o novo material.\n");
        return;
    }
    // Preencher os detalhes do novo material
    strcpy(novo_material->nome, nome);
    strcpy(novo_material->tipo, tipo);
    novo_material->preco = preco;
    novo_material->qtdEstoque = qtdEstoque;

    // Alocar memória para o novo nó de material
    NoMaterial *novo_no = (NoMaterial *)malloc(sizeof(NoMaterial));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória para o novo nó de material.\n");
        free(novo_material); // Liberar memória alocada para o novo material
        return;
    }

    // Preencher o novo nó com o material e ajustar o próximo para NULL
    novo_no->material = novo_material;
    novo_no->prox = NULL;

    // Verificar se a lista de materiais da seção está vazia
    if (secao->materiais == NULL) {
        secao->materiais = novo_no; // Se estiver vazia, o novo nó se torna o primeiro da lista
    } else {
        // Se não estiver vazia, percorrer a lista até o último nó
        NoMaterial *atual = secao->materiais;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        // Adicionar o novo nó após o último nó da lista
        atual->prox = novo_no;
    }
}



void remover_material(Material *material, Secao *secao)
{
    NoMaterial *atual = secao->materiais;
    NoMaterial *anterior = NULL;

    if (atual == NULL)
    {
        printf("A lista de materiais está vazia na seção %s.\n", secao->nome);
        return;
    }

    // Verifica se o material a ser removido está no início da lista
    if (strcmp(atual->material->nome, material->nome) == 0 && strcmp(atual->material->tipo, material->tipo) == 0)
    {
        secao->materiais = atual->prox;
        printf("Material removido com sucesso da seção %s!\n", secao->nome);
        free(atual);
        return;
    }

    // Percorre a lista procurando o material a ser removido
    while (atual != NULL)
    {
        if (strcmp(atual->material->nome, material->nome) == 0 && strcmp(atual->material->tipo, material->tipo) == 0)
        {
            if (anterior != NULL) {
                anterior->prox = atual->prox;
            }
            printf("Material removido com sucesso da seção %s!\n", secao->nome);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Material não encontrado na seção %s.\n", secao->nome);
}

void buscar_material(Material *material, ListaSecoes *listaSecoes)
{
    ListaSecoes *p = listaSecoes;

    while (p != NULL)
    {
        NoMaterial *atualMaterial = p->secao->materiais;

        while (atualMaterial != NULL)
        {
            if (strcmp(atualMaterial->material->nome, material->nome) == 0 &&
                strcmp(atualMaterial->material->tipo, material->tipo) == 0)
            {
                printf("Material encontrado na seção %s!\n", p->secao->nome);
                printf("Detalhes:\n");
                printf("Nome: %s\n", atualMaterial->material->nome);
                printf("Tipo: %s\n", atualMaterial->material->tipo);
                printf("Preço: %.2f\n", atualMaterial->material->preco);
                printf("Quantidade em estoque: %d\n", atualMaterial->material->qtdEstoque);
                return;
            }
            atualMaterial = atualMaterial->prox;
        }
        p = p->prox;
    }

    printf("Material não encontrado em nenhuma seção.\n");
}
