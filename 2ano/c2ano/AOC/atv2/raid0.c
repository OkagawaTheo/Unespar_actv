#include <stdio.h>
#include <string.h>

int main(){
    char frase[100];
    char disco1[100];
    char disco2[100];

    printf("Simulador de RAID 0\n");
    printf("Digite a frase: ");
    fgets(frase,sizeof(frase),stdin);
    
    for(int i=0;i<strlen(frase);i+=2){
        printf("%c",frase[i]);
    }

}