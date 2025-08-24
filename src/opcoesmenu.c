#define menu

#include "opcoesmenu.h"
#include "variaveis.h"
#include <stdio.h>
#include <string.h>

//TODAS AS OPÇÕES SELECIONAVÉIS DO MENU PRINCIPAL SERÃO CONDUZIDAS POR AQUI.

//FUNCAO QUE VERIFICA SE O CODIGO DO PRODUTO JA FOI ESCRITO
int codigoJaExiste(int codigo) {
    for(int i = 0; i < TotalProdutosCadastrados; i++) {
        if(produtosCadastraveis[i].codigo == codigo)
            return 1; // já existe
    }
    return 0;
}
//FUNÇÃO PARA MOSTRAR TODOS OS PRODUTOS CADASTRADOS PQ EU TAVA COM PREGUIÇA DE ESCREVER ISSO TODA VEZ
void mostrarProdutos() {
    
    for(int i = 0; i < TotalProdutosCadastrados; i++) {
           
        printf("\n");
        printf("===========================================\n");
        printf(" CODIGO DO PRODUTO:      %d\n", produtosCadastraveis[i].codigo);
        printf(" NOME DO PRODUTO:        %s\n", produtosCadastraveis[i].nomeProduto);
        printf(" CATEGORIA:              %s\n", produtosCadastraveis[i].categoria);
        printf(" QUANTIDADE EM ESTOQUE:  %d unidades\n", produtosCadastraveis[i].qntdEmEstoque);
        printf(" PRECO UNITARIO:      R$ %.2f\n", produtosCadastraveis[i].precoUnitario);
        printf(" VALIDADE:               %02d/%02d/%04d\n", produtosCadastraveis[i].validade.dia, produtosCadastraveis[i].validade.mes, produtosCadastraveis[i].validade.ano);
        printf("===========================================\n");
        printf("\n");
        };
    
}

