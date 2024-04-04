#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    FILE* entrada;
    FILE* saida;
    char texto[100];
    char caracter;

    entrada = fopen("entrada.txt","w");
    printf("Digite o que quiser no arquivo: ");
    fgets(texto,sizeof(texto),stdin);
    fprintf(entrada,texto);   
    
    saida = fopen("saida.txt","w");
    fclose(entrada);
    entrada = fopen("entrada.txt","r");

    while ((caracter = fgetc(entrada)) != EOF){
        if (isalpha(caracter) && strchr("AEIOUaeiou",caracter)){
            fputc('*',saida);
        }
        else {
            fputc(caracter,saida);
        }
    }
}