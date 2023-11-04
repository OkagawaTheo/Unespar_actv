#include <stdio.h>

int main(){

    FILE* arq1 = fopen("arq1.txt","w");
    FILE* arq2 = fopen("arq2.txt","w");
    char txt1[100],txt2[100],caracter1,caracter2;

    printf("O que deseja escrever no primeiro arquivo? ");
    fgets(txt1,sizeof(txt1),stdin);
    printf("E no segundo? ");
    fgets(txt2,sizeof(txt2),stdin);
    fprintf(arq1,txt1);
    fprintf(arq2,txt2);
    fclose(arq1);
    fclose(arq2);

    FILE* arq3 = fopen("arq3.txt","w");
    fprintf(arq3,txt1);
    fprintf(arq3,txt2);

}