// OPÇÃO [ 1 ] - Cadastrar produto-------------------------------------------------------------------------------------------------------------------------------
void cadastrarProduto() {

    //FUNCÃO AUTOEXPLICATIVA(PRECISA FORNECER PERGUNTAS PARA QUE O USUARIO CADASTRE UM PRODUTO)

  printf("\n");
    printf("===========================================\n");
    printf("|            CADASTRAR PRODUTO            |\n");
    printf("===========================================\n");
    printf("\n");
    printf("Digite quantos produtos voce vai cadastrar: ");
    scanf("%d", &TotalProdutosCadastrando);
   
    //LOOP DE CADASTRO DE PRODUTOS
   
    for(int i = 0; i < TotalProdutosCadastrando; i++) {
        
        int indice = TotalProdutosCadastrados; // ALTERA EM QUAL POSIÇÃO O PRODUTO VAI SER GRAVADO
       
        printf("\n===========================================\n");
        printf("|                 Produto %d               |\n"          , i + 1);
        printf("===========================================\n");

    //PEDE PRO USUARIO DIGITAR O CODIGO E VERIFICA SE JA EXISTE 
       do {
    printf("\nDigite o codigo do produto: ");
    scanf("%d", &produtosCadastraveis[indice].codigo);

    if(codigoJaExiste(produtosCadastraveis[indice].codigo)) {
        printf("\n");
        printf("Codigo ja existe! Digite outro.\n");
        printf("\n");
    }

    } while(codigoJaExiste(produtosCadastraveis[indice].codigo));
       
        printf("\n Digite o nome do produto: "); // CADASTRANDO O NOME DO PRODUTO
        while(getchar() != '\n'); //LIMPANDO BUFFER
        fgets(produtosCadastraveis[indice].nomeProduto, sizeof(produtosCadastraveis[indice].nomeProduto), stdin);
       
       
         // CADASTRANDO A CATEGORIA DO PRODUTO
        printf("\n Escolha a categoria que o produto se encaixa: ");
        printf("\n");
        printf(" [1] Alimentos\n");
        printf(" [2] Limpeza\n");
        printf(" [3] Bebidas\n");
        printf(" [4] Higiene\n");
        printf(" [5] Outros\n");
        printf("\n");
       
        printf("Categoria: ");
       
        opcaoSelecionada = 0;
       
        scanf("%d", &opcaoSelecionada);
       
        //OPÇÕES DE CATEGORIAS PARA O PRODUTO
       
        switch (opcaoSelecionada) {
          case 1: strcpy(produtosCadastraveis[indice].categoria, "Alimentos"); break;
          case 2: strcpy(produtosCadastraveis[indice].categoria, "Limpeza"); break;
          case 3: strcpy(produtosCadastraveis[indice].categoria, "Bebidas"); break;
          case 4: strcpy(produtosCadastraveis[indice].categoria, "Higiene"); break;
          case 5: strcpy(produtosCadastraveis[indice].categoria, "Outros"); break;
          default: strcpy(produtosCadastraveis[indice].categoria, "Outros");
     };
       
        printf("\n Digite a quantidade em estoque do produto: "); // CADASTRANDO A QUANTIDADE
        scanf("%d", &produtosCadastraveis[indice].qntdEmEstoque);
       
        printf("\n Digite o valor do produto: R$ "); // CADASTRANDO O PREÇO
        scanf("%f", &produtosCadastraveis[indice].precoUnitario);
       
        // CADASTRANDO A VALIDADE
       
        printf("\n");
        printf("===========================================\n");
        printf("|           VALIDADE DO PRODUTO            |\n");
        printf("===========================================\n");
        printf("\n");
       
        printf("\n Digite a validade do produto(coloque 0 se o produto nao tiver validade)");
        while (getchar() != '\n'); //LIMPA O BUFFER
        printf("\n");
       
        printf("\n Digite o DIA de vencimento: "); //DIA
        scanf("%d", &produtosCadastraveis[indice].validade.dia);
       
        printf("\n Digite o MES de vencimento: "); //MES
        scanf("%d", &produtosCadastraveis[indice].validade.mes);
       
        printf("\n Digite o ANO de vencimento: "); // ANO
        scanf("%d", &produtosCadastraveis[indice].validade.ano);
       
        //FINALIZANDO CADASTRO DO PRODUTO(MOSTRA O QUE O USUÁRIO PREENCHEU ANTES DE CONFIRMAR)
       
        printf("\n");
        printf("Verifique as informacoes dos produto(s) cadastrado(s): \n");
        printf("\n");
        printf("===========================================\n");
        printf(" CODIGO DO PRODUTO:      %d\n", produtosCadastraveis[indice].codigo);
        printf(" NOME DO PRODUTO:        %s\n", produtosCadastraveis[indice].nomeProduto);
        printf(" CATEGORIA:              %s\n", produtosCadastraveis[indice].categoria);
        printf(" QUANTIDADE EM ESTOQUE:  %d unidades\n", produtosCadastraveis[indice].qntdEmEstoque);
        printf(" PRECO UNITARIO:      R$ %.2f\n", produtosCadastraveis[indice].precoUnitario);
        printf(" VALIDADE:               %02d/%02d/%04d\n", produtosCadastraveis[indice].validade.dia, produtosCadastraveis[indice].validade.mes, produtosCadastraveis[indice].validade.ano);
        printf("===========================================\n");
        printf("\n");
       
        //CONFIRMAÇÃO DE CADASTRO DO PRODUTO
        printf("Aperte [S] para confirmar ou aperte [N] para cancelar o cadastro: ");
       
        char confirmarOUcancelar[2]; //CAPTA LETRAS DIGITADAS PELO USUÁRIO
       
        while (getchar() != '\n');// limpa o buffer
    
        scanf("%c", confirmarOUcancelar);
       
        //CASO CONFIRMÇÃO SEJA POSITIVA:
       
        if (strcmp(confirmarOUcancelar, "S") == 0 || strcmp(confirmarOUcancelar, "s") == 0) { //GARANTE TANTO "S" QUANTO "s"
           
            printf("\n");
            printf("===========================================\n");
            printf("|     PRODUTO CADASTRADO COM SUCESSO!      |\n");
            printf("===========================================\n");
            printf("\n");
            
            TotalProdutosCadastrados++;
         
         // CASO CONFIRMAÇÃO FOR NEGATIVA
           } 
           
           else {
            printf("\n");
            printf("Cadastro cancelado...\n");
            printf("\n");
            
            //ZERA TODOS OS CAMPOS PREENCHIDOS ANTERIORMENTE
            produtosCadastraveis[indice].codigo = 0;
            strcpy(produtosCadastraveis[indice].nomeProduto, "") ;
            strcpy(produtosCadastraveis[indice].categoria, "");
            produtosCadastraveis[indice].qntdEmEstoque = 0;
            produtosCadastraveis[indice].precoUnitario = 0;
            produtosCadastraveis[indice].validade.dia = 0;
            produtosCadastraveis[indice].validade.mes = 0;
            produtosCadastraveis[indice].validade.ano = 0;
        };
       
    }
}
 
