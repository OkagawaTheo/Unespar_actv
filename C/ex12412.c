#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
// Funcaoo main
// Main Function
int main(int argc, char** argv)
{
 float a, b, c, x1, x2, delta;
 
 // Le os termos da equacao
 printf("Digite o valor do termo a: ");
 scanf("%f", &a);
 printf("Digite o valor do termo b: ");
 scanf("%f", &b);
 printf("Digite o valor do termo c: ");
 scanf("%f", &c);
 
 // Calcula o valor de x1
 delta = b*b - 4*a*c;
 x1 = (-b + sqrt(delta)) / (2*a);
 x2 = (-b - sqrt(delta)) / (2*a);
 
 // Imprime os resultados
 if(delta < 0) {
 printf("A equacao nao possui raizes reais.n");
 } else {
 printf("O valor de x1: %.2fn", x1);
 printf("O valor de x2: %.2fn", x2);
 }
 
 system("pause");
 return 0;
}