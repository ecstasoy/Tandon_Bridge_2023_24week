#include <iostream>
using namespace std;

int main() {
    int n, num;

    cout<<"Please enter a positive integer: "<<endl;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        num = i + 1;
        for (int j = 0; j < n; ++j) {
            cout<<num<<"\t";
            num += (i + 1); 
        }
        cout<<"\n";
    }

    return 0;
}