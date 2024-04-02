#include "../include/materiais.h"
#include "../include/menu.h"
#include "../include/secao.h"
#include <stdio.h>
#include <stdlib.h>

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
      adicionarSecao(&secoes);
      break;
    case 2:
      adicionarMaterial(&materiais, &secoes);
      break;
    case 3:
      buscarMaterial(secoes);
      break;
    case 4:
      realizarVenda(&materiais);
      break;
    case 5:
      removerMaterial(&materiais);
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
