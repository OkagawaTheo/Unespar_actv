#include <stdio.h>
#include <string.h>
typedef struct MaiorCidade{
    char nome_cidade[40];
    char auxNome[40];
    int habitantes;
    char int_str[100];
    int aux;
}MaiorCidade;

int main(){
    
    char nome1[100],nome2[100];
    char nomeArq1[100],nomeArq2[100];
    char cidade[40];

    printf("Digite o nome do 1º arquivo: ");
    fgets(nome1,sizeof(nome1),stdin);
    snprintf(nomeArq1,sizeof(nomeArq1),"%s.txt",nome1);

    printf("Digite o nome do 2º: ");
    fgets(nome2,sizeof(nome2),stdin);
    snprintf(nomeArq2,sizeof(nomeArq2),"%s.txt",nome2);
    
    FILE* arq_cidades = fopen(nomeArq1,"w");
    
    for (int i=0;i<2;i++){
        printf("Digite o nome da cidade e qtd de habitantes ");
        fgets(cidade,sizeof(cidade),stdin);
        fprintf(arq_cidades,cidade);
    }
    fclose(arq_cidades);
    arq_cidades = fopen(nomeArq1,"r");

    MaiorCidade maior;
    maior.aux = 0;

    while (fscanf(arq_cidades, "%s %d",maior.nome_cidade, &maior.habitantes) != EOF){
        if (maior.habitantes > maior.aux){
            strcpy(maior.auxNome,maior.nome_cidade);
            maior.aux = maior.habitantes;
        }
    }

    FILE* saida = fopen(nomeArq2,"w");
    fprintf(saida,maior.nome_cidade); 
    sprintf(maior.int_str, "%d",maior.habitantes); //converte maior.habitantes para string  
    fprintf(saida,maior.int_str);
    fclose(saida);


}