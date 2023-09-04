#include <stdio.h>
 
int main() {
 
    int leaving_minutes,tempo_min;
    int p1,p2;
    scanf("%d %d %d",&leaving_minutes,&p1,&p2);

    if (p1+p2 > leaving_minutes){
        printf("Deixa para amanha!\n");
    }
    else printf("Farei hoje!\n");

    }

