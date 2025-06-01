#include <iostream>

#define MAX_VERTICES 5

struct Grafo {
    int** matrizAdjacencia;
    int numVertices;
};

Grafo* criarGrafo(int V) {
    Grafo* grafo = new Grafo;
    grafo->numVertices = V;
    grafo->matrizAdjacencia = new int*[V];
    for (int i = 0; i < V; i++) {
        grafo->matrizAdjacencia[i] = new int[V];
        for (int j = 0; j < V; j++) {
            grafo->matrizAdjacencia[i][j] = 0;
        }
    }
    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino) {
    grafo->matrizAdjacencia[origem][destino] = 1;
    grafo->matrizAdjacencia[destino][origem] = 1;
}

void imprimirGrafo(Grafo* grafo) {
    std::cout << "Matriz de Adjacencia:\n";
    for (int i = 0; i < grafo->numVertices; i++) {
        for (int j = 0; j < grafo->numVertices; j++) {
            std::cout << grafo->matrizAdjacencia[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Algoritmo de Busca em Profundidade (DFS)
enum Cor { BRANCO, AMARELO, VERMELHO };

void dfsVisita(Grafo* grafo, int v, Cor* cor) {
    cor[v] = AMARELO;
    std::cout << "Visitando vertice: " << v << std::endl;
    for (int u = 0; u < grafo->numVertices; u++) {
        if (grafo->matrizAdjacencia[v][u] && cor[u] == BRANCO) {
            dfsVisita(grafo, u, cor);
        }
    }
    cor[v] = VERMELHO;
}

void buscaEmProfundidade(Grafo* grafo) {
    Cor* cor = new Cor[grafo->numVertices];
    for (int i = 0; i < grafo->numVertices; i++) {
        cor[i] = BRANCO;
    }
    for (int i = 0; i < grafo->numVertices; i++) {
        if (cor[i] == BRANCO) {
            dfsVisita(grafo, i, cor);
        }
    }
    delete[] cor;
}
// Fim do algoritmo de Busca em Profundidade


void liberarGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        delete[] grafo->matrizAdjacencia[i];
    }
    delete[] grafo->matrizAdjacencia;
    delete grafo;
}

int main() {
    Grafo* grafo = criarGrafo(MAX_VERTICES);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 4);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);

    imprimirGrafo(grafo);

    buscaEmProfundidade(grafo);

    liberarGrafo(grafo);

    return 0;
}