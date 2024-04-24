#include <stdio.h>

int main(){
    double n1,n2,media;

    scanf("%lf %lf",&n1,&n2);
    media = (n1*3.5 + n2*7.5) / (3.5+7.5);
    printf("MEDIA = %.5f\n",media);
}