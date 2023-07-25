#include <stdio.h>
#include <math.h>

int main(){

    double raio;
    double const pi = 3.14;

    printf("\nInsira o valor do raio do circulo: ");
    scanf("%lf",&raio);

    printf("O valor da área do círculo é %lf\n",pi * pow(raio,2));
}

// usar parâmetro -lm ao executar
