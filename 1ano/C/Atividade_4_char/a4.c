#include <stdio.h>
#include <string.h>

int main(){
    char frase[100];
    char vogais[] = {'a','e','i','o','u','\0'};

    printf("Digite a frase: ");
    fgets(frase,100,stdin);

    for (int i=0;i<strlen(frase);i++){
        for (int j=0;j<strlen(vogais);j++){
            if (frase[i] == vogais[j]){
                frase[i] = '*';
            }
        }
    }
    printf(frase);

}