#include <iostream>
#include <vector>

int* findMissing(int arr[], int n, int& resArrSize);
void printArray(int* arr, int size);

int main() {
    int arrSize, resArrSize = 0;
    int* outArr;

    std::cout << "Please enter the size of the array: " << std::endl;
    std::cin >> arrSize;
    int* arr = new int[arrSize];
    
    std::cout << "Please enter " << arrSize << " integers in the range of [0, " << arrSize << "]" <<" one by one (press enter after each entry): " << std::endl;
    for (int i = 0; i < arrSize; ++i) {
        std::cin>>arr[i];
    }

    outArr = findMissing(arr, arrSize, resArrSize);
    std::cout << "The missing " << resArrSize << " elements are: " << std::endl;
    printArray(outArr, resArrSize);
    delete[] outArr;
    delete[] arr;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int startPos;
    std::vector<bool> existedElement(n, false);

    for (int i = 0; i < n; ++i) {
        existedElement[arr[i]] = true;
    }

    std::vector<int> outVec;

    for (int i = 0; i < n; ++i) {
        if (!existedElement[i]) outVec.push_back(i);
    }

    resArrSize = outVec.size();
    int* outArr = new int [resArrSize];
    for (int i = 0; i < resArrSize; ++i) {
        outArr[i] = outVec[i];
    }

    return outArr;
}

void printArray(int* arr, int size) {
    std::cout<<"[";
    for (int i = 0; i < size; ++i) {
        std::cout<<arr[i];
        if (i < size - 1) std::cout<<", ";
    }
    std::cout<<"]"<<std::endl;
}