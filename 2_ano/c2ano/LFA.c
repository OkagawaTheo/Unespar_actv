#include <stdio.h>
#include <stdbool.h>

typedef struct Automato{
    int estado_inicial;
    int qtd_estados; //q0,q1 //por ponteiro dps
    int estados_finais[100];
    int qtd_estado_final;
    int qtd_simbolos;
    char simbolos[100];

}afdinfo;

bool verificacao(){

}

int main(){
    afdinfo afd; 
    int linhas_transicao, colunas_transicao;
    char palavra[100];
    printf("\tAutomato Finito Deterministico\t\n\n");
    printf("Digite o estado inicial: "); 
    scanf("%d",&afd.estado_inicial);
    
    printf("Digite a quantidade de estados: "); 
    scanf("%d",&afd.qtd_estados); //linhas matriz
    
    printf("Digite a quantidade de estados finais: "); 
    scanf("%d",&afd.qtd_estado_final); 

    for (int i=0;i<afd.qtd_estado_final;i++){ 
        printf("\tDigite o %dº estado final: ",i+1);
        scanf("%d",&afd.estados_finais[i]);
    }
    printf("Quantidade de símbolos: ");
    scanf("%d",&afd.qtd_simbolos); //colunas matriz
    for (int i=0;i<afd.qtd_simbolos;i++){
        printf("\tDigite o %dº simbolo do alfabeto:",i+1);
        scanf("%s",&afd.simbolos[i]);
    }
    linhas_transicao = afd.qtd_estados;
    colunas_transicao = afd.qtd_simbolos;
    int matriz_transicao[linhas_transicao][colunas_transicao];

    printf("Matriz transição:\n"); //matriz da tabela de transição
    for (int i=0;i<linhas_transicao;i++){
        for(int j=0;j<colunas_transicao;j++){
            scanf("%d",&matriz_transicao[i][j]);
        }
    }
    printf("\n Tabela de transição digitada: \n\n");
    for (int i=0;i<linhas_transicao;i++){
        for (int j=0;j<colunas_transicao;j++){
            printf("\t%d",matriz_transicao[i][j]);
        }
    printf("\n");
    }
    printf("Digite a palavra a ser testada: ");
    scanf("%s",&palavra);
}

