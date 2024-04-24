#include <stdio.h> //idade
int main(){
    int idade;
    printf("Digite a idade: "); scanf("%d",&idade);
    if (idade > 25){
        printf("maduro");
    } else if(idade > 60){
        printf("Idoso");
    } else if (idade >= 17 && idade <= 25){
        printf("jovem adulto");
    }else if (idade < 18){
        printf("jovem");
    }
}