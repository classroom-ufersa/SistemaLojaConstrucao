#ifndef MENU_H
#define MENU_H

/**
 * @brief Função para apresentar o menu.
 *
 */
void menu();

/*
 * @brief Formata uma string (colocando o primeiro caractere como letra
 * maiúscula)
 *
 * @param *str String para ser formatada
 *
 * @return char* String formatada (com primeira letra maiúscula);
 */
char *formatarString(char *str);

/**
 * @brief Função para ler um inteiro, validando para que apenas números inteiros
 * sejam lidos.
 *
 * @return int Número inteiro validado.
 */
int lerNumeroInteiro();
#endif
