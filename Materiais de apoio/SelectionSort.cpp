#include <iostream>

// Função para realizar o Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;

    selectionSort(arr, n);

    std::cout << "Array ordenado: ";
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}