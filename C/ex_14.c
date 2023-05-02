#include <stdio.h>
#include <math.h>

int main(){
    float x1,x2,x3,a,b,c,delta;
    
    printf("Digite o valor de a: ");
    scanf("%f",&a);

    printf("Digite o valor de b: ");
    scanf("%f",&b);

    printf("Digite o valor de c: ");
    scanf("%f",&c);


    delta = (pow(b,2)) - (4*a*c);
    x1 = ( (-b) + (sqrt(delta)) ) / (2*a);
	x2 = ( (-b) - (sqrt(delta)) ) / (2*a);


    if (delta > 0){
        printf("x1 = %.2f\nx2 = %.2f",x1,x2);
    }
    else if (delta == 0){
        x3 = ((-b) / (2*a));
        printf("A única raiz possivel e: %.2f",x3);
    }
    else{
        printf("\nNão é possivel calcular.");
    }
    
}