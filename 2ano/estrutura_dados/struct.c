#include <stdio.h>

typedef struct Aluno{
    char nome[40];
    int numero;
    int nota;
}Aluno;


int main(){
    Aluno al;
    printf("---Cadastro de aluno---\n\n\n");

    printf("Nome do aluno: ");
    fflush(stdin);
    fgets(al.nome,sizeof(al.nome),stdin);
    
    printf("Digite o numero do aluno: ");
    scanf("%d",&al.numero);

    printf("Nota do aluno: ");
    scanf("%f",&al.nota);

    printf("\nDados lidos:\n\n\n");
    printf("Nome: %s",al.nome);
    printf("\nNumero do aluno: %d",al.numero);
    printf("\nNota: %.2f",al.nota);
}