#include <iostream>

int palindromeDistance(int *arr, int n);

int main() {
    int arr[6] = {1, 3, 6, 6, 5, 2};

    std::cout << palindromeDistance(arr, 6) << std::endl;

    return 0;
}

int palindromeDistance(int *arr, int n) {
    if (n < 2) return 0;
    int sum = palindromeDistance(arr + 1, n - 2);
    if (arr[0] == arr[n - 1]) {
        return sum + 0;
    } else {
        return sum + 1;
    }
}