#include <iostream>

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    std::cout << res1 << " " << res2 << std::endl; //should both be -9
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    std::cout << res3 << " " << res4 << std::endl; //should both be 3
    return 0;
}

int minInArray1(int arr[], int arrSize) {
    if (arrSize <= 1) return arr[0];
    int min = minInArray1(arr, arrSize - 1);
    if (arr[arrSize - 1] < min) {
        return arr[arrSize - 1];
    } else {
        return min;
    }
}

int minInArray2(int arr[], int low, int high) {
    if (low == high) return arr[low];

    int mid = (low + high) / 2;
    int minLeft = minInArray2(arr, low, mid);
    int minRight = minInArray2(arr, mid + 1, high);

    if (minLeft < minRight) {
        return minLeft;
    } else {
        return minRight;
    }
}