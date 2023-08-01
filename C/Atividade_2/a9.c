#include <stdio.h>

int main(){
    int code;
    float price;

    printf("Digite respectivamente o preço do produto e código de origem: ");
    scanf("%f %d",&price,&code);

    switch (code)
    {
    case 1:
        printf("Norte");
        break;

    case 2:
    printf("Nordeste");
    break;

    case 3:
        printf("Sudeste");
        break;

    case 4:
    printf("Sul");
    break;

    case 5: 
    printf("Centro-oeste");
    
    default:
        break;
    }
}