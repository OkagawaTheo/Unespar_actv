#include <stdio.h>

typedef struct Funcionario {
    char nome[30];
    int idade;
    char dataNasc[30];
    char sexo;
    char cpf[20];
    int codSetor;
    char cargo[30];
    float salario;
} func;

void catchInfo(func *f) {
    printf("Digite o nome: ");
    fgets(f->nome, sizeof(f->nome), stdin);

    printf("Digite a idade: ");
    scanf("%d", &f->idade);

    getchar(); 

    printf("Digite a data de nascimento: ");
    fgets(f->dataNasc, sizeof(f->dataNasc), stdin);

    printf("Digite o sexo: ");
    scanf(" %c", &f->sexo);

    printf("Digite o cpf: ");
    getchar(); 
    fgets(f->cpf, sizeof(f->cpf), stdin);

    printf("Digite o código do setor[0-99]: ");
    scanf("%d", &f->codSetor);

    getchar(); 

    printf("Digite o cargo: ");
    fgets(f->cargo, sizeof(f->cargo), stdin);

    printf("Digite o salário: ");
    scanf("%f", &f->salario);
}

void printData(func f) {
    printf("\n\nInformações:");
    printf("Nome: %s", f.nome);
    printf("Idade: %d\n", f.idade);
    printf("Data nasc: %s", f.dataNasc);
    printf("Sexo: %c\n", f.sexo);
    printf("Código setor: %d\n", f.codSetor);
    printf("Cargo: %s", f.cargo);
    printf("Salário: %.2f\n", f.salario);
}

int main() {
    func funcionario;

    catchInfo(&funcionario);
    printData(funcionario);

}
