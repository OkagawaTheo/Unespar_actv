#include <stdio.h>

typedef struct Lojas{
    char num[5];
    float total_vendas;
}filial;

int main(){
    FILE* arq;
    filial f;
    int qtd_cadastros;
    int filial;
    float valor_total;
    
    printf("Quantas vendas deseja cadastrar? ");
    scanf("%d",&qtd_cadastros);
    if ((arq = fopen("entrada.txt","w")) == NULL){
        printf("Erro ao abrir");
    }
    

    for (int i=0;i<qtd_cadastros;i++){
        printf("Cadastrando a %dº venda",i+1);
        setbuf(stdin, NULL);
        printf("\nCódigo da filial: ");
        scanf("%s",&f.num);
        
        printf("Digite o total de vendas: ");
        scanf("%f",&f.total_vendas);
        
        fprintf(arq,"%s,%.2f\n",f.num,f.total_vendas);
    }
    fclose(arq);
    
    arq = fopen("entrada.txt","r");

    //while (fscanf(arq,"%s,%f",f.num,&f.total_vendas) != EOF){
    //    printf("\n%f",vendas[i]);
    //}
    //printf("Valor total das vendas de todas as filiais: %.2f",valor_total);
}