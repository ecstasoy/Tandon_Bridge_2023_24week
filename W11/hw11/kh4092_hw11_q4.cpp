#include <iostream>

int lowestTotalCost(int arr[], int arrSize);

int main() {
    int arrSize;

    std::cout << "Please enter the number of columns: " << std::endl;
    std::cin >> arrSize;
    int* arr = new int[arrSize];
    
    std::cout << "\nPlease enter " << arrSize << " integers one by one (always start with a 0, press enter after each entry): " << std::endl;
    for (int i = 0; i < arrSize; ++i) {
        std::cin>>arr[i];
    }

    std::cout << "The lowest total cost is " << lowestTotalCost(arr, arrSize) << ". " << std::endl;

    return 0;
}

int lowestTotalCost(int arr[], int arrSize) {   
    if (arrSize <= 1) return arr[arrSize - 1];

    int moveCost = lowestTotalCost(arr, arrSize - 1) + arr[arrSize - 1];
    int jumpCost = lowestTotalCost(arr, arrSize - 2) + arr[arrSize - 2];

    if (moveCost < jumpCost) {
        return moveCost;
    } else {
        return jumpCost;
    }
}