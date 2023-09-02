#include <iostream>

const int MAX_NUM = 20;

int minInArray(int arr[], int arrSize);
int findIndices(int arr[], int a);
void fillArray(int arr[], int size);

int main(){
    using namespace std;

    int arr[MAX_NUM];

    fillArray(arr, MAX_NUM);
    int minValue = minInArray(arr, MAX_NUM);

    cout<<"The minimum value is "<<minValue<<", and it is located in the following indices: ";

    for (int i = 0; i < MAX_NUM; ++i) {
        if (arr[i] == minValue) cout<<i<<" ";
    }  

    return 0;
}

void fillArray(int arr[], int size){
    using namespace std;

    cout<<"Please enter "<<size<<" integers separated by a space: "<<endl;

    int index;
    while (index < size) {
        cin>>arr[index];
        ++index;
    }
}

int minInArray(int arr[], int arrSize){
    using namespace std;

    int min = arr[0];
    for (int i = 0; i < arrSize; ++i){
        if (arr[i] <= min) min = arr[i];
    }

    return min;
}
