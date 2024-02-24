#include <stdio.h>
#include <stdbool.h>

int main(){

    int tentativa;

    while (true){
        scanf("%d",&tentativa);
        if (tentativa != 2002){
            printf("Senha Invalida\n");
        }
        else{
            printf("Acesso Permitido\n");
            break;
        };
    }
}