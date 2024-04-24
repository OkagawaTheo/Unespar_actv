#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    int main(){
    int qtd1 = 0, qtd2 = 0, qtd3 = 0, qtd4 = 0, qtd5 = 0, qtd6 = 0;   

    int valores[20];
    

    srand(time(NULL));

    for (int i=0;i<20;i++){
        valores[i] = rand() % 6 + 1;        
        printf("%d\n",valores[i]);
       
        if (valores[i] == 1)qtd1++; 
        else if (valores[i] == 2)qtd2++;
        else if(valores[i]== 3)qtd3++;
        else if(valores[i] == 4)qtd4++;
        else if(valores[i] == 5)qtd5++;
        else if(valores[i] == 6)qtd6++;

    }
    printf("Quantidade de dados com valor 1 = %d\n", qtd1);
    printf("Quantidade de dados com valor 2 = %d\n", qtd2);
    printf("Quantidade de dados com valor 3 = %d\n", qtd3);
    printf("Quantidade de dados com valor 4 = %d\n", qtd4);
    printf("Quantidade de dados com valor 5 = %d\n", qtd5);
    printf("Quantidade de dados com valor 6 = %d\n", qtd6);
    
    }
    