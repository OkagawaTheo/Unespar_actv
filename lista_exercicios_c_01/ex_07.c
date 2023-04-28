#include <stdio.h>

int main() {
    int num;

    printf("\nInsira um número inteiro: ");
    scanf("%d",&num);

    if (num % 3 == 0){
        printf("\nO número %d é múltiplo de 3.");
    } else{
        printf("\nO número %d não é múltiplo de 3.\n");
    }
}
