#include <stdio.h>

int main()
{

    int mam, ave, rep;
    int quad, bip, herb, voador, aqua, naovoador, nad, rapina, casco, carn, sempatas, oni, frut, tropical, polar;

    printf("Digite 1 para sim e 0 para não.\n");

    printf("É mamifero? ");
    scanf("%d", &mam);
    if (mam == 1)
    {
        printf("É quadrupede? ");
        scanf("%d", &quad);

        if (quad == 1)
        {
            printf("É carnivoro? ");
            scanf("%d", &carn);
            if (carn == 1)
            {
                printf("Leao");
                exit(0);
            }
            else
            {
                printf("Herbívoro, Cavalo.");
                exit(0);
            }
        }

        printf("É bipede? ");
        scanf("%d", &bip);
        if (bip == 1)
        {
            printf("É onivoro? ");
            scanf("%d", &oni);
            if (oni == 1)
            {
                printf("Homem");
                exit(0);
            }
            else
            {
                printf("frutifero, macaco.");
                exit(0);
            }
        }

        printf("é voador? ");
        scanf("%d", &voador);
        if (voador == 1)
        {
            printf("morcego");
            exit(0);
        }
        else
        {
            printf("aquatico, baleia");
            exit(0);
        }
    }

    printf("É ave? ");
    scanf("%d", &ave);

    if (ave == 1)
    {
        printf("nao-voadora? ");
        scanf("%d", &naovoador);
        if (naovoador == 1)
        {
            printf("Tropical? ");
            scanf("%d", &tropical);
            if (tropical == 1)
            {
                printf("avestruz");
                exit(0);
            }
            else
            {
                printf("polar, pinguim");
                exit(0);
            }
        }

        else
        {
            printf("é nadadora? ");
            scanf("%d", &nad);
            if (nad == 1)
            {
                printf("pato");
                exit(0);
            }
            else
            {
                printf("rapina, aguia");
                exit(0);
            }
        }


        printf("É reptil? ");
        scanf("%d", &rep);
        if (rep == 1)
        {
            printf("Tem casco? ");
            scanf("%d", &casco);
            if (casco == 1)
            {
                printf("tartaruga");
                exit(0);
            }
            printf("Carnivoro? ");
            scanf("%d", carn);
            if (carn == 1)
            {
                printf("crocodilo");
                exit(0);
            }
            else
            {
                printf("sem patas, cobra");
                exit(0);
            }
        }
    }
}