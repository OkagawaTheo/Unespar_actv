#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *proximo;
}No;
struct No *topo = NULL;

void push(int item){
    printf("\nEmpilhando %d:\n",item);
    struct No *novo = malloc(sizeof(No));

    if (novo == NULL){
        printf("Erro de alocação de memória.\n");
        return;
    }
    novo->dado = item; // item é o numero novo a ser alocado
    novo->proximo = topo;
    topo = novo;
}

void imprimir(){
    if (topo == NULL){
        printf("Lista vazia.");
    }
    No *atual = topo;
    printf("\nElementos da pilha:\n");
    while (atual != NULL){
        printf("%d\n",atual->dado);
        atual = atual->proximo;
    }
}

int main(){
    int opcao,numero;
    
    do{
        printf("Menu: \n1.Empilhar\n2.Remover\n3.Imprimir");
        printf("\nEscolha uma opção [0-3]: ");
        scanf("%d",&opcao);
        
        switch (opcao){
            case 1:
                printf("\nEntre com um valor para ser empilhado: ");
                scanf("%d",&numero);
                push(numero);
                break;

            case 3:
                imprimir();
                break;
            default:
                if (opcao != 0) printf("Opção inválida.");
        }
    }while (opcao != 0);
    
}