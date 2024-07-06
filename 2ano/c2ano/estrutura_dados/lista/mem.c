#include <stdio.h>
#include <stdlib.h>

typedef struct bloco {
    int tamanhoTotal;
    int memoriaOcupada; 
    struct bloco *prox; 
} Bloco;

Bloco *criarBloco(int tamanho) {
    Bloco *novoBloco = (Bloco *)malloc(sizeof(Bloco));
    novoBloco->tamanhoTotal = tamanho; 
    novoBloco->memoriaOcupada = 0; 
    novoBloco->prox = NULL; 
    return novoBloco; 
}

void adicionarBloco(Bloco **inicio, int tamanho) {
    Bloco *novoBloco = criarBloco(tamanho); 
    if (*inicio == NULL) { 
        *inicio = novoBloco;
    } else {
        Bloco *atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoBloco;
    }
}


void inserirMemoria(Bloco *inicio, int quantidade) {
    Bloco *atual = inicio;
    while (atual != NULL) { 
        int espacoLivre = atual->tamanhoTotal - atual->memoriaOcupada; 
        if (quantidade <= espacoLivre) { 
            atual->memoriaOcupada += quantidade;
            printf("\nMemoria de %d inserida no bloco de %d de memoria. Espaco livre restante: %d\n", quantidade, atual->tamanhoTotal, espacoLivre - quantidade);
            return;
        }
        atual = atual->prox; 
        }
 
    printf("Nao ha espaco suficiente em nenhum bloco para %d.\n", quantidade);
}


void mostrarBlocos(Bloco *inicio) {
    Bloco *atual = inicio;
    printf("----------------------------------------------------------------\n");
    printf("| Bloco | Tamanho Total | Memoria Ocupada | Espaco Livre |\n");
    printf("-----------------------------------------------------------------\n");
    int contador = 1;
    while (atual != NULL) { 
        printf("|   %d   |      %d       |       %d        |     %d       |\n",
               contador++, atual->tamanhoTotal, atual->memoriaOcupada, atual->tamanhoTotal - atual->memoriaOcupada);
        atual = atual->prox;
    }
    printf("-------------------------------------------------\n");
}

void liberarBlocos(Bloco **inicio) {
    Bloco *atual = *inicio;
    while (atual != NULL) { 
        Bloco *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *inicio = NULL; 
}

int main() {
    Bloco *inicio = NULL; 
    int nBlocos, tamanhoTotal, nQuantidades, quantidade;

    printf("Digite a quantidade de blocos: ");
    scanf("%d", &nBlocos);
    for (int i = 0; i < nBlocos; i++) {
        printf("\nDigite o tamanho total do bloco %d: ", i + 1);
        scanf("%d", &tamanhoTotal);
        adicionarBloco(&inicio, tamanhoTotal);
    }
    printf("\n");

    printf("Digite o numero de memorias a serem alocadas: ");
    scanf("%d", &nQuantidades);
    for (int i = 0; i < nQuantidades; i++) {
        printf("\nDigite a quantidade de memoria que quer armazenar (%d): ", i + 1);
        scanf("%d", &quantidade);
        inserirMemoria(inicio, quantidade);
    }
    printf("\n");

    mostrarBlocos(inicio); 
    liberarBlocos(&inicio); 

    return 0;
}