#include <stdio.h>

void preencher_array(int *arr, int size, int value) {
    int *ptr = arr;
    while (ptr < arr + size) {
        *ptr = value;
        ptr++;
    }
}

int main() {
    int size, value;

    printf("Digite o tamanho do array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Tamanho inválido. Digite um valor positivo para o tamanho do array.\n");
        return 1;
    }

    printf("Digite o valor a ser preenchido: ");
    scanf("%d", &value);

    int arr[size];

    preencher_array(arr, size, value);

    printf("Array preenchido com o valor %d:\n", value);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
