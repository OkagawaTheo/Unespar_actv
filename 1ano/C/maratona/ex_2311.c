#include <stdio.h>

int main(){
    int num_competidores;
    float grau_dificuldade;
    char nome[30];
    float array_notas[7];
    float nota;
    float maior=0.0,menor=0.0;

    scanf("%d",&num_competidores);
    for (int i=0;i<num_competidores;i++){
        scanf("%s",&nome);
        scanf("%f",&grau_dificuldade);
        printf("--\n");

        for (int j=0;j<7;j++){
            printf("Nota-%d ",j+1);
            scanf("%f",&nota);
            array_nomenor = notas[j] = nota;
            if (nota > maior) maior = nota;
            int temp = 10;
            if (nota < temp){
                temp = nota;
                menor = nota;
            };
            
        }
        
        printf("%f\n",maior);
        printf("%f\n",menor);
    }
}
