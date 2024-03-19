#include <stdio.h>
#include "../include/secao.h"
#include "../include/listaencadeada.h"

int main() {
    // Criando uma lista de seções
    ListaSecoes *listaSecoes = criarListaSecoes();

    // Criando algumas seções e adicionando à lista
    listaSecoes = criarSecao("Ferramentas", "Local 1", listaSecoes);
    listaSecoes = criarSecao("Decoração", "Local 2", listaSecoes);
    listaSecoes = criarSecao("Hidráulica", "Local 3", listaSecoes);

    // Imprimindo a lista de seções
    printf("Lista de Seções:\n");
    imprimirListaSecoes(listaSecoes);

    // Adicionando materiais às seções
    adicionar_material(listaSecoes->secao, "Martelo", "Ferramenta", 15.99, 20);
    adicionar_material(listaSecoes->prox->secao, "Vaso", "Decoração", 29.99, 10);
    adicionar_material(listaSecoes->prox->prox->secao, "Encanamento", "Hidráulica", 10.50, 15);

    // Buscando materiais
    printf("\nBuscando materiais:\n");
    Material material1 = {"Martelo", "Ferramenta", 0.0, 0};
    buscar_material(&material1, listaSecoes);
    Material material2 = {"Vaso", "Decoração", 0.0, 0};
    buscar_material(&material2, listaSecoes);
    Material material3 = {"Encanamento", "Hidráulica", 0.0, 0};
    buscar_material(&material3, listaSecoes);

    // Removendo materiais
    printf("\nRemovendo materiais:\n");
    Material material4 = {"Martelo", "Ferramenta", 0.0, 0};
    remover_material(&material4, listaSecoes->secao);

    // Imprimindo a lista de seções após a remoção
    printf("\nLista de Seções após Remoção:\n");
    imprimirListaSecoes(listaSecoes);

    return 0;
}
