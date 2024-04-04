#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int createVet(int vet[]){
    int num;
    printf("Criando um vetor de 10 posições aleatoriamente...");

    for (int i=0;i<10;i++){
        vet[i] = rand()% 100;
    }
    
    printf("\n\nDigite um número entre 0 e 100: ");
    scanf("%d",&num);

    return num;
}

bool checkNum(int vet[],int num){
    bool flag = false;

    for (int i=0;i<10;i++){
        if (num == vet[i]){
            flag = true;
        }
    }
    return flag;
}

int main(){
    int vet[10],num;
    bool flag;
    
    srand(time(NULL));

    num = createVet(vet);
    flag = checkNum(vet,num);
    
    if (flag == true){
        printf("Seu número está no vetor!");
    }
    else printf("Seu número nao está no vetor.");

    }
