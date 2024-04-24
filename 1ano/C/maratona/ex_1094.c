#include <stdio.h>

int main(){
    int s=0,r=0,c=0;
    char escolha;
    float qtd_casos,qtd_animais;
    float total_cobaias=0;
    float total_s=0,total_r=0,total_c=0;
    float porcentagem;
    scanf("%f",&qtd_casos);

    for (int i=0;i<qtd_casos;i++){
        scanf("%f %c",&qtd_animais,&escolha);
        total_cobaias += qtd_animais;

        if (escolha == 'S'){
            s++;
            total_s += qtd_animais;
        }
        else if (escolha == 'R'){
            r++;
            total_r += qtd_animais;
        }
        else if (escolha == 'C'){
            c++;
            total_c += qtd_animais;
        }
        
    }
    printf("Total: %.0f cobaias\n",total_cobaias);
    printf("Total de coelhos: %.0f\n",total_c);
    printf("Total de ratos: %.0f\n",total_r);
    printf("Total de sapos: %.0f\n",total_s);
    printf("Percentual de coelhos: %.2f %%\n",(total_c*100.0)/total_cobaias);
    printf("Percentual de ratos: %.2f %%\n",(total_r*100.0)/total_cobaias);
    printf("Percentual de sapos: %.2f %%\n",(total_s*100.0)/total_cobaias);

}


