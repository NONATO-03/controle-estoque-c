#ifndef opcoesmenu     
#define opcoesmenu   

#include <stdio.h>
#include <string.h>
#include "variaveis"
#include "menu"

//MENU PRINCIPAL----------------------------------------------------------------------------------------------------------------------------------------------------------
void exibirMenu() {
opcaoSelecionada = 0;
     
    printf("\n");
    printf("===========================================\n");
    printf("|         CONTROLE DE ESTOQUE - MENU       | \n");
    printf("===========================================\n");
    printf(" [1] Cadastrar produto                    \n");
    printf(" [2] Listar todos os produtos             \n");
    printf(" [3] Relatório por categoria              \n");
    printf(" [4] Ordenar por preço (decrescente)      \n");
    printf(" [5] Ordenar por validade (crescente)     \n");
    printf(" [6] Buscar produto por código            \n");
    printf(" [7] Sair do programa                     \n");
    printf("\n");
    printf("Digite sua opção: ");
     
    scanf("%d", &opcaoSelecionada); //VARIÁVEL USADA EM SWITCH'S
    while (getchar() != '\n');


//DIRECIONAR O USUÁRIO COM BASE NA ESCOLHA DO MENU  
switch (opcaoSelecionada) {
    case 1: cadastrarProduto(); break;
    case 2: listarProdutos(); break;
    case 3: relatorio(); break;
    case 4: ordenarPreco(); break;
    case 5: ordenarValidade(); break;
    case 6: break;
    case 7: break;
    default: printf("\n"); printf("Opção inválida. Tente novamente\n"); printf("\n");
       };
     
};


#endif