#include <stdio.h>

void fitaCilindro(int tamanho_cilindro, char transicoes[]) {
    printf("\nRepresentação do cilindro:\n");
    
    for (int i = 0; i < tamanho_cilindro; i++) {
        printf("| %2d ", i + 1);  
    }
    printf("|\n");
    
    for (int i = 0; i < tamanho_cilindro; i++) {
        printf("| %2c ", transicoes[i]);  
    }
    printf("|\n");
}

void marcarCilindro(int tamanho_cilindro, int qtd_pedidos, char transicoes[], int pedidos_cilindro[]) {
    for (int i = 0; i < qtd_pedidos; i++) {
        transicoes[pedidos_cilindro[i] - 1] = 'x';
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
    
    int pedidos_cilindro[qtd_pedidos];
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

    marcarCilindro(tamanho_cilindro, qtd_pedidos, transicoes, pedidos_cilindro);
}
