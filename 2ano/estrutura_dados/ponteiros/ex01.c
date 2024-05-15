#include <stdio.h>

int main(){
    int valor = 29;
    int *ptr;
    ptr = &valor;
    printf("conteudo da variavel %d\n",valor);
    printf("endereço da variavel %x\n",&valor);
    printf("Conteudo da variavel ponteiro %x\n",ptr);
}