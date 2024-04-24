#include <stdio.h>
#include <math.h>

void maiorNumero(double a, double b){
    if (a > b){
        printf("Número %lf é maior.",a);
    } else if (a < b){
        printf("Número %lf é maior.",b);
    } else printf("Iguais.");
}


void squareRoot(double num){
    printf("%lf",sqrt(num));
}

void fat(double num){
    int fat;
    for(fat = 1; num > 1; num-=1){
        fat *= num;
    }
    printf("%d",fat);
}

int main(){
    double a,b,num;
    printf("Digite os dois números: ");
    scanf("%lf %lf",&a,&b);
    maiorNumero(a,b);

    printf("\nDigite um número para saber sua raiz e fatorial: ");
    scanf("%lf",&num);

    squareRoot(num);
    fat(num);
}