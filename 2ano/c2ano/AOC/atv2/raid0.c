#include <stdio.h>
#include <string.h>

typedef struct discos {
    char disco1[100];
    char disco2[100];
    char disco3[100];
    char disco_paridade[100];
} disc;

void raid0(disc *discos_raid0, char *frase) {
    int len = strlen(frase);
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) discos_raid0->disco1[i / 2] = frase[i];
        else discos_raid0->disco2[i / 2] = frase[i]; 
    }
    discos_raid0->disco1[(len + 1) / 2] = '\0';
    discos_raid0->disco2[len / 2] = '\0';
}

void raid1(disc *discos_raid1, char *frase) {
    // disco 2 = copia
    strcpy(discos_raid1->disco1, frase);
    strcpy(discos_raid1->disco2, frase);
}

void raid4(disc *discos_raid4, char *frase) {
    // paridade xor
    for (int i=0; i< strlen(frase); i++){
        if (i % 3 == 0) discos_raid4->disco1[i/3] = frase[i];
        else if (i % 3 == 1) discos_raid4->disco2[i/3] = frase[i];
        else discos_raid4->disco3[i/3] = frase[i];
    }
}

int main() {
    disc discos_raid0;
    disc discos_raid1;
    disc discos_raid4;
    char frase[100];

    printf("Digite a frase: ");
    fgets(frase, sizeof(frase), stdin);
    
    printf("Exemplo de RAID 0: \n");
    raid0(&discos_raid0, frase);
    printf("Disco 1: %s\n", discos_raid0.disco1);
    printf("Disco 2: %s\n", discos_raid0.disco2);

    printf("\nExemplo de RAID 1:\n");
    raid1(&discos_raid1, frase);
    printf("Disco 1: %s\n", discos_raid1.disco1);
    printf("Disco 2: %s\n", discos_raid1.disco2);

    printf("\nExemplo de RAID 4:\n");
    raid4(&discos_raid4, frase);
    printf("Disco 1: %s\n", discos_raid4.disco1);
    printf("Disco 2: %s\n", discos_raid4.disco2);
    printf("Disco 3: %s\n", discos_raid4.disco3);
    printf("Disco de Paridade: %s\n", discos_raid4.disco_paridade);
}

