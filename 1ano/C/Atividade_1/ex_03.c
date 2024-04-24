#include <stdio.h>

int main() {
    int dist;
    float litros;

    printf("\nDigite a distância percorrida: ");
    scanf("%i", &dist);

    printf("\nDigite o total de combustivel gasto (em litros): ");
    scanf("%f", &litros);

    
    printf("\nConsumo médio de %d km rodados e %.1f litros consumidos é de %.2f km/l\n",dist,litros, (dist / litros));
}