//OPÇÃO [ 2 ] - Listar todos os produtos-------------------------------------------------------------------------------------------------------------------------------------------------------  
  void listarProdutos() {
      
     //FUNÇÃO AUTOEXPLICATIVA(MOSTRAR TODOS OS PRODUTOS CADASTRADOS)
     
        printf("\n");
        printf("===========================================\n");
        printf("|      LISTA DE PRODUTOS CADASTRADOS      |\n");
        printf("===========================================\n");
        printf("\n");
       
        mostrarProdutos();
        
        printf("Voce possui %d produto(s) cadastrados.\n", TotalProdutosCadastrados);
   };

//OPÇÃO [ 3 ] - Relatório por categoria-------------------------------------------------------------------------------------------------------------------------------------------------------  
 void relatorio() {
     
     //ESSA FUNÇÃO PRECISA MOSTRAR TODOS OS PRODUTOS DA CATEGORIA ESCOLHIDA E MOSTRAR O VALOR TOTAL DA CATEGORIA QNTD X PREÇO UNITARIO
     
     opcaoSelecionada = 0;
     int Encontrou = 0; //VARIAVEL QUE VAI DIZER QUE TEM OU NÃO ALGUM PRODUTO NAQUELA CATEGORIA
     float ValorDaCategoria = 0; //VARIAVEL QUE VAI SOMAR TODA A CATEGORIA
     
     //PEDIR PRO USUÁRIO ESCOLHER A CATEGORIA
     printf("\n");
     printf("===========================================\n");
     printf("|         RELATORIO POR CATEGORIA         |\n");
     printf("===========================================\n");
     printf("\n");
     
     printf("\n");
     printf("Escolha uma categoria: \n");
     printf("\n");
     
     printf(" [1] Alimentos\n");
     printf(" [2] Limpeza\n");
     printf(" [3] Bebidas\n");
     printf(" [4] Higiene\n");
     printf(" [5] Outros\n");
     printf("\n");
       
     printf("Categoria: ");
     scanf("%d", &opcaoSelecionada);
     
     const char* categoriaEscolhida; //APONTA PARA A OPÇÃO SEM ARMAZENAR
     
     //OPÇÕES DE CATEGORIAS PARA O PRODUTO
       
        switch (opcaoSelecionada) {
          case 1: categoriaEscolhida = "Alimentos"; break;
          case 2: categoriaEscolhida = "Limpeza"; break;
          case 3: categoriaEscolhida = "Bebidas"; break;
          case 4: categoriaEscolhida = "Higiene"; break;
          case 5: categoriaEscolhida = "Outros"; break; 
          default: categoriaEscolhida = "Outros";
        };
        
        printf("\n");
        printf("Categoria escolhida: %s", categoriaEscolhida);
        printf("\n");
        
        printf("\n");
        printf("===========================================\n");
        printf("          CATEGORIA: %s                \n", categoriaEscolhida);
        printf("===========================================\n");
        printf("\n");
        
      //PROCURANDO PELA CATEGORIA ESCOLHIDA  
     for(int i = 0; i < TotalProdutosCadastrados; i++) {
         
         if(strcmp(produtosCadastraveis[i].categoria, categoriaEscolhida) == 0) { //COMPARA AS STRING'S DESSAS 2 VARIÁVEIS, SE RETORNA 0 SIGNIFICA QUE SÃO IDENTICAS
             Encontrou = 1; // VARIAVEL CASO O LOOP NAO ENCONTRE NENHUM PRODUTO NA CATEGORIA  ESCOLHIDA
             
            printf("\n");
            printf("===========================================\n");
            printf("CODIGO DO PRODUTO: %d\n", produtosCadastraveis[i].codigo);
            printf("NOME DO PRODUTO: %s", produtosCadastraveis[i].nomeProduto);
            printf("CATEGORIA: %s\n", produtosCadastraveis[i].categoria);
            printf("QUANTIDADE EM ESTOQUE: %d\n", produtosCadastraveis[i].qntdEmEstoque);
            printf("PRECO UNITARIO: R$ %.2f\n", produtosCadastraveis[i].precoUnitario);
            printf("VALIDADE: %d/%d/%d\n", produtosCadastraveis[i].validade.dia, produtosCadastraveis[i].validade.mes, produtosCadastraveis[i].validade.ano);
            printf("===========================================\n");
            printf("\n");
            
            
         };
         
         //CALCULAR O VALOR TOTAL DA CATEGORIA
            ValorDaCategoria = ValorDaCategoria + produtosCadastraveis[i].qntdEmEstoque * produtosCadastraveis[i].precoUnitario;
            
     }; //FIM DO FOR
    
        //CASO NÃO ACHE NENHUM PRODUTO NA CATEGORIA ESCOLHIDA
            if(Encontrou == 0) {
                
            printf("\n");
            printf("Nenhum produto encontrado nessa categoria!");
            printf("\n");
            
         //MOSTRA O VALOR TOTAL DA CATEGORIA PRO USUÁRIO       
            } else {
                printf("\n");
                printf("Valor total da categoria[%s]: R$ %.2f", categoriaEscolhida, ValorDaCategoria);
                printf("\n");
            };    
         
 }
 
