#include <stdio.h>

int main() {
    float celsius;
    
    printf("Digite a temperatura em graus Cº: ");
    scanf("%f", &celsius);

    printf("\n%f\n", (celsius * 1.8) + 32);

}