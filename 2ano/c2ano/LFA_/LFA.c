#include <stdio.h>
#include <stdbool.h>

// função para fazer a verificação da palavra digitada pelo usuario
bool verificarPalavra(int estado_inicial, int estados_finais[], int qtd_estados_finais, int qtd_simbolos, char alfabeto[], int tabela_transicao[][10], char palavra[]) {
    int estado_atual = estado_inicial;

    // laço de repetição para procurar a palavra no meio do alfabeto
    for (int i = 0; palavra[i] != '\0'; i++) { //diferente de "final"
        int indice_simbolo = -1;
        for (int j = 0; j < qtd_simbolos; j++) {
            if (palavra[i] == alfabeto[j]) {
                indice_simbolo = j;
                break;
            }
        }
        // if feito para ver se o simbolo está ou não no alfabeto
        if (indice_simbolo == -1) {
            printf("Símbolo invalido.\n");
            return false;
        }
        
        // Estado atual atualizado conforme transição
        estado_atual = tabela_transicao[estado_atual - 1][indice_simbolo];
    }
        // ffazer comparação entre estado atual e final para se forem iguais retorna como true por ter conseguido "passar" por todos os caracteres e ter chego no ultimo que que é um final.
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

    printf("Digite os estados finais:");
    for (int i = 0; i < qtd_estados_finais; i++) {
        scanf("%d", &estados_finais[i]); 
    }

    printf("Digite a quantidade de simbolos do alfabeto: ");
    scanf("%d", &qtd_simbolos);

    printf("Símbolos do alfabeto: ");
    for (int i = 0; i < qtd_simbolos; i++) { 
        scanf(" %c", &alfabeto[i]); 
    }

    // Preencher a tabela de transicao
    printf("Preencha a tabela de transicao (estado x símbolo):\n"); 
    for (int i = 0; i < qtd_estados; i++) {
        for (int j = 0; j < qtd_simbolos; j++) {
            printf("(Q%d, %c): ", i + 1, alfabeto[j]); 
            scanf("%d", &tabela_transicao[i][j]); 
        }
    }

    printf("\nTabela de Transição: \n");
    printf("Estado   ");
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
    char palavra[100];
    printf("\nDigite a palavra a ser verificada: ");
    scanf("%s", palavra);

    // verificamos se a funcao verificar palabra é verdadeira, caso for sera impressa a mensagem que ela é aceita, caso não, ela não é aceita.
    if (verificar_palavra(estado_inicial, estados_finais, qtd_estados_finais, qtd_simbolos, alfabeto, tabela_transicao, palavra)) 
    printf("A palavra \"%s\" é aceita pelo AFD.\n", palavra);
        
    else printf("A palavra \"%s\" não é aceita pelo AFD.\n", palavra);
}