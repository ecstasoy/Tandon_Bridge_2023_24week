#include <iostream>

double findMedian(int arr[], int n);

int main() {
    int arr[7] = {3, 5, 3, 7, 1, 7, 6};

    std::cout << findMedian(arr, 7) << std::endl;

    return 0;
}

double findMedian(int arr[], int n) {
    int freq[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) ++freq[arr[i] - 1];
    int i = 0;
    while (sum <= n / 2) {
        sum = sum + freq[i];
        ++i;
    }

    return i;
}