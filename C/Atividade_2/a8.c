#include <stdio.h>

int main(){
    int n1,n2;
    
    printf("Digite dois números inteiros: ");
    scanf("%d %d",&n1, &n2);
    if (n1 > n2) {
        printf("%d é maior que %d",n1,n2);
    } else{
        printf("%d é maior que %d",n2,n1);
    }
}


