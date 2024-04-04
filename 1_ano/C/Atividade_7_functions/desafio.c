#include <stdio.h>
#include <stdbool.h>

typedef struct Produto{
    int codigo;
    char perfil[30];
    int qtd_estoque;
    int estoque_min;
    float preço_compra;
    float preço_venda;
}produto;


void cadastrarProduto(produto *prod){
    int num;
    
    while (true){
        if (num == 0){
            break;
        }
        
        printf("Digite o código do produto: ");

        scanf("%d",&prod->codigo);

        getchar();
        printf("Descrição: ");
        fgets(prod->perfil,sizeof(prod->perfil),stdin);

        printf("Quantidade no estoque: ");
        scanf("%d",&prod->qtd_estoque);

        printf("Quantidade mínima necessária no estoque: ");
        scanf("%d",&prod->estoque_min);

        printf("Preço de compra: ");
        scanf("%f",&prod->preço_compra);

        printf("Preço de venda: ");
        scanf("%f",&prod->preço_venda);

        printf("\nCadastrar um produto\nCadastrar[1]\nSair[0]\n ");

    }
} 

void listProducts(produto prod){
    
}

int main(){
    produto prod;
    int num;

    printf("Cadastrar um produto\nCadastrar[1]\nSair[0]\n ");
    scanf("%d",&num);

    switch (num){
        case 1: cadastrarProduto(&prod); 
        default: printf("erro");
    }
}