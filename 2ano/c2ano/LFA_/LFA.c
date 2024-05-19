#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Função para fazer a verificação da palavra digitada pelo usuário
bool verificarPalavra(int estado_inicial, int estados_finais[], int qtd_estados_finais, int qtd_simbolos, char alfabeto[], int tabela_transicao[][10], char palavra[]) {
    int estado_atual = estado_inicial;

    // Laço de repetição para procurar a palavra no meio do alfabeto
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice_simbolo = -1;
        for (int j = 0; j < qtd_simbolos; j++) {
            if (palavra[i] == alfabeto[j]) {
                indice_simbolo = j;
                break;
            }
        }

        // Verificar se o símbolo está ou não no alfabeto
        if (indice_simbolo == -1) {
            printf("Símbolo inválido.\n");
            return false;
        }

        // Atualizar o estado atual conforme a transição
        estado_atual = tabela_transicao[estado_atual - 1][indice_simbolo];

        // Verificar se a transição leva a um estado inválido
        if (estado_atual == 0) {
            printf("Transição inválida.\n");
            return false;
        }
    }

    // Fazer a comparação entre estado atual e final
    for (int i = 0; i < qtd_estados_finais; i++) {
        if (estado_atual == estados_finais[i]) {
            return true;
        }
    }

    return false;
}

int main() {
    int estado_inicial, qtd_estados, qtd_estados_finais, qtd_simbolos;
    char alfabeto[10];
    int estados_finais[100], tabela_transicao[100][10];

    printf("Digite o estado inicial: ");
    scanf("%d", &estado_inicial);

    printf("Quantidade de estados: ");
    scanf("%d", &qtd_estados);

    printf("Digite a quantidade de estados finais: ");
    scanf("%d", &qtd_estados_finais);

    printf("Digite os estados finais: ");
    for (int i = 0; i < qtd_estados_finais; i++) {
        scanf("%d", &estados_finais[i]); 
    }

    printf("Digite a quantidade de simbolos do alfabeto: ");
    scanf("%d", &qtd_simbolos);

    printf("Símbolos do alfabeto: ");
    for (int i = 0; i < qtd_simbolos; i++) { 
        scanf(" %c", &alfabeto[i]); 
    }

    // Preencher a tabela de transição
    printf("Preencha a tabela de transição (estado x símbolo):\n"); 
    for (int i = 0; i < qtd_estados; i++) {
        for (int j = 0; j < qtd_simbolos; j++) {
            printf("(Q%d, %c): ", i + 1, alfabeto[j]); 
            scanf("%d", &tabela_transicao[i][j]); 
        }
    }

    printf("\nTabela de Transição: \n");
    printf("Estado    ");
    for (int i = 0; i < qtd_simbolos; i++) {
        printf("| %c ", alfabeto[i]);
    }
    printf("\n");
    for (int i = 0; i < qtd_estados; i++) {
        printf("q%d        ", i + 1);
        for (int j = 0; j < qtd_simbolos; j++) {
            printf("| %d ", tabela_transicao[i][j]);
        }
        printf("\n");
    }

    // Verificar palavra digitada pelo usuário
    while(true){
        char palavra[100];
        printf("\nDigite a palavra a ser verificada ('0' pra sair): ");
        scanf("%s", palavra);
        if (strcmp(palavra,"0") == 0) break; // para dar break se usuario digitar 0
        // Verificamos se a função verificar palavra é verdadeira, caso for será impressa a mensagem que ela é aceita, caso não, ela não é aceita.
        if (verificarPalavra(estado_inicial, estados_finais, qtd_estados_finais, qtd_simbolos, alfabeto, tabela_transicao, palavra)) 
            printf("A palavra \"%s\" é aceita pelo AFD.\n", palavra);
        else 
            printf("A palavra \"%s\" não é aceita pelo AFD.\n", palavra);
    }
    
}
