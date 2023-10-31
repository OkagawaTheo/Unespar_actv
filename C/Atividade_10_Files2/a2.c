#include <stdio.h>

int main(){
    FILE* arq;
    char texto[100];
    char vogais[] = {'a','e','i','o','u','\0'};

    if ((arq = fopen("arq1.txt","w")) == NULL){
        printf("error");
    }
    
    printf("Digite o que deseja inserir no arquivo: ");
    fgets(texto,sizeof(texto),stdin);
    fprintf(arq,texto);
    fclose(arq);

    FILE* arq_saida = fopen("saida.txt","w");
    fprintf(arq_saida,texto);
    rewind(arq_saida);
    fclose(arq_saida);

    arq = fopen("saida.txt","r");
}