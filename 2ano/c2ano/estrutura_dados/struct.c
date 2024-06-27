#include <stdio.h>

typedef struct Aluno{
    char nome[100];
    float nota;
} Aluno;

void preencher(Aluno *al){
    printf("Digite nome: ");
    fgets(al->nome,sizeof(al->nome),stdin);
    printf("Digite nota: ");
    scanf("%f", &al->nota);
    getchar(); 
}

void mostrar(Aluno *al){
    printf("Nome: %s", al->nome);
    printf("Nota:\n %.2f", al->nota);
}

int main(){
   Aluno al[3];

   for (int i = 0; i < 3; i++){
        preencher(&al[i]);
   }

   printf("Nomes digitados:\n ");
   
   for (int i = 0; i < 3; i++){
        mostrar(&al[i]);
   }

}
