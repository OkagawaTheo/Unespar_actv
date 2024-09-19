#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct {
    No *raiz;
} ArvB;

void adicionarNo(No **raiz, int valor) {
    if (*raiz == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        *raiz = novo;
    } else if (valor < (*raiz)->conteudo) {
        adicionarNo(&((*raiz)->esquerda), valor);
    } else if (valor > (*raiz)->conteudo) {
        adicionarNo(&((*raiz)->direita), valor);
    }
}

void exibirEmOrdem(No *raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esquerda);
        printf("%d  ", raiz->conteudo);
        exibirEmOrdem(raiz->direita);
    }
}

void exibirPreOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d  ", raiz->conteudo);
        exibirPreOrdem(raiz->esquerda);
        exibirPreOrdem(raiz->direita);
    }
}

void exibirPosOrdem(No *raiz) {
    if (raiz != NULL) {
        exibirPosOrdem(raiz->esquerda);
        exibirPosOrdem(raiz->direita);
        printf("%d  ", raiz->conteudo);
    }
}

int contarNos(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int contarPares(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int cont = (raiz->conteudo % 2 == 0) ? 1 : 0;
    return cont + contarPares(raiz->esquerda) + contarPares(raiz->direita);
}

int main() {
    int opcao1, opcao2, valor;
    ArvB arvore;
    arvore.raiz = NULL;

    do {
        printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n");
        scanf("%d", &opcao1);

        switch (opcao1) {
            case 0:
                printf("\nEncerrando...\n");
                break;

            case 1:
                printf("Informe um valor: ");
                scanf("%d", &valor);
                adicionarNo(&(arvore.raiz), valor);
                break;

            case 2:
                printf("\nEscolha o tipo de impressão:\n1 - Em Ordem\n2 - Pré-Ordem\n3 - Pós-Ordem\n");
                scanf("%d", &opcao2);

                if (opcao2 == 1) {
                    exibirEmOrdem(arvore.raiz);
                } else if (opcao2 == 2) {
                    exibirPreOrdem(arvore.raiz);
                } else if (opcao2 == 3) {
                    exibirPosOrdem(arvore.raiz);
                } else {
                    printf("Opção Inválida.\n");
                }

                printf("\nTamanho da árvore: %d\n", contarNos(arvore.raiz));
                printf("Quantidade de números pares: %d\n", contarPares(arvore.raiz));
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao1 != 0);
}
