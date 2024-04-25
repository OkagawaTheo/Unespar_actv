#include <stdio.h>
#include "retan.h"

int main(){
    Retangulo meuRetangulo = criarRetangulo(5.0,3.0);
    
    float area = calcularArea(meuRetangulo);
    printf("A area do retangulo é %.2f\n",area);
}z