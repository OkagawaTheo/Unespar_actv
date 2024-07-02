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

void raid1(disc *discos_raid1,char *frase){
    // disco 2 = copia
    strcpy(discos_raid1->disco1,frase);
    strcpy(discos_raid1->disco2,frase);

}

int main(){
    disc discos_raid0;
    disc discos_raid1;
    char frase[100];

    printf("Digite a frase: ");
    fgets(frase,sizeof(frase),stdin);


    printf("Exemplo de RAID 0: \n");
    raid0(&discos_raid0,frase);
    printf("Disco 1: %s\n", discos_raid0.disco1);
    printf("Disco 2: %s\n", discos_raid0.disco2);
    
    printf("Exemplo de RAID 1:\n");
    raid1(&discos_raid1,frase);
    printf("Disco 1: %s\n", discos_raid1.disco1);
    printf("Disco 2: %s\n", discos_raid1.disco2);

    printf("Exemplo de RAID 4:\n");
    
    

}