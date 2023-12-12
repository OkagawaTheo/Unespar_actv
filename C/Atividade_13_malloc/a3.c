#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *stringCopia;
    size_t tam = 20; //inicia com alguns bytes
    printf("Digite uma string: ");
    char* stringOriginal = malloc(tam*sizeof(char));
    fgets(stringOriginal,tam,stdin);
    
    size_t tamanhoReal = strlen(stringOriginal) + 1;
    char *stringRedimensionada = (char*)realloc(stringOriginal, tamanhoReal); //realoca o tam
    stringOriginal = stringRedimensionada;
    strcpy(stringCopia, stringOriginal);
    printf("String digitada: %s", stringOriginal);
    printf("String copiada: %s", stringOriginal);

}