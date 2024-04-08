#ifndef SECAO_H
#define SECAO_H

typedef struct material Material;

// Estrutura para representar uma sessão
typedef struct secao {
    char nome[50];
    char localizacao[50];
    Material *materiais;
    struct secao *prox;
} Secao;

/**
 * @brief Função para adicionar uma nova seção para a lista de seções 
 * 
 * @param head Cabeçalho da lista de seções. 
 */
void adicionarSecao(Secao **head);
/**
 * @brief Função para remover uma seção da lista de seções. 
 * 
 * @param head 
 */
void removerSecao(Secao **head);
/**
 * @brief Função para listar as seções da lista de seções. 
 * 
 * @param head Cabeçalho da lista de seções. 
 */

void listarSecoes(Secao *head);

/**
 * @brief Função para salvar as seções no arquivo de texto. 
 * 
 * @param head Cabeçalho da lista de seções.
 */
void salvarDados(Secao *head);

/**
 * @brief Função para remover uma seção da lista de seções. 
 * 
 * @param head Cabeçalho da lista de seções.
 */
void carregarDados(Secao **head);

/**
 * @brief Função para adicionar um material através dos parâmetros passados pela função. 
 * 
 * @param head Cabeçalho da lista de seções.
 * @param nome Nome do material a ser adicionado.
 * @param tipo Tipo do material a ser adicionado.
 * @param preco Preço do material a ser adicionado.
 * @param quantidade Quantidade do material a ser adicionado.
 */
void adicionarMaterialArgs(Material **head, char nome[], char tipo[], float preco, int quantidade);
#endif /* SESSAO_H */

