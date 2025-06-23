#include <iostream>

using namespace std;

const int INF = 1e9;
const int MAXN = 100;

int adj[MAXN][MAXN]; // matriz de adjacência
int dist[MAXN];
bool visited[MAXN];

// Função que implementa o algoritmo de Dijkstra para encontrar as menores distâncias
// de um vértice inicial 'start' para todos os outros vértices em um grafo com 'n' vértices.
void dijkstra(int n, int start) {
    // Inicializa todas as distâncias como infinito e todos os vértices como não visitados
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }
    // A distância do vértice inicial para ele mesmo é zero
    dist[start] = 0;

    // Repete o processo para todos os vértices
    for (int i = 0; i < n; ++i) {
        int u = -1;
        // Encontra o vértice não visitado com a menor distância atual
        for (int j = 0; j < n; ++j)
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        // Se a menor distância for infinita, os demais vértices não são alcançáveis
        if (dist[u] == INF) break;
        // Marca o vértice como visitado
        visited[u] = true;

        // Atualiza as distâncias dos vizinhos do vértice selecionado
        for (int v = 0; v < n; ++v) {
            // Se existe uma aresta de u para v e a distância pode ser melhorada
            if (adj[u][v] && dist[v] > dist[u] + adj[u][v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

void desenharGrafo(int n) {
    cout << "Mapa do grafo (matriz de adjacência):\n";
    cout << "    ";
    for (int j = 0; j < n; ++j)
        cout << j << "   ";
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << i << " | ";
        for (int j = 0; j < n; ++j) {
            if (adj[i][j])
                cout << adj[i][j] << "   ";
            else
                cout << ".   ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 5;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = 0;

    adj[0][1] = 10;
    adj[0][2] = 3;
    adj[1][2] = 1;
    adj[1][3] = 2;
    adj[2][1] = 4;
    adj[2][3] = 8;
    adj[2][4] = 2;
    adj[3][4] = 7;
    adj[4][3] = 9;

    int start = 0;
    dijkstra(n, start);

    cout << "Distâncias a partir do vértice " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF)
            cout << i << ": INF\n";
        else
            cout << i << ": " << dist[i] << "\n";
    }

    cout << "\n";
    // Desenha o grafo
    desenharGrafo(n);

    return 0;
}