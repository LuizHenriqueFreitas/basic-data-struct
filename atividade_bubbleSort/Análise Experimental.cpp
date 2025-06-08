#include <iostream>
#include <random>
#include <chrono>

// Função para gerar array aleatório
void geraArrayAleatorio(int arr[], int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);

    for (int i = 0; i < n; ++i) {
        arr[i] = dis(gen);
    }
}

// Função Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para medir tempo
double medeTempo(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / 1000.0; // retorna em milissegundos
}

// Função para copiar arrays
void copiaArray(int dest[], const int src[], int n) {
    for (int i = 0; i < n; ++i) {
        dest[i] = src[i];
    }
}

int main() {
    int sizes[] = {100, 500, 1000, 2000};
    const int executions = 5;

    for (int s = 0; s < 4; ++s) {
        int size = sizes[s];
        double totalTime = 0.0;
        int* arr = new int[size];
        int* arrCopy = new int[size];

        for (int exec = 0; exec < executions; ++exec) {
            geraArrayAleatorio(arr, size);
            copiaArray(arrCopy, arr, size);
            double time = medeTempo(arrCopy, size);
            totalTime += time;
        }
        double avgTime = totalTime / executions;
        std::cout << "Tamanho do array: " << size
                  << " | Tempo medio: " << avgTime << " ms" << std::endl;

        delete[] arr;
        delete[] arrCopy;
    }

    return 0;
}