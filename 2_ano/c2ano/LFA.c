#include <stdio.h>

typedef struct Afdinfo{
    int estado_inicial;
    int qtd_estados; //q0,q1
    int estados_finais[100];
    int qtd_estado_final;
    int qtd_simbolos;

}afdinfo;


int main(){
    afdinfo afd; //call struct to catch info about afd
    
    printf("Digite o estado inicial: "); scanf("%d",&afd.estado_inicial);
    printf("Digite a quantidade de estados: "); scanf("%d",&afd.qtd_estados);
    printf("Digite a quantidade de estado final: "); scanf("%d",&afd.qtd_estado_final);

    for (int i=0;i<afd.qtd_estado_final;i++){
        printf("    Digite o %dº estado: ",i+1);
        scanf("%d",&afd.estados_finais[i]);
    }
    
    
     
}