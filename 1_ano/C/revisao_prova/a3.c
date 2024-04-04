#include <stdio.h>

typedef struct Carro{
    char fabricante[100];
    char modelo[100];
    char placa[20];
    char tipo_combustivel[30];
    char tamanho
}Carro;


void Preencher(Carro *c){
    printf("Fabricante do carro: ");
    fgets(c->fabricante,sizeof(c->fabricante),stdin);
    printf("Modelo: ");
    fgets(c->modelo,sizeof(c->modelo),stdin);
    printf("Placa: ");
    fgets(c->placa,sizeof(c->placa),stdin);
    printf("Tipo de combstivel: [c,a,al]: ");
    fgets(c->tipo_combustivel,sizeof(c->tipo_combustivel),stdin);

}


int main(){
    Carro carro;
    Preencher(&carro);
}