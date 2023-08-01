#include <stdio.h>

int main(){
    int valor_show,ingresso;

    printf("Digite o valor do show: ");
    scanf("%d",&valor_show);
    
    printf("Digite o valor de cada ingresso: ");
    scanf("%d",&ingresso);

    printf("Para o show ser pago, precisa-se vender ao menos %d ingressos. ",valor_show/ingresso);

}