#include <stdio.h>

typedef struct Empresas {
    char nome[100];
    char area_atuacao[100];
    float valor_acao;
    float valor_anterior;
    double variacao_preco;
} Emp;

void CalcularVariacaoAcao(Emp *empresa) {
    empresa->variacao_preco = ((empresa->valor_acao - empresa->valor_anterior) / empresa->valor_anterior) * 100;
}

void Preencher(Emp *empresa) {
    printf("Digite o nome da empresa: ");
    fgets(empresa->nome, sizeof(empresa->nome), stdin);
    
    printf("Área de atuação: ");
    fgets(empresa->area_atuacao,sizeof(empresa->area_atuacao),stdin);

    printf("Valor atual da ação [R$]: ");
    scanf("%f", &empresa->valor_acao);
    
    printf("Valor anterior da ação [R$]: ");
    scanf("%f", &empresa->valor_anterior);
    getchar(); 

    CalcularVariacaoAcao(empresa);
}

void PrintarInfo(Emp empresa){
    printf("\nNome da empresa: %s",empresa.nome);
    printf("rea de atuação da empresa: %s",empresa.area_atuacao);
    printf("Valor atual da ação: %.2f",empresa.valor_acao);
    printf("\nValor anterior: %.2f\n",empresa.valor_anterior);
}

int main() {
    Emp empresa1[3];
    float compararAcao;
    printf("Preenchendo 3 empresas!\n");

    for (int i=0;i<3;i++){
        Preencher(&empresa1[i]);
    }
    printf("\nDigite um valor de ação: ");
    scanf("%f",&compararAcao);
    
    printf("Empresas com valor de ação menores que %.2f:\n",compararAcao);
    for (int i=0,j=0;i<3;i++){
        if (empresa1[i].valor_acao < compararAcao){
            j++;
            PrintarInfo(empresa1[i]);
        }
        if (j==0) printf("\n Nenhuma empresa.");
    }
}