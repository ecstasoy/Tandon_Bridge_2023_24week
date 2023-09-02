#include <iostream>

using namespace std;

const string PASSWORD = "12345";
const int SIZE = 10;

void generate(int arr[]);
void displayNum(int arr[]);
bool checkPassword(const string& str, int arr[]);

int main(){
    using namespace std;

    int pswd[SIZE];
    string inputStr;

    srand(time(NULL));
    generate(pswd);
    cout<<"Please enter your PIN according to the following mapping: "<<endl;
    cout<<"PIN: 0 1 2 3 4 5 6 7 8 9"<<endl;
    displayNum(pswd);
    cin>>inputStr;

    if (checkPassword(inputStr, pswd)){
        cout<<"Your PIN is correct";
    } else {
        cout<<"Your PIN is not correct";
    }

    return 0;
}

void generate(int arr[]){
    for (int i = 0; i < SIZE; ++i){
        arr[i] = (rand() % 3) + 1;
    }
}

void displayNum(int arr[]){
    cout<<"NUM: ";
    for(int i = 0; i < SIZE; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

bool checkPassword(const string& str, int arr[]){
    string checkStr = "";
    int index;

    for (int i = 0; i < 5; ++i){
        index = PASSWORD[i]-'0';
        checkStr += to_string(arr[index]);
    }

    return str == checkStr;
}