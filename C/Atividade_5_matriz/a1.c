#include <stdio.h>

int main(){
    int mat[3][3];
    int maior=0;

    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            scanf("%d",&mat[i][j]); //scanf com espaço pede mais um numero
            if (mat[i][j] > maior) maior=mat[i][j];
        }
    }

    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\nO maior número digitado foi: %d",maior);
}