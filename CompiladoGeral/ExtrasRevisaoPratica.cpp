// Algoritmo de Dijkstra
/* #include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

struct State {
    int cost;
    int u;

    bool operator<(const State& other) const {
        return cost > other.cost;
    }
};

std::vector<int> dijkstra(int startNode, int numNodes, const std::vector<std::vector<Edge>>& adj) {
    std::vector<int> distances(numNodes, INF);

    std::priority_queue<State> pq;

    distances[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int currentCost = current.cost;
        int u = current.u;

        if (currentCost > distances[u]) {
            continue;
        }

        for (const Edge& edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }

    return distances;
}

int main() {
    int numNodes = 5;

    std::vector<std::vector<Edge>> adj(numNodes);

    adj[0].push_back({1, 10});
    adj[0].push_back({2, 3});
    adj[1].push_back({3, 2});
    adj[2].push_back({1, 4});
    adj[2].push_back({3, 8});
    adj[2].push_back({4, 2});
    adj[3].push_back({4, 5});
    adj[4].push_back({3, 7});

    int startNode = 0;

    std::vector<int> shortestDistances = dijkstra(startNode, numNodes, adj);

    std::cout << "Distâncias mais curtas do nó " << startNode << ":" << std::endl;
    for (int i = 0; i < numNodes; ++i) {
        if (shortestDistances[i] == INF) {
            std::cout << "Nó " << i << ": inacessível" << std::endl;
        } else {
            std::cout << "Nó " << i << ": " << shortestDistances[i] << std::endl;
        }
    }

    return 0;
} */

// Insertion Sort
/* #include <iostream>
#include <vector>
#include <algorithm>

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> myVector = {12, 11, 13, 5, 6, 7};

    std::cout << "Vetor original: ";
    printArray(myVector);

    insertionSort(myVector);

    std::cout << "Vetor ordenado: ";
    printArray(myVector);

    std::vector<int> anotherVector = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "\nOutro vetor original: ";
    printArray(anotherVector);

    insertionSort(anotherVector);
    std::cout << "Outro vetor ordenado: ";
    printArray(anotherVector);

    return 0;
} */

// Quick Sort
/* #include <iostream>
#include <vector>
#include <algorithm>

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Sub-array à esquerda do pivô
        quickSort(arr, pi + 1, high); // Sub-array à direita do pivô
    }
}

int main() {
    std::vector<int> myVector = {10, 7, 8, 9, 1, 5};

    std::cout << "Vetor original: ";
    printArray(myVector);

    quickSort(myVector, 0, myVector.size() - 1);

    std::cout << "Vetor ordenado: ";
    printArray(myVector);

    std::vector<int> anotherVector = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "\nOutro vetor original: ";
    printArray(anotherVector);

    quickSort(anotherVector, 0, anotherVector.size() - 1);
    std::cout << "Outro vetor ordenado: ";
    printArray(anotherVector);

    return 0;
} */

// Counting Sort
/* #include <iostream>
#include <vector>
#include <algorithm>

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void countingSort(std::vector<int>& arr) {
    int n = arr.size();

    if (n == 0) {
        return;
    }
    int max_val = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    std::vector<int> count(max_val + 1, 0);

    for (int num : arr) {
        count[num]++;
    }

    for (int i = 1; i <= max_val; ++i) {
        count[i] += count[i - 1];
    }

    std::vector<int> output(n);

    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

int main() {
    std::vector<int> myVector = {4, 2, 2, 8, 3, 3, 1};

    std::cout << "Vetor original: ";
    printArray(myVector);

    countingSort(myVector);

    std::cout << "Vetor ordenado: ";
    printArray(myVector);

    std::vector<int> anotherVector = {9, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::cout << "\nOutro vetor original: ";
    printArray(anotherVector);

    countingSort(anotherVector);
    std::cout << "Outro vetor ordenado: ";
    printArray(anotherVector);

    std::vector<int> emptyVector = {};
    std::cout << "\nVetor vazio original: ";
    printArray(emptyVector);
    countingSort(emptyVector);
    std::cout << "Vetor vazio ordenado: ";
    printArray(emptyVector);

    return 0;
} */