//OPÇÃO [ 4 ] - Ordenar por preço(Bubble sort)(Decrescente)-------------------------------------------------------------------------------------------------------------------------------------------------------   
void ordenarPreco() {
    //ESSA FUNÇÃO DEVE LISTAR TODOS OS PRODUTOS A PARTIR DO PREÇO EM ORDEM DECRESCENTE
    
      // BUBBLE SORT
    for (int i = 0; i < TotalProdutosCadastrados - 1; i++) {
        for (int j = 0; j < TotalProdutosCadastrados - i - 1; j++) {
            if (produtosCadastraveis[j].precoUnitario < produtosCadastraveis[j + 1].precoUnitario) {
                
                // TROCA AS POSIÇÕES
                struct produto temp = produtosCadastraveis[j];
                produtosCadastraveis[j] = produtosCadastraveis[j + 1];
                produtosCadastraveis[j + 1] = temp;
            };
        };
    };
    
    //FUNÇÃO QUE MOSTRA TODOS OS PRODUTOS CADASTRADOS
    mostrarProdutos();
}

//OPCAO [ 5 ] - ORDENAR POR VALIDADE(BUBBLE SORT)(CRESCENTE)------------------------------------------------------
//ORDENAR POR VALIDADE (CRESCENTE) E LISTAR OS PRODUTOS QUE VENCEM NOS PROXIMOS X DIAS
//USUARIO ESCOLHE A DATA DE HOJE E QUANTOS DIAS A FRENTE QUER VER
//NAO USA TIME.H, CONVERTE DATA EM DIAS

//BISSEXTO?
int anoBissexto(int ano) {
    return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}

//TRANSFORMA A DATA EM DIAS
int dataParaDiasPrecisos(ValidadeTipo v) {
    int diasMeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int totalDias = 0;

    //SOMA OS DIAS DOS ANOS COMPLETOS
    for(int a = 0; a < v.ano; a++) {
        totalDias += anoBissexto(a) ? 366 : 365;
    }

    //SOMA OS DIAS DOS MESES DO ANO ATUAL
    for(int m = 0; m < v.mes - 1; m++) {
        totalDias += diasMeses[m];
    }

    //+1 SE FOR BISSEXTO E JA PASSOU FEVEREIRO
    if(v.mes > 2 && anoBissexto(v.ano)) {
        totalDias++;
    }

    //SOMA OS DIAS DO MES ATUAL
    totalDias += v.dia;

    return totalDias;
}

void ordenarValidade() {
    int diasEscolhidos;

    ValidadeTipo hoje;

    printf("\n===========================================\n");
    printf("|      RELATORIO POR DATA DE VALIDADE     |\n");
    printf("===========================================\n");

    //PERGUNTA DATA DE HOJE
    printf("Digite a data de hoje:\n");
    printf("DIA: ");
    scanf("%d", &hoje.dia); //DIA
    printf("MES: ");
    scanf("%d", &hoje.mes); //MES
    printf("ANO: ");
    scanf("%d", &hoje.ano); //ANO

    printf("Defina quantos dias a frente deseja ver produtos vencendo: ");
    scanf("%d", &diasEscolhidos);

    //BUBBLE SORT
    for(int i = 0; i < TotalProdutosCadastrados - 1; i++) {
        for(int j = 0; j < TotalProdutosCadastrados - i - 1; j++) {
            int diasJ = (produtosCadastraveis[j].validade.dia == 0) ? 999999 : dataParaDiasPrecisos(produtosCadastraveis[j].validade);
            int diasJ1 = (produtosCadastraveis[j+1].validade.dia == 0) ? 999999 : dataParaDiasPrecisos(produtosCadastraveis[j+1].validade);

            if(diasJ > diasJ1) {
                struct produto temp = produtosCadastraveis[j];
                produtosCadastraveis[j] = produtosCadastraveis[j+1];
                produtosCadastraveis[j+1] = temp;
            }
        }
    }

    int hojeDias = dataParaDiasPrecisos(hoje);
    int encontrou = 0;

    //MOSTRA OS PRODUTOS VENCENDO
    printf("\nPRODUTOS QUE VENCEM NOS PROXIMOS %d DIAS:\n", diasEscolhidos);
    for(int i = 0; i < TotalProdutosCadastrados; i++) {
        int diasProduto = (produtosCadastraveis[i].validade.dia == 0) ? 999999 : dataParaDiasPrecisos(produtosCadastraveis[i].validade);

        if(diasProduto != 999999 && diasProduto <= hojeDias + diasEscolhidos) {
            encontrou = 1;
            printf("\n===========================================\n");
            printf("CODIGO DO PRODUTO: %d\n", produtosCadastraveis[i].codigo);
            printf("NOME DO PRODUTO: %s", produtosCadastraveis[i].nomeProduto);
            printf("CATEGORIA: %s\n", produtosCadastraveis[i].categoria);
            printf("QUANTIDADE EM ESTOQUE: %d\n", produtosCadastraveis[i].qntdEmEstoque);
            printf("PRECO UNITARIO: R$ %.2f\n", produtosCadastraveis[i].precoUnitario);
            printf("VALIDADE: %02d/%02d/%04d\n", produtosCadastraveis[i].validade.dia, produtosCadastraveis[i].validade.mes, produtosCadastraveis[i].validade.ano);
            printf("===========================================\n");
        }
    }

    //SE NAO TIVER NENHUM PRODUTO VENCENDO
    if(!encontrou) {
        printf("NENHUM PRODUTO VENCENDO NOS PROXIMOS %d DIAS.\n", diasEscolhidos);
    }
}

