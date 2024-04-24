#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    typedef struct Dados{
        double salario;
        int idade;
        char sexo;
        int num_filhos;
    }Dados;

int main(){ 
    int qtd,i=0;
    double cont_salario_inferior=0.0;
    double menor_idade = 0.0,total_salario = 0.0,total_numFilhos=0.0, maior_salario=0.0;


    printf("Quantos usuários deseja cadastrar? ");
    scanf("%d",&qtd);
    Dados d[qtd];

    while (i != qtd){
        printf("\nDigite o salário: ");
        scanf("%lf",&d[i].salario);
        total_salario += d[i].salario;
        maior_salario = d[i].salario;
        if (maior_salario < d[i].salario){
            maior_salario = d[i].salario;
        }

        printf("\nIdade: ");
        scanf("%d",&d[i].idade);
        menor_idade = d[i].idade;
        if (menor_idade > d[i].idade){
            menor_idade = d[i].idade;
        }

        if (d[i].idade == 0) break;

        printf("\nSexo: ");
        scanf("%s",&d[i].sexo);

        printf("\nNº de filhos: ");
        scanf("%d",&d[i].num_filhos);
        total_numFilhos += d[i].num_filhos;

        if (d[i].salario < 300 && d[i].sexo == 'f') cont_salario_inferior++;
        i++;
    }

    printf("\nMédia de mulheres com salário menor de 300 reais: %lf \n",cont_salario_inferior/i);
    printf("Média de salário da população: %.2lf\n",total_salario/i);
    printf("Média de número de filhos: %.2lf\n",total_numFilhos/i);
    printf("Maior salário: %.2lf\n",maior_salario);
    printf("Menor idade: %.2lf\n",menor_idade);

}


