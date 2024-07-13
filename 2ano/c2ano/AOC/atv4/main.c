#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_BLOCOS 30

void PrimeiroAjuste(int fitaMemoria[], int *memoriaTotal) {
    int memoriaAlocada;
    printf("Quantidade de KB a ser alocada: ");
    scanf("%d", &memoriaAlocada);

    if (*memoriaTotal >= memoriaAlocada) { //procura espaço vazio
        for (int i = 0; i < MAX_BLOCOS; i++) {
            if (fitaMemoria[i] == 0) {
                fitaMemoria[i] = memoriaAlocada;
                *memoriaTotal -= memoriaAlocada;
                printf("%d KB alocados no bloco %d. Restam %d KB.\n", memoriaAlocada, i, *memoriaTotal);
                return;
            }
        }
        printf("Não há espaço suficiente na memória.\n");
    } else {
        printf("Não há memória suficiente para alocar %d KB.\n", memoriaAlocada);
    }
}

void SelecionarInstrucao(bool *sair, int qtd_kb, int fitaMemoria[], int *memoriaTotal) {
    char instrucao;

    printf("\nDigite a instrução (I) para inserir, (L) para liberar e (X) para sair: ");
    scanf(" %c", &instrucao);
    instrucao = tolower(instrucao);

    switch (instrucao) {
        case 'l':
            // liberar
            printf("Liberando memoria...\n");
            break;
        case 'i':
            // inserir
            printf("Inserindo memoria...\n");
            PrimeiroAjuste(fitaMemoria, memoriaTotal);
            break;
        case 'x':
            printf("\nSaindo...\n");
            *sair = true;
            break;
        default:
            printf("\nInstrução inválida.\n");
            break;
    }
}

int main() {
    int qtd_kb, ajuste;
    bool sair = false;
    int fitaMemoria[MAX_BLOCOS] = {0};
    int memoriaTotal;

    printf("Informe a quantidade total de memória em KB: ");
    scanf("%d", &memoriaTotal);

    while (!sair) {
        printf("Digite a instrução (1) para alocar memória, (L) para liberar e (X) para sair: ");
        scanf(" %d", &ajuste);

        switch (ajuste) {
            case 1:
                // Alocar memória
                printf("\n<Alocar memória selecionado>\n");
                SelecionarInstrucao(&sair, qtd_kb, fitaMemoria, &memoriaTotal);
                printf("Memória total disponível: %d KB.\n", memoriaTotal);
                break;
            case 2:
                // Melhor ajuste (a ser implementado)
                printf("Melhor ajuste selecionado\n");
                break;
            case 3:
                // Pior ajuste (a ser implementado)
                printf("Pior ajuste selecionado\n");
                break;
            case 'l':
                // Liberar memória (a ser implementado)
                printf("Liberar memória selecionado\n");
                break;
            case 'x':
                // Sair
                printf("Saindo...\n");
                sair = true;
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}
