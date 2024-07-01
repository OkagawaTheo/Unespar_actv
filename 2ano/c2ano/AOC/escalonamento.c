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
    //ordenar menor pra maior
    for (int i = 0; i < qtd_pedidos - 1; i++) {
        for (int j = 0; j < qtd_pedidos - i - 1; j++) {
            if (pedidos_cilindro[j] > pedidos_cilindro[j + 1]) {
                int temp = pedidos_cilindro[j];
                pedidos_cilindro[j] = pedidos_cilindro[j + 1];
                pedidos_cilindro[j + 1] = temp;
            }
        }
    }
    int pos_temp = 0;

    for (int i=0;i<qtd_pedidos;i++){
        if (pedidos_cilindro[i] >= pos_temp){
            transicoes[pedidos_cilindro[i]-1] = 'x';
            fitaCilindro(tamanho_cilindro,transicoes);
            pos_temp = pedidos_cilindro[i];
        }
    }
    for (int i=qtd_pedidos-1;i>=0;i--){
        if (pedidos_cilindro[i] < pos_temp){
            transicoes[pedidos_cilindro[i]-1] = 'x';
            fitaCilindro(tamanho_cilindro,transicoes);
            pos_temp = pedidos_cilindro[i];
        }
    }
    fitaCilindro(tamanho_cilindro, transicoes);
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
