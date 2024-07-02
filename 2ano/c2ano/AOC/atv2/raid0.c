#include <stdio.h>
#include <string.h>

typedef struct discos{
    char disco1[100];
    char disco2[100];
}disc;

void raid0(disc *discos_raid0, char *frase){
    for (int i = 0; i < strlen(frase); i++) {
        if (i % 2 == 0) discos_raid0->disco1[i / 2] = frase[i];
        else discos_raid0->disco2[i / 2] = frase[i]; 
    }
}

int main(){
    disc discos_raid0;
    char frase[100];

    printf("Simulador de RAID 0\n");
    printf("Digite a frase: ");
    fgets(frase,sizeof(frase),stdin);
    
    raid0(&discos_raid0,frase);
    
    printf("Disco 1: %s\n", discos_raid0.disco1);
    printf("Disco 2: %s\n", discos_raid0.disco2);
    

}