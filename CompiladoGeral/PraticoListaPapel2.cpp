#include <vector>
#include <algorithm>

// Código original, de complexidade O(n^3)
/* bool temTripla(int arr[], int n, int soma) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == soma) {
                    return true;
                }
            }
        }
    }
    return false;
} */

// Código reescrito, de complexidade O(n^2)
bool temTriplaOtimizada(std::vector<int>& arr, int n, int soma) {
    std::sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        int valor_alvo = soma - arr[i];

        while (left < right) {
            int current_sum = arr[left] + arr[right];

            if (current_sum == valor_alvo) {
                return true;
            } else if (current_sum < valor_alvo) {
                left++;
            } else {
                right--;
            }
        }
    }

    return false;
}