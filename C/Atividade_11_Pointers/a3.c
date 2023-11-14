#include <stdio.h>

int main(){
    int a,b;
    printf("Digite um valor para A e um para B: \n");
    scanf("%d %d",&a,&b);

    if (&a > &b){
        printf("Maior endereço é do a. Conteúdo: %d",a);
    } else printf("Maior endereço é do b. Conteúdo: %d",b);
}