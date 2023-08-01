#include <stdio.h>

int main() {
    int peso;
    int g1,g2;

    printf("\nDigite o peso do saco de ração(g): ");
    scanf("%d",&peso);

    printf("Quantidade de ração dada para cada gato\n");
    
    printf("Gato 1: ");
    scanf("%d",&g1);

    printf("Gato 2: ");
    scanf("%d",&g2);

    int tot_racao = peso - (g1+g2)*3; 


    if (peso - (g1+g2) * 3 < 0){
        printf("Não terá ração para 3 dias.");
    } else{
        printf("Após 3 dias, restará %dg de ração.",tot_racao);
    }
    
    // int dias;
    // printf("Ração para quantos dias? ");
    // scanf("%i",&dias);

    // if (peso - (g1+g2) * dias < 0){
    //     printf("Não terá ração para %i dias.",dias);
    // } else{
    //     printf("Após 3 dias, restará %dg de ração.",tot_racao);
    // }

}

