#include "opcoesmenu"
#include "menu"
#include "variaveis"
#include <stdio.h>
#include <string.h>
// A FAZERES:

//Ordenar por validade (crescente) e listar os itens que vencem nos próximos X dias, sendo X
//informado pelo usuário.   

//Buscar produto por código (após ordenar por código) usando busca binária, permitindo atualizar
//quantidade (entrada/saída de estoque) e preço.

//Utilizar bubble sort para ordenações (por preço, validade e código).

//Implementar comparações de datas de validade para identificar os produtos mais próximos do vencimento.


int main() {
   
opcaoSelecionada = 0;


    while(opcaoSelecionada != 7) { //VAI RODAR O MENU PRINCIPAL ATÉ O USUÁRIO ESCOLHER [7] - SAIR DO PROGRAMA
        exibirMenu();
    };

    return 0;
}
