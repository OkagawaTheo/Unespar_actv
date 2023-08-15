#include <stdio.h>
#include <string.h>

int main(){
    char vogais[] = {'a','e','i','o','u','\0'};
    char frase[100];
    int count=0;

    printf("Digite uma frase: ");
    gets(frase);

    for (int i=0;i<strlen(frase);i++){
        for (int j=0;j<strlen(vogais);j++){
            if (frase[i] == vogais[j]){
                count++;
            }
        }
    }
    printf("Número de vogais: %d",count);
}