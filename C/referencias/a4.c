#include <stdio.h>

void changeVet(int vet[25]){
    for (int i=0;i<3;i++){
        if (vet[i] < 0){
            vet[i] = 0;
        }
    }
}

int main(){
    int vet[25];
    printf("Digite os valores: ");
    for (int i=0;i<25;i++){
        scanf("%d",&vet[i]);
    }
    changeVet(vet);
    
    for (int i=0;i<25;i++){
        printf("%d ",vet[i]);
    }
}