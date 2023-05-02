#include <stdio.h>

int main(){

    float n1,n2;
    int freq;

    printf("Digite as duas notas do aluno:\n");
    scanf("%f %f",&n1,&n2);
    
    printf("\nDigite o percentual de frequência do aluno (0-100): ");
    scanf("%d",&freq);

    if ((n1 + n2) > 7 && freq >= 75){
        printf("\nAluno aprovado com a média de %.2f\n",(n1 + n2)/2);
    } else{
        printf("\nAluno reprovado com a média de %2.f\n",(n1 + n2) / 2);
    }
}