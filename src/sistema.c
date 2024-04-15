#include "../include/sistema.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
  printf("\n==== Menu ====\n");
  printf("1. Adicionar secao\n");
  printf("2. Adicionar material\n");
  printf("3. Buscar material\n");
  printf("4. Realizar venda\n");
  printf("5. Remover material\n");
  printf("6. Remover secao\n");
  printf("7. Listar todas as secoes e seus materiais\n");
  printf("8. Sair\n");
}

char *formatarString(char *str) {

  if (!isupper(str[0])) {
    str[0] = toupper(str[0]);
  }

  for (int i = 1; i < strlen(str); i++) {
    if (!islower(str[i])) {
      str[i] = tolower(str[i]);
    }
  }

  return str;
}

int lerNumeroInteiro() {
  char opcao[100];
  int inteiroValido = 1;

  // Solicita ao usuario que insira uma opcao
  scanf("%s", opcao);

  // Verifica se a entrada e um numero
  for (int i = 0; i < strlen(opcao); i++) {
    if (!isdigit(opcao[i])) {
      inteiroValido = 0;
      break;
    }
  }

  while (!inteiroValido) {
    printf("Entrada invalida. Por favor, insira um numero inteiro: ");
    scanf("%s", opcao);

    inteiroValido = 1;

    for (int i = 0; i < strlen(opcao); i++) {
      if (!isdigit(opcao[i])) {
        inteiroValido = 0;
        break;
      }
    }
  }

  return atoi(opcao);
}
