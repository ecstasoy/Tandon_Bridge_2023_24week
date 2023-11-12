#include <iostream>

int findFirstPosition(int arr[], int arrSize, int elem);

int main() {
    int arr[10] = {2, 15, 3, 8, 3, 10, 6, 23, 12, 32};

    std::cout << findFirstPosition(arr, 10, 3) << " " << findFirstPosition(arr, 10, 7) << std::endl;

    return 0;
}

int findFirstPosition(int arr[], int arrSize, int elem) {
    if (arr[0] != elem && arrSize == 1) return - 1;
    if (arr[0] == elem) return 0;
    int firstOf = findFirstPosition(arr + 1, arrSize - 1, elem);

    if (firstOf == -1) {
        return -1;
    } else {
        return firstOf + 1;
    }
}