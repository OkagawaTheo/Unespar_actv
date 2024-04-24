#include <stdio.h>

int main(){
    int num;
    
    printf("Digite um número para ver se é par ou ímpar: ");
    scanf("%d",&num);

    if (num % 2 == 0){
        printf("Par");
    } else{ 
        printf("Ímpar"); 
    }
}