#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho;
    printf("Insira o tamanho dos dois arrays: ");
    scanf("%d",&tamanho);
    
    int* arr1 = malloc(tamanho*sizeof(int));
    int* arr2 = malloc(tamanho*sizeof(int));
    int* somaArr = malloc(tamanho*sizeof(int));

    for (int i=0;i<tamanho;i++){
        printf("%dº Elemento arr1: : ",i+1);
        scanf("%d",&arr1[i]);
        printf("%dº Elemento arr2: ",i+1);
        scanf("%d",&arr2[i]);
    }
    
    for (int i=0;i<tamanho;i++){
        somaArr[i] = arr1[i] + arr2[i];
    }

    for (int i=0;i<tamanho;i++){
        printf("%d + %d = %d\n",arr1[i],arr2[i],somaArr[i]);
    }


}