#include "../include/sistema.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void menu() {
  printf("\n==== Menu ====\n");
  printf("1. Adicionar secão\n");
  printf("2. Adicionar material\n");
  printf("3. Buscar material\n");
  printf("4. Realizar venda\n");
  printf("5. Remover material\n");
  printf("6. Remover secão\n");
  printf("7. Listar todas as secões e seus materiais\n");
  printf("8. Sair\n");
}

char *formatarString(char *str) {

  if (!isupper(str[0])) {
    str[0] = toupper(str[0]);
  }

  return str;
}

int lerNumeroInteiro() {
    char opcao[100];
    int inteiroValido = 1;

    printf("\nEscolha uma opção: ");

    // Solicita ao usuário que insira uma opção
    scanf("%s", opcao);

    // Verifica se a entrada é um número
    for(int i = 0; i < strlen(opcao); i++) {
        if(!isdigit(opcao[i])) {
            inteiroValido = 0;
            break;
        }
    }

    while (!inteiroValido) {
        printf("Entrada inválida. Por favor, insira um número inteiro: ");
        scanf("%s", opcao);
        
        inteiroValido = 1; 
        
        for(int i = 0; i < strlen(opcao); i++) {
            if(!isdigit(opcao[i])) {
                inteiroValido = 0;
                break;
            }
        }
    }

    return atoi(opcao);
}
