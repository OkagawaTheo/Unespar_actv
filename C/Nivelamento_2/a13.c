#include <stdio.h>




int main(){
    float price,juros;
    int parc;


    printf("Digite o valor do carro: ");
    scanf("%f",&price);

    printf("Qual a quantidade de parcelas? \n");
    printf("Parcelas disponíveis: 12,24,48 ou 1 para à vista com desconto de 5 porcento.\n");
    scanf("%d",&parc);

    juros = price + ((parc / 2)*price)/100 ;

    if (parc == 1){
        printf("Com o desconto aplicado, o preço final ficou R$%.2f\n",price - (price*5)/100);
    }

   printf("\nO valor final do carro ficou: %.2f. Aumento de R$%.2f\n",juros,juros-price);
   printf("Serão %d parcelas de R$%.2f cada.",parc,juros/parc);

}