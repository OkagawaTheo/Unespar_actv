#include <stdio.h>

int main(){
    int vet[20];
    int mat[3][6];
    int a=0;

    printf("Digite os valores: ");

    for (int i=0;i<18;i++){
        scanf("%d",&vet[i]);
    }
    
    for (int i=0;i<3;i++){
        for (int j=0;j<6;j++){
            mat[i][j] = vet[a];
            a++;

            printf("%d ",mat[i][j]);

        }
    printf("\n");
    }
}