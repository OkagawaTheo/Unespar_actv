#include <stdio.h>

int main(){
    int valores[9];
    for (int i=0;i<9;i++){
        scanf("%d",&valores[i]);
    }
    
    for (int i=0;i<9;i++){
        if (valores[i] % 2 == 0){
            printf("valor: %d\n",valores[i]);
            printf("ìndice: %d\n",i);
            
        }
    }
}