#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node* prox;
}node;

typedef struct EstruturaGrafo{
    int numVertices;
    node* listaAdj[100]; //lista conexoes de cada vertice
}Grafo;


Grafo* criarGrafo(int vertices){
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = vertices;
    for(int i=0;i<vertices;i++){
        grafo->listaAdj[i] = NULL;
    }
    return grafo;
}

void addAresta(Grafo* grafo,int origem, int destino){ //direcionado
    node* novoNode = (node*)malloc(sizeof(node));
    novoNode->valor = destino;
    novoNode->prox = grafo->listaAdj[origem]; //add prox lig na origem
    grafo->listaAdj[origem] = novoNode;
} 


void BuscaLargura(Grafo* grafo,int inicio){
    int fila[100];
    int inicioFila = 0, fimFila = 0, visitado[100] = {0};
    
    fila[fimFila++] = inicio;
    visitado[inicio] = 1;

    printf("Busca em largura a partir da origem: ");
    while(inicioFila < fimFila){
        int atual = fila[inicioFila++];
        printf("%d ",atual);

        node* temp = grafo->listaAdj[atual];
        while (temp != NULL) {
            int adjacente = temp->valor;
            if (!visitado[adjacente]) {
                visitado[adjacente] = 1; // Marca como visitado
                fila[fimFila++] = adjacente; // Adiciona à fila
            }
            temp = temp->prox;
        }
    }
    printf("\n");
}

int main(){

    Grafo* grafo = criarGrafo(5); //3 vertices
    addAresta(grafo,0,1); // origem -> destino
    addAresta(grafo,1,2);
    addAresta(grafo,2,3);
    addAresta(grafo,2,4);
    BuscaLargura(grafo,0);
}
