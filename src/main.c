#include "../include/secao.h"
#include "../include/listaencadeada.h"



int main() {
    ListaSecoes *listaSecoes = criarListaSecoes();
    listaSecoes = criarSecao("Ferramentas", "local massa", listaSecoes); 
    listaSecoes = criarSecao("Decoração", "local massa", listaSecoes); 
    listaSecoes = criarSecao("Hidraulica", "local massa", listaSecoes); 
    listaSecoes = criarSecao("Eletrica", "local massa", listaSecoes); 
    
    printf("\n Seções Cadastradas: \n"); 
    
    imprimirListaSecoes(listaSecoes);
    return 0;
};
