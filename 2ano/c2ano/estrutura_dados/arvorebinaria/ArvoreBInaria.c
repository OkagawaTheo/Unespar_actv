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

// Função para encontrar o menor valor em uma subárvore
No *encontrarMenorNum(No *raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

No *remover(No *raiz, int chave) {
    if (raiz == NULL) {
        printf("Valor não encontrado.\n");
        return NULL;
    } 
    
    if (chave < raiz->conteudo) {
        raiz->esquerda = remover(raiz->esquerda, chave);
    } else if (chave > raiz->conteudo) {
        raiz->direita = remover(raiz->direita, chave);
    } else {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            printf("Elemento folha removido: %d\n", chave);
            return NULL;
        } else if (raiz->esquerda == NULL) {
            No *temp = raiz->direita;
            free(raiz);
            printf("Elemento removido (um filho direita): %d\n", chave);
            return temp;
        } else if (raiz->direita == NULL) {
            No *temp = raiz->esquerda;
            free(raiz);
            printf("Elemento removido (com um filho esquerda): %d\n", chave);
            return temp;
        } else {
            No *temp = encontrarMenorNum(raiz->direita); //menor valor direita
            raiz->conteudo = temp->conteudo;  // Substitui valor
            raiz->direita = remover(raiz->direita, temp->conteudo);
            printf("Elemento removido (com dois filhos): %d\n", chave);
        }
    }
    return raiz;
}

int main() {
    int opcao1, opcao2, valor;
    ArvB arvore;
    arvore.raiz = NULL;

    do {
        printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Remover\n");
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
            
            case 3:
                printf("Informe o valor a ser removido: ");
                scanf("%d", &valor);
                arvore.raiz = remover(arvore.raiz, valor);
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao1 != 0);
}
