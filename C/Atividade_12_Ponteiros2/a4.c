#include <stdio.h>

void ordena_valores(int *val1, int *val2, int *val3) {
    int temp;
    if (*val1 > *val2) {
        temp = *val1;
        *val1 = *val2;
        *val2 = temp;
    }

    if (*val2 > *val3) {
        temp = *val2;
        *val2 = *val3;
        *val3 = temp;

        if (*val1 > *val2) {
            temp = *val1;
            *val1 = *val2;
            *val2 = temp;
        }
    }
}

int le_valor() {
    int valor;
    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);
    return valor;
}

int main() {
    int valor1, valor2, valor3;
    valor1 = le_valor();
    valor2 = le_valor();
    valor3 = le_valor();

    ordena_valores(&valor1, &valor2, &valor3);

    printf("Valores ordenados: %d, %d, %d\n", valor1, valor2, valor3);

    return 0;
}
