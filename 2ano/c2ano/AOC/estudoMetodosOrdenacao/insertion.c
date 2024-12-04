#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void iniciarVetor(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % 100; 
    }
}

void insertionSort(int vet[], int tamanho) {
    int i, j, aux;
    for (i = 0; i < tamanho - 1; i++) {
        if (vet[i] > vet[i + 1]) {
            aux = vet[i + 1];
            vet[i + 1] = vet[i];
            vet[i] = aux;
            j = i - 1;
            while (j >= 0) {
                if (aux < vet[j]) {
                    vet[j + 1] = vet[j];
                    vet[j] = aux;
                } else {
                    break;
                }
                j--; 
            }
        }
    }
}

void bubbleSort(int vet[],int tamanho){
    int i,aux,flag=1;

    while(flag){
        flag=0;
        for(i=0;i<tamanho-1;i++){
            if (vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                flag=1;

            }
        }
    }

}


void SelectionSort(int vet[], int tamanho){
    int i,j,aux;
    for (i=0;i<tamanho;i++){
        int menor = i; 
        for (j=i+1;j<tamanho;j++){
            if (vet[j] < vet[menor]){
                menor = j;
            }   
        }
        aux = vet[i];
        vet[i] = vet[menor]; 
        vet[menor] = aux;
    }
}


void main() {
    srand(time(NULL));
    int vetorInsertion[10];
    int vetorBubble[10];
    int VetorSelection[10];

    //InsertionSort
    iniciarVetor(vetorInsertion, 10);
    printf("Vetor original: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetorInsertion[i]);
    }
    printf("\n");

    insertionSort(vetorInsertion, 10);
    printf("Vetor ordenado (Insertion Sort): ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetorInsertion[i]);
    }
    printf("\n");

    //bubblesort
    iniciarVetor(vetorBubble,10);
    printf("\nVetor original:");
    for(int i=0;i<10;i++){
        printf("%d ",vetorBubble[i]);
    }

    printf("\nVetor ordenado(BubbleSort):");
    bubbleSort(vetorBubble,10);

    for(int i=0;i<10;i++){
        printf("%d ",vetorBubble[i]);
    }

    //Selection
    iniciarVetor(VetorSelection,10);
    printf("\n\nVetor original: ");
    for(int i=0;i<10;i++){
        printf("%d ",VetorSelection[i]);
    }
    printf("\nVetor Ordenado (Selection): \n");
    SelectionSort(VetorSelection,10);
    for(int i=0;i<10;i++){
        printf("%d ",VetorSelection[i]);
    }
}
