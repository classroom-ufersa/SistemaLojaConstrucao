#ifndef SECAO_H
#define SECAO_H

typedef struct material Material;

// Estrutura para representar uma sessão
typedef struct Secao {
    char nome[50];
    char localizacao[50];
    Material *materiais;
    struct Secao *prox;
} Secao;

void adicionarSecao(Secao **head);

void removerSecao(Secao **head);

void listarSecoes(Secao *head);

void salvarSecoes(Secao *head);

void carregarSecoes(Secao **head);

void salvarDados(Secao *head);

void carregarSecoesMateriais(Secao **head);

#endif /* SESSAO_H */

