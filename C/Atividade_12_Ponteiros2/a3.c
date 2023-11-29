#include <stdio.h>

int main(){
    float array[10];

    printf("Digite 10 numeros: ");
    for (int i=0;i<10;i++){
        scanf("%d",&array[i]);
    }

    printf("Endereços:\n");
    
    for(int i=0;i<10;i++){
        printf("%d",&array[i]);
    }
}