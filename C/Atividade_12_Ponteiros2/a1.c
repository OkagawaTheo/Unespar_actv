#include <stdio.h>

void TrocarValores(int *n1,int *n2){
    int aux;
    if (*n2 > *n1){
        aux = *n1;
        *n1 = *n2;
        *n2 = aux;
        printf("%d %d",*n1,*n2);
    } 
    else if (*n1 == *n2) printf("Iguais.");
    else printf("%d %d",*n1,*n2);
}

int main(){
    int num1,num2;
    
    printf("Digite dois valores inteiros: ");
    scanf("%d %d",&num1,&num2);
    TrocarValores(&num1,&num2);
}