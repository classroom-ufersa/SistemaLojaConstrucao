#include "../include/materiais.h"
#include "../include/secao.h"
#include "../include/sistema.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Secao *secoes = NULL;
  Material *materiais = NULL;
  carregarDados(&secoes);
  int escolha;
  do {
    menu();
    escolha = lerNumeroInteiro();
    switch (escolha) {
    case 1:
      adicionarSecao(&secoes);
      salvarDados(secoes);
      break;
    case 2:
      adicionarMaterial(&secoes);
      salvarDados(secoes);
      break;
    case 3:
      buscarMaterial(secoes);
      break;
    case 4:
      realizarVenda(secoes);
      salvarDados(secoes);
      break;
    case 5:
      removerMaterial(secoes);
      salvarDados(secoes);
      break;
    case 6:
      removerSecao(&secoes);
      salvarDados(secoes);
      break;
    case 7:
      listarSecoes(secoes);
      break;
    case 8:
      printf("Saindo do programa...\n");
      break;
    default:
      printf("Opçao invalida. Por favor, tente novamente.\n");
    }
  } while (escolha != 8);

  salvarDados(secoes);
  liberarMemoria(&secoes);
  return 0;
}