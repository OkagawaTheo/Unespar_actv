#include <stdio.h>

void encontrar_maior_e_contagem(int valores[], int tamanho, int *maior, int *ocorrencias) {
    if (tamanho <= 0) {
        printf("Array vazio ou tamanho inválido.\n");
        return;
    }

    *maior = valores[0];
    *ocorrencias = 1;

    for (int i = 1; i < tamanho; i++) {
        if (valores[i] > *maior) {
            *maior = valores[i];
            *ocorrencias = 1;
        } else if (valores[i] == *maior) {
            (*ocorrencias)++;
        }
    }
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido. Digite um valor positivo para o tamanho do array.\n");
        return 1;
    }

    int valores[tamanho];

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &valores[i]);
    }

    int maior, ocorrencias;
    
    encontrar_maior_e_contagem(valores, tamanho, &maior, &ocorrencias);

    printf("Maior elemento: %d\n", maior);
    printf("Número de vezes que o maior elemento ocorreu: %d\n", ocorrencias);

    return 0;
}
