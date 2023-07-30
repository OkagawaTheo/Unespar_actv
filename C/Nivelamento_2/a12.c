#include <stdio.h>

int main(){

    float peso,m_idade;
    float x,count;
    int idade, altura;

    for (int i=0;i<10;i++){
        printf("Digite idade peso(kg) e altura(cm) respectivamente: ");
        scanf("%d %f %d",&idade,&peso,&altura);

        m_idade += idade;
        
        if (peso >= 90 && altura <= 150){
            x += 1;
        };

        if (altura >= 190){
            if (idade >= 10 && idade <= 30){
                count += 1;
            }
            
        }

    }

printf("Em média %.2f anos\n",m_idade / 2);
printf("Existem %.2f pessoas com mais de 90 kg e menores que 1.50m\n",x);
printf("%.2f porcento de pessoas com idade entre 10 e 30 anos entre pessoas com mais de 1.90 de altura.\n",(count/10)*100);
}