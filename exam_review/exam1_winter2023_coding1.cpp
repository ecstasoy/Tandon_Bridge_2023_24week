#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string spacing, letter;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>n;

    for (int i = 1; i <= 2*n; ++i) {
        string spacing = string(2*n-i, ' ');
        string letter = string(i, '*');
        cout<<spacing<<letter<<endl;
    }

    return 0;
}