#include <stdio.h>
#include <string.h>

int main(){
    char palavra[100];
    fgets(palavra,100,stdin);

    char l = strlen(palavra);
    char rev[100];
    int count=0;

    for (int i=0;i<l;i++){
        rev[i] = palavra[l-1-i];
        if (rev[i] = palavra[i]){
            count++;
        }
    }

    if (count > 0) printf("\nPalíndromo!");
    else printf("\nNão é um palíndromo.");

    // // printf("frase normal: %s\n",palavra);
    // printf("frase reversa: %s",rev);

}