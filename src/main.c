#include "../include/listaencadeada.h"
#include "../include/materiais.h"
#include <stdio.h>
#include <stdlib.h>


void imprimirArquivo(ListaSecoes *listaSecoes) {
    FILE *arquivo = fopen("secoes_materiais.txt", "a+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    ListaSecoes *ptr = listaSecoes;
    while (ptr != NULL) {
        fprintf(arquivo, "Seção: %s, Localização: %s\n", ptr->secao->nome, ptr->secao->local);
        NoMaterial *materialPtr = ptr->secao->materiais;
        while (materialPtr != NULL) {
            fprintf(arquivo, "  Material: %s, Categoria: %s, Preço: %.2f, Quantidade: %d\n",
                    materialPtr->material->nome, materialPtr->material->tipo,
                    materialPtr->material->preco, materialPtr->material->qtdEstoque);
            materialPtr = materialPtr->prox;
        }
        fprintf(arquivo, "\n");
        ptr = ptr->prox;
    }

    fclose(arquivo);
}

void exibirMenu() {
    printf("\n=== Menu ===\n");
    printf("1. Criar uma nova seção\n");
    printf("2. Adicionar material a uma seção\n");
    printf("3. Remover material de uma seção\n");
    printf("4. Buscar material em todas as seções\n");
    printf("5. Imprimir lista de seções e materiais\n");
    printf("6. Sair\n");
}

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função principal
int main() {
    ListaSecoes *listaSecoes = criarListaSecoes();

    int escolha;
    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        limparBufferEntrada(); // Limpar o buffer de entrada após a leitura

        switch (escolha) {
            case 1: {
                char nome[50], local[50];
                printf("Digite o nome da nova seção: ");
                fgets(nome, 50, stdin);
                printf("Digite a localização da nova seção: ");
                fgets(local, 50, stdin);
                listaSecoes = criarSecao(nome, local, listaSecoes);
                break;
            }
            case 2: {
                char nome[50], tipo[50];
                float preco;
                int qtdEstoque;
                printf("Digite o nome do material: ");
                fgets(nome, 50, stdin);
                printf("Digite o tipo do material: ");
                fgets(tipo, 50, stdin);
                printf("Digite o preço do material: ");
                scanf("%f", &preco);
                printf("Digite a quantidade em estoque do material: ");
                scanf("%d", &qtdEstoque);
                limparBufferEntrada();
                printf("Em qual seção deseja adicionar o material? Digite o nome da seção: ");
                char nomeSecao[50];
                fgets(nomeSecao, 50, stdin);
                ListaSecoes *secao = listaSecoes;
                while (secao != NULL) {
                    if (strcmp(secao->secao->nome, nomeSecao) == 0) {
                        adicionar_material(secao->secao, nome, tipo, preco, qtdEstoque);
                        break;
                    }
                    secao = secao->prox;
                }
                break;
            }
            case 3: {
                char nome[50], tipo[50];
                printf("Digite o nome do material a ser removido: ");
                fgets(nome, 50, stdin);
                printf("Digite o tipo do material a ser removido: ");
                fgets(tipo, 50, stdin);
                Material material;
                strcpy(material.nome, nome);
                strcpy(material.tipo, tipo);
                buscar_material(&material, listaSecoes);
                break;
            }
            case 4: {
                char nome[50], tipo[50];
                printf("Digite o nome do material a ser buscado: ");
                fgets(nome, 50, stdin);
                printf("Digite o tipo do material a ser buscado: ");
                fgets(tipo, 50, stdin);
                Material material;
                strcpy(material.nome, nome);
                strcpy(material.tipo, tipo);
                buscar_material(&material, listaSecoes);
                break;
            }
            case 5: {
                printf("\nLista de Seções e Materiais:\n");
                imprimirListaSecoes(listaSecoes);
                break;
            }
            case 6: {
                printf("Volte sempre!!!\n");
                break;
            }
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (escolha != 6);

      // Salvando as seções e materiais em um arquivo
  ordenarListaSecoes(listaSecoes);
  imprimirArquivo(listaSecoes);

    return 0;
}