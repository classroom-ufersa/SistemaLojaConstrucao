#include <stdlib.h>
#include <stdio.h>
#include "../include/secao.h"
#include "../include/materiais.h"
#include "../include/menu.h"

int main() {
    Secao *secoes = NULL;
    Material *materiais = NULL;

    // Carregar dados das seções e materiais do arquivo único
    carregarSecoesMateriais(&secoes, &materiais);

    int escolha;
    do {
        menu();
        printf("\nEscolha uma opção: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                adicionarMaterial(&materiais, &secoes);
                break;
            case 2:
                removerMaterial(&materiais);
                break;
            case 3:
                realizarVenda(&materiais);
                break;
            case 4:
                buscarMaterial(materiais);
                break;
            case 5:
                adicionarSecao(&secoes);
                break;
            case 6:
                removerSecao(&secoes);
                break;
            case 7:
                listarSecoes(secoes);
                break;
            case 8: 
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
        }
    } while (escolha != 8); 

    salvarDados(secoes);

    return 0;
}