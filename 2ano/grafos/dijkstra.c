#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct Node {
    int valor;
    int peso; // a mais no dijkstra
    struct Node* prox;
} node;

typedef struct EstruturaGrafo {
    int numVertices;
    node* listaAdj[100];
} Grafo;

Grafo* criarGrafo(int vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        grafo->listaAdj[i] = NULL;
    }
    return grafo;
}

void addAresta(Grafo* grafo, int origem, int destino, int peso) {
    node* novoNode = (node*)malloc(sizeof(node));
    novoNode->valor = destino;
    novoNode->peso = peso;
    novoNode->prox = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNode;
}

int verticeMin(int* distancias, int* visitados, int numVertices) {
    int minimo = INF;
    int verticeMinimo = -1;

    for (int v = 0; v < numVertices; v++) {
        if (!visitados[v] && distancias[v] <= minimo) {
            minimo = distancias[v];
            verticeMinimo = v;
        }
    }
    return verticeMinimo;
}

void printDistancia(int* distancias, int numVertices, int inicio) {
    printf("Distâncias a partir do vértice origem %d:\n", inicio);
    for (int i = 0; i < numVertices; i++) {
        if (distancias[i] == INF) {
            printf("Vértice %d: INFINITO\n", i);
        } else {
            printf("Vértice %d: %d\n", i, distancias[i]);
        }
    }
}

void Dijkstra(Grafo* grafo, int inicio) {
    int numVertices = grafo->numVertices;
    int distancias[numVertices];
    int visitados[numVertices];

    for (int i = 0; i < numVertices; i++) {
        distancias[i] = INF;
        visitados[i] = 0;
    } // marca distancias como inf a partir da origem

    distancias[inicio] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = verticeMin(distancias, visitados, numVertices);
        visitados[u] = 1;

        node* temp = grafo->listaAdj[u];
        while (temp != NULL) {
            int v = temp->valor;
            int peso = temp->peso;

            if (!visitados[v] && distancias[u] != INF && distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
            }
            temp = temp->prox;
        }
    }

    printDistancia(distancias, numVertices, inicio);
}

int main() {
    Grafo* grafo = criarGrafo(5);

    addAresta(grafo, 0, 1, 10);
    addAresta(grafo, 0, 2, 3);
    addAresta(grafo, 1, 2, 1);
    addAresta(grafo, 1, 3, 2);
    addAresta(grafo, 2, 1, 4);
    addAresta(grafo, 2, 3, 8);
    addAresta(grafo, 2, 4, 2);
    addAresta(grafo, 3, 4, 7);
    addAresta(grafo, 4, 3, 9);
    Dijkstra(grafo, 0);


}