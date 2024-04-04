#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int v[6];
    int pares[6];
    int imp[6];

    int par=0,impar = 0;
    srand(time(NULL));

    for (int i=0;i<6;i++){
        v[i] = rand() % 5+1;

        if (v[i] % 2 == 0){ // pegar pares
            pares[i] = v[i];
            par++;
        } 
        else{
            imp[i] = v[i];
            impar++;
        }
    }
    
    printf("Quantidade de valores pares: %d\n",par);
    printf("Todos os números pares: ");
    for (int i=0;i<6;i++){
        if (pares[i] != 0){
            printf("%d ",pares[i]);
        }

    }
    
    printf("\nQuantidade de valores ímpares: %d\n",impar);
    printf("Todos os números ímpares: ");
    for (int i=0;i<6;i++){
        if (imp[i] != 0){
            printf("%d ",imp[i]);
        }
    }
}