#include <stdio.h>

int main(){
    int mat_a[2][2];
    int mat_b[2][2];
    int maior=0;

    for (int i=0;i<2;i++){ // mat_a elements
        for (int j=0;j<2;j++){
            scanf("%d",&mat_a[i][j]);
            if (mat_a[i][j] > maior) maior = mat_a[i][j]; //check higher num
        }      
    }
    for (int i=0;i<2;i++){ //multiply
        for (int j=0;j<2;j++){
            mat_a[i][j] *= maior;
        }    
    }
    
    printf("Maior número: %d\n",maior);
    printf("Nova matriz:\n");

    for (int i=0;i<2;i++){ //output
        for (int j=0;j<2;j++){
            printf("%d ",mat_a[i][j]);
        }    
        printf("\n");  
    }
}