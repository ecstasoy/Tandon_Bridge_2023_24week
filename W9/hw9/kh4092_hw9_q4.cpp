#include <iostream>
#include <vector>

void oddsKeepEvensFlip(int* arr, int arrSize);
void printArray(int* arr, int size);

int main() {
    using namespace std;

    int arrSize;
    cout<<"Please enter the size of the array: "<<endl;
    cin>>arrSize;
    int *arr = new int[arrSize];
    cout<<"Please enter "<<arrSize<<" integers one by one (press enter after each entry): "<<endl;
    for (int i = 0; i < arrSize; ++i) {
        cin>>arr[i];
    }

    oddsKeepEvensFlip(arr, arrSize);
    printArray(arr, arrSize);

    return 0;
}

void oddsKeepEvensFlip(int* arr, int arrSize) {
    using namespace std;

    vector<int> outArr;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] % 2 == 1) outArr.push_back(arr[i]);
    }
    for (int i = arrSize - 1; i >= 0; --i) {
        if (arr[i] % 2 == 0) outArr.push_back(arr[i]);
    }
    for (int i = 0; i < arrSize; ++i) {
        arr[i] = outArr[i];
    }


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