#include <stdio.h>

int main(){
    float vendas[3][4];
    float total_vendas = 0;
    float v1=0,v2=0,v3=0;
    float sem1=0,sem2=0,sem3=0;

    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            scanf("%f",&vendas[i][j]);
            total_vendas += vendas[i][j];
        }
    }

    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            if (i == 0) v1 += vendas[i][j];
            else if (i == 1) v2 += vendas[i][j];
            else v3 += vendas[i][j];

            if (j==0) sem1 += vendas[i][j];
            else if (j==1) sem2 += vendas[i][j];
            else sem3 += vendas[i][j];
        }
    }

//vendedores
printf("Vendedores: \n");
printf("%.2f\n",v1);
printf("%.2f\n",v2);
printf("%.2f\n\n",v3);

//valor semanal
printf("Valores semanais: \n");
printf("%.2f\n",sem1);
printf("%.2f\n",sem2);
printf("%.2f\n",sem3);

}

