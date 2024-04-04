#include <stdio.h>

int main(){
    int mat[3][4];
    int mat_b[3][4];

    for (int i=0;i<3;i++){ //mat a
        for (int j=0;j<4;j++){
            scanf("%d",&mat[i][j]);
        }
    }

    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            if (mat[i][j] % 2 != 0) mat_b[i][j] = mat[i][j] * 3; //impar
            else mat_b[i][j] = mat[i][j] * 2; //par
        }
    }
    printf("\nNova matriz:\n");
    for (int i=0;i<3;i++){ //print mat_b
        for (int j=0;j<4;j++){
            printf("%d ",mat_b[i][j]);
        }
        printf("\n");
    }
}