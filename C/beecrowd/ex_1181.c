#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int mat[12][12];
    srand(time(NULL));
    

    for (int i=0;i<12;i++){
        for (int j=0;j<12;j++){
            mat[i][j] = rand()%20;
            
        }
    }

    for (int i=0;i<12;i++){
        for (int j=0;j<12;j++){
            printf("%d\t",mat[i][j]);
            
        }
    }
}