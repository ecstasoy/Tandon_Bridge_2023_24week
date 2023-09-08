#include <iostream>
#include <vector>

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int* arr, int size);

int main() {
    using namespace std;

    int arrSize;
    int *arr = new int[arrSize];

    cout<<"Please enter the size of the array: "<<endl;
    cin>>arrSize;
    cout<<"Please enter "<<arrSize<<" integers one by one (press enter after each entry): "<<endl;
    for (int i = 0; i < arrSize; ++i) {
        cin>>arr[i];
    }

    //function 1 test
    int outPosArrSize;
    int *outputArr1 = getPosNums1(arr, arrSize, outPosArrSize);
    cout<<"function 1: "<<endl;
    printArray(outputArr1, outPosArrSize);
    cout<<"\n";
    delete []outputArr1;

    //function 2 test
    int outPosArrSize2;
    int *outputArr2 = getPosNums2(arr, arrSize, &outPosArrSize2);
    cout<<"function 2: "<<endl;
    printArray(outputArr2, outPosArrSize2);
    cout<<"\n";
    delete []outputArr2;

    //function 3 test
    int outPosArrSize3;
    int* outputArr3;
    getPosNums3(arr, arrSize, outputArr3, outPosArrSize3);
    cout << "function 3: "<<endl;;
    printArray(outputArr3, outPosArrSize3);
    cout<<"\n";
    delete[] outputArr3;

    //function 4 test: 
    int outPosArrSize4;
    int* outputArr4;
    getPosNums4(arr, arrSize, &outputArr4, &outPosArrSize4);
    cout << "function 4: "<<endl;;
    printArray(outputArr4, outPosArrSize4);
    cout<<"\n";
    delete[] outputArr4;

    delete []arr;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    using namespace std;

    vector<int> posNum;

    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) posNum.push_back(arr[i]);
    }
    outPosArrSize = posNum.size();
    int* outputArr = new int[outPosArrSize];

    for (int i = 0; i < outPosArrSize; ++i) {
        outputArr[i] = posNum[i];
    }

    return outputArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    using namespace std;

    int outPosArrSize;
    vector<int> posNum;

    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) posNum.push_back(arr[i]);
    }
    outPosArrSize = posNum.size();
    int* outputArr = new int[outPosArrSize];
    for (int i = 0; i < outPosArrSize; ++i) {
        outputArr[i] = posNum[i];
    }

    *outPosArrSizePtr = outPosArrSize;

    return outputArr;
}

void getPosNums3(int* arr, int arrSize, int*& outputArr, int& outPosArrSize) {
    using namespace std;

    vector<int> posNum;

    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) posNum.push_back(arr[i]);
    }
    outPosArrSize = posNum.size();
    outputArr = new int[outPosArrSize];
    for (int i = 0; i < outPosArrSize; ++i) {
        outputArr[i] = posNum[i];
    }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    using namespace std;

    int outPosArrSize;
    vector<int> posNum;

    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) posNum.push_back(arr[i]);
    }
    outPosArrSize = posNum.size();
    int* outputArr = new int[outPosArrSize];
    for (int i = 0; i < outPosArrSize; ++i) {
        outputArr[i] = posNum[i];
    }

    *outPosArrPtr = outputArr;
    *outPosArrSizePtr = outPosArrSize;
}

void printArray(int* arr, int size) {
    using namespace std;
    
    cout<<"[";
    for (int i = 0; i < size; ++i) {
        cout<<arr[i];
        if (i < size - 1) cout<<", ";
    }
    cout<<"]"<<endl;
}