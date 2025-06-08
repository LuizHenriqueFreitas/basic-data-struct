#include <iostream>

using namespace std;

// Função para o Bubble Sort otimizado
int bubbleSortOtimizado(int arr[], int n) {
    int passadas = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        passadas++;
        if (!swapped) break; // Se não houve trocas, já está ordenado
    }
    return passadas;
}

// Função para imprimir o vetor
void mostraArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int ordenado[] = {1, 2, 3, 4, 5};
    int desordenado[] = {5, 4, 3, 2, 1};
    int n = 5;

    // Teste com array já ordenado
    int arr1[5];
    for (int i = 0; i < n; i++) arr1[i] = ordenado[i];
    int passadas1 = bubbleSortOtimizado(arr1, n);
    cout << "Array já ordenado: ";
    mostraArray(arr1, n);
    cout << "Passadas necessárias: " << passadas1 << endl << endl;

    // Teste com array desordenado
    int arr2[5];
    for (int i = 0; i < n; i++) arr2[i] = desordenado[i];
    int passadas2 = bubbleSortOtimizado(arr2, n);
    cout << "Array desordenado: ";
    mostraArray(arr2, n);
    cout << "Passadas necessárias: " << passadas2 << endl;

    return 0;
}