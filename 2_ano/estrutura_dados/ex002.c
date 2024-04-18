
#include <stdio.h>
// Aluno: Theo Okagawa

main(){ //incremento
    int c; 
    c = 5;
    printf("%d \n", c);
    printf("%d \n", c++);
    printf("%d \n\n", c);
    c = 5;
    printf("%d \n", c);
    printf("%d \n", ++c);
    printf("%d \n\n", c);

}
#include <stdio.h>
main(){// aritmetica
    
    i+= 2;       //i=(i+2)
    x*=y+1;     //x=x*(y+1)
    t/=2.5;    //t=(t/2.5)
    p%=5;     //p=(p%5)
    d-=3;    //d=(d-3)

}

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

main(){
    int numero;
    printf("Digite um numero");
    scanf("%d",&numero);

    if (num == 10){
        printf("vc acertou");
    } else{
        if (num > 10){
            printf("numero maior q 10");
        }else{
            printf("numero menor que 10");
        }
    }
}

main(){
    for(int i=0;i<10;i++){
        printf("%d\n",i);
    }
}