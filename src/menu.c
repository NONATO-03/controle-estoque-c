#include "menu.h"
#include "variaveis.h"
#include "opcoesmenu.h"
#include <stdio.h>

//ESTÁ SEM PONTUAÇÃO, JÁ QUE NO .EXE BUGA.
//MENU PRINCIPAL
void exibirMenu() {
    printf("\n");
    printf("===========================================\n");
    printf("|         CONTROLE DE ESTOQUE - MENU       | \n");
    printf("===========================================\n");
    printf(" [1] Cadastrar produto                    \n");
    printf(" [2] Listar todos os produtos             \n");
    printf(" [3] Relatorio por categoria              \n");
    printf(" [4] Ordenar por preco (decrescente)      \n");
    printf(" [5] Ordenar por validade (crescente)     \n");
    printf(" [6] Buscar produto por codigo            \n");
    printf(" [7] Sair do programa                     \n");
    printf("\n");
    printf("Digite sua opcao: ");

    scanf("%d", &opcaoSelecionada);
    while (getchar() != '\n');

    //DIRECIONAR USUÁRIO COM BASE NA ESCOLHA DO MENU
    switch (opcaoSelecionada) {
        case 1: cadastrarProduto(); break;
        case 2: listarProdutos(); break;
        case 3: relatorio(); break;
        case 4: ordenarPreco(); break;
        case 5: ordenarValidade(); break;
        case 6: buscarProdutoPorCodigo(); break;
        case 7: break; // LOOP NO MAIN JA EXECUTA ESSE CASE
        default: printf("\nOpcao invalida. Tente novamente\n"); break;
    }
}
