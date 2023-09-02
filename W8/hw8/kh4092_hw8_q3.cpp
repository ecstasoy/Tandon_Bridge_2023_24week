#include <iostream>

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void swap(int& v1, int& v2);

int main(){
using namespace std;

    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    
    return 0;
}

void printArray(int arr[], int arrSize){
    using namespace std;
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void swap(int& v1, int& v2){
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

void reverseArray(int arr[], int arrSize){
    int start = 0;
    int end = arrSize;

    while (start < end) {
        --end;
        swap(arr[start], arr[end]);
        ++start;
    }
}

void removeOdd(int arr[], int& arrSize){
    int writeIndex = 0;
    for (int readIndex = 0; readIndex < arrSize; ++readIndex){
        if (arr[readIndex] % 2 == 0) {
            arr[writeIndex] = arr[readIndex];
            ++writeIndex;
        }
    }

    arrSize = writeIndex;

}

void splitParity(int arr[], int arrSize){
    int start = 0;
    int end = arrSize;

    while (start < end){
        --end;
        if (arr[start] % 2 == 0 && arr[end] % 2 == 1){
            swap(arr[start], arr[end]);
        }
        ++start;
    }
}