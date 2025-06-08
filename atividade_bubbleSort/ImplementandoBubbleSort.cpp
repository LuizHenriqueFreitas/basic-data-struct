#include <iostream>
using namespace std;

// Implementação da função Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mostraArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {7, 3, 9, 1, 5, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    mostraArray(arr, n);

    bubbleSort(arr, n);

    cout << "Array ordenado: ";
    mostraArray(arr, n);

    return 0;
}

