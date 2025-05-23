#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um vetor com valores baseados no tipo escolhido
void inicializarVetor(int vet[], int tam, int tipo) {
    for (int i = 0; i < tam; i++) {
        if (tipo == 1) vet[i] = rand() % 10000;          // Valores aleatórios
        else if (tipo == 2) vet[i] = i;                  // Valores em ordem crescente
        else vet[i] = tam - i - 1;                       // Valores em ordem decrescente
    }
}

void bubbleSort(int vet[], int tam, int *comparacoes, int *movimentacoes) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            (*comparacoes)++;
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                (*movimentacoes)++;
            }
        }
    }
}

void selectionSort(int vet[], int tam, int *comparacoes, int *movimentacoes) {
    for (int i = 0; i < tam - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tam; j++) {
            (*comparacoes)++;
            if (vet[j] < vet[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = vet[min_idx];
            vet[min_idx] = vet[i];
            vet[i] = temp;
            (*movimentacoes)++;
        }
    }
}

// Função Insertion Sort
void insertionSort(int vet[], int tam, int *comparacoes, int *movimentacoes) {
    for (int i = 1; i < tam; i++) {
        int chave = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            j--;
            (*movimentacoes)++;
            (*comparacoes)++;
        }
        vet[j + 1] = chave;
        (*movimentacoes)++;
    }
}

// Função para medir e exibir o desempenho de cada algoritmo de ordenação
void testarOrdenacao(void (*sortFunc)(int[], int, int*, int*), int tam, int tipo, const char *algoritmo, const char *tipoDescricao) {
    int *vet = (int *)malloc(tam * sizeof(int));
    inicializarVetor(vet, tam, tipo);

    int comparacoes = 0, movimentacoes = 0;
    clock_t inicio = clock();
    sortFunc(vet, tam, &comparacoes, &movimentacoes);
    clock_t fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\n=============================================\n");
    printf("Algoritmo: %s\nTipo de vetor: %s\n", algoritmo, tipoDescricao);
    printf("Tamanho do vetor: %d\n", tam);
    printf("---------------------------------------------\n");
    printf("Tempo de execucao: %.6f segundos\n", tempo_execucao);
    printf("Numero de comparacoes: %d\n", comparacoes);
    printf("Numero de movimentacoes: %d\n", movimentacoes);
    printf("=============================================\n\n");

    free(vet);
}

int main() {
    srand(time(NULL));

    int tamanhos[] = {100, 1000, 10000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    const char *tipos[] = {"Aleatorio", "Ordenado", "Inverso"};

    printf("======== Testes de Algoritmos de Ordenacao ========\n\n");

    for (int i = 0; i < numTamanhos; i++) {
        int tam = tamanhos[i];
        for (int tipo = 1; tipo <= 3; tipo++) {
            printf("---------------\n");
            printf("Tamanho: %d, Tipo de vetor: %s\n\n", tam, tipos[tipo - 1]);
            
            testarOrdenacao(bubbleSort, tam, tipo, "Bubble Sort", tipos[tipo - 1]);
            testarOrdenacao(selectionSort, tam, tipo, "Selection Sort", tipos[tipo - 1]);
            testarOrdenacao(insertionSort, tam, tipo, "Insertion Sort", tipos[tipo - 1]);
            
            printf("===============\n\n");
        }
    }
}