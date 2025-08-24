#ifndef VARIAVEIS_H
#define VARIAVEIS_H

#include <stdio.h>
#include <string.h>

// VARIAVEIS DE MULTIUSO DO CÓDIGO--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//ESTRUTURA DE VARIAVÉIS
typedef struct { // CRIANDO UMA STRUCT SEM TIPO
    int dia, mes, ano; //VALIDADE DO PRODUTO
}ValidadeTipo; //TYPE DA VARIAVEL

struct produto {
    int codigo; // CODIGO DO PRODUTO
    char nomeProduto[50]; // NOME DO PRODUTO
    char categoria[20]; // CATEGORIA DO PRODUTO
    int qntdEmEstoque; // QNTD EM ESTOQUE DO PRODUTO
    float precoUnitario; // PREÇO DO PRODUTO
    ValidadeTipo validade; // VALIDADE DO PRODUTO
};

//FUNÇÕES IMPORTANTES
//mostrarProdutos(); // MOSTRA TODOS OS PRODUTOS CADASTRADOS

// VARIAVEIS GLOBAIS
extern struct produto produtosCadastraveis[10]; // TOTAL DE ESPAÇOS NO VETOR QUE SERÃO USADOS PARA CADASTRAR PRODUTOS.
extern int TotalProdutosCadastrando; // VARIÁVEL QUE GUARDA QUANTOS PRODUTOS VÃO SER CADASTRADOS DE UMA SÓ VEZ.
extern int opcaoSelecionada; // USADO EM SWITCH'S.
extern int TotalProdutosCadastrados; // QUANTIDADE TOTAL DE PRODUTOS QUE FORAM CADASTRADOS(USADO PARA RASTREAR QUAIS ESPAÇOS NO VETOR FORAM OCUPADOS).


#endif