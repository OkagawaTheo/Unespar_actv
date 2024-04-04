#include <stdio.h>

int main(){
    int a,b;
    //printf("%d\n",&a);
    //printf("%d",&b);

    if (&a > &b){
        printf("Maior endereço é da variável a com valor %d",&a);
    } 
    else printf("O maior endereço é da variável b com valor de %d",&b);
}