//OPCAO [ 6 ] - BUSCAR PRODUTO POR CODIGO(BUBBLE SORT + BUSCA BINARIA)--------------------------------------------
void buscarProdutoPorCodigo() {
    //ORDENA POR CODIGO CRESCENTE
    for(int i = 0; i < TotalProdutosCadastrados - 1; i++) {
        for(int j = 0; j < TotalProdutosCadastrados - i - 1; j++) {
            if(produtosCadastraveis[j].codigo > produtosCadastraveis[j+1].codigo) {
                struct produto temp = produtosCadastraveis[j];
                produtosCadastraveis[j] = produtosCadastraveis[j+1];
                produtosCadastraveis[j+1] = temp;
            }
        }
    }
    printf("\n");
    printf("===========================================\n");
    printf("|        BUSCAR PRODUTO POR CODIGO         |\n");
    printf("===========================================\n");
    printf("\n");

    //PERGUNTA O CODIGO DO PRODUTO
    int codigoProcurado;
    printf("\nDigite o codigo do produto que deseja buscar: ");
    printf("\n");
    scanf("%d", &codigoProcurado);

    //BUSCA BINARIA
    int esquerda = 0;
    int direita = TotalProdutosCadastrados - 1;
    int encontrado = 0;

    while(esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if(produtosCadastraveis[meio].codigo == codigoProcurado) {
            encontrado = 1;

            printf("\n");
            printf("PRODUTO ENCONTRADO:\n");
            printf("===========================================\n");
            printf("CODIGO DO PRODUTO: %d\n", produtosCadastraveis[meio].codigo);
            printf("NOME DO PRODUTO: %s", produtosCadastraveis[meio].nomeProduto);
            printf("CATEGORIA: %s\n", produtosCadastraveis[meio].categoria);
            printf("QUANTIDADE EM ESTOQUE: %d\n", produtosCadastraveis[meio].qntdEmEstoque);
            printf("PRECO UNITARIO: R$ %.2f\n", produtosCadastraveis[meio].precoUnitario);
            printf("VALIDADE: %02d/%02d/%04d\n", produtosCadastraveis[meio].validade.dia, produtosCadastraveis[meio].validade.mes, produtosCadastraveis[meio].validade.ano);
            printf("===========================================\n");
            printf("\n");

            //PERGUNTA PRO USUARIO SE ELE DESEJA MUDAR A QNTD OU PRECO DO PRODUTO
            char opcao;
            printf("Deseja atualizar a quantidade ou o preco? (S/N): ");
            while(getchar() != '\n');
            scanf("%c", &opcao);

            if(opcao == 'S' || opcao == 's') {
                printf("\n");
                printf("Digite a nova quantidade: ");
                scanf("%d", &produtosCadastraveis[meio].qntdEmEstoque);
                printf("Digite o novo preco: R$ ");
                scanf("%f", &produtosCadastraveis[meio].precoUnitario);
                printf("\nAtualizacao realizada com  sucesso!\n");
                printf("\n");
            }
            break;
        } else if(produtosCadastraveis[meio].codigo < codigoProcurado) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    //SE NAO ENCONTRAR O PRODUTO
    if(!encontrado) {
        printf("\n");
        printf("\nProduto com codigo %d nao encontrado.\n", codigoProcurado);
        printf("\n");
    }
}
