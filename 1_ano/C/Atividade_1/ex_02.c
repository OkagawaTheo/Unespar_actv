#include <stdio.h>
#include <math.h>

int main() {
    float pi = 3.14;
    float r, h,area;
    float litros,latas, valorTotal;
    
    printf("\nDigite o valor do raio: ");
    scanf("%f",&r);

    printf("\nDigite a altura: ");
    scanf("%f",&h);

    area = (pi * pow(r,2)) + ((2 *pi) * r * h);

    printf("\nÁrea: %f",area);

    litros = area / 3;
    latas = ceil(litros / 5);
    valorTotal = ceil(latas) * 50;

    printf("\nForam compradas %.0f latas e custou R$%.2f\n",latas,valorTotal);

}

