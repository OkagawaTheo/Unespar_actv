#include <stdio.h>

void TrocarValores(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a,b;
    printf("Digite dois números inteiros: ");
    scanf("%d %d",&a,&b);
    TrocarValores(&a,&b);
    printf("Valores Trocados: \n");
    printf("A = %d\n B = %d",a,b);
}