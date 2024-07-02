#include <stdio.h>
#include <string.h>

int main(){
    char frase[100];
    char disco1[100];
    char disco2[100];

    printf("Simulador de RAID 0\n");
    printf("Digite a frase: ");
    fgets(frase,sizeof(frase),stdin);
    
  for (int i = 0; i < strlen(frase); i++) {
        if (i % 2 == 0) disco1[i / 2] = frase[i];
        else disco2[i / 2] = frase[i]; 
    }
    
    printf("Disco 1: %s\n", disco1);
    printf("Disco 2: %s\n", disco2);
    

}