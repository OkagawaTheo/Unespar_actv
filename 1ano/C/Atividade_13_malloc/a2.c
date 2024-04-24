#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtd_notas;
    
    printf("Quantas notas deseja calcular? ");
    scanf("%d",&qtd_notas);

    float* notas = malloc(qtd_notas*sizeof(float));

    for(int i=0;i<qtd_notas;i++){
        printf("%dº nota: ",i+1);
        scanf("%f",&notas[i]);
    }
    float soma = 0.0;
    for (int i=0;i<qtd_notas;i++){
        soma += notas[i];
    }
    float media = soma/qtd_notas;

    printf("Média das %d notas: %.2f",qtd_notas,media);
}