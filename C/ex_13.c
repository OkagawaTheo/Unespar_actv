#include <stdio.h>

int main(){
    int salario;

    printf("Digite o salário para mostrar o reajuste: ");
    scanf("%d",&salario);
    
    if (salario > 0 && salario <= 400){
        salario = salario + (salario*15)/100;
    } 
    else if (salario > 400 && salario <= 800){
        salario = salario + (salario*12)/100;
    }
    else if (salario > 800 && salario <=1200){
        salario = salario + (10*10)/100;
    }
    else if (salario > 1200 && salario <=2000){
        salario = salario + (salario*7)/100;
    }
    else{
        salario = salario + (salario*4)/100;
    }
    printf("\no salário com o reajuste ficou R$%d\n",salario);

}