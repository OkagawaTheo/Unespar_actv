#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIZ_X 1000
#define MATRIZ_Y 1000
// define valores para x e y da matriz

double benchmark(){
    double soma = 0;
    double mat[MATRIZ_X][MATRIZ_Y];

    srand(time(NULL)); // seed para gerar os números aleatórios

    // for para preencher matriz com numeros aleatorios
    for (int i=0;i<MATRIZ_X;i++){
        for (int j=0;j<MATRIZ_Y;j++){
            mat[i][j] = rand() / (double)RAND_MAX;
        }
    }

    clock_t start = clock(); //começa a contagem de tempo

    // for que faz os calculos de soma
    for (int i=0;i<MATRIZ_X;i++){
        for (int j=0;j<MATRIZ_Y;j++){ 
            soma += mat[i][j];
            mat[i] = soma;
            mat[j]= mat[i] + soma;
        }
    }
    clock_t end = clock(); //termina a contagem de tempo

    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0; //retorna o valor em milisegundos
}


int main(){
    double tempo = benchmark();
    double tempo_segundos = tempo / 1000.0; // divide novamente o valor o tempo para obter em segundos
    printf("Tempo em milisegundos: %.2f \n",tempo);
    printf("Tempo em segundos: %.6f\n",tempo_segundos);
}