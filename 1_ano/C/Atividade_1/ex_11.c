#include <stdio.h>

int main(){

    int num;


    printf("\nDigite a idade do nadador e darei a classificação correspondente: ");
    scanf("%d",&num);


    if (num >= 5 && num <= 7 ){
        printf("\nInfantil A\n");
    } 
    else if (num >= 8 && num <= 10) {
        printf("\nInfantil B\n");

    }
    else if (num >= 11 && num <= 13) {
        printf("\nJuvenil A\n");

    }
    else if (num >= 14 && num <= 17) {
        printf("\nJuvenil B\n");

    } else{
        printf("Sênior");
    }


}