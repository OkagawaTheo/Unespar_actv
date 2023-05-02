#include <stdio.h>

int main(){
    float num;

    printf("Digite um número: ");
    scanf("%f",&num);

    if (num >= 50) {
        printf("%.2f / 2 = %.2f\n",num,num / 2);
    } else{
        printf("%.2f x 2 = %.2f\n",num,num * 2);
    }


}
