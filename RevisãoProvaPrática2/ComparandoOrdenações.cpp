//Comparação entre Select#include <iostream>
#include <iostream>
#include <chrono>
using namespace std;

// Função Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

// Função auxiliar para o Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[1000], R[1000];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Função Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Função para imprimir os primeiros n elementos do array
void printArray(const int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << "]\n";
}

// Função simples para gerar números pseudoaleatórios
int simpleRand(int seed) {
    static unsigned int x = 123456789;
    x = (1103515245 * x + 12345 + seed) & 0x7fffffff;
    return x;
}

int main() {
    const int SIZE = 1000;
    const int PRINT_SIZE = 20;
    int arr1[SIZE], arr2[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr1[i] = 1 + (simpleRand(i) % 10000);
        arr2[i] = arr1[i];
    }

    cout << "Array Original (primeiros " << PRINT_SIZE << "): ";
    printArray(arr1, PRINT_SIZE);

    // Selection Sort
    auto start1 = chrono::high_resolution_clock::now();
    selectionSort(arr1, SIZE);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration1 = end1 - start1;

    cout << "\nSelection Sort:\n";
    cout << "Array Ordenado (primeiros " << PRINT_SIZE << "): ";
    printArray(arr1, PRINT_SIZE);
    cout << "Tempo de execução: " << duration1.count() << " ms\n";

    // Merge Sort
    auto start2 = chrono::high_resolution_clock::now();
    mergeSort(arr2, 0, SIZE - 1);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration2 = end2 - start2;

    cout << "\nMerge Sort:\n";
    cout << "Array Ordenado (primeiros " << PRINT_SIZE << "): ";
    printArray(arr2, PRINT_SIZE);
    cout << "Tempo de execução: " << duration2.count() << " ms\n";

    cout << "\n// Selection Sort: Complexidade O(n^2) na prática é lento para grandes arrays.\n";
    cout << "// Merge Sort: Complexidade O(n log n), muito mais eficiente para grandes arrays.\n";

    return 0;
}
