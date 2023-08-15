#include <stdio.h>
#include <string.h>

int main(){
    char musica[50];
    int oc[20];
    char letra;
    int q = 0;
    int num = 0;

    printf("Informe o nome de uma musica: ");
    fgets(musica,50,stdin);

    printf("Informe uma letra: ");
    scanf("%c", &letra);

    for(int i = 0; i < strlen(musica); i++){
        if(musica[i] == letra){
            oc[num] = i;
            q++;
            num++;
        }
    }

    if(q > 0){
        for(int i = 0; i < q; i++){
            printf("Ocorrencia do caractere na posicao %d\n", oc[i]);
        }
    }else{
        printf("Caractere nao encontrado\n");
    }
}    char letra;xf86-input-synaptics
