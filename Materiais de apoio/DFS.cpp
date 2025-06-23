// buscas em profundidade (DFS) em um grafo não direcionado
#include <iostream>
using namespace std;

const int MAX = 100;
int adj[MAX][MAX];
bool visited[MAX];
int n = 5; // número de vértices

void desenhaMatrizAdjacencia() {
    cout << "Matriz de Adjacência:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

void removeAresta(int u, int v) {
    if (u >= 0 && u < n && v >= 0 && v < n) {
        adj[u][v] = 0;
        adj[v][u] = 0; // Para grafo não direcionado
    }
}

void removeVertice(int v) {
    if (v >= 0 && v < n) {
        for (int i = 0; i < n; i++) {
            adj[v][i] = 0;
            adj[i][v] = 0;
        }
    }
}

void adicionaAresta(int u, int v) {
    if (u >= 0 && u < n && v >= 0 && v < n) {
        adj[u][v] = 1;
        adj[v][u] = 1; // Para grafo não direcionado
    }
}

void adicionaVertice() {
    if (n < MAX) {
        for (int i = 0; i < n; i++) {
            adj[i][n] = 0; // Nova coluna
            adj[n][i] = 0; // Nova linha
        }
        n++;
    } else {
        cout << "Número máximo de vértices atingido." << endl;
    }
}

void deletaGrafo() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    n = 0;
}

int main() {
    // Inicializa matriz de adjacência e visitados
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // Adiciona arestas para um grafo 5x5 (exemplo: (0-1), (0-2), (1-3), (2-4))
    adicionaAresta(0, 1);
    adicionaAresta(0, 2);
    adicionaAresta(1, 3);
    adicionaAresta(2, 4);

    desenhaMatrizAdjacencia();

    int start = 0; // vértice inicial
    cout << "DFS: ";
    DFS(start);
    cout << endl;

    return 0;
}
