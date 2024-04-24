#include <stdio.h>

int main(){
    float salario,perc;

    printf("Digite o salário do funcionário: ");
    scanf("%f",&salario);

    printf("Porcentagem de aumento: ");
    scanf("%f",&perc);

    perc = salario * (perc / 100);

    printf("O novo salário é R$%.2f e seu respectivo aumento foi de R$%.2f\n",salario+perc,perc);

}