# Sistema de Gerenciamento de Loja de Material de Construção
Este é um sistema desenvolvido em C para auxiliar na gestão de seções e materiais no estoque de uma loja de material de construção, desenvolvido para a disciplina de Algoritmos e Estruturas de Dados I.

## Estrutura do Projeto:
- include/: Este diretório contém os arquivos de cabeçalho necessários para o funcionamento do programa.
- src/: Aqui estão os arquivos fonte do programa, incluindo o arquivo principal main.c.

## Como Compilar e Executar:
Para compilar o programa, você pode usar um compilador C compatível com o padrão C99. Aqui está um exemplo de como compilar e executar o projeto utilizando o GCC:

```bash
gcc -c src/main.c src/materiais.c src/menu.c src/secao.c
gcc -o main.out src/main.o src/menu.o src/secao.o
./main.out
```
## Funcionalidades do Programa:
- **Adicionar Seção**: Permite adicionar uma nova seção ao sistema.
- **Adicionar Materia**: Adiciona um novo material a uma seção existente.
- **Buscar Material**: Realiza uma busca por um material específico no sistema.
- **Realizar Venda**: Registra uma venda de material, atualizando o estoque.
- **Remover Material**: Remove um material do sistema.
- **Remover Seção**: Remove uma seção do sistema, juntamente com seus materiais.
- **Listar Seções**: Exibe todas as seções e seus respectivos materiais.
- **Sair do Programa**: Encerra a execução do programa.

## Como Utilizar:
Ao executar o programa, um menu será exibido com as opções disponíveis. Basta selecionar a opção desejada digitando o número correspondente e pressionar Enter. O programa irá guiá-lo através das diferentes funcionalidades disponíveis. Todos os dados são salvos em um arquivo txt chamado dados.txt, que será criado na mesma pasta do executável.
