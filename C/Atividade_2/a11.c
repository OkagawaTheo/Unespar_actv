#include <stdio.h>

int main(){

printf("Números entre 1000 e 2000 divisíveis por 7: ");
for (int i=1000;i<2001;i++){
    if (i % 7 == 0){
        printf("%d\n",i);
    }
}


}