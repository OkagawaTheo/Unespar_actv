#include <stdio.h>

int main(){
    int a = 10; // declara a como 10
    int b = 20; // declara b como 20
    int *p, *q; // inicia dois ponteiros
    p = &a; // p recebe o endereço de a
    q = &b; // b recebe endereço de b

    *p = 30; //altera a variavel a pelo endereço da p
    *q = 40;//altera a variavel b pelo endereço da q

    printf("%p %d\n",a,a); //printa endereço e valor da variavel a;
}