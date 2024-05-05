#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIZ_X 1000
#define MATRIZ_Y 1000


double benchmark(){
    double soma = 0;
    double mat[MATRIZ_X][MATRIZ_Y];

    srand(time(NULL));

    for (int i=0;i<MATRIZ_X;i++){
        for (int j=0;j<MATRIZ_Y;j++){
            mat[i][j] = rand() / (double)RAND_MAX;
        }
    }

    clock_t start = clock();
    for (int i=0;i<MATRIZ_X;i++){
        for (int j=0;j<MATRIZ_Y;j++){
            soma += mat[i][j];
        }
    }
    clock_t end = clock();

    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0; //milisegundos
    
}


int main(){
    double tempo = benchmark();
    double tempo_segundos = tempo / 1000.0;
    printf("Tempo em milisegundos: %.2f \n",tempo);
    printf("Tempo em segundos: %.6f\n",tempo_segundos);

}