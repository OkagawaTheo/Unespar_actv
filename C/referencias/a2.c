#include <stdio.h>

void acres(float preço_antigo,float preço_novo,float *acrescimo){
    *acrescimo = ((preço_novo - preço_antigo)/preço_antigo) *100;
}

int main(){
    float preço_antigo,preço_novo,acrescimo;

    printf("Preço antigo do produto: ");
    scanf("%f",&preço_antigo);

    printf("Preço atual: ");
    scanf("%f",&preço_novo);

    acres(preço_antigo,preço_novo,&acrescimo);

    printf("Percentual de acrescimo: %%%.2f",acrescimo);
}