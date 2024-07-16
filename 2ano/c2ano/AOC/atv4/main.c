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
                printf("<<%d KB alocados no bloco %d. Restam %d>> KB.\n", memoriaAlocada, i, *memoriaTotal);
                return;
            }
        }
        printf("Não há espaço suficiente na memória.\n");
    } else {
        printf("Não há memória suficiente para alocar %d KB.\n", memoriaAlocada);
    }
}

void MelhorAjuste(int fitaMemoria[], int *memoriaTotal) {
    int memoriaAlocada;
    printf("Quantidade de KB a ser alocada: ");
    scanf("%d", &memoriaAlocada);

    if (*memoriaTotal >= memoriaAlocada) {
        int melhorBloco = -1;
        int menorEspacoSobrando = __INT_MAX__;

        for (int i = 0; i < MAX_BLOCOS; i++) {
            if (fitaMemoria[i] == 0 && (i == 0 || fitaMemoria[i - 1] != 0)) {
                int espacoLivre = 0;
                for (int j = i; j < MAX_BLOCOS && fitaMemoria[j] == 0; j++) {
                    espacoLivre += memoriaAlocada;
                }
                if (espacoLivre >= memoriaAlocada && espacoLivre < menorEspacoSobrando) {
                    melhorBloco = i;
                    menorEspacoSobrando = espacoLivre;
                }
            }
        }

        if (melhorBloco != -1) {
            fitaMemoria[melhorBloco] = memoriaAlocada;
            *memoriaTotal -= memoriaAlocada;
            printf("<<%d KB alocados no bloco %d. Restam %d>> KB.\n", memoriaAlocada, melhorBloco, *memoriaTotal);
        } else {
            printf("Não há espaço suficiente na memória.\n");
        }
    } else {
        printf("Não há memória suficiente para alocar %d KB.\n", memoriaAlocada);
    }
}

void PiorAjuste(int fitaMemoria[], int *memoriaTotal) {
    int memoriaAlocada;
    printf("Quantidade de KB a ser alocada: ");
    scanf("%d", &memoriaAlocada);

    if (*memoriaTotal >= memoriaAlocada) {
        int piorBloco = -1;
        int maiorEspacoSobrando = -1;

        for (int i = 0; i < MAX_BLOCOS; i++) {
            if (fitaMemoria[i] == 0 && (i == 0 || fitaMemoria[i - 1] != 0)) {
                int espacoLivre = 0;
                for (int j = i; j < MAX_BLOCOS && fitaMemoria[j] == 0; j++) {
                    espacoLivre += memoriaAlocada;
                }
                if (espacoLivre >= memoriaAlocada && espacoLivre > maiorEspacoSobrando) {
                    piorBloco = i;
                    maiorEspacoSobrando = espacoLivre;
                }
            }
        }

        if (piorBloco != -1) {
            fitaMemoria[piorBloco] = memoriaAlocada;
            *memoriaTotal -= memoriaAlocada;
            printf("<<%d KB alocados no bloco %d. Restam %d>> KB.\n", memoriaAlocada, piorBloco, *memoriaTotal);
        } else {
            printf("Não há espaço suficiente na memória.\n");
        }
    } else {
        printf("Não há memória suficiente para alocar %d KB.\n", memoriaAlocada);
    }
}

void SelecionarInstrucao(bool *sair, int fitaMemoria[], int *memoriaTotal) {
    char instrucao;

    printf("\nDigite a instrução (I) para inserir, (L) para liberar e (X) para sair: ");
    scanf(" %c", &instrucao);
    instrucao = tolower(instrucao);

    switch (instrucao) {
        case 'l':
            printf("Liberando memoria...\n");
            break;
        case 'i':
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
    int ajuste;
    bool sair = false;
    int fitaMemoria[MAX_BLOCOS] = {0};
    int memoriaTotal;

    printf("Informe a quantidade total de memória em KB: ");
    scanf("%d", &memoriaTotal);

    while (!sair) {
        printf("Digite a instrução (1) para alocar memória, (2) para melhor ajuste, (3) para pior ajuste, (L) para liberar e (X) para sair: ");
        scanf(" %d", &ajuste);

        switch (ajuste) {
            case 1:
                printf("\n<Primeiro Ajuste Selecionado>\n");
                PrimeiroAjuste(fitaMemoria, &memoriaTotal);
                printf("Memória total disponível: %d KB.\n", memoriaTotal);
                break;
            case 2:
                printf("\n<Melhor Ajuste Selecionado>\n");
                MelhorAjuste(fitaMemoria, &memoriaTotal);
                printf("Memória total disponível: %d KB.\n", memoriaTotal);
                break;
            case 3:
                printf("\n<Pior Ajuste Selecionado>\n");
                PiorAjuste(fitaMemoria, &memoriaTotal);
                printf("Memória total disponível: %d KB.\n", memoriaTotal);
                break;
            case 'l':
                printf("Liberar memória selecionado\n");
                break;
            case 'x':
                printf("Saindo...\n");
                sair = true;
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }
}
