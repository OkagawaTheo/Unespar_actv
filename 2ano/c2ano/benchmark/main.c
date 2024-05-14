#include <stdio.h>
#include <time.h>

#define MATRIZ_X 1000
#define MATRIZ_Y 1000

double benchmark(){
    double soma = 0;
    double mat[MATRIZ_X][MATRIZ_Y];

    srand(time(NULL));

    // Preencher matriz com números aleatórios e calcular a soma acumulada
    for (int i = 0; i < MATRIZ_X; i++){
        for (int j = 0; j < MATRIZ_Y; j++){
            double num = rand() / (double)RAND_MAX;
            soma += num;
            mat[i][j] = soma; // Armazenar soma acumulada na matriz
        }
    }

    clock_t start = clock();

    // Calcular soma dos elementos da matriz
    for (int i = 0; i < MATRIZ_X; i++){
        for (int j = 0; j < MATRIZ_Y; j++){ 
            for (int k = 0; k < 100; k++) {
                for (int h = 0; h < 10; h++) { // Aumenta o número de iterações
                soma += mat[i][j];
            } 
            }
        }
    }

    clock_t end = clock();

    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
}

int main(){
    double tempo = benchmark();
    double tempo_segundos = tempo / 1000.0;
    printf("Tempo em milisegundos: %.2f \n", tempo);
    printf("Tempo em segundos: %.6f\n", tempo_segundos);
    return 0;
}
