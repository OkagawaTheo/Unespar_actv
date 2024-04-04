#include <stdio.h>
#include <string.h>

typedef struct Aluno {
    int numero;
    char nome[50];
    char curso[30];
    float nota1, nota2;
} Aluno;

int main() {
    Aluno aluno;
    char nomeArq[100];

    printf("Número do aluno: ");
    scanf("%d", &aluno.numero);
    getchar(); 

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);

    snprintf(nomeArq, sizeof(nomeArq), "%s.txt", aluno.nome);
    FILE *arq = fopen(nomeArq, "w");

    printf("Curso: ");
    fgets(aluno.curso, sizeof(aluno.curso), stdin);

    printf("1º nota: ");
    scanf("%f", &aluno.nota1);

    printf("2º nota: ");
    scanf("%f", &aluno.nota2);

    fprintf(arq, "Número: %d\n", aluno.numero);
    fprintf(arq, "Nome: %s\n", aluno.nome);
    fprintf(arq, "Curso: %s\n", aluno.curso);
    fprintf(arq, "Nota 1: %.2f\n", aluno.nota1);
    fprintf(arq, "Nota 2: %.2f\n", aluno.nota2);

    fclose(arq);
    printf("Informações salvas no arquivo %s.\n", nomeArq);

    return 0;
}
