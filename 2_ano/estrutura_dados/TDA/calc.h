#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

typedef struct{
    int result;
}Calculadora;

Calculadora *criarCalc();

void destruir(Calculadora* calculadora);
void somar(Calculadora* calculadora,int valor);
void subtrair(Calculadora* calculadora, int valor);
void multiplicar(Calculadora* calculadora, int valor);
void imprimir(const Calculadora* calculadora);
#endif
