#include <stdio.h>
#include <stdlib.h>

int main(){
    int ra[7];
    float media_final[7];

    for (int i=0;i<7;i++){
        printf("RA do %dº aluno: ",i+1);
        scanf("%d",&ra[i]);

        printf("Média do %dº aluno: ",i+1);
        scanf("%f",&media_final[i]);

        if (media_final[i] < 7){
            printf("Aluno não aprovado. Precisa tirar ao menos %.2f no exame\n \n",7-media_final[i]);
        }else {
            printf("Aprovado.\n \n");
        }
    }

    // for (int i=0;i<7;i++){
        // printf("%d %.2f\n",ra[i],media_final[i]);
    // }

}


