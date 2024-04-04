#include <stdio.h>

int main() {
    int A, *B, **C, ***D;
    B = &A;
    C = &B;
    D = &C;

    printf("Digite um valor inteiro para A: ");
    scanf("%d", &A);

    printf("Dobro: %d\n", (*B) * 2);
    printf("Triplo: %d\n", (**C) * 3);
    printf("Quádruplo: %d\n", (***D) * 4);

    return 0;
}
