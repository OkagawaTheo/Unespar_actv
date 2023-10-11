// #include <stdio.h>

// int main(){
//     FILE* arq;
//     char nome[30];

//     arq = fopen("myname.txt","w");

//     if(arq==NULL){
//         printf("Error");
//     }
//     printf("Digite um nome: ");
//     scanf("%s",nome);

//     fputs("meu nome é ",arq);
//     fputs(nome,arq);
//     fclose(arq);
// }




#include <stdio.h>

int main(){
    FILE* arquivo;
    char c;
    arquivo = fopen("arq.txt","w");

    while (1){ //true
        scanf(" %c",&c);
        if (c == '0'){
            break;
        }
        fputc(c,arquivo);
    }
    fclose(arquivo);

    arquivo = fopen("arq.txt","r");
    printf("Conteúdo do arquivo: ");

    while ((c = fgetc(arquivo)) != EOF){
        printf("%c",c);
    }


}