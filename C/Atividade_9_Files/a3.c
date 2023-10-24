#include <stdio.h>

typedef struct Aluno{
    int numero;
    char nome[50];
    char curso[30];
    float nota1, nota2;
}al;



int main(){
    al aluno;
    char nomeArq[100];

    printf("Número do aluno: ");
    scanf("%d",&aluno.numero);
    getchar();
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome,sizeof(aluno.nome),stdin);

    printf("Curso: ");
    fgets(aluno.curso,sizeof(aluno.curso),stdin);

    printf("1º nota: ");
    scanf("%f",&aluno.nota1);

    printf("2º nota: ");
    scanf("%f",&aluno.nota2);

    snprintf(nomeArq, sizeof(nomeArq), "%s.txt", aluno.nome);
    FILEhttps://github.com/OkagawaTheo/Unespar_actv/tree/main/C/Atividade_9_Files *arq = fopen(nomeArq,"w");

    fprintf(arq, "Número: %d\n",aluno.numero);
    fprintf(arq, "Nome: %d\n",aluno.nome);
    fprintf(arq, "Curso: %d\n",aluno.curso);
    fprintf(arq, "Nota 1: %d\n",aluno.nota1);
    fprintf(arq, "Nota 2: %d\n",aluno.nota2);
    
    fclose(arq);
    printf("Informações salvas no arquivo %s.\n",nomeArq);


}