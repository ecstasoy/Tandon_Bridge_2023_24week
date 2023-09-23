#include <iostream>

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arrSize;

    std::cout << "Please enter the size of the array: " << std::endl;
    std::cin >> arrSize;
    int* arr = new int[arrSize];
    
    std::cout << "\nPlease enter " << arrSize << " integers one by one (press enter after each entry): " << std::endl;
    for (int i = 0; i < arrSize; ++i) {
        std::cin>>arr[i];
    }

    std::cout << "\n1. sumOfSquares(): " << std::endl;
    std::cout << sumOfSquares(arr, arrSize) << std::endl;

    std::cout << "\n2. isSorted(): " << std::endl;
    if (isSorted(arr, arrSize)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 0) return 0;
    int sum = sumOfSquares(arr, arrSize - 1);
    int num = arr[arrSize - 1];

    return sum + num * num;
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize <= 1) return true;

    if (arr[0] > arr[1]) return false;

    return isSorted(arr + 1, arrSize - 1);
}