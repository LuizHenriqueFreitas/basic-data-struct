#include <iostream>

void printArray(const int arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i != size - 1) std::cout << ", ";
    }
    std::cout << "]";
}

void bubbleSortVisualizacao(int arr[], int size) {
    int passada = 1;
    bool trocou;

    do {
        trocou = false;
        std::cout << "Passada " << passada << ":\n";
        for (int i = 0; i < size - 1; ++i) {
            std::cout << "  Comparando " << arr[i] << " e " << arr[i+1] << ": ";
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                std::cout << "Troca! -> ";
                printArray(arr, size);
                std::cout << "\n";
                trocou = true;
            } else {
                std::cout << "Nao troca\n";
            }
        }
        std::cout << "Final da passada " << passada << ": ";
        printArray(arr, size);
        std::cout << "\n\n";
        passada++;
        size--; // Otimização: o último elemento já está no lugar
    } while (trocou);
}

int main() {
    int arr[] = {5, 2, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSortVisualizacao(arr, size);
    return 0;
}