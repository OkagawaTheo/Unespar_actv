#include <stdio.h>


typedef struct Vendedor{
    float salario_fixo;
    int vendas;
    float comissao;
    float salario_final;

}Vendedor;


void calculoSalario(Vendedor *v){
    
    printf("\nDigite o valor do salário fixo: ");
    scanf("%f",&v->salario_fixo);    
    printf("Digite o valor total das vendas efetuadas: ");
    scanf("%d",&v->vendas);

    v->comissao = v->vendas*0.06;
    v->salario_final = v->salario_fixo + v->comissao;
    
}

int main(){
    Vendedor v1,v2;
    calculoSalario(&v1);
    printf("\nInformações do Vendedor 1:\n");
    printf("Salário Fixo: %.2f\n", v1.salario_fixo);
    printf("Valor das Vendas: %.2f\n", v1.vendas);
    printf("Comissão: %.2f\n", v1.comissao);
    printf("Salário Final: %.2f\n", v1.salario_final);

    calculoSalario(&v2);
    printf("\nInformações do Vendedor 2:\n");
    printf("Salário Fixo: %.2f\n", v2.salario_fixo);
    printf("Valor das Vendas: %.2f\n", v2.vendas);
    printf("Comissão: %.2f\n", v2.comissao);
    printf("Salário Final: %.2f\n", v2.salario_final);
    // refatorar com vetor e for depois pra deixar dinâmico.
}
