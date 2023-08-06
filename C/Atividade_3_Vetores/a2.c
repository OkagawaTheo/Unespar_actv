#include <stdio.h>

int main(){
    float temps[12]; 
    
    float maior = 0.0, menor;
    int indiceM,indiceN;
    char mes;
    
    for (int i=0;i<3;i++){
        float maior = 0;
        printf("temperatura média: ");
        scanf("%f",&temps[i]);
    }
    menor = temps[0];

    for (int i=0;i<3;i++){
        if (i == 0){
            maior = temps[i];
            
        }
        if (temps[i] > maior){
            maior = temps[i];
            indiceM = i+1;
            
        }
        
        if (temps[i] < menor){
            menor = temps[i];
            indiceN = i+1;
        }
    }
    printf("A maior temperatura foi de %.2f graus e no mês %d\n",maior,indiceM);
    printf("A menor temperatura foi de %.2f graus no mês %d\n",menor,indiceN);
}


// meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Março", "Junho", "Julho", "Agosto", "Setembro", "Outubro","Novembro", "Dezembro"};


