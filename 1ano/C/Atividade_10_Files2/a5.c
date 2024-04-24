#include <stdio.h>
// #include <time.h>

typedef struct Pessoa{
    char nome[40];
    int ano_nasc;
    char ano_str[10];
}Pessoa;

int main(){
    Pessoa p;
    int ano_atual;
    printf("Digite o atual ano: ");
    scanf("%d",&ano_atual);
    getchar();

    printf("Digite o nome de uma pessoa: ");
    fgets(p.nome,sizeof(p.nome),stdin);
    printf("Ano de nascimento: ");
    scanf("%d",&p.ano_nasc);

    FILE* entrada = fopen("entrada.txt","w");
    fprintf(entrada,p.nome);
    sprintf(p.ano_str,"%d",p.ano_nasc);
    fprintf(entrada,p.ano_str);
    fclose(entrada);

    FILE* saida = fopen("saida.txt","w");
    if ((ano_atual - p.ano_nasc) >= 18){
        fprintf(saida,p.nome);
        fprintf(saida,"Maior de idade.");
    } 
    else{
        fprintf(saida,"Menor de idade.");
        fprintf(saida,p.nome);    
    }
    fclose(entrada);
    fclose(saida);
}