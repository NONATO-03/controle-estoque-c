#ifndef menu
#define menu

#include <stdio.h>
#include <string.h>
#include "variaveis"

//TODAS AS OPÇÕES SELECIONAVÉIS DO MENU PRINCIPAL SERÃO CONDUZIDAS POR AQUI.

//FUNÇÃO PARA MOSTRAR TODOS OS PRODUTOS CADASTRADOS PQ EU TAVA COM PREGUIÇA DE ESCREVER ISSO TODA VEZ

void mostrarProdutos() {
    
    for(int i = 0; i < TotalProdutosCadastrados; i++) {
           
        printf("\n");
        printf("===========================================\n");
        printf(" CÓDIGO DO PRODUTO:      %d\n", produtosCadastraveis[i].codigo);
        printf(" NOME DO PRODUTO:        %s\n", produtosCadastraveis[i].nomeProduto);
        printf(" CATEGORIA:              %s\n", produtosCadastraveis[i].categoria);
        printf(" QUANTIDADE EM ESTOQUE:  %d unidades\n", produtosCadastraveis[i].qntdEmEstoque);
        printf(" PREÇO UNITÁRIO:      R$ %.2f\n", produtosCadastraveis[i].precoUnitario);
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
    printf("Digite quantos produtos você irá cadastrar: ");
    scanf("%d", &TotalProdutosCadastrando);
   
    //LOOP DE CADASTRO DE PRODUTOS
   
    for(int i = 0; i < TotalProdutosCadastrando; i++) {
        
        int indice = TotalProdutosCadastrados; // ALTERA EM QUAL POSIÇÃO O PRODUTO VAI SER GRAVADO
       
        printf("\n===========================================\n");
        printf("|                 Produto %d               |\n"          , i + 1);
        printf("===========================================\n");
       
        printf("\n Digite o código do produto: "); // CADASTRANDO O CÓDIGO DO PRODUTO
        scanf("%d", &produtosCadastraveis[indice].codigo);
       
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
       
        printf("\n Digite a validade do produto(coloque 0 se o produto não tiver validade)");
        while (getchar() != '\n'); //LIMPA O BUFFER
        printf("\n");
       
        printf("\n Digite o DIA de vencimento: "); //DIA
        scanf("%d", &produtosCadastraveis[indice].validade.dia);
       
        printf("\n Digite o MÊS de vencimento: "); //MES
        scanf("%d", &produtosCadastraveis[indice].validade.mes);
       
        printf("\n Digite o ANO de vencimento: "); // ANO
        scanf("%d", &produtosCadastraveis[indice].validade.ano);
       
        //FINALIZANDO CADASTRO DO PRODUTO(MOSTRA O QUE O USUÁRIO PREENCHEU ANTES DE CONFIRMAR)
       
        printf("\n");
        printf("Verifique as informações dos produto(s) cadastrado(s): \n");
        printf("\n");
        printf("===========================================\n");
        printf(" CÓDIGO DO PRODUTO:      %d\n", produtosCadastraveis[indice].codigo);
        printf(" NOME DO PRODUTO:        %s\n", produtosCadastraveis[indice].nomeProduto);
        printf(" CATEGORIA:              %s\n", produtosCadastraveis[indice].categoria);
        printf(" QUANTIDADE EM ESTOQUE:  %d unidades\n", produtosCadastraveis[indice].qntdEmEstoque);
        printf(" PREÇO UNITÁRIO:      R$ %.2f\n", produtosCadastraveis[indice].precoUnitario);
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
        
        printf("Você possuí %d produto(s) cadastrados.\n", TotalProdutosCadastrados);
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
            printf("CÓDIGO DO PRODUTO: %d\n", produtosCadastraveis[i].codigo);
            printf("NOME DO PRODUTO: %s", produtosCadastraveis[i].nomeProduto);
            printf("CATEGORIA: %s\n", produtosCadastraveis[i].categoria);
            printf("QUANTIDADE EM ESTOQUE: %d\n", produtosCadastraveis[i].qntdEmEstoque);
            printf("PREÇO UNITÁRIO: R$ %.2f\n", produtosCadastraveis[i].precoUnitario);
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
    
      // BUBBLE SORT(ESTUDAR)
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

//OPÇÃO [ 5 ] - Ordernar por válidade(Bubble sort)(Crescente)-------------------------------------------------------------------------------------------------------------------------------------------------------   
void ordenarValidade() {
    
    //Ordenar por validade (crescente) e listar os itens que vencem nos próximos X dias, sendo X
   //informado pelo usuário.  
   
    //USUARIO ESCOLHE OS PRODUTOS QUE VENCEM NOS PROXIMOS X DIAS
    
    int diasEscolhidos;
    
     printf("\n");
     printf("===========================================\n");
     printf("|      RELATORIO POR DATA DE VALIDADE     |\n");
     printf("===========================================\n");
     printf("\n");
      
     printf("Defina quantos dias à frente quer ver produtos vencendo: ");
     
     //arrumar
}

#endif