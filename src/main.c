#include "../include/secao.h"
#include "../include/listaencadeada.h"



int main() {
    ListaSecoes *listaSecoes = criarListaSecoes();
    criarSecao("Ferramentas", "local massa", listaSecoes); 
    criarSecao("Decoração", "local massa", listaSecoes); 
    criarSecao("Hidraulica", "local massa", listaSecoes); 
    criarSecao("Eletrica", "local massa", listaSecoes); 

    return 0;
};
