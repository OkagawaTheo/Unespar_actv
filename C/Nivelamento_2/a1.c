#include <stdio.h>

int main(){
    float n1,n2,n3;
    float p1,p2,p3;

    printf("\nDigite as 3 notas: ");
    scanf("%f %f %f",&n1,&n2,&n3);

    printf("Digite os respectivos pesos: ");
    scanf("%f %f %f",&p1,&p2,&p3);

    float mp = ((n1*p2 + n2*p2 + n3*p3) / (p1+p2+p3));
    printf("A média do aluno é: %.2f\n",mp);
}