//tabela hash
#include <iostream>

#define TAMANHO_TABELA 10

// No da lista encadeada
struct No {
    int chave;
    No* prox;
};

// Estrutura da tabela hash
struct TabelaHash {
    No* tabela[TAMANHO_TABELA];
};

// Funcao hash simples
int funcaoHash(int chave) {
    return chave % TAMANHO_TABELA;
}

// Inicializa a tabela hash
void inicializar(TabelaHash &th) {
    for (int i = 0; i < TAMANHO_TABELA; ++i)
        th.tabela[i] = nullptr;
}

// Insere uma chave na tabela hash (encadeamento separado)
void inserir(TabelaHash &th, int chave) {
    int indice = funcaoHash(chave);
    No* novo = new No{chave, th.tabela[indice]};
    th.tabela[indice] = novo;
}

// Busca uma chave na tabela hash
bool buscar(TabelaHash &th, int chave) {
    int indice = funcaoHash(chave);
    No* atual = th.tabela[indice];
    while (atual) {
        if (atual->chave == chave) return true;
        atual = atual->prox;
    }
    return false;
}

// Exibe o conteudo da tabela hash
void exibir(TabelaHash &th) {
    for (int i = 0; i < TAMANHO_TABELA; ++i) {
        std::cout << i << ":";
        No* atual = th.tabela[i];
        while (atual) {
            std::cout << " " << atual->chave;
            atual = atual->prox;
        }
        std::cout << std::endl;
    }
}

// Libera memoria alocada
void liberar(TabelaHash &th) {
    for (int i = 0; i < TAMANHO_TABELA; ++i) {
        No* atual = th.tabela[i];
        while (atual) {
            No* temp = atual;
            atual = atual->prox;
            delete temp;
        }
    }
}

int main() {
    TabelaHash th;
    inicializar(th);
    inserir(th, 15);
    inserir(th, 25);
    inserir(th, 35);
    inserir(th, 5);

    std::cout << "Tabela Hash:\n";
    exibir(th);

    int chave = 25;
    if (buscar(th, chave))
        std::cout << chave << " encontrado!\n";
    else
        std::cout << chave << " nao encontrado!\n";

    liberar(th);
    return 0;
}
