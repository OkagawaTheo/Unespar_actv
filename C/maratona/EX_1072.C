#include <stdio.h>

int main(){
    int qtd_testes, valor;
    int in=0,out=0;
    scanf("%d",&qtd_testes);
    for (int i=0;i<qtd_testes;i++){
        scanf("%d",&valor);
        if (valor >= 10 && valor <= 20) in++;
        else out++;
    }
    printf("%d in\n",in);
    printf("%d out\n",out);
}