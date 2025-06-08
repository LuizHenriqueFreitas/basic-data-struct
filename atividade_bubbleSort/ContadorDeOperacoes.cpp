#include <iostream>
using namespace std;

// Função Bubble Sort modificada para contar operações
void bubbleSort(int arr[], int n, int &comparacoes, int &trocas) {
    comparacoes = 0;
    trocas = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocas++;
                swapped = true;
            }
        }
        if (!swapped) break; // Otimização: para se já estiver ordenado
    }
}

// Função para imprimir array (renomeada para mostraArray)
void mostraArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // Arrays para teste
    int arr1[] = {3, 1, 4, 1, 5}; // Pequeno
    int arr2[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6}; // Médio
    int arr3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // Pior caso (inverso)
    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Melhor caso (ordenado)

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    int comparacoes, trocas;

    cout << "Teste 1: Array pequeno\n";
    mostraArray(arr1, n1);
    bubbleSort(arr1, n1, comparacoes, trocas);
    cout << "Comparacoes: " << comparacoes << ", Trocas: " << trocas << "\n\n";

    cout << "Teste 2: Array medio\n";
    mostraArray(arr2, n2);
    bubbleSort(arr2, n2, comparacoes, trocas);
    cout << "Comparacoes: " << comparacoes << ", Trocas: " << trocas << "\n\n";

    cout << "Teste 3: Pior caso (inverso)\n";
    mostraArray(arr3, n3);
    bubbleSort(arr3, n3, comparacoes, trocas);
    cout << "Comparacoes: " << comparacoes << ", Trocas: " << trocas << "\n\n";

    cout << "Teste 4: Melhor caso (ordenado)\n";
    mostraArray(arr4, n4);
    bubbleSort(arr4, n4, comparacoes, trocas);
    cout << "Comparacoes: " << comparacoes << ", Trocas: " << trocas << "\n\n";

    return 0;
}