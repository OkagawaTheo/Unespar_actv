#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila
typedef struct No {
    int dado;
    struct No *proximo;
} No;

// Ponteiros para o início e fim da fila, inicialmente nulos
No *inicio = NULL;
No *fim = NULL;

// Função para inserir um elemento na fila
void enqueue(int item) {
    No *novo = (No *)malloc(sizeof(No)); // Aloca memória para o novo nó
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }
    novo->dado = item;    // Define o dado do novo nó
    novo->proximo = NULL; // O novo nó será o último, então seu próximo é NULL

    if (fim == NULL) { // Se a fila estiver vazia, o novo nó é tanto o início quanto o fim
        inicio = novo;
        fim = novo;
    } else {
        fim->proximo = novo; // O último nó atualiza seu próximo para o novo nó
        fim = novo;          // Atualiza o ponteiro fim para o novo nó
    }
    printf("Inserido: %d\n", item);
}

// Função para remover um elemento da fila
int dequeue() {
    if (inicio == NULL) {
        printf("A fila está vazia.\n");
        return -1; // Retorna -1 para indicar que a fila está vazia
    }

    No *temp = inicio;   // Salva o ponteiro para o nó a ser removido
    int item = temp->dado; // Salva o dado do nó a ser removido
    inicio = inicio->proximo; // Atualiza o início para o próximo nó

    if (inicio == NULL) { // Se a fila ficar vazia, atualiza o fim para NULL também
        fim = NULL;
    }

    free(temp); // Libera a memória do nó removido
    printf("Removido: %d\n", item);
    return item;
}

// Função para imprimir todos os elementos da fila
void imprimir() {
    if (inicio == NULL) {
        printf("A fila está vazia.\n");
        return;
    }

    No *atual = inicio;
    printf("Elementos da fila:\n");
    while (atual != NULL) {
        printf("%d\n", atual->dado); // Imprime o dado do nó atual
        atual = atual->proximo;      // Move para o próximo nó
    }
}

// Função principal
int main() {
    int opcao, numero;

    do {
        printf("Menu:\n 1. Inserir\n 2. Remover\n 3. Imprimir\n 0. Sair\n");
        printf("Escolha uma opção [0-3]: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Entre com um valor para ser inserido: ");
                scanf("%d", &numero);
                enqueue(numero);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                imprimir();
                break;

            default:
                if(opcao != 0) printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
