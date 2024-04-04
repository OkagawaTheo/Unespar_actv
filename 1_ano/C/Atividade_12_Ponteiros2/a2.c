#include <stdio.h>

void SomaDobro(int *a,int *b){
    *a *= 2;
    *b *= 2;
    printf("A soma do dobro dos dois números é: %d",*a+*b);
}

int main(){
    int a,b;

    printf("Digite dois valores inteiros: ");
    scanf("%d %d",&a,&b);
    SomaDobro(&a,&b);
}