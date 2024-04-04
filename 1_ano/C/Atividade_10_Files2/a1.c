#include <stdio.h>

typedef struct Texto{
    char nome[100];
    char texto[100];
}Texto;


int main(){
    char nomeArq[100];
    FILE* arq;
    Texto txt;

    printf("\nDigite o nome do seu arquivo: ");
    fgets(txt.nome, sizeof(txt.nome),stdin);
    snprintf(nomeArq,sizeof(nomeArq),"%s.txt",txt.nome);
    printf("%s",nomeArq);
    
    if (( arq = fopen(nomeArq, "w")) == NULL){
        printf("\nNao consigo abrir o arquivo ! ");
    }
    
    printf("O que deseja inserir dentro do arquivo? ");
    fgets(txt.texto,sizeof(txt.texto),stdin);
    fprintf(arq,txt.texto);
}