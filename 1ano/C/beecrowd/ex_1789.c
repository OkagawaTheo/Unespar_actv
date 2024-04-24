#include <stdio.h>

int main(){
    int qtd_testes;
    int velocidade;
    int maior = 0;
    
    while((scanf("%d",&qtd_testes) != EOF)){
        for(int i=0;i<qtd_testes;i++){
            scanf("%d",&velocidade);
            if (velocidade > maior) maior = velocidade;
            
        }
        printf("%d\n",maior);
        maior = 0;
    }
}
    