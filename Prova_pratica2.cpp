//Prova Pratica Final Estrutura de dados

//exercicio 1 -> Verificação de Conectividade em Grafo com DFS
//Eu fiz com BFS porque esta na dica que poderia usar, mas de qualquer forma não funcionou
#include <iostream>
#include <cstring>

using namespace std;
/*
// Grafo não direcionado usando lista de adjacência
struct Grafo {
    int V;
    int** adj;
};

void inicializarGrafo(Grafo* g, int V) {
    // Define o número de vértices do grafo
    g->V = V;
    // Aloca dinamicamente um array de ponteiros para representar as linhas da matriz de adjacência
    g->adj = new int*[V];
    // Para cada linha da matriz
    for (int i = 0; i < V; ++i) {
        // Aloca dinamicamente um array de inteiros para representar as colunas da matriz
        g->adj[i] = new int[V];
        // Inicializa todos os elementos da linha com 0 (sem arestas)
        for (int j = 0; j < V; ++j)
            g->adj[i][j] = 0;
    }
}

void adicionarAresta(Grafo* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1; // Não direcionado
}

void destruirGrafo(Grafo* g) {
    for (int i = 0; i < g->V; ++i) delete[] g->adj[i];
    delete[] g->adj;
}

// Fila simples
struct Fila {
    int* dados;
    int inicio, fim, tamanho, capacidade;
};

void inicializarFila(Fila* f, int cap) {
    f->dados = new int[cap];
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = cap;
}

void destruirFila(Fila* f) {
    delete[] f->dados;
}

//adiciona um elemento ao final da fila
void push(Fila* f, int x) {
    if (f->tamanho < f->capacidade) {
        f->dados[f->fim] = x;
        f->fim = (f->fim + 1) % f->capacidade;
        ++f->tamanho;
    }
}

//remove o elemento do início da fila
void pop(Fila* f) {
    if (f->tamanho > 0) {
        f->inicio = (f->inicio + 1) % f->capacidade;
        --f->tamanho;
    }
}

//retorna o elemento do início da fila sem removê-lo
int front(Fila* f) { return f->dados[f->inicio]; }
// verifica se a fila está vazia
bool empty(Fila* f) { return f->tamanho == 0; }

// Função para inverter vetor
void inverter(int* arr, int n) {
    for (int i = 0; i < n / 2; ++i) {
        int tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
}

// Retorna o caminho mais curto do verticeOrigem ao verticeDestino usando BFS
int bfs(Grafo* grafo, int verticeOrigem, int verticeDestino, int* caminho) {
    int V = grafo->V;
    bool* visitado = new bool[V];
    int* anterior = new int[V];
    for (int i = 0; i < V; ++i) {
        visitado[i] = false;
        anterior[i] = -1;
    }
    Fila fila;
    inicializarFila(&fila, V);

    visitado[verticeOrigem] = true;
    push(&fila, verticeOrigem);

    while (!empty(&fila)) {
        int atual = front(&fila);
        pop(&fila);

        if (atual == verticeDestino) break;

        for (int vizinho = 0; vizinho < V; ++vizinho) {
            if (grafo->adj[atual][vizinho] && !visitado[vizinho]) {
                visitado[vizinho] = true;
                anterior[vizinho] = atual;
                push(&fila, vizinho);
            }
        }
    }

    // Reconstruir caminho
    int tam = 0;
    if (!visitado[verticeDestino]) {
        destruirFila(&fila);
        delete[] visitado;
        delete[] anterior;
        return 0; // Caminho vazio se não existe
    }
    for (int v = verticeDestino; v != -1; v = anterior[v]) {
        caminho[tam++] = v;
    }
    inverter(caminho, tam);

    destruirFila(&fila);
    delete[] visitado;
    delete[] anterior;
    return tam;
}

void desenharListaAdjacencias(Grafo* g) {
    cout << "Lista de adjacências:" << endl;
    for (int i = 0; i < g->V; ++i) {
        cout << i << ":";
        for (int j = 0; j < g->V; ++j) {
            if (g->adj[i][j]) {
                cout << " " << j;
            }
        }
        cout << endl;
    }
}*/
/*
void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < 7; i++) {
        if (Grafo->adj && !visited[i]) {
            DFS(i);
        }
    }
}
*//*
int main() {
    Grafo grafo;
    inicializarGrafo(&grafo, 7);

    // Adicionando pelo menos 8 arestas
    adicionarAresta(&grafo, 0, 1);
    adicionarAresta(&grafo, 0, 2);
    adicionarAresta(&grafo, 1, 3);
    adicionarAresta(&grafo, 2, 3);
    adicionarAresta(&grafo, 1, 4);
    adicionarAresta(&grafo, 4, 5);
    adicionarAresta(&grafo, 12, 14);
    adicionarAresta(&grafo, 14, 17);
    adicionarAresta(&grafo, 17, 12);

    desenharListaAdjacencias(&grafo);

    // Testando para dois pares de vértices
    int testes[2][2] = {{0, 3}, {0, 5}};

    for (int t = 0; t < 2; ++t) {
        int origem = testes[t][0], destino = testes[t][1];
        int caminho[6];
        int tam = bfs(&grafo, origem, destino, caminho);
        if (tam == 0) {
            cout << "Não existe caminho de " << origem << " para " << destino << endl;
        } else {
            cout << "Caminho mais curto de " << origem << " para " << destino << ": ";
            for (int i = 0; i < tam; ++i) {
                cout << caminho[i];
                if (i + 1 < tam) cout << " -> ";
            }
            cout << endl;
        }
    }

    destruirGrafo(&grafo);
    return 0;
}
*/
//Exercicio 2
/*
string cores[20]{
        "preto",
        "marrom",
        "vermelho",
        "laranja",
        "amarelo",
        "verde",
        "azul",
        "anil",
        "violeta",
        "rosa",
        "cinza",
        "branco",
        "dourado",
        "prateado",
        "ciano",
        "magenta",
        "lilas",
        "vinho",
        "salmao",
        "turquesa",
    };

    void selectionSort(string arr[], string n) {
    for (int i = 0; i < 14; ++i) {
        int min_idx = i;
        ???????????//nao sei o que fazer
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main(void){
    string entradas[15];
    for(int i=0; i<=14; i++){
        cin >> entradas[i];
        selectionSort(entradas[], entradas[i]){

        }
    }

    

       return 0;
}*/

//nao sei resolver isso

/*
    o 3 eu nao vou nem tentar porque eu nao entendi 
    direiro o conceito basico da tabela, quem dirá 
    conseguir aplicar num exercicio assim.
*/

/*
    Agora são 22:00, já é claro para mim que nao conseguirei fazer nada
    claro que houveram problemas maiores no decorrer do semestre e perdemos
    muitas aulas, mas considero a prova de hoje extremamente dificil, somando
    os fatos que: os exercicios pedem logica complexa se comparada a vista em sala,
    sem falar do 3, que não chegamos a ver em sala como resolver algo parecido;
    e também o fato pessoal que eu trabalho em comercio numa cidade turistica,
    trabalho finais de semana e feriado as vezes até mais do que dias uteis,
    sendo assim, o tempo que eu estudo é fundamentalmente quando estou na faculdade.

    Enfim, são os ossos do ofício, espero conseguir entregar alguma coisa na
    prova de amanhã, para pelo menos pegar IFA, ja venho me preparando para 
    caso isso acontecesse (agora espero que aconteça, senão já era infelizmente),
    afinal, pedi folga no proximo final de semana para a competição de programação
    e usarei esses dias para estudar para a IFA
*/
