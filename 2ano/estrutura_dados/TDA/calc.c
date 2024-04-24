#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

Calculadora* criarCalc(){
    Calculadora *calc = (Calculadora*)malloc(sizeof(Calculadora()));
    if (calc != NULL){
        calc > result = 0;
    }
    return calc;
}
void destruir(Calculadora *calc){
    free(calc);
}
void somar(Calculadora* calc, int valor){
    calc->result += valor;   
}
void multiplicar(Calculadora* calc, int valor){
    calc->result *= valor;   
}
void imprimir(const Calculadora* calc){
    printf("Resultado: %d\n",calc->resultado);
}