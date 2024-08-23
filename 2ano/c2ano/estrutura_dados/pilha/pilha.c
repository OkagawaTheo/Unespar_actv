#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    int dado;
    struct no *proximo;
}no;

int main(){
    int opcao;
    print("Digite uma opção: [1-Empilhar 2-Remover 3- sair]");
    scanf("%d",&opcao);

    do{
        switch (opcao){
            case 1:
                empilhar();
                break;
                
            case 2:
                remover();
                break;

            case 3:
                break;

            default:
                print("opção invalida");
        
        }
    } while(opcao != 0);

}