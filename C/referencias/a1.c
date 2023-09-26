#include <stdio.h>

void calcMedia(float n1,float n2,float n3,float *re_media,char l){
    int const peso = 10;
    int a = 5, b = 3, c = 2;

    if (l == 'a'){
        *re_media =  (n1 + n2 + n3) / 3;    
    } else if (l == 'p') {
        *re_media = (n1*a + n2*b + n3*c) / peso;
    }
}


int main(){
    float n1,n2,n3,re_media;
    char l;
    
    printf("Digite as 3 notas do aluno: ");
    scanf("%f %f %f",&n1,&n2,&n3);
    
    printf("[a] - Média aritmética\n[p] - Média ponderada\n");
    scanf("%s",&l);

    calcMedia(n1,n2,n3,&re_media,l);
    printf(".1%f",re_media);
}