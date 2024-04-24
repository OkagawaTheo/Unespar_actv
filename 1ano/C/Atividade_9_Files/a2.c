#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char nomeArquivo[100];
    char c;
    int numVogais = 0;

    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo,sizeof(nomeArquivo),stdin);

    FILE* arq = fopen(nomeArquivo,"r");
    
    if (arq == NULL){
        printf("\nErro ao abrir/criar arquivo.");
    }

    while ((c = fgetc(arq)) != EOF){
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            numVogais++;
        }
    }

    fclose(arq);
    printf("O arquivo possui %d vogaisn\n",numVogais);
}