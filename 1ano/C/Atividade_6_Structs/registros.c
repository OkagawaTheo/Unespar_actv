#include <stdio.h>
#include <ctype.h>

typedef struct Professores
{
    int codigo;
    char sexo;
    int ValorhoraAula;
} Prof;

int main()
{
    Prof p[10];
    double const horaAula = 60.50;
    double novo_sal;
    int f = 0, m = 0;
    double tot_salario_m = 0.0, tot_salario_f = 0.0;

    for (int i = 0; i < 2; i++)
    {
        printf("Digite o código do %dº professor: ", i + 1);
        scanf("%d", &p[i].codigo);
        fflush(stdin);
        printf("Digite o sexo [m,f]:");
        scanf("%s", &p[i].sexo);

        printf("Digite o total de horas-aula ministradas:");
        scanf("%d", &p[i].ValorhoraAula);
        double sal_bruto = horaAula * p[i].ValorhoraAula;

        if (p[i].ValorhoraAula < 70)
        {
            novo_sal = sal_bruto - ((sal_bruto * 8) / 100);
        }
        else
        {
            novo_sal = sal_bruto - ((sal_bruto * 5) / 100);
        }

        if (p[i].sexo == 'm'){
            tot_salario_m += novo_sal;
            m++;
        }
        else{
            tot_salario_f += novo_sal;
            f++;
        }

        printf("\nCódigo do professor: %d\n", p[i].codigo);
        printf("Salário bruto: %.2lf\n", sal_bruto);
        printf("Salário líquido: %.2lf\n", novo_sal);
        printf("---------------\n");
    }
    printf("Média aritmética M: %.2lf\n", tot_salario_m / m);
    printf("Média aritmética F: %.2lf\n", tot_salario_f / f);
}
