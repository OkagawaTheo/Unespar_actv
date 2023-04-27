#include <stdio.h>

int main(){
    // int cont;
    //  typedef struct n
    // {
        // /* data */
    // };
    // 
    // adas = [];
    // for (cont = 100;cont<107;cont++){
        // printf()
    // }

    int code;
    float qnt;



    menu();
    
    printf("\nDigite o código do produto que deseja: ");
    scanf("%d", &code);
    printf("Digite a quantidade que deseja: ");
    scanf("%f",&qnt);


    switch (code){
        case 100:
        printf("%.2f unidades = R$%.2f",qnt,(qnt*7.50));
        break;

        case 101:
        printf("%.2f unidades = R$%.2f",qnt,(qnt*5.50));
        break;

        case 103:
        printf("%.2f unidades = R$%.2f",qnt,(qnt*10.50));
        break;

        case 104:
        printf("%.2f unidades = R$%.2f",qnt,(qnt*11.00));
        break;

        case 105:
        printf("%.2f unidades = R$%.2f",qnt,(qnt*13.50));
        break;

        case 106:
        printf("%.2f unidades = R$%.2f",qnt,(qnt*5.50));
        break;

        default:
        printf("Valor inválido.");
    }

}


 int menu(void){
    printf("\n100 - Cachorro Quente - 7,50\n");
    printf("101 - Bauru - 5,50\n");
    printf("103 - x-burguer - 10,50\n");
    printf("104 - x-salada - 11,00\n");
    printf("105 - x-bacon - 13,50\n");
    printf("106 - Refrigerante - 3,50\n");
    }

// float calc(float a,float b){
// }
//     printf("%.2f unidades = R$%.2f",a,(a*b);