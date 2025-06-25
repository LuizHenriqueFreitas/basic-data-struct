#include <iostream>
using namespace std;

const int TAMANHO_TABELA = 5;

struct EntradaHash {
    int chave;
    int valor;
    bool ocupado;
};

void inicializarTabela(EntradaHash tabela[]) {
    for (int i = 0; i < TAMANHO_TABELA; ++i)
        tabela[i].ocupado = false;
}

int funcaoHash(int chave) {
    return chave % TAMANHO_TABELA;
}

// Função para tratamento de colisão usando sondagem linear
int resolverColisao(EntradaHash tabela[], int idx) {
    int idxInicial = idx;
    do {
        idx = (idx + 1) % TAMANHO_TABELA;
        if (!tabela[idx].ocupado)
            return idx;
    } while (idx != idxInicial);
    return -1; // tabela cheia
}

void inserir(EntradaHash tabela[], int chave, int valor) {
    int idx = funcaoHash(chave);
    if (!tabela[idx].ocupado) {
        tabela[idx].chave = chave;
        tabela[idx].valor = valor;
        tabela[idx].ocupado = true;
        cout << "Inserido (" << chave << ", " << valor << ") na posição " << idx << endl;
        return;
    }
    // Colisão: usar função de tratamento
    int novoIdx = resolverColisao(tabela, idx);
    if (novoIdx != -1) {
        tabela[novoIdx].chave = chave;
        tabela[novoIdx].valor = valor;
        tabela[novoIdx].ocupado = true;
        cout << "Inserido (" << chave << ", " << valor << ") na posição " << novoIdx << " (colisão resolvida)\n";
    } else {
        cout << "Tabela hash cheia!\n";
    }
}

bool buscar(EntradaHash tabela[], int chave, int &valor) {
    int idx = funcaoHash(chave);
    int idxInicial = idx;
    do {
        if (tabela[idx].ocupado && tabela[idx].chave == chave) {
            valor = tabela[idx].valor;
            return true;
        }
        if (!tabela[idx].ocupado)
            return false;
        idx = (idx + 1) % TAMANHO_TABELA;
    } while (idx != idxInicial);
    return false;
}

void exibir(EntradaHash tabela[]) {
    for (int i = 0; i < TAMANHO_TABELA; ++i) {
        if (tabela[i].ocupado)
            cout << i << ": (" << tabela[i].chave << ", " << tabela[i].valor << ")\n";
        else
            cout << i << ": vazio\n";
    }
}

int main() {
    EntradaHash tabela[TAMANHO_TABELA];
    inicializarTabela(tabela);

    inserir(tabela, 1, 100);
    inserir(tabela, 6, 200);
    inserir(tabela, 11, 300);
    inserir(tabela, 2, 400);
    inserir(tabela, 7, 500);

    exibir(tabela);

    int valor;
    if (buscar(tabela, 6, valor))
        cout << "Chave 6 encontrada com valor " << valor << endl;
    else
        cout << "Chave 6 não encontrada\n";

    if (buscar(tabela, 3, valor))
        cout << "Chave 3 encontrada com valor " << valor << endl;
    else
        cout << "Chave 3 não encontrada\n";

    return 0;
}
