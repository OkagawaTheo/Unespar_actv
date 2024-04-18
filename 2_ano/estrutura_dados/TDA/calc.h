#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

typedef struct{
    int result;
}Calc;

Calc *criarCalc();

void destruir(Calc* calculadora);
void soma(Calc* calculadora,int valor);
void subtrair(Calc* calculadora, int valor);
void multiplicar(Calc* calculadora, int valor);
void imprimir(const Calc* calculadora);
#endif
