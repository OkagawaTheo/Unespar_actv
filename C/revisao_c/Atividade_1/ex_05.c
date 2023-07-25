#include <stdio.h>

int main(){
    int total;

    printf("\nDigite um valor e retornarei as possiveis notas disponíveis: ");
    scanf("%d",&total);
    
    printf("%d\n",total);
    printf("%d notas de R$ 100\n", total/100);
    total = total%100;
    printf("%d notas de R$ 50\n", total/50);
    total = total%50;
    printf("%d notas de R$ 20\n", total/20);
    total = total%20;
    printf("%d notas de R$ 10\n", total/10);
    total = total%10;
    printf("%d notas de R$ 5\n", total/5);
    total = total%5;
    printf("%d notas de R$ 2\n", total/2);
    total = total%2;
    printf("%d moedas de R$ 1\n", total%2);
}