// Heap Sort
/* #include <iostream>
#include <vector>
#include <algorithm>

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> myVector = {12, 11, 13, 5, 6, 7};

    std::cout << "Vetor original: ";
    printArray(myVector);

    heapSort(myVector);

    std::cout << "Vetor ordenado: ";
    printArray(myVector);

    std::vector<int> anotherVector = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "\nOutro vetor original: ";
    printArray(anotherVector);

    heapSort(anotherVector);
    std::cout << "Outro vetor ordenado: ";
    printArray(anotherVector);

    std::vector<int> emptyVector = {};
    std::cout << "\nVetor vazio original: ";
    printArray(emptyVector);
    heapSort(emptyVector);
    std::cout << "Vetor vazio ordenado: ";
    printArray(emptyVector);

    std::vector<int> singleElementVector = {42};
    std::cout << "\nVetor com um elemento original: ";
    printArray(singleElementVector);
    heapSort(singleElementVector);
    std::cout << "Vetor com um elemento ordenado: ";
    printArray(singleElementVector);

    return 0;
} */

// Bucket Sort
/* #include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

void printArray(const std::vector<double>& arr) {
    for (double num : arr) {
        std::cout << std::fixed << std::setprecision(2) << num << " ";
    }
    std::cout << std::endl;
}

void bucketSort(std::vector<double>& arr) {
    int n = arr.size();

    if (n <= 1) {
        return;
    }

    std::vector<std::vector<double>> buckets(n);

    for (int i = 0; i < n; i++) {
        int bucketIndex = static_cast<int>(n * arr[i]);
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (double num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    std::vector<double> myVector = {0.89, 0.45, 0.68, 0.90, 0.29, 0.34, 0.78, 0.12, 0.56, 0.67};

    std::cout << "Vetor original: ";
    printArray(myVector);

    bucketSort(myVector);

    std::cout << "Vetor ordenado: ";
    printArray(myVector);

    std::vector<double> anotherVector = {0.11, 0.05, 0.99, 0.81, 0.23, 0.77, 0.40, 0.55};
    std::cout << "\nOutro vetor original: ";
    printArray(anotherVector);

    bucketSort(anotherVector);
    std::cout << "Outro vetor ordenado: ";
    printArray(anotherVector);

    std::vector<double> duplicatesVector = {0.7, 0.1, 0.9, 0.2, 0.7, 0.1, 0.5, 0.2};
    std::cout << "\nVetor com duplicatas original: ";
    printArray(duplicatesVector);

    bucketSort(duplicatesVector);
    std::cout << "Vetor com duplicatas ordenado: ";
    printArray(duplicatesVector);

    return 0;
} */

// Radix Sort (professor não falou nada sobre, mas o Gemini sugeriu então é bom ter de referência)
#include <iostream>
#include <vector>
#include <algorithm>

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Interessante notar que esse algoritmo usa um Counting Sort dentro de si mesmo, como auxiliar
void countSort(std::vector<int>& arr, int n, int exp) {
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr) {
    int n = arr.size();

    if (n == 0) {
        return;
    }

    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

int main() {
    std::vector<int> myVector = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Vetor original: ";
    printArray(myVector);

    radixSort(myVector);

    std::cout << "Vetor ordenado: ";
    printArray(myVector);

    std::vector<int> anotherVector = {833, 100, 10, 1, 5, 2000, 150};
    std::cout << "\nOutro vetor original: ";
    printArray(anotherVector);

    radixSort(anotherVector);
    std::cout << "Outro vetor ordenado: ";
    printArray(anotherVector);

    std::vector<int> emptyVector = {};
    std::cout << "\nVetor vazio original: ";
    printArray(emptyVector);
    radixSort(emptyVector);
    std::cout << "Vetor vazio ordenado: ";
    printArray(emptyVector);

    return 0;
}