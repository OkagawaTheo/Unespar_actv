#include <stdio.h>
#include <stdlib.h>

void fitaCilindro(int tamanho_cilindro, char transicoes[]) {
    printf("\nRepresentação do cilindro SCAN:\n");
    
    for (int i = 0; i < tamanho_cilindro; i++) {
        printf("| %2d ", i + 1);  
    }
    printf("|\n");
    
    for (int i = 0; i < tamanho_cilindro; i++) {
        printf("| %2c ", transicoes[i]);  
    }
    printf("|\n");
}

void marcarCilindroEscalonamento(int tamanho_cilindro, int qtd_pedidos, char transicoes[], int pedidos_cilindro[]) {
    int menorDistancia = pedidos_cilindro[0];
    if 


    // for (int i=0;i<qtd_pedidos;i++){
    //     transicoes[menorDistancia-1] = 'x';
    fitaCilindro(tamanho_cilindro, transicoes);
    }
}


int main() {
    printf("Informe o tamanho do cilindro: ");
    int tamanho_cilindro;
    scanf("%d", &tamanho_cilindro);
    
    char transicoes[tamanho_cilindro];
    for (int i = 0; i < tamanho_cilindro; i++) {
        transicoes[i] = '-';
    }

    printf("Informe a quantidade de pedidos de cilindros: ");
    int qtd_pedidos;
    scanf("%d", &qtd_pedidos);
    
    int pedidos_cilindro[qtd_pedidos]; // Cria lista dos pedidos do tamanho da qtd pedida
    for (int i = 0; i < qtd_pedidos; i++) {
        printf("\tInforme o %dº pedido de cilindro: ", i + 1);
        scanf("%d", &pedidos_cilindro[i]);
    }

    fitaCilindro(tamanho_cilindro, transicoes);

    printf("\nVetor de pedidos: ");
    for (int i = 0; i < qtd_pedidos; i++) {
        printf("%d ", pedidos_cilindro[i]);
    }
    printf("\n");

    marcarCilindroEscalonamento(tamanho_cilindro, qtd_pedidos, transicoes, pedidos_cilindro);
}
