#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_BLOCOS 30 


void PrimeiroAjuste(int fitaMemoria[], int *memoriaTotal) {
    int memoriaAlocada;
    printf("KB a alocar: ");
    scanf("%d", &memoriaAlocada);

    if (*memoriaTotal < memoriaAlocada) {
        printf("Memória insuficiente.\n");
        return;
    }

    int inicioEspacoLivre = -1;
    int tamanhoEspacoLivre = 0;

    for (int i = 0; i < MAX_BLOCOS; i++) {
        if (fitaMemoria[i] == 0) { 
            if (inicioEspacoLivre == -1) inicioEspacoLivre = i;
            tamanhoEspacoLivre++;
        } else {
            if (tamanhoEspacoLivre >= memoriaAlocada) {
                for (int j = 0; j < memoriaAlocada; j++) {
                    fitaMemoria[inicioEspacoLivre + j] = 1; 
                }
                *memoriaTotal -= memoriaAlocada;
                printf("<<%d KB alocados a partir do bloco %d. Restam: %d KB>>\n", memoriaAlocada, inicioEspacoLivre, *memoriaTotal);
                return;
            }
            inicioEspacoLivre = -1;
            tamanhoEspacoLivre = 0;
        }
    }

    if (tamanhoEspacoLivre >= memoriaAlocada) {
        for (int j = 0; j < memoriaAlocada; j++) {
            fitaMemoria[inicioEspacoLivre + j] = 1; 
        }
        *memoriaTotal -= memoriaAlocada;
        printf("<<%d KB alocados a partir do bloco %d. Restam: %d KB>>\n", memoriaAlocada, inicioEspacoLivre, *memoriaTotal);
        return;
    }

    printf("Não há espaço contíguo suficiente na memória.\n");
}

void ProximoAjuste(int fitaMemoria[], int *memoriaTotal, int *ultimoBloco) {
    int memoriaAlocada;
    printf("KB a alocar: ");
    scanf("%d", &memoriaAlocada);

    if (*memoriaTotal < memoriaAlocada) {
        printf("Memória insuficiente.\n");
        return;
    }

    int inicioEspacoLivre = -1;
    int tamanhoEspacoLivre = 0;

    for (int k = 0; k < MAX_BLOCOS; k++) { 
        int i = (*ultimoBloco + k) % MAX_BLOCOS; 

        if (fitaMemoria[i] == 0) { 
            if (inicioEspacoLivre == -1) inicioEspacoLivre = i;
            tamanhoEspacoLivre++;
        } else {
            if (tamanhoEspacoLivre >= memoriaAlocada) {
                for (int j = 0; j < memoriaAlocada; j++) {
                    fitaMemoria[(inicioEspacoLivre + j) % MAX_BLOCOS] = 1; 
                }
                *memoriaTotal -= memoriaAlocada;
                *ultimoBloco = (inicioEspacoLivre + memoriaAlocada) % MAX_BLOCOS; 
                printf("<<%d KB alocados a partir do bloco %d. Restam: %d KB>>\n", memoriaAlocada, inicioEspacoLivre, *memoriaTotal);
                return;
            }
            inicioEspacoLivre = -1; 
            tamanhoEspacoLivre = 0;
        }
    }

    if (tamanhoEspacoLivre >= memoriaAlocada) {
        for (int j = 0; j < memoriaAlocada; j++) {
            fitaMemoria[(inicioEspacoLivre + j) % MAX_BLOCOS] = 1; 
        }
        *memoriaTotal -= memoriaAlocada;
        *ultimoBloco = (inicioEspacoLivre + memoriaAlocada) % MAX_BLOCOS; 
        printf("<<%d KB alocados a partir do bloco %d. Restam: %d KB>>\n", memoriaAlocada, inicioEspacoLivre, *memoriaTotal);
        return;
    }

    printf("Não há espaço contíguo suficiente na memória.\n");
}

void MelhorAjuste(int fitaMemoria[], int *memoriaTotal) {
    int memoriaAlocada;
    printf("KB a alocar: ");
    scanf("%d", &memoriaAlocada);

    if (*memoriaTotal < memoriaAlocada) {
        printf("Memória insuficiente.\n");
        return;
    }

    int melhorInicioBloco = -1;
    int menorTamanhoEspaco = INT_MAX;

    int inicioEspacoAtual = -1;
    int tamanhoEspacoAtual = 0;

    for (int i = 0; i <= MAX_BLOCOS; i++) { 
        if (i < MAX_BLOCOS && fitaMemoria[i] == 0) { 
            if (inicioEspacoAtual == -1) inicioEspacoAtual = i;
            tamanhoEspacoAtual++;
        } else {
            if (tamanhoEspacoAtual >= memoriaAlocada) {
                if (tamanhoEspacoAtual < menorTamanhoEspaco) {
                    menorTamanhoEspaco = tamanhoEspacoAtual;
                    melhorInicioBloco = inicioEspacoAtual;
                }
            }
            inicioEspacoAtual = -1; 
            tamanhoEspacoAtual = 0;
        }
    }

    if (melhorInicioBloco != -1) {
        for (int i = 0; i < memoriaAlocada; i++) {
            fitaMemoria[melhorInicioBloco + i] = 1; 
        }
        *memoriaTotal -= memoriaAlocada;
        printf("<<%d KB alocados a partir do bloco %d. Restam: %d KB>>\n", memoriaAlocada, melhorInicioBloco, *memoriaTotal);
    } else {
        printf("Não há espaço contíguo suficiente para o Melhor Ajuste.\n");
    }
}

