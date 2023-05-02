#include <stdio.h>

int main(){

    int mam, ave,rep;
    int quad,bip,herb,voador,aqua,naovoador,nad,rapina,casco,carn,sempatas,oni,frut,tropical,polar,nadador;

    printf("Digite 1 para sim e 0 para não.\n");

    printf("É mamifero? ");
    scanf("%d",&mam);

    printf("É quadrupede? ");
    scanf("%d",&quad);

    printf("É carnivoro? ");
    scanf("%d",&carn);

    printf("É herbivoro? ");
    scanf("%d",&herb);

    printf("É ave? ");
    scanf("%d",&ave);

    printf("É reptil? ");
    scanf("%d",&rep);

    if (mam == 1){
        if (quad == 1){ //mam e quad

        if (herb == 1 && carn == 0){
                printf("cavalo");
            }

        if (carn == 1){
            printf("leao");
        }
            
        }

        if (bip == 1){
            if (oni == 1){
                printf("Homem");
            }
            if (frut == 1){
                printf("Macaco");
            }
        }

        if (voador == 1){
            printf("Morcego");
        }
        if (aqua == 1){
            printf("Baleia");
        }
    }

    if (ave == 1){
        if (naovoador == 1){
            if (tropical == 1){
                printf("avestruz");
            }
        if (polar == 1){
            printf("pinguim");
        }
        
        }

        if (nadador == 1){
            printf("pato");
        }

        if (rapina == 1){
            printf("aguia");
        }
    }

    if (rep == 1){
        if (casco == 1){
            printf("tartaruga");
        }
    
        if (carn == 1){
            printf("crocodilo");
        }

        if (sempatas == 1){
            printf("cobra");
        }
    }


}