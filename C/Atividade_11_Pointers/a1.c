#include <stdio.h>

int main(){
    int inteiro = 5;
    float real = 10;
    char c = 'a';


    printf("Valores antes da modificação: \n");
    printf("%d\n %.2f \n%c\n",inteiro,real,c);

    int *pont_inteiro = &inteiro;
    float *pont_float = &real;
    char *pont_char = &c;
    *pont_inteiro = 10;
    *pont_float = 20.20;
    *pont_char = 'b';
    
    printf("Valores após modificação: \n");
    printf("%d\n %.2f\n %c\n",inteiro,real,c);
}