void PiorAjuste(int fitaMemoria[], int *memoriaTotal) { //maior gap de memoria
    int memoriaAlocada;
    printf("KB a alocar: ");
    scanf("%d", &memoriaAlocada);

    if (*memoriaTotal < memoriaAlocada) {
        printf("Memória insuficiente.\n");
        return;
    }

    int piorInicioBloco = -1;
    int maiorTamanhoEspaco = -1;

    int inicioEspacoAtual = -1;
    int tamanhoEspacoAtual = 0;

    for (int i = 0; i <= MAX_BLOCOS; i++) { 
        if (i < MAX_BLOCOS && fitaMemoria[i] == 0) { 
            if (inicioEspacoAtual == -1) inicioEspacoAtual = i;
            tamanhoEspacoAtual++;
        } else {
            if (tamanhoEspacoAtual >= memoriaAlocada) {
                if (tamanhoEspacoAtual > maiorTamanhoEspaco) {
                    maiorTamanhoEspaco = tamanhoEspacoAtual;
                    piorInicioBloco = inicioEspacoAtual;
                }
            }
            inicioEspacoAtual = -1; 
            tamanhoEspacoAtual = 0;
        }
    }

    if (piorInicioBloco != -1) {
        for (int i = 0; i < memoriaAlocada; i++) {
            fitaMemoria[piorInicioBloco + i] = 1; 
        }
        *memoriaTotal -= memoriaAlocada;
        printf("<<%d KB alocados a partir do bloco %d. Restam: %d KB>>\n", memoriaAlocada, piorInicioBloco, *memoriaTotal);
    } else {
        printf("Não há espaço contíguo suficiente para o Pior Ajuste.\n");
    }
}

void LiberarMemoria(int fitaMemoria[], int *memoriaTotal) {
    int blocoInicio, tamanho; 
    printf("Bloco inicial e tamanho a liberar (ex: 2 5): ");
    scanf("%d %d", &blocoInicio, &tamanho);

    if (blocoInicio < 0 || blocoInicio >= MAX_BLOCOS || blocoInicio + tamanho > MAX_BLOCOS) {
        printf("Intervalo inválido!\n");
        return;
    }

    for (int i = blocoInicio; i < blocoInicio + tamanho; i++) {
        if (fitaMemoria[i] == 1) { 
            fitaMemoria[i] = 0; 
            (*memoriaTotal)++; 
        }
    }
    printf("<<Memória liberada. Total disponível: %d KB>>\n", *memoriaTotal);
}

void MostrarMemoria(int fitaMemoria[], int memoriaDisponivel) {
    printf("\nEstado da Memória (0=Livre, 1=Ocupado):\n");
    for (int i = 0; i < MAX_BLOCOS; i++) {
        printf("Bloco %2d: %d\n", i, fitaMemoria[i]);
    }
    printf("Memória total disponível: %d KB\n", memoriaDisponivel);
}

int main() {
    int opcao;
    bool sair = false;
    int fitaMemoria[MAX_BLOCOS] = {0}; 
    int memoriaDisponivel = MAX_BLOCOS; 
    int ultimoBloco = 0; 

    printf("\nMemória inicial: %d KB\n", MAX_BLOCOS);

    while (!sair) {
        printf("\nMenu:\n");
        printf("1 - Primeiro Ajuste\n");
        printf("2 - Proximo Ajuste\n");
        printf("3 - Melhor Ajuste\n");
        printf("4 - Pior Ajuste\n");
        printf("5 - Liberar Memoria\n");
        printf("6 - Mostrar Memoria\n");
        printf("7 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: PrimeiroAjuste(fitaMemoria, &memoriaDisponivel); break;
            case 2: ProximoAjuste(fitaMemoria, &memoriaDisponivel, &ultimoBloco); break;
            case 3: MelhorAjuste(fitaMemoria, &memoriaDisponivel); break;
            case 4: PiorAjuste(fitaMemoria, &memoriaDisponivel); break;
            case 5: LiberarMemoria(fitaMemoria, &memoriaDisponivel); break;
            case 6: MostrarMemoria(fitaMemoria, memoriaDisponivel); break;
            case 7: sair = true; break;
            default: printf("Opção inválida!\n");
        }
    }
    return 0;
}