#include <stdio.h>

int main(){

    int num;

    while(num =! 0){

        printf("\nDigite um DDD para consultar na lista:  \n");
        scanf("%d",&num);
        
        
        switch (num){
        case 61:
        printf("Brasilia\n");
        break;

        case 71:
        printf("Salvador\n");
        break;

        case 11:
        printf("São Paulo\n");
        break;

        case 21:
        printf("Rio de Janeiro\n");
        break;

        case 32:
        printf("Juiz de Fora\n");
        break;

        case 19:
        printf("Campinas\n");
        break;

        case 27:
        printf("Vitória\n");
        break;

        case 31:
        printf("Belo Horizonte\n");
        break;

        case 0:
        break;

        default:
        printf("Valor Inválido!\n");
        break;
    }
    }
    

}