#include <stdio.h>

int soma_arrays(const int *arr1, const int *arr2, int *resultado, int tamanho) {
    if (tamanho <= 0) {
        printf("Tamanho inválido.\n");
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        resultado[i] = arr1[i] + arr2[i];
    }

    return 1;
}

int main() {
    int tamanho;

    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido. Digite um valor positivo para o tamanho dos arrays.\n");
        return 1;
    }

    int arr1[tamanho], arr2[tamanho], resultado[tamanho];

    printf("Digite os elementos do primeiro array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Digite os elementos do segundo array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &arr2[i]);
    }

    int sucesso = soma_arrays(arr1, arr2, resultado, tamanho);

    if (sucesso) {
        printf("Soma dos arrays:\n");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");
    } else {
        printf("A soma não pode ser realizada devido a tamanhos diferentes.\n");
    }

}
