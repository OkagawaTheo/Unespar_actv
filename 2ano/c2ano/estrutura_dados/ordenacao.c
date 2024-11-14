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
// algoritmo do por
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
// algoritmo que compara menor e maior e troca com o valor inicial
// mais lerdo
//"seleciona um valor e coloca no inicio"
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

// percorre da esqierda para a direita e colocando cala um na posição certa
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
void testarOrdenacao(FILE *arquivo, void (*sortFunc)(int[], int, int*, int*), int tam, int tipo, const char *algoritmo, const char *tipoDescricao) {
    int *vet = (int *)malloc(tam * sizeof(int));
    inicializarVetor(vet, tam, tipo);

    int comparacoes = 0, movimentacoes = 0;
    clock_t inicio = clock();
    sortFunc(vet, tam, &comparacoes, &movimentacoes);
    clock_t fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;


    fprintf(arquivo, "%-18s %-14s %-8d %-15.6f %-15d %-15d\n", 
            algoritmo, tipoDescricao, tam, tempo_execucao, comparacoes, movimentacoes);

    free(vet);
}

int main() {
    srand(time(NULL));

    int tamanhos[] = {100, 1000, 10000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    const char *tipos[] = {"Aleatorio", "Ordenado", "Inverso"};

    FILE *arquivo = fopen("resultado_ordenacao.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    }

 
    fprintf(arquivo, "======== Testes de Algoritmos de Ordenacao ========\n\n");
    fprintf(arquivo, "Algoritmo          Tamanho  Tempo (s)     Comparacoes    Movimentacoes\n");
    fprintf(arquivo, "------------------------------------------------------------\n");

    fprintf(arquivo, "\n\n===== Algoritmo: Bubble Sort =====\n\n");
    for (int i = 0; i < numTamanhos; i++) {
        int tam = tamanhos[i];
        for (int tipo = 1; tipo <= 3; tipo++) {
            fprintf(arquivo, "Tamanho: %d, Tipo de vetor: %s\n", tam, tipos[tipo - 1]);
            testarOrdenacao(arquivo, bubbleSort, tam, tipo, "Bubble Sort", tipos[tipo - 1]);
        }
    }


    fprintf(arquivo, "\n\n===== Algoritmo: Selection Sort =====\n\n");
    for (int i = 0; i < numTamanhos; i++) {
        int tam = tamanhos[i];
        for (int tipo = 1; tipo <= 3; tipo++) {
            fprintf(arquivo, "Tamanho: %d, Tipo de vetor: %s\n", tam, tipos[tipo - 1]);
            testarOrdenacao(arquivo, selectionSort, tam, tipo, "Selection Sort", tipos[tipo - 1]);
        }
    }


    fprintf(arquivo, "\n\n===== Algoritmo: Insertion Sort =====\n\n");
    for (int i = 0; i < numTamanhos; i++) {
        int tam = tamanhos[i];
        for (int tipo = 1; tipo <= 3; tipo++) {
            fprintf(arquivo, "Tamanho: %d, Tipo de vetor: %s\n", tam, tipos[tipo - 1]);
            testarOrdenacao(arquivo, insertionSort, tam, tipo, "Insertion Sort", tipos[tipo - 1]);
        }
    }

    fprintf(arquivo, "\n======== Fim dos Testes ========\n");
    fclose(arquivo);

    printf("Resultados salvos no arquivo 'resultado_ordenacao.txt'\n");
    return 0;
}
