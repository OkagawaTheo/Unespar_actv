#include <stdio.h>
#include <math.h>

int main(){

    float raio,p;
    
    p = 3.14;

    printf("Insira o valor do raio do circulo: ");
    scanf("%f",&raio);

    printf("O valor da área do círculo é %f",p*pow(raio,2));
}

// caso nao compilar, colocar -lm ao executar

