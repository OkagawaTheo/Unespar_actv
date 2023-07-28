#include <stdio.h>

int main(){

    float peso,altura,m_idade;
    float idade,y,x,z;

    for (int i=0;i<2;i++){
        printf("Digite idade peso(kg) e altura(m) respectivamente: ");
        scanf("%f %f %f",&idade,&peso,&altura);
        m_idade += idade;
        

        if (peso >= 90 && altura <= 1,50){
            x += 1;
        };

        if (altura > 1,9){
            y += 1;
            if (idade >= 10 && idade <= 30){
                z += 1;
            }
        }

        

    }

printf("Em média %.2f anos\n",m_idade / 2);
printf("Existem %.2f pessoas com mais de 90 kg e menores que 1.50m\n",x);
printf("%.2f porcento de pessoas com idade entre 10 e 30 anos entre pessoas com mais de 1.90 de altura.\n",(z/y) * 100);
}