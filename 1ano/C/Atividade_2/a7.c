#include <stdio.h> 

int main(){
    float n1,n2,n3,m;

    printf("\nDigite as três notas do aluno: ");
    scanf("%f %f %f",&n1,&n2,&n3);

    m = (n1+n2+n3) / 3;
    printf("Média: %f\n",m);


    if (m > 0 && m <= 2.9){
        printf("Reprovado.");
    } else if (m >= 3 && m <= 6.9){
        printf("Em recuperação. Para ficar na média, precisa tirar pelo menos %.2f na recuperação",(7.0 - m));
    } else{
        printf("Aprovado.");
    }
}