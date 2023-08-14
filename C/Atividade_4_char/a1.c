#include <stdio.h>

int main(){
    char n[5][50];
     for(int i = 0; i < 5; i++){
        printf("Informe um nome: ");
        fgets(n[i],50,stdin);
        // fflush(stdin);
    }
    printf("Nomes digitados foram: \n");
    for (int i=0;i<5;i++){
        printf("%s",n[i]); //puts
    }
}