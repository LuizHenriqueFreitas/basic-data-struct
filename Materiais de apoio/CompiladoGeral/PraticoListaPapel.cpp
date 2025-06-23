#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int encontrarSegundoMaior(const std::vector<int>& arr) {
    if (arr.size() < 2) {
        std::cerr << "Erro: Array deve ter pelo menos 2 elementos para encontrar o segundo maior." << std::endl;
        return std::numeric_limits<int>::min(); // Retorna o menor int possível, para indicar um erro
    }

    int maior = std::numeric_limits<int>::min();
    int segundoMaior = std::numeric_limits<int>::min();

    for (int x : arr) {
        if (x > maior) {
            segundoMaior = maior;
            maior = x;
        } else if (x > segundoMaior && x != maior) {
            segundoMaior = x;
        }
    }

    if (segundoMaior == std::numeric_limits<int>::min()) {
         std::cerr << "Aviso: Todos os elementos podem ser iguais ou não há um segundo valor distinto." << std::endl;
    }

    return segundoMaior;
}

bool verificarArrayOrdenado(const std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return true;
    }

    bool crescente = true;
    bool decrescente = true;

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i-1]) { 
            crescente = false;
        }
        if (arr[i] > arr[i-1]) {
            decrescente = false;
        }
    }

    return crescente || decrescente;
}

int contarOcorrencias(const std::vector<int>& arr, int elemento) {
    int contador = 0;
    for (int x : arr) {
        if (x == elemento) {
            contador++;
        }
    }
    return contador;
}

int main() {
    std::cout << "--- Teste: Encontrar o Segundo Maior Elemento ---" << std::endl;
    std::vector<int> arr1 = {10, 5, 20, 8, 15};
    std::cout << "Array: {10, 5, 20, 8, 15}" << std::endl;
    std::cout << "Segundo maior elemento: " << encontrarSegundoMaior(arr1) << std::endl;

    std::vector<int> arr2 = {5, 5, 5, 5};
    std::cout << "Array: {5, 5, 5, 5}" << std::endl;
    std::cout << "Segundo maior elemento: " << encontrarSegundoMaior(arr2) << std::endl;

    std::vector<int> arr3 = {1, 2};
    std::cout << "Array: {1, 2}" << std::endl;
    std::cout << "Segundo maior elemento: " << encontrarSegundoMaior(arr3) << std::endl;

    std::vector<int> arr4 = {7};
    std::cout << "Array: {7}" << std::endl;
    std::cout << "Segundo maior elemento: " << encontrarSegundoMaior(arr4) << std::endl;

    std::vector<int> arr5 = {10, 20, 30, 40, 50};
    std::cout << "Array: {10, 20, 30, 40, 50}" << std::endl;
    std::cout << "Segundo maior elemento: " << encontrarSegundoMaior(arr5) << std::endl;

    std::cout << std::endl;

    std::cout << "--- Teste: Verificar se um Array Está Ordenado ---" << std::endl;
    std::vector<int> sortedArr1 = {1, 2, 3, 4, 5};
    std::cout << "Array: {1, 2, 3, 4, 5} - Ordenado? " << (verificarArrayOrdenado(sortedArr1) ? "Sim" : "Não") << std::endl;

    std::vector<int> sortedArr2 = {5, 4, 3, 2, 1};
    std::cout << "Array: {5, 4, 3, 2, 1} - Ordenado? " << (verificarArrayOrdenado(sortedArr2) ? "Sim" : "Não") << std::endl;

    std::vector<int> unsortedArr1 = {1, 5, 3, 2, 4};
    std::cout << "Array: {1, 5, 3, 2, 4} - Ordenado? " << (verificarArrayOrdenado(unsortedArr1) ? "Sim" : "Não") << std::endl;

    std::vector<int> singleElementArr = {42};
    std::cout << "Array: {42} - Ordenado? " << (verificarArrayOrdenado(singleElementArr) ? "Sim" : "Não") << std::endl;

    std::vector<int> emptyArr;
    std::cout << "Array: {} - Ordenado? " << (verificarArrayOrdenado(emptyArr) ? "Sim" : "Não") << std::endl;

    std::vector<int> duplicateArr = {7, 7, 7, 7};
    std::cout << "Array: {7, 7, 7, 7} - Ordenado? " << (verificarArrayOrdenado(duplicateArr) ? "Sim" : "Não") << std::endl;

    std::cout << std::endl;

    std::cout << "--- Teste: Contar Ocorrências de um Elemento ---" << std::endl;
    std::vector<int> countArr = {1, 2, 3, 2, 4, 2, 5};
    int elemento1 = 2;
    int elemento2 = 7;
    std::cout << "Array: {1, 2, 3, 2, 4, 2, 5}" << std::endl;
    std::cout << "Ocorrências de " << elemento1 << ": " << contarOcorrencias(countArr, elemento1) << std::endl;
    std::cout << "Ocorrências de " << elemento2 << ": " << contarOcorrencias(countArr, elemento2) << std::endl;

    std::vector<int> allSameArr = {10, 10, 10, 10};
    int elemento3 = 10;
    std::cout << "Array: {10, 10, 10, 10}" << std::endl;
    std::cout << "Ocorrências de " << elemento3 << ": " << contarOcorrencias(allSameArr, elemento3) << std::endl;

    return 0;
}