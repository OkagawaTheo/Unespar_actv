#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int num;
    struct No *prox;// ponteiro que aponta para algo que não foi definido ainda, inicio da lista.
}no;

no *criar_no(){// função para alocar memória dinâmicamente;
    no *novo = (no *)malloc(sizeof(no));// alocado memoria dinâmica para o ponteiro nó.
    return novo;
}

no *inserir_no_inicio(no *lista, int dado){// Função para fazer com que a lista aponte para no, dado é um valor numerico para preencher o nó.
    no *novo_no = criar_no();// criar o novo nó.
    novo_no->num = dado;// Atribuiu um número (dado) para o inicio da lista.

    if(lista == NULL){// existem duas possibilidades a lista estar vazia ou não.
        lista = novo_no;// o ponteiro lista aponta para o ponteiro novo_no.
        novo_no->prox = NULL; // o ponteiro novo_no aponta para o ponteiro prox.
    }else{// lista encadeada, cria uma nova lista na frente de lista.
        novo_no->prox = lista;
        lista = novo_no;
    }
    return lista;
}

    no *inserirElementoFim(no *lista, int dado){

        no *novoFim = criar_no();
        novoFim ->  num = dado;

        if(lista ==NULL){// unico elemento da lista
            lista = novoFim;
            novoFim -> prox = NULL;
        } else {
            no *aux = lista;
        while(aux -> prox != NULL){
            aux = aux -> prox;
        }

        novoFim -> prox = NULL;
        aux -> prox = novoFim;
        }

        return lista;

    }

void imprimir_lista(no *lista){
    no *aux = lista;// o auxiliar percorre a lista para que nenhum dado da lista seja perdido.
    while(aux != NULL){
        printf("%d ", aux->num);// a variável num na função inserir_no_inicio é atribuida ao ponteito novo_no.
        aux = aux->prox;
    }
}

no *remover(no *lista,int dado){
    if (lista == NULL) return NULL;
    no *temp = lista;
    no *prev = NULL;

    if (temp != NULL && temp->num==dado){
        lista = temp->prox;
        free(temp);
        return lista;
    }
    while(temp != NULL && temp->num != dado){
        prev = temp;
        temp = temp->prox;
    }
    if (temp == NULL) return lista;
    prev->prox = temp->prox;
    free(temp);
    return lista;
}



int main(){
    int numRemovido;

    no *lista = NULL;// Criando um ponteiro de lista que aponta para null.

    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 20);
    lista = inserirElementoFim(lista, 30);
    imprimir_lista(lista);
    printf("\n");
    printf("Digite o número da lista que deseja remover: ");
    scanf("%d",&numRemovido);
    lista = remover(lista,numRemovido);
    imprimir_lista(lista);
}
