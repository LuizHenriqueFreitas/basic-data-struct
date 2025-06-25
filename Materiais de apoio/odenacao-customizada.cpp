#include <iostream>
using namespace std;

// Função que compara duas strings de acordo com critérios customizados
bool compararStrings(const string& a, const string& b, bool porTamanho, bool alfabetico) {
    if (porTamanho && a.size() != b.size())
        return a.size() < b.size();
    if (alfabetico)
        return a < b;
    return false;
}

// Função de ordenação customizada (bubble sort)
void ordenarCustomizado(string arr[], int n, bool porTamanho, bool alfabetico) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (compararStrings(arr[j + 1], arr[j], porTamanho, alfabetico)) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    string palavras[] = {"banana", "uva", "abacaxi", "kiwi", "pera", "maçã"};
    int n = sizeof(palavras) / sizeof(palavras[0]);

    // Exemplo: ordenar por tamanho e depois alfabeticamente
    ordenarCustomizado(palavras, n, true, true);

    cout << "Palavras ordenadas (por tamanho, depois alfabeticamente):\n";
    for (int i = 0; i < n; ++i) {
        cout << palavras[i] << "\n";
    }

    return 0;
}
