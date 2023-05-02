#include <stdio.h>
#include <math.h>

int main(){
    float ct1,ct2,hip;

    printf("\nDigite o valor do primeiro cateto: ");
    scanf("%f",&ct1);

    printf("\nDigite o valor do segundo cateto: ");
    scanf("%f",&ct2);

    
    hip = sqrt((pow(ct1,2)) + (pow(ct2,2)));

    printf("\nHipotenusa = %.2f\n",